#pragma once
#include "glad.h"
#include "glfw3.h"

namespace shgame::rendering
{
	class Renderer
	{
	private:
		GLFWwindow* window;
		bool setVisible();
		void mainLoop();

	public:
		Renderer();
		void run();
	};
}