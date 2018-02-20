//Tida Sooreechine
//Assignment 4, 11/21/15

//reptilepeople.hpp is the ReptilePeople class specification file

#ifndef REPTILEPEOPLE_HPP
#define REPTILEPEOPLE_HPP

#include "creature.hpp"

//ReptilePeople class declaration
class ReptilePeople : public Creature
{
protected:

public:
	ReptilePeople(string creatureName, int teamNum);
	virtual void recovery();
};

#endif
