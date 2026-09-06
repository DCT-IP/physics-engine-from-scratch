cmake_minimum_required(VERSION 3.20)

project(PhysicsEngine VERSION 0.1 LANGUAGES CXX)

# ==========================================================
# C++ Standard
# ==========================================================

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==========================================================
# Engine Sources
# ==========================================================

set(ENGINE_SOURCES
    Core/Math/Vec2.cpp
    Core/Math/Mat2.cpp
    Core/Math/MathUtils.cpp
    Core/Math/Vec3.cpp
    Core/Math/Mat3.cpp
    Core/Math/Vec4.cpp
    Core/Math/Mat4.cpp
    Core/Math/Transform2D.cpp
    Core/Math/Transform3D.cpp
    Core/Math/Quaternion.cpp
)

set(ENGINE_HEADERS
    Core/Math/Vec2.h
    Core/Math/Mat2.h
    Core/Math/MathUtils.h
    Core/Math/Vec3.h
    Core/Math/Mat3.h
    Core/Math/Vec4.h
    Core/Math/Mat4.h
    Core/Math/Transform2D.h
    Core/Math/Transform3D.h
    Core/Math/Quaternion.h
)

# ==========================================================
# Engine Library
# ==========================================================

add_library(PhysicsEngineCore
    ${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
)

target_include_directories(PhysicsEngineCore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/Math
)

# ==========================================================
# Demo
# ==========================================================

add_executable(PhysicsEngineDemo
    Demo/main.cpp
)

target_link_libraries(PhysicsEngineDemo
    PRIVATE
        PhysicsEngineCore
)

# ==========================================================
# Math Tests
# ==========================================================

enable_testing()

set(MATH_TEST_SOURCES
    Tests/Maths/Vec2Tests.cpp
    Tests/Maths/Mat2Tests.cpp
    Tests/Maths/Mat3Tests.cpp
    Tests/Maths/MathUtilsTests.cpp
    Tests/Maths/Vec3Tests.cpp
    Tests/Maths/Vec4Tests.cpp
    Tests/Maths/Mat4Tests.cpp
    Tests/Maths/Transform2DTests.cpp
    Tests/Maths/Transform3DTests.cpp
    Tests/Maths/QuaternionTests.cpp
)

foreach(TEST_SRC ${MATH_TEST_SOURCES})
    # Extracts target name from path (e.g. "QuaternionTests")
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WE)
    
    add_executable(${TEST_NAME} ${TEST_SRC})
    
    target_link_libraries(${TEST_NAME}
        PRIVATE
            PhysicsEngineCore
    )
    
    # Resolves M_PI missing scope errors on MSVC/MinGW
    target_compile_definitions(${TEST_NAME} PRIVATE _USE_MATH_DEFINES)
    
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()