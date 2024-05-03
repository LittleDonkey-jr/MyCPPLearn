#include "ZQueue.h"

template<class T>
void Thread_Safe_Queue<T>::safe_Push(T data)
{
	std::lock_guard<std::mutex> lock(m_mtx);
	this->m_queue.push(data);
	std::cout << "push data success!\n";
}
template<class T>
void Thread_Safe_Queue<T>::safe_Pop()
{
	if (!m_queue.empty())
	{
		std::lock_guard<std::mutex> lock(m_mtx);
		if (!m_queue.empty())
		{
			m_queue.pop();
			std::cout << "pop data success!\n";
		}
	}
}

template<typename T>
void producer(Thread_Safe_Queue<T>& produce)
{
	for (int i = 0; i < 10; i++)
	{
		produce.safe_Push(1);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
template<typename T>
void consumer(Thread_Safe_Queue<T>& consume)
{
	for (int i = 0; i < 12; i++)
	{
		consume.safe_Pop();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void test_Thread_Safe_Queue()
{
	Thread_Safe_Queue<int> my_stack;
	std::thread t1(producer<int>, std::ref(my_stack));
	std::thread t2(consumer<int>, std::ref(my_stack));
	std::thread t3(consumer<int>, std::ref(my_stack));
	std::thread t4(consumer<int>, std::ref(my_stack));
	std::thread t5(consumer<int>, std::ref(my_stack));
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
}