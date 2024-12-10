#include "inverted_index.h"

inverted_index::vector_str inverted_index::split(inverted_index::str& s, const str& delimiter) {
    std::vector<str> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

inverted_index::map_str_docs inverted_index::add_doc(inverted_index::map_str_docs& mp, const inverted_index::str& doc_name, inverted_index::str& text){
    auto words = inverted_index::split(text, DELIMITER);

    for(const auto& word : words) {
        inverted_index::docs target = {doc_name, 1};
        // Procura pelo elemento dentro da lista da palavra
        auto it = std::find(mp[word].begin(), mp[word].end(), target);
        if(it != mp[word].end()){
            *it += 1; // Incrementa o valor contido dentro do documento
        } else {
            mp[word].push_back(target);
        }
    }

    return mp;
}

inverted_index::list_docs inverted_index::find_doc(inverted_index::map_str_docs& mp, str& word){
    return mp[word];
}

inverted_index::list_docs inverted_index::find_answer(inverted_index::map_str_docs& mp, inverted_index::str& input) {
    inverted_index::list_docs result;
    inverted_index::set_docs unique_docs;

    // Coloca o texto em minúsculas
    std::transform(input.begin(), input.end(), input.begin(), to_lowercase);

    // Divide o input em palavras com base no delimitador
    auto words = split(input, DELIMITER);

    for (auto& word : words) {
        list_docs docs = find_doc(mp, word); // Busca documentos relacionados à palavra
        for (const auto& d : docs) {
            unique_docs.insert(d); // Armazena apenas os nomes dos documentos
        }
    }

    // Converte os nomes únicos de volta para objetos do tipo `docs`
    for (const auto& doc : unique_docs) {
        result.push_back({doc}); // Freq = 0, pois não é usada aqui
    }

    return result;
}