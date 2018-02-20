//Tida Sooreechine
//Assignment 4, 11/21/15

//barbarian.cpp is the Barbarian class function implementation file

#include "barbarian.hpp"

//Barbarian Constructor
Barbarian::Barbarian(string creatureName, int teamNum) : Creature()
{
	type = "Barbarian";
	name = creatureName;
	playerTeam = teamNum;
	attackNumDice = 2;
	attackNumSides = 6;
	defenseNumDice = 2;
	defenseNumSides = 6;
	armor = 0;
	strength = 12;
	wins = 0;
	totalAttacks = 0;
	injured = false;
}

void Barbarian::recovery()
{
	int newStrength = 12 - wins;
	if (strength < newStrength)
		strength = newStrength;
}
