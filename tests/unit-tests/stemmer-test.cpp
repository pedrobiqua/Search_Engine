#include <gtest/gtest.h>

#include "preprocessing/stemmer.h"

TEST(StemmerTest, TestRules) {
    // Inicializa o stemmer
    stemmer::RSPL stemmer;
    // std::string sentence = "O coração bate rapidamente na cidade";
    // std::string expected_sentence = "o corac bat rapid na cidad";

    // stemmer.run(&sentence);
    // EXPECT_EQ(sentence, expected_sentence);

    std::string sentence = "O vitor bebeu muita cerveja";
    std::string expected_sentence = "o vitor beb muit cervej";
    stemmer.run(&sentence);
    EXPECT_EQ(sentence, expected_sentence);
}