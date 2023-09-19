#pragma once

#include "iget_patient_data.hpp"
#include "common_types.hpp"

namespace Genetics {

class GetPatientData {
public:
    explicit GetPatientData(IGetPatientData& a_PatientGetter);
    GetPatientData(GetPatientData const& a_other) = delete;
    GetPatientData& operator=(GetPatientData const& a_other) = delete;
    ~GetPatientData() = default;

    std::string getName();
    std::string getId();
    bool getGender();
    GenesVec getVariants();

private:
    IGetPatientData& m_getter;
};

} // namespace Genetics