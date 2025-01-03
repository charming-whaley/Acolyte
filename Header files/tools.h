#ifndef tools_h
#define tools_h

void printAcolyteLogo();
void printVersion();
void clearScreen();
void showCommandsHistory(std::vector<std::string> commandsStack);
std::string showCurrentOrSpecifiedDirectory();

#endif
