
#include "cmdline.h"

#define __release_mode

#include "data_declaration.h"
//#include "data_judge.h"
#include "swirl_serialize.hpp"
#include <iostream>
#include "json.hpp"
//void test()
//{
//    student s1 { 20, 345, 600 };
//    std::string s2;
//    std::string path = "data.txt";
//    wstd::read_file(path, s2);
//    std::string id = "d01040001";
//    nlohmann::json j = nlohmann::json::parse(s2);
//   // std::cout << j.dump(4) << std::endl;
//    bool str = wstd::data_serialize::compare(s1, j, id);
//    std::cout << "str -> " << str << std::endl;
//}

int main(int argc, char* argv[])
{
    //test();

#ifdef __release_mode

    std::cout << "start parse stucture data." << std::endl;
    cmdline::parser cmd;
    cmd.add<std::string>("source_path", 's', "source file path", true, "");
    cmd.add<std::string>("dest_path", 'd', "dest file path", true, "");
    cmd.parse_check(argc, argv);

    std::string source_path = cmd.get<std::string>("source_path");
    std::string dest_path = cmd.get<std::string>("dest_path");

#else
    std::string source_path = "data_declaration.h";
    std::string dest_path = "data_judge.h";
#endif

    // ���ɽӿ�
    wstd::swirl_compare(source_path, dest_path);

    return 0;
}
