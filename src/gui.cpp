// project resources
#include <config.h>

void GUImain() {
    // Make a fullscreen invisible window (no title bar, background, etc.)
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

    ImGui::Begin("TextOverlay", nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoInputs |
        ImGuiWindowFlags_NoBackground
    );

    const char* text = "Hello, world!";
    ImVec2 textSize = ImGui::CalcTextSize(text);
    ImVec2 screenSize = ImGui::GetIO().DisplaySize;

    // Center text in the middle of the screen
    ImGui::SetCursorPos(ImVec2(
        (screenSize.x - textSize.x) * 0.5f,
        (screenSize.y - textSize.y) * 0.5f
    ));

    ImGui::Text(text);

    ImGui::End();
}