# Docker-Ubuntu - ARM64 Linux

This repo demonstrates ARM cross-compilation, GoogleTest, and CI/CD with GitHub Actions.

---

## Test Results (GoogleTest)

[![tests](https://img.shields.io/github/actions/workflow/status/dangorozco/docker-ubuntu/ci.yml?label=tests&job=tests)](https://github.com/dangorozco/docker-ubuntu/actions?query=workflow%3ACI+branch%3Amain)

This badge reflects the status of the **GoogleTest suite** (`results.xml`) executed in the `tests` job.  
Clicking the badge will take you to the **CI workflow runs page**, where you can open the latest run **unit tests** to view detailed GoogleTest results.

---

## Continuous Integration (CI)

![CI](https://github.com/dangorozco/docker-ubuntu/actions/workflows/ci.yml/badge.svg)

The **CI badge** above shows the current build status of the project.  
Every commit and pull request automatically triggers a GitHub Actions workflow that:

- Cross-compiles the code for ARM64.  
- Builds and runs the native test suite using GoogleTest.  
- Performs static analysis checks with `clang-tidy`.  

This ensures the codebase is always buildable, tested, and validated before integration.

---

## Test Coverage

[![codecov](https://codecov.io/gh/dangorozco/docker-ubuntu/branch/main/graph/badge.svg)](https://codecov.io/gh/dangorozco/docker-ubuntu)

[![Coverage Report](https://img.shields.io/badge/coverage-HTML-green)](https://dangorozco.github.io/docker-ubuntu/)

This project integrates automated test coverage reporting into the CI/CD pipeline.  
Coverage is collected with **LCOV** during each GitHub Actions run, then uploaded to **Codecov** for tracking and visualization.  
In addition, a browsable **HTML Coverage Report** is generated and published via GitHub Pages.

- 🟢 **Codecov Badge** (above) shows the current unit test coverage percentage.  
- 📊 **Detailed Coverage Report** is available as an interactive HTML view: [Coverage Report](https://dangorozco.github.io/docker-ubuntu/)  
- 🔄 Ensures every commit is tested, progress is tracked over time, and critical functions remain covered.

This provides both a quick at-a-glance view (Codecov badge) and a detailed breakdown of test coverage across the codebase.


---

## Developer Guide

This section provides step-by-step instructions for new contributors to build, test, and push changes to this project.  
The project demonstrates **ARM cross-compilation (AArch64)**, **GoogleTest unit testing**, and **automated CI/CD pipelines** with **GitHub Actions + Codecov**.

---

### 1. Prerequisites

On your local machine (Linux, macOS, or WSL2), install the following:

- **CMake** (≥ 3.16)
- **GCC / G++** (native build)
- **Cross-compiler toolchain** for ARM64:
  - `gcc-aarch64-linux-gnu`
  - `g++-aarch64-linux-gnu`
- **GoogleTest** (`libgtest-dev`)
- **LCOV** (for coverage reports)
- **Clang-Tidy** (optional: static analysis)
- **Git**

If on **macOS**
Install docker app and run it
open homebrew terminal
```bash
docker run -it \
  -v $(pwd):/workspace \
  -w /workspace \
  --name my-ubuntu-dev \
  ubuntu:22.04 bash-
```
After docker gets permission to access local hardware and folders then it shows the /workspace a seen below 

![alt text](<Screenshot 2025-10-01 at 12.22.35 PM.png>)


On **Ubuntu/Debian**:
```bash
apt-get update && apt-get install -y \
    gcc-aarch64-linux-gnu g++-aarch64-linux-gnu \
    git cmake make vim nano qemu-user \
    lcov clang-tidy git \
    && rm -rf /var/lib/apt/lists/*
  
```

On **macOS**:

If you use VS Code, there’s a Remote - Containers plugin that lets you open the Docker container as if it were your dev environment.
	•	You write code in VS Code on macOS.
	•	It syncs directly into the container.
	•	Very popular in professional embedded + DevOps setups.

	•	Install the VS Code extension: Dev Containers.
	•	Press F1 → search Dev Containers: Attach to Running Container….
	•	Pick my-ubuntu-dev.
	•	Your /workspace folder will be visible.
	•	You can edit, build, debug all inside VS Code, using the container’s toolchain.

Once the folder is opened, the .json and cmake files shown below should be updated for the ARM 64 
Also C/C++ extension module should be installed
￼
![alt text](EXPLORER.png)

![alt text](<tf eate srds.t.png>)


---

2. Clone the Repository

git clone https://github.com/dangorozco/docker-ubuntu.git
cd docker-ubuntu

---

3. Native Build (x86_64)

Build the project natively on your machine (for fast iteration):

cmake -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -- -j$(nproc)

Run the binary:

./build/hello


---

4. ARM64 Cross-Compilation

Build the project for ARM64 using the provided toolchain file:

cmake -B build-arm64 -DCMAKE_TOOLCHAIN_FILE=arm64-toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build-arm64 -- -j$(nproc)

This produces binaries that can run on ARM64 Linux environments (e.g., Raspberry Pi, embedded boards, Docker ARM emulation).

---

5. Run Unit Tests (GoogleTest)

Unit tests are located in tests/. Build and run them natively:

cmake -B build-tests -DCMAKE_BUILD_TYPE=Coverage
cmake --build build-tests -- -j$(nproc)
./build-tests/test_hello --gtest_output=xml:results.xml

Expected output:

[==========] Running 1 test from 1 test suite.
[ RUN      ] HelloTest.SayHelloReturnsZero
[       OK ] HelloTest.SayHelloReturnsZero (0 ms)
[==========] 1 test from 1 test suite ran. (0 ms total)


---

6. Generate Coverage Report (Local)

lcov --capture --directory build-tests --output-file build-tests/coverage.info
lcov --remove build-tests/coverage.info '/usr/*' --output-file build-tests/coverage.info
genhtml build-tests/coverage.info --output-directory build-tests/coverage-html

Open in browser:

open build-tests/coverage-html/index.html   # macOS
xdg-open build-tests/coverage-html/index.html  # Linux


---

7. GitHub CI/CD Pipeline

Every push to main automatically:
	•	Builds natively and cross-compiles for ARM64.
	•	Runs GoogleTests (results.xml uploaded via dorny/test-reporter).
	•	Uploads coverage results to Codecov.
	•	Publishes an HTML coverage report to GitHub Pages:
👉 Coverage Report

Badges:
	•	CI: 

	•	Tests: 

	•	Code Coverage: 


---

8. Contributing Workflow
	1.	Create a new branch:

git checkout -b feature/my-change


	2.	Make your changes (source code in hello.c, tests in tests/).
	3.	Format and lint code (optional but recommended):

clang-tidy hello.c -- -I.


	4.	Commit your changes:

git add .
git commit -m "feat: add new function X with tests"


	5.	Push your branch:

git push origin feature/my-change


	6.	Open a Pull Request (PR) on GitHub for review.

All PRs will automatically trigger CI/CD, running tests + coverage checks.

---

9. Resources
	•	GoogleTest Docs
	•	CMake Documentation
	•	Codecov
	•	GitHub Actions

---

🔹 Quick Start

For a quick sanity check (native build + run):

git clone https://github.com/dangorozco/docker-ubuntu.git
cd docker-ubuntu
cmake -B build
cmake --build build
./build/hello


---


👉 This is now a **drop-in section** for your `README.md`.  
It’s structured, beginner-friendly, and matches your project’s CI/CD setup.  

Would you like me to also create a **short "Project Architecture" diagram** (tools + flow: Developer → GitHub → Actions → Codecov → Pages) to embed in README.md for newcomers?