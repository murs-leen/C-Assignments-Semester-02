#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>
#include<iostream>


using namespace std;

// Position structure
struct Position
{
    int x, y;
};

// --------------------UNIT CLASS DECLERATIONS----------------------------

class Unit
{
    string unitType;
    int health;
    int attack;
    int defense;
    int movementRange;
    Position position;
    
    public:
    // Constructor
    Unit(string unitType, int health, int attack, int defense, int movementRange, int x, int y);
    // will move Unit
    void moveUnit(int newX, int newY);
    // Check if Unit is Alive
    bool isAlive();
    // Attack Logic
    void attackUnit(Unit *enemyUnit);
    // Display current status
    void display();
    // get Health
    int getHealth() const;
    int getX() const { return position.x; }
    int getY() const { return position.y; }
};

// --------------------MAP CLASS DECLERATIONS----------------------------

const int MAP_SIZE = 10; // Define grid size

class Map
{
private:
    Unit *grid[MAP_SIZE][MAP_SIZE]; // 2D array of Unit pointers

public:
    // Constructor to initialize the map
    Map();
    // Initializes the grid with empty cells.
    void initializeMap();
    // Adds a unit at the specified position.
    void addUnitToMap(Unit *unit, int x, int y);
    // Removes the unit from the specified position.
    void removeUnitFromMap(int x, int y);
    // Displays the map with positions of all units.
    void displayMap();
    // Will return the Unit at provided x and y coordinates
    Unit *getUnitAt(int x, int y);
};

// --------------------PLAYER CLASS DECLERATIONS----------------------------

const int MAX_UNITS = 5; // Maximum Units a player can have
class Player
{
    string name;
    Unit *units[MAX_UNITS];
    int unitCount;

public:
    // Constructor with parameter to add player name
    Player(string playerName);
    // Adds a unit to the player’s list of units
    void addUnit(Unit *newUnit);
    // Removes a unit from the player’s list of units
    void removeUnit(Unit *unit);
    // Displays the details of all units controlled by the player
    void displayUnits();
    // To get player name
    string getName() const;
    // get unitCount
    int getUnitCount() const;
};

//-----------------------GAME CLASS DECLERATIONS---------------------------------

class Game
{
private:

public:
int currentPlayerIndex; // Tracks whose turn it isz
Player *players[2]; // Two players
    Map map;
    // Constructor that will iniatilize Player Object and will assign a name to it
    Game(Player* player1, Player* player2);
    // It will vanish the players when game will finish
    ~Game();
    // Will handle logic of the player's turn
    void nextTurn();
    // Moves a unit from (x, y) to (newX, newY) if possible
    void performAction(int x, int y, int newX, int newY);
    // Checks if any player has won the game.
    bool checkVictory();
    // Displays the current game state, including the map and whose turn it is
    void displayGameState();
    void resolveCombat(Unit* attacker, Unit* defender);
};

#endif
