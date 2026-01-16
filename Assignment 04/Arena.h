#pragma once

#include"character.h"

enum ENVIRONMENT { FIRE, ICE, JUNGLE };

class Arena
{
	string name;
	ENVIRONMENT type;
	Character* player1;
	Character* player2;
public:
	string getName()const;
	ENVIRONMENT getEnvironmentType()const;

	void setName(string n);
	void setEnvironmentType(ENVIRONMENT ty);

	void addPlayer1(Character* player);
	void addPlayer2(Character* player);
	void removePlayer1(Character* player);
	void removePlayer2(Character* player);
	void giveBuff(Character* player);
	void giveDebuff(Character* player);
};
