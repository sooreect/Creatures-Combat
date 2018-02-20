//Tida Sooreechine
//Assignment 4, 11/21/15

//team.hpp is the Team class specification file

#ifndef TEAM_HPP
#define TEAM_HPP

#include <algorithm>
#include "creature.hpp"

using std::swap;

struct teamNode
{
	Creature *creaturePtr;
	teamNode *next;
	teamNode(Creature *member, teamNode *nextPtr = NULL)
	{
		creaturePtr = member;
		next = nextPtr;
	}
};

//Team class declaration
class Team
{
private:
	teamNode *front;		//queue front pointer
	teamNode *back;			//queue back pointer	

public:
	Team();				//constructor
	~Team();
	void addBack(Creature *aliveCreature);
	Creature* getFront();
	void removeFront();
	bool isEmpty();
	int size();
	void bubbleSort();
};

#endif
