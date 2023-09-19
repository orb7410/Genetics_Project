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

// InfoOfGenes is a unordered map : The key is pair of a gene and its variant and the value is info on this variant.
using GeneAndVariant = std::pair<std::string, std::string>;
using InfoOfGenes = std::unordered_map<GeneAndVariant, std::string>;

class DataBase {
public:
    DataBase();
    explicit DataBase(const std::string& a_fileName);
    DataBase& operator=(DataBase const& a_other) = delete;
    ~DataBase() = default;

	bool isGeneExist(const std::string& a_geneName, const std::string& a_variant) const;
	std::string getGeneDetails(const std::string& a_geneName, const std::string& a_variant) const;
	size_t numOfGenes() const; // for tests

private:
	void loadData(const std::string& a_fileName);
	std::string findGene(const std::string& a_geneName, const std::string& a_variant) const;

private:
	InfoOfGenes m_genes;
};

} // genetics

