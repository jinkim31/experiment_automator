#include "application.h"
#include "custom_widgets.h"
#include "test_thread.h"

void Application::onStart()
{
    testThread.start();
}

void Application::onRender()
{
    Widget::beginDockspace();

    ImGui::ShowDemoWindow();
    ImPlot::ShowDemoWindow();

    ImGui::End();
}

void Application::onTerminate()
{
    testThread.stop();
}

void Application::callback()
{
    std::cout<<"callback!"<<std::endl;
    EventThread::callInterThread(&TestThread::callback);
}
