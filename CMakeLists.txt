cmake_minimum_required(VERSION 3.26.0)
project(dear_mygui_boilerplate VERSION 1.0.0)

add_executable(dear_mygui_boilerplate
    src/main.cpp

    dependencies/glad.c

    dependencies/imgui/imgui.cpp
    dependencies/imgui/imgui_draw.cpp
    dependencies/imgui/imgui_tables.cpp
    dependencies/imgui/imgui_widgets.cpp
    dependencies/imgui/backends/imgui_impl_glfw.cpp
    dependencies/imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(dear_mygui_boilerplate PRIVATE
    dependencies
    dependencies/glad
    dependencies/imgui
    dependencies/imgui/backends

    include/core
    include/utils
)



# Set the output directory for the executable to "bin" inside the build folder
set_target_properties(dear_mygui_boilerplate PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)



# Define paths to the directories
set(SOURCE_RES_DIR "${CMAKE_SOURCE_DIR}/res")
set(BUILD_RES_DIR "${CMAKE_BINARY_DIR}/res")

# Create a custom command to copy the res directory
add_custom_command(
    TARGET dear_mygui_boilerplate PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${SOURCE_RES_DIR} ${BUILD_RES_DIR}
)

set_target_properties(dear_mygui_boilerplate PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)




if(WIN32)
    target_link_libraries(dear_mygui_boilerplate "${CMAKE_SOURCE_DIR}/dependencies/GLFW/libglfw3.a")
else()
    target_link_libraries(dear_mygui_boilerplate "${CMAKE_SOURCE_DIR}/dependencies/GLFW/libglfw3-compiled-mint.a")
endif()




set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")



# project definitions

target_compile_definitions(dear_mygui_boilerplate PRIVATE PROJECT_WINDOW_NAME="Dear MyGui Boilerplate") # (PROJECT_WINDOW_NAME) Window name 
target_compile_definitions(dear_mygui_boilerplate PRIVATE PROJECT_ICON_PATH="res/img/icon.png") # (ICOPROJECT_ICON_PATHN_PATH) path to the window icon both in output and project folder 
