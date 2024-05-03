#include "ZVector.h"
#include "ZUnorderedMap.h"
#include "ZLogSystem.h"
#include "ZStack.h"
#include "ZTimer.h"
#include "ZQueue.h"
#include "ZFunctionPtr.h"
#include <iostream>

void func(int x)
{
	std::cout << "x is " << x << std::endl;
}


int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> vec = { 1,3,5,6,6,4,2,4 };

    erase_Vector_Numbers(vec,6);
    sort_Vector_Numbers(vec);
    vec.push_back(5);
    count_Unordered_Map_Numbers(vec);
    erase_Unordered_Map_Numbers(vec,5);
    erase_Unordered_Map_Numbers(vec,6);


	LogSystem* logger = LogSystem::getInstance();
	LogSystem* logger2 = LogSystem::getInstance();
	std::cout <<"address of two loggers " << logger << " " << logger2 << "\n";
	logger->setLogLevel(LogSystem::level_info);
	logger->log_Info("info!\n");
	logger->log_Warning("warning!\n");
	logger->log_Error("error!\n");

	logger->log_Info("info %02X\n",0x1c);

	

	TestSheet::Test_bracket_Is_Valid("()[]{}");

	{
		Timer t1;
		t1.add_Timer(100,std::bind(timer_callback));
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		t1.add_Timer(150, std::bind(func, 5));
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	test_Thread_Safe_Queue();
	
	test_Init_System();

	return 0;
}


