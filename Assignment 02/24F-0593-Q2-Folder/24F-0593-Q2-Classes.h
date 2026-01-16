#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>
#include <iostream>
using namespace std;

enum ItemType
{
    WEAPON,
    ARMOR,
    POTION,
    MISC
};
enum EnemyType
{
    GOBLIN,
    TROLL,
    DRAGON,
    SKELETON
};
enum TerrainType
{
    FOREST,
    CAVE,
    MOUNTAIN,
    VILLAGE
};



class Item
{
private:
    string name;
    ItemType type;
    int value;
    double weight;
public:
    // Constructor
    Item(string name, ItemType type, int value, double weight);
    // Method to describe the item
    void describeItem() const;
    ItemType getType() const;
};

class Enemy
{
private:
    string name;
    EnemyType type;
    int health;
    int attackPower;
    int defensePower;
public:
    // Constructor
    Enemy(string name, EnemyType type, int health, int attackPower, int defensePower);
    // Method to simulate an attack on the enemy
    bool attackEnemy(int damage);
    // Method to display enemy info
    void displayEnemyInfo() const;
    // Getter for health
    int getHealth() const;
};

class Character
{
private:
    string name;
    int level;
    int experience;
    int health;
    int attackPower;
    int defensePower;
    Item *inventory[10]; // Array of pointers to Item objects
    int inventorySize;
public:
    // Constructor
    Character(string name, int level, int experience, int health, int attackPower, int defensePower);
    // Getter for attackPower
    int getAttackPower() const;
    // Getter for health
    int getHealth() const;
    // Getter for name
    string getName() const;
    void addItem(Item *item);
    void removeItem(Item *item);
    // Method to gain experience
    void gainExperience(int exp);
    // Method to use an item
    void useItem(Item *item);
    // Method to display character info
    void displayCharacterInfo() const;
};

class Terrain
{
private:
    string name;
    TerrainType type;
    Enemy *enemies[10]; // Array of pointers to Enemy objects
    int numEnemies;
    Item *items[10]; // Array of pointers to Item objects
    int numItems;
public:
    // Constructor
    Terrain(string name, TerrainType type);
    void addEnemy(Enemy *enemy);
    void removeEnemy(Enemy *enemy);
    // Method to add an item
    void addItem(Item *item);
    void removeItem(Item *item);
    // Method to display terrain info
    void displayTerrainInfo() const;
};

class Area
{
private:
    string name;
    Terrain *terrain;
    Area *connectedAreas[5]; // Array of pointers to Area objects
    int numConnectedAreas;
public:
    // Constructor
    Area(string name, Terrain *terrain);
    // Method to add a connected area
    void addConnectedArea(Area *area);
    // Method to display area info
    void displayAreaInfo() const;
};

class GameWorld
{
private:
    Area *areas[10]; // Array of pointers to Area objects
    int numAreas;
public:
    // Constructor
    GameWorld();
    // Method to add an area
    void addArea(Area *area);
    void removeArea(Area *area);
    int getAreaCount();
    // Method to display world info
    void displayWorldInfo() const;
};

#endif
