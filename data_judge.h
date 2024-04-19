#pragma once
#include "json.hpp"
#include <string>
#include "data_declaration.h"
namespace wstd {
	namespace data_serialize {

		inline bool compare(back_data_header ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.addr <= std::stoi(std::string(____object_json[____object_id]["addr"]["dataUpperLimit"])) && ____object_hd.addr >= std::stoi(std::string(____object_json[____object_id]["addr"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.id <= std::stoi(std::string(____object_json[____object_id]["id"]["dataUpperLimit"])) && ____object_hd.id >= std::stoi(std::string(____object_json[____object_id]["id"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reserved0 <= std::stoi(std::string(____object_json[____object_id]["reserved0"]["dataUpperLimit"])) && ____object_hd.reserved0 >= std::stoi(std::string(____object_json[____object_id]["reserved0"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reserved1 <= std::stoi(std::string(____object_json[____object_id]["reserved1"]["dataUpperLimit"])) && ____object_hd.reserved1 >= std::stoi(std::string(____object_json[____object_id]["reserved1"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(modbus_tcp_cmd_header ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.idx <= std::stoi(std::string(____object_json[____object_id]["idx"]["dataUpperLimit"])) && ____object_hd.idx >= std::stoi(std::string(____object_json[____object_id]["idx"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.protocol <= std::stoi(std::string(____object_json[____object_id]["protocol"]["dataUpperLimit"])) && ____object_hd.protocol >= std::stoi(std::string(____object_json[____object_id]["protocol"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.length <= std::stoi(std::string(____object_json[____object_id]["length"]["dataUpperLimit"])) && ____object_hd.length >= std::stoi(std::string(____object_json[____object_id]["length"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.addr <= std::stoi(std::string(____object_json[____object_id]["addr"]["dataUpperLimit"])) && ____object_hd.addr >= std::stoi(std::string(____object_json[____object_id]["addr"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(modbus_tcp_cmd ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.func <= std::stoi(std::string(____object_json[____object_id]["func"]["dataUpperLimit"])) && ____object_hd.func >= std::stoi(std::string(____object_json[____object_id]["func"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(modbus_rtu_cmd ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.addr <= std::stoi(std::string(____object_json[____object_id]["addr"]["dataUpperLimit"])) && ____object_hd.addr >= std::stoi(std::string(____object_json[____object_id]["addr"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.func <= std::stoi(std::string(____object_json[____object_id]["func"]["dataUpperLimit"])) && ____object_hd.func >= std::stoi(std::string(____object_json[____object_id]["func"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reg <= std::stoi(std::string(____object_json[____object_id]["reg"]["dataUpperLimit"])) && ____object_hd.reg >= std::stoi(std::string(____object_json[____object_id]["reg"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.length <= std::stoi(std::string(____object_json[____object_id]["length"]["dataUpperLimit"])) && ____object_hd.length >= std::stoi(std::string(____object_json[____object_id]["length"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.crc <= std::stoi(std::string(____object_json[____object_id]["crc"]["dataUpperLimit"])) && ____object_hd.crc >= std::stoi(std::string(____object_json[____object_id]["crc"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(modbus_register_cmd ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			return true;
		}

		inline bool compare(device_amc_data ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.voltage_a <= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataUpperLimit"])) && ____object_hd.voltage_a >= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_b <= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataUpperLimit"])) && ____object_hd.voltage_b >= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_c <= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataUpperLimit"])) && ____object_hd.voltage_c >= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_a <= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataUpperLimit"])) && ____object_hd.current_a >= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_b <= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataUpperLimit"])) && ____object_hd.current_b >= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_c <= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataUpperLimit"])) && ____object_hd.current_c >= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_a <= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataUpperLimit"])) && ____object_hd.active_power_a >= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_b <= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataUpperLimit"])) && ____object_hd.active_power_b >= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_c <= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataUpperLimit"])) && ____object_hd.active_power_c >= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_total <= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataUpperLimit"])) && ____object_hd.active_power_total >= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_kwh <= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataUpperLimit"])) && ____object_hd.active_kwh >= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.switch_status <= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataUpperLimit"])) && ____object_hd.switch_status >= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(device_bwdk_data ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.temperature_a <= std::stoi(std::string(____object_json[____object_id]["temperature_a"]["dataUpperLimit"])) && ____object_hd.temperature_a >= std::stoi(std::string(____object_json[____object_id]["temperature_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.temperature_b <= std::stoi(std::string(____object_json[____object_id]["temperature_b"]["dataUpperLimit"])) && ____object_hd.temperature_b >= std::stoi(std::string(____object_json[____object_id]["temperature_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.temperature_c <= std::stoi(std::string(____object_json[____object_id]["temperature_c"]["dataUpperLimit"])) && ____object_hd.temperature_c >= std::stoi(std::string(____object_json[____object_id]["temperature_c"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(device_ion7650_data ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.voltage_a <= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataUpperLimit"])) && ____object_hd.voltage_a >= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_b <= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataUpperLimit"])) && ____object_hd.voltage_b >= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_c <= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataUpperLimit"])) && ____object_hd.voltage_c >= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ab <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataUpperLimit"])) && ____object_hd.line_voltage_ab >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_bc <= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataUpperLimit"])) && ____object_hd.line_voltage_bc >= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ac <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataUpperLimit"])) && ____object_hd.line_voltage_ac >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_a <= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataUpperLimit"])) && ____object_hd.current_a >= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_b <= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataUpperLimit"])) && ____object_hd.current_b >= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_c <= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataUpperLimit"])) && ____object_hd.current_c >= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_a <= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataUpperLimit"])) && ____object_hd.active_power_a >= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_b <= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataUpperLimit"])) && ____object_hd.active_power_b >= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_c <= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataUpperLimit"])) && ____object_hd.active_power_c >= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_total <= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataUpperLimit"])) && ____object_hd.active_power_total >= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_a <= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataUpperLimit"])) && ____object_hd.reactive_power_a >= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_b <= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataUpperLimit"])) && ____object_hd.reactive_power_b >= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_c <= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataUpperLimit"])) && ____object_hd.reactive_power_c >= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_total <= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataUpperLimit"])) && ____object_hd.reactive_power_total >= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_a <= std::stoi(std::string(____object_json[____object_id]["apparent_power_a"]["dataUpperLimit"])) && ____object_hd.apparent_power_a >= std::stoi(std::string(____object_json[____object_id]["apparent_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_b <= std::stoi(std::string(____object_json[____object_id]["apparent_power_b"]["dataUpperLimit"])) && ____object_hd.apparent_power_b >= std::stoi(std::string(____object_json[____object_id]["apparent_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_c <= std::stoi(std::string(____object_json[____object_id]["apparent_power_c"]["dataUpperLimit"])) && ____object_hd.apparent_power_c >= std::stoi(std::string(____object_json[____object_id]["apparent_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_total <= std::stoi(std::string(____object_json[____object_id]["apparent_power_total"]["dataUpperLimit"])) && ____object_hd.apparent_power_total >= std::stoi(std::string(____object_json[____object_id]["apparent_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_a <= std::stoi(std::string(____object_json[____object_id]["power_factor_a"]["dataUpperLimit"])) && ____object_hd.power_factor_a >= std::stoi(std::string(____object_json[____object_id]["power_factor_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_b <= std::stoi(std::string(____object_json[____object_id]["power_factor_b"]["dataUpperLimit"])) && ____object_hd.power_factor_b >= std::stoi(std::string(____object_json[____object_id]["power_factor_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_c <= std::stoi(std::string(____object_json[____object_id]["power_factor_c"]["dataUpperLimit"])) && ____object_hd.power_factor_c >= std::stoi(std::string(____object_json[____object_id]["power_factor_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_total <= std::stoi(std::string(____object_json[____object_id]["power_factor_total"]["dataUpperLimit"])) && ____object_hd.power_factor_total >= std::stoi(std::string(____object_json[____object_id]["power_factor_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.frequency <= std::stoi(std::string(____object_json[____object_id]["frequency"]["dataUpperLimit"])) && ____object_hd.frequency >= std::stoi(std::string(____object_json[____object_id]["frequency"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_kwh <= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataUpperLimit"])) && ____object_hd.active_kwh >= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_kwh <= std::stoi(std::string(____object_json[____object_id]["reactive_kwh"]["dataUpperLimit"])) && ____object_hd.reactive_kwh >= std::stoi(std::string(____object_json[____object_id]["reactive_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_total_harmonic_ratio_a <= std::stoi(std::string(____object_json[____object_id]["voltage_total_harmonic_ratio_a"]["dataUpperLimit"])) && ____object_hd.voltage_total_harmonic_ratio_a >= std::stoi(std::string(____object_json[____object_id]["voltage_total_harmonic_ratio_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_total_harmonic_ratio_b <= std::stoi(std::string(____object_json[____object_id]["voltage_total_harmonic_ratio_b"]["dataUpperLimit"])) && ____object_hd.voltage_total_harmonic_ratio_b >= std::stoi(std::string(____object_json[____object_id]["voltage_total_harmonic_ratio_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_total_harmonic_ratio_c <= std::stoi(std::string(____object_json[____object_id]["voltage_total_harmonic_ratio_c"]["dataUpperLimit"])) && ____object_hd.voltage_total_harmonic_ratio_c >= std::stoi(std::string(____object_json[____object_id]["voltage_total_harmonic_ratio_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_total_harmonic_ratio_a <= std::stoi(std::string(____object_json[____object_id]["current_total_harmonic_ratio_a"]["dataUpperLimit"])) && ____object_hd.current_total_harmonic_ratio_a >= std::stoi(std::string(____object_json[____object_id]["current_total_harmonic_ratio_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_total_harmonic_ratio_b <= std::stoi(std::string(____object_json[____object_id]["current_total_harmonic_ratio_b"]["dataUpperLimit"])) && ____object_hd.current_total_harmonic_ratio_b >= std::stoi(std::string(____object_json[____object_id]["current_total_harmonic_ratio_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_total_harmonic_ratio_c <= std::stoi(std::string(____object_json[____object_id]["current_total_harmonic_ratio_c"]["dataUpperLimit"])) && ____object_hd.current_total_harmonic_ratio_c >= std::stoi(std::string(____object_json[____object_id]["current_total_harmonic_ratio_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_unbalance_factor <= std::stoi(std::string(____object_json[____object_id]["voltage_unbalance_factor"]["dataUpperLimit"])) && ____object_hd.voltage_unbalance_factor >= std::stoi(std::string(____object_json[____object_id]["voltage_unbalance_factor"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_unbalance_factor <= std::stoi(std::string(____object_json[____object_id]["current_unbalance_factor"]["dataUpperLimit"])) && ____object_hd.current_unbalance_factor >= std::stoi(std::string(____object_json[____object_id]["current_unbalance_factor"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.long_flicker_a <= std::stoi(std::string(____object_json[____object_id]["long_flicker_a"]["dataUpperLimit"])) && ____object_hd.long_flicker_a >= std::stoi(std::string(____object_json[____object_id]["long_flicker_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.long_flicker_b <= std::stoi(std::string(____object_json[____object_id]["long_flicker_b"]["dataUpperLimit"])) && ____object_hd.long_flicker_b >= std::stoi(std::string(____object_json[____object_id]["long_flicker_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.long_flicker_c <= std::stoi(std::string(____object_json[____object_id]["long_flicker_c"]["dataUpperLimit"])) && ____object_hd.long_flicker_c >= std::stoi(std::string(____object_json[____object_id]["long_flicker_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.short_flicker_a <= std::stoi(std::string(____object_json[____object_id]["short_flicker_a"]["dataUpperLimit"])) && ____object_hd.short_flicker_a >= std::stoi(std::string(____object_json[____object_id]["short_flicker_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.short_flicker_b <= std::stoi(std::string(____object_json[____object_id]["short_flicker_b"]["dataUpperLimit"])) && ____object_hd.short_flicker_b >= std::stoi(std::string(____object_json[____object_id]["short_flicker_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.short_flicker_c <= std::stoi(std::string(____object_json[____object_id]["short_flicker_c"]["dataUpperLimit"])) && ____object_hd.short_flicker_c >= std::stoi(std::string(____object_json[____object_id]["short_flicker_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.switch_status <= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataUpperLimit"])) && ____object_hd.switch_status >= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(device_830dp_data ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.voltage_a <= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataUpperLimit"])) && ____object_hd.voltage_a >= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_b <= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataUpperLimit"])) && ____object_hd.voltage_b >= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_c <= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataUpperLimit"])) && ____object_hd.voltage_c >= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ab <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataUpperLimit"])) && ____object_hd.line_voltage_ab >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_bc <= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataUpperLimit"])) && ____object_hd.line_voltage_bc >= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ac <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataUpperLimit"])) && ____object_hd.line_voltage_ac >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_a <= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataUpperLimit"])) && ____object_hd.current_a >= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_b <= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataUpperLimit"])) && ____object_hd.current_b >= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_c <= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataUpperLimit"])) && ____object_hd.current_c >= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_a <= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataUpperLimit"])) && ____object_hd.active_power_a >= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_b <= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataUpperLimit"])) && ____object_hd.active_power_b >= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_c <= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataUpperLimit"])) && ____object_hd.active_power_c >= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_total <= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataUpperLimit"])) && ____object_hd.active_power_total >= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_a <= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataUpperLimit"])) && ____object_hd.reactive_power_a >= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_b <= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataUpperLimit"])) && ____object_hd.reactive_power_b >= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_c <= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataUpperLimit"])) && ____object_hd.reactive_power_c >= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_total <= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataUpperLimit"])) && ____object_hd.reactive_power_total >= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_a <= std::stoi(std::string(____object_json[____object_id]["apparent_power_a"]["dataUpperLimit"])) && ____object_hd.apparent_power_a >= std::stoi(std::string(____object_json[____object_id]["apparent_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_b <= std::stoi(std::string(____object_json[____object_id]["apparent_power_b"]["dataUpperLimit"])) && ____object_hd.apparent_power_b >= std::stoi(std::string(____object_json[____object_id]["apparent_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_c <= std::stoi(std::string(____object_json[____object_id]["apparent_power_c"]["dataUpperLimit"])) && ____object_hd.apparent_power_c >= std::stoi(std::string(____object_json[____object_id]["apparent_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_total <= std::stoi(std::string(____object_json[____object_id]["apparent_power_total"]["dataUpperLimit"])) && ____object_hd.apparent_power_total >= std::stoi(std::string(____object_json[____object_id]["apparent_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_a <= std::stoi(std::string(____object_json[____object_id]["power_factor_a"]["dataUpperLimit"])) && ____object_hd.power_factor_a >= std::stoi(std::string(____object_json[____object_id]["power_factor_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_b <= std::stoi(std::string(____object_json[____object_id]["power_factor_b"]["dataUpperLimit"])) && ____object_hd.power_factor_b >= std::stoi(std::string(____object_json[____object_id]["power_factor_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_c <= std::stoi(std::string(____object_json[____object_id]["power_factor_c"]["dataUpperLimit"])) && ____object_hd.power_factor_c >= std::stoi(std::string(____object_json[____object_id]["power_factor_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_total <= std::stoi(std::string(____object_json[____object_id]["power_factor_total"]["dataUpperLimit"])) && ____object_hd.power_factor_total >= std::stoi(std::string(____object_json[____object_id]["power_factor_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.frequency <= std::stoi(std::string(____object_json[____object_id]["frequency"]["dataUpperLimit"])) && ____object_hd.frequency >= std::stoi(std::string(____object_json[____object_id]["frequency"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_kwh <= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataUpperLimit"])) && ____object_hd.active_kwh >= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_kwh <= std::stoi(std::string(____object_json[____object_id]["reactive_kwh"]["dataUpperLimit"])) && ____object_hd.reactive_kwh >= std::stoi(std::string(____object_json[____object_id]["reactive_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_unbalance_factor <= std::stoi(std::string(____object_json[____object_id]["voltage_unbalance_factor"]["dataUpperLimit"])) && ____object_hd.voltage_unbalance_factor >= std::stoi(std::string(____object_json[____object_id]["voltage_unbalance_factor"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_unbalance_factor <= std::stoi(std::string(____object_json[____object_id]["current_unbalance_factor"]["dataUpperLimit"])) && ____object_hd.current_unbalance_factor >= std::stoi(std::string(____object_json[____object_id]["current_unbalance_factor"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.switch_status <= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataUpperLimit"])) && ____object_hd.switch_status >= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(device_td710_data ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.voltage_a <= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataUpperLimit"])) && ____object_hd.voltage_a >= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_b <= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataUpperLimit"])) && ____object_hd.voltage_b >= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_c <= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataUpperLimit"])) && ____object_hd.voltage_c >= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ab <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataUpperLimit"])) && ____object_hd.line_voltage_ab >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_bc <= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataUpperLimit"])) && ____object_hd.line_voltage_bc >= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ac <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataUpperLimit"])) && ____object_hd.line_voltage_ac >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_a <= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataUpperLimit"])) && ____object_hd.current_a >= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_b <= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataUpperLimit"])) && ____object_hd.current_b >= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_c <= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataUpperLimit"])) && ____object_hd.current_c >= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_a <= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataUpperLimit"])) && ____object_hd.active_power_a >= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_b <= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataUpperLimit"])) && ____object_hd.active_power_b >= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_c <= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataUpperLimit"])) && ____object_hd.active_power_c >= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_total <= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataUpperLimit"])) && ____object_hd.active_power_total >= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_a <= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataUpperLimit"])) && ____object_hd.reactive_power_a >= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_b <= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataUpperLimit"])) && ____object_hd.reactive_power_b >= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_c <= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataUpperLimit"])) && ____object_hd.reactive_power_c >= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_total <= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataUpperLimit"])) && ____object_hd.reactive_power_total >= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.switch_status <= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataUpperLimit"])) && ____object_hd.switch_status >= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataLowerLimit"]))))
				return false;
			return true;
		}

		inline bool compare(device_pm750_data ____object_hd, nlohmann::json ____object_json, std::string ____object_id)
		{
			if (!(____object_hd.voltage_a <= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataUpperLimit"])) && ____object_hd.voltage_a >= std::stoi(std::string(____object_json[____object_id]["voltage_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_b <= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataUpperLimit"])) && ____object_hd.voltage_b >= std::stoi(std::string(____object_json[____object_id]["voltage_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_c <= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataUpperLimit"])) && ____object_hd.voltage_c >= std::stoi(std::string(____object_json[____object_id]["voltage_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ab <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataUpperLimit"])) && ____object_hd.line_voltage_ab >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ab"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_bc <= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataUpperLimit"])) && ____object_hd.line_voltage_bc >= std::stoi(std::string(____object_json[____object_id]["line_voltage_bc"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.line_voltage_ac <= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataUpperLimit"])) && ____object_hd.line_voltage_ac >= std::stoi(std::string(____object_json[____object_id]["line_voltage_ac"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_a <= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataUpperLimit"])) && ____object_hd.current_a >= std::stoi(std::string(____object_json[____object_id]["current_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_b <= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataUpperLimit"])) && ____object_hd.current_b >= std::stoi(std::string(____object_json[____object_id]["current_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_c <= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataUpperLimit"])) && ____object_hd.current_c >= std::stoi(std::string(____object_json[____object_id]["current_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_a <= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataUpperLimit"])) && ____object_hd.active_power_a >= std::stoi(std::string(____object_json[____object_id]["active_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_b <= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataUpperLimit"])) && ____object_hd.active_power_b >= std::stoi(std::string(____object_json[____object_id]["active_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_c <= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataUpperLimit"])) && ____object_hd.active_power_c >= std::stoi(std::string(____object_json[____object_id]["active_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_power_total <= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataUpperLimit"])) && ____object_hd.active_power_total >= std::stoi(std::string(____object_json[____object_id]["active_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_a <= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataUpperLimit"])) && ____object_hd.reactive_power_a >= std::stoi(std::string(____object_json[____object_id]["reactive_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_b <= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataUpperLimit"])) && ____object_hd.reactive_power_b >= std::stoi(std::string(____object_json[____object_id]["reactive_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_c <= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataUpperLimit"])) && ____object_hd.reactive_power_c >= std::stoi(std::string(____object_json[____object_id]["reactive_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_power_total <= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataUpperLimit"])) && ____object_hd.reactive_power_total >= std::stoi(std::string(____object_json[____object_id]["reactive_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_a <= std::stoi(std::string(____object_json[____object_id]["apparent_power_a"]["dataUpperLimit"])) && ____object_hd.apparent_power_a >= std::stoi(std::string(____object_json[____object_id]["apparent_power_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_b <= std::stoi(std::string(____object_json[____object_id]["apparent_power_b"]["dataUpperLimit"])) && ____object_hd.apparent_power_b >= std::stoi(std::string(____object_json[____object_id]["apparent_power_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_c <= std::stoi(std::string(____object_json[____object_id]["apparent_power_c"]["dataUpperLimit"])) && ____object_hd.apparent_power_c >= std::stoi(std::string(____object_json[____object_id]["apparent_power_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.apparent_power_total <= std::stoi(std::string(____object_json[____object_id]["apparent_power_total"]["dataUpperLimit"])) && ____object_hd.apparent_power_total >= std::stoi(std::string(____object_json[____object_id]["apparent_power_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_a <= std::stoi(std::string(____object_json[____object_id]["power_factor_a"]["dataUpperLimit"])) && ____object_hd.power_factor_a >= std::stoi(std::string(____object_json[____object_id]["power_factor_a"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_b <= std::stoi(std::string(____object_json[____object_id]["power_factor_b"]["dataUpperLimit"])) && ____object_hd.power_factor_b >= std::stoi(std::string(____object_json[____object_id]["power_factor_b"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_c <= std::stoi(std::string(____object_json[____object_id]["power_factor_c"]["dataUpperLimit"])) && ____object_hd.power_factor_c >= std::stoi(std::string(____object_json[____object_id]["power_factor_c"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.power_factor_total <= std::stoi(std::string(____object_json[____object_id]["power_factor_total"]["dataUpperLimit"])) && ____object_hd.power_factor_total >= std::stoi(std::string(____object_json[____object_id]["power_factor_total"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.frequency <= std::stoi(std::string(____object_json[____object_id]["frequency"]["dataUpperLimit"])) && ____object_hd.frequency >= std::stoi(std::string(____object_json[____object_id]["frequency"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.active_kwh <= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataUpperLimit"])) && ____object_hd.active_kwh >= std::stoi(std::string(____object_json[____object_id]["active_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.reactive_kwh <= std::stoi(std::string(____object_json[____object_id]["reactive_kwh"]["dataUpperLimit"])) && ____object_hd.reactive_kwh >= std::stoi(std::string(____object_json[____object_id]["reactive_kwh"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.voltage_unbalance_factor <= std::stoi(std::string(____object_json[____object_id]["voltage_unbalance_factor"]["dataUpperLimit"])) && ____object_hd.voltage_unbalance_factor >= std::stoi(std::string(____object_json[____object_id]["voltage_unbalance_factor"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.current_unbalance_factor <= std::stoi(std::string(____object_json[____object_id]["current_unbalance_factor"]["dataUpperLimit"])) && ____object_hd.current_unbalance_factor >= std::stoi(std::string(____object_json[____object_id]["current_unbalance_factor"]["dataLowerLimit"]))))
				return false;
			if (!(____object_hd.switch_status <= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataUpperLimit"])) && ____object_hd.switch_status >= std::stoi(std::string(____object_json[____object_id]["switch_status"]["dataLowerLimit"]))))
				return false;
			return true;
		}
	}
}