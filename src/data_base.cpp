#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>

#include "data_base.hpp"
#include "string_utils.hpp"
namespace genetics {

namespace {
	GeneAndVariant inputValidator(const std::string& a_geneName, const std::string& a_variant)
	{
    std::string geneName = toLowercase(a_geneName);
    geneName = removeSpaces(geneName);

    std::string variant = toLowercase(a_variant);
    variant = removeSpaces(variant);

    return std::make_pair(geneName, variant);
	}

}

DataBase::DataBase(const std::string& a_fileName)
{
    loadData(a_fileName);
}

void DataBase::loadData(const std::string& a_fileName)
{
    std::ifstream file(a_fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open file " << a_fileName << std::endl;
        return;
    }

    Json::Value json;
    file >> json;

	const auto& genes = json["genes"];

    for (const auto& gene : genes) {
        const std::string geneName = gene["gene"].asString();
        const std::string variant = gene["variant"].asString();
        const std::string info = gene["info"].asString();

        m_genes[std::make_pair(geneName, variant)] = info;
    }
}

std::string DataBase::findGene(const std::string& a_geneName, const std::string& a_variant) const
{
	if (a_geneName.empty() || a_variant.empty()) {
		return "";
	}

	// create a key using the gene name and variant
	std::pair<std::string, std::string> key = inputValidator(a_geneName, a_variant);

	// check if the key exists in the map
	auto it = m_genes.find(key);
	if (it != m_genes.end()) {
		return it->second;
	}

	// return an empty string if the key is not found
	return "";
}

bool DataBase::isGeneExist(const std::string& a_geneName, const std::string& a_variant) const
{
    return !findGene(a_geneName, a_variant).empty();
}

std::string DataBase::getGeneDetails(const std::string& a_geneName, const std::string& a_variant) const
{
    return findGene(a_geneName, a_variant);
}


size_t DataBase::numOfGenes() const
{
	return m_genes.size();
}

} // namespace genetics

