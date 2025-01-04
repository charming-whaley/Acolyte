#include <iostream>
#include "../Header files/documentation.h"

void displayAcolyteDocumentation() {
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
    std::cout << "+------------------------------- Welcome to Acolyte! ------------------------------+" << std::endl;
    std::cout << "|                                                                                  |" << std::endl;
    std::cout << "|   Acolyte is the lightweight terminal file manager which gives versatile options |" << std::endl;
    std::cout << "|   to control, manage, delete, and write files in Finder                          |" << std::endl;
    std::cout << "|                                                                                  |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------------+" << std::endl << std::endl;
    std::cout << "+-- Available commands: -----------------------------------------------------------+" << std::endl;
    std::cout << "| - help                           -- display Acolyte docs                         |" << std::endl;
    std::cout << "| - clear                          -- clear current session                        |" << std::endl;
    std::cout << "| - exit                           -- quit Acolyte                                 |" << std::endl;
    std::cout << "| - path                           -- display current working directory            |" << std::endl;
    std::cout << "| - list                           -- display files/folders in current directory   |" << std::endl;
    std::cout << "| - version                        -- display current version                      |" << std::endl;
    std::cout << "| - echo [message]                 -- display your message                         |" << std::endl;
    std::cout << "| - go [directory]                 -- go to directory                              |" << std::endl;
    std::cout << "| - make [filename.extension]      -- create file                                  |" << std::endl;
    std::cout << "| - remove [filename]              -- remove file/folder                           |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------------+" << std::endl;
    std::cout << std::endl;
}
