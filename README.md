# Projeto Exemplo

Esse projeto serve para ilustrar como é que pode ser utilizado CMake em um projeto C++.

Para compilar e executar crie uma pasta build e abra ela.

```bash
mkdir build && cd build 
```

Dentro da pasta build execute o seguinte comando.

```bash
cmake ../ 
```

Para compilar o programa.

```bash
make
```

### Executando testes

Como esse programa é uma biblioteca de exemplo, para ver seu funcionamento basta executar o arquivo de testes. Dentro do diretório build execute o comando abaixo.

```bash
./tests/unit-tests/LibUnitTests  
```