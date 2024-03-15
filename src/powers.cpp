// Copyright (c) 2023 Nathan Greenfield. All rights reserved

#include "powers.h"

#include <iostream>

POWER_ID Power::getID()
{
	return mPowerID; // Returns the POWER_ID in each derived class constructor
}

// StrengthPower class implementation 
StrengthPower::StrengthPower() {
    mDescription = "Superhuman Strength";
    mPowerID = POWER_STRENGTH; // Assigns to strength power ID
}

// String with the text when using the power
std::string StrengthPower::use() {
    return "SMASH!!";
}

// Outcome of the StrengthPower fight - power vs power
int StrengthPower::fight(Power* other) {
    switch (other->getID()) {
    case POWER_STRENGTH: 
        std::cout << "TIE - It's the immovable object vs. the unstoppable force." << std::endl;
        return 0; // Tie
    case POWER_FLIGHT: 
        std::cout << "FLIGHT WINS - The agility in the air overcomes any strength." << std::endl;
        return -1; // Flight wins
    case POWER_LASER:
        std::cout << "STRENGTH WINS - The laser is SMASHED!" << std::endl;
        return 1; // Strength wins
    case POWER_INTEL:
        std::cout << "INTELLIGENCE WINS - Brains over brawn!" << std::endl;
        return -1; // Intelligence wins
    case POWER_GADGETS:
        std::cout << "STRENGTH WINS - The gadget gets SMASHED." << std::endl;
        return 1; // Strength wins
    case POWER_NATIONAL: 
        std::cout << "STRENGTH WINS - Why bother about patriotic speeches when you can just flex your muscles?" << std::endl;
        return 1; // Strength wins
    default:
        return -1; // Handle errors
    }
}

// FlightPower class implementation 
FlightPower::FlightPower() {
    mDescription = "Ability to fly";
    mPowerID = POWER_FLIGHT;
}

// String with the text when using the power
std::string FlightPower::use() {
    return "flies away, maybe far from this place.";
}

// Outcome of the FlightPower fight - power vs power
int FlightPower::fight(Power* other) {
    switch (other->getID()) {
    case POWER_STRENGTH:
        std::cout << "FLIGHT WINS - The agility in the air overcomes any strength." << std::endl;
        return 1; // Flight wins
    case POWER_FLIGHT:
        std::cout << "TIE - You both fly far away." << std::endl;
        return 0; // Tie
    case POWER_LASER:
        std::cout << "LASER WINS - They have a good sniper shot so flying doesn't help." << std::endl;
        return -1; // Laser wins
    case POWER_INTEL:
        std::cout << "FLIGHT WINS - The thinking takes too long, they're gone by then." << std::endl;
        return 1; // Flight wins
    case POWER_GADGETS:
        std::cout << "GADGETS WINS - Rope snares make it tough to fly away" << std::endl;
        return -1; // Gadgets win
    case POWER_NATIONAL:
        std::cout << "FLIGHT WINS - Flight outshines any national pride." << std::endl;
        return 1; // Flight wins
    default:
        return -1; // Handle errors
    }
}

// LaserPower class implementation 
LaserPower::LaserPower() {
    mDescription = "Can shoot lasers";
    mPowerID = POWER_LASER;
}

// String with the text when using the power
std::string LaserPower::use() {
    return "shoots lasers from their eyes. PEWPEWPEW!";
}

// Outcome of the LaserPower fight - power vs power
int LaserPower::fight(Power* other) {
    switch (other->getID()) {
    case POWER_STRENGTH:
        std::cout << "STRENGTH WINS - The laser is SMASHED!" << std::endl;
        return -1; // Strength wins
    case POWER_FLIGHT:
        std::cout << "LASER WINS - They have a good sniper shot so flying doesn't help." << std::endl;
        return 1; // Laser wins
    case POWER_LASER:
        std::cout << "TIE - Too hot to handle!" << std::endl;
        return 0; // Tie
    case POWER_INTEL:
        std::cout << "LASER WINS - It's hard to think when being fried by a laser." << std::endl;
        return 1; // Laser wins
    case POWER_GADGETS:
        std::cout << "GADGETS WINS - The lasers are blocked by the gadget." << std::endl;
        return -1; // Gadget wins
    case POWER_NATIONAL:
        std::cout << "LASER WINS - The flag gets toasted." << std::endl;
        return 1; // Laser wins
    default:
        return -1; // Handle errors
    }
}

// IntelPower class implementation 
IntelPower::IntelPower() {
    mDescription = "Superhuman Intelligence";
    mPowerID = POWER_INTEL;
}

// String with the text when using the power
std::string IntelPower::use() {
    return "ponders deeply";
}

// Outcome of the IntelPower fight - power vs power
int IntelPower::fight(Power* other) {
    switch (other->getID()) {
    case POWER_STRENGTH:
        std::cout << "INTELLIGENCE WINS - Brains over brawn!" << std::endl;
        return 1; // Intelligence wins
    case POWER_FLIGHT:
        std::cout << "FLIGHT WINS - The thinking takes too long, they're gone by then." << std::endl;
        return -1; // Flight wins
    case POWER_LASER:
        std::cout << "LASER WINS - It's hard to think when being fried by a laser." << std::endl;
        return -1; // Laser wins
    case POWER_INTEL:
        std::cout << "TIE - They couldn't get to an agreement." << std::endl;
        return 0; // Tie
    case POWER_GADGETS:
        std::cout << "INTELLIGENCE WINS - The glitch in the gadget is discovered!" << std::endl;
        return 1; // Intelligence wins
    case POWER_NATIONAL:
        std::cout << "INTELLIGENCE WINS - Brains beat banners!" << std::endl;
        return 1; // Intelligence wins
    default:
        return -1; // Handle errors
    }
}

// GadgetPower class implementation 
GadgetPower::GadgetPower() {
    mDescription = "Uses some crazy gadgets";
    mPowerID = POWER_GADGETS;
}

// String with the text when using the power
std::string GadgetPower::use() {
    return "uses what's (hopefully) the right tool for the job.";
}

// Outcome of the fight - power vs power
int GadgetPower::fight(Power* other) {
    switch (other->getID()) {
    case POWER_STRENGTH:
        std::cout << "STRENGTH WINS - The gadget gets SMASHED." << std::endl;
        return -1; // Strength win
    case POWER_FLIGHT:
        std::cout << "GADGETS WINS - Rope snares make it tough to fly away" << std::endl;
        return 1; // Gadgets win
    case POWER_LASER:
        std::cout << "GADGETS WINS - The lasers are blocked by the gadget." << std::endl;
        return 1; // Gadgets win
    case POWER_INTEL:
        std::cout << "INTELLIGENCE WINS - The glitch in the gadget is discovered!" << std::endl;
        return -1; // Intelligence win
    case POWER_GADGETS:
        std::cout << "TIE - The two gadgets clashed." << std::endl;
        return 0; // Tie
    case POWER_NATIONAL:
        std::cout << "GADGET WINS - It is the representation of technological progress over sheer intelligence." << std::endl;
        return 1; // Gadgets win
    default:
        return -1; // Handle errors
    }
}

// NationalPower class implementation 
NationalPower::NationalPower() {
    mDescription = "A strong belief in their mother country";
    mPowerID = POWER_NATIONAL;
}

// String with the text when using the power
std::string NationalPower::use() {
    return "displays his patriotism.";
}

// Outcome of the fight - power vs power
int NationalPower::fight(Power* other) {
    switch (other->getID()) {
    case POWER_STRENGTH:
        std::cout << "STRENGTH WINS - Why bother about patriotic speeches when you can just flex your muscles?" << std::endl;
        return -1; // Strength wins
    case POWER_FLIGHT:
        std::cout << "FLIGHT WINS - Flight outshines any national pride." << std::endl;
        return -1; // Flight wins
    case POWER_LASER:
        std::cout << "LASER WINS - The flag gets toasted." << std::endl;
        return -1; // Laser wins
    case POWER_INTEL:
        std::cout << "INTELLIGENCE WINS - Brains beat banners!" << std::endl;
        return -1; // Intel wins
    case POWER_GADGETS:
        std::cout << "GADGET WINS - It is the representation of technological over sheer intelligence." << std::endl;
        return -1; // Gadgets win
    case POWER_NATIONAL:
        std::cout << "TIE - It's like two politicians in capes." << std::endl;
        return 0; // Tie
    default:
        return -1; // Handle errors - Should I return something else?
    }
}

Power* powerFactory(const std::string& powerName)
{
    if (powerName == "strength") {
        return new StrengthPower();
    }
    else if (powerName == "flight") {
        return new FlightPower();
    }
    else if (powerName == "laser") {
        return new LaserPower();
    }
    else if (powerName == "intel") {
        return new IntelPower();
    }
    else if (powerName == "gadget") {
        return new GadgetPower();
    }
    else if (powerName == "national") {
        return new NationalPower();
    }
    else {
        return nullptr;
    }
}

// Overload of operator<< to display the power's description
std::ostream& operator<<(std::ostream& out, const Power& p) {
    out << p.mDescription;
    return out;
}