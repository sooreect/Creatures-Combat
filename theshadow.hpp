//Tida Sooreechine
//Assignment 4, 11/21/15

//theshadow.hpp is the TheShadow class specification file

#ifndef THESHADOW_HPP
#define THESHADOW_HPP

#include "creature.hpp"

using std::cout;
using std::endl;

//TheShadow class declaration
class TheShadow : public Creature
{
protected:

public:
	TheShadow(string creatureName, int teamNum);
	virtual void defense(int);
	virtual void recovery();
};

#endif
