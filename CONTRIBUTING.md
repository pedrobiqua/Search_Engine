# Contribuindo para o Projeto Search Engine

Obrigado por considerar contribuir para o projeto **Search Engine**! Ao seguir estas diretrizes, você estará nos ajudando a manter a qualidade do projeto e a garantir que suas contribuições sejam facilmente integradas.

## Como Contribuir

### 1. Fork do Repositório

Faça um fork do repositório principal e clone o fork em seu ambiente local:

```bash
git clone https://github.com/seu-usuario/search-engine.git
```

### 2. Crie uma Branch para a Sua Contribuição

Use uma branch separada para sua contribuição. Certifique-se de nomear a branch de acordo com a funcionalidade ou correção que está trabalhando:

```bash
git checkout -b minha-nova-funcionalidade
```

### 3. Faça Commits Claros e Significativos

Escreva mensagens de commit descritivas e curtas. Utilize o seguinte padrão de commit:

- Use o modo imperativo ("Adiciona suporte para...").
- Mantenha a primeira linha da mensagem de commit com no máximo 50 caracteres.
- Adicione uma descrição adicional após uma linha em branco, se necessário.

Exemplo de mensagem de commit:

```bash
git commit -m "Corrige bug no algoritmo PageRank"

git commit -m "Adiciona funcionalidade de busca por palavras-chave
- Implementa a função de busca no índice reverso
- Melhora a performance da indexação de grandes volumes de dados"
```

### 4. Sincronize Seu Fork Regularmente

Mantenha seu fork atualizado com as alterações do repositório principal:

```bash
git fetch upstream
git checkout main
git merge upstream/main
```

### 5. Execute os Testes

Certifique-se de que sua contribuição não quebre nada. Rode os testes unitários antes de submeter seu pull request:

```bash
make test
```

Se necessário, adicione novos testes cobrindo sua funcionalidade ou correção.

### 6. Abra um Pull Request

Depois de concluir suas alterações e testar o código, envie seu pull request:

1. Vá até a página do seu fork no GitHub.
2. Clique em "New Pull Request".
3. Preencha o título e a descrição do pull request com o máximo de detalhes sobre as alterações.

---

## Revisão de Código

Ao abrir um pull request, ele será revisado por um dos mantenedores do projeto. Tenha paciência, pois o processo de revisão pode levar algum tempo, dependendo da complexidade das alterações. Pedidos de alteração podem ser feitos durante a revisão.

## Padrões de Código

Siga estas diretrizes de estilo ao contribuir com o código:

- **Padrão C++11**: Certifique-se de que o código está compatível com o padrão C++11 ou superior.
- **Indentação**: Utilize indentação com 4 espaços, sem tabulações.
- **Nomenclatura**: Use nomes de variáveis e funções claros e significativos. Utilize `CamelCase` para classes e `snake_case` para variáveis e funções.
- **Documentação**: Escreva comentários explicativos para funções complexas ou código não trivial.

---

## Reportando Bugs

Se encontrar um bug, por favor, abra um **issue** no GitHub com as seguintes informações:

1. Descrição do bug.
2. Passos para reproduzir o bug.
3. Qual o comportamento esperado.
4. Informações sobre o ambiente (sistema operacional, versão do compilador, etc.).

---

## Agradecimentos

Agradecemos por dedicar seu tempo e esforço para melhorar o **Search Engine**. Sua contribuição é muito valiosa para nós!

---

# Contributing to the Search Engine Project

Thank you for considering contributing to the **Search Engine** project! By following these guidelines, you will help maintain the project's quality and ensure that your contributions can be easily integrated.

## How to Contribute

### 1. Fork the Repository

Fork the main repository and clone the fork to your local environment:

```bash
git clone https://github.com/your-username/search-engine.git
```

### 2. Create a Branch for Your Contribution

Create a separate branch for your contribution. Make sure to name the branch according to the feature or bug fix you are working on:

```bash
git checkout -b my-new-feature
```

### 3. Make Clear and Meaningful Commits

Write descriptive and concise commit messages. Follow this commit message convention:

- Use the imperative mood ("Add support for...").
- Keep the first line of the commit message under 50 characters.
- Add a longer description after a blank line, if needed.

Example commit message:

```bash
git commit -m "Fix bug in PageRank algorithm"

git commit -m "Add keyword search functionality
- Implement search function in the reverse index
- Improve indexing performance for large data sets"
```

### 4. Keep Your Fork Synchronized

Regularly update your fork with changes from the main repository:

```bash
git fetch upstream
git checkout main
git merge upstream/main
```

### 5. Run Tests

Ensure that your contribution does not break anything. Run the unit tests before submitting your pull request:

```bash
make test
```

If necessary, add new tests covering your functionality or fix.

### 6. Submit a Pull Request

After completing your changes and testing the code, submit your pull request:

1. Go to the page of your fork on GitHub.
2. Click "New Pull Request."
3. Provide a detailed title and description for your pull request explaining the changes.

---

## Code Review

When you open a pull request, it will be reviewed by one of the project maintainers. Please be patient, as the review process may take some time depending on the complexity of the changes. Reviewers may request changes during the process.

## Coding Standards

Follow these coding guidelines when contributing:

- **C++11 Standard**: Ensure your code complies with the C++11 standard or higher.
- **Indentation**: Use 4 spaces for indentation, no tabs.
- **Naming Conventions**: Use clear and meaningful names for variables and functions. Use `CamelCase` for class names and `snake_case` for variables and functions.
- **Documentation**: Write comments to explain complex functions or non-trivial code.

---

## Reporting Bugs

If you find a bug, please open an **issue** on GitHub with the following information:

1. Bug description.
2. Steps to reproduce the bug.
3. Expected behavior.
4. Environment information (OS, compiler version, etc.).

---

## Acknowledgements

Thank you for taking the time to contribute to the **Search Engine** project. Your contribution is greatly appreciated!
