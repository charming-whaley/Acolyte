#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/ioctl.h>
#include <unistd.h>
#include <filesystem>
#include <fstream>
#include "../Header files/filesystem_manager.h"

void FilesystemManager::goToSpecifiedPath(const std::string& path) {
    try {
        if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
            std::filesystem::current_path(path);
        else
            std::cout << RED << "Error: " << RESET_COLOR << "path does not exist!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "An error occured when changing directory: " << RESET_COLOR << e.what() << std::endl;
    }
}

void FilesystemManager::showCurrentWorkingDirectory() {
    try {
        std::cout << std::filesystem::current_path() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "An error occured when getting directory: " << RESET_COLOR << e.what() << std::endl;
    }
}

// This is what I am developing

int FilesystemManager::retrieveTerminalSize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void FilesystemManager::showPathContent() {
    const std::string PATH = std::filesystem::current_path().string();

    try {
        if (std::filesystem::exists(PATH) && std::filesystem::is_directory(PATH)) {
            std::vector<std::string> directoryContent;
            for (const auto& entry: std::filesystem::directory_iterator(PATH))
                directoryContent.push_back(entry.path().filename().string());
            if (directoryContent.empty()) return;
            
            int terminalSize = retrieveTerminalSize();
            size_t maxLength = 0;
            for (const auto& filenameSize: directoryContent)
                maxLength = std::max(maxLength, filenameSize.size());

            int columns = terminalSize / (maxLength + 2);
            if (columns == 0) columns = 1;

            int rows = (directoryContent.size() + columns - 1) / columns;
            for (int row = 0; row < rows; ++row) {
                for (int column = 0; column < columns; ++column) {
                    int index = row * (1 + column);
                    if (index < directoryContent.size()) {
                        std::cout << BLUE << directoryContent[index] << RESET_COLOR;
                        int paddingBetweenNames = maxLength - directoryContent[index].size() + 2;
                        std::cout << std::string(paddingBetweenNames, ' ');
                    }
                }
                std::cout << std::endl;
            }
        } else
            std::cout << RED << "Error: " << RESET_COLOR << "not possible to show files!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "An error occured when loading files: " << RESET_COLOR << e.what() << std::endl;
    }
}

// This is what I am developing

void FilesystemManager::makeFileInCurrentWorkingDirectory(const std::string& filename) {
    const std::filesystem::path PATH = std::filesystem::current_path() / filename;
    std::ofstream file(PATH);

    try {
        if (file.is_open()) {
            file << "";
            file.close();
            std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
        } else 
            std::cout << RED << "Error: " << RESET_COLOR << "not possible to create " << filename << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "An error occured when creating file: " << RESET_COLOR << e.what() << std::endl;
    }
}

void FilesystemManager::removeFileFromCurrentWorkingDirectory(const std::string& filename) {
    const std::filesystem::path PATH = std::filesystem::current_path() / filename;

    try {
        if (std::filesystem::exists(PATH) && std::filesystem::is_regular_file(PATH)) {
            std::filesystem::remove(PATH);
            std::cout << GREEN << "Success!" << RESET_COLOR << std::endl;
        } else 
            std::cout << RED << "Error: " << RESET_COLOR << " unable to remove" << filename << " from " << PATH.string() << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "An error occured when deleting file: " << RESET_COLOR << e.what() << std::endl;
    }
}