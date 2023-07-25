#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <map>

namespace Genetics {

class IUpdatePatientData {
public:
    virtual ~IUpdatePatientData() = default;

    virtual void updateName(std::string a_name) noexcept = 0;
    virtual void updateId(std::string a_id) noexcept = 0;
    virtual void updateGender(bool a_gender) noexcept = 0;
    virtual void updateGene(std::string a_gene, std::string a_varient) = 0;
};

} // se