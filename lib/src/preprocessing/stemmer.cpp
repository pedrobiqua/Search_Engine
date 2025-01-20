#include "preprocessing/stemmer.h"
#include <codecvt>
#include <locale>

namespace stemmer {
RSPL::RSPL() {
    // As regras são inicializadas no construtor da classe
    std::vector<StepRule> plural_reduction_rules = {
        {"ns", 1, "m"},   {"ões", 3, "ão"}, {"ães", 1, "ão"}, {"ais", 1, "al"},
        {"éis", 2, "el"}, {"eis", 2, "el"}, {"óis", 2, "ol"}, {"is", 2, "il"},
        {"is", 1, "l"},   {"res", 1, "r"},  {"s", 2, ""}};

    std::vector<StepRule> feminine_reduction_rules = {
        {"inha", 4, "inho"}, {"esa", 3, "es"}, {"osa", 3, "oso"},
        {"na", 2, "no"},     {"da", 2, "do"},  {"va", 2, "vo"},
        {"ia", 2, "io"}};

    std::vector<StepRule> augmentative_reduction_rules = {
        {"zão", 3, "z"},  {"são", 3, "s"},  {"ão", 2, "o"},
        {"ona", 3, "on"}, {"ões", 3, "ão"}, {"íssimos", 7, "o"}};

    std::vector<StepRule> diminutive_reduction_rules = {
        {"zinho", 5, ""},  {"zinha", 6, ""}, {"zinhos", 6, ""},
        {"zinhas", 7, ""}, {"inho", 4, ""},  {"inha", 5, ""}};

    std::vector<StepRule> verb_conjugation_reduction_rules = {
        // Infinitive reduction
        {"ar", 2, ""},
        {"er", 2, ""},
        {"ir", 2, ""},

        // Gerund reduction
        {"ando", 4, ""},
        {"endo", 4, ""},
        {"indo", 4, ""},

        // Past participle reduction
        {"ado", 3, ""},
        {"ido", 3, ""},

        // Future tense reduction
        {"arei", 4, ""},
        {"erei", 4, ""},
        {"irei", 4, ""},
        {"arás", 4, ""},
        {"erás", 4, ""},
        {"irás", 4, ""},
        {"ará", 3, ""},
        {"erá", 3, ""},
        {"irá", 3, ""},
        {"aremos", 6, ""},
        {"eremos", 6, ""},
        {"iremos", 6, ""},
        {"areis", 5, ""},
        {"ereis", 5, ""},
        {"ireis", 5, ""},
        {"arão", 4, ""},
        {"erão", 4, ""},
        {"irão", 4, ""},

        // Imperfect tense reduction
        {"ava", 3, ""},
        {"ia", 2, ""},
        {"ávamos", 6, ""},
        {"íamos", 5, ""},
        {"áveis", 5, ""},
        {"íeis", 5, ""},

        // Present tense reduction
        {"o", 1, ""},
        {"as", 2, ""},
        {"es", 2, ""},
        {"a", 1, ""},
        {"e", 1, ""},
        {"amos", 4, ""},
        {"emos", 4, ""},
        {"imos", 4, ""},
        {"ais", 3, ""},
        {"eis", 3, ""},
        {"is", 2, ""},
        {"am", 2, ""},
        {"em", 2, ""},

        // Conditional tense reduction
        {"aria", 4, ""},
        {"eria", 4, ""},
        {"iria", 4, ""},
        {"aríamos", 7, ""},
        {"eríamos", 7, ""},
        {"iríamos", 7, ""},
        {"aríeis", 6, ""},
        {"eríeis", 6, ""},
        {"iríeis", 6, ""},

        // Subjunctive reduction
        {"asse", 4, ""},
        {"esse", 4, ""},
        {"isse", 4, ""},
        {"áramos", 6, ""},
        {"éramos", 6, ""},
        {"íramos", 6, ""},
        {"ásseis", 6, ""},
        {"ésseis", 6, ""},
        {"ísseis", 6, ""},

        // Preterite tense reduction
        {"ei", 2, ""},
        {"ou", 2, ""},
        {"aste", 4, ""},
        {"este", 4, ""},
        {"iste", 4, ""},
        {"aram", 4, ""},
        {"eram", 4, ""},
        {"iram", 4, ""},
        {"amos", 4, ""},
        {"emos", 4, ""},
        {"imos", 4, ""},

        // Additional rules for "eu" and other omitted cases
        {"eu", 3, ""},
        {"ava", 3, ""},
        {"ava", 3, ""},
        {"á", 2, ""},
        {"ê", 2, ""},
        {"í", 2, ""}};

    std::vector<StepRule> noun_reduction_rules = {
        {"ezas", 4, "ez"},      {"ezes", 4, "ez"},     {"eza", 3, "ez"},
        {"ez", 2, ""},          {"mentos", 6, "ment"}, {"mento", 5, "ment"},
        {"idades", 7, "idade"}, {"idade", 6, ""},      {"ismos", 5, "ismo"},
        {"ista", 4, ""},        {"istas", 5, ""},      {"ções", 4, "ção"},
        {"ção", 3, ""}};

    std::vector<StepRule> adverb_reduction_rules = {{"mente", 4, ""}};

    std::vector<StepRule> remove_vowel_rules = {
        {"a", 3, ""}, {"e", 3, ""}, {"o", 3, ""}};

    // Conjunto de regras para a aplicação do algoritmo
    ruleMap_ = {
        {"plural_reduction", plural_reduction_rules},
        {"feminine_reduction", feminine_reduction_rules},
        {"augmentative_reduction", augmentative_reduction_rules},
        {"diminutive_reduction", diminutive_reduction_rules},
        {"adverb_reduction", adverb_reduction_rules},
        {"verb_conjugation_reduction", verb_conjugation_reduction_rules},
        {"noun_reduction", noun_reduction_rules},
        {"remove_vowel", remove_vowel_rules}};
}

RSPL::~RSPL() {}

bool RSPL::endsWithA(const std::string& word) {
    char last_char = word.back();
    if (last_char == 'a')
        return true;
    return false;
}

bool RSPL::endsWithS(const std::string& word) {
    char last_char = word.back();
    if (last_char == 's')
        return true;
    return false;
}

std::vector<std::string> RSPL::split(std::string& s) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    std::string delimiter = " ";
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

std::string RSPL::removeAccents(const std::string& input) {
    std::wstring winput =
        std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(input);
    std::wstring woutput;
    woutput.reserve(winput.size());  // Evitar alocações desnecessárias

    // Processar a string como wstring
    for (wchar_t ch : winput) {
        if (accentMap_.count(ch)) {
            woutput.push_back(accentMap_.at(ch));  // Substituir acentuados
        } else {
            woutput.push_back(ch);  // Mantém o caractere não acentuado
        }
    }

    // Converter de volta para std::string
    return std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(woutput);
}

void RSPL::shrinkString(std::string* input) {
    if (!input)
        return;  // Verifica se o ponteiro é válido

    icu::UnicodeString ustr(input->c_str(), "UTF-8");
    ustr.toLower();
    std::string result;
    ustr.toUTF8String(result);
    *input = result;
}

bool RSPL::applyRules(std::string& word, const std::vector<StepRule>& rules) {
    for (const auto& rule : rules) {
        // Verificar se a palavra termina com o sufixo especificado
        if (word.size() >= rule.suffixToRemove.size() &&
            word.compare(word.size() - rule.suffixToRemove.size(),
                         rule.suffixToRemove.size(),
                         rule.suffixToRemove) == 0) {
            // Calcular o tamanho do radical após a remoção do sufixo
            size_t stem_size = word.size() - rule.suffixToRemove.size();
            if (stem_size >= static_cast<size_t>(rule.minimumStemSize)) {
                // Aplicar a regra: remover o sufixo e adicionar o replacement
                word = word.substr(0, stem_size) + rule.replacement;
                return true;  // Regra aplicada
            }
        }
    }
    return false;  // Nenhuma regra foi aplicada
}

void RSPL::run(std::string* sentence) {
    // Separar a sentença em palavras
    this->shrinkString(sentence);
    // std::cout << *sentence << std::endl;
    std::vector<std::string> words = this->split(*sentence);

    for (std::string& word : words) {
        // PLURAL REDUCTION
        bool rule_applied = false;

        if (endsWithS(word)) {
            rule_applied = applyRules(word, ruleMap_["plural_reduction"]);
        }

        // FEMININE REDUCTION
        if (endsWithA(word)) {
            rule_applied = applyRules(word, ruleMap_["feminine_reduction"]);
        }

        // AUGMENTATIVE REDUCTION
        rule_applied = applyRules(word, ruleMap_["augmentative_reduction"]);

        rule_applied = applyRules(word, ruleMap_["diminutive_reduction"]);

        // ADVERB REDUCTION
        rule_applied = applyRules(word, ruleMap_["adverb_reduction"]);

        // NOUN REDUCTION
        rule_applied = applyRules(word, ruleMap_["noun_reduction"]);

        if (!rule_applied) {
            rule_applied =
                applyRules(word, ruleMap_["verb_conjugation_reduction"]);
            if (!rule_applied)
                // remove vogal
                rule_applied = applyRules(word, ruleMap_["remove_vowel"]);
        }

        // Função para remover acentos
        word = removeAccents(word);
        // std::cout << word << std::endl;
    }

    // for (auto& word : words)
    //     std::cout << word << std::endl;

    // Concatena o vetor em uma string
    *sentence = std::accumulate(words.begin(), words.end(), std::string(""),
                                [](const std::string& a, const std::string& b) {
                                    return a + (a.empty() ? "" : " ") + b;
                                });
}

}  // namespace stemmer
