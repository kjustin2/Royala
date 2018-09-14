#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Character.h"
#include <random>
class Enemy : public Character
{
	int magicChance;

public:
	Enemy(std::string name, int health, int stamina, int magic, int maxHealth, int maxStamina, int maxMagic, int magicChance);
	
	int getMagicChance();
	void minusMagicChance(int change);
	void setMagicChance(int change);
	bool doMagic();
	int regainStamAuto();
};

#endif PLAYER_H

