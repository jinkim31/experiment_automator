#ifndef APPLICATION_H
#define APPLICATION_H

#include <entry_point.h>
#include "test_thread.h"

class Application : public EntryPoint
{
public:
    void callback();
protected:
    void onStart() override;
    void onRender() override;
    void onTerminate() override;
private:
    TestThread testThread;
};

#endif
