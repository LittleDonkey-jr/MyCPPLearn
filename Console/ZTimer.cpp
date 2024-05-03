#include "ZTimer.h"

Timer::Timer()
{
	this->start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
	this->stop_Timer();
	if (m_thread.joinable()) {
		m_thread.join();
	}
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "time cost " << duration.count() << " s" << "\n";
}



void Timer::add_Timer(int timeout, const std::function<void()>& cb)
{
	auto newTimeoutPoint = std::chrono::high_resolution_clock::now() + std::chrono::milliseconds(timeout);

	std::lock_guard<std::mutex> lock(m_mtx);	
	timer_Node newNode;
	newNode.cb = cb;
	newNode.expire_time = newTimeoutPoint;
	m_timer_node_pq.push(newNode);
	
	m_cv.notify_all();

}

void Timer::stop_Timer() {
	std::lock_guard<std::mutex> lock(m_mtx);
	stop = true;
	m_cv.notify_all();
}

void Timer::tick()
{
	while (true) {
		std::unique_lock<std::mutex> lock(m_mtx);
		m_cv.wait(lock, [this] { return !m_timer_node_pq.empty() || stop; }); // 等待直到有计时器或停止信号
		if (stop && m_timer_node_pq.empty()) {
			// 当停止被请求且没有计时器时，真正结束循环
			return;
		}

		if (std::chrono::duration_cast<std::chrono::milliseconds>(m_timer_node_pq.top().expire_time - std::chrono::high_resolution_clock::now()).count() > 0) {
			continue;
		}
		if (!m_timer_node_pq.empty())
		{
			m_timer_node_pq.top().cb();
			m_timer_node_pq.pop();
		}
		lock.unlock();
	}
}

void timer_callback()
{
	std::cout << "running timer callback function\n";
}