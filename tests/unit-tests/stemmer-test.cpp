#include <gtest/gtest.h>

#include "preprocessing/stemmer.h"

TEST(StemmerTest, TestRules) {
    // Inicializa o stemmer
    stemmer::rspl stemmer;
    std::string sentence = "O coração bate rapidamente na cidade";
    std::string expected_sentence = "o coracao bat rapid na cidad";

    stemmer.run(&sentence);
    EXPECT_EQ(sentence, expected_sentence);
}