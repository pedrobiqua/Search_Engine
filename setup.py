import os

from Cython.Build import cythonize
from setuptools import Extension, setup
import subprocess

BUILD_FOLDER = "build"

def build_lib_cpp(path: str):
    if not os.path.exists(path):
        old_path = os.getcwd()
        os.makedirs(path)
        os.chdir(path)
        subprocess.run(["cmake", ".."])
        subprocess.run(["make"])
        os.chdir(old_path)

def build():
    # Dentro do build será buildado o cpp
    pass

build_lib_cpp(BUILD_FOLDER)

# Caminho da biblioteca compartilhada libhello.so
library_dir = os.path.abspath("build/lib")

# TODO: Nessa parte fazer um for percorrendo todos os modulos que serão usados no python
libs_names = [
    "_hello",
    #"_page_rank"
]

# Definir a extensão Cython
extensions = [
    Extension(
        "search_engine",
        sources=["lib/src/_hello.pyx"],  # Arquivo Cython
        language="c++",
        libraries=["search_engine"],  # Nome da biblioteca C++
        library_dirs=[library_dir],  # Diretório da biblioteca, onde tem os .so
        include_dirs=["lib/include"],  # Incluir o diretório include
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

# import os
# import shutil
# import pathlib
# import subprocess
# import sys
# from distutils.core import setup
# from distutils.extension import Extension
# from Cython.Distutils import build_ext
# from Cython.Build import cythonize

# def build_lib(path: str):
#     """
#     Compila a biblioteca C++ utilizando CMake.
#     """
#     old_path = os.getcwd()  # Salva o diretório atual
#     os.chdir(path)  # Muda para o diretório de compilação

#     # Cria um diretório de compilação separado (build) e navega até ele
#     build_dir = "build"
#     os.makedirs(build_dir, exist_ok=True)
#     os.chdir(build_dir)

#     # Executa os comandos do CMake para gerar os arquivos de make e compilar
#     subprocess.check_call(["cmake", ".."])  # Gera os arquivos Makefile a partir de CMakeLists.txt
#     subprocess.check_call(["cmake", "--build", "."])  # Compila o projeto C++ com CMake

#     os.chdir(old_path)  # Retorna ao diretório anterior

# def copy_lib(path_cpp: pathlib.Path, path_lib: pathlib.Path):
#     """
#     Copia as bibliotecas compiladas (por exemplo, .so, .dll, .dylib) do diretório de saída CMake para o destino.
#     """
#     extensions = [".so*", ".dll*", ".dylib*"]
#     for ext in extensions:
#         path_so = path_cpp.glob(f"build/*{ext}")  # Encontra as bibliotecas geradas
#         path_lib.mkdir(exist_ok=True, parents=True)
#         for lib in path_so:
#             shutil.copy(lib, path_lib)  # Copia cada biblioteca para o diretório de destino

# def copy_include(path_cpp: pathlib.Path, path_inc: pathlib.Path):
#     """
#     Copia os arquivos de cabeçalho (includes) gerados, se necessário.
#     """
#     path_inc_src = path_cpp / "include"
#     path_inc.mkdir(exist_ok=True, parents=True)
#     shutil.copytree(path_inc_src, path_inc, dirs_exist_ok=True)

# def build_cpp():
#     """
#     Função principal para compilar a biblioteca C++ e copiar os arquivos necessários.
#     """
#     cpppath = pathlib.Path(__file__).parent / "cpppy/mcpp"
#     path_lib = pathlib.Path(__file__).parent / "cpppy/mcpp/lib"
    
#     # Limpa o diretório de bibliotecas existentes
#     shutil.rmtree(path_lib, ignore_errors=True)

#     # Compila a biblioteca C++ usando CMake
#     build_lib(cpppath.as_posix())

#     # Copia as bibliotecas compiladas para o destino
#     copy_lib(cpppath, path_lib)

# def build(setup_kwargs):
#     """
#     Integração com a compilação de bibliotecas C++ e Cython.
#     """
#     build_cpp()  # Compila a biblioteca C++ usando CMake

#     # Configuração de extensões Cython
#     libs_names = ["octree"]
#     extensions = []
#     for lib_name in libs_names:
#         ext = Extension(
#             f"cpppy.mcpp.{lib_name}",
#             sources=[
#                 f"cpppy/mcpp/{lib_name}.pyx",
#                 # Adicione outros arquivos C++ aqui, se necessário
#             ],
#             include_dirs=["cpppy/mcpp/include/"],
#             library_dirs=["cpppy/mcpp/lib/"],
#             runtime_library_dirs=["cpppy/mcpp/lib/"],
#             libraries=[f"{lib_name}"],  # Refere-se a "lib{lib_name}.so"
#         )
#         extensions.append(ext)

#     # Integra as extensões com o setup.py
#     setup_kwargs["ext_modules"] = cythonize(extensions, compiler_directives={"language_level": "3str"}, force=True)