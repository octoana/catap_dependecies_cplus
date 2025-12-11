# catap_dependecies_cplus
testing cpp dependencies and vcpkg

# C++ SFML + SQLite3 Test Project

This is a minimal example project using **SFML 3.0.0** and **SQLite3 3.50.3** in C++.  
Dependencies are managed using [vcpkg](https://vcpkg.io/).

## Setup

### 1. Install vcpkg

```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh   # Linux/macOS
.\bootstrap-vcpkg.bat  # Windows
```

### 2. Install dependencies

```bash
./vcpkg install sfml sqlite3
```

*(Alternatively, with the provided `vcpkg.json`, use manifest mode:)*

```bash
# From project root:
vcpkg install
```

### 3. Build

Use CMake:

```bash
cmake -B build -S .
cmake --build build
```

### 4. Run

```bash
./build/cpp-sfml-sqlite-test
```

**Note:** You may need to have a font file (`arial.ttf` or similar) in your working directory for the text to render.

## What does it do?

- Opens a simple SFML window.
- Executes a test SQLite3 query in memory and prints a result to the console.

---
