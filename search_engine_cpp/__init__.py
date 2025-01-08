import ctypes
import os

# Get lib path to .so file
lib_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "lib", "libsearch_engine.so"))

# Load the .so with ctypes
try:
    ctypes.CDLL(lib_path)
except OSError as e:
    raise ImportError(f"Error loading the shared library '{lib_path}': {e}")
