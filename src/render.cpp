// project resources
#include <config.h>

#include "gui.cpp"

#include <iostream>

const microseconds frameDuration(1'000'000 / targetFPS); // 1,000,000 μs / 60 = 16666 μs = 16.666 m

void setupGUIframe() {
    // Start a new ImGui frame (OpenGL backend)
    ImGui_ImplOpenGL3_NewFrame();

    // Start a new ImGui frame (GLFW backend)
    ImGui_ImplGlfw_NewFrame();

    // Begin a new ImGui frame (internal setup)
    ImGui::NewFrame();
        
    // this functions will setup the gui (custom) - where the imgui functions will be called
    GUImain();

    // Complete and render the ImGui frame
    ImGui::Render();
}

void render() {
    auto frameStart = high_resolution_clock::now();

    // sets up and renders a gui frame
    setupGUIframe();

    // Get the current size of the framebuffer (masterWindow in pixels)
    int display_w, display_h;
    glfwGetFramebufferSize(masterWindow, &display_w, &display_h);

    // Set the OpenGL viewport to match the framebuffer size
    glViewport(0, 0, display_w, display_h);

    // Clear the screen with a dark gray background
    glClearColor(
        backgroundColor[0],
        backgroundColor[1],
        backgroundColor[2],
        backgroundColor[3]
    );

    glClear(GL_COLOR_BUFFER_BIT);

    // Render ImGui's draw data using OpenGL
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Swap the front and back buffers (show the rendered frame)
    glfwSwapBuffers(masterWindow);

    // Calculate frame time
    auto frameEnd = high_resolution_clock::now();
    auto elapsed = duration_cast<microseconds>(frameEnd - frameStart);

    static decltype(frameStart) lastTime;

    // here just so everything doesn't fly 10 000 km off the screen
    static bool isFirstFrame = true;
    if (isFirstFrame) {
        lastTime = frameStart;
        isFirstFrame = false;
    }

    deltaTime =  duration_cast<microseconds>(frameStart - lastTime).count() / 1'000'000.0f;

    std::cout << 1/deltaTime << std::endl;
        
    Timer(frameDuration - elapsed, render);

    lastTime = frameEnd;
}