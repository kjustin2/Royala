#include "Enemy.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>


Enemy::Enemy(std::string name, int health, int stamina, int magic, int maxHealth, int maxStamina, int maxMagic, int magicChance)
	: magicChance(magicChance), Character(name, health, stamina, magic, maxHealth, maxStamina, maxMagic) {}

Enemy::Enemy() {}

int Enemy::getMagicChance()
{
	return magicChance;
}

void Enemy::minusMagicChance(int change)
{
	magicChance -= change;
}

void Enemy::setMagicChance(int change)
{
	magicChance = change;
}

bool Enemy::doMagic()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, getMagicChance());
	if (distr(eng) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Enemy::regainStamMagicAuto()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 6);
	int regained = -(distr(eng));
	minusStamina(regained);
	minusMagic(regained);
	return -regained;
}
