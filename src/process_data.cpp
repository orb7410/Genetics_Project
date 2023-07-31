#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <iomanip>

#include "process_data.hpp"

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

void ProcessData::generateSummaryLetter(const DataBase& a_database)
{
    // Get patient information
    std::string patientName ;
    std::string patientID ;
    std::string patientGender ;
    std::vector<std::string> patientGenes = { "Gene1", "Gene2", "Gene3" };
    //GetPatientData patientData(patientName, patientID, patientGender, patientGenes);

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
        const std::string& gene = patientGenes[i];
        std::string geneInfo = a_database.getGeneDetails(gene, /* Add the gene variant here */);
        if (!geneInfo.empty()) {
            letter << i + 1 << ". " << gene << " - " << geneInfo << "\n";
        } else {
            letter << i + 1 << ". " << gene << " - No information available\n";
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

