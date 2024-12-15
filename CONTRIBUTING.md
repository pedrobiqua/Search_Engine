# Contributing Guidelines

Thank you for your interest in contributing to this project! Your support and collaboration are greatly appreciated. Please read these guidelines carefully to help us maintain a positive and productive community.

---

## How to Contribute

### 1. Fork the Repository

Fork the main repository and clone the fork to your local environment:

```bash
git clone https://github.com/your-username/search-engine.git
```

### 2. Create a Branch for Your Contribution

Create a separate branch for your contribution. Make sure to name the branch according to the feature or bug fix you are working on. Each pull request **must** be associated with its own branch. GitHub provides an option to directly create branches linked to issues, which can simplify this process:

```bash
git checkout -b my-new-feature
```

### 3. Open an Issue or Discussion Before Implementation

Before starting work on a feature or bug fix, create an **issue** or open a **discussion** in the repository. This allows maintainers and contributors to provide feedback, avoid duplicated efforts, and ensure that the planned implementation aligns with the project's goals.

### 4. Make Clear and Meaningful Commits

Write descriptive and concise commit messages. Follow this commit message convention:

- Use the imperative mood (e.g., "Add support for...").
- Keep the first line of the commit message under 50 characters.
- Add a longer description after a blank line, if needed.

Example commit message:

```bash
git commit -m "Fix bug in PageRank algorithm"

git commit -m "Add keyword search functionality
- Implement search function in the reverse index
- Improve indexing performance for large data sets"
```

### 5. Keep Your Fork Synchronized

Regularly update your fork with changes from the main repository:

```bash
git fetch upstream
git checkout main
git merge upstream/main
```

### 6. Run Tests

Ensure that your contribution does not break anything. Run the unit tests before submitting your pull request:

```bash
make test
```

If necessary, add new tests covering your functionality or fix.

### 7. Submit a Pull Request

After completing your changes and testing the code, submit your pull request:

1. Go to the page of your fork on GitHub.
2. Click "New Pull Request."
3. Provide a detailed title and description for your pull request explaining the changes.

---

## Code Review

When you open a pull request, it will be reviewed by one of the project maintainers. Please be patient, as the review process may take some time depending on the complexity of the changes. Reviewers may request changes during the process.

---

## Coding Standards

Follow these coding guidelines when contributing:

- **C++11 Standard**: Ensure your code complies with the C++11 standard or higher.
- **Indentation**: Use 4 spaces for indentation, no tabs.
- **Naming Conventions**: Use clear and meaningful names for variables and functions. Use `CamelCase` for class names and `snake_case` for variables and functions.
- **Documentation**: Write comments to explain complex functions or non-trivial code.

---

## Reporting Bugs

If you find a bug, please open an **issue** on GitHub with the following information:

1. Bug description.
2. Steps to reproduce the bug.
3. Expected behavior.
4. Environment information (OS, compiler version, etc.).

---

## Links to Documentation

For more details on how to contribute, please refer to the following:
- [GitHub Documentation on Forking Repositories](https://docs.github.com/en/get-started/quickstart/fork-a-repo)
- [GitHub Discussions Overview](https://docs.github.com/en/discussions)
- [Docs Library Search Engine](https://pedrobiqua.github.io/Search_Engine/html/Chap_00_Architecture_documentation.html)
- [Code of Conduct](CODE_OF_CONDUCT.md)
- [README](README.md)

---

## General Rules and Expectations

1. **Respect others**: Treat all contributors and users with respect. Harassment, trolling, or abusive language will not be tolerated. Please refer to our [Code of Conduct](CODE_OF_CONDUCT.md) for more details.
2. **Be constructive**: Provide helpful feedback, avoid unproductive criticism, and aim to make this project better for everyone.
3. **Collaborate**: Communicate openly and proactively to ensure smooth teamwork and avoid duplicated efforts.

---

## Acknowledgements

Thank you for taking the time to contribute to the **Search Engine** project. Your contribution is greatly appreciated!
