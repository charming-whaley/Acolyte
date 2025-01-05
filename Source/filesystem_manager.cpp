#include <iostream>
#include <string>
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

void FilesystemManager::showPathContent() {
    const std::string PATH = std::filesystem::current_path().string();

    try {
        if (std::filesystem::exists(PATH) && std::filesystem::is_directory(PATH))
            for (const auto& entry: std::filesystem::directory_iterator(PATH))
                std::cout << BLUE << entry.path().filename().string() << RESET_COLOR << std::endl;
        else
            std::cout << RED << "Error: " << RESET_COLOR << "not possible to show files!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "An error occured when loading files: " << RESET_COLOR << e.what() << std::endl;
    }
}

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