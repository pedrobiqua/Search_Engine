from .exceptions import UrlError

# Libs
import requests
import re
from bs4 import BeautifulSoup

class Crawler:
    # Regex para validar URLs
    REGEX = re.compile(
        r'^(?:http|https)://'  # protocolo http ou https
        r'(?:\S+(?::\S*)?@)?'  # autenticação opcional
        r'(?:[a-zA-Z0-9-]+\.)+[a-zA-Z]{2,6}'  # domínio
        r'(?::\d{2,5})?'  # porta opcional
        r'(?:/\S*)?$',  # caminho opcional
        re.IGNORECASE
    )

    def __init__(self, url_base: str, page_name: str):
        # TODO: Adicionar parametro para remover links indesejados
        self.url_base = url_base
        self.page_name = page_name
        self._validate_url(url_base)
    
    def _get_links(self, current_page):
        """This function returns all links from the current page"""
        if current_page is None:
            raise UrlError()
        
        response = requests.get(self.url_base + self.page_name + current_page)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            return [a.get('href') for a in soup.find_all('a', href=True) if a.get('href').startswith(self.page_name)]
        return []
    
    def _get_paragraphs(self, current_page):
        """This function returns all paragraphs from the current page"""
        response = requests.get(self.url_base + self.page_name + current_page)
        if response.status_code == 200:
            soup = BeautifulSoup(response.content, 'html.parser')
            return [p.get_text() for p in soup.find_all('p')]
        return []

    # Função para validar a URL
    def _validate_url(self, url):
        if not re.match(self.REGEX, url):
            raise ValueError("Invalid URL")
        
    def run(self):
        """This function runs the crawler"""
        # TODO: Fazer os loops para percorrer as páginas
        links = self._get_links(self.page_name)
        paragraphs = self._get_paragraphs(self.page_name)
        return links, paragraphs