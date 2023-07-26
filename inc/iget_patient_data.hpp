#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace Genetics {

class IGetPatientData {
public:
    virtual ~IGetPatientData() = default;

    virtual std::string getName() const noexcept = 0;
    virtual std::string getId() const noexcept = 0;
    virtual std::string getGender() const noexcept = 0;
    virtual std::string getVarients() const = 0;
};

} // se