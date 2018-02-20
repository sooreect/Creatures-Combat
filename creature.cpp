//Tida Sooreechine
//Assignment 4, 11/21/15

//creature.cpp is the Creature class function implementation file

#include "creature.hpp"

int Creature::attack(Creature *opponent)
{
	//check current health status
	//if is already injured, leave status unchanged
	//if not previously injured but Goblin's archilles is true, change status to injured
	if (!injured)
	{
		if ((opponent->getType() == "Goblin") && (opponent->archilles))
			injured = true;
	}
	
	int attackPoints = 0;

	//roll the attack dice
	Die *dieA;
	dieA = new Die(attackNumSides);
	for (int i = 0; i < attackNumDice; i++)
		attackPoints += dieA->roll();
	delete dieA;
	
	//if attacker is injured, reduce impact in half
	if (injured)
	{
		attackPoints = (attackPoints / 2);
		cout << " * Injured! Attack is halved." << endl;
		cout << " - " << this->name << " Attack = " << attackPoints << endl;

		totalAttacks += attackPoints;
		return attackPoints;
	}
	else
	{
		cout << " - " << this->name << " Attack = " << attackPoints << endl;

		totalAttacks += attackPoints;
		return attackPoints;
	}
}

void Creature::defense(int attackReceived)
{
	int defensePoints = 0;
	int damage = 0;	
	
	//roll the defense dice
	Die *dieD;
	dieD = new Die(defenseNumSides);
	for (int i = 0; i < defenseNumDice; i++)
		defensePoints += dieD->roll();
	
	damage = attackReceived - defensePoints - armor;

	if (damage < 0)	//cannot have negative damage
		damage = 0;

	strength -= damage;

	if (strength < 0)	//cannot have negative strength
		strength = 0;

	cout << " - " << this->name << " Defense = " << defensePoints << endl;
	cout << " - " << this->name << " Damage = " << damage << endl;
	cout << " - " << this->name << " Strength = " << strength << endl;

	delete dieD;
}

string Creature::getType()
{
	return type;
}

string Creature::getName()
{
	return name;
}

int Creature::getTeam()
{
	return playerTeam;
}

int Creature::getStrength()
{
	return strength;
}

int Creature::getTotalAttacks()
{
	return totalAttacks;
}

void Creature::updateWins()
{
	wins += 1;
}
