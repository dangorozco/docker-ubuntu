# Docker-Ubuntu - ARM64 Linux

This repo demonstrates ARM cross-compilation, GoogleTest, and CI/CD with GitHub Actions.

---

## Test Results (GoogleTest)

![tests](https://github.com/dangorozco/docker-ubuntu/actions/workflows/ci.yml/badge.svg?job=tests)

This badge reflects the latest GoogleTest results (from `results.xml`) processed by `dorny/test-reporter`.  
Clicking it will take you to the latest workflow run where you can see detailed results.

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