#pragma once
#ifndef OPENGLINIT_H
#define OPENGLINIT_H

#include <iostream>

class Initialize
{
private:
    const int ScreenHeight = 380;
    const int ScreenWidth = 285;

public:
    Initialize(GLFWwindow **window)
    {
        // GLFW Initialization
        if (!glfwInit())
        {
            std::cerr << "GLFW::INITIALIZATION::FAILED" << std::endl;
            exit(1);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);    // GLFW_FALSE Hides the window
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // GLFW_FALSE Prevents window resizing
        glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
        // glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); // Hides the title bar

        // Window creation / making current context
        *window = glfwCreateWindow(ScreenWidth, ScreenHeight, "Urethane Calculator", NULL, NULL);
        if (*window == nullptr)
        {
            std::cerr << "WINDOW::CREATION::FAILED" << std::endl;
            glfwTerminate();
            exit(1);
        }
        glfwMakeContextCurrent(*window);

        glfwSwapInterval(1);

        glfwSetFramebufferSizeCallback(*window, FramebufferCallback);

        // GLAD Initialization
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "GLAD::INITIALIZATION::FAILED" << std::endl;
            glfwTerminate();
            exit(1);
        }
    }
    ~Initialize() {}

    static void FramebufferCallback(GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
        glfwSetWindowSize(window, width, height);
        std::cout << "Window width -> [" << width << "]" << std::endl;
        std::cout << "Window height -> [" << height << "]" << std::endl;
    }
};
#endif