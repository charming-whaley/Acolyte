#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <filesystem>
#include <fstream>

#define RESET_COLOR "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class Controller {
public:
    static void goToSpecifiedDirectory(const std::string& directory) {
        try {
            if (std::filesystem::exists(directory) && std::filesystem::is_directory(directory))
                std::filesystem::current_path(directory);
            else
                std::cout << RED << "Error: " << RESET_COLOR << "path does not exist!" << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when changing directory: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void displayCurrentWorkingDirectory() {
        try {
            std::cout << std::filesystem::current_path() << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when getting directory: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void showPathContent() {
        const std::string PATH = std::filesystem::current_path().string();

        try {
            if (std::filesystem::exists(PATH) && std::filesystem::is_directory(PATH)) {
                std::vector<std::string> directoryContent;
                for (const auto& entry : std::filesystem::directory_iterator(PATH))
                    directoryContent.push_back(entry.path().filename().string());
                if (directoryContent.empty())
                    std::cout << YELLOW << "Directory is empty!" << RESET_COLOR << std::endl;

                const int terminalSize = retrieveTerminalSize();

                size_t maxLength = 0;
                for (const auto& fileNameSize : directoryContent)
                    maxLength = std::max(maxLength, fileNameSize.size());

                int columns = terminalSize / (maxLength + 2);
                if (columns == 0)
                    columns = 1;

                int rows = (directoryContent.size() + columns - 1) / columns;
                for (int row = 0; row < rows; ++row) {
                    for (int column = 0; column < columns; ++column) {
                        const int index = row * (1 + column);
                        if (index < directoryContent.size()) {
                            std::cout << CYAN << directoryContent[index] << RESET_COLOR;
                            const int paddingBetweenNames = maxLength - directoryContent[index].size() + 2;
                            std::cout << std::string(paddingBetweenNames, ' ');
                        }
                    }
                    std::cout << std::endl;
                }
            } else
                std::cout << RED << "Error: " << RESET_COLOR << "could not load files!" << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when loading files: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void createFileInCurrentWorkingDirectory(const std::string& filename) {
        const std::filesystem::path PATH = std::filesystem::current_path() / filename;
        std::ofstream file(PATH);

        try {
            if (file.is_open()) {
                file << "";
                file.close();
                std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
            } else
                std::cout << RED << "Error: " << RESET_COLOR << "not possible to create " << filename << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when creating file: " << RESET_COLOR << error.what() << std::endl;
        }
    }
    static void removeFileFromCurrentWorkingDirectory(const std::string& filename) {
        const std::filesystem::path PATH = std::filesystem::current_path() / filename;

        try {
            if (std::filesystem::exists(PATH) && std::filesystem::is_regular_file(PATH)) {
                std::filesystem::remove(PATH);
                std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
            } else
                std::cout << RED << "Error:" << RESET_COLOR << " unable to remove" << filename << " from " << PATH.string() << std::endl;
        } catch (const std::exception& error) {
            std::cout << RED << "An error occurred when removing file: " << RESET_COLOR << error.what() << std::endl;
        }
    }
private:
    static int retrieveTerminalSize() {
        struct winsize win {};
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
        return win.ws_col;
    }
};
