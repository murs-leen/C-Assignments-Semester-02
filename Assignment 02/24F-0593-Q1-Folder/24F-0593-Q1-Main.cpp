#include "24F-0593-Q1-Classes.h"
#include "24F-0593-Q1-Classes_Methods.cpp"
#include<iostream>
using namespace std;
int main() {
    //Game created
    Player* player1 = new Player("Ahmed");
    Player* player2 = new Player("Shahmeer");
    
    //Unit( unitType, int health, int attack, int defense, int movementRange, int x, int y);
    Unit* unit1 = new Unit("Horse", 100, 20, 10, 5, 0, 0);
    Unit* unit2 = new Unit("Temple", 100, 20, 10, 5, 0, 1);
    Unit* unit3 = new Unit("King", 100, 20, 10, 5, 0, 2);
    player1->addUnit(unit1);
    player1->addUnit(unit2);
    player1->addUnit(unit3);

    Unit* unit4 = new Unit("Horse", 20, 20, 0, 5, 9, 9);
    Unit* unit5 = new Unit("Temple", 100, 20, 10, 5, 9, 8);
    Unit* unit6 = new Unit("King", 100, 20, 10, 5, 9, 7);  
    player2->addUnit(unit4);
    player2->addUnit(unit5);
    player2->addUnit(unit6);  

    Game game(player1, player2);
    game.map.initializeMap();

    game.map.addUnitToMap(unit1, 0,0);
    game.map.addUnitToMap(unit2, 0,1);
    game.map.addUnitToMap(unit1, 0,2);

    game.map.addUnitToMap(unit1, 9,9);
    game.map.addUnitToMap(unit1, 9, 8);
    game.map.addUnitToMap(unit1, 9,7);

    while (!game.checkVictory()) {
        game.displayGameState();
    
        // Current player's turn
        Player* currentPlayer = game.players[game.currentPlayerIndex];
        cout << currentPlayer->getName() << "'s turn:" << endl;
    
        // Example: Move a unit
        int x, y, newX, newY;
        cout << "Enter the position of the unit you want to move (x y): ";
        cin >> x >> y;
        cout << "Enter the new position (newX newY): ";
        cin >> newX >> newY;
        game.performAction(x, y, newX, newY);
        game.displayGameState();
    
        // Example: Attack with a unit
        cout << "Enter the position of the unit you want to attack with (x y): ";
        cin >> x >> y;
        cout << "Enter the position of the enemy unit to attack (X Y): ";
        cin >> newX >> newY;
        game.performAction(newX, newY, x, y);
    
        // Switch to the next player's turn
        game.nextTurn();
    }
    return 0;
}