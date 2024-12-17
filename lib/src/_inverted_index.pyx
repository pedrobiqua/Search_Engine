# inverted_index.pyx
from libcpp.map cimport map as cpp_map
from libcpp.list cimport list as cpp_list
from libcpp.string cimport string
from libcpp.pair cimport pair

cdef extern from "inverted_index.h" namespace "inverted_index":
    ctypedef string str

    # Estrutura docs
    cdef struct docs:
        str name_doc
        int freq
        cpp_list[str] links_docs

    # Tipos de dados
    ctypedef cpp_list[docs] list_docs
    ctypedef cpp_map[str, list_docs] map_str_docs

    # Funções expostas
    map_str_docs add_doc(map_str_docs& mp, const str& doc_name, str& text)
    list_docs find_answer(map_str_docs& mp, str& input)

# Conversões entre string
def cpp_to_py_str(string cpp_str):
    return cpp_str.decode("utf-8")

def py_to_cpp_str(unicode py_str):
    return py_str.encode("utf-8")


# Wrapper para add_doc
def add_document(dict mp, unicode doc_name, unicode text):
    cdef string cpp_doc_name = py_to_cpp_str(doc_name)
    cdef string cpp_text = py_to_cpp_str(text)

    cpp_result = add_doc(mp, cpp_doc_name, cpp_text) # Chama a função C++

    # Retorna resultado convertido para Python
    return cpp_result

# Wrapper para find_answer
def find_documents(dict mp, unicode input_word):
    cdef string cpp_input = py_to_cpp_str(input_word)
    cpp_result = find_answer(mp, cpp_input) # Função c++
    # Retorna lista de documentos em Python
    return cpp_result
