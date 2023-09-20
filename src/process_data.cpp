#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "process_data.hpp"
#include "common_types.hpp"

namespace genetics {

namespace {

std::string getCurrentDate()
{
    std::time_t now = std::time(nullptr);
    std::tm timeinfo;
    localtime_r(&now, &timeinfo); // Use localtime_r for thread-safe version
    std::stringstream dateStream;
    dateStream << std::put_time(&timeinfo, "%Y-%m-%d");
    return dateStream.str();
}

} // namespace

ProcessData::ProcessData(const DataBase& a_database, IGetPatientData& a_igetPatientData)
: m_igetPatientData(a_igetPatientData)
, m_dataBase(a_database)
{
}

void generateSummaryLetter() const
{
	// get patient information
    std::string patientName = m_igetPatientData.getName();
    std::string patientID = m_igetPatientData.getId();
    std::string patientGender = m_igetPatientData.getGender();
	//using GenesVec = std::vector<std::pair<std::string, std::vector<std::string>>>;
    GenesVec patientGenes = m_igetPatientData.getVariants();;

	// Create the summary letter
	std::stringstream letter;
	letter << "Date: " << getCurrentDate() << "\n";
    letter << "Full Name: " << patientName << "\n";
    letter << "ID: " << patientID << "\n";
    letter << "Greetings,\n";
    letter << "At issue: the results of an extended screening test for carriers of hereditary diseases\n\n";
    letter << "We would like to summarize the results of the extended screening for carriers of hereditary diseases that you performed.\n\n";
    letter << "Below are the findings of your tests:\n";

	for (size_t i = 0; i < patientGenes.size(); ++i) {
		const std::string& geneName = patientGenes[i].first;
    	const std::vector<std::string>& geneVariants = patientGenes[i].second;

		for (const std::string& variant : geneVariants) {
			letter << "   Gene: " << geneName << "\n";
			letter << "   Variant: " << variant << "\n";

			std::string geneInfo = m_dataBase.getGeneDetails(geneName, variant);

			if (!geneInfo.empty()) {
				letter << "   Info: " << geneInfo << "\n";
			} else {
				letter << "   Info: No information available\n";
			}
    	}
    }

    letter << "\nBest regards,\n\n";

	// Generate a unique filename using current date and time
    std::time_t now = std::time(nullptr);
    std::tm timeinfo;
    localtime_r(&now, &timeinfo); // Use localtime_r for thread-safe version
    std::stringstream filenameStream;
    filenameStream << "SummaryLetter_" << std::put_time(&timeinfo, "%Y%m%d_%H%M%S") << ".txt";
    std::string outputFileName = filenameStream.str();

    // Write the letter to the file
    std::ofstream outputFile(outputFileName);
    if (outputFile.is_open()) {
        outputFile << letter.str();
        outputFile.close();
        std::cout << "Summary letter has been written to: " << outputFileName << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing: " << outputFileName << std::endl;
    }
}

} // namespace genetics

