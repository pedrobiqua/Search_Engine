from search_engine.crawler import Crawler

crawler = Crawler("https://pt.wikipedia.org", "/wiki/")


print(crawler._get_links("Gato"))