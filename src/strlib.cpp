// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#include "strlib.h"

// Piece of code copied from HW3
std::vector<std::string> strSplit(const std::string& str, char splitChar)
{
	std::vector<std::string> result; // Holds the pieces of substrings after splitting
	std::string currentSelection; // Stores each substring as it's being constructed

	for (unsigned int i = 0; i < str.size(); i++) {
		// Checks for the splitting characters
		if (str[i] == splitChar) {
			result.push_back(currentSelection); // If the character is found, add it to result
			currentSelection.clear();
		}
		else {
			currentSelection += str[i]; // If not, append the character to the currentSelection
		}
	}

	// Ensures that the last substring is always added to the result when a splitChar is found
	result.push_back(currentSelection);

	return result;
}