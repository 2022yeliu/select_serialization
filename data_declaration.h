#pragma once

#include <cstring>
#include <string>

enum
{
	// 三相
	phase_count_three = 3,
	// 三相 + t
	phase_count_four = 4,
	// 谐波相数
	harmonic_phase_count = 31,
};

#pragma pack(push, 1)

struct back_data_header
{
	uint8_t magic[8];
	uint8_t addr;
	uint8_t id;
	uint8_t reserved0;
	uint8_t reserved1;
};

struct modbus_tcp_cmd_header
{
	uint16_t idx;
	uint16_t protocol;
	uint16_t length;
	uint8_t addr;
};

// modbus tcp 命令
struct modbus_tcp_cmd
{
	// modbus header
	modbus_tcp_cmd_header header;
	uint8_t func;
	uint8_t data[4];
};

struct modbus_rtu_cmd
{
	uint8_t addr;
	uint8_t func;
	uint16_t reg;
	uint16_t length;
	uint16_t crc;
};

struct modbus_register_cmd
{
	uint8_t magic[8];
	modbus_rtu_cmd cmd;
};

struct device_amc_data
{
	// 相电压 - a
	float voltage_a;
	// 相电压 - b
	float voltage_b;
	// 相电压 - c
	float voltage_c;
	// 相电流 - a
	float current_a;
	// 相电流 - b
	float current_b;
	// 相电流 - c
	float current_c;
	// 有功功率 - a
	float active_power_a;
	// 有功功率 - b
	float active_power_b;
	// 有功功率 - c
	float active_power_c;
	// 有功功率 - t
	float active_power_total;
	// 有功电度
	float active_kwh;
	// 开关量
	int switch_status;
};

// bwdk data
struct device_bwdk_data
{
	// 温度 - a
	float temperature_a;
	// 温度 - b	
	float temperature_b;
	// 温度 - c		
	float temperature_c;
};

// ion7650 data
struct device_ion7650_data
{
	// 相电压 - a
	float voltage_a;
	// 相电压 - b
	float voltage_b;
	// 相电压 - c
	float voltage_c;
	// 线电压 - ab
	float line_voltage_ab;
	// 线电压 - bc
	float line_voltage_bc;
	// 线电压 - ac
	float line_voltage_ac;
	// 相电流 - a
	float current_a;
	// 相电流 - b
	float current_b;
	// 相电流 - c
	float current_c;
	// 有功功率 - a
	float active_power_a;
	// 有功功率 - b
	float active_power_b;
	// 有功功率 - c
	float active_power_c;
	// 总有功功率
	float active_power_total;
	// 无功功率 - a
	float reactive_power_a;
	// 无功功率 - b
	float reactive_power_b;
	// 无功功率 - c
	float reactive_power_c;
	// 总无功功率
	float reactive_power_total;
	// 视在功率 - a
	float apparent_power_a;
	// 视在功率 - b
	float apparent_power_b;
	// 视在功率 - c
	float apparent_power_c;
	// 总视在功率
	float apparent_power_total;
	// 功率因素 - a
	float power_factor_a;
	// 功率因素 - b
	float power_factor_b;
	// 功率因素 - c
	float power_factor_c;
	// 总功率因素
	float power_factor_total;
	// 频率
	float frequency;
	// 正向有功电度
	float active_kwh;
	// 正向无功电度
	float reactive_kwh;
	// 电压2-32次谐波 - a
	float voltage_harmonic_ratio_a[harmonic_phase_count];
	// 电压2-32次谐波 - b
	float voltage_harmonic_ratio_b[harmonic_phase_count];
	// 电压2-32次谐波 - c
	float voltage_harmonic_ratio_c[harmonic_phase_count];
	// 电流2-32次谐波 - a
	float current_harmonic_ratio_a[harmonic_phase_count];
	// 电流2-32次谐波 - b
	float current_harmonic_ratio_b[harmonic_phase_count];
	// 电流2-32次谐波 - c
	float current_harmonic_ratio_c[harmonic_phase_count];
	// 电压总谐波含有率 - a
	float voltage_total_harmonic_ratio_a;
	// 电压总谐波含有率 - b
	float voltage_total_harmonic_ratio_b;
	// 电压总谐波含有率 - c
	float voltage_total_harmonic_ratio_c;
	// 电流总谐波含有率 - a
	float current_total_harmonic_ratio_a;
	// 电流总谐波含有率 - b
	float current_total_harmonic_ratio_b;
	// 电流总谐波含有率 - c
	float current_total_harmonic_ratio_c;
	// 电压不平衡度
	float voltage_unbalance_factor;
	// 电流不平衡度
	float current_unbalance_factor;
	// 电压长时闪变 - a
	float long_flicker_a;
	// 电压长时闪变 - b
	float long_flicker_b;
	// 电压长时闪变 - c
	float long_flicker_c;
	// 电压短时闪变 - a
	float short_flicker_a;
	// 电压短时闪变 - b
	float short_flicker_b;
	// 电压短时闪变 - c
	float short_flicker_c;
	// 开关量
	int switch_status;
};

struct device_830dp_data
{
	// 相电压 - a
	float voltage_a;
	// 相电压 - b
	float voltage_b;
	// 相电压 - c
	float voltage_c;
	// 线电压 - ab
	float line_voltage_ab;
	// 线电压 - bc
	float line_voltage_bc;
	// 线电压 - ac
	float line_voltage_ac;
	// 相电流 - a
	float current_a;
	// 相电流 - b
	float current_b;
	// 相电流 - c
	float current_c;
	// 有功功率 - a
	float active_power_a;
	// 有功功率 - b
	float active_power_b;
	// 有功功率 - c
	float active_power_c;
	// 总有功功率
	float active_power_total;
	// 无功功率 - a
	float reactive_power_a;
	// 无功功率 - b
	float reactive_power_b;
	// 无功功率 - c
	float reactive_power_c;
	// 总无功功率
	float reactive_power_total;
	// 视在功率 - a
	float apparent_power_a;
	// 视在功率 - b
	float apparent_power_b;
	// 视在功率 - c
	float apparent_power_c;
	// 总视在功率
	float apparent_power_total;
	// 功率因素 - a
	float power_factor_a;
	// 功率因素 - b
	float power_factor_b;
	// 功率因素 - c
	float power_factor_c;
	// 总功率因素
	float power_factor_total;
	// 频率
	float frequency;
	// 正向有功电度
	float active_kwh;
	// 正向无功电度
	float reactive_kwh;
	// 电压不平衡度
	float voltage_unbalance_factor;
	// 电流不平衡度
	float current_unbalance_factor;
	// 开关量
	int switch_status;
};

struct device_td710_data
{
	// 相电压 - a
	float voltage_a;
	// 相电压 - b
	float voltage_b;
	// 相电压 - c
	float voltage_c;
	// 线电压 - ab
	float line_voltage_ab;
	// 线电压 - bc
	float line_voltage_bc;
	// 线电压 - ac
	float line_voltage_ac;
	// 相电流 - a
	float current_a;
	// 相电流 - b
	float current_b;
	// 相电流 - c
	float current_c;
	// 有功功率 - a
	float active_power_a;
	// 有功功率 - b
	float active_power_b;
	// 有功功率 - c
	float active_power_c;
	// 总有功功率
	float active_power_total;
	// 无功功率 - a
	float reactive_power_a;
	// 无功功率 - b
	float reactive_power_b;
	// 无功功率 - c
	float reactive_power_c;
	// 总无功功率
	float reactive_power_total;
	// 开关量
	int switch_status;
};

struct device_pm750_data
{
	// 相电压 - a
	float voltage_a;
	// 相电压 - b
	float voltage_b;
	// 相电压 - c
	float voltage_c;
	// 线电压 - ab
	float line_voltage_ab;
	// 线电压 - bc
	float line_voltage_bc;
	// 线电压 - ac
	float line_voltage_ac;
	// 相电流 - a
	float current_a;
	// 相电流 - b
	float current_b;
	// 相电流 - c
	float current_c;
	// 有功功率 - a
	float active_power_a;
	// 有功功率 - b
	float active_power_b;
	// 有功功率 - c
	float active_power_c;
	// 总有功功率
	float active_power_total;
	// 无功功率 - a
	float reactive_power_a;
	// 无功功率 - b
	float reactive_power_b;
	// 无功功率 - c
	float reactive_power_c;
	// 总无功功率
	float reactive_power_total;
	// 视在功率 - a
	float apparent_power_a;
	// 视在功率 - b
	float apparent_power_b;
	// 视在功率 - c
	float apparent_power_c;
	// 总视在功率
	float apparent_power_total;
	// 功率因素 - a
	float power_factor_a;
	// 功率因素 - b
	float power_factor_b;
	// 功率因素 - c
	float power_factor_c;
	// 总功率因素
	float power_factor_total;
	// 频率
	float frequency;
	// 正向有功电度
	float active_kwh;
	// 正向无功电度
	float reactive_kwh;
	// 电压不平衡度
	float voltage_unbalance_factor;
	// 电流不平衡度
	float current_unbalance_factor;
	// 开关量
	int switch_status;
};

#pragma pack(pop)