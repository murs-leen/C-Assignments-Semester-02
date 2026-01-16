#pragma once

#include<iostream>
#include<string>
using namespace std;

enum CHARACTER { GOKU, GOJO, LEVI };

class Character
{
protected:
	string name;
	int level;
	int health;
	int attack;
	int defense;
	bool ability;
	bool turn;
	CHARACTER type;
	int battleWon;
public:
	virtual string getName() const = 0;
	virtual int getLevel() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual int getDefense() const = 0;
	virtual bool getAbility()const = 0;
	virtual bool getTurn()const = 0;
	virtual int getBattleWon() const = 0;
	virtual CHARACTER getType()const = 0;
	virtual int getKi() const = 0;
	virtual bool getSuperSaiyan() const = 0;
	virtual bool getLimitlessTechnique() const = 0;
	virtual int getStamina() const = 0;
	virtual int getFatigue() const = 0;
	virtual int getUseLimit() const = 0;

	virtual void setKi(int ki) = 0;
	virtual void setSuperSaiyan(bool ss) = 0;
	virtual void setLimitlessTechnique(bool limit) = 0;
	virtual void setStamina(int stamina) = 0;
	virtual void setFatigue(int fatigue) = 0;
	virtual void setUseLimit(int limit) = 0;
	virtual void setName(const string n) = 0;
	virtual void setLevel(int lvl) = 0;
	virtual void setHealth(int hp) = 0;
	virtual void setAttack(int hp) = 0;
	virtual void setDefense(int def) = 0;
	virtual void setTurn(bool turn) = 0;
	virtual void setAbility(bool ab) = 0;
	virtual void setBattleWon(int wins) = 0;

	virtual void useSpecialAbility(Character& player) = 0;
	virtual void attackTarget(Character& cPtr) = 0;
	bool operator ==(Character& player);
	bool operator >(Character& player);
	Character& operator -(Character& player);
	virtual ~Character() = default;
};

class Goku :virtual public Character
{
protected:
	int ki;
	bool superSaiyan;
public:
	Goku(string name, CHARACTER type, int level, int health, int attack, int defense);
	string getName() const override;
	int getLevel() const override;
	int getHealth() const override;
	int getAttack() const override;
	int getDefense() const override;
	bool getTurn() const override;
	int getKi() const override;
	bool getAbility() const override;
	bool getSuperSaiyan() const override;
	int getBattleWon() const override;
	CHARACTER getType() const override;

	void setName(const string n) override;
	void setLevel(int lvl) override;
	void setHealth(int hp) override;
	void setAttack(int hp) override;
	void setDefense(int def) override;
	void setKi(int ki) override;
	void setAbility(bool ab) override;
	void setTurn(bool turn) override;
	void setSuperSaiyan(bool ss) override;
	void setBattleWon(int wins) override;

	void useSpecialAbility(Character& player) override;
	void attackTarget(Character& cPtr) override;

	//empty functions
	bool getLimitlessTechnique() const override { return false; }
	int getStamina() const override { return 0; }
	int getFatigue() const override { return 0; }
	int getUseLimit() const override { return 0; }

	void setLimitlessTechnique(bool) override {}
	void setUseLimit(int limit) override {}
	void setStamina(int) override {}
	void setFatigue(int) override {}
	~Goku() override = default;
};

class SuperSaiyan :public Goku
{
	int useLimit;
public:
	SuperSaiyan(string name, CHARACTER type, int level, int health, int attack, int defense, int useLimit);

	void setUseLimit(int limit) override;
	void setTurn(bool turn) override;

	int getUseLimit() const override;
	bool getTurn() const override;
	~SuperSaiyan() override = default;

	void useSpecialAbility(Character& player) override;
};

class Gojo :public Character
{
	bool limitlessTechnique;
	int curseEnergy;
public:
	Gojo(string name, CHARACTER type, int level, int health, int attack, int defense);
	string getName() const override;
	int getLevel() const override;
	int getHealth() const override;
	int getAttack() const override;
	int getDefense() const override;
	bool getTurn() const override;
	bool getAbility() const override;
	bool getLimitlessTechnique() const override;
	int getBattleWon() const override;
	CHARACTER getType() const override;

	void setName(const string n) override;
	void setLevel(int lvl) override;
	void setHealth(int hp) override;
	void setAttack(int hp) override;
	void setDefense(int def) override;
	void setTurn(bool turn) override;
	void setAbility(bool ab) override;
	void setLimitlessTechnique(bool limit) override;
	void setBattleWon(int wins) override;

	void useSpecialAbility(Character& player) override;
	void attackTarget(Character& cPtr) override;

	//empty functions
	int getKi() const override { return 0; }
	bool getSuperSaiyan() const override { return false; }
	int getStamina() const override { return 0; }
	int getFatigue() const override { return 0; }
	int getUseLimit() const override { return 0; }
	void setKi(int) override {}
	void setSuperSaiyan(bool) override {}
	void setStamina(int) override {}
	void setFatigue(int) override {}
	void setUseLimit(int) override {}
	~Gojo() override = default;
};

class Levi :public Character
{
	int stamina;
	int fatigue;
public:
	Levi(string name, CHARACTER type, int level, int health, int attack, int defense);
	string getName() const override;
	int getLevel() const override;
	int getHealth() const override;
	int getAttack() const override;
	int getDefense() const override;
	int getStamina() const override;
	int getFatigue() const override;
	bool getAbility() const override;
	bool getTurn() const override;
	int getBattleWon() const override;
	CHARACTER getType() const override;

	void setName(const string n) override;
	void setLevel(int lvl) override;
	void setHealth(int hp) override;
	void setAttack(int hp) override;
	void setDefense(int def) override;
	void setStamina(int stamina) override;
	void setFatigue(int fatigue) override;
	void setTurn(bool turn) override;
	void setAbility(bool ab) override;
	void setBattleWon(int wins) override;

	void useSpecialAbility(Character& player) override;
	void attackTarget(Character& cPtr) override;

	//empty functions
	int getKi() const override { return 0; }
	bool getSuperSaiyan() const override { return false; }
	bool getLimitlessTechnique() const override { return false; }
	int getUseLimit() const override { return 0; }
	void setKi(int) override {}
	void setSuperSaiyan(bool) override {}
	void setLimitlessTechnique(bool) override {}
	void setUseLimit(int) override {}
	~Levi() override = default;
};