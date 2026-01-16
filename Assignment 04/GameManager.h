#pragma once

#include "Arena.h"

class GameManager
{
	Arena* currentArena;
	Character* currentPlayer;
	Character* otherPlayer;
	string battleHistory;
	const string historyFileName = "battleHistory.txt";

	void saveHistoryToFile() const;
public:
	GameManager();
	~GameManager();
	void setArena(Arena* arena);
	void setPlayers(Character* player1, Character* player2);
	void changeTurn();
	Character* getCurrentPlayer() const;
	Character* getOtherPlayer() const;
	void recordBattleHistory(const string message);
	void finalizeBattle(const string message);
	void displayBattleHistory() const;
	friend ostream& operator <<(ostream& print, GameManager& game);
};
