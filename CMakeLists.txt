cmake_minimum_required(VERSION 3.20)

project(PhysicsEngine VERSION 0.1 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================
# Demo Executable
# ============================

add_executable(PhysicsEngineDemo
    Demo/main.cpp
    Core/Math/Vec2.cpp
)

target_include_directories(PhysicsEngineDemo PRIVATE
    Core/Math
)

# ============================
# Test Executable
# ============================

add_executable(Vec2Tests
    Tests/Vec2Tests.cpp
    Core/Math/Vec2.cpp
)

target_include_directories(Vec2Tests PRIVATE
    Core/Math
)