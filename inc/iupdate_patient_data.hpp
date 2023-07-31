#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <map>

#include "common_types.hpp"

namespace Genetics
{

    class IUpdatePatientData
    {
    public:
        virtual ~IUpdatePatientData() = default;

        virtual void updateName(std::string const &a_name) = 0;
        virtual void updateId(std::string const &a_id) = 0;
        virtual void updateGender(bool a_gender) = 0;
        virtual void updateGene(std::string const &a_gene, std::string const &a_varient) = 0;
    };

} // se