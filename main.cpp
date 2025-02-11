#include <iostream>
#include <windows.h>

#include "./src/Master.h"

void Input();
void PreDraw(GLFWwindow *window);

int main(int argc, char *argv[])
{
    GLFWwindow *PolyCalc = nullptr;
    Initialize InitialSetup(&PolyCalc);

    MyGui MyGui(PolyCalc);

    PreDraw(PolyCalc);
    while (!glfwWindowShouldClose(PolyCalc))
    {
        Input();
        MyGui.BeginFrame();

        MyGui.WindowConfig(PolyCalc);
        MyGui.Draw();

        glfwSwapBuffers(PolyCalc);
    }

    // Cleanup
    glfwDestroyWindow(PolyCalc);
    glfwTerminate();

    MyGui.Cleanup();
}

// Comment out the following for DEBUG
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    return main(__argc, __argv); // Forward Windows arguments to standard main
}

void Input()
{
    glfwPollEvents();
}

void PreDraw(GLFWwindow *window)
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}