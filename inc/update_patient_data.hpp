
#pragma once

#include "iupdate_patient_data.hpp"

namespace Genetics {

class UpdatePatientData {
public:
    explicit UpdatePatientData(IUpdatePatientData& a_PatientUpdater);
    UpdatePatientData(UpdatePatientData const& a_other) = delete;
    UpdatePatientData& operator=(UpdatePatientData const& a_other) = delete;
    ~UpdatePatientData() = default;

    void updateName(std::string const& a_name);
    void updateId(std::string const& a_id);
    void updateGender(bool a_gender);
    void updateGene(std::string const& a_gene, std::string const& a_varient);

private:
    IUpdatePatientData& m_updater;
};

} // namespace Genetics