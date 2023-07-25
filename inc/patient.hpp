#pragma once
#include <string>
#include <unordered_map>

#include "iupdate_patient_data.hpp"
#include "iget_patient_data.hpp"

enum class Gender {
    male,
    female
};

namespace Genetics {

class Patient : public IUpdatePatientData, public IGetPatientData {
public:
    Patient() = delete;
    explicit Patient(std::string const& a_name, std::string const& a_id, bool a_gender, std::vector<std::string> const& a_varients);
    Patient(Patient const& a_other) = delete;
    Patient& operator=(Patient const& a_other) = delete;
    ~Patient() = default;

    std::string getName() const noexcept override;
    std::string getId() const noexcept override;
    Gender getGender() const noexcept override;
    std::string getVarients() const override;

    void updateName(std::string a_name) noexcept override;
    void updateId(std::string a_id) noexcept override;
    void updateGender(bool a_gender) noexcept override;
    void updateGene(std::string a_gene, std::string a_varient) override;

private:
    std::string m_name;
    std::string m_id;
    Gender m_gender; 
    std::unordered_map<std::string, std::vector<std::string>> m_cerringGenes;
};

} //Genetics