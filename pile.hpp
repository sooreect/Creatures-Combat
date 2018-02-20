//Tida Sooreechine
//Assignment4, 11/21/15

//pile.hpp is the Pile class specification file

#ifndef PILE_HPP
#define PILE_HPP

#include "creature.hpp" 

struct PileNode 
{
	Creature *creaturePtr;
	PileNode *next;
	PileNode(Creature *member, PileNode *nextPtr = NULL)
	{
		creaturePtr = member;
		next = nextPtr;
	}
};

//Pile class declaration
class Pile
{
private:
	PileNode *top;			//loser stack top pointer

public:
	Pile();				//constructor
	~Pile();
	void addTop(Creature *deadCharacter);
	Creature* getTop();
	void removeTop();
	bool isEmpty();
};


#endif
