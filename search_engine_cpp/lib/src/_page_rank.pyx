from libcpp.string cimport string
from libcpp.map cimport map
from libcpp.list cimport list
from libcpp cimport bool

# Importar a classe Graph do C++
cdef extern from "page_rank.h" namespace "page_rank":
    cdef cppclass Graph:
        void add_edge(int u, int v)
        map[int, double] compute_page_rank(double damping_factor, int max_iterations, double tol, bool on_print)
        void print()
        const map[int, list[int]]& get_adjList() const
        map[int, list[int]] adjList_

# Expor a classe Graph para o Python
cdef class PyGraph:
    cdef Graph* c_graph

    def __cinit__(self):
        # Inicializa a classe C++ Graph
        self.c_graph = new Graph()

    def __dealloc__(self):
        del self.c_graph

    def add_edge(self, int u, int v):
        self.c_graph.add_edge(u, v)

    def compute_page_rank(self, double damping_factor=0.85, int max_iterations=100,
                          double tol=1e-6, bint on_print=False):
        return self.c_graph.compute_page_rank(damping_factor, max_iterations, tol, on_print)

    def print(self):
        self.c_graph.print()

    def get_adj_list(self):
        return self.c_graph.get_adjList()