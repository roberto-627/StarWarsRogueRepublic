#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	//Atributes.
	string username;
	string userpass;
	string forceAffiliation;
	int usercredits;
	int battles;
	int battlesWon;
	int battlesLost;
	int unitsLost;
	int unitsKilled;

	//Deafult Player Constructor (IDE).
	Player();
	//New Player Constructor.
	Player(string n, string pass);
	//Existing Player Constructor.
	Player(string n, string pass, int credits, int bwon, int blost);
};