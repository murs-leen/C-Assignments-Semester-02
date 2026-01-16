#include"character.h"

//------------------------- Goku -------------------------\\

Goku::Goku(string name, CHARACTER type, int level, int health, int attack, int defense)
{
	this->name = name;
	this->type = type;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->ki = 100;
	this->superSaiyan = false;
	this->ability = false;
	this->battleWon = 0;
}

string Goku::getName() const { return name; }
bool Goku::getTurn() const { return turn; }
int Goku::getLevel() const { return level; }
int Goku::getHealth() const { return health; }
int Goku::getAttack() const { return attack; }
int Goku::getDefense() const { return defense; }
int Goku::getKi()const { return ki; }
bool Goku::getAbility()const { return ability; }
bool Goku::getSuperSaiyan()const { return superSaiyan; }
int Goku::getBattleWon() const { return battleWon; }
CHARACTER Goku::getType()const { return type; }

void Goku::setName(const string n) { name = n; }
void Goku::setLevel(int lvl) { level = lvl; }
void Goku::setHealth(int hp) { health = hp; }
void Goku::setAttack(int atk) { attack = atk; }
void Goku::setDefense(int def) { defense = def; }
void Goku::setTurn(bool turn) { this->turn = turn; }
void Goku::setKi(int ki) { this->ki = ki; }
void Goku::setAbility(bool ab) { ability = ab; }
void Goku::setSuperSaiyan(bool ss)
{
	superSaiyan = ss;
	cout << "Superman goes Super Saiyan!!!\n";
}
void Goku::setBattleWon(int wins)
{
	battleWon = wins;
	if (battleWon == 2)
	{
		superSaiyan = true;
	}
}

void Goku::useSpecialAbility(Character& p2)
{
	cout << "Superman's ki: " << ki << endl;
	cout << "Superman Abilities:\n";
	cout << "1. Kamehameha(50 coins required)\n2. Instant Transmission(30 ki required)\n3. Super Saiyan(100 ki required)\n";
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (ki >= 50)
		{
			ki -= 50;
			p2.setHealth(p2.getHealth() - 50);
			cout << "Superman Uses Kamehameha!! Enemy hp -50\n";
		}
		else
			cout << "Not enough coins for this attack!\n";
		break;
	case 2:
		if (ki >= 30)
		{
			ki -= 30;
			defense += 10;
			p2.setHealth(p2.getHealth() - 30);
			cout << "Superman Uses Instant Transmission and blow a surprise attack!! Enemy hp -30, Superman's def +10\n";
		}
		else
			cout << "Not enough ki for this attack!\n";
		break;
	case 3:
		if (superSaiyan)
		{
			if (ki >= 100)
			{
				ki -= 100;
				SuperSaiyan saiyan("Super Saiyan Goku", GOKU, level += 3, health += 50, attack += 50, defense += 50, 1);
				cout << "Superman Becomes Super Saiyan!! +50 boost in all stats!\n";
				saiyan.useSpecialAbility(p2);
			}
			else
				cout << "Not enough coins for this attack!\n";
		}
		else
			cout << "Superman don't have enough experience to get Super Saiyan!\n";
		break;
	default:
		cout << "Invalid Input!\n";
	}
	ki += 50;
}
void Goku::attackTarget(Character& p2)
{
	int dmg = attack - p2.getDefense();
	if (dmg < 0)
	{
		cout << "Attack too weak!! Enemy's Defenses are high! Superman -20 hp\n";
		health -= 20;
		ki += 35;
	}
	else
	{
		p2.setHealth(p2.getHealth() - dmg);
		cout << "Superman attacked " << p2.getName() << " for " << dmg << " damage! +50 ki\n";
		ki += 50;
	}
	if (ki % 100 == 0)
	{
		level++;
		cout << "Superman Level up!\n";
		cout << "+20 boost in all stats\n";
		attack += 20;
		defense += 20;
		health += 20;
	}
}

//------------------------- Super Saiyan -------------------------\\

SuperSaiyan::SuperSaiyan(string name, CHARACTER type, int level, int health, int attack, int defense, int useLimit) : Goku(name, type, level, health, attack, defense)
{
	this->useLimit = useLimit;
}

void SuperSaiyan::setUseLimit(int limit)
{
	useLimit = limit;
	if (useLimit < 0)
	{
		useLimit = 0;
	}
}

void SuperSaiyan::useSpecialAbility(Character& p2)
{
	cout << "Super Saiyan Goku Used Kamehameha!!" << p2.getName() << " -" << attack - p2.getDefense() << " hp\n";
	p2.setHealth(p2.getHealth() - (attack - p2.getDefense()));
}

int SuperSaiyan::getUseLimit() const { return useLimit; }

void SuperSaiyan::setTurn(bool turn) { this->turn = turn; }

bool SuperSaiyan::getTurn() const { return turn; }

//------------------------- Gojo -------------------------\\

Gojo::Gojo(string name, CHARACTER type, int level, int health, int attack, int defense)
{
	this->name = name;
	this->type = type;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->limitlessTechnique = false;
	this->ability = false;
	this->battleWon = 0;
	curseEnergy = 0;
}

string Gojo::getName() const { return name; }
int Gojo::getLevel() const { return level; }
int Gojo::getHealth() const { return health; }
int Gojo::getAttack() const { return attack; }
bool Gojo::getTurn() const { return turn; }
int Gojo::getDefense() const { return defense; }
bool Gojo::getAbility()const { return ability; }
bool Gojo::getLimitlessTechnique()const { return limitlessTechnique; }
int Gojo::getBattleWon() const { return battleWon; }
CHARACTER Gojo::getType()const { return type; }

void Gojo::setName(const string n) { name = n; }
void Gojo::setLevel(int lvl) { level = lvl; }
void Gojo::setHealth(int hp) { health = hp; }
void Gojo::setAttack(int atk) { attack = atk; }
void Gojo::setDefense(int def) { defense = def; }
void Gojo::setAbility(bool ab) { ability = ab; }
void Gojo::setLimitlessTechnique(bool limit)
{
	limitlessTechnique = limit;
	cout << "Gojo's Limitless Technique is Activated!\n";
}
void Gojo::setBattleWon(int wins) { battleWon = wins; }
void Gojo::setTurn(bool turn) { this->turn = turn; }

void Gojo::useSpecialAbility(Character& p2)
{
	cout << "Gojo's Special Abilities: \n";
	cout << "1. Limitless Technique\n2. Hollow Purple\n3. Domain Expansion (requires limitless technique)\n";
	cout << "Enter Choice: ";
	int opt;
	cin >> opt;
	if (level % 3 == 0)
		limitlessTechnique = true;

	switch (opt)
	{
	case 1:
		if (limitlessTechnique)
		{
			defense += 100;
			health += 30;
			cout << "Gojo uses Limitless technique!! No one can touch him!! +100 def, +30 hp\n";
			limitlessTechnique = false;
		}
		else
			cout << "Limitless Technique not activated!\n";
		break;
	case 2:
		p2.setHealth(p2.getHealth() - 50);
		cout << "Gojo uses Hollow Purple by joining Repulsive Red and Attractive Blue resulting in an Imaginary Mass!!! " << p2.getName() << " -50 hp\n";
		break;
	case 3:
		if (level >= 3 && limitlessTechnique)
		{
			attack += 50;
			health += 50;
			defense += 50;
			p2.setHealth(p2.getHealth() - (attack - p2.getDefense()));
			cout << "Gojo: Domain Expansion Infinite Void\nGojo Used his Domain Expansion!! +50 boost in all stats!!\n";
			cout << p2.getName() << " -50 hp\n";
			limitlessTechnique = false;
		}
		else
			cout << "Cannot use Domain Expansion! Minimum Level Required is 3 and Limitless Technique Should be activated!\n";
		break;
	default:
		cout << "Invalid Input!\n";
	}
	curseEnergy += 50;
}
void Gojo::attackTarget(Character& p2)
{
	int dmg = attack - p2.getDefense();
	if (dmg < 0)
	{
		cout << "Attack too weak!! Enemy's Defenses are high! Gojo -20 hp\n";
		health -= 20;
		curseEnergy += 30;
	}
	else
	{
		p2.setHealth(p2.getHealth() - dmg);
		cout << "Gojo attacked " << p2.getName() << " for " << dmg << " damage!\n";
		curseEnergy += 50;
	}
	if (curseEnergy % 100 == 0)
	{
		level++;
		cout << "Gojo Level up!\n";
		cout << "+20 boost in all stats\n";
		attack += 20;
		defense += 20;
		health += 20;
	}
}

//------------------------- Levi -------------------------\\

Levi::Levi(string name, CHARACTER type, int level, int health, int attack, int defense)
{
	this->name = name;
	this->type = type;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->stamina = 100;
	this->fatigue = 0;
	this->ability = false;
	this->battleWon = 0;
}
string Levi::getName() const { return name; }
int Levi::getLevel() const { return level; }
int Levi::getHealth() const { return health; }
bool Levi::getTurn() const { return turn; }
int Levi::getAttack() const { return attack; }
int Levi::getDefense() const { return defense; }
int Levi::getStamina() const { return stamina; }
int Levi::getFatigue() const { return fatigue; }
bool Levi::getAbility()const { return ability; }
int Levi::getBattleWon() const { return battleWon; }
CHARACTER Levi::getType()const { return type; }

void Levi::setName(const string n) { name = n; }
void Levi::setLevel(int lvl) { level = lvl; }
void Levi::setHealth(int hp) { health = hp; }
void Levi::setAttack(int atk) { attack = atk; }
void Levi::setDefense(int def) { defense = def; }
void Levi::setAbility(bool ab) { ability = ab; }
void Levi::setBattleWon(int wins) { battleWon = wins; }
void Levi::setTurn(bool turn) { this->turn = turn; }
void Levi::setStamina(int newStamina)
{
	stamina = newStamina;
	if (stamina < 0)
		stamina = 0;
}

void Levi::setFatigue(int newFatigue)
{
	fatigue = newFatigue;
	if (fatigue > 100)
		fatigue = 100;
}

void Levi::useSpecialAbility(Character& p2)
{
	cout << "Joker's special abilities:\n";
	cout << "1. Thunder Spare\n2. Rage\n";
	cout << "Enter choice: ";
	int opt;
	cin >> opt;
	switch (opt)
	{
	case 1:
		p2.setHealth(p2.getHealth() - 50);
		cout << "Joker Uses Thunder Spere!! " << p2.getName() << " -50 hp\n";
		break;
	case 2:
		p2.setHealth(p2.getHealth() - 40);
		cout << "Joker got Rage!! " << p2.getName() << " -40 hp\n";
		break;
	default:
		cout << "Invalid Input!\n";
	}
}
void Levi::attackTarget(Character& p2)
{
	int dmg = attack - p2.getDefense();
	if (dmg < 0)
	{
		cout << "Attack too weak!! Enemy's Defenses are high! Joker -20 hp\n";
		health -= 20;
	}
	else
	{
		p2.setHealth(p2.getHealth() - dmg);
		cout << "Joker attacked " << p2.getName() << " for " << dmg << " damage!\n";
	}
}

//------------------------- Operator Overloading -------------------------\\

bool Character::operator ==(Character& p2)
{
	int p1Power, p2Power;
	p1Power = (attack + defense + health) * level;
	p2Power = (p2.attack + p2.defense + p2.health) * p2.level;
	return p1Power == p2Power;
}
bool Character::operator >(Character& p2)
{
	int p1Power, p2Power;
	p1Power = (attack + defense + health) * level;
	p2Power = (p2.attack + p2.defense + p2.health) * p2.level;
	return p1Power > p2Power;
}

Character& Character::operator -(Character& p2)
{
	health += 10;
	p2.health -= 10;
	return *this;
}