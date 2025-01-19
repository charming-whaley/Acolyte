#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Tools {
public:
    static void displayProductLogo() {
        std::cout << std::endl;
        std::cout << "  " << RED << "    ||  " << GREEN << "     |||||  " << YELLOW << "     |||||   " << CYAN << "  |||     " << YELLOW << "  |||     |||" << GREEN << "  |||||||||||" << RED << "  ||||||||" << RESET_COLOR << std::endl;
        std::cout << "  " << RED << "  || |||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << CYAN << "  |||     " << YELLOW << "   |||   ||| " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
        std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << CYAN << "  |||     " << YELLOW << "    ||| |||  " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
        std::cout << "  " << RED << "|||  |||" << GREEN << "  |||       " << YELLOW << "  |||     |||" << CYAN << "  |||     " << YELLOW << "     |||||   " << GREEN << "      |||    " << RED << "  |||||   " << RESET_COLOR << std::endl;
        std::cout << "  " << RED << "||||||||" << GREEN << "   ||||  |||" << YELLOW << "   |||   ||| " << CYAN << "  |||     " << YELLOW << "     |||     " << GREEN << "      |||    " << RED << "  |||     " << RESET_COLOR << std::endl;
        std::cout << "  " << RED << "||    ||" << GREEN << "     |||||  " << YELLOW << "     |||||   " << CYAN << "  ||||||||" << YELLOW << "    |||      " << GREEN << "      |||    " << RED << "  ||||||||" << RESET_COLOR << std::endl << std::endl;
    }
    static void displayProductDocumentation() {
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
    static void displayProductCurrentVersion() {
        std::cout << CYAN << "alpha v1.0.0" << RESET_COLOR << std::endl;
    }
    static void clearCurrentSession() {
        system("clear");
    }
    static void showCommandsHistory(const std::vector<std::string>& commandsHistory) {
        for (const auto& command : commandsHistory)
            std::cout << YELLOW << command << RESET_COLOR << std::endl;
        std::cout << std::endl;
    }
    static void echoMessage(const std::string& message) {
        std::cout << GREEN << message << RESET_COLOR << std::endl;
    }
};
