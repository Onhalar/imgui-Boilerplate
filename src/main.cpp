// project resources
#include <config.h>

// modules
#include "render.cpp"

void setup();
void mainloop();
void terminate();

int main(int argc, char* argv[]) {

    // setup the system path from run arguments for later use
    if (argc > 0) { setupSystemPath(argv[0]); } 
    
    setup();

    mainloop();

    terminate();

    return 0;
}

void setupIcon() {
    GLFWimage icon;
    icon.pixels = stbi_load((projectPath/PROJECT_ICON_PATH).string().c_str(), &icon.width, &icon.height, 0, 4); //rgba channels 
    
    if (icon.pixels) {
        glfwSetWindowIcon(masterWindow, 1, &icon);
        stbi_image_free(icon.pixels);
    }
}

void setup() {
    // Initialize GLFW library (must be done before creating windows or contexts)
    glfwInit();

    // Set OpenGL version to 3.3 Core Profile (modern OpenGL)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Create a masterWindow with 800x600 dimensions and an OpenGL context
    masterWindow = glfwCreateWindow(800, 600, PROJECT_WINDOW_NAME, nullptr, nullptr);

    // Make the OpenGL context current for rendering
    glfwMakeContextCurrent(masterWindow);

    // Load all OpenGL function pointers using glad
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // Initialize ImGui context (must be done before using any ImGui features)
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Access ImGui's I/O structure (useful for config/input later if needed)
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Initialize ImGui's GLFW backend (handles input/events)
    ImGui_ImplGlfw_InitForOpenGL(masterWindow, true);

    // Initialize ImGui's OpenGL3 backend with GLSL version string
    ImGui_ImplOpenGL3_Init("#version 330");

    glfwSwapInterval(VSync);

    setupIcon();
}

void mainloop() {

    render();

    // Main application loop — runs until the masterWindow is closed
    while (!glfwWindowShouldClose(masterWindow)) {
        // handles the Timer.hpp scheduler
        handleSchedule();

        // Poll and process masterWindow/input events (keyboard, mouse, etc.)
        glfwPollEvents();
    }
}

void terminate() {
    // Cleanup ImGui OpenGL backend
    ImGui_ImplOpenGL3_Shutdown();

    // Cleanup ImGui GLFW backend
    ImGui_ImplGlfw_Shutdown();

    // Destroy the ImGui context
    ImGui::DestroyContext();

    // Destroy the masterWindow
    glfwDestroyWindow(masterWindow);

    // Terminate GLFW library (cleanup internal resources)
    glfwTerminate();
}
