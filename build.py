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
    import pathlib


BUILD_FOLDER = "build"

def build_lib_cpp(path: str):
    if not os.path.exists(path):
        old_path = os.getcwd()
        os.makedirs(path)
        os.chdir(path)
        subprocess.run(["cmake", "..", "-DBUILD_TESTS=OFF"])
        subprocess.run(["make"])
        os.chdir(old_path)

def copy_lib(root_path, path_lib):
    extensions = [".so*", ".dll*", ".dylib*"]
    for ext in extensions:
        path_so = root_path.glob(f"{BUILD_FOLDER}/lib/*{ext}")
        path_lib.mkdir(exist_ok=True, parents=True)
        # Copy each .so file
        for lib in path_so:
            shutil.copy(lib, path_lib)
            print(f"\n\n\n{path_lib}\n\n\n")

# setup_kwargs
def build(setup_kwargs):
    # Monta a biblioteca c++ para ser usada no Python
    build_lib_cpp(BUILD_FOLDER)
    root_path = pathlib.Path(__file__).parent
    path_lib = pathlib.Path(__file__).parent / "search_engine_cpp/lib"
    copy_lib(root_path, path_lib)
    library_dir = os.path.abspath("search_engine_cpp/lib")


    # Modulos que serão usados no Python
    # TODO: Lembrar de arrumar o build, poois vou querer que seja feito esse esquema de pasta para o stemmer e todas as ferramentas de preprocessamento
    libs_names = [
        "_hello",
        "_page_rank",
        "_inverted_index",
        "preprocessing.stemmer_cpp"
    ]

    extensions = []

    for lib in libs_names:
        lib_pyx = lib.replace(".", "/")

        ext = Extension(
            f"search_engine_cpp.{lib}",
            language="c++",
            sources=[
                f"lib/src/{lib_pyx}.pyx"
            ],
            include_dirs=["lib/include"],
            library_dirs=[library_dir],
            runtime_library_dirs=[library_dir],
            libraries=["search_engine"],
            # extra_compile_args=["-std=c++11"]
        )
        extensions.append(ext)

    # Monta o setup usando o extensions
    # setup_kwargs["cmdclass"] = {"build_ext": build_ext}
    setup_kwargs["script_args"] = ["build_ext"]
    # Inclua os arquivos .so na instalação
    setup_kwargs["package_data"] = {
        "search_engine_cpp": ["lib/*.so"]
    }
    setup_kwargs["include_package_data"] = True

    setup_kwargs["ext_modules"] = cythonize(extensions, compiler_directives={"language_level": "3str"}, force=True)
