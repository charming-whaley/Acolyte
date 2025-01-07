#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "../Header files/filemanager_tools.h"

void FilemanagerTools::displayLogo() {
    std::cout << std::endl;
    std::cout << "  " << RED << "    ||  " << GREEN << "     |||||  " << YELLOW << "     |||||   " << BLUE << "  |||     " << YELLOW << "  |||     |||" << GREEN << "  |||||||||||" << RED << "  ||||||||" << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "  || |||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << BLUE << "  |||     " << YELLOW << "   |||   ||| " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << BLUE << "  |||     " << YELLOW << "    ||| |||  " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << BLUE << "  |||     " << YELLOW << "     |||||   " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "||||||||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << BLUE << "  |||     " << YELLOW << "     |||     " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "||    ||" << GREEN << "     |||||  " << YELLOW << "     |||||   " << BLUE << "  ||||||||" << YELLOW << "    |||      " << GREEN << "      |||    " << RED << "  ||||||||" << RESET_COLOR << std::endl << std::endl;
}

void FilemanagerTools::displayDocumentation() {
    std::cout << std::endl;
    std::cout << "  " << RED << "    ||  " << GREEN << "     |||||  " << YELLOW << "     |||||   " << BLUE << "  |||     " << YELLOW << "  |||     |||" << GREEN << "  |||||||||||" << RED << "  ||||||||" << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "  || |||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << BLUE << "  |||     " << YELLOW << "   |||   ||| " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << BLUE << "  |||     " << YELLOW << "    ||| |||  " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << BLUE << "  |||     " << YELLOW << "     |||||   " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "||||||||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << BLUE << "  |||     " << YELLOW << "     |||     " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
    std::cout << "  " << RED << "||    ||" << GREEN << "     |||||  " << YELLOW << "     |||||   " << BLUE << "  ||||||||" << YELLOW << "    |||      " << GREEN << "      |||    " << RED << "  ||||||||" << RESET_COLOR << std::endl << std::endl;
    std::cout << "+------------------------------- Welcome to Acolyte! -------------------------------+" << std::endl;
    std::cout << "|                                                                                   |" << std::endl;
    std::cout << "|  Acolyte is the lightweight terminal file manager which gives versatile options   |" << std::endl;
    std::cout << "|  to control, manage, delete, and write files in Finder                            |" << std::endl;
    std::cout << "|                                                                                   |" << std::endl;
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl << std::endl;
    std::cout << "+-- Available commands: ------------------------------------------------------------+" << std::endl;
    std::cout << "| - help                           -- display Acolyte docs                          |" << std::endl;
    std::cout << "| - clear                          -- clear current session                         |" << std::endl;
    std::cout << "| - exit                           -- quit Acolyte                                  |" << std::endl;
    std::cout << "| - path                           -- display current working directory             |" << std::endl;
    std::cout << "| - ls                             -- display files/folders in current directory    |" << std::endl;
    std::cout << "| - version                        -- display current version                       |" << std::endl;
    std::cout << "| - echo [message]                 -- display your message                          |" << std::endl;
    std::cout << "| - go [directory]                 -- go to directory                               |" << std::endl;
    std::cout << "| - make [filename.extension]      -- create file                                   |" << std::endl;
    std::cout << "| - remove [filename]              -- remove file/folder                            |" << std::endl;
    std::cout << "+-----------------------------------------------------------------------------------+" << std::endl;
    std::cout << std::endl;
}

void FilemanagerTools::displayCurrentVersion() {
    std::cout << "alpha v1.0.0" << std::endl;
}

void FilemanagerTools::clearCurrentSession() {
    system("clear");
}

void FilemanagerTools::showCommandsHistory(std::vector<std::string> commands_stack) {
    for (std::string &command: commands_stack)
        std::cout << BLUE << command << "\n";
    std::cout << RESET_COLOR;
}

void FilemanagerTools::echoMessage(const std::string& message) {
    std::cout << message << std::endl;
}