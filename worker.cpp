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
}

void Worker::DoWork(std::function<void()> func) {
    this->workQueue.push_back(func);
}