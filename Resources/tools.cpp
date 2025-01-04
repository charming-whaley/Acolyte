#include <filesystem>
#include <iostream>
#include <cstdlib>
#include <string>
#include "../Header files/tools.h"

void clearCurrentSession() {
    system("clear");
}

void displayCurrentAcolyteVersion() {
    std::cout << "alpha v1.0.0" << std::endl;
}

void showCommandsHistory(std::vector<std::string> commandsStack) {
    for (std::string &command: commandsStack)
        std::cout << command << "\n";
}

void displayAcolyteLogo() {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    
    std::cout << std::endl;
    std::cout << "  " << RED << "    ||  " << GREEN << "     |||||  " << YELLOW << "     |||||   " << BLUE << "  |||     " << YELLOW << "  |||     |||" << GREEN << "  |||||||||||" << RED << "  ||||||||" << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "  || |||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << BLUE << "  |||     " << YELLOW << "   |||   ||| " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << BLUE << "  |||     " << YELLOW << "    ||| |||  " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << BLUE << "  |||     " << YELLOW << "     |||||   " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "||||||||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << BLUE << "  |||     " << YELLOW << "     |||     " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "||    ||" << GREEN << "     |||||  " << YELLOW << "     |||||   " << BLUE << "  ||||||||" << YELLOW << "    |||      " << GREEN << "      |||    " << RED << "  ||||||||" << RESET_COLOR << std::endl << std::endl;
}
