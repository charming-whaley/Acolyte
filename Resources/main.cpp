#include <iostream>
#include <string>
#include <vector>
#include "documentation.cpp"
#include "tools.cpp"
#include "directory_editing.cpp"

int main(int argc, const char * argv[]) {
    const std::string RESET_COLOR = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    
    std::vector<std::string> commandStack;
    
    printAcolyteLogo();
    
    std::string userInput;
    while (userInput != "exit()" and userInput != "exit") {
        std::cout << "> ";
        std::getline(std::cin, userInput);
        commandStack.push_back(userInput);

        if (userInput == "help") {
            printDocumentation();
        } else if (userInput == "clear") {
            clearScreen();
        } else if (userInput == "version") {
            printVersion();
        } else if (userInput == "history") {
            showCommandsHistory(commandStack);
        } else if (userInput == "path")  {
            showCurrentWorkingDirectory();
        } else if (userInput[0] == 'g' && userInput[1] == 'o') {
            std::string path;
            for (int i = 3; userInput[i] != '\0'; ++i)
                path.push_back(userInput[i]);
            goTo(path);
        } else if (userInput == "list") {
            showAllFilesAndFoldersInPath();
        } else {
            if (userInput != "exit()" and userInput != "exit")
                std::cout << RED << "Error" << RESET_COLOR << ": no such command " << userInput << std::endl;
        }


    }
    
    return 0;
}
