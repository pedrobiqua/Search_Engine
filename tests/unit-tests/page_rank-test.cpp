#include <gtest/gtest.h>

#include "page_rank.h"

// Teste para verificar a adição de arestas no grafo
TEST(PageRankTest, AddEdge) {
    page_rank::Graph g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);

    // Verifica se a aresta foi adicionada corretamente
    std::map<int, std::list<int>> expected = {{1, {2, 3}}};
    std::map<int, std::list<int>> actual =
        g.get_adjList();  // Necessita de um getter
    EXPECT_EQ(actual, expected);
}

// Teste para verificar a convergência do PageRank
TEST(PageRankTest, PageRankConvergence) {
    page_rank::Graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 1);

    auto page_ranks = g.compute_page_rank();

    // Como o grafo é bidirecional e balanceado, o PageRank deve ser igual para
    // ambos os nós
    EXPECT_NEAR(page_ranks[1], 0.5, 1e-6);
    EXPECT_NEAR(page_ranks[2], 0.5, 1e-6);
}

// Teste para verificar a execução correta do algoritmo em um grafo maior
TEST(PageRankTest, LargerGraph) {
    page_rank::Graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 1);

    auto page_ranks = g.compute_page_rank();

    // Não esperamos resultados exatos aqui, mas podemos verificar se os valores
    // fazem sentido
    EXPECT_GT(page_ranks[1], 0.0);
    EXPECT_GT(page_ranks[2], 0.0);
    EXPECT_GT(page_ranks[3], 0.0);
}