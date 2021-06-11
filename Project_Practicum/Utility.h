#pragma once
#include <string>

std::string toLower(std::string command)
{
	for (char& c : command) {
		if (c >= 'A' && c <= 'Z') {
			c = c + 32;
		}
	}
	return command;
}