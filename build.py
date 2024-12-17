import os

# See if Cython is installed
try:
    from Cython.Build import cythonize
# Do nothing if Cython is not available
except ImportError:
    # Got to provide this function. Otherwise, poetry will fail
    def build(setup_kwargs):
        pass
# Cython is installed. Compile
else:
    from setuptools import Extension, setup
    from setuptools.dist import Distribution
    from distutils.command.build_ext import build_ext
    import subprocess
    import glob
    import shutil


BUILD_FOLDER = "build"

def build_lib_cpp(path: str):
    if not os.path.exists(path):
        old_path = os.getcwd()
        os.makedirs(path)
        os.chdir(path)
        subprocess.run(["cmake", ".."])
        subprocess.run(["make"])
        os.chdir(old_path)

def build(setup_kwargs):
    # Monta a biblioteca c++ para ser usada no Python
    build_lib_cpp(BUILD_FOLDER)
    library_dir = os.path.abspath("build/lib")

    # Modulos que serão usados no Python
    libs_names = [
        "_hello",
        "_page_rank",
        "_inverted_index"
    ]

    extensions = []

    for lib in libs_names:
        ext = Extension(
            f"{lib}",
            language="c++",
            sources=[
                f"lib/src/{lib}.pyx"
            ],
            include_dirs=["lib/include"],
            library_dirs=[library_dir],
            runtime_library_dirs=[library_dir],
            libraries=["search_engine"],
            # extra_compile_args=["-std=c++11"]
        )
        extensions.append(ext)

    # Monta o setup usando o extensions
    setup_kwargs["ext_modules"] = cythonize(extensions, compiler_directives={"language_level": "3str"}, force=True)
    # setup(
    #     name="search_engine",
    #     ext_modules=cythonize(extensions, compiler_directives={"language_level": "3str"}, force=True)
    # )

    # Depois de buildar mover os .so na pasta search_engine
    # old_path = os.getcwd()
    # dest_path = os.path.abspath("search_engine")

    # for so_file in glob.glob(old_path + "/*.so"):
    #     shutil.move(so_file, dest_path)
    #     print(f"Moved {so_file} -> {dest_path}")



# build()
################################################################################################################
## COMPILANDO ANTES

# Definir a extensão Cython
# extensions = [
#     Extension(
#         "search_engine",
#         sources=["lib/src/_hello.pyx"],  # Arquivo Cython
#         language="c++",
#         libraries=["search_engine"],  # Nome da biblioteca C++
#         library_dirs=[library_dir],  # Diretório da biblioteca, onde tem os .so
#         include_dirs=["lib/include"],  # Incluir o diretório include
#         extra_compile_args=["-std=c++11"],
#         runtime_library_dirs=[library_dir],
#         cython_directives={"language_level": "3str"},
#     )
# ]

# Compilar o Cython
# setup(
#     name="search_engine",
#     ext_modules=cythonize(extensions),
# )