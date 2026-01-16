#include"Arena.h"

string Arena::getName() const{
	return name;
}

ENVIRONMENT Arena::getEnvironmentType() const{
	return type;
}

void Arena::setName(string n){
	name = n;
}

void Arena::setEnvironmentType(ENVIRONMENT ty){
	type = ty;
}

void Arena::addPlayer1(Character* player){
	player1 = player;
	cout << player->getName() << " entered the arena!" << endl;
}

void Arena::addPlayer2(Character* player){
	player2 = player;
	cout << player->getName() << " entered the arena!" << endl;
}

void Arena::removePlayer1(Character* player){
	if (player1 == player)
		player1 = nullptr;
	else
		cout << "Character not found!" << endl;
}

void Arena::removePlayer2(Character* player){
	if (player2 == player)
		player2 = nullptr;
	else
		cout << "Character not found!" << endl;
}

void Arena::giveBuff(Character* player){
	CHARACTER charType = player->getType();

	switch (type)
	{
	case FIRE:
		if (charType == GOJO)
		{
			player->setAttack(player->getAttack() + 20);
			player->setDefense(player->getDefense() + 20);
			cout << player->getName() << " loves hot fights! +20 ATK,+20 DEF!" << endl;
		}
		break;
	case ICE:
		if (charType == GOKU)
		{
			player->setDefense(player->getDefense() + 30);
			player->setAttack(player->getAttack() + 10);
			cout << player->getName() << " Enjoy in cold! +30 DEF, +10 ATK!" << endl;
		}
		else
		{
			player->setDefense(player->getDefense() + 20);
			cout << player->getName() << " found cover in ice! +20 DEF" << endl;
		}
		break;

	case JUNGLE:
		if (charType == LEVI)
		{
			player->setAttack(player->getAttack() + 30);
			player->setDefense(player->getDefense() + 30);
			cout << player->getName() << " moves like lightning through trees! +30 DEF, +30 ATK!" << endl;
		}
		else
		{
			player->setDefense(player->getDefense() + 20);
			player->setHealth(player->getHealth() + 30);
			cout << player->getName() << " finds herbs healing +30 HP!" << endl;
			cout << player->getName() << " got cover by trees +20 DEF!" << endl;
		}
		break;
	}
}

void Arena::giveDebuff(Character* player)
{
	CHARACTER charType = player->getType();

	switch (type)
	{
	case FIRE:
		if (charType != GOJO)
		{
			player->setHealth(player->getHealth() - 20);
			cout << player->getName() << " caught in Fire! -20 HP" << endl;
		}
		break;

	case ICE:
		if (charType != GOKU)
		{
			player->setAttack(player->getAttack() - 10);
			player->setDefense(player->getDefense() - 10);
			cout << player->getName() << " shivers from cold! -10 ATK, -10 DEF!" << endl;
		}
		break;

	case JUNGLE:
		if (charType != LEVI)
		{
			player->setAttack(player->getAttack() - 20);
			cout << player->getName() << "'s attacks misses due to trees! -20 ATK!" << endl;
		}
		break;
	}
}