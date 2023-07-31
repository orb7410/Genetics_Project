#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

namespace Genetics {
using GenesMap = std::unordered_map<std::string, std::vector<std::string>>;
using GenesVec = std::vector<std::pair<std::string, std::vector<std::string>>>;

} //Genetics