#include "entry_point.h"

void EntryPoint::update()
{
    handleQueuedEvents();
    onRender();
}

void EntryPoint::task(){}

void EntryPoint::onImGuiCreate()
{
    onStart();
}

void EntryPoint::onImGuiDestroy()
{
    onTerminate();
}
