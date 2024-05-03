#include "ZFunctionPtr.h"

void initialize_Net(int port)
{
	std::cout << "success init network port" << port << "\n";
}

void initialize_SPI(int port)
{
	std::cout << "success init SPI port" << port << "\n";
}

void initialize_I2C(int port)
{
	std::cout << "success init I2C port" << port << "\n";
}

void test_Init_System()
{
	System_Initializer_Lists initial_table[3]
	{
		System_Initializer_Lists(initialize_Net),
		System_Initializer_Lists(initialize_SPI),
		System_Initializer_Lists(initialize_I2C)
	};
	for (int i = 0; i < 3; i++)
	{
		initial_table[i].m_funptr(i);
	}
}