#ifndef PROJECT_CONFIG_FILE
#define PROJECT_CONFIG_FILE

// Load OpenGL functions using glad
#include <glad/glad.h>

// Include GLFW for masterWindow/context/input handling
#include <GLFW/glfw3.h>

// Core ImGui header
#include <imgui/imgui.h>

// ImGui platform/backend bindings for GLFW and OpenGL3
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

// image manipulation (just icon for this example)
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <Timer.hpp>

// STD includes
#include <filesystem>
#include <chrono>

using namespace std::chrono;

using path = std::filesystem::path;
using RGBA = float[4];

int targetFPS = 60;
int VSync = 0;

float deltaTime;

GLFWwindow* masterWindow;
RGBA backgroundColor = {0.1f, 0.1f, 0.1f, 1.0f};

path projectPath = "";

void setupSystemPath(path runningPath) { projectPath = runningPath.parent_path().parent_path(); } // ../src(bin)/main.cpp (.exe)

#endif