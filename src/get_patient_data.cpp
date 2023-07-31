#include "iget_patient_data.hpp"
#include "get_patient_data.hpp"
#include "common_types.hpp"

namespace Genetics {

GetPatientData::GetPatientData(IGetPatientData& a_PatientGetter)
: m_getter(a_PatientGetter)
{
}

std::string GetPatientData::getName()
{
    return m_getter.getName();
}

std::string GetPatientData::getId()
{
    return m_getter.getName();
}

bool GetPatientData::getGender()
{
    return m_getter.getGender();   
}

GenesVec GetPatientData::getVariants()
{
    return m_getter.getVariants();      
}



} // namespace Genetics