//Tida Sooreechine
//Assignment 4, 11/21/15

//Goblin.cpp is the Goblin class function implementation file

#include "goblin.hpp"

//Goblin class constructor
Goblin::Goblin(string creatureName, int teamNum) : Creature()
{
	type = "Goblin";
	name = creatureName;
	playerTeam = teamNum;
	attackNumDice = 2; 
	attackNumSides = 6;
	defenseNumDice = 1;
	defenseNumSides = 6;
	armor = 3;
	strength = 8;
	wins = 0;
	totalAttacks = 0;
	injured = false;	//Goblins cannot be injured
	archilles = false;	//Archilles Mode is not activated	
}

int Goblin::attack(Creature *opponent)
{
	int attackPoints = 0;

	//roll the attack dice
	Die *dieA;
	dieA = new Die(attackNumSides);
	for (int i = 0; i < attackNumDice; i++)
		attackPoints += dieA->roll();

	//cut archilles tendon
	if (attackPoints == 12)		//if Goblin rolls a 12
	{
		archilles = true;		//Archilles Mode activated
		cout << " - " << this->name << " Attack = " << attackPoints << endl;
		cout << " * Archilles Mode activated." << endl;
	}	
	else
		cout << " - " << this->name << " Attack = " << attackPoints << endl;	
	
	totalAttacks += attackPoints;

	delete dieA;
	
	return attackPoints;
}

void Goblin::recovery()
{
	int newStrength = 8 - wins;	//Goblin is exhausted from all the previous fights
	if (strength < newStrength)
		strength = newStrength;
}

