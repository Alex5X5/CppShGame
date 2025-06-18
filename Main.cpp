#include "glad.h"
#include "Libraries/includes/include/glfw3.h"
#include <windows.h>
#include <iostream>
#include <list>
#include "Renderer.h"

void glfwErrorCallback(int error, const char* description) {
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}



int main(int argc,      // Number of strings in array argv
    char* argv[],   // Array of command-line argument strings
    char* envp[])  // Array of environment variable strings
{
    using namespace std;
    int count;
    // Display each command-line argument.
    list<string> _args = {};
    //cout << "\nCommand-line arguments:\n";

    //asio::io_context my_context;
    //asio::ip::tcp::acceptor acceptor(my_context);
    //asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), 1000);
    //acceptor.open(endpoint.protocol());
    //acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
    //acceptor.bind(endpoint);
    //acceptor.listen();

    
    shgame::rendering::Renderer r = shgame::rendering::Renderer();
    r.run();
}

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
