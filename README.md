# Search Engine  
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.0-4baaaa.svg)](code_of_conduct.md)  
[![CMake Build and Test](https://github.com/pedrobiqua/Search_Engine/actions/workflows/cmake-multi-platform.yml/badge.svg?branch=main)](https://github.com/pedrobiqua/Search_Engine/actions/workflows/cmake-multi-platform.yml)  

---

**Search Engine** is a simple, efficient engine that builds a reverse index for keyword searching and ranks results using the **PageRank** algorithm.

## 📋 Requirements

Before compiling the project, ensure your environment meets the following requirements:

- **CMake 3.10** or higher
- **Google Test** for unit testing
- A **C++11** compatible compiler or higher

## 📂 Project Structure

The project is organized as follows:

- **`src/`**: Main implementation of the search engine, including reverse indexing and the PageRank algorithm.
- **`tests/`**: Unit tests to verify the functionality of the system.
- **`CMakeLists.txt`**: Configuration file for building the project with CMake.

---

## 🔧 Building the Project

To compile the project, follow these steps:

1. Create a `build` directory and navigate into it:

    ```bash
    mkdir build && cd build
    ```

2. Run **CMake** to generate the build files:

    ```bash
    cmake ..
    ```

3. Compile the project using **make**:

    ```bash
    make
    ```

---

## 🧪 Running Tests

Run unit tests to ensure the correctness of the system.

1. After building the project, navigate to the `build` directory and execute:

    ```bash
    ./tests/unit-tests/LibUnitTests
    ```

This will run the tests covering search engine functionality, reverse indexing, and the PageRank algorithm.

---

## ⚙️ How It Works

- **Reverse Indexing**: Maps keywords to the documents where they appear.
- **PageRank**: An algorithm that assigns a relevance score to each document based on its links and structure.
- **Querying**: Searches for documents related to a keyword and ranks them according to their PageRank score.

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

Keep learning,<br>
**Pedro;)**
