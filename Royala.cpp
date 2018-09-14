
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include <cstdlib>
#include <random>
void pText(std::string text);
void Text(std::string text);
void getWord(std::string &renamed);
void vendor(Player &a, std::string greeting);
void fight(std::string intro, Player &a, Enemy &b);

int main()
{
	pText("Welcome to the world of Royala!");
	pText("Prepare to face the ardous world of Royala as you attempt to save your father!");
	pText("A dark knight has stolen him from you, and you must find him before his soup gets cold!");
	Text("Before we begin, enter your name.");
	std::string name;
	getWord(name);
	Player a(name, 30, 10, 10, 30, 10, 10, 20, 0, 0, 0);
	pText("Ah, " + a.getName() + ", " + "an excellent name!");
	Enemy b("bear", 10, 10, 10, 10, 10, 10, 5);
	fight("A " + b.getName() + " attacks!", a, b);
	// Start coding sequence of events, array of choices and stuff
	return 0;
}

void pText(std::string text) 
{
	std::cout << text << "\n" << std::endl;
	std::cout << "Press Enter to Continue" << std::endl;
	std::cin.ignore();
	system("cls");
}

void Text(std::string text)
{
	std::cout << text << std::endl;
}

void getWord(std::string &renamed)
{
	std::getline(std::cin, renamed);
	system("cls");
}

void vendor(Player &a, std::string greeting) 
{
	pText(greeting);
	std::string vendChoice;
	bool vend = true;
	while (vend) 
	{
		Text("Please make your selection \nHealth Potion(Enter 1): \t10 dollars \nStamina Potion(Enter 2): \t10 dollars \nMagic Potion(Enter 3): \t\t10 dollars \nExit(Enter 4):\n");
		Text("Current:\nMoney: \t\t\t\t" + std::to_string(a.getMoney()));
		Text("Health Potions: \t\t" + std::to_string(a.getHealthPotion()));
		Text("Stamina Potions: \t\t" + std::to_string(a.getStaminaPotion()));
		Text("Magic Potions: \t\t\t" + std::to_string(a.getMagicPotion()));
		getWord(vendChoice);
		if (vendChoice.compare("1") == 0)
		{
			if (a.getMoney() >= 10)
			{
				pText("A wonderful selection!");
				a.minusMoney(10);
				a.minusHealthPotion(-1);
			}
			else
			{
				pText("You don't have enough money!");
			}
		}
		if (vendChoice.compare("2") == 0)
		{
			if (a.getMoney() >= 10)
			{
				pText("A wonderful selection!");
				a.minusMoney(10);
				a.minusStaminaPotion(-1);
			}
			else
			{
				pText("You don't have enough money!");
			}
		}
		if (vendChoice.compare("3") == 0)
		{
			if (a.getMoney() >= 10)
			{
				pText("A wonderful selection!");
				a.minusMoney(10);
				a.minusMagicPotion(-1);
			}
			else
			{
				pText("You don't have enough money!");
			}
		}
		if (vendChoice.compare("4") == 0)
		{
			pText("See you next time! Safe travels!");
			vend = false;
		}
	}
}

void fight(std::string intro, Player &a, Enemy &b)
{
	pText(intro);
	pText("Prepare for battle!");
	std::string battleChoice;
	bool won = false;
	bool lost = false;
	while (true)
	{
		Text("Select an option:\n");
		Text("Attack: \t(Enter 1)\nRest: \t\t(Enter 2)\nMagic: \t\t(Enter 3)\n");
		Text("Your Stats:\n");
		Text("Health: \t" + std::to_string(a.getHealth()));
		Text("Stamina: \t" + std::to_string(a.getStamina()));
		Text("Magic: \t\t" + std::to_string(a.getMagic()));
		Text("\n");
		Text("Enemy Stats:\n");
		Text("Health: \t" + std::to_string(b.getHealth()));
		Text("Stamina: \t" + std::to_string(b.getStamina()));
		Text("Magic: \t\t" + std::to_string(b.getMagic()));
		Text("\n");
		getWord(battleChoice);
		if (battleChoice.compare("1") == 0)
		{
			int playerDamage = a.getPhysicalDamageTakeStam();
			int enemyDamage;
			int enemyRegain = 0;
			pText("You did " + std::to_string(playerDamage) + " damage!");
			b.minusHealth(playerDamage);
			if (b.getHealth() == 0) {
				won = true;
				break;
			}
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina!");
			}
			a.minusHealth(enemyDamage);
			if (a.getHealth() == 0)
			{
				lost = true;
				break;
			}
		}
		if (battleChoice.compare("2") == 0)
		{
			int regain = a.regainStam();
			int enemyDamage;
			int enemyRegain = 0;
			pText("You gained " + std::to_string(regain) + " stamina!");
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina!");
			}
			a.minusHealth(enemyDamage);
			if (a.getHealth() == 0)
			{
				lost = true;
				break;
			}
		}
		if (battleChoice.compare("3") == 0)
		{
			int playerDamage = a.getMagicDamageTakeMagic();
			int enemyDamage;
			int enemyRegain = 0;
			b.minusHealth(playerDamage);
			pText("You did " + std::to_string(playerDamage) + " damage!");
			b.minusHealth(playerDamage);
			if (b.getHealth() == 0) {
				won = true;
				break;
			}
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina!");
			}
			a.minusHealth(enemyDamage);
			if (a.getHealth() == 0)
			{
				lost = true;
				break;
			}
		}
	}
	if (won)
	{
		pText("You have slayed the " + b.getName() + "!");
	}
	if (lost)
	{
		pText("The " + b.getName() + " has killed you! You must try again!");
		main();
	}

}

