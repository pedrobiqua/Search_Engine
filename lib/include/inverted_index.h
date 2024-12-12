#ifndef INVERTED_INDEX
#define INVERTED_INDEX

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <set>

namespace inverted_index {
    typedef std::string str;
    typedef std::list<str> list_str;
    #define DELIMITER " "

    struct docs {
        str name_doc;
        int freq;
        list_str links_docs; // Armazenar os nomes de documentos que aquele documento aponta

        bool operator==(const docs& other) const {return (name_doc == other.name_doc);}

        bool operator<(const docs& other) const {return name_doc < other.name_doc;}

        docs& operator +=(int value){freq += value;return *this;}

        friend std::ostream& operator<<(std::ostream& os, const docs& d) {
            os << "Doc: " << d.name_doc << " | Freq: " << d.freq;
            return os;
        }
    };

    typedef std::list<docs> list_docs;
    typedef std::map<str, list_docs> map_str_docs;
    typedef std::set<docs> set_docs;
    typedef std::vector<str> vector_str;

    char to_lowercase(unsigned char c) {
        return std::tolower(c);
    }

    vector_str split(str& s, const str& delimiter);
    map_str_docs add_doc(map_str_docs& mp, const str& doc_name, str& text);
    list_docs find_doc(map_str_docs& mp, str& word);
    list_docs find_answer(map_str_docs& mp, str& input);
    void shrink_string(std::string* input);
}

#endif // INVERTED_INDEX