#pragma once

#include <string>
#include <unordered_map>

// Custom hash function specialization for std::pair<std::string, std::string>
namespace std {
	template <>
	struct hash<std::pair<std::string, std::string>> {
		size_t operator()(const std::pair<std::string, std::string>& p) const {
			// You can use a simple hash combining the hash of both strings
			return std::hash<std::string>{}(p.first) ^ std::hash<std::string>{}(p.second);
		}
	};
}

namespace genetics {

// GeneMap is a unordered map : The key is pair of a gene and its mutation and the value is info on this mutation.
using GenesMap = std::unordered_map<std::pair<std::string, std::string>, std::string>;

class DataBase {
public:
    DataBase();
    explicit DataBase(const std::string& a_fileName);
    DataBase& operator=(DataBase const& a_other) = delete;
    ~DataBase() = default;

	bool isGeneExist(const std::string& a_geneName, const std::string& a_variant) const;  // i dont think we need it
	std::string getGeneDetail(const std::string& a_geneName, const std::string& a_variant) const;

private:
	void loadData(const std::string& a_fileName);

private:
	std::string m_fileName;
	GenesMap m_genes;
};

} // genetics
