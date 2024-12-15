# Search Engine
[![CMake Build and Test](https://github.com/pedrobiqua/Search_Engine/actions/workflows/cmake-multi-platform.yml/badge.svg?branch=main)](https://github.com/pedrobiqua/Search_Engine/actions/workflows/cmake-multi-platform.yml)


[![English Version](https://img.shields.io/badge/English-Version-blue?style=for-the-badge)](#english-version)

Este projeto é um motor de busca simples que utiliza páginas da Wikipedia. Ele constrói um índice reverso para buscar palavras-chave e utiliza o algoritmo PageRank para ranquear as páginas com base na relevância e nos links entre elas.

## Requisitos

Antes de compilar o projeto, certifique-se de que seu ambiente atenda aos seguintes requisitos:

- CMake 3.10 ou superior
- Google Test para testes unitários
- Um compilador compatível com C++11 ou superior

## Estrutura do Projeto

- **src/**: Implementação principal do motor de busca, incluindo o índice reverso e o PageRank.
- **tests/**: Testes unitários para verificar a funcionalidade do sistema.
- **CMakeLists.txt**: Arquivo de configuração para construir o projeto com CMake.

## Compilando o Projeto

Para compilar o projeto, siga os seguintes passos:

1. Crie um diretório `build` e entre nele:

    ```bash
    mkdir build && cd build
    ```

2. Execute o CMake para gerar os arquivos de compilação:

    ```bash
    cmake ..
    ```

3. Compile o projeto utilizando `make`:

    ```bash
    make
    ```

## Executando os Testes

Como este projeto é uma biblioteca, você pode rodar os testes unitários para verificar a funcionalidade.

1. Após a compilação, no diretório `build`, execute o comando:

    ```bash
    ./tests/unit-tests/LibUnitTests
    ```

Isso executará os testes que cobrem o funcionamento da engine, indexação reversa e PageRank.

## Funcionamento

- **Indexação Reversa**: Mapeia palavras-chave para as páginas da Wikipedia onde aparecem.
- **PageRank**: Algoritmo que atribui uma pontuação de relevância a cada página baseada nos links e na estrutura da Wikipedia.
- **Consulta**: Busca páginas relacionadas a uma palavra-chave e ordena os resultados com base no PageRank.

## Licença

Ainda estamos avaliando qual lincença será a lincença que será utilizada.

Here’s the README translated into English:

---

# English Version

This project is a simple search engine that utilizes Wikipedia pages. It builds a reverse index for keyword searching and uses the PageRank algorithm to rank pages based on relevance and interlinking.

## Requirements

Before compiling the project, make sure your environment meets the following requirements:

- CMake 3.10 or higher
- Google Test for unit testing
- A compiler compatible with C++11 or higher

## Project Structure

- **src/**: Main implementation of the search engine, including the reverse index and PageRank.
- **tests/**: Unit tests to verify the functionality of the system.
- **CMakeLists.txt**: Configuration file for building the project with CMake.

## Building the Project

To compile the project, follow these steps:

1. Create a `build` directory and navigate into it:

    ```bash
    mkdir build && cd build
    ```

2. Run CMake to generate the build files:

    ```bash
    cmake ..
    ```

3. Compile the project using `make`:

    ```bash
    make
    ```

## Running Tests

Since this project is a library, you can run the unit tests to verify its functionality.

1. After building, in the `build` directory, execute:

    ```bash
    ./tests/unit-tests/LibUnitTests
    ```

This will run the tests covering the search engine functionality, reverse indexing, and PageRank.

## How It Works

- **Reverse Indexing**: Maps keywords to the Wikipedia pages in which they appear.
- **PageRank**: An algorithm that assigns a relevance score to each page based on links and the structure of Wikipedia.
- **Querying**: Searches for pages related to a keyword and ranks the results based on PageRank.

## License

---
