#pragma once
#include <string>
#include <vector>

namespace genetics {

class PatientGene{
public:
    PatientGene() = delete;
    explicit PatientGene(std::string const& a_name, std::vector<std::string> const& a_varients);
    PatientGene(PatientGene const& a_other) = delete;
    PatientGene& operator=(PatientGene const& a_other) = delete;
    ~PatientGene() = default;

    std::string getName() const noexcept;
    std::string getvarients() const noexcept;

private:
    std::string m_name;
    std::vector<std::string> m_varient;
};

} //se