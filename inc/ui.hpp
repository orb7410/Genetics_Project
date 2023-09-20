#pragma once
#include <string>
#include "input_validate.hpp"

namespace Genetics {
    
// Define color escape sequences
const std::string RESET_COLOR = "\033[0m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";
const std::string RED_COLOR = "\033[31m";

int menu();
    

} //Genetics

// std::string getInput(const std::string& a_inputReuest);

// void printSearchResult(const std::string& a_term, const QueryResult& a_vec, uint32_t a_limitResults) ;

// void printCrawlResult(const ISearch& a_searcher);

