#include <iostream>
#include "24F-0593-Q2-Classes.h"
using namespace std;

// Constructor
Item::Item(string name, ItemType type, int value, double weight)
    : name(name), type(type), value(value), weight(weight) {}

// Method to describe the item
void Item::describeItem() const
{
    cout << "Item: " << name << endl;
    cout << "Type: " << static_cast<int>(type) << endl;
    cout << "Value: " << value << " gold" << endl;
    cout << "Weight: " << weight << " kg" << endl;
}
ItemType Item::getType() const { return type; }

// ------------------------------------------------------------

Enemy::Enemy(string name, EnemyType type, int health, int attackPower, int defensePower)
    : name(name), type(type), health(health), attackPower(attackPower), defensePower(defensePower) {}

// Method to simulate an attack on the enemy
bool Enemy::attackEnemy(int damage)
{
    int effectiveDamage = damage - defensePower;
    if (effectiveDamage < 0)
        effectiveDamage = 0; // Ensure damage is not negative
    health -= effectiveDamage;
    if (health <= 0)
    {
        health = 0;
        cout << name << " took " << effectiveDamage << " damage!" << endl
             << "Health: " << health << endl;
        return true;
    }
    else
    {
        cout << name << " took " << effectiveDamage << " damage!" << endl
             << "Health: " << health << endl;
        return false;
    }
}

// Method to display enemy info
void Enemy::displayEnemyInfo() const
{
    cout << "Enemy: " << name << endl;
    cout << "Type: " << static_cast<int>(type) << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Defense Power: " << defensePower << endl;
}

// Getter for health
int Enemy::getHealth() const
{
    return health;
}

// ------------------------------------------------------------

Character::Character(string name, int level, int experience, int health, int attackPower, int defensePower)
    : name(name), level(level), experience(experience), health(health), attackPower(attackPower), defensePower(defensePower), inventorySize(0) {}

// Getter for attackPower
int Character::getAttackPower() const
{
    return attackPower;
}

// Getter for health
int Character::getHealth() const
{
    return health;
}

// Getter for name
string Character::getName() const
{
    return name;
}

void Character::addItem(Item *item)
{
    inventory[inventorySize] = item;
    inventorySize++;
}

void Character::removeItem(Item *item)
{
    for (int i = 0; i < inventorySize; i++)
    {
        if (inventory[i] == item)
        {
            inventory[i] = nullptr;
            inventorySize--;
        }
    }
}

// Method to gain experience
void Character::gainExperience(int exp)
{
    experience += exp;
    if (experience >= 100)
    {
        level++;
        experience -= 100;
        cout << name << " leveled up to level " << level << "!" << endl;
    }
}

// Method to use an item
void Character::useItem(Item *item)
{
    cout << name << " used ";
    item->describeItem();
    cout << endl;
    // Apply item effects here (e.g., increase health, attack power, etc.)
    if (item->getType() == POTION)
    {
        health += 10;
        cout << name << " gained 10 health!" << endl;
    }
    else if (item->getType() == WEAPON)
    {
        attackPower += 5;
        cout << name << " gained 5 attack power!" << endl;
    }
    else if (item->getType() == ARMOR)
    {
        defensePower += 5;
        cout << name << " gained 5 defense power!" << endl;
    }
    else if (item->getType() == MISC)
    {
        attackPower += 2;
        cout << name << " gained 2 attack power!" << endl;
    }
}

// Method to display character info
void Character::displayCharacterInfo() const
{
    cout << "Character: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << endl;
    cout << "Health: " << health << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Defense Power: " << defensePower << endl;
    cout << "Inventory: " << inventorySize << " items" << endl;
}

// -----------------------------------------------------------------------------------------------

Terrain::Terrain(string name, TerrainType type)
    : name(name), type(type), numEnemies(0), numItems(0) {}

// Method to add an enemy
void Terrain::addEnemy(Enemy *enemy)
{
    if (numEnemies < 10)
    {
        enemies[numEnemies] = enemy;
        numEnemies++;
    }
}

void Terrain::removeEnemy(Enemy *enemy)
{
    for (int i = 0; i < numEnemies; i++)
    {
        if (enemies[i] == enemy)
        {
            enemies[i] = nullptr;
            numEnemies--;
        }
    }
}

// Method to add an item
void Terrain::addItem(Item *item)
{
    if (numItems < 10)
    {
        items[numItems] = item;
        numItems++;
    }
}

void Terrain::removeItem(Item *item)
{
    for (int i = 0; i < numItems; i++)
    {
        if (items[i] == item)
        {
            items[i] = nullptr;
            numItems--;
        }
    }
}

// Method to display terrain info
void Terrain::displayTerrainInfo() const
{
    cout << "Terrain: " << name << endl;
    cout << "Type: " << static_cast<int>(type) << endl;
    cout << "Enemies: " << numEnemies << endl;
    cout << "Items: " << numItems << endl;
}

Area::Area(string name, Terrain *terrain)
    : name(name), terrain(terrain), numConnectedAreas(0) {}

// Method to add a connected area
void Area::addConnectedArea(Area *area)
{
    if (numConnectedAreas < 5)
    {
        connectedAreas[numConnectedAreas++] = area;
    }
}

// Method to display area info
void Area::displayAreaInfo() const
{
    cout << "Area: " << name << endl;
    terrain->displayTerrainInfo();
    cout << endl
         << "Connected Areas: " << numConnectedAreas << endl;
}

GameWorld::GameWorld() : numAreas(-1) {}

// Method to add an area
void GameWorld::addArea(Area *area)
{
    if (numAreas < 10)
    {
        areas[numAreas] = area;
        numAreas++;
    }
}

void GameWorld::removeArea(Area *area)
{
    for (int i = 0; i < numAreas; i++)
    {
        if (areas[i] == area)
        {
            areas[i] = nullptr;
            numAreas--;
        }
    }
}
int GameWorld::getAreaCount() { return numAreas; }
// Method to display world info
void GameWorld::displayWorldInfo() const
{
    cout << "Game World: " << numAreas << " areas" << endl;
    for (int i = 0; i < numAreas; i++)
    {
        if (areas[i] != nullptr)
            areas[i]->displayAreaInfo();
    }
}