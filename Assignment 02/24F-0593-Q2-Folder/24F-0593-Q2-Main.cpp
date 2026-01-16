#include "24F-0593-Q2-Classes.h"
#include "24F-0593-Q2-Classes_Methods.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    // Create items
    Item sword("Sword", ItemType::WEAPON, 100, 2.5);
    Item potion("Health Potion", ItemType::POTION, 50, 0.5);

    // Create enemies
    Enemy goblin("Goblin", EnemyType::GOBLIN, 50, 10, 5);
    Enemy dragon("Dragon", EnemyType::DRAGON, 50, 50, 5);

    // Create terrains
    Terrain forest("Dark Forest", TerrainType::FOREST);
    forest.addEnemy(&goblin);
    forest.addItem(&sword);

    Terrain cave("Spooky Cave", TerrainType::CAVE);
    cave.addEnemy(&dragon);
    cave.addItem(&potion);

    // Create areas
    Area area1("Forest Area", &forest);
    Area area2("Cave Area", &cave);
    area1.addConnectedArea(&area2);

    // Create game world
    GameWorld world;
    world.addArea(&area1);
    world.addArea(&area2);

    // Create character
    // string name, int level, int experience, int health, int attackPower, int defensePower
    Character hero("Hero", 1, 0, 100, 60, 10);

    // Simulating game
    cout << "================Starting game simulation===============" << endl;
    world.displayWorldInfo();
    cout << endl <<"------------------------------------" << endl; 
    hero.displayCharacterInfo();
    cout << endl << endl;

    // Simulate moving to the forest area
    cout << "Hero enters the Forest Area..." << endl;
    forest.displayTerrainInfo();

    cout << "\nHero Attacks the Goblin... " << endl;
    if(goblin.attackEnemy(40)){
        cout << "Goblin is defeated!" << endl;
        forest.removeEnemy(&goblin);
        hero.gainExperience(60);
        hero.addItem(&sword);
        forest.removeItem(&sword);
    }
    
    cout << "\nHero Attacks the Goblin AGAIN... " << endl;
    if(goblin.attackEnemy(40)){
        cout << "Goblin is defeated!" << endl;
        forest.removeEnemy(&goblin);
        hero.gainExperience(110);
        hero.addItem(&sword);
        forest.removeItem(&sword);
    }
    cout << endl;

    forest.displayTerrainInfo();
    cout << endl;
    hero.displayCharacterInfo();

    world.removeArea(&area1);

    cout << world.getAreaCount() << endl;

    if(world.getAreaCount()){
        cout << "Hero moves to the next area..." << endl;
    }
    else{
        cout << "Hero has reached the end of the world..." << endl;
    }

    cout << endl <<"=======================================================================================" << endl; 
    world.displayWorldInfo();
    cout << endl <<"------------------------------------" << endl; 
    hero.displayCharacterInfo();
    cout << endl << endl;

    // Simulate moving to the forest area
    cout << "Hero enters the Forest Area..." << endl;
    cave.displayTerrainInfo();

    cout << "\nHero Attacks the Dragon... " << endl;
    if(dragon.attackEnemy(40)){
        cout << "Dragon is defeated!" << endl;
        cave.removeEnemy(&dragon);
        hero.gainExperience(60);
        hero.addItem(&potion);
        cave.removeItem(&potion);
    }
    
    cout << "\nHero Attacks the Goblin AGAIN... " << endl;
    if(dragon.attackEnemy(40)){
        cout << "Dragon is defeated!" << endl;
        cave.removeEnemy(&dragon);
        hero.gainExperience(60);
        hero.addItem(&potion);
        cave.removeItem(&potion);
    }
    cout << endl;

    cave.displayTerrainInfo();
    cout << endl;
    hero.displayCharacterInfo();

    world.removeArea(&area2);
    world.removeArea(&area2);


    cout << world.getAreaCount() << endl;
    if(world.getAreaCount()){
        cout << "Hero moves to the next area..." << endl;
    }
    else{
        cout << "Hero has reached the end of the world..." << endl;
    }
    return 0;
}