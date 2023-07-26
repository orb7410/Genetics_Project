#include <string>
#include <vector>

#include "patient.hpp"

namespace Genetics {
namespace {
bool isVarientExist(std::vector<std::string> const& a_geneVarients, std::string const& a_varient) 
{
    for (const auto& var : a_geneVarients) {
        if(var == a_varient) {
            return true;
        }
    }

    return false;
}
} // empty namespace for static functions

Patient::Patient()
: m_name()
, m_id()
, m_gender()
, m_cerringGenes()
{

}

std::string Patient::getName() const noexcept
{
    return m_name.empty() ? "Unknown" : m_name;
}

std::string Patient::getId() const noexcept 
{
    return m_id.empty() ? "Unknown" : m_id;
}

std::string Patient::getGender() const noexcept
{
        switch (m_gender) {
        case Gender::NOT_INITIALIZE: return "unknown";
        case Gender::FEMALE: return "female";
        case Gender::MALE: return "male";
        default: return "unknown";
    }
}

std::string Patient::getVarients() const ///////////////fix
{
    return m_name;
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
    m_gender = (a_gender) ? Gender::MALE : Gender::FEMALE;
}

void Patient::updateGene(std::string const& a_gene, std::string const& a_varient) 
{
    std::unordered_map<std::string, std::vector<std::string>>;

    // check if the gene already exists
    auto it = m_cerringGenes.find(a_gene);
    if (it != m_cerringGenes.end()) {
        // gene already exists, add the varient to its existing vector
        if(!isVarientExist(it->second, a_varient)) {
            it->second.push_back(a_varient);
        }
    } else {
        // new gene, create new varients vector
        std::vector<std::string> varientsVector;
        varientsVector.push_back(a_varient);
        m_cerringGenes.insert({a_varient, varientsVector});
    }
}

} // Genetics