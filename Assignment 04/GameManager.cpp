#include "GameManager.h"
#include<fstream>
#include<conio.h>

GameManager::GameManager() : currentArena(nullptr), currentPlayer(nullptr), otherPlayer(nullptr)
{
	battleHistory = "- - - - - BATTLE HISTORY - - - - -\n";
}

GameManager::~GameManager()
{
	saveHistoryToFile();
}

void GameManager::setArena(Arena* arena)
{
	currentArena = arena;
	recordBattleHistory("Arena: " + arena->getName());
}

void GameManager::setPlayers(Character* player1, Character* player2)
{
	currentPlayer = player1;
	otherPlayer = player2;
	recordBattleHistory("Battle: " + player1->getName() + " vs " + player2->getName());
}

void GameManager::changeTurn()
{
	if (currentPlayer->getTurn())
	{
		currentPlayer->setTurn(false);
		otherPlayer->setTurn(true);
	}
	else
	{
		currentPlayer->setTurn(true);
		otherPlayer->setTurn(false);
	}
	Character* temp = currentPlayer;
	currentPlayer = otherPlayer;
	otherPlayer = temp;
}

Character* GameManager::getCurrentPlayer() const
{
	return currentPlayer;
}

Character* GameManager::getOtherPlayer() const
{
	return otherPlayer;
}

void GameManager::recordBattleHistory(const string message)
{
	battleHistory += " -> " + message + "\n";
}

void GameManager::finalizeBattle(const string message)
{
	recordBattleHistory("Result: " + message);
	saveHistoryToFile();
}

void GameManager::displayBattleHistory() const
{
	cout << battleHistory;
}

void GameManager::saveHistoryToFile() const
{
	ofstream fout(historyFileName);
	if (fout.is_open())
	{
		fout << battleHistory;
		fout.close();
	}
	else
		cout << "Cannot save! File Cannot be Opened!\n";
}
ostream& operator <<(ostream& print, GameManager& game)
{
	print << "- - - - - Player Stats - - - - -\n\n";
	print << "Name: " << game.currentPlayer->getName() << endl;
	print << "Level: " << game.currentPlayer->getLevel() << endl;
	print << "Health: " << game.currentPlayer->getHealth() << endl;
	print << "Attack: " << game.currentPlayer->getAttack() << endl;
	print << "Defense: " << game.currentPlayer->getDefense() << endl;
	print << "no.of Battles won: " << game.currentPlayer->getBattleWon() << endl;
	print << "Special ability:\n";
	switch (game.currentPlayer->getType())
	{
	case GOKU:
		print << "Kamehameha\nSuper Saiyan Form\n";
		break;
	case LEVI:
		print << "Thunder Spere\nUse ODM Gear\n";
		break;
	case GOJO:
		print << "Limitless Technique\nSix Eyes\nDomain Expansion\n";
		break;
	}
	print << "\n\nPress any key tocontinue..\n";
	_getch();
	system("cls");
	return print;
}