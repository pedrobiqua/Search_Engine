## Overview

The **Search Engine** library is designed to create custom search systems, combining reverse indexing with the **PageRank** algorithm to deliver relevant and efficient search results.


## Key Features

- **Reverse Indexing**: Maps keywords to the documents where they appear.
- **PageRank**: Calculates document relevance based on link structure.
- **Flexible Integration**: Suitable for a wide range of projects requiring search capabilities.


## Installation

To install the library, use the following `pip` command:

```bash
pip install search-engine-cpp
```


## Quick Start Example

Here’s a basic example of how to use the library:

```python
from search_engine.crawler import Crawler

# Initialize the Crawler
crawler = Crawler("https://en.wikipedia.org", "/wiki/", "Cat", test_mode=True)

# Run the crawler with a limit of 10 pages
graph = crawler.run(limit=10)

# Compute PageRank
page_ranks = graph.compute_page_rank()

# Display the top 3 most relevant pages
top_pages = sorted(page_ranks.items(), key=lambda item: item[1], reverse=True)[:3]
print(top_pages)
```


## License

This project is licensed under the **MIT License**.

