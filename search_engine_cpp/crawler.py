from .exceptions import UrlError
from .wrapper.page_rank import PyGraph
from .helper.converter import StringToIntConverter

# Libs
import requests
import re
from bs4 import BeautifulSoup
from collections import deque

class Crawler:
    """
    A web crawler that traverses a network of web pages, extracts links and paragraphs,
    and constructs a graph using the PageRank algorithm.

    This crawler starts from a given base URL and an initial page, and follows links within
    the website to collect data such as links and paragraphs. It constructs a graph based on
    the relationships between pages.

    @param url_base: The base URL from which the crawler starts.
    @param page_name: The initial page to start crawling.
    @param remove_pages: A list of pages to exclude from the crawl. (Optional, default is [])

    Attributes
    ----------
    graph : PyGraph
        A graph representation used for PageRank calculations.

    Examples
    --------
    >>> crawler = Crawler('https://example.com', '/home')
    >>> links, paragraphs = crawler.run()
    """

    # Regex for URL validation
    REGEX = re.compile(
        r'^(?:http|https)://'  # http or https protocol
        r'(?:\S+(?::\S*)?@)?'  # optional authentication
        r'(?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,6}'  # domain
        r'(?::\d{2,5})?'  # optional port
        r'(?:/\S*)?$',  # optional path
        re.IGNORECASE
    )

    def __init__(self, url_base: str, page_name: str, initial_page: str, remove_pages: list[str] = [], test_mode:bool = False):
        """
        Initialize the Crawler with a base URL, the starting page, and optionally,
        a list of pages to exclude.

        @param url_base: The base URL of the website to crawl.
        @param page_name: The starting page to begin crawling.
        @param remove_pages: Pages to exclude from the crawl (optional).
        @param test_mode: Flag to activate the test mode for crawling. (default: False)
        """
        self.url_base = url_base
        self.page_name = page_name
        self.initial_page = initial_page
        self.remove_pages = remove_pages
        self.test_mode = test_mode
        self._validate_url(url_base)

        # Initialize the graph for PageRank
        self.graph = PyGraph()
        self.converter = StringToIntConverter()

    def _get_links(self, current_page: str) -> list:
        """
        Retrieve all links from the specified page.

        @param current_page: The current page to fetch links from.

        @return: A list of valid links found on the current page.

        @raises UrlError: If the current page URL is invalid or inaccessible.
        """
        if current_page is None:
            raise UrlError()

        response = requests.get(self.url_base + self.page_name + current_page)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            # Find all tags <p>
            paragraphs = soup.find_all('p')
            # Find links in tag <p>
            links = [a.get('href') for p in paragraphs for a in p.find_all('a', href=True)
                    if a.get('href').startswith(self.page_name)]
            return links
        return []

    def _get_paragraphs(self, current_page: str) -> list:
        """
        Retrieve all paragraphs from the specified page.

        @param current_page: The current page to fetch paragraphs from.

        @return: A list of paragraphs' text found on the current page.
        """
        response = requests.get(self.url_base + self.page_name + current_page)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            return [p.get_text() for p in soup.find_all('p')]
        return []

    def _validate_url(self, url: str):
        """
        Validate the format of the given URL.

        @param url: The URL to validate.

        @raises UrlError: If the URL is not valid.
        """
        if not re.match(self.REGEX, url):
            raise UrlError()

    def run(self, limit = 2):
        """
        Run the crawler to collect links and paragraphs starting from the base page.
        It uses a queue to traverse the links in a breadth-first manner.

        @param limit: The maximum number of pages to crawl in test mode.

        @return: A graph representation of the pages and their links.
        """
        # Initialize queue with the starting page
        queue = deque([self.initial_page])
        visited = set()  # Track visited pages to avoid processing them multiple times
        all_links = []  # Store all the links found during crawling
        all_paragraphs = []  # Store all the paragraphs found during crawling

        run = True
        counter = 0

        while queue and run:
            current_page = queue.popleft()  # Get the next page to crawl

            # Skip if page has already been visited
            if current_page in visited:
                continue

            # Mark page as visited
            visited.add(current_page)

            # Get links and paragraphs from the current page
            links = self._get_links(current_page)
            paragraphs = self._get_paragraphs(current_page)

            # TODO: Com os paragrafos e com o nome da página eu posso adicionar o indice reverso aqui!



            # Store the results
            all_links.extend(links)
            all_paragraphs.extend(paragraphs)

            current_page_int = self.converter.convert(current_page)

            # Add new links to the queue if they haven't been visited
            for link in links:
                if link not in visited and link not in queue and link not in self.remove_pages:
                    # Extract the last part of the link as the next page
                    next_page = link.split('/')[-1]
                    next_page_int = self.converter.convert(next_page)
                    # Make graph
                    self.graph.add_edge(current_page_int, next_page_int)
                    queue.append(next_page)

            # Only when test_mode is activated
            if self.test_mode:
                counter += 1
                if counter == limit:
                    run = False

        return self.graph
