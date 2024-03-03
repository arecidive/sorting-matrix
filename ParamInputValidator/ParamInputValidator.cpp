#include <limits>
#include <iostream>


int getInput(const std::string &paramName) {
    int num;
    while (true) {
        std::cout << "Enter the parameter value '" << paramName << "':";
        std::cin >> num;
        if (std::cin.peek() == '\n' && std::cin.good()) {
            break;
        } else {
            std::cout << "Error: The entered value does not meet the conditions!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return num;
}

int getPositiveNumber(const std::string &paramName) {
    int number;
    while (true) {
        number = getInput(paramName);
        if (number > 1 & number < 31) {
            return number;
        }
        std::cout << "Error: The entered value must be greater than 1 and less than 31!" << std::endl;
    }
}