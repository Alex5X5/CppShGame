#include <iostream>
#include <string>
#include "glfw3.h"
#include "asio.hpp"
//#include "glad/glad.h"


class Person
{
public:
    Person() { hidden_name = "unknown"; };
    Person(std::string name) { hidden_name = name; };
    void work() {
        std::cout << hidden_name << " is working - useless." << std::endl; };
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
    using namespace asio;
    try
    {
        asio::io_context io_context(1);

        asio::signal_set signals(io_context, SIGINT, SIGTERM);
        signals.async_wait([&](auto, auto) { io_context.stop(); });

        //co_spawn(io_context, listener(), asio::detached);

        io_context.run();
    }
    catch (std::exception& e)
    {
        std::printf("Exception: %s\n", e.what());
    }
}

//int main(int argc,      // Number of strings in array argv
//    char* argv[],   // Array of command-line argument strings
//    char* envp[])  // Array of environment variable strings
//{
//    using namespace std;
//    int count;
//    // Display each command-line argument.
//    list<string> _args = {};
//    //cout << "\nCommand-line arguments:\n";
//    
//    for (count = 0; count < argc; count++)
//        if (argv[count] == "a") {
//            std::cout << argv[count];
//        }
//}

int maien(int argc, char* argv[], char* envp[])
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
        //glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(float), nullptr);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
