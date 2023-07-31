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
    Gender getGender();
    GenesVec getVarients();

private:
    IGetPatientData& m_getter;
};

} // namespace Genetics