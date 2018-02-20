//Tida Sooreechine
//Assignment 4, 11/21/15

//barbarian.hpp is the Creature class specification file

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "creature.hpp"

//Barbarian class declaration
class Barbarian : public Creature
{
protected:

public:
	Barbarian(string creatureName, int teamNum);
	virtual void recovery(); 
};

#endif
