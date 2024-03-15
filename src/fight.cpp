// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#include <iostream>
#include <ctime>
#include <fstream>

#include "fight.h"
#include "strlib.h"
#include "powers.h"
#include "hero.h"

bool loadHeroes(const std::string& fileName, std::vector<Hero*>& heroVector)
{
	std::ifstream fileInput(fileName); // Open file for reading
	if (!fileInput.is_open()) {
		return false;
	}

	// Delete existing heroes and clean the vector
	for (Hero* hero : heroVector) {
		delete hero;
	}
	heroVector.clear();

	std::string line;
	while (std::getline(fileInput, line)) {
		if (!line.empty()) {
			Hero* newHero = new Hero(line); // Create a new Hero object
			heroVector.push_back(newHero); // Add the new Hero to the vector
		}
	}

	fileInput.close(); // Close the file after reading
	return true;
}

Hero* selectHero(std::vector<Hero*>& heroVector, const std::string& prompt, std::ostream& out, std::istream& in)
{
	int heroIndex = -1; // Initialize index
	std::string option;

	while (heroIndex < 0 && heroIndex >= heroVector.size()) {
		out << prompt;
		std::getline(in, option);
		heroIndex = std::stoi(option);
		}
	return heroVector[heroIndex];
}

// Function that simulates a battle between heroA and heroB.
void heroCombat(Hero* heroA, Hero* heroB, std::ostream& output)
{
	// Reset heroes health
	heroA->resetHealth();
	heroB->resetHealth();

	// Continue the fight until one or both heroes run out of health
	while (heroA->getHealth() > 0 && heroB->getHealth() > 0) {

		// Display the initial health of both heroes
		output << "---------------------------------------" << std::endl;
		output << heroA->getName() << " has " << heroA->getHealth() << " health " << std::endl;
		output << heroB->getName() << " has " << heroB->getHealth() << " health " << std::endl;

		Power* powerA = heroA->useRandomPower();
		Power* powerB = heroB->useRandomPower();

		// Display the powers each hero decides to use
		output << heroA->getName() << " " << powerA->use() << std::endl;
		output << heroB->getName() << " " << powerB->use() << std::endl;

		// Determine the outcome of the fight between the two powers
		int result = powerA->fight(powerB);
		if (result == 1) {
			// If heroA wins, heroB takes damage
			heroB->takeDamage();
		}
		else if (result == -1) {
			// If heroB wins, heroA takes damage
			heroA->takeDamage();
		}
		else if (result == 0) {
			heroA->takeDamage();
			heroB->takeDamage();
		}
	}

	// Condition to check which hero still has health, and then display the winner
	output << "---------------------------------------" << std::endl;
	if (heroA->getHealth() > 0) {
		output << heroA->getName() << " WINS!!!" << std::endl;
	}
	else if (heroB->getHealth() > 0) {
		output << heroB->getName() << " WINS!!!" << std::endl;
	}
}

int fight(const std::string& inputFileName, const std::string& outputFileName, unsigned seed)
{
	// Open input and output files
	std::ifstream inputFile(inputFileName);
	if (!inputFile.is_open()) {
		return 1; // Return error if opening fails
	}

	std::ofstream outputFile(outputFileName);
	if (!outputFile.is_open()) {
		inputFile.close(); // Close input file if output file opening fails
		return 1; // Return error
	}

	int functionResult = fight(inputFile, outputFile, seed); // Call the main fight function with the files 

	// Close the files
	inputFile.close();
	outputFile.close();

	return functionResult; // Return the result from the main fight function
}

int fight(std::istream& input, std::ostream& output, unsigned seed)
{
	std::srand(seed); // Seed the random number generator

	output << "Seed: " << seed << std::endl; // Display the seed value
	output << std::endl;

	std::vector<Hero*> heroes; // Vector to store Hero objects
	std::string userInput; // Variable to store user input

	while (true) {
		// Print menu options
		output << "Choose an option:" << std::endl;
		output << "1. Load Heroes" << std::endl;
		output << "2. Print Hero Roster" << std::endl;
		output << "3. Hero Fight!" << std::endl;
		output << "4. Quit" << std::endl;
		output << "> ";
		std::getline(input, userInput);
		output << std::endl;

		if (userInput == "1") {
			output << "Enter the file to load: ";
			std::string fileName;
			std::getline(input, fileName);
			if (!loadHeroes(fileName, heroes)) {
				output << "Failed to load heroes from file." << std::endl;
			}
			output << std::endl;
		}
		else if (userInput == "2") {
			if (heroes.empty()) {
				output << "You need to load heroes first!" << std::endl;
			}
			else {
				output << "The following " << heroes.size() << " heroes are loaded..." << std::endl;
				output << "---------------------------------------" << std::endl;
				for (int i = 0; i < heroes.size(); ++i) {
					output << *(heroes[i]); // Dereference the hero pointer
					output << "---------------------------------------" << std::endl;
				}
			}
			output << std::endl;
		}
		else if (userInput == "3") {
			// List all the loaded heroes with indices
			for (int i = 0; i < heroes.size(); ++i) {
				output << i << ": " << heroes[i]->getName() << std::endl;
			}

			Hero* firstHero = selectHero(heroes, "Select your first hero: ", output, input); // User input to select first hero
			Hero* secondHero = selectHero(heroes, "Select your second hero: ", output, input); // User input to select second hero

			// Check if the same hero is selected twice
			if (firstHero == secondHero) {
				output << "Please choose different heroes." << std::endl;
			}
			else {
				heroCombat(firstHero, secondHero, output);
			}
			output << std::endl;
		}
		else if (userInput == "4") {
			output << "Goodbye" << std::endl;
			break;
		}
		else {
			output << std::endl;
		}
	}

	// Delete Hero object and clean the vector
	for (Hero* hero : heroes) {
		delete hero;
	}
	heroes.clear();

	return 0;
}