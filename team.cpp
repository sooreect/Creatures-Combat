//Tida Sooreechine
//Assignment 4, 11/21/15

//team.cpp is the Team class function implementation file

#include <iostream>
#include "team.hpp"

using std::cin;
using std::cout;
using std::endl;

//Team class constructor
//create an empty queue
Team::Team()
{
	front = NULL;
	back = NULL;
}

//adds new item to the back of the queue
void Team::addBack(Creature *aliveCharacter)
{
	teamNode *nodePtr = new teamNode(aliveCharacter);

	if (isEmpty())		
		front = nodePtr;			//point front to the newly allocated node
	else	
		back->next = nodePtr;		//point back to the newly allocated node

	back = nodePtr;					//point back pointer to new node
}

//returns the first fighter in line
Creature* Team::getFront()
{
	if (!isEmpty())
	{
		teamNode *nodePtr = front;
		return (nodePtr->creaturePtr);	
	}
	else
	{
		return NULL;
	}
}

//checks if queue is empty
//returns true if queue is empty
bool Team::isEmpty()
{
	if (!front)
		return true;
	else
		return false;
}

//removes the frontmost item
void Team::removeFront()
{
	if (!isEmpty())
	{
		teamNode *nodePtr = front;			//start at front of the queue
		front = front->next;				//reassign front to second node
		delete nodePtr;						//delete frontmost node
	}
}

int Team::size()
{
	if (!isEmpty())
	{
		teamNode *nodePtr = front;
		int count = 0;
		
		while (nodePtr != NULL)
		{
			count++;
			nodePtr = nodePtr->next;
		}
		
		return count;
	}
	else
		return 0;
}

void Team::bubbleSort()
{
	if (this->size() > 1)
	{
		teamNode *nodePtr = NULL;
		teamNode *trailPtr = NULL;
		teamNode *tempPtr = NULL;
	
		int count = this->size();
		
		for (int i = 0; i < count; ++i)
		{
			nodePtr = trailPtr = front;		//start at the beginning
			
			while (nodePtr->next != NULL)
			{
				if (nodePtr->creaturePtr->getTotalAttacks() > nodePtr->next->creaturePtr->getTotalAttacks())
				{
					tempPtr = nodePtr->next;
					nodePtr->next = nodePtr->next->next;
					tempPtr->next = nodePtr;
	
					if (nodePtr == front)
						front = trailPtr = tempPtr;
					else
						trailPtr->next = tempPtr;
					
					nodePtr = tempPtr;
				}
				
				trailPtr = nodePtr;
				nodePtr = nodePtr->next;
			}
		}	
	}	
}

//Team class destructor
//deallocate the memory used by the queue
Team::~Team()
{
 	teamNode *nodePtr = front;			//start at front of the queue
	while (nodePtr != NULL)				//while queue is not empty
	{
		teamNode *garbage = nodePtr;	//create and point garbage pointer to front of queue	
		nodePtr = nodePtr->next;		//once nodePtr moves to next node
		delete garbage;					//delete "garbage" node
	}

	front = back = NULL;
}
