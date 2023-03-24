#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#include "eventThread.h"

using namespace ethr;

class EntryPoint : public EventThread
{
private:
    void task() final;
public:
    virtual void onRender()=0;
    void update();
    void onImGuiCreate();
    void onImGuiDestroy();
};


#endif
