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

Gender GetPatientData::getGender()
{
    return m_getter.getGender();   
}

GenesVec GetPatientData::getVarients()
{
    return m_getter.getVarients();      
}



} // namespace Genetics