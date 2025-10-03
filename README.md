# Docker-Ubuntu - ARM64 Linux

This repo demonstrates ARM cross-compilation, GoogleTest, and CI/CD with GitHub Actions.

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

## Test Coverage (Codecov)

[![codecov](https://codecov.io/gh/dangorozco/docker-ubuntu/branch/main/graph/badge.svg)](https://codecov.io/gh/dangorozco/docker-ubuntu)

The **Codecov badge** above reflects the current percentage of unit test coverage.  
Coverage is collected with **LCOV** and uploaded to Codecov on every CI run, providing visibility into which parts of the code are tested.  

- ✅ The badge shows an at-a-glance coverage percentage.  
- 📊 A detailed HTML report is also generated and published via GitHub Pages:  
  👉 [Coverage Report](https://dangorozco.github.io/docker-ubuntu/)  
- 🔗 This helps track testing progress over time and ensures critical functions remain covered.

---

## Test Coverage Reports

[![Coverage Report](https://img.shields.io/badge/coverage-HTML-green)](https://dangorozco.github.io/docker-ubuntu/)

This project includes automated test coverage reporting integrated into the CI/CD pipeline:

- **Codecov Badge** (above) shows the current test coverage percentage.
- **HTML Coverage Report** is automatically generated with LCOV and published to GitHub Pages.
- You can view the latest detailed report here: [Coverage Report](https://dangorozco.github.io/docker-ubuntu/)

This ensures that every commit is tested, coverage is tracked, and results are visible both in Codecov and as a browsable HTML report.