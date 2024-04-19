#pragma once

#include <cstring>
#include <string>

enum
{
	// ����
	phase_count_three = 3,
	// ���� + t
	phase_count_four = 4,
	// г������
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

// modbus tcp ����
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
	// ���ѹ - a
	float voltage_a;
	// ���ѹ - b
	float voltage_b;
	// ���ѹ - c
	float voltage_c;
	// ����� - a
	float current_a;
	// ����� - b
	float current_b;
	// ����� - c
	float current_c;
	// �й����� - a
	float active_power_a;
	// �й����� - b
	float active_power_b;
	// �й����� - c
	float active_power_c;
	// �й����� - t
	float active_power_total;
	// �й����
	float active_kwh;
	// ������
	int switch_status;
};

// bwdk data
struct device_bwdk_data
{
	// �¶� - a
	float temperature_a;
	// �¶� - b	
	float temperature_b;
	// �¶� - c		
	float temperature_c;
};

// ion7650 data
struct device_ion7650_data
{
	// ���ѹ - a
	float voltage_a;
	// ���ѹ - b
	float voltage_b;
	// ���ѹ - c
	float voltage_c;
	// �ߵ�ѹ - ab
	float line_voltage_ab;
	// �ߵ�ѹ - bc
	float line_voltage_bc;
	// �ߵ�ѹ - ac
	float line_voltage_ac;
	// ����� - a
	float current_a;
	// ����� - b
	float current_b;
	// ����� - c
	float current_c;
	// �й����� - a
	float active_power_a;
	// �й����� - b
	float active_power_b;
	// �й����� - c
	float active_power_c;
	// ���й�����
	float active_power_total;
	// �޹����� - a
	float reactive_power_a;
	// �޹����� - b
	float reactive_power_b;
	// �޹����� - c
	float reactive_power_c;
	// ���޹�����
	float reactive_power_total;
	// ���ڹ��� - a
	float apparent_power_a;
	// ���ڹ��� - b
	float apparent_power_b;
	// ���ڹ��� - c
	float apparent_power_c;
	// �����ڹ���
	float apparent_power_total;
	// �������� - a
	float power_factor_a;
	// �������� - b
	float power_factor_b;
	// �������� - c
	float power_factor_c;
	// �ܹ�������
	float power_factor_total;
	// Ƶ��
	float frequency;
	// �����й����
	float active_kwh;
	// �����޹����
	float reactive_kwh;
	// ��ѹ2-32��г�� - a
	float voltage_harmonic_ratio_a[harmonic_phase_count];
	// ��ѹ2-32��г�� - b
	float voltage_harmonic_ratio_b[harmonic_phase_count];
	// ��ѹ2-32��г�� - c
	float voltage_harmonic_ratio_c[harmonic_phase_count];
	// ����2-32��г�� - a
	float current_harmonic_ratio_a[harmonic_phase_count];
	// ����2-32��г�� - b
	float current_harmonic_ratio_b[harmonic_phase_count];
	// ����2-32��г�� - c
	float current_harmonic_ratio_c[harmonic_phase_count];
	// ��ѹ��г�������� - a
	float voltage_total_harmonic_ratio_a;
	// ��ѹ��г�������� - b
	float voltage_total_harmonic_ratio_b;
	// ��ѹ��г�������� - c
	float voltage_total_harmonic_ratio_c;
	// ������г�������� - a
	float current_total_harmonic_ratio_a;
	// ������г�������� - b
	float current_total_harmonic_ratio_b;
	// ������г�������� - c
	float current_total_harmonic_ratio_c;
	// ��ѹ��ƽ���
	float voltage_unbalance_factor;
	// ������ƽ���
	float current_unbalance_factor;
	// ��ѹ��ʱ���� - a
	float long_flicker_a;
	// ��ѹ��ʱ���� - b
	float long_flicker_b;
	// ��ѹ��ʱ���� - c
	float long_flicker_c;
	// ��ѹ��ʱ���� - a
	float short_flicker_a;
	// ��ѹ��ʱ���� - b
	float short_flicker_b;
	// ��ѹ��ʱ���� - c
	float short_flicker_c;
	// ������
	int switch_status;
};

struct device_830dp_data
{
	// ���ѹ - a
	float voltage_a;
	// ���ѹ - b
	float voltage_b;
	// ���ѹ - c
	float voltage_c;
	// �ߵ�ѹ - ab
	float line_voltage_ab;
	// �ߵ�ѹ - bc
	float line_voltage_bc;
	// �ߵ�ѹ - ac
	float line_voltage_ac;
	// ����� - a
	float current_a;
	// ����� - b
	float current_b;
	// ����� - c
	float current_c;
	// �й����� - a
	float active_power_a;
	// �й����� - b
	float active_power_b;
	// �й����� - c
	float active_power_c;
	// ���й�����
	float active_power_total;
	// �޹����� - a
	float reactive_power_a;
	// �޹����� - b
	float reactive_power_b;
	// �޹����� - c
	float reactive_power_c;
	// ���޹�����
	float reactive_power_total;
	// ���ڹ��� - a
	float apparent_power_a;
	// ���ڹ��� - b
	float apparent_power_b;
	// ���ڹ��� - c
	float apparent_power_c;
	// �����ڹ���
	float apparent_power_total;
	// �������� - a
	float power_factor_a;
	// �������� - b
	float power_factor_b;
	// �������� - c
	float power_factor_c;
	// �ܹ�������
	float power_factor_total;
	// Ƶ��
	float frequency;
	// �����й����
	float active_kwh;
	// �����޹����
	float reactive_kwh;
	// ��ѹ��ƽ���
	float voltage_unbalance_factor;
	// ������ƽ���
	float current_unbalance_factor;
	// ������
	int switch_status;
};

struct device_td710_data
{
	// ���ѹ - a
	float voltage_a;
	// ���ѹ - b
	float voltage_b;
	// ���ѹ - c
	float voltage_c;
	// �ߵ�ѹ - ab
	float line_voltage_ab;
	// �ߵ�ѹ - bc
	float line_voltage_bc;
	// �ߵ�ѹ - ac
	float line_voltage_ac;
	// ����� - a
	float current_a;
	// ����� - b
	float current_b;
	// ����� - c
	float current_c;
	// �й����� - a
	float active_power_a;
	// �й����� - b
	float active_power_b;
	// �й����� - c
	float active_power_c;
	// ���й�����
	float active_power_total;
	// �޹����� - a
	float reactive_power_a;
	// �޹����� - b
	float reactive_power_b;
	// �޹����� - c
	float reactive_power_c;
	// ���޹�����
	float reactive_power_total;
	// ������
	int switch_status;
};

struct device_pm750_data
{
	// ���ѹ - a
	float voltage_a;
	// ���ѹ - b
	float voltage_b;
	// ���ѹ - c
	float voltage_c;
	// �ߵ�ѹ - ab
	float line_voltage_ab;
	// �ߵ�ѹ - bc
	float line_voltage_bc;
	// �ߵ�ѹ - ac
	float line_voltage_ac;
	// ����� - a
	float current_a;
	// ����� - b
	float current_b;
	// ����� - c
	float current_c;
	// �й����� - a
	float active_power_a;
	// �й����� - b
	float active_power_b;
	// �й����� - c
	float active_power_c;
	// ���й�����
	float active_power_total;
	// �޹����� - a
	float reactive_power_a;
	// �޹����� - b
	float reactive_power_b;
	// �޹����� - c
	float reactive_power_c;
	// ���޹�����
	float reactive_power_total;
	// ���ڹ��� - a
	float apparent_power_a;
	// ���ڹ��� - b
	float apparent_power_b;
	// ���ڹ��� - c
	float apparent_power_c;
	// �����ڹ���
	float apparent_power_total;
	// �������� - a
	float power_factor_a;
	// �������� - b
	float power_factor_b;
	// �������� - c
	float power_factor_c;
	// �ܹ�������
	float power_factor_total;
	// Ƶ��
	float frequency;
	// �����й����
	float active_kwh;
	// �����޹����
	float reactive_kwh;
	// ��ѹ��ƽ���
	float voltage_unbalance_factor;
	// ������ƽ���
	float current_unbalance_factor;
	// ������
	int switch_status;
};

#pragma pack(pop)