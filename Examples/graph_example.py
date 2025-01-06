# EXEMPLO USANDO A BIBLIOTECA SEARCH_ENGINE

from search_engine_cpp.crawler import Crawler

# Rodar com o test_mode ativado ajuda a testar a lib e fazer com que o parametro limit seja usado

# O CRAWLER É RESPONSAVEL POR VARER AS PÁGINAS
crawler = Crawler("https://pt.wikipedia.org", "/wiki/", "Gato", test_mode=True)

# QUANDO TERMINA DE RODAR ISSO SERÁ GERADO UM GRAFO
grafo = crawler.run(limit=10)
# grafo.print()

# COM O GRAFO CONSEGUIMOS COMPUTAR O PAGE_RANK DAS PÁGINAS
meu_dict = grafo.compute_page_rank()
top_tres = sorted(meu_dict.items(), key=lambda item: item[1], reverse=True)[:3]

print(top_tres)