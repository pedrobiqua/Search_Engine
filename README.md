# Search Engine
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.0-4baaaa.svg)](code_of_conduct.md)
[![CMake Build and Test](https://github.com/pedrobiqua/Search_Engine/actions/workflows/cmake-multi-platform.yml/badge.svg?branch=main)](https://github.com/pedrobiqua/Search_Engine/actions/workflows/cmake-multi-platform.yml)
[![Pages Build Deployment](https://github.com/pedrobiqua/Search_Engine/actions/workflows/pages/pages-build-deployment/badge.svg?branch=main)](https://github.com/pedrobiqua/Search_Engine/actions/workflows/pages/pages-build-deployment)
[![Poetry](https://img.shields.io/endpoint?url=https://python-poetry.org/badge/v0.json)](https://python-poetry.org/)
[![PyPi](https://img.shields.io/pypi/v/search-engine-cpp)](https://pypi.org/project/search-engine-cpp)

<p align="center">
  <img src="https://github.com/user-attachments/assets/3d2be218-6aa2-45af-a956-f1d0fde5bf7e" alt="Logo da biblioteca" width="300">
</p>

---

**Search Engine** is a simple, efficient engine that builds a reverse index for keyword searching and ranks results using the **PageRank** algorithm.

## ⚙️ Installation

Please create a virtual environment using `venv`, as the project is still in alpha testing and in its initial implementations.  
```bash
python3 -m venv .env
source .env/bin/activate
pip install search-engine-cpp
```

## 🚀 Usage
```python
from search_engine.crawler import Crawler

crawler = Crawler("https://en.wikipedia.org", "/wiki/", "Cat", test_mode=True)
graph = crawler.run(limit=10)
my_dict = graph.compute_page_rank()
top = sorted(my_dict.items(), key=lambda item: item[1], reverse=True)[:3]

print(top)
```

## 📋 Requirements for Contributions

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

## 🧪 Running Tests for Contributions

Run unit tests to ensure the correctness of the system.

1. After building the project, navigate to the `build` directory and execute:

    ```bash
    ./tests/unit-tests/LibUnitTests
    ```

This will run the tests covering search engine functionality, reverse indexing, and the PageRank algorithm.

---

## 🏃 Running Examples for Contributions

The first step is building the project, for this to run:

```bash
poetry install
poetry build
```

After building it, run this command to see the library working:

```bash
poetry run python Examples/graph_example.py
```

---

## ⚙️ How It Works

- **Reverse Indexing**: Maps keywords to the documents where they appear.
- **PageRank**: An algorithm that assigns a relevance score to each document based on its links and structure.
- **Querying**: Searches for documents related to a keyword and ranks them according to their PageRank score.

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

## 👥 Contributors

We welcome all contributions to this project! Please make sure to follow the guidelines outlined in the [CONTRIBUTING.md](CONTRIBUTING.md) file.<br>
Thanks to all [contributors](https://github.com/pedrobiqua/Search_Engine/graphs/contributors)

[![Contributors](https://contrib.rocks/image?repo=pedrobiqua/Search_Engine)](https://github.com/pedrobiqua/Search_Engine/graphs/contributor)


Made with [contrib.rocks](https://contrib.rocks).

---

Keep learning,<br>
**Pedro;)**
