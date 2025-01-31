#include "inverted_index.h"
#include <bits/stdc++.h>
#include <unicode/locid.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <cwctype>
#include <locale>

using namespace inverted_index;

map_str_docs inverted_index::add_doc(map_str_docs& mp,
                                     const str& doc_name,
                                     str& text) {
    utils::shrink_string(&text);
    auto words = utils::split(text, utils::DELIMITER);

    for (const auto& word : words) {
        docs target = {doc_name, 1};
        // Procura pelo elemento dentro da lista da palavra
        auto it = std::find(mp[word].begin(), mp[word].end(), target);
        if (it != mp[word].end()) {
            *it += 1;  // Incrementa o valor contido dentro do documento
        } else {
            mp[word].push_back(target);
        }
    }

    return mp;
}

list_docs inverted_index::find_doc(map_str_docs& mp, str& word) {
    return mp[word];
}

list_docs inverted_index::find_answer(map_str_docs& mp, str& input) {
    list_docs result;
    set_docs unique_docs;

    utils::shrink_string(&input);
    auto words = utils::split(input, utils::DELIMITER);

    for (auto& word : words) {
        list_docs docs = inverted_index::find_doc(
            mp, word);  // Busca documentos relacionados à palavra
        for (const auto& d : docs) {
            unique_docs.insert(d);  // Armazena apenas os nomes dos documentos
        }
    }

    // Converte os nomes únicos de volta para objetos do tipo `docs`
    for (const auto& doc : unique_docs) {
        result.push_back({doc});  // Freq = 0, pois não é usada aqui
    }

    return result;
}