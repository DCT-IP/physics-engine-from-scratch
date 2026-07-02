cmake_minimum_required(VERSION 3.20)

project(PhysicsEngine VERSION 0.1 LANGUAGES CXX)

# ==========================================================
# C++ Standard
# ==========================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================================
# Engine Sources
# ==========================================================

set(ENGINE_SOURCES
    Core/Math/Vec2.cpp
    Core/Math/Mat2.cpp
)

set(ENGINE_HEADERS
    Core/Math/Vec2.h
    Core/Math/Mat2.h
)

# ==========================================================
# Include Directories
# ==========================================================

include_directories(
    Core/Math
)

# ==========================================================
# Demo
# ==========================================================

add_executable(PhysicsEngineDemo
    Demo/main.cpp
    ${ENGINE_SOURCES}
)

# ==========================================================
# Tests
# ==========================================================

add_executable(Vec2Tests
    Tests/Vec2Tests.cpp
    ${ENGINE_SOURCES}
)

add_executable(Mat2Tests
    Tests/Mat2Tests.cpp
    ${ENGINE_SOURCES}
)