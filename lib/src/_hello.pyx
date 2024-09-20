from libcpp.string cimport string

# Importar a classe do C++
cdef extern from "hello.h":
    cdef cppclass Hello:
        Hello()
        string greet(string name)

# Expor a classe Hello para o Python
cdef class PyHello:
    cdef Hello* c_hello

    def __cinit__(self):
        self.c_hello = new Hello()

    def __dealloc__(self):
        del self.c_hello

    def greet(self, name):
        return self.c_hello.greet(name.encode('utf-8'))
