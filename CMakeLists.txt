# CMakeList.txt : CMake project for suspension-demo-opengl, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("suspension-demo-opengl")

# Add GLFW as subdirectory
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

# Add source to this project's executable.
add_executable (suspension-demo-opengl "src/main.cpp" "include/glad/glad.h" "include/KHR/khrplatform.h" "src/glad.c"         "include/track.h" "src/track.cpp"   "include/game.h" "src/game.cpp" "include/shader.h" "src/shader.cpp" "include/wheel.h" "src/wheel.cpp" "include/glutils.h" "src/glutils.cpp")

# Find OpenGL
find_package(OpenGL REQUIRED)

# Link GLFW and necessary system libs
target_link_libraries(suspension-demo-opengl glfw OpenGL::GL glm::glm-header-only)
target_include_directories(suspension-demo-opengl PRIVATE include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET suspension-demo-opengl PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
