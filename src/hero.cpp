// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#include <iostream>

#include "hero.h"
#include "strlib.h"

Hero::Hero(const std::string& heroDef) {
	std::vector<std::string> heroAttributes = strSplit(heroDef, '|');
	mName = heroAttributes[0];

	std::vector<std::string> powersList = strSplit(heroAttributes[1], ','); // Split the string into heroAttributes using ',' as the delimite
	for (const std::string& powerName : powersList) {
		Power* power = powerFactory(powerName);
		if (power != nullptr) {
			mPowers.push_back(power);
		}
	}

	mMaxHealth = std::stoi(heroAttributes[2]); // Converts the definition to an integer
	mHealth = mMaxHealth; // Set the health of the hero as max health
}


// Getters
std::string Hero::getName() {
	return mName; // Return the hero's name
}

int Hero::getHealth() {
	return mHealth; // Return the hero's current health
}

Power* Hero::useRandomPower()
{
	if (mPowers.empty()) {
		return nullptr; // Return null if there are no powers
	}

	int randomPowerIndex = rand() % mPowers.size();
	return mPowers[randomPowerIndex];
}

void Hero::takeDamage()
{
	if (mHealth > 0) {
		mHealth--;
	}
}

void Hero::resetHealth()
{
	mHealth = mMaxHealth; // Reset health to max
}

std::ostream& operator<<(std::ostream& out, const Hero& h)
{
	out << h.mName << " has the following powers..." << std::endl;
	for (int i = 0; i < h.mPowers.size(); i++)
	{
		out << "\t" << *(h.mPowers[i]) << std::endl; // Output each power
	}
	return out;
}

Hero::~Hero()
{
	for (Power* power : mPowers) {
		delete power;
	}
}
