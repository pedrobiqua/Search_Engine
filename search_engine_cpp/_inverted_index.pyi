# -*- coding: utf-8 -*-
from typing import Dict, List

# Definindo o tipo 'docs' conforme sua estrutura C
class docs:
    name_doc: str
    freq: int
    links_docs: List[str]

# O tipo 'map_str_docs' é um mapa que associa strings a listas de documentos
map_str_docs = Dict[str, List[docs]]

# Definindo as funções expostas
def add_document(mp: map_str_docs, doc_name: str, text: str) -> map_str_docs:
    pass

def find_documents(mp: map_str_docs, input_word: str) -> List[docs]:
    pass

# Funções auxiliares para conversão de tipos
def cpp_to_py_str(cpp_str: str) -> str:
    pass

def py_to_cpp_str(py_str: str) -> str:
    pass
