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
    
    displayAcolyteLogo();
    
    std::string userInput;
    while (userInput != "exit()" and userInput != "exit") {
        std::cout << "> ";
        std::getline(std::cin, userInput);
        commandStack.push_back(userInput);

        if (userInput == "help")
            displayAcolyteDocumentation();
        else if (userInput == "clear")
            clearCurrentSession();
        else if (userInput == "version")
            displayCurrentAcolyteVersion();
        else if (userInput == "history")
            showCommandsHistory(commandStack);
        else if (userInput == "path")
            showCurrentWorkingDirectory();
        else if (userInput == "list")
            showAllFilesAndFoldersInPath();
        else if (userInput[0] == 'g' && userInput[1] == 'o') {
            std::string path;
            for (int i = 3; userInput[i] != '\0'; ++i)
                path.push_back(userInput[i]);
            goToSpecifiedPath(path);
        } else if (userInput[0] == 'm' && userInput[1] == 'a' && userInput[2] == 'k' && userInput[3] == 'e') {
            std::string filename;
            for (int i = 5; userInput[i] != '\0'; ++i)
                filename.push_back(userInput[i]);
            makeFileInTheCurrentDirectory(filename);
        } else if (userInput[0] == 'r' && userInput[1] == 'e' && userInput[2] == 'm' && userInput[3] == 'o' && userInput[4] == 'v' && userInput[5] == 'e') {
            std::string filename;
            for (int i = 7; userInput[i] != '\0'; ++i)
                filename.push_back(userInput[i]);
            removeFileFromCurrentDirectory(filename);
        } else
            if (userInput != "exit()" and userInput != "exit")
                std::cout << RED << "Error" << RESET_COLOR << ": no such command " << userInput << std::endl;
    }
    
    return 0;
}
