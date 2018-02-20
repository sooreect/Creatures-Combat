/****************************************************************************************
 * Author: Tida Sooreechine
 * Date: 11/21/2015
 * Description: Fantasy Creatures Combat Tournament  
 * Inputs: User specifies the number of fighters, and the players input creature of 
 * 	choice and name for each fighter.
 * Outputs: The game outputs the result of each fight round, each battle round, and 
 * 	the tournament. 
****************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "die.hpp"
#include "creature.hpp"
#include "goblin.hpp"
#include "barbarian.hpp"
#include "reptilepeople.hpp"
#include "bluemen.hpp"
#include "theshadow.hpp"
#include "team.hpp"
#include "pile.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	cout << endl << endl;
	cout << "ASSIGNMENT 4: CONTAINERS" << endl << endl;

	//declare local variables
	int action;
	int numFighters, charChoice, player;
	int attackValue;
	int player1Score = 0;
	int player2Score = 0;
	string name, teamName;

	//creating object pointers
	Creature *character, *fighter1, *fighter2, *loser, *winner, *fighterAlive;
	Pile *loserPile = new Pile();
	Pile *rankings = new Pile();
	Team *team1 = new Team();
	Team *team2 = new Team();

	//seed random number from system time
	srand(time(NULL));

	cout << "COMBAT TOURNAMENT" << endl << endl;

	//prompt user to input number of fighters
	cout << "Please enter the number of fighters for each team: ";
	cin >> numFighters;
	while (numFighters < 1)	//validate input
	{
		cout << "Invalid input. Please enter a positive integer: ";
		cin >> numFighters;
	}
	cout << endl;

	//prompt players to choose their lineup of fighters
	for (int j = 0; j < 2; j++)
	{
		cout << "Player " << (j + 1) << ", please select your lineup of fighters." << endl << endl;

		//dislay characters menu
		cout << "Fighters Selection Menu:" << endl;
		cout << " 1. Goblin" << endl;
		cout << " 2. Barbarian" << endl;
		cout << " 3. Reptile People" << endl;
		cout << " 4. Blue Men" << endl;
		cout << " 5. The Shadow" << endl << endl;

		for	(int i = 0; i < numFighters; i++)
		{
			//prompt player for fighter's creature type 
			cout << "Select team fighter #" << (i + 1) << " (1-5): ";
			cin >> charChoice; 
			while (charChoice < 1 || charChoice > 5)
			{
				cout <<"Invalid input. Please re-enter choice (1-5): ";
				cin >> charChoice;
			}
		
			//prompt player for fighter's name
			cout << "Enter team fighter #" << (i + 1) << "\'s name: ";
			cin.ignore();
			getline(cin, name);		

			if (j == 0)
				player = 1;
			else
				player = 2;			

			//instantiate creature 
			if (charChoice == 1)
				character = new Goblin(name, player);
			else if (charChoice == 2)
				character = new Barbarian(name, player);
			else if (charChoice == 3)
				character = new ReptilePeople(name, player);
			else if (charChoice == 4)
				character = new BlueMen(name, player);
			else 
				character = new TheShadow(name, player);
		
			//add creature to back of the team's queue
			if (j == 0) 
				team1->addBack(character);
			else
				team2->addBack(character);
		}
		cout << endl;
	}
	
	//battle field
	for (int battle = 0; battle < 100; battle++)
	{
		//if both team lineups are not empty
		if ((!team1->isEmpty()) && (!team2->isEmpty()))
		{
			//naming the first player in line as fighters
			fighter1 = team1->getFront();
			fighter2 = team2->getFront();

			//battle round for-loop
			cout << "------------------------------------------------------------------------" << endl;
			cout << "BATTLE " << (battle + 1) << " : ";
			cout << fighter1->getName() << " the " << fighter1->getType() << " VS. ";
			cout << fighter2->getName() << " the " << fighter2->getType();
			cout << endl;
			cout << "------------------------------------------------------------------------" << endl;

			//fight round for-loop
			for (int round = 0; round < 100; round++)
			{
				//if fighters are not dead continue to next round
				if ((fighter1->getStrength() > 0) && (fighter2->getStrength() > 0))
				{
					cout << "ROUND " << (round + 1) << " : ";
					cout << fighter1->getName() << " - " << fighter1->getStrength() << " | ";
					cout << fighter2->getName() << " - " << fighter2->getStrength();
					cout << endl;

					//display Archilles mode status
					if (fighter1->getType() == "Goblin")
					{
						if (fighter1->archilles)
							cout << "Archilles mode activated." << endl;
					}
					if (fighter2->getType() == "Goblin")
					{
						if (fighter2->archilles)
							cout << "Archilles mode activated." << endl;
					}
					cout << "." << endl;

					//fighter1 attacks
					cout << fighter1->getName() << " attacks " << fighter2->getName() << endl;
					attackValue = fighter1->attack(fighter2);					
	
					//fighter2 defends
					fighter2->defense(attackValue);

					//if fighter2 is still alive, it attacks back
					if (fighter2->getStrength() > 0)
					{
						cout << fighter2->getName() << " attacks back." << endl;
						attackValue = fighter2->attack(fighter1);
						
						//fighter1 defends
						fighter1->defense(attackValue);
	
						//check if fighter1 is dead
						if (fighter1->getStrength() <= 0)
							cout << fighter1->getName() << " is dead!" << endl;
						cout << endl;
					}
					else
						cout << fighter2->getName() << " is dead!" << endl;	
					cout << endl;
				}
			}//round for loop

			cout << "BATTLE OVER." << endl;

			//display battle round stats		

			//if fighter from team 1 wins
			if (fighter1->getStrength() > fighter2->getStrength())
			{
				cout << fighter1->getName() << " wins the battle!" << endl;
				player1Score++;
				cout << "Player 1's score = " << player1Score << endl;
				cout << "Player 2's score = " << player2Score << endl << endl;
				fighter1->updateWins();			//update win points
				fighter1->recovery();			//recover winner's strength points as needed
				team1->addBack(fighter1);		//add winner to the back of the lineup for future rounds
				loserPile->addTop(fighter2);	//add loser to the stack of shame
				rankings->addTop(fighter2);		//add loser to the rankings stack
			}
			else	//if fighter from team 2 wins
			{
				cout << fighter2->getName() << " wins the battle!" << endl;
				player2Score++;
				cout << "Player 1's score = " << player1Score << endl;
				cout << "Player 2's score = " << player2Score << endl << endl;
				fighter2->updateWins();			//update win points
				fighter2->recovery();			//recover winner's strength points as needed
				team2->addBack(fighter2);		//add winer to the back of the lineup for future rounds
				loserPile->addTop(fighter1);	//add loser to the stack of shame
				rankings->addTop(fighter1);		//add loser to the rankings stack
			}

			//remove the fighters to their respective lineups
			team1->removeFront();
			team2->removeFront();
		}//if not empty
	}//battle for loop
	cout << endl;
	cout << endl;

	cout << "******************************************************************************";
	cout << endl;
	cout << " G A M E  O V E R" << endl;
	cout << "******************************************************************************";
	cout << endl;
	cout << endl;

	//tournament stats
	
	//display the last three finishers
	cout << "Best 3 Fighters: " << endl;
	if (!team1->isEmpty())						//if team 1 is the winning team
	{
		team1->bubbleSort();					//sort the fighters alive based on the attack points dealt
		while (!team1->isEmpty())
		{
			fighterAlive = team1->getFront();	//empty queue into ranking stack
			rankings->addTop(fighterAlive);		
			team1->removeFront();				
		}
	}
	else										//if team 2 is the winning team
	{
		team2->bubbleSort();					//sort the fighters alive based on the attack points dealt
		while (!team2->isEmpty())
		{	
			fighterAlive = team2->getFront();	//empty queue into ranking stack
			rankings->addTop(fighterAlive);
			team2->removeFront();	
		}
	}

	for (int k = 0; k < 3; k++)					//pop the last three finishers from ranking stack
	{
		winner = rankings->getTop();
	
		if (winner->getStrength() > 0)
		{
			cout << (k + 1) << ". " << winner->getName();
			cout << " (" << winner->getTotalAttacks();
			if (winner->getTeam() == 1)
				cout << ") from Team 1" << endl;
			else 
				cout << ") from Team 2" << endl;
		}
		else
		{ 
			cout << (k + 1) << ". " << winner->getName();
			cout << " (RIP) ";
			if (winner->getTeam() == 1)
				cout << "from Team 1" << endl;
			else
				cout << "from Team 2" << endl;
		}
	
		rankings->removeTop();
	}
	cout << endl;

	//optional menu
	cout << "Options: " << endl;
	cout << " 1. To see the rest of the rankings, press 1: " << endl;
	cout << " 2. To visit the Wall of Shame, press 2: " << endl;
	cout << "Enter your choice: ";
	cin >> action;
	while (action < 1 || action > 2) 
	{
		cout << "Invalid input. Enter 1-2: ";
		cin >> action;
	}
	cout << endl;

	if (action == 1)	//continue showing the fighters from the ranking stack
	{
		int n = 0;
		while (!rankings->isEmpty())	
		{
			winner = rankings->getTop();
		
			if (winner->getStrength() > 0)
			{
				cout << (n + 4) << ". " << winner->getName();
				cout << " (" << winner->getTotalAttacks();
				if (winner->getTeam() == 1)
					cout << ") from Team 1" << endl;
				else 
					cout << ") from Team 2" << endl;
			}
			else
			{ 
				cout << (n + 4) << ". " << winner->getName();
				cout << " (RIP) ";
				if (winner->getTeam() == 1)
					cout << "from Team 1" << endl;
				else
					cout << "from Team 2" << endl;
			}

			rankings->removeTop();
			n++;
		}
		cout << endl;
	}
	else	//pop the dead bodies from the loserPile stack
	{
		cout << "The Wall of Shame" << endl;
		cout << "Displaying the losers in order of their deaths (last to first):" << endl;
		while (!loserPile->isEmpty())
		{
			loser = loserPile->getTop();
			cout << " - " << loser->getName() << endl;		
			loserPile->removeTop();
		}
		cout << endl;	
	}

	//announce the tournament winner and their scores
	cout << "---" << endl << endl;
	cout << "Player 1's final score = " << player1Score << endl;
	cout << "Player 2's final score = " << player2Score << endl << endl;

	if (player1Score > player2Score)
		cout << "PLAYER 1 WINS THE TOURNAMENT!" << endl;
	else
		cout << "PLAYER 2 WINS THE TOURNAMENT!" << endl;
	cout << endl;

	delete loserPile;
	delete rankings;	
	delete team1;
	delete team2;
	return 0;
}

