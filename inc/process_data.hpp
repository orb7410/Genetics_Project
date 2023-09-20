#include <string>
#include <sstream>

#include "data_base.hpp"
#include "get_patient_data.hpp"
#include "iget_patient_data.hpp"

namespace genetics {

class ProcessData {
public:
 	explicit ProcessData(const DataBase& a_database, IGetPatientData& a_igetPatientData);
    ProcessData(const ProcessData& a_other) = delete;
    ProcessData& operator=(const ProcessData& a_other) = delete;
    ~ProcessData() = default;

	void generateSummaryLetter() const;

private:
    IGetPatientData m_igetPatientData;
    DataBase m_dataBase;


};

} // namespace genetics
