# TinyProject Programming 2

## Project Overview

This repository contains the source code and documentation for the TinyProject in Programming 2, implemented individually. The project is divided into two parts:

* **Part A**: Matrix operations and linear system solver
* **Part B**: Linear regression for CPU performance prediction

## Table of Contents

* [Author](#author)
* [Repository Structure](#repository-structure)
* [Part A: Linear System Solver](#part-a-linear-system-solver)

  * [File Layout](#file-layout)
  * [Building and Running](#building-and-running)
* [Part B: Linear Regression](#part-b-linear-regression)

  * [File Layout](#file-layout-1)
  * [Building and Running](#building-and-running-1)
* [Tests](#tests)
* [Dependencies](#dependencies)
* [License](#license)

## Author

* Diêu Ngọc Thiên An - 10423192

## Repository Structure

```
LICENSE
README.md
tinyProject1.pdf    # Project report

/Part A
  ├─ Vector.h
  ├─ Vector.cpp
  ├─ Matrix.h
  ├─ Matrix.cpp
  ├─ LinearSystem.h
  ├─ LinearSystem.cpp
  ├─ PosSymLinSystem.h
  ├─ PosSymLinSystem.cpp
  ├─ Tests.h
  ├─ Tests.cpp
  └─ main.cpp          # Demonstration and solver interface

/Part B
  ├─ LinearRegression.h
  ├─ LinearRegression.cpp
  ├─ machine.names     # Dataset attribute names
  ├─ machine.txt       # Raw dataset file
  └─ main.cpp          # Training and evaluation driver
```

## Part A: Linear System Solver

Implement classes to manage vectors, matrices, and solve systems of linear equations.

### File Layout

* **Vector.h / Vector.cpp**: `Vector` class with memory management and overloaded operators.
* **Matrix.h / Matrix.cpp**: `Matrix` class with deep copy, arithmetic, determinant, inverse, and pseudo-inverse.
* **LinearSystem.h / LinearSystem.cpp**: `LinearSystem` class for solving Ax = b via Gaussian elimination.
* **PosSymLinSystem.h / PosSymLinSystem.cpp**: Derived class implementing Conjugate Gradient for symmetric positive definite systems.
* **Tests.h / Tests.cpp**: Unit tests covering vector/matrix operations and solvers.
* **main.cpp**: Example usage and command-line interface.

### Building and Running

```bash
cd Part\ A
# Compile Part A
g++ -std=c++11 Vector.cpp Matrix.cpp LinearSystem.cpp PosSymLinSystem.cpp Tests.cpp main.cpp -o solverA
# Run demos and tests
./solverA
```

## Part B: Linear Regression

Predict CPU performance using linear regression on the UCI Computer Hardware dataset.

### File Layout

* **LinearRegression.h / LinearRegression.cpp**: Implementation of linear regression using normal equations.
* **machine.names**: Attribute names description for the dataset.
* **machine.txt**: Dataset file containing 209 instances.
* **main.cpp**: Loads data, splits into training/testing, fits model, and reports RMSE.

### Building and Running

```bash
cd Part\ B
# Compile Part B
g++ -std=c++11 LinearRegression.cpp main.cpp -o regressorB
# Run regression (reads machine.txt in the same directory)
./regressorB
```

## Tests

* **Part A**: `Tests.cpp` includes unit tests for:

  * Vector and matrix operations
  * Determinant, inverse, pseudo-inverse
  * Gaussian elimination and Conjugate Gradient methods

## Dependencies

* Standard C++ library (C++11 or later)

## License

This project is released under the GNU General Public License v3.0. See [LICENSE](LICENSE) for details.
