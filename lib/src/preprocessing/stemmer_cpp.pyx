from libcpp.string cimport string

# Importar a classe RSPL do C++
cdef extern from "preprocessing/stemmer.h" namespace "stemmer":
    cdef cppclass RSPL:
        RSPL()  # Construtor
        void run(string* sentence)  # Método público

# Expor a classe RSPL para o Python
cdef class PyRSPL:
    cdef RSPL* c_rspl

    def __cinit__(self):
        # Inicializa a classe C++ RSPL
        self.c_rspl = new RSPL()

    def __dealloc__(self):
        # Libera a memória alocada
        del self.c_rspl

    def run(self, str sentence):
        # Converte a string Python para std::string
        cdef string cpp_sentence = sentence.encode("utf-8")
        # Chama o método `run` da classe RSPL
        self.c_rspl.run(&cpp_sentence)
        # Converte a std::string de volta para string Python
        return cpp_sentence.decode("utf-8")
