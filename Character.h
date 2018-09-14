#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
class Character
{
	std::string name;
	int health;
	int stamina;
	int magic;
	int maxHealth;
	int maxStamina;
	int maxMagic;

public:
	Character(std::string name, int health, int stamina, int magic, int maxHealth, int maxStamina, int maxMagic);
	std::string getName();
	int getHealth();
	void minusHealth(int change);
	void setHealth(int change);
	int getStamina();
	void minusStamina(int change);
	void setStamina(int change);
	int getMagic();
	void minusMagic(int change);
	void setMagic(int change);
	int getMaxHealth();
	void minusMaxHealth(int change);
	void setMaxHealth(int change);
	int getMaxStamina();
	void minusMaxStamina(int change);
	void setMaxStamina(int change);
	int getMaxMagic();
	void minusMaxMagic(int change);
	void setMaxMagic(int change);
	int getPhysicalDamageTakeStam();
	int getMagicDamageTakeMagic();
};

#endif CHARACTER_H

