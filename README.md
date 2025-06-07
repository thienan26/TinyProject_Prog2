=# TinyProject Programming 2

## Project Overview

This repository contains the source code and documentation for the TinyProject in Programming 2, implemented individually. The project is organized into two parts:

* **Part A**: Matrix operations and linear system solver
* **Part B**: Linear regression for CPU performance prediction

## Table of Contents

* [Author](#author)
* [Repository Structure](#repository-structure)
* [Part A: Linear System Solver](#part-a-linear-system-solver)

  * [Vector Class](#vector-class)
  * [Matrix Class](#matrix-class)
  * [LinearSystem Class](#linearsystem-class)
  * [PosSymLinSystem Class](#possymlinssystem-class)
  * [Underdetermined/Overdetermined Systems](#underdeterminedoverdetermined-systems)
  * [Building and Running](#building-and-running)
* [Part B: Linear Regression](#part-b-linear-regression)

  * [Dataset](#dataset)
  * [Regression Model](#regression-model)
  * [Training and Evaluation](#training-and-evaluation)
  * [Building and Running](#building-and-running-1)
* [Tests](#tests)
* [Dependencies](#dependencies)
* [License](#license)

## Author

* Diêu Ngọc Thiên An - Student ID: 10423192
* GitHub: [thienan26](https://github.com/thienan26)

## Repository Structure

```
/Part_A
  ├─ Vector.h
  ├─ Vector.cpp
  ├─ Matrix.h
  ├─ Matrix.cpp
  ├─ LinearSystem.h
  ├─ LinearSystem.cpp
  ├─ PosSymLinSystem.h
  ├─ PosSymLinSystem.cpp
  ├─ main.cpp          # Demonstration and solver interface
  └─ tests.cpp         # Unit tests for Part A

/Part_B
  ├─ LinearRegression.h
  ├─ LinearRegression.cpp
  ├─ main.cpp          # Training and evaluation driver
  └─ dataset.csv       # Computer Hardware dataset (209 instances)

README.md               # This file
LICENSE                 # GNU GPL v3
```

## Part A: Linear System Solver

Implement classes to manage vectors, matrices, and solve systems of linear equations.

### Vector Class

* Manages a dynamic array of doubles.
* **Members**: `int mSize`, `double* mData`.
* Constructors/destructor handle allocation and deallocation.
* Overloaded operators:

  * Assignment, unary (`-`), binary (`+`, `-`, `*`) for vector–vector and vector–scalar.
  * `operator[](int)` for 0-based access with bounds checking.
  * `operator()(int)` for 1-based access.

### Matrix Class

* Manages a 2D array of doubles.
* **Members**: `int mNumRows`, `int mNumCols`, `double** mData`.
* Constructors:

  * `(numRows, numCols)` initializes zeros.
  * Copy constructor for deep copy.
* Destructor frees allocated memory.
* Accessors: `numRows()`, `numCols()`.
* Overloaded operators:

  * `operator()(int i, int j)` for 1-based indexing.
  * Assignment, unary, binary (`+`, `-`, `*`) for matrix–matrix, matrix–vector, matrix–scalar (with `assert` checks).
* Member functions:

  * `double determinant()` for square matrices.
  * `Matrix inverse()` for computing inverses.
  * `Matrix pseudoInverse()` for Moore–Penrose inverse.

### LinearSystem Class

* Represents **Ax = b**.
* **Members**: `int mSize`, `Matrix* mpA`, `Vector* mpb`.
* Constructor initializes from a matrix and vector (no default constructor).
* Copy constructor disabled.
* `virtual Vector Solve()` uses Gaussian elimination with partial pivoting.

### PosSymLinSystem Class

* Derived from `LinearSystem` with protected access to `mpA` and `mpb`.
* Overrides `Solve()` to implement the Conjugate Gradient method for symmetric positive definite matrices.
* Checks symmetry of `mpA`.

### Underdetermined/Overdetermined Systems

* Solutions via:

  * Moore–Penrose pseudo-inverse (`Matrix::pseudoInverse`).
  * Tikhonov regularization (ridge regression implementation).

### Building and Running

```bash
cd Part_A
g++ -std=c++11 Vector.cpp Matrix.cpp LinearSystem.cpp PosSymLinSystem.cpp main.cpp tests.cpp -o solverA
./solverA          # runs built-in tests and demos
```

## Part B: Linear Regression

Predict CPU performance using linear regression on the UCI Computer Hardware dataset.

### Dataset

* Provided in `Part_B/dataset.csv`.
* 209 instances with attributes:

  * `MYCT`, `MMIN`, `MMAX`, `CACH`, `CHMIN`, `CHMAX` (predictors)
  * `PRP` (target)
  * Non-predictive columns `vendor name`, `Model Name`, `ERP` are ignored.

### Regression Model

```
PRP = x1*MYCT + x2*MMIN + x3*MMAX + x4*CACH + x5*CHMIN + x6*CHMAX
```

* Parameters estimated by solving normal equations using Part A solvers.

### Training and Evaluation

* Split: **80%** training, **20%** testing (fixed random seed).
* Fit model on training set.
* Evaluate using **Root Mean Square Error (RMSE)** on test set.
* Output training MSE, testing MSE, and RMSE.

### Building and Running

```bash
cd Part_B
g++ -std=c++11 LinearRegression.cpp main.cpp -o regressorB
./regressorB dataset.csv
```

## Tests

* `Part_A/tests.cpp` includes unit tests for:

  * Vector and matrix operations
  * Determinant, inverse, pseudo-inverse
  * Gaussian elimination and Conjugate Gradient solvers

## Dependencies

* Standard C++11 library.

## License

This project is released under the GNU General Public License v3.0. See [LICENSE](LICENSE) for details.
