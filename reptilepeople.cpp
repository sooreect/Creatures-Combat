//Tida Sooreechine
//Assignment 4 , 11/21/15

//ReptilePeople.cpp is the ReptilePeople class function implementation file

#include "reptilepeople.hpp"

//ReptilePeople Constructor 
ReptilePeople::ReptilePeople(string creatureName, int teamNum) : Creature()
{
	type = "Reptile People";
	name = creatureName;
	playerTeam = teamNum;
	attackNumDice = 3;
	attackNumSides = 6;
	defenseNumDice = 1;
	defenseNumSides = 6;
	armor = 7;
	strength = 18;
	wins = 0;
	totalAttacks = 0;
	injured = false;
}

void ReptilePeople::recovery()
{
	int newStrength = 18 - wins;
	if (strength < newStrength)
		strength = newStrength;
}
