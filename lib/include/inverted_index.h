#ifndef INVERTED_INDEX
#define INVERTED_INDEX

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>


namespace inverted_index
{

    const std::string _CHARS = "abcdefghijklmnopqrstuvwxyz0123456789.:-_/";
    const size_t MAX_NODES = 41;

    class node {
    public:
        node() { isWord = false; }
        ~node() { for(auto& pair : next) delete pair.second; }
        bool isWord;
        std::vector<std::string> files;
        std::unordered_map<char, node*> next;
    };

    class index {
    public:
        void add( std::string s, std::string fileName );
        void findWord( std::string s );

    private:

        void pushFileName( node* n, std::string fn );
        const std::vector<std::string>& find( std::string s );
        node* addWord(std::string s);
        node root;
    };
    
} // namespace inverted_index

#endif // INVERTED_INDEX