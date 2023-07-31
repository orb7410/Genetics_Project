#include <string>
#include <vector>

#include "patient.hpp"

namespace Genetics {
namespace {
bool isvariantExist(std::vector<std::string> const& a_genevariants, std::string const& a_variant) 
{
    for (const auto& var : a_genevariants) {
        if(var == a_variant) {
            return true;
        }
    }

    return false;
}
} // empty namespace for static functions

Patient::Patient()
: m_name()
, m_id()
, m_gender(true)
, m_cerringGenes()
{

}

std::string Patient::getName() const noexcept
{
    return m_name;
}

std::string Patient::getId() const noexcept 
{
    return m_id;
}

bool Patient::getGender() const noexcept
{
    return m_gender;
}

GenesVec Patient::getVariants() const 
{
    GenesVec genes;
    for (auto const& gene : m_cerringGenes) {
        genes.push_back(std::make_pair(gene.first, gene.second));
    }
    return genes;
}

void Patient::updateName(std::string const& a_name)
{
    m_name = a_name;
}

void Patient::updateId(std::string const& a_id)
{
    m_id = a_id;
}

void Patient::updateGender(bool a_gender) 
{
    m_gender = a_gender;
}

void Patient::updateGene(std::string const& a_gene, std::string const& a_variant) 
{
    if(a_gene.size() > 0 && a_variant.size() > 0) {
        // check if the gene already exists
        auto it = m_cerringGenes.find(a_gene);
        if (it != m_cerringGenes.end()) {
            // gene already exists, add the variant to its existing vector
            if(!isvariantExist(it->second, a_variant)) {
                it->second.push_back(a_variant);
            }
        } else {
            // new gene, create new variants vector
            std::vector<std::string> variantsVector;
            variantsVector.push_back(a_variant);
            m_cerringGenes.insert({a_gene, variantsVector});
        }   
    }
}

} // Genetics