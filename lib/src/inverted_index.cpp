#include "inverted_index.h"

inverted_index::node::node() {
    inverted_index::node::isWord = false; 
}

inverted_index::node::~node() {
    for(auto& pair : next) delete pair.second; 
}


void inverted_index::index::add( std::string s, std::string fileName ) {
    std::transform( s.begin(), s.end(), s.begin(), tolower );
    std::string h;
    for( std::string::iterator i = s.begin(); i != s.end(); i++ ) {
        if( *i == 32 ) {
            pushFileName( addWord( h ), fileName );
            h.clear();
            continue;
        }
        h.append( 1, *i );
    }
    if( h.length() )
        pushFileName( addWord( h ), fileName );
}

void inverted_index::index::findWord( std::string s ) {
    std::vector<std::string> v = find( s );
    if( !v.size() ) {
        std::cout << s + " was not found!\n";
        return;
    }
    std::cout << s << " found in:\n";
    for( std::vector<std::string>::iterator i = v.begin(); i != v.end(); i++ ) {
        std::cout << *i << "\n";
    }
    std::cout << "\n";
}

void inverted_index::index::pushFileName( node* n, std::string fn ) {
    std::vector<std::string>::iterator i = std::find( n->files.begin(), n->files.end(), fn );
    if( i == n->files.end() ) n->files.push_back( fn );
}

const std::vector<std::string>& inverted_index::index::find( std::string s ) {
    size_t idx;
    std::transform( s.begin(), s.end(), s.begin(), tolower );
    node* rt = &root;
    for( std::string::iterator i = s.begin(); i != s.end(); i++ ) {
        idx = _CHARS.find( *i );
        if( idx < MAX_NODES ) {
            if( !rt->next[idx] ) return std::vector<std::string>();
            rt = rt->next[idx];
        }
    }
    if( rt->isWord ) return rt->files;
    return std::vector<std::string>();
}

inverted_index::node* inverted_index::index::addWord(std::string s) {
    node* rt = &root;
    for (char c : s) {
        if (rt->next.find(c) == rt->next.end()) {
            rt->next[c] = new node();
        }
        rt = rt->next[c];
    }
    rt->isWord = true;
    return rt;
}