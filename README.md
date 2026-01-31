# C++ Backtracking Puzzles: Wordle Solver + Shift Scheduler

This repo contains two classic recursive/backtracking problems implemented in C++:

- **Wordle-style pattern solver** (`wordle.cpp/.h`) with “floating letters” constraints
- **Shift scheduling (CSP/backtracking)** (`schedwork.cpp/.h`) respecting availability + max shifts

## 1) Wordle Solver

### Goal
Given:
- a pattern string (e.g. `s---ng`, where `-` means unknown)
- optional floating letters that must appear somewhere in the unknown slots
return all valid words in the dictionary matching constraints.

### Files
- `wordle.cpp`, `wordle.h`
- `wordle-driver.cpp` (demo program)
- `dict-eng.txt` + `dict-eng.cpp/.h` (dictionary loader)

### Run
Build:
```bash
make
```

Example:
```bash
./wordle-driver "s---ng"
./wordle-driver "a--le" "p"
```
The driver automatically loads dict-eng.txt from the repo root.


## 2) Shift Scheduler (Backtracking / Constraint Satisfaction)

### Goal

### Find a schedule that assigns workers to each day such that:
-	assigned workers are available that day
-	daily staffing requirement is met
-	each worker does not exceed maxShifts

### Files
-	schedwork.cpp, schedwork.h
-	schedwork-driver.cpp (demo program)

### Run
```bash
./schedwork-driver
```
The driver contains a small hardcoded AvailabilityMatrix. You can edit it to try new scenarios.

## Quick Start (Makefile)
Build everything:
```bash
make
```

Outputs:
	•	wordle-driver
	•	schedwork-driver

Clean:
```bash
make clean
```

## CMake Build (optional, more “project-style”)
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

## Memory Safety (recommended on macOS): AddressSanitizer
```bash
cmake -S . -B build-asan -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer"
cmake --build build-asan -j
./build-asan/wordle-driver "a--le" "p"
./build-asan/schedwork-driver
```


