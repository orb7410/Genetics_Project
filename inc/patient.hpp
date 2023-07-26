#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "iupdate_patient_data.hpp"
#include "iget_patient_data.hpp"

enum class Gender {
    NOT_INITIALIZE,
    FEMALE,
    MALE
};

namespace Genetics {

class Patient : public IUpdatePatientData, public IGetPatientData {
public:
    Patient();
    Patient(Patient const& a_other) = delete;
    Patient& operator=(Patient const& a_other) = delete;
    ~Patient() = default;

    std::string getName() const noexcept override;
    std::string getId() const noexcept override;
    std::string getGender() const noexcept override;
    std::string getVarients() const override;

    void updateName(std::string const& a_name) override;
    void updateId(std::string const& a_id) override;
    void updateGender(bool a_gender) override;
    void updateGene(std::string const& a_gene, std::string const& a_varient) override;

private:
    std::string m_name;
    std::string m_id;
    Gender m_gender; 
    std::unordered_map<std::string, std::vector<std::string>> m_cerringGenes;
};

} //Genetics