from _page_rank import PyGraph

def montargrafo_print():
    graph = PyGraph()

    graph.add_edge(1, 3)
    graph.add_edge(2, 3)
    graph.add_edge(3, 4)

    graph.print()


# montargrafo_print()