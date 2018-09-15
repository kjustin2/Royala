#include "Player.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>


Player::Player(std::string name, int health, int stamina, int magic, int maxHealth, int maxStamina, int maxMagic, int money, int healthPotion, int staminaPotion, int magicPotion, int role)
	: money(money), healthPotion(healthPotion), staminaPotion(staminaPotion), magicPotion(magicPotion), role(role), Character(name, health, stamina, magic, maxHealth, maxStamina, maxMagic){}

Player::Player() {}

int Player::getMoney()
{
	return money;
}

void Player::minusMoney(int change)
{
	money -= change;
}

void Player::setMoney(int change)
{
	money = change;
}

int Player::getHealthPotion()
{
	return healthPotion;
}

void Player::minusHealthPotion(int change)
{
	healthPotion -= change;
}

void Player::setHealthPotion(int change)
{
	healthPotion = change;
}

int Player::getStaminaPotion()
{
	return staminaPotion;
}

void Player::minusStaminaPotion(int change)
{
	staminaPotion -= change;
}

void Player::setStaminaPotion(int change)
{
	staminaPotion = change;
}

int Player::getMagicPotion()
{
	return magicPotion;
}

void Player::minusMagicPotion(int change)
{
	magicPotion -= change;
}

void Player::setMagicPotion(int change)
{
	magicPotion = change;
}

void Player::useHealthPotion()
{
	minusHealthPotion(1);
	minusHealth(-10);
}

void Player::useStaminaPotion()
{
	minusStaminaPotion(1);
	minusStamina(-10);
}

void Player::useMagicPotion()
{
	minusMagicPotion(1);
	minusMagic(-10);
}

int Player::regainStamHealth()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 8);
	int regained = -(distr(eng));
	minusStamina(regained);
	minusHealth(regained);
	return -regained;
}

int Player::getRole()
{
	return role;
}

int Player::regainOther()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr2(0, 7);
	std::uniform_int_distribution<> distr(0, 4);
	int regained = 0;
	minusStamina(regained);
	if (role == 0) 
	{
		regained = -(distr(eng));
		minusHealth(regained);
	}
	if (role == 1)
	{
		regained = -(distr2(eng));
		minusStamina(regained);
	}
	if (role == 2)
	{
		regained = -(distr2(eng));
		minusMagic(regained);
	}
	return -regained;
}

