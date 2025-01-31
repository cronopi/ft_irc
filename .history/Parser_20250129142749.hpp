#ifndef PARSER_HPP
# define PARSER_HPP

#include <iostream>
#include "Command.hpp"

void	trimIsSpace(std::string &s);
std::vector<std::string> split(std::string str);
bool findCommand(std::string str);
void handleCommands(std::vector<std::string> command);

#endif
