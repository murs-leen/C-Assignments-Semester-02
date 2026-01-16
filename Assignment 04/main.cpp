#include "GameManager.h"
#include<conio.h>

int main()
{
	Goku* goku = new Goku("Superman", GOKU, 1, 100, 60, 20);
	Gojo* gojo = new Gojo("Batman", GOJO, 1, 120, 60, 30);
	Levi* levi = new Levi("Joker", LEVI, 1, 90, 40, 15);

	Arena fireArena;
	fireArena.setName("Volcano Ring");
	fireArena.setEnvironmentType(FIRE);

	Arena iceArena;
	iceArena.setName("Icy Hills");
	iceArena.setEnvironmentType(ICE);

	Arena jungleArena;
	jungleArena.setName("Wild Forest");
	jungleArena.setEnvironmentType(JUNGLE);

	GameManager game;

	cout << "Select Arena:\n";
	cout << "1. Volcano Ring (Fire)\n";
	cout << "2. Icy Hills (Ice)\n";
	cout << "3. Wild Forest (Jungle)\n";
	cout << "Enter Choice: ";
	int option;
	cin >> option;
	Arena* arena = nullptr;
	switch (option)
	{
	case 1:
		arena = &fireArena;
		break;
	case 2:
		arena = &iceArena;
		break;
	case 3:
		arena = &jungleArena;
		break;
	default:
		cout << "Invalid choice! Arena is set to Wild Forest\n";
		arena = &fireArena;
	}
	game.setArena(arena);
	cout << "Arena is set to " << arena->getName() << endl;

	_getch();
	system("cls");
	Character* player1 = nullptr;
	Character* player2 = nullptr;

	cout << "\nSelect Player 1:\n";
	cout << "1. Superman\n";
	cout << "2. Bateman\n";
	cout << "3. Joker\n";
	cout << "Enter Choice: ";
	int p1Choice;
	cin >> p1Choice;
	switch (p1Choice)
	{
	case 1:
		player1 = goku;
		break;
	case 2:
		player1 = gojo;
		break;
	case 3:
		player1 = levi;
		break;
	default:
		cout << "Invalid choice! player is set to Goku\n";
		player1 = goku;
	}
	cout << "Player 1 is set to " << player1->getName() << endl;
	_getch();
	system("cls");
	cout << "\nSelect Player 2:\n";
	cout << "1. Superman\n";
	cout << "2. Bateman\n";
	cout << "3. Joker\n";
	cout << "Enter Choice: ";
	int p2Choice;
	cin >> p2Choice;
	switch (p2Choice)
	{
	case 1:
		player2 = goku;
		break;
	case 2:
		player2 = gojo;
		break;
	case 3:
		player2 = levi;
		break;
	default:
		cout << "Invalid choice! player is set to Gojo\n";
		player2 = gojo;
	}
	cout << "Player 2 is set to " << player2->getName() << endl;

	player1->setTurn(true);
	player2->setTurn(false);
	_getch();
	system("cls");

	arena->addPlayer1(player1);
	arena->addPlayer2(player2);

	arena->giveBuff(player1);
	arena->giveBuff(player2);
	arena->giveDebuff(player1);
	arena->giveDebuff(player2);
	game.setPlayers(player1, player2);

	_getch();
	system("cls");
	int turn = 1;
	int play = 1;
	while (play != 0)
	{
		cout << "- - - - - Turn " << turn << " - - - - -\n\n";

		Character* currentPlayer = game.getCurrentPlayer();
		Character* enemy = game.getOtherPlayer();

		cout << currentPlayer->getName() << "'s turn:\n";
		cout << "1. Attack\n";
		cout << "2. Use Special Ability\n";
		cout << "3. View Stats\n";

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			currentPlayer->attackTarget(*enemy);
			game.recordBattleHistory(currentPlayer->getName() + " attacked " + enemy->getName());
			break;
		case 2:
			currentPlayer->useSpecialAbility(*enemy);
			game.recordBattleHistory(currentPlayer->getName() + " used special ability on " + enemy->getName());
			break;
		case 3:
			cout << game;
			continue;
		default:
			cout << "Invalid choice! Your Turnis Lost\n";
			game.recordBattleHistory(currentPlayer->getName() + " Lost his Turn");
		}

		if (enemy->getHealth() <= 0)
		{
			cout << enemy->getName() << " has been defeated!\n";
			currentPlayer->setBattleWon(currentPlayer->getBattleWon() + 1);
			game.finalizeBattle(currentPlayer->getName() + " wins!");
			cout << "Enter 0 if you want to quit, else press any key: ";
			cin >> play;
			if (play != 0)
			{
				Character* otherPlayer = nullptr;
				if (currentPlayer == player1)
					otherPlayer = player2;
				else
					otherPlayer = player1;
				int type = otherPlayer->getType();
				delete otherPlayer;
				switch (type)
				{
				case GOKU:
					otherPlayer = new Goku("Superman", GOKU, 1, 100, 30, 20);
					break;
				case GOJO:
					otherPlayer = new Gojo("Batman", GOJO, 1, 120, 35, 30);
					break;
				case LEVI:
					otherPlayer = new Levi("Joker", LEVI, 1, 90, 20, 15);
					break;
				}
				if (currentPlayer == player1)
					player2 = otherPlayer;
				else
					player1 = otherPlayer;
				otherPlayer = nullptr;
				currentPlayer->setHealth(currentPlayer->getHealth() + 50);
			}
		}

		game.changeTurn();
		turn++;
		_getch();
		system("cls");
		if (player1->getType() == GOKU)
		{
			int battleWon = player1->getBattleWon();
			if (battleWon >= 2)
				player1->setSuperSaiyan(true);
		}
		if (player2->getType() == GOKU)
		{
			int battleWon = player2->getBattleWon();
			if (battleWon >= 2)
				player2->setSuperSaiyan(true);
		}
		if (player1->getType() == GOJO)
		{
			int battleWon = player1->getBattleWon();
			if (battleWon >= 1)
				player1->setLimitlessTechnique(true);
		}
		if (player2->getType() == GOJO)
		{
			int battleWon = player2->getBattleWon();
			if (battleWon >= 1)
				player2->setLimitlessTechnique(true);
		}
	}

	game.displayBattleHistory();

	delete goku;
	delete gojo;
	delete levi;

	return 0;
}