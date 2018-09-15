#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <random>
#include "Character.h"
class Player: public Character
{
	int money;
	int healthPotion;
	int staminaPotion;
	int magicPotion;
	int role;

public:
	Player(std::string name, int health, int stamina, int magic, int maxHealth, int maxStamina, int maxMagic, int money, int healthPotion, int staminaPotion, int magicPotion, int role);
	Player();
	int getMoney();
	void minusMoney(int change);
	void setMoney(int change);
	int getHealthPotion();
	void minusHealthPotion(int change);
	void setHealthPotion(int change);
	int getStaminaPotion();
	void minusStaminaPotion(int change);
	void setStaminaPotion(int change);
	int getMagicPotion();
	void minusMagicPotion(int change);
	void setMagicPotion(int change);
	void useHealthPotion();
	void useStaminaPotion();
	void useMagicPotion();
	int regainStamHealth();
	int getRole();
	int regainOther();
};

#endif PLAYER_H
