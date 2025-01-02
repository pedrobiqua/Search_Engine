#ifndef INVERTED_INDEX
#define INVERTED_INDEX

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace inverted_index {
/**
 * @typedef str
 * @brief Type used to represent a string.
 */
typedef std::string str;

/**
 * @typedef list_str
 * @brief Type used to represent a list of strings.
 */
typedef std::list<str> list_str;

/**
 * @define DELIMITER
 * @brief Delimiter used to split strings.
 */
#define DELIMITER " "

/**
 * @struct docs
 * @brief Structure that stores information about a document.
 *
 * The `docs` structure stores the document name, occurrence frequency,
 * and links to other documents that the current document references.
 */
struct docs {
    str name_doc; /**< Document name */
    int freq;     /**< Document occurrence frequency */
    list_str
        links_docs; /**< List of documents the current document points to */

    /**
     * @brief Equality operator to compare documents.
     * @param other Another document to compare.
     * @return `true` if the documents are equal, `false` otherwise.
     */
    bool operator==(const docs& other) const {
        return (name_doc == other.name_doc);
    }

    /**
     * @brief Less-than operator for document comparison (used by containers
     * like `set`).
     * @param other Another document to compare.
     * @return `true` if the current document is less than the other, based on
     * the name.
     */
    bool operator<(const docs& other) const {
        return name_doc < other.name_doc;
    }

    /**
     * @brief `+=` operator to increment the document's frequency.
     * @param value Value to add to the frequency.
     * @return Reference to the current document with the updated frequency.
     */
    docs& operator+=(int value) {
        freq += value;
        return *this;
    }

    /**
     * @brief Stream operator overload to print document information.
     * @param os Output stream.
     * @param d Document to print.
     * @return Output stream with the document's information.
     */
    friend std::ostream& operator<<(std::ostream& os, const docs& d) {
        os << "Doc: " << d.name_doc << " | Freq: " << d.freq;
        return os;
    }
};

/**
 * @typedef list_docs
 * @brief Type used to represent a list of documents.
 */
typedef std::list<docs> list_docs;

/**
 * @typedef map_str_docs
 * @brief Type used to represent a map of words to a list of documents.
 */
typedef std::map<str, list_docs> map_str_docs;

/**
 * @typedef set_docs
 * @brief Type used to represent a set of documents.
 */
typedef std::set<docs> set_docs;

/**
 * @typedef vector_str
 * @brief Type used to represent a vector of strings.
 */
typedef std::vector<str> vector_str;

/**
 * @brief Converts a character to lowercase.
 * @param c Character to convert.
 * @return Character converted to lowercase.
 */
char to_lowercase(unsigned char c) {
    return std::tolower(c);
}

/**
 * @brief Splits a string based on a delimiter.
 * @param s String to split.
 * @param delimiter Delimiter to split the string.
 * @return Vector of strings resulting from the split.
 */
vector_str split(str& s, const str& delimiter);

/**
 * @brief Adds a new document to the document map.
 * @param mp Map of words to lists of documents.
 * @param doc_name Name of the document to add.
 * @param text Document text to analyze.
 * @return Updated map with the new document.
 */
map_str_docs add_doc(map_str_docs& mp, const str& doc_name, str& text);

/**
 * @brief Finds documents that contain a given word.
 * @param mp Map of words to lists of documents.
 * @param word Word to search for in the documents.
 * @return List of documents containing the word.
 */
list_docs find_doc(map_str_docs& mp, str& word);

/**
 * @brief Finds documents relevant to a query (input).
 * @param mp Map of words to lists of documents.
 * @param input Input word to search for.
 * @return List of documents relevant to the query.
 */
list_docs find_answer(map_str_docs& mp, str& input);

/**
 * @brief Removes unwanted characters from a string, such as extra spaces.
 * @param input String to process.
 */
void shrink_string(std::string* input);
}  // namespace inverted_index

#endif  // INVERTED_INDEX
