from .exceptions import UrlError
from _page_rank import PyGraph

# Libs
import requests
import re
from bs4 import BeautifulSoup

class Crawler:
    """
    A web crawler that traverses a network of web pages, extracts links and paragraphs, 
    and constructs a graph using the PageRank algorithm.

    Parameters
    ----------
    url_base : str
        The base URL from which the crawler starts.
    page_name : str
        The initial page to start crawling.
    remove_pages : list of str, optional (default=[])
        A list of pages to exclude from the crawl.
    
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

    def __init__(self, url_base: str, page_name: str, remove_pages: list[str] = []):
        """
        Initialize the Crawler with a base URL, the starting page, and optionally, 
        a list of pages to exclude.

        Parameters
        ----------
        url_base : str
            The base URL of the website to crawl.
        page_name : str
            The starting page to begin crawling.
        remove_pages : list of str, optional
            Pages to exclude from the crawl.
        """
        self.url_base = url_base
        self.page_name = page_name
        self.remove_pages = remove_pages
        self._validate_url(url_base)

        # Initialize the graph for PageRank
        self.graph = PyGraph()
    
    def _get_links(self, current_page: str) -> list:
        """
        Retrieve all links from the specified page.

        Parameters
        ----------
        current_page : str
            The current page to fetch links from.
        
        Returns
        -------
        links : list of str
            A list of valid links found on the current page.

        Raises
        ------
        UrlError
            If the current page URL is invalid or inaccessible.
        """
        if current_page is None:
            raise UrlError()
        
        response = requests.get(self.url_base + self.page_name + current_page)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            return [a.get('href') for a in soup.find_all('a', href=True) if a.get('href').startswith(self.page_name)]
        return []
    
    def _get_paragraphs(self, current_page: str) -> list:
        """
        Retrieve all paragraphs from the specified page.

        Parameters
        ----------
        current_page : str
            The current page to fetch paragraphs from.
        
        Returns
        -------
        paragraphs : list of str
            A list of paragraphs' text found on the current page.
        """
        response = requests.get(self.url_base + self.page_name + current_page)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            return [p.get_text() for p in soup.find_all('p')]
        return []

    def _validate_url(self, url: str):
        """
        Validate the format of the given URL.

        Parameters
        ----------
        url : str
            The URL to validate.
        
        Raises
        ------
        UrlError
            If the URL is not valid.
        """
        if not re.match(self.REGEX, url):
            raise UrlError()
        
    def run(self):
        """
        Run the crawler to collect links and paragraphs from the starting page.

        Returns
        -------
        links : list of str
            A list of links found on the starting page.
        paragraphs : list of str
            A list of paragraphs found on the starting page.
        """
        links = self._get_links(self.page_name)
        paragraphs = self._get_paragraphs(self.page_name)
        return links, paragraphs
