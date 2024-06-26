
#pragma once

#include <fstream>
#include <sstream>
#include <boost/regex.hpp>
#include <filesystem>
#include <map>

namespace wstd
{
    enum
    {
        array_seq_count = 4,
    };

    // �����ļ�����
    bool read_file(std::string path, std::string& content)
    {
        std::ifstream file(path);
        std::ostringstream stream;
        stream << file.rdbuf();
        content = stream.str();
        return true;
    }

    // д���ļ�
    bool write_file(std::string path, std::string& content)
    {
        // truncд��
        std::ofstream file(path, std::ofstream::trunc);
        file << content;
        file.close();
        return true;
    }

    // �������л��ļ�
    void swirl_compare(std::string source_path, std::string dest_path)
    {
        std::string content;
        read_file(source_path, content);

        content = boost::regex_replace(content, boost::regex("\/\\*(.*?)\\*\/"), "");
        content = boost::regex_replace(content, boost::regex("\/\/(.*?)\n"), "\n");


        // �Ѽ�����struct����
        std::string trains_content = content;
        std::vector<std::string> trains;
        boost::regex type_train_regex("struct ((.|\\r|\\n)*?)\\{((.|\\r|\\n)*?)\\};");
        boost::smatch type_train_match;
        while (boost::regex_search(trains_content, type_train_match, type_train_regex))
        {
            // ��ȡ����
            std::string train_name = type_train_match[1].str();
            train_name.erase(std::remove(train_name.begin(), train_name.end(), '\n'), train_name.end());
            train_name.erase(std::remove(train_name.begin(), train_name.end(), ' '), train_name.end());
            trains.push_back(train_name);
            trains_content = type_train_match.suffix();
        }

        // �滻������
        for (auto& type : trains)
        {
            boost::regex sub_type_regex(type + " (.*?);");
            content = boost::regex_replace(content, sub_type_regex, "subtype " + type + " $1;");
        }

        // ��������
        std::string full_content;
        // ��ʼ�ϳ����л�����
        boost::regex base_regex("struct ((.|\\r|\\n)*?)\\{((.|\\r|\\n)*?)\\};");
        boost::smatch base_match;
        while (boost::regex_search(content, base_match, base_regex))
        {
            if (5 != base_match.size())
            {
                content = base_match.suffix();
                continue;
            }

            // �ϳɺ��� ��> node_funtion
            std::string struct_type_name = base_match[1].str();
            struct_type_name.erase(std::remove(struct_type_name.begin(), struct_type_name.end(), '\n'), struct_type_name.end());

            // ���л�
            std::string node_function_serialize = std::string("\n\tinline bool ") + "compare (" +
                struct_type_name + std::string(" ____object_hd") + ", nlohmann::json ____object_json "+ std::string(",std::string") + std::string(" ____object_id)") + " \n\t{\n";

            // �ڲ��ڵ� ��> ��ͨ����
            std::string node = base_match[3].str();
            boost::smatch node_match;
            boost::regex node_regex("^[\\t|\\s]{1,}[a-zA-Z0-9_]{1,}[\\s]{1,}([a-zA-Z0-9_]{1,})([^\\s]*?);");
            
            while (boost::regex_search(node, node_match, node_regex))
            {
                // ��ȡ��Ա
                std::string member = node_match[0].str();

                // ��������
                std::string array_seq = node_match[2].str();
                // �Ƴ��ո�
                array_seq.erase(std::remove(array_seq.begin(), array_seq.end(), ' '), array_seq.end());

                // ��ȡ��ȡ��ֵ
                //double extracted_value = std::stod(node_match[1].str());
                //��ȡ�ȽϷ�ֵ��С��ֵ
                std::string val = node_match[1].str();
                //�ж��Ƿ��ڷ�ֵ��Χ��
                bool member_value = true;

                if ("" == array_seq)
                {
                    //��ֵ��С
                    std::string max;
                    std::string min;
                    std::string id = "d01040001";
                    node_function_serialize += std::string("\t\tif(!(____object_hd." + node_match[1].str() + " <= std::stoi(std::string(____object_json[____object_id][\"" +
                        node_match[1].str() + "\"]" + "[\"" + "dataUpperLimit" + "\"]))" + "&&____object_hd." + node_match[1].str() + " >= std::stoi(std::string(____object_json[____object_id][\"" +
                        node_match[1].str() + "\"]" + "[\"" + "dataLowerLimit" + "\"]))))\n");
                    node_function_serialize += "\t\t\treturn false;\n";                   
                }                    
                node = node_match.suffix();
            }
            node_function_serialize += "\t\treturn true;\n";
            // ����ڵ�洢 ��> Ƕ�׽ṹ��
            std::map<std::string, std::string> struct_array_code_mapper;
            // �ڲ��ڵ� ��> Ƕ�׽ṹ
            boost::regex struct_regex("[a-zA-Z0-9_]{1,} ([a-zA-Z0-9_]{1,}) ([a-zA-Z0-9_]{1,})(.*?);");
            node = base_match[3].str();

            std::string real_array_node;
            while (boost::regex_search(node, node_match, struct_regex))
            {
                std::string type = node_match[1].str();
                // ��������
                std::string array_seq = node_match[3].str();
                // �Ƴ��ո�
                array_seq.erase(std::remove(array_seq.begin(), array_seq.end(), ' '), array_seq.end());
                if ("" == array_seq)
                {
                    // ���л�
                    //node_function_serialize += "\t\tcompare(____object_hd." + node_match[2].str()
                    //    + "," + " ____object_json[\"" + node_match[2].str() + "\"]" + "); \n";
                    node = node_match.suffix();
                    continue;
                }

                // ά�Ƚ���
                boost::regex array_seq_index[array_seq_count] = {
                    boost::regex("\\[(.*?)\\]"),
                    boost::regex("\\[(.*?)\\]\\[(.*?)\\]"),
                    boost::regex("\\[(.*?)\\]\\[(.*?)\\]\\[(.*?)\\]"),
                    boost::regex("\\[(.*?)\\]\\[(.*?)\\]\\[(.*?)\\]\\[(.*?)\\]"), };
                for (auto i = 0; i < array_seq_count; ++i)
                {
                    std::string array_loop_head[] = {
    "\n\
\t\tstd::string result_index = \"[\";\n\
\t\tfor (std::size_t i = 0; i < ____type_index_i; i++)\n\
\t\t{\n\
\t\t    result_index += judge(____object_st.__node_name_index[i]) + (i !=  ____type_index_i - 1 ? \",\" : \"\");\n\
\t\t}\n\
\t\tresult_index += \"]\";\n",

"\n\
\t\tstd::string result_index = \"[\";\n\
\t\tfor (std::size_t i = 0; i < ____type_index_i; i++)\n\
\t\t{\n\
\t\t    std::string result_index1 = \"[\";\n\
\t\t    for (std::size_t j = 0; j < ____type_index_j; j++)\n\
\t\t    {\n\
\t\t        result_index1 += judge(____object_hd.__node_name_index[i][j]) + (j !=  ____type_index_j - 1 ? \",\" : \"\");\n\
\t\t    }\n\
\t\t    result_index1 += \"]\";\n\
\t\t    result_index += result_index1 + (i != ____type_index_i - 1 ? \",\" : \"\");\n\
\t\t}\n\
\t\tresult_index += \"]\";\n",

"\n\
\t\tstd::string result_index = \"[\";\n\
\t\tfor (std::size_t i = 0; i < ____type_index_i; i++)\n\
\t\t{\n\
\t\t    std::string result_index1 = \"[\";\n\
\t\t    for (std::size_t j = 0; j < ____type_index_j; j++)\n\
\t\t    {\n\
\t\t        std::string result_index2 = \"[\";\n\
\t\t        for (std::size_t k = 0; k < ____type_index_k; k++)\n\
\t\t        {\n\
\t\t           result_index2 += judge(____object_st.__node_name_index[i][j][k]) + (k !=  ____type_index_k - 1 ? \",\" : \"\");\n\
\t\t        }\n\
\t\t        result_index2 += \"]\";\n\
\t\t        result_index1 += result_index2 + (j != ____type_index_j - 1 ? \",\" : \"\");\n\
\t\t    }\n\
\t\t    result_index1 += \"]\";\n\
\t\t    result_index += result_index1 + (i != ____type_index_i - 1 ? \",\" : \"\");\n\
\t\t}\n\
\t\tresult_index += \"]\";\n",

"\n\
\t\tstd::string result_index = \"[\";\n\
\t\tfor (std::size_t i = 0; i < ____type_index_i; i++)\n\
\t\t{\n\
\t\t    std::string result_index1 = \"[\";\n\
\t\t    for (std::size_t j = 0; j < ____type_index_j; j++)\n\
\t\t    {\n\
\t\t        std::string result_index2 = \"[\";\n\
\t\t        for (std::size_t k = 0; k < ____type_index_k; k++)\n\
\t\t        {\n\
\t\t            std::string result_index3 = \"[\";\n\
\t\t            for (std::size_t l = 0; l < ____type_index_l; l++)\n\
\t\t            {\n\
\t\t                result_index3 += judge(____object_st.__node_name_index[i][j][k][l]) + (l != ____type_index_l - 1 ? \",\" : \"\");\n\
\t\t            }\n\
\t\t            result_index3 += \"]\";\n\
\t\t            result_index2 += result_index3 + (k != ____type_index_k - 1 ? \",\" : \"\");\n\
\t\t        }\n\
\t\t        result_index2 += \"]\";\n\
\t\t        result_index1 += result_index2 + (j != ____type_index_j - 1 ? \",\" : \"\");\n\
\t\t    }\n\
\t\t    result_index1 += \"]\";\n\
\t\t    result_index += result_index1 + (i != ____type_index_i - 1 ? \",\" : \"\");\n\
\t\t}\n\
\t\tresult_index += \"]\";\n",
                    };

                    std::string array_node;
                    boost::smatch array_match;
                    if (!boost::regex_search(array_seq, array_match, array_seq_index[i]))
                        continue;

                    switch (i)
                    {
                    case 0:
                    {
                        array_node += array_loop_head[i];
                        array_node = boost::regex_replace(array_node, boost::regex("__node_name_index"), node_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_i"), array_match[1].str());
                        array_node = boost::regex_replace(array_node, boost::regex("result_index"), "result_index_" + node_match[2].str());
                        struct_array_code_mapper[node_match[2].str()] = array_node;
                        break;
                    }
                    case 1:
                    {
                        array_node += array_loop_head[i];
                        array_node = boost::regex_replace(array_node, boost::regex("__node_name_index"), node_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_i"), array_match[1].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_j"), array_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("result_index"), "result_index_" + node_match[2].str());
                        struct_array_code_mapper[node_match[2].str()] = array_node;
                        break;
                    }
                    case 2:
                    {
                        array_node += array_loop_head[i];
                        array_node = boost::regex_replace(array_node, boost::regex("__node_name_index"), node_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_i"), array_match[1].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_j"), array_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_k"), array_match[3].str());
                        array_node = boost::regex_replace(array_node, boost::regex("result_index"), "result_index_" + node_match[2].str());
                        struct_array_code_mapper[node_match[2].str()] = array_node;
                        break;
                    }
                    case 3:
                    {
                        array_node += array_loop_head[i];
                        array_node = boost::regex_replace(array_node, boost::regex("__node_name_index"), node_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_i"), array_match[1].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_j"), array_match[2].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_k"), array_match[3].str());
                        array_node = boost::regex_replace(array_node, boost::regex("____type_index_l"), array_match[4].str());
                        array_node = boost::regex_replace(array_node, boost::regex("result_index"), "result_index_" + node_match[2].str());
                        struct_array_code_mapper[node_match[2].str()] = array_node;
                        break;
                    }
                    default:
                        break;
                    }

                    std::string array_loop_head_des[] = {
    "\n\
\t\tfor (auto i = 0; i < ____object_json[\"__node_name_index\"].size(); i++)\n\
\t\t{\n\
\t\t    deserialize(____object_hd.__node_name_index[i], ____object_json[\"__node_name_index\"][i]);\n\
\t\t}\n",

"\n\
\t\tfor (auto i = 0; i < ____object_json[\"__node_name_index\"].size(); i++)\n\
\t\t{\n\
\t\t    for (auto j = 0; j < ____object_json[\"__node_name_index\"][i].size(); j++)\n\
\t\t    {\n\
\t\t        deserialize(____object_hd.__node_name_index[i][j], ____object_json[\"__node_name_index\"][i][j]);\n\
\t\t    }\n\
\t\t}\n",

"\n\
\t\tfor (auto i = 0; i < ____object_json[\"__node_name_index\"].size(); i++)\n\
\t\t{\n\
\t\t    for (auto j = 0; j < ____object_json[\"__node_name_index\"][i].size(); j++)\n\
\t\t    {\n\
\t\t        for (auto k = 0; k < ____object_json[\"__node_name_index\"][i][j].size(); k++)\n\
\t\t        {\n\
\t\t            deserialize(____object_hd.__node_name_index[i][j][k], ____object_json[\"__node_name_index\"][i][j][k]);\n\
\t\t        }\n\
\t\t    }\n\
\t\t}\n",

"\n\
\t\tfor (auto i = 0; i < ____object_json[\"__node_name_index\"].size(); i++)\n\
\t\t{\n\
\t\t    for (auto j = 0; j < ____object_json[\"__node_name_index\"][i].size(); j++)\n\
\t\t    {\n\
\t\t        for (auto k = 0; k < ____object_json[\"__node_name_index\"][i][j].size(); k++)\n\
\t\t        {\n\
\t\t            for (auto l = 0; l < ____object_json[\"__node_name_index\"][i][j][k].size(); l++)\n\
\t\t            {\n\
\t\t                deserialize(____object_hd.__node_name_index[i][j][k][l], ____object_json[\"__node_name_index\"][i][j][k][l]);\n\
\t\t            }\n\
\t\t        }\n\
\t\t    }\n\
\t\t}\n",
                    };

                    // �����л�
                    array_node = array_loop_head_des[i];
                    array_node = boost::regex_replace(array_node, boost::regex("__node_name_index"), node_match[2].str());
                    real_array_node = array_node;
                }
                node_function_serialize += real_array_node;
                node = node_match.suffix();
            }

            // ��������
            for (auto val : struct_array_code_mapper)
            {
                node_function_serialize += "\n" + val.second;
                node_function_serialize += std::string("\t\tjson_data[\"") + val.first + "\"] = " + "nlohmann::json::parse(result_index_" + val.first + ");\n";
            }
           // node_function_serialize += "\t\treturn false;\n";
            node_function_serialize += "\t}\n";

            full_content += node_function_serialize;

            content = base_match.suffix();
        }

        // ������������
        std::filesystem::path file_path = source_path;
        std::string file_name = file_path.filename().string();

        full_content = "#include \"" + file_name + "\"\n" + std::string("namespace wstd { namespace data_compare { \n") + full_content;
        full_content += "} }";
        full_content = "#pragma once\n" + std::string("#include \"json.hpp\"\n") + std::string("#include <string>\n") + full_content;

        // �Ƴ�subtype
        full_content = boost::regex_replace(full_content, boost::regex("subtype "), "");
        write_file(dest_path, full_content);
    }
};

