#pragma once
#ifndef MASTER_H
#define MASTER_H

// Standard includes
#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>

// ImGui headers
// #include "./ext/ImGui/imgui.h"
// #include "./ext/ImGui/imgui_impl_glfw.h"
// #include "./ext/ImGui/imgui_impl_opengl3.h"
// ImGui Docking headers
#include "./ext/ImGuiDock/imgui.h"
#include "./ext/ImGuiDock/imgui_impl_glfw.h"
#include "./ext/ImGuiDock/imgui_impl_opengl3.h"

// GLAD/GLFW headers
#include "./ext/GLAD/glad.h"
#include "./ext/GLFW/glfw3.h"

// OpenGL Headers
#include "./src/OpenGLInit.hpp"

// Project headers
#include "./src/gui/myGui.hpp"

#endif