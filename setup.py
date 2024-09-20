import os

from Cython.Build import cythonize
from setuptools import Extension, setup

# Caminho da biblioteca compartilhada libhello.so
library_dir = os.path.abspath("build/lib")

# Definir a extensão Cython
extensions = [
    Extension(
        "search_engine",
        sources=["lib/src/_hello.pyx"],  # Arquivo Cython
        language="c++",
        libraries=["search_engine"],  # Nome da biblioteca C++
        library_dirs=[library_dir],  # Diretório da biblioteca
        include_dirs=["lib/include"],  # Incluir o diretório atual
        extra_compile_args=["-std=c++11"],
        runtime_library_dirs=[library_dir],
        cython_directives={"language_level": "3str"},
    )
]

# Compilar o Cython
setup(
    name="search_engine",
    ext_modules=cythonize(extensions),
)
