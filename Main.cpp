#include <iostream>
#include <string>
#include "glfw3.h"
#include "asio.hpp"

class Person
{
public:
    Person() { hidden_name = "unknown"; };
    Person(std::string name) { hidden_name = name; };
    void work() { std::cout << hidden_name << " is working - useless." << std::endl; };
    void set_name(std::string name) { hidden_name = name; };
protected:
    std::string hidden_name;
};

class Specialist : public Person
{
public:
    Specialist() : Person() {};
    void work() { std::cout << hidden_name << " is working - succeess!" << std::endl; };
};

void glfwErrorCallback(int error, const char* description) {
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

int main() 
{
    //asio::basic_socket s = asio::basic_socket();
    glfwSetErrorCallback(glfwErrorCallback);

    if (!glfwInit()) {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1000, 1000, "fds", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
