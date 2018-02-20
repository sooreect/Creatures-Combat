//Tida Sooreechine
//Assignment 4, 11/21/15

//theshadow.cpp is the TheShadow class function implementation file

#include "theshadow.hpp"

//TheShadow Constructor
TheShadow::TheShadow(string creatureName, int teamNum) : Creature()
{
	type = "The Shadow";
	name = creatureName;
	playerTeam = teamNum;
	attackNumDice = 2;
	attackNumSides = 10;
	defenseNumDice = 1;
	defenseNumSides = 6;
	strength = 12;
	wins = 0;
	totalAttacks = 0;
	injured = false;
}

//Overrides Creature class' defense function
void TheShadow::defense(int attackReceived) 
{
	//initialize accumulator variables
	int defensePoints = 0;
	int damage = 0;

	//use rand() function to determine if The Shadow is present 
	//50% chance of receiving the damage
	int chance = rand() % 2 + 1;
	if (chance == 1)
	{
		Die *dieD;
		dieD = new Die(defenseNumSides);
	
		for (int i = 0; i < defenseNumDice; i++)
			defensePoints += dieD->roll();

		damage = attackReceived - defensePoints; //The Shadow does not have armor points
	
		if (damage > 0)
			strength -= damage;
	
		if (strength < 0)
			strength = 0; 

		cout << " - " << this->name << " Defense = " << defensePoints << endl;
		cout << " - " << this->name << " Damage = " << damage << endl;
		cout << " - " << this->name << " Strength = " << strength << endl;		
	
		delete dieD;
	}
	else
	{
		cout << " * No damage. " << this->name << " was someplace else." << endl;
	}	
}

void TheShadow::recovery()
{
	int newStrength = 12 - wins;
	if (strength < newStrength)
		strength = newStrength;
}
