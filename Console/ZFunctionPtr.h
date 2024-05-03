#pragma once
#include <iostream>

using initializer_funptr = void(*)(int);

class System_Initializer_Lists
{
public:
	initializer_funptr m_funptr;
public:
	System_Initializer_Lists(initializer_funptr funptr) : m_funptr(funptr) {}
	~System_Initializer_Lists() {}
};

void initialize_Net(int port);

void initialize_SPI(int port);

void initialize_I2C(int port);

void test_Init_System();