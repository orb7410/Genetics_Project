#include "iupdate_patient_data.hpp"
#include "update_patient_data.hpp"

namespace Genetics {

UpdatePatientData::UpdatePatientData(IUpdatePatientData& a_PatientUpdater)
: m_updater(a_PatientUpdater)
{
}

void UpdatePatientData::updateName(std::string const& a_name)
{
    m_updater.updateName(a_name);
}

void UpdatePatientData::updateId(std::string const& a_id)
{
    m_updater.updateId(a_id);
}

void UpdatePatientData::updateGender(bool a_gender)
{
    m_updater.updateGender(a_gender);   
}

void UpdatePatientData::updateGene(std::string const& a_gene, std::string const& a_varient)
{
    m_updater.updateGene(a_gene, a_varient);   
}

} // namespace Genetics