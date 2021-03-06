
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
void vendor(Player &a);
void fight(std::string intro, Player &a, Enemy &b, int gainMoney);
int askChoice(std::string intro);
void runPathLoop(int *money, Enemy *enemies, std::string *intros, std::string *enemyLines, int pathLength, Player &thePlayer);
bool vendOn = true;

int main()
{
	pText("Welcome to the world of Royala!");
	pText("Prepare to face the ardous world of Royala as you attempt to save your father!");
	pText("A dark knight has stolen him from you, and you must find him before his soup gets cold!");
	Text("Before we begin, enter your name.");
	std::string name;
	std::string response1;
	Player mainChar;
	// intro 1 
	Enemy hawk("hawk", 6, 4, 2, 6, 4, 2, 8);
	Enemy armadillo("armadillo", 8, 6, 0, 8, 6, 0, 0);
	Enemy rock("rock monster", 10, 4, 2, 10, 4, 2, 7);
	Enemy bigRock("rock king", 13, 4, 5, 13, 4, 5, 6);
	// intro 2 
	Enemy bear("bear", 6, 4, 2, 6, 4, 2, 0);
	Enemy hoodedMan("hooded man", 8, 4, 2, 8, 4, 2, 6);
	Enemy serpent("serpent", 10, 4, 2, 10, 4, 2, 7);
	Enemy monkey("monkey", 14, 6, 2, 14, 6, 2, 7);
	// second 1
	Enemy waterSnake("water snake", 10, 7, 0, 10, 7, 0, 0);
	Enemy tortoise("tortoise", 14, 4, 2, 14, 4, 2, 7);
	Enemy eagle("eagle", 14, 6, 3, 14, 6, 3, 5);
	Enemy whale("whale", 25, 7, 0, 25, 7, 0, 0);
	// second 2
	Enemy scorpion("scorpion", 11, 6, 0, 11, 6, 0, 0);
	Enemy mummy("mummy", 12, 6, 2, 12, 6, 2, 1);
	Enemy pyramidGuard("pyramid guard", 15, 7, 1, 15, 7, 1, 8);
	Enemy dragon("dragon", 20, 7, 5, 20, 7, 5, 4);
	// third 1
	Enemy zombie("zombie", 17, 6, 4, 17, 6, 4, 5);
	Enemy ruinedCar("ruined car", 20, 9, 0, 20, 9, 0, 0);
	Enemy largeZombie("large zombie", 20, 7, 5, 20, 7, 5, 6);
	Enemy zombieKing("King zombie", 25, 12, 0, 25, 12, 0, 0);
	// third 2
	Enemy cultist("cultist", 15, 7, 5, 15, 7, 5, 7);
	Enemy cultGuard("cult guard", 22, 5, 2, 22, 5, 2, 4);
	Enemy raven("raven", 25, 7, 0, 25, 7, 0, 0);
	Enemy weirdMan("Unknown man", 15, 12, 10, 15, 12, 10, 2);
	// final
	Enemy towerGuard("tower guard", 25, 9, 0, 25, 9, 0, 0);
	Enemy dinnerLeader("dinner leader", 25, 8, 3, 25, 8, 3, 4);
	Enemy trainedBear("trained bear", 27, 7, 4, 27, 7, 4, 5);
	Enemy kingGuard("King's guard", 25, 12, 5, 25, 12, 5, 3);
	Enemy king("The King", 35, 7, 5, 35, 7, 5, 2);
	Enemy royala("ROYALA", 35, 17, 10, 35, 17, 10, 1);
	int introMoney[4] = { 5, 5, 5, 10 };
	int secondMoney[4] = { 8, 8, 8, 20 };
	int thirdMoney[4] = { 10, 10, 10, 25 };
	int finalMoney[6] = { 15, 15, 15, 15, 30, 30 };
	std::string intro1Story[5] = { "You begin walking down the road, whistling to yourself.", "You see a hill ahead and you follow the road up it.", "After the hill, you descend into a rocky valley.", "You can see a clearance past the next set of rocks.", "You arrive out of the rocky valley."};
	std::string intro2Story[5] = { "You enter the woods, and suddenly darkness descends.", "You continue through the woods, looking behind your shoulder.", "You see a river ahead and decide to swim across it.", "You climb up a tree to look around and you can see an exit past the next turn.", "You arrive at the end of the forest." };
	std::string second1Story[5] = { "You hop on a nearby boat and began paddling.", "The river becomes rough and waves splash your face.", "The water suddenly speeds up into a current.", "You see a waterfall ahead and you can't escape it!", "You jump onto the land, your clothes soaked." };
	std::string second2Story[5] = { "You see nothing around you in the sandy desert.", "A pyramid appears in the horizon.", "You reach the pyramid and see an entrance.", "You climb to the top and think about sliding down the side.", "You slide down the pyramid \nand the desert fades." };
	std::string third1Story[5] = { "You enter the city, but nobody is around.", "You enter a small shop that used to sell tires.", "You exit the shop and head for a large black tower.", "You get closer to the tower and start to hear something odd.", "You recognize the voice in \nthe tower as your father's!" };
	std::string third2Story[5] = { "You go into the suburban town and something smells odd.", "You get overwhelmed by other cultists and wake up in a cell.", "You escape your prison, but you're not sure where you are.", "You notice a gigantic black \ntower near you and start walking towards it.", "You can hear your father in the tower!" };
	std::string finalStory[7] = { "Outside the tower a guard stands.", "You enter the tower and face a room of people dressed royally.", "The room clears and you start walking up the grand staircase.", "You enter the main ballroom \nand see your father strapped to a chair.", "The King's guard is gone, and the King stands.", "The King falls, but someone descends from a bright \nlight in the ceiling when you try to \nuntie your father", "You untie your father and go home!" };
	std::string intro1Enemy[4] = { "Suddenly, a hawk tries to swipe at you!", "Then, you see a giant armadillo rolling towards you!", "A rock comes to life and strikes you!", "Instantly, another rock monster appears in your way!" };
	std::string intro2Enemy[4] = { "Suddenly, a bear jumps out at you!", "A hooded man appears from a tree and attacks!", "All at once, a serpent wraps around you!", "Then, a savage monkey bites you!" };
	std::string second1Enemy[4] = { "A water snake then jumps onto your boat!", "As the river becomes rough, a large tortoise slaps you!", "An eagle swoops at you as you ride the current!", "As you fall down the waterfall, a whale falls with you and attacks!" };
	std::string second2Enemy[4] = { "Then, a scorpion tries to sting you!", "You see something running at you from the pyramid. It's a mummy!", "A guard stands at the entrance and \nsays you must fight him to enter!", "At the top of the pyramid, \na massive dragon rises from the sand and flies towards you!" };
	std::string third1Enemy[4] = { "Out of nowhere, a zombie charges you!", "In the corner of the small shop, \na ruined car comes to life and drives at you!", "As you head for the tower, \na humongous zombie leaps at you!", "Ignoring the sound, you walk on. \nThen, a Zombie King appears!" };
	std::string third2Enemy[4] = { "A group of cultists appear \nfrom one of the homes and try to bite you!", "You break out of the cell and a guard attacks!", "Out of nowhere, a raven swoops down to attack!", "A man stops you and tells you to turn around, \nbut you don't. He then tries to stab you!" };
	std::string finalEnemy[6] = { "The guard demands you die!", "The leader of the dinner addresses you \nand attacks you for ruining his dinner!", "A trained bear comes down \nthe stairs and fights you!", "The King's guard says it is your time to die!", "The King instantly teleports to you and swings \nhis sword in one swift motion! \nYou barely dodge it and prepare to fight!", "I AM ROYALA, GOD OF THIS KINGDOM. \nYOUR FATHER IS A SACRIFICE I MUST HAVE. \nYOU WILL NOW DIE!" };
	Enemy intro1[4] = { hawk, armadillo, rock, bigRock };
	Enemy intro2[4] = { bear, hoodedMan, serpent, monkey };
	Enemy second1[4] = { waterSnake, tortoise, eagle, whale };
	Enemy second2[4] = { scorpion, mummy, pyramidGuard, dragon };
	Enemy third1[4] = { zombie, ruinedCar, largeZombie, zombieKing };
	Enemy third2[4] = { cultist, cultGuard, raven, weirdMan };
	Enemy final1[6] = { towerGuard, dinnerLeader, trainedBear, kingGuard, king, royala };
	getWord(name);
	pText("Ah, " + name + ", " + "an excellent name!");
	while (true) 
	{
		Text("Now, would you like to be a warrior(1), archer(2), or wizard(3)?");
		getWord(response1);
		if (response1.compare("1") == 0)
		{
			Player mainChar2(name, 40, 15, 5, 40, 15, 5, 0, 0, 0, 0, 0);
			mainChar = mainChar2;
			pText("A proud warrior! Great health and good damage, with little knowledge of magic.\nGain health each rest.");
			break;
		}
		if (response1.compare("2") == 0)
		{
			Player mainChar2(name, 30, 20, 10, 30, 20, 10, 0, 0, 0, 0, 1);
			mainChar = mainChar2;
			pText("A cunning archer! Good health and great damage, with little knowledge of magic.\nGain more stamina each rest.");
			break;
		}
		if (response1.compare("3") == 0)
		{
			Player mainChar2(name, 30, 10, 20, 30, 10, 20, 0, 0, 0, 0, 2);
			mainChar = mainChar2;
			pText("A wise wizard! Little health and good damage, with great knowledge of magic.\nGain magic each rest.");
			break;
		}
	}
	int firstDecision = askChoice("You leave your house to begin your quest!\nDo you want to take the road(Enter 1) or the forest(Enter 2)?");
	if (firstDecision == 1) {
		runPathLoop(introMoney, intro1, intro1Story, intro1Enemy, 4, mainChar);
	}
	else
	{
		runPathLoop(introMoney, intro2, intro2Story, intro2Enemy, 4, mainChar);
	}
	int secondDecision = askChoice("You see two paths ahead now!\nDo you want to take the river(Enter 1) or the desert(Enter 2)?");
	if (secondDecision == 1) {
		runPathLoop(secondMoney, second1, second1Story, second1Enemy, 4, mainChar);
	}
	else
	{
		runPathLoop(secondMoney, second2, second2Story, second2Enemy, 4, mainChar);
	}
	int thirdDecision = askChoice("You see two paths ahead now!\nDo you want to take the city route(Enter 1) or the suburbs(Enter 2)?");
	if (thirdDecision == 1) {
		runPathLoop(thirdMoney, third1, third1Story, third1Enemy, 4, mainChar);
	}
	else
	{
		runPathLoop(thirdMoney, third2, third2Story, third2Enemy, 4, mainChar);
	}
	runPathLoop(finalMoney, final1, finalStory, finalEnemy, 6, mainChar);
	pText("YOU WIN!!!");
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

void vendor(Player &a) 
{
	pText("Welcome to the shop!");
	std::string vendChoice;
	bool vend = true;
	while (vend) 
	{
		Text("Please make your selection \nHealth Potion(Enter 1): \t12 dollars \nStamina Potion(Enter 2): \t10 dollars \nMagic Potion(Enter 3): \t\t20 dollars \nExit(Enter 4):\n");
		Text("Current:\nMoney: \t\t\t\t" + std::to_string(a.getMoney()));
		Text("Health Potions: \t\t" + std::to_string(a.getHealthPotion()));
		Text("Stamina Potions: \t\t" + std::to_string(a.getStaminaPotion()));
		Text("Magic Potions: \t\t\t" + std::to_string(a.getMagicPotion()));
		getWord(vendChoice);
		if (vendChoice.compare("1") == 0)
		{
			if (a.getMoney() >= 12)
			{
				pText("A wonderful selection!");
				a.minusMoney(12);
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
			if (a.getMoney() >= 20)
			{
				pText("A wonderful selection!");
				a.minusMoney(20);
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

void fight(std::string intro, Player &a, Enemy &b, int gainMoney)
{
	pText(intro);
	pText("Prepare for battle!");
	std::string battleChoice;
	bool won = false;
	bool lost = false;
	while (true)
	{
		Text("Select an option:\n");
		Text("Attack: \t(Enter 1)\nRest: \t\t(Enter 2)\nMagic: \t\t(Enter 3)\nHealth Potion: \t(Enter 4)\nStamina Potion: (Enter 5)\nMagic Potion: \t(Enter 6)\n");
		Text("Your Stats:\n");
		Text("Health: \t" + std::to_string(a.getHealth()));
		Text("Stamina: \t" + std::to_string(a.getStamina()));
		Text("Magic: \t\t" + std::to_string(a.getMagic()));
		Text("Health Potion: \t" + std::to_string(a.getHealthPotion()));
		Text("Stamina Potion: " + std::to_string(a.getStaminaPotion()));
		Text("Magic Potion: \t" + std::to_string(a.getMagicPotion()));
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
				enemyRegain = b.regainStamMagicAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina and magic!");
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
			int regain = a.regainStamHealth();
			int regain2 = a.regainOther();
			int enemyDamage;
			int enemyRegain = 0;
			if (a.getRole() == 0)
			{
				pText("You gained " + std::to_string(regain) + " stamina!\nYou gained " + std::to_string(regain2+regain) + " health!");
			}
			if (a.getRole() == 1)
			{
				pText("You gained " + std::to_string(regain+regain2) + " stamina!\nYou gained " + std::to_string(regain) + "health");
			}
			if (a.getRole() == 2)
			{
				pText("You gained " + std::to_string(regain) + " stamina and health!\nYou gained " + std::to_string(regain2) + " magic!");
			}
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamMagicAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina and magic!");
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
				enemyRegain = b.regainStamMagicAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina and magic!");
			}
			a.minusHealth(enemyDamage);
			if (a.getHealth() == 0)
			{
				lost = true;
				break;
			}
		}
		if (battleChoice.compare("4") == 0)
		{
			if (a.getHealthPotion() > 0)
			{
				a.useHealthPotion();
				pText("You gained 10 health!");
			}
			else
			{
				pText("You have no health potions!");
			}
			int enemyDamage;
			int enemyRegain = 0;
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamMagicAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina and magic!");
			}
			a.minusHealth(enemyDamage);
			if (a.getHealth() == 0)
			{
				lost = true;
				break;
			}
		}
		if (battleChoice.compare("5") == 0)
		{
			if (a.getStaminaPotion() > 0)
			{
				a.useStaminaPotion();
				pText("You gained 10 stamina!");
			}
			else
			{
				pText("You have no stamina potions!");
			}
			int enemyDamage;
			int enemyRegain = 0;
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamMagicAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina and magic!");
			}
			a.minusHealth(enemyDamage);
			if (a.getHealth() == 0)
			{
				lost = true;
				break;
			}
		}
		if (battleChoice.compare("6") == 0)
		{
			if (a.getMagicPotion() > 0)
			{
				a.useMagicPotion();
				pText("You gained 10 magic!");
			}
			else
			{
				pText("You have no magic potions!");
			}
			int enemyDamage;
			int enemyRegain = 0;
			if (b.doMagic())
			{
				enemyDamage = b.getMagicDamageTakeMagic();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage with a magic attack!");
			}
			else
			{
				enemyDamage = b.getPhysicalDamageTakeStam();
				enemyRegain = b.regainStamMagicAuto();
				pText("The " + b.getName() + " did " + std::to_string(enemyDamage) + " damage!\n" + "And regained " + std::to_string(enemyRegain) + " stamina and magic!");
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
		a.minusMoney(-gainMoney);
		pText("You gained " + std::to_string(gainMoney) + " dollars!");
	}
	if (lost)
	{
		pText("The " + b.getName() + " has killed you! You must try again!");
		main();
	}

}

int askChoice(std::string intro)
{
	std::string choice1;
	while (true)
	{
		Text(intro);
		getWord(choice1);
		if (choice1.compare("1") == 0) {
			return 1;
		}
		if (choice1.compare("2") == 0)
		{
			return 2;
		}
	}
	return 0;
}

void runPathLoop(int *money, Enemy *enemies, std::string *intros, std::string *enemyLines, int pathLength, Player &thePlayer)
{
	int mo = 0;
	for (; mo < pathLength; mo++) {
		pText(intros[mo]);
		fight(enemyLines[mo], thePlayer, enemies[mo], money[mo]);
		if ((!(pathLength == 6)) && (!(mo == 5)))
		{
			pText("A man appears out of smoke!");
			vendor(thePlayer);
		}
	}
	pText(intros[mo]);
}