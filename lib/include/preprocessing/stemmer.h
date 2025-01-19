#ifndef STEMMER_H
#define STEMMER_H

#include <unicode/locid.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>

#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

namespace stemmer {

/**
 * @brief Represents a suffix transformation rule.
 */
struct StepRule {
    std::string suffixToRemove;  ///< Suffix to be removed.
    int minimumStemSize;      ///< Minimum stem size after removing the suffix.
    std::string replacement;  ///< Suffix replacement.
};

using RuleMap = std::map<std::string, std::vector<StepRule>>;

/**
 * @class RSPL
 * @brief Implements the RSPL stemming algorithm.
 */
class RSPL {
   public:
    /**
     * @brief Default constructor.
     * Initializes predefined rules.
     */
    RSPL();

    /**
     * @brief Destructor.
     */
    ~RSPL();

    /**
     * @brief Executes the stemming process on a sentence or word.
     * @param sentence The sentence (or word) to be processed.
     */
    void run(std::string* sentence);

   private:
    RuleMap ruleMap_;  ///< Mapping of rules for each suffix.

    /**
     * @brief Mapping to normalize accented characters to their ASCII
     * equivalents.
     */
    const std::unordered_map<wchar_t, wchar_t> accentMap_ = {
        {L'á', L'a'}, {L'à', L'a'}, {L'â', L'a'}, {L'ã', L'a'}, {L'ä', L'a'},
        {L'é', L'e'}, {L'è', L'e'}, {L'ê', L'e'}, {L'ë', L'e'}, {L'í', L'i'},
        {L'ì', L'i'}, {L'î', L'i'}, {L'ï', L'i'}, {L'ó', L'o'}, {L'ò', L'o'},
        {L'ô', L'o'}, {L'õ', L'o'}, {L'ö', L'o'}, {L'ú', L'u'}, {L'ù', L'u'},
        {L'û', L'u'}, {L'ü', L'u'}, {L'ç', L'c'}, {L'Á', L'A'}, {L'À', L'A'},
        {L'Â', L'A'}, {L'Ã', L'A'}, {L'Ä', L'A'}, {L'É', L'E'}, {L'È', L'E'},
        {L'Ê', L'E'}, {L'Ë', L'E'}, {L'Í', L'I'}, {L'Ì', L'I'}, {L'Î', L'I'},
        {L'Ï', L'I'}, {L'Ó', L'O'}, {L'Ò', L'O'}, {L'Ô', L'O'}, {L'Õ', L'O'},
        {L'Ö', L'O'}, {L'Ú', L'U'}, {L'Ù', L'U'}, {L'Û', L'U'}, {L'Ü', L'U'},
        {L'Ç', L'C'}};

    /**
     * @brief Applies transformation rules to a word.
     * @param word The word to be processed.
     * @param rules The transformation rules to be applied.
     * @return `true` if a rule was applied, otherwise `false`.
     */
    bool applyRules(std::string& word, const std::vector<StepRule>& rules);

    /**
     * @brief Checks if a word ends with 's'.
     * @param word The word to be checked.
     * @return `true` if the word ends with 's', otherwise `false`.
     */
    bool endsWithS(const std::string& word);

    /**
     * @brief Checks if a word ends with 'a'.
     * @param word The word to be checked.
     * @return `true` if the word ends with 'a', otherwise `false`.
     */
    bool endsWithA(const std::string& word);

    /**
     * @brief Splits a string into parts based on delimiters.
     * @param s The string to be split.
     * @return A vector containing the parts of the string.
     */
    std::vector<std::string> split(std::string& s);

    /**
     * @brief Removes accents from a string.
     * @param input The input string.
     * @return The string without accents.
     */
    std::string removeAccents(const std::string& input);

    /**
     * @brief Shrinks the size of a string to normalize it.
     * @param input Pointer to the input string.
     */
    void shrinkString(std::string* input);
};

}  // namespace stemmer

#endif  // STEMMER_H
