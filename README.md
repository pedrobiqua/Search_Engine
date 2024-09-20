# Search Engine

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
