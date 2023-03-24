#include "test_thread.h"
#include "application.h"

TestThread::TestThread()
{
    setLoopFreq(1);
}

void TestThread::task()
{
    EventThread::callInterThread(&Application::callback);
    std::cout<<"test thread task!"<<std::endl;
}
