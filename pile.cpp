//Tida Sooreechine
//Assignment 4, 11/21/15

//pile.cpp is the Pile class function implementation file

#include <iostream>
#include "pile.hpp"

using std::cin;
using std::cout;
using std::endl;

//Pile class constructor
//creates an empty stack
Pile::Pile()
{
	top = NULL;
}

//add new item to the top of the stack
void Pile::addTop(Creature *deadCharacter)
{
	PileNode *nodePtr = new PileNode(deadCharacter);

	if (isEmpty())
		top = nodePtr;	
	else
	{
		nodePtr->next = top;
		top = nodePtr;
	}	
}

Creature* Pile::getTop()
{
	if (!isEmpty())
	{
		PileNode *nodePtr = top;
		return (nodePtr->creaturePtr);
	}
	else
	{
		return NULL;
	}
}

void Pile::removeTop()
{
	if(!isEmpty())
	{
		PileNode *nodePtr = top;
		top = top->next;
		delete nodePtr;
	}
}

bool Pile::isEmpty()
{
	if (!top)
		return true;
	else 
		return false;
}

//LoserPile class destructor
//deallocates the memory used by the stack
//Reference: Gaddis, p.1029
Pile::~Pile()
{
 	PileNode *nodePtr = top;			//start at top of the stack
	while (nodePtr != NULL)				//while stack is not empty
	{
		PileNode *garbage = nodePtr;	//create and point garbage pointer to top of stack	
		nodePtr = nodePtr->next;		//once nodePtr moves to next node
		delete garbage;					//delete "garbage" node
	}
}


