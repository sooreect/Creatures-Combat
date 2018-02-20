//Tida Sooreechine
//Assignment 4, 11/21/15

//creature.hpp is the Creature class specification file

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <iomanip>

#include "die.hpp"

using std::cout;
using std::endl;
using std::string;
using std::setw;

//Creature class declaration
class Creature
{
protected:
	string type;
	string name;
	int playerTeam;
	int attackNumDice;
	int attackNumSides;
	int defenseNumDice;
	int defenseNumSides;
	int armor;
	int strength;
	int wins;
	int totalAttacks;
	bool injured;

public:
	bool archilles;
	string getType();
	string getName();
	int getTeam();
	int getStrength();
	int getTotalAttacks();
	void updateWins();
	virtual int attack(Creature *opponent);
	virtual void defense(int attackReceived);
	virtual void recovery() = 0;
};

#endif

