#pragma once
#include <string>
#include <vector>
#include <cstdint>

#include "common_types.hpp"

namespace Genetics {

class IGetPatientData {
public:
    virtual ~IGetPatientData() = default;

    virtual std::string getName() const noexcept = 0;
    virtual std::string getId() const noexcept = 0;
    virtual Gender getGender() const noexcept = 0;
    virtual GenesVec getVarients() const = 0;
};

} // se