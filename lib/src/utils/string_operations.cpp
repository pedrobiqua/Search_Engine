#include "utils/string_operations.h"

namespace utils {

void shrink_string(std::string* input) {
    if (!input)
        return;  // Verifica se o ponteiro é válido

    icu::UnicodeString ustr(input->c_str(), "UTF-8");
    ustr.toLower();
    std::string result;
    ustr.toUTF8String(result);
    *input = result;
}

std::vector<std::string> split(std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
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

std::string removeAccents(const std::string& input) {
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

}  // namespace utils
