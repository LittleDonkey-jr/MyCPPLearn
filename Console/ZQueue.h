#pragma once
#include <iostream>
#include <queue>
#include <mutex>

/**
* �Զ���Queue���̰߳�ȫ��װ
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
	* �Զ���Push�������̰߳�ȫ��װ
	* @param T data 
	* @return void
	*/
	void safe_Push(T data);

	/**
	* �Զ���Pop�������̰߳�ȫ��װ
	* @param void
	* @return void
	*/
	void safe_Pop();
};

/**
* ��Thread_Safe_Queue�̰߳�ȫ����Push����
* @param Thread_Safe_Queue<T>& produce
* @return void
*/
template<typename T>
void producer(Thread_Safe_Queue<T>& produce);


/**
* ��Thread_Safe_Queue�̰߳�ȫ����Pop����
* @param Thread_Safe_Queue<T>& consume
* @return void
*/
template<typename T>
void consumer(Thread_Safe_Queue<T>& consume);

/**
* ��Thread_Safe_Queue�̰߳�ȫ���з�װ�Ĳ���
* @param void
* @return void
*/
void test_Thread_Safe_Queue();
