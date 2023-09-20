#include "ui.hpp"

#include <iostream>

namespace Genetics {
namespace {

std::string getInput(const std::string& a_inputReuest) 
{
    std::string input;
    std::cout << a_inputReuest << "\n";
    std::getline(std::cin, input);
    std::cout << "\n";
    return input;
}

}

int menu()
{
    std::cout << "Welcome to Summary Generator!\n";
    std::cout << "0 - Exit\n"; 
    std::cout << "1 - Create a summary\n";
    std::cout << "Please enter a number to proceed: ";
    
    int num;
    std::cin >> num;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    return num;
}

}