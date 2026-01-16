#include <iostream>
#include "24F-0593-Q1-Classes.h"
using namespace std;

//-----------------------UNIT CLASS METHOD'S DEFINITION--------------------

Unit::Unit(string unitType, int health, int attack, int defense, int movementRange, int x, int y){
    this->unitType = unitType;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->movementRange = movementRange;
    this->position.x = x;
    this->position.y = y;
}

//will move Unit
void Unit::moveUnit(int newX, int newY){
    position.x = newX;
    position.y = newY;
}

//Check if Unit is Alive
bool Unit::isAlive() { return health > 0; }

//Attack Logic
void Unit::attackUnit(Unit* enemyUnit){
    int damage = 0;
    //Checking if they are both in same line, if not then there will be no damage and attack will be waste
    if(this->position.x == enemyUnit->position.x){
        damage = attack - enemyUnit->defense;
        if(damage>0){
            cout << "Damage done : " << damage << endl; 
            enemyUnit->health = enemyUnit->health - damage;
            cout << "Now remaining health of enemy unit : " << enemyUnit->health << endl;
            if(enemyUnit->health < 0){
                enemyUnit->health = 0;
            }
        }
    }
    
}

//Display current status
void Unit::display(){
    cout << "Type : " << unitType << endl;
    cout << "Health : " << health << endl;
    cout << "Attack Value : " << attack << endl;
    cout << "Last Defense : " << defense << endl;
    cout << "Position: (" << position.x << ", " << position.y << ")" << endl << endl;
}

int Unit::getHealth() const{
    return health;
}

//--------------MAP CLASS METHOD'S DEFINITION----------------------

Map::Map() {
    initializeMap();
}

// Initializes the grid with NULL pointers (empty cells)
void Map::initializeMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            grid[i][j] = nullptr;
        }
    }
}

// Adds a unit to the map at (x, y)
void Map::addUnitToMap(Unit* unit, int x, int y) {
    if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
        if (grid[x][y] == nullptr) {
            grid[x][y] = unit;
            cout << "Successfuly added!" << endl;
        } 
        else {
            cout << "Position (" << x << ", " << y << ") is already occupied!" << endl;
        }
    } else {
        cout << "Invalid position!" << endl;
    }
}

// Removes a unit from the map at (x, y)
void Map::removeUnitFromMap(int x, int y) {
    if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
        if (grid[x][y] != nullptr) {
            grid[x][y] = nullptr;
            cout << "Successfuly removed!" << endl;
        } else {
            cout << "No unit found at (" << x << ", " << y << ")!" << endl;
        }
    } else {
        cout << "Invalid position!" << endl;
    }
}

// Displays the map with unit positions
void Map::displayMap() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (grid[i][j] != nullptr) {
                cout << "[U] "; // 'U' represents a unit
            } else {
                cout << "[ ] "; // Empty space
            }
        }
        cout << endl;
    }
}

//Will return the Unit at provided x and y coordinates
Unit* Map::getUnitAt(int x, int y) {
    if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE) {
        return grid[x][y]; // Returns the Unit pointer at (x, y)
    }
    return nullptr; // No unit at this position
}

// --------------------PLAYER CLASS METHOD'S DEFINITION----------------------------

Player::Player(std::string playerName) {
    name = playerName;
    unitCount = 0;
    for (int i = 0; i < MAX_UNITS; i++) {
        units[i] = nullptr;
    }
}

// Adds a unit to the player's list
void Player::addUnit(Unit* newUnit) {
    if (unitCount < MAX_UNITS) {
        units[unitCount] = newUnit;
        unitCount++;
    } else {
        cout << "Cannot add more units, maximum reached!" << endl;
    }
}

// Removes a unit from the player's list
void Player::removeUnit(Unit* unit) {
    for (int i = 0; i < unitCount; i++) {
        if (units[i] == unit) {
            // Shift remaining units to fill the gap
            for (int j = i; j < unitCount - 1; j++) {
                units[j] = units[j + 1];
            }
            units[unitCount - 1] = nullptr;
            unitCount--;
            cout << "Unit removed from player " << name << endl;
            return;
        }
    }
    cout << "Unit not found!" << endl;
}

// Displays all units controlled by the player
void Player::displayUnits() {
    cout << "Player: " << name << " has " << unitCount << " units.\n";
    for (int i = 0; i < unitCount; i++) {
        if (units[i] != nullptr) {
            units[i]->display();
        }
    }
}
string Player::getName() const {
    return name;
}
//get unitCount
int Player::getUnitCount() const{
    return unitCount;
}
// --------------------GAME CLASS METHOD'S DEFINITION----------------------------

//Constructor that will iniatilize Player Object and will assign a name to it
Game::Game(Player* player1, Player* player2) {
    players[0] = player1;
    players[1] = player2;
    currentPlayerIndex = 0; // Player 1 starts
}
//It will vanish the players when game will finish
Game::~Game(){
    delete players[0];
    delete players[1];
}
//Will handle logic of the player's turn
void Game::nextTurn(){
    currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    cout << "It's now " << (currentPlayerIndex == 0 ? players[0]->getName() : players[1]->getName()) << "'s turn.\n";
}
// Moves a unit from (x, y) to (newX, newY) if possible
void Game::performAction(int x, int y, int newX, int newY) {
    Unit* unit = map.getUnitAt(x, y);
    if (unit != nullptr) {
        map.removeUnitFromMap(x, y);
        map.addUnitToMap(unit, newX, newY);
        cout << "Unit moved from (" << x << ", " << y << ") to (" << newX << ", " << newY << ")\n";
    } else {
        cout << "No unit found at (" << x << ", " << y << ")\n";
    }
}
//Checks if any player has won the game.
bool Game::checkVictory() {
    if (players[0]->getUnitCount() == 0) {
        cout << players[1]->getName() << " wins the game!\n";
        return true;
    }
    if (players[1]->getUnitCount() == 0) {
        cout << players[0]->getName() << " wins the game!\n";
        return true;
    }
    return false;
}
//Displays the current game state, including the map and whose turn it is
void Game::displayGameState() {
    cout << "\nCurrent Game State:\n";
    map.displayMap();
    cout << "Player Turn: " << (currentPlayerIndex == 0 ? players[0]->getName() : players[1]->getName()) << endl;
}

//---------------------------RESOLVE COMBAT FUNCTION DEFINITION-----------------


void Game::resolveCombat(Unit* attacker, Unit* defender){
    attacker->attackUnit(defender);
    if(defender->getHealth() == 0){
        players[currentPlayerIndex]->removeUnit(defender);
    }
}