import ctypes
import os

# Obtenha o caminho absoluto do .so
lib_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "lib", "libsearch_engine.so"))

# Carregue o .so com ctypes
try:
    ctypes.CDLL(lib_path)
except OSError as e:
    raise ImportError(f"Erro ao carregar a biblioteca compartilhada '{lib_path}': {e}")

# Agora, importe os submódulos normalmente
from . import _hello
from . import _page_rank
from . import _inverted_index

__all__ = ["_hello", "_page_rank", "_inverted_index"]
