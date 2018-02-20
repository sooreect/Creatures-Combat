//Tida Sooreechine
//Assignment 4, 11/21/15

//bluemen.hpp is the BlueMen class specification file

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "creature.hpp"

//BlueMen class declaration
class BlueMen : public Creature
{
protected:

public:
	BlueMen(string creatureName, int teamNum);
	virtual void recovery();
};

#endif
