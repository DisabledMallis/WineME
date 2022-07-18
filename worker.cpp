#include "worker.h"

Worker::Worker() {
    this->innerThread = std::thread([&](){
        while(true) {
            if(!workQueue.empty()) {
                std::function<void()> func = workQueue.front();
                func();
                workQueue.pop_front();
            } else {
                usleep(10);
            }
        }
    });
    this->innerThread.detach();
}

Worker::~Worker() {
    this->innerThread.~thread();
}

void Worker::DoWork(std::function<void()> func) {
    this->workQueue.push_back(func);
}