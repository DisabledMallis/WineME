#pragma once

#include <deque>
#include <functional>
#include <thread>

class Worker {
    std::deque<std::function<void()>> workQueue;
    std::thread innerThread;
public:
    Worker();
    void DoWork(std::function<void()> func);
};