#include "inverted_index.h"
#include <gtest/gtest.h>
#include <string>

// Teste para verificar a adição de texto
#include <gtest/gtest.h>

using namespace std::string_literals;

TEST(InvertedIndexTest, AddAndFindDocuments) {
    // Map onde será armazenado os índices e suas respectivas listas de
    // documentos
    inverted_index::map_str_docs mp;

    // Documentos de exemplo
    std::vector<std::pair<std::string, std::string>> documents = {
        {"Albert Einstein",
         "A imaginação é mais importante que o conhecimento, pois o "
         "conhecimento é limitado."},
        {"Isaac Newton",
         "Se vi mais longe foi por estar sobre ombros de gigantes."},
        {"René Descartes",
         "Penso, logo existo. É a base do conhecimento humano."},
        {"Aristóteles", "A felicidade depende de nós mesmos."},
        {"Sócrates",
         "Só sei que nada sei, mas em reconhecer minha ignorância, abro as "
         "portas para o aprendizado."},
        {"Leonardo da Vinci",
         "A simplicidade é o último grau de sofisticação."},
        {"Galileu Galilei", "Eppur si muove."},
        {"Confúcio",
         "Aquele que move montanhas começa carregando pequenas pedras."}};

    // Adicionando os documentos ao índice
    for (auto& [author, phrase] : documents) {
        inverted_index::add_doc(mp, author, phrase);
    }

    // Verifica se palavras específicas foram indexadas corretamente
    ASSERT_EQ(mp["imaginação"].size(), 1);
    ASSERT_EQ(mp["conhecimento"].size(), 2);
    ASSERT_EQ(mp["felicidade"].size(), 1);
    ASSERT_EQ(mp["montanhas"].size(), 1);

    // Realiza buscas específicas e verifica os resultados
    inverted_index::str input = "conhecimento";
    inverted_index::list_docs docs = inverted_index::find_answer(mp, input);

    ASSERT_EQ(docs.size(), 2);  // Deve retornar 2 documentos
    EXPECT_TRUE(std::any_of(docs.begin(), docs.end(),
                            [](const inverted_index::docs& d) {
                                return d.name_doc == "Albert Einstein";
                            }));
    EXPECT_TRUE(std::any_of(docs.begin(), docs.end(),
                            [](const inverted_index::docs& d) {
                                return d.name_doc == "René Descartes";
                            }));

    // Testa uma palavra que não está nos documentos
    input = "inexistente";
    docs = inverted_index::find_answer(mp, input);

    ASSERT_TRUE(docs.empty());  // Não deve encontrar nada
}

TEST(InvertedIndexTest, CaseInsensitiveSearch) {
    // Map onde será armazenado os índices e suas respectivas listas de
    // documentos
    inverted_index::map_str_docs mp;

    // Documento simples
    std::string text = "A imaginação abrange o mundo inteiro.";
    inverted_index::add_doc(mp, "Teste", text);

    // Busca case-insensitive
    inverted_index::str input = "IMAGINAÇÃO";
    inverted_index::list_docs docs = inverted_index::find_answer(mp, input);

    ASSERT_EQ(docs.size(), 1);
    EXPECT_EQ(docs.front().name_doc, "Teste");
}