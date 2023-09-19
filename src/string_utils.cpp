#include <algorithm>

#include "string_utils.hpp"
namespace genetics {

std::string toLowercase(const std::string& a_string)
{
    std::string result(a_string);
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}

std::string removeSpaces(const std::string& a_string)
{
    std::string result;
    for (char c : a_string) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            result += c;
        }
    }
    return result;
}

} // namespace se

