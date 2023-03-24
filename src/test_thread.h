#ifndef TEST_THREAD_H
#define TEST_THREAD_H

#include <eventThread.h>

using namespace ethr;

class TestThread : public EventThread
{
public:
    TestThread();
    void callback(){std::cout<<"test thread callback!"<<std::endl;}
protected:
    void task() override;
};


#endif
