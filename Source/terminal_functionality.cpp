#include <iostream>
#include <cstdlib>
#include "../Header files/terminal_functionality.h"

void TerminalFunctionality::openSpecifiedPathOrFileInFinder(const std::string& path) {
    std::string script = "osascript -e 'tell application \"Finder\" to open POSIX file \"" + path + "\"'";

    int result = system(script.c_str());
    if (result == 0)
        std::cout << GREEN << "Success: " << RESET_COLOR << "Finder window has been open!" << std::endl;
    else
        std::cout << RED << "Error: " << RESET_COLOR << "couldn't open Finder window!" << std::endl;
}

void TerminalFunctionality::openSpecifiedFileInVim(const std::string& filename) {
    std::string script = "vim " + filename;

    int result = system(script.c_str());
    if (result == 0)
        std::cout << GREEN << "Success: " << RESET_COLOR << "file was open in Vim!" << std::endl;
    else
        std::cout << RED << "Error: " << RESET_COLOR << "couldn't open file in Vim!" << std::endl;
}

void TerminalFunctionality::openSpecifiedFileInPython(const std::string& filename) {
    std::string script = "python3 " + filename;

    int result = system(script.c_str());
    if (result == 0)
        std::cout << GREEN << "Success: " << RESET_COLOR << "file was open in Python!" << std::endl;
    else
        std::cout << RED << "Error: " << RESET_COLOR << "couldn't open file in Python!" << std::endl;
}

void TerminalFunctionality::retrieveRootInTerminal(const std::string& commands) {
    std::string script = "sudo" + commands;
    int result = system(script.c_str());
}