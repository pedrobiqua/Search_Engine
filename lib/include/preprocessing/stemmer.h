#ifndef STEMMER
#define STEMMER

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
 * Regra de cada step
 */
struct step_rule {
    std::string suffix_to_remove;
    int minimun_stem_size;
    std::string replacement;
};

typedef std::map<std::string, std::vector<step_rule>> map_str_vec_step_rule;

/**
 * Classe que implementa o algoritimo RSPL
 */
class rspl {
   private:
    map_str_vec_step_rule rule_map;
    std::unordered_map<char, char> accent_map = {
        {'á', 'a'}, {'à', 'a'}, {'â', 'a'}, {'ã', 'a'}, {'ä', 'a'}, {'é', 'e'},
        {'è', 'e'}, {'ê', 'e'}, {'ë', 'e'}, {'í', 'i'}, {'ì', 'i'}, {'î', 'i'},
        {'ï', 'i'}, {'ó', 'o'}, {'ò', 'o'}, {'ô', 'o'}, {'õ', 'o'}, {'ö', 'o'},
        {'ú', 'u'}, {'ù', 'u'}, {'û', 'u'}, {'ü', 'u'}, {'ç', 'c'}, {'Á', 'A'},
        {'À', 'A'}, {'Â', 'A'}, {'Ã', 'A'}, {'Ä', 'A'}, {'É', 'E'}, {'È', 'E'},
        {'Ê', 'E'}, {'Ë', 'E'}, {'Í', 'I'}, {'Ì', 'I'}, {'Î', 'I'}, {'Ï', 'I'},
        {'Ó', 'O'}, {'Ò', 'O'}, {'Ô', 'O'}, {'Õ', 'O'}, {'Ö', 'O'}, {'Ú', 'U'},
        {'Ù', 'U'}, {'Û', 'U'}, {'Ü', 'U'}, {'Ç', 'C'}};

    bool apply_rules(std::string& word, const std::vector<step_rule>& rules);
    bool ends_s(const std::string& word);
    bool ends_a(const std::string& word);
    std::vector<std::string> split(std::string& s);
    std::string remove_accents(const std::string& input);
    void shrink_string(std::string* input);

   public:
    rspl();  // inicializa as regras que já são pre-definidas
    ~rspl();

    // Vai ser de uma frase, ou vai ser palavra por palavra?
    void run(std::string* sentence);
};

}  // namespace stemmer

#endif  // STEMMER