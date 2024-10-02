from search_engine.crawler import Crawler

crawler = Crawler("https://pt.wikipedia.org", "/wiki/", "Gato")


crawler.run()