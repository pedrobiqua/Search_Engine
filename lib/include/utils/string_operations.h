#include <unicode/locid.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <codecvt>
#include <locale>
#include <string>
#include <unordered_map>
#include <vector>

namespace utils {

/**
 * @define DELIMITER
 * @brief Delimiter used to split strings.
 */
constexpr std::string DELIMITER = " ";

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
// Funções para manipular string

/**
 * @brief Removes unwanted characters from a string, such as extra spaces.
 * @param input String to process.
 */
void shrink_string(std::string* input);

/**
 * @brief Splits a string based on a delimiter.
 * @param s String to split.
 * @param delimiter Delimiter to split the string.
 * @return Vector of strings resulting from the split.
 */
std::vector<std::string> split(std::string& s, const std::string& delimiter);

/**
 * @brief Removes accents from a string.
 * @param input The input string.
 * @return The string without accents.
 */
std::string removeAccents(const std::string& input);

}  // namespace utils
