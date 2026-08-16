# Physics Engine

A from-scratch 2D/3D Physics Engine written in Modern C++.

This repository documents the complete engineering journey of designing and implementing a reusable physics engine from the ground up. Rather than focusing on isolated programming exercises, every module is designed to become a permanent component of the engine.

The project follows a milestone-based development process where every subsystem is designed, implemented, tested, debugged, and integrated before progressing to the next stage.

---

## Objectives

- Build a reusable physics engine in Modern C++
- Develop engine-quality software architecture
- Implement mathematical foundations from scratch
- Understand physics simulation through implementation
- Practice modular software design
- Maintain production-style testing and debugging practices

---

## Development Philosophy

This project follows one guiding principle:

> Every line of code should either become part of the engine or directly contribute to building it.

Instead of writing temporary practice programs, each session produces reusable modules that remain part of the engine throughout its development.

Every development session follows a structured workflow:

1. Design the module
2. Plan the repository structure
3. Define the public API
4. Implement incrementally
5. Debug
6. Test
7. Refactor
8. Integrate into the engine

---

# Repository Structure

```
PhysicsEngine/
│
├── Core/
│   ├── Math/
│   ├── Utility/
│   └── ...
│
├── Physics/
│
├── Renderer/
│
├── Demo/
│
├── Tests/
│
├── Build/
│
├── CMakeLists.txt
├── LICENSE
├── .gitignore
└── README.md
```

# Engine Architecutre

The project is organized into independent modules
```
                     Physics Engine
                           │
     ┌─────────────────────┼─────────────────────┐
     │                     │                     │
    Core               Physics             Renderer
     │
     ├── Math
     │     ├── MathUtils
     │     ├── Vec2
     │     ├── Vec3
     │     ├── Vec4
     │     ├── Mat2
     │     ├── Mat3
     │     └── Mat4
     │
     └── Utilities
```
---

## Core

Reusable engine infrastructure.

Examples:

- Vector Mathematics
- Matrix Mathematics
- Utility Classes
- Core Data Types

---

## Physics

Physics simulation systems.

Examples:

- Particle System
- Forces
- Numerical Integrators
- Collision Detection
- Collision Resolution
- Rigid Bodies
- Constraints

---

## Renderer

Visualization layer for the engine.

Rendering is intentionally separated from the physics simulation so that either component can be modified independently.

---

## Demo

Small demonstration applications showcasing individual engine modules.

Implemented demonstrations:

- Math utility functions
- Vec2
- Vec3
- Vec4
- Mat2
- Mat3
- Mat4

Planned demonstrations:

- Transform2D
- Transform3D
- Quaternion
- Particle simulation
- Force generators
- Numerical integration
- Collision detection
- Rigid body dynamics

---

## Tests

Unit tests used to verify the correctness of every engine module.

Implemented test suites:

- MathUtilsTests
- Vec2Tests
- Vec3Tests
- Vec4Tests
- Mat2Tests
- Mat3Tests
- Mat4Tests

Every public feature added to the engine is accompanied by corresponding tests before integration.
---

# Project Roadmap

---

## Milestone 1 — Core Mathematics

### Mathematics' Utility

- [x] MathUtils

### Vector Mathematics

- [x] Vec2
- [x] Vec3
- [x] Vec4

### Matrix Mathematics

- [x] Mat2
- [x] Mat3
- [x] Mat4

### Transformations

- [x] Transform2D
- [ ] Transform3D

### Rotations

- [ ] Quaternion

---

## Milestone 2 — Simulation Core

- [ ] Time Management
- [ ] Particle
- [ ] Particle System
- [ ] Force Generators
- [ ] Numerical Integrators

---

## Milestone 3 — Collision

- [ ] Bounding Volumes
- [ ] Broad Phase
- [ ] Narrow Phase
- [ ] Collision Detection
- [ ] Collision Resolution

---

## Milestone 4 — Rigid Body Dynamics

- [ ] Rigid Body
- [ ] Angular Motion
- [ ] Constraints
- [ ] Joints

---

## Milestone 5 — Engine Systems

- [ ] Spatial Partitioning
- [ ] Memory Management
- [ ] Optimization
- [ ] Profiling
- [ ] Multithreading

---

## Milestone 6 — Rendering

- [ ] Debug Renderer
- [ ] SDL2 Integration
- [ ] OpenGL Renderer
- [ ] Camera System
- [ ] Scene Visualization

---

# Technologies

Implemented :

- Modern C++17
- CMake
- Standard Template Library (STL)

Planned:

- SDL2
- OpenGL
- GoogleTest (or Catch2)

---

# Building and Running

## Prerequisites

- C++17 compatible compiler
- CMake 3.20 or newer

---

## Configure

```bash
cmake -S . -B Build -G "MinGW Makefiles"
```

---

## Build

Build individual modules:

```bash
cmake --build Build --target PhysicsEngineDemo

cmake --build Build --target MathUtilsTests

cmake --build Build --target Vec2Tests
cmake --build Build --target Vec3Tests
cmake --build Build --target Vec4Tests

cmake --build Build --target Mat2Tests
cmake --build Build --target Mat3Tests
cmake --build Build --target Mat4Tests
cmake --build Build --target Transform2DTests
```
---

## Run

Run the demo:

```bash
./Build/PhysicsEngineDemo.exe
```

Run the test suite:

```bash
./Build/Vec2Tests.exe
./Build/Vec3Tests.exe
./Build/Vec4Tests.exe

./Build/Mat2Tests.exe
./Build/Mat3Tests.exe
./Build/Mat4Tests.exe
./Build/Transform2dTests.exe
```

---

## Development Workflow

Whenever changes are made to the source code, follow this workflow:

```
Edit Source Code
        │
        ▼
Build Project
        │
        ▼
Run Demo
        │
        ▼
Run Tests
        │
        ▼
Debug
        │
        ▼
Commit Changes
```

Example:

```bash
cmake --build Build --target PhysicsEngineDemo

cmake --build Build --target Vec2Tests

cmake --build Build --target Mat2Tests

cmake --build Build --target MathUtilsTests

cmake --build Build --target Transform2DTests

./Build/PhysicsEngineDemo.exe

./Build/Vec2Tests.exe

./Build/Mat2Tests.exe

./Build/MathUtilsTests.exe

./Build/Transform2DTests.exe
```

> **Note:** Editing a source file does **not** automatically update the executable. The project must be rebuilt before running the latest changes.

---

# License

This project is released under the MIT License.