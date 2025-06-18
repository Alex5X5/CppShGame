#include <iostream>
#include <string>
#include "Renderer.h"

void errorCallback(int error_code, const char* description)
{
    std::cerr << "GLFW Error (" << error_code << "): " << description << std::endl;
}

shgame::rendering::Renderer::Renderer()
{
    glfwSetErrorCallback(errorCallback);

    setVisible();
}


bool shgame::rendering::Renderer::setVisible()
{
    if (!glfwInit())
    {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1000, 1000, "fds", nullptr, nullptr);


    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    return true;
}

void shgame::rendering::Renderer::run()
{
    while (!glfwWindowShouldClose(window)) {
        mainLoop();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void shgame::rendering::Renderer::mainLoop()
{
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}