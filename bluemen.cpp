//Tida Sooreechine
//Assignment 4, 11/21/15

//bluemen.cpp is the BlueMen class function implementation file

#include "bluemen.hpp"

//BlueMen constructor
BlueMen::BlueMen(string creatureName, int teamNum) : Creature()
{
	type = "Blue Men";
	name = creatureName;
	playerTeam = teamNum;
	attackNumDice = 2;
	attackNumSides = 10;
	defenseNumDice = 3;
	defenseNumSides = 6;
	armor = 3;
	strength = 12;
	wins = 0;
	totalAttacks = 0;
	injured = false;
}

void BlueMen::recovery()
{
	int newStrength = 12 - wins;
	if (strength < newStrength)
		strength = newStrength;
}
