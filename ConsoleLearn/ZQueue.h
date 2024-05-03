#pragma once
#include <iostream>
#include <queue>
#include <mutex>

/**
* 对队列Queue的线程安全封装
* @param void safe_Push(T data)
* @param void safe_Pop()
*/
template<class T>
class Thread_Safe_Queue
{
private:
	std::queue<T> m_queue;
	std::mutex m_mtx;
public:
	Thread_Safe_Queue() {}
	~Thread_Safe_Queue() {}
	/**
	* 对队列Push函数的线程安全封装
	* @param T data 
	* @return void
	*/
	void safe_Push(T data);

	/**
	* 对队列Pop函数的线程安全封装
	* @param void
	* @return void
	*/
	void safe_Pop();
};

/**
* 对Thread_Safe_Queue线程安全队列Push数据
* @param Thread_Safe_Queue<T>& produce
* @return void
*/
template<typename T>
void producer(Thread_Safe_Queue<T>& produce);


/**
* 对Thread_Safe_Queue线程安全队列Pop数据
* @param Thread_Safe_Queue<T>& consume
* @return void
*/
template<typename T>
void consumer(Thread_Safe_Queue<T>& consume);

/**
* 对Thread_Safe_Queue线程安全队列封装的测试
* @param void
* @return void
*/
void test_Thread_Safe_Queue();
