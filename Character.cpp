#include "Character.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>

Character::Character(std::string name, int health, int stamina, int magic, int maxHealth, int maxStamina, int maxMagic)
:name(name), health(health), stamina(stamina), magic(magic), maxHealth(maxHealth), maxStamina(maxStamina), maxMagic(maxMagic){}

Character::Character() {}

std::string Character::getName() 
{
	return name;
}

int Character::getHealth()
{
	return health;
}

void Character::minusHealth(int change)
{
	health -= change;
	if (health > maxHealth) 
	{
		health = maxHealth;
	}
	if (health < 0) {
		health = 0;
	}
}

void Character::setHealth(int change)
{
	health = change;
}

int Character::getStamina()
{
	return stamina;
}

void Character::minusStamina(int change)
{
	stamina -= change;
	if (stamina > maxStamina)
	{
		stamina = maxStamina;
	}
	if (stamina < 0) 
	{
		stamina = 0;
	}
}

void Character::setStamina(int change)
{
	stamina = change;
}

int Character::getMagic()
{
	return magic;
}

void Character::minusMagic(int change)
{
	magic -= change;
	if (magic > maxMagic)
	{
		magic = maxMagic;
	}
	if (magic < 0) 
	{
		magic = 0;
	}
}

void Character::setMagic(int change)
{
	magic = change;
}

int Character::getMaxHealth()
{
	return maxHealth;
}

void Character::minusMaxHealth(int change)
{
	maxHealth -= change;
}

void Character::setMaxHealth(int change)
{
	maxHealth = change;
}

int Character::getMaxStamina()
{
	return maxStamina;
}

void Character::minusMaxStamina(int change)
{
	maxStamina -= change;
}

void Character::setMaxStamina(int change)
{
	maxStamina = change;
}

int Character::getMaxMagic()
{
	return maxMagic;
}

void Character::minusMaxMagic(int change)
{
	maxMagic -= change;
}

void Character::setMaxMagic(int change)
{
	maxMagic = change;
}

int Character::getPhysicalDamageTakeStam()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, getStamina());
	int dmg = distr(eng);
	minusStamina(dmg);
	return dmg;
}

int Character::getMagicDamageTakeMagic()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, (getMagic()/2));
	int dmg = distr(eng);
	minusMagic(dmg);
	std::random_device rd2;
	std::mt19937 eng2(rd2());
	std::uniform_int_distribution<> distr2(1, 3);
	int randomFactor = distr2(eng2);
	// Returning random from (1,3) times the damage since magic does more damage, it's harder to recover than stamina because there's no rest button
	return (dmg * randomFactor);
}