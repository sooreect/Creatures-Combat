//Tida Sooreechine
//Assignment 4, 11/21/15

//goblin.hpp is the Goblin class specification file

#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "creature.hpp"

using std::cout;
using std::endl;

//Goblin class declaration
class Goblin : public Creature
{
protected:

public:
	Goblin(string creatureName, int teamNum);
	virtual int attack(Creature *opponent);
	virtual void recovery();
};

#endif
