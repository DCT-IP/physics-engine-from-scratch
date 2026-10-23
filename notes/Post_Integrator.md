# Physics Engine — Milestone 2 Progress

## 23-10-2026 — 21:27
### Integrator Architecture

- Removed the standalone Integrator implementation as the integrator abstraction evolved into a polymorphic base class.
- Established a base framework that allows different numerical integration methods to be implemented and extended naturally.
- `SemiImplicitEuler` implements the integrator interface and handles the numerical integration of bodies.

---

## 23-10-2026 — 21:48
### Force Generation

- Refactored the architecture by establishing an abstract `ForceGenerator` interface.
- Implemented concrete force generators:
  - `ConstantForce`
  - `Gravity`
- This design allows new force-generation mechanisms to be introduced without changing the core integration logic.

---

## 23-10-2026 — 22:27
### BodySystem

The goal of `BodySystem` is to connect the existing `SemiImplicitEuler` integrator, `Gravity`, and `ConstantForce` components.

- Provides a single interface for managing and updating a system of bodies.
- Uses `std::unique_ptr` to allow `BodySystem` to own and safely manage the lifetimes of its bodies.
- ForceGenerator instances were initially kept externally owned, with `BodySystem` retaining non-owning references to them.
- `SemiImplicitEuler` is owned by `BodySystem`.

#### Implemented `update(dt)`

1. Apply all registered force generators to their associated bodies.
2. Integrate every body using the selected integrator.
3. Clear each body's accumulated forces after integration.

- Added tests to verify body management, force application, and system updates.

---

## 23-10-2026 — 23:03
### Time Management

The next step was to introduce the concept of time into the simulation.

Distinguished between two kinds of time:

- **Real Time:** Time measured using the computer's clock.
- **Simulation Time:** Time advanced by the physics simulation.

Implemented the `Time` class using `std::chrono::steady_clock` to measure elapsed real time and frame delta time.

---

## 23-10-2026 — 23:21
### Fixed Timestep

Recognized that simply measuring elapsed time is insufficient for consistent physics simulation.

- Introduced `FixedTimestep` to accumulate frame delta time and determine how many fixed physics updates must execute.
- The accumulator allows the simulation to process zero, one, or multiple physics steps per rendered frame.
- Added a maximum substep limit to prevent excessive catch-up work when the simulation falls behind.
- Implemented reset functionality and tests for accumulation, substep limits, and invalid inputs.

---

## 24-10-2026 — 00:07
### SimulationWorld

Introduced `SimulationWorld` as the top-level coordinator for simulation components.

- Connected `BodySystem` and `FixedTimestep` behind a unified interface.
- Added world-level body creation, force-generator registration, time advancement, and state queries.
- `SimulationWorld` owns its force generators, while `BodySystem` retains non-owning references to them.
- This ownership arrangement ensures registered force generators remain alive for as long as the world needs them.
- The simulation can now be advanced using frame delta time while physics updates execute at a fixed timestep.

---

# Final Architecture — Milestone 2

## 1. Core/Math

Provides the mathematical foundation used by the physics engine:

- Vectors (`Vec2`, `Vec3`, `Vec4`)
- Matrices (`Mat2`, `Mat3`, `Mat4`)
- Transformations
- Quaternions
- Mathematical utility functions

## 2. Core/Time

**Class:** `Time`

- Measures real elapsed time using `std::chrono::steady_clock`.
- Tracks frame delta time and elapsed time.
- Supplies timing information that can be used by the application or simulation loop.

## 3. Physics/Body

**Class:** `Body`

- Stores position, velocity, acceleration, mass, and accumulated force.
- Accepts forces through `applyForce()`.
- Provides state accessors and mass-related calculations.
- Accumulates forces until the integration step processes and clears them.

## 4. Physics/Integrator

**Base class:** `Integrator`

**Implementation:** `SemiImplicitEuler`

- Defines a polymorphic interface for numerical integration.
- `SemiImplicitEuler` updates acceleration, velocity, and position.
- The abstraction allows additional integration methods to be introduced later.

## 5. Physics/ForceGenerator

**Base class:** `ForceGenerator`

**Implementations:**

- `Gravity`
- `ConstantForce`

Responsibilities:

- Defines a common interface for applying forces to bodies.
- `Gravity` calculates gravitational force from mass and gravitational acceleration.
- `ConstantForce` applies a specified force vector.
- Additional force generators can be implemented independently.

## 6. Physics/BodySystem

**Class:** `BodySystem`

- Owns bodies using `std::unique_ptr`.
- Stores non-owning registrations to force generators.
- Owns its `SemiImplicitEuler` integrator.
- Applies registered forces and integrates bodies through `update(dt)`.
- Provides a single interface for updating a collection of bodies.

## 7. Physics/FixedTimestep

**Class:** `FixedTimestep`

- Accumulates frame delta time.
- Executes physics updates using a constant timestep.
- Supports multiple physics steps per frame when necessary.
- Limits the maximum number of substeps to control catch-up work.
- Discards excess whole-step backlog when the configured limit is reached, retaining only the fractional remainder.

## 8. Physics/SimulationWorld

**Class:** `SimulationWorld`

- Acts as the top-level simulation coordinator.
- Owns its `BodySystem` and `FixedTimestep`.
- Owns registered force generators, keeping them alive while `BodySystem` references them.
- Provides a unified interface to:
  - Add bodies.
  - Register forces.
  - Advance simulation time.
  - Query simulation state.

---

# Architecture Flow

```text
Application / Main Loop
        |
        | frameDeltaTime
        v
  SimulationWorld
        |
        v
   FixedTimestep
        |
        | zero or more fixed physics steps
        v
 BodySystem.update(fixedDeltaTime)
        |
        +--> Apply registered ForceGenerators
        |           |
        |           +--> Gravity
        |           |
        |           +--> ConstantForce
        |
        +--> Integrator
                    |
                    +--> SemiImplicitEuler
                                |
                                +--> Update acceleration
                                |
                                +--> Update velocity
                                |
                                +--> Update position
        |
        +--> Clear accumulated forces
```