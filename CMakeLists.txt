cmake_minimum_required(VERSION 3.0)
project(serial_monitor)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_COMMON
        # imgui
        lib/imgui/imgui.cpp
        lib/imgui/imgui_widgets.cpp
        lib/imgui/imgui_tables.cpp
        lib/imgui/imgui_demo.cpp
        lib/imgui/imgui_draw.cpp
        # implot
        lib/implot/implot.cpp
        lib/implot/implot_items.cpp
        lib/implot/implot_demo.cpp
        # user
        src/custom_widgets.cpp
        entry_point/entry_point.cpp
        src/application.cpp
        src/test_thread.cpp
)

add_subdirectory(lib/serial)
include_directories(lib/serial/include)
add_subdirectory(lib/event_thread)

if(APPLE)
        link_directories("/opt/homebrew/lib")
        include_directories("/opt/homebrew/include")

        add_executable(${PROJECT_NAME}
                entry_point/main_glfw_metal.mm
                ${SRC_COMMON}
                lib/imgui/backends/imgui_impl_glfw.cpp
                lib/imgui/backends/imgui_impl_metal.mm
        )
        target_link_libraries(${PROJECT_NAME}
                "-framework Metal"
                "-framework MetalKit"
                "-framework AppKit"
                "-framework Foundation"
                "-framework QuartzCore"
                "glfw"
                "serial"
                event_thread
        )
elseif(UNIX)
        add_executable(${PROJECT_NAME}
                entry_point/main_glwf_opengl2.cpp
                ${SRC_COMMON}
                lib/imgui/backends/imgui_impl_glut.cpp
                lib/imgui/backends/imgui_impl_opengl2.cpp
        )
        target_link_libraries(${PROJECT_NAME}
                glut
                GL
                serial
                event_thread
        )
else()
        find_package(FreeGLUT REQUIRED PATHS "C:/msys64/mingw64")
        find_library(glfw3 NAMES glwf3 libglfw3 PATHS "C:/GLFW/lib-mingw-w64" REQUIRED)
        add_executable(${EXECUTABLE_NAME}
                entry_point/main_glwf_opengl2.cpp
                ${SRC_COMMON}
                lib/imgui/backends/imgui_impl_opengl2.cpp
                lib/imgui/backends/imgui_impl_glfw.cpp
                )
        target_include_directories(${PROJECT_NAME} PRIVATE "C:/GLFW/include")
        target_link_libraries(${PROJECT_NAME}
                FreeGLUT::freeglut
                ${glfw3}
                serial
                event_thread
        )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC
        lib/imgui
        lib/imgui/backends
        lib/implot
        entry_point
)