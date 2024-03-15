// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#pragma once

#include <string>
#include <vector>
#include <ostream>

#include "powers.h"

class Hero
{
public:
    // Name:
    //        Hero parameterized constructor
    // Input:
    //        1. A string (passed as constant reference) with 3 fields.
    //              a. The hero name followed by a vertical bar "|"
    //              b. A list of comma separated power names
    //              c. The maximum health for that hero
    // Output:
    //        None (it's a constructor)
    // Side effects:
    //        Dynamically creates new powers and puts their memory addresses in the Power vector
    // Summary:
    //        Calls the hero constructor to make all the heros
	Hero(const std::string& heroDef);

    // Name:
    //        getName
    // Input:
    //        None
    // Output:
    //        A std::string with the hero's name
    // Side effects:
    //        None
    // Summary:
    //        Name getter
	std::string getName();

	// Name:
    //        getHealth
    // Input:
    //        None
    // Output:
    //        An integer with the hero's current health
    // Side effects:
    //        None
    // Summary:
    //        Current health getter
	int getHealth();


	// Name:
	//        useRandomPower
	// Input:
	//        None
	// Output:
	//        A pointer to a random Power as determined by std::rand
	// Side effects:
	//        Displays that power's flavor text
	// Summary:
	//        Name getter
	Power* useRandomPower();

	// Name:
    //        takeDamage
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        Decrements hero's mHealth by 1
    // Summary:
    //        Hero takes 1 point of damage when called
	void takeDamage();

	// Name:
	//        resetHealth
	// Input:
	//        None
	// Output:
	//        None
	// Side effects:
	//        Set's hero's mHealth to mMaxHealth
	// Summary:
	//        Resets hero's health for the next fight
	void resetHealth();

	// Name:
	//        FRIEND: operator<<
	// Input:
	//		  1. Output stream to display to (passed by reference)
	//		  2. Hero to display (passed as constant reference)
	// Output:
	//        Original output stream to allow chaining
	// Side effects:
	//        Modifies inputted output stream to show hero
	// Summary:
	//        Displays hero information to output stream
	friend std::ostream& operator<<(std::ostream& out, const Hero& h);

	// Name:
	//        Destructor
	// Input:
	//        None
	// Output:
	//        None
	// Side effects:
	//        Clears heap data
	// Summary:
	//        Destructor
	~Hero();

private:
	// Max health
	int mMaxHealth;
	// Current health
	int mHealth;
	// Name of hero
	std::string mName;
	// Array of pointers to powers
    std::vector<Power*> mPowers;
};
