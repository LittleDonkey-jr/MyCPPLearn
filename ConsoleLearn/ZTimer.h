#pragma once
#include <chrono>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

struct timer_Node
{
	std::function<void()> cb;
	std::chrono::high_resolution_clock::time_point expire_time;
	// 可以提供一个比较函数对象，用于比较expire_time  
	struct Compare {
		bool operator()(const timer_Node& lhs, const timer_Node& rhs) const {
			return lhs.expire_time > rhs.expire_time; // 注意这里是>，因为我们想要升序队列  
		}
	};
};

class Timer 
{
private:
	std::chrono::high_resolution_clock::time_point start;
	std::thread m_thread = std::thread(&Timer::tick, this);
	std::mutex m_mtx;
	std::condition_variable m_cv;
	std::priority_queue<timer_Node, std::vector<timer_Node>, timer_Node::Compare> m_timer_node_pq;
	bool stop = false;

public:
	Timer();
	~Timer();
	void add_Timer(int timeout,const std::function<void()>& cb);
	void stop_Timer();
	void tick();
};

void timer_callback();