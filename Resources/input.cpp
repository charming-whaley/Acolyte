#include <iostream>
#include "../Header files/information.h"

void printDocumentation() {
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
    std::cout << "+---------------------------- Welcome to the Acolyte! -----------------------------+" << std::endl;
    std::cout << "|                                                                                  |" << std::endl;
    std::cout << "|   Acolyte is the lightweight terminal file manager which let versatile options   |" << std::endl;
    std::cout << "|   to control, manage, delete, and write files in Finder                          |" << std::endl;
    std::cout << "|                                                                                  |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------------+" << std::endl << std::endl;
    std::cout << "+-- Available options: ------------------------------------------------------------+" << std::endl;
    std::cout << "| -help                              -- print Acolyte docs                         |" << std::endl;
    std::cout << "| -version                           -- print current version                      |" << std::endl;
    std::cout << "| -goto [directory]                  -- go to directory                            |" << std::endl;
    std::cout << "| -make [filename] { directory }     -- create file in current directory           |" << std::endl;
    std::cout << "| -remove [filename] { directory }   -- remove file from current directory         |" << std::endl;
    std::cout << "| -show { directory }                -- show files in current directory            |" << std::endl;
    std::cout << "| -history                           -- show full commands history                 |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------------+" << std::endl;
    std::cout << std::endl;
}
