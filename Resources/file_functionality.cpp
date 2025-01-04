#include <iostream>
#include <cstdlib>
#include <string>
#include "../Header files/file_functionality.h"

void openSpecifiedDirectoryInFinder(std::string path) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";

    std::string script = "osascript -e 'tell application \"Finder\" to open POSIX file \"" + path + "\"'";

    int result = system(script.c_str());
    if (result == 0)
        std::cout << GREEN << "Success: " << RESET_COLOR << "Finder window has been open!" << std::endl;
    else
        std::cout << RED << "Error: " << RESET_COLOR << "couldn't open Finder window!" << std::endl;
}

void openSpecifiedFileInVim(std::string path) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    
    std::string script = "vim " + path;

    int result = system(script.c_str());
    if (result == 0)
        std::cout << GREEN << "Success: " << RESET_COLOR << "file was open in Vim!" << std::endl;
    else
        std::cout << RED << "Error: " << RESET_COLOR << "couldn't open file in Vim!" << std::endl;
}

void openSpecifiedFileInPython(std::string path) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";

    std::string script = "python3 " + path;

    int result = system(script.c_str());
    if (result == 0)
        std::cout << GREEN << "Success: " << RESET_COLOR << "file was open in Python!" << std::endl;
    else
        std::cout << RED << "Error: " << RESET_COLOR << "couldn't open file in Python!" << std::endl;
}
