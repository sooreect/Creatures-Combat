//Tida Sooreechine
//Assignment 3, 11/7/15

//die.hpp is the Die class specification file.

#ifndef DIE_HPP
#define DIE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

//Die class declaration
class Die
{
private:
	int numSides;
public:
	Die(int numSides);
	int roll();
};

#endif
