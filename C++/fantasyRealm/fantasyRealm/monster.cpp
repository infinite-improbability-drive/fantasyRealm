#include "pch.h"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

static wstring getMonsterName(wstring type);
static wstring getMonsterType();
static wstring trashMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring smallMonsters[] = { L"Gnome", L"Fairy", L"Cockatrice", L"Enchanted Clothing",
	L"Faery", L"Goblin", L"Hobbit", L"Imp", L"Jackelope", L"Kodama", L"Leprechaun", L"Pirhana",
	L"Pixie", L"Rat", L"Slime", L"Sprite", L"Wisp" };
static wstring normalMonsters[] = { L"Bandit", L"Basilisk", L"Centaur", L"Demon", L"Djinn",
	L"Dryad", L"Elemental", L"Enchanted Furniture", L"Faun", L"Ghoul", L"Giant Rat", L"Green Man",
	L"Harpy", L"Lamia", L"Large Slime", L"Mermaid", L"Naga", L"Orc", L"Satyr", L"Shapeshifter",
	L"Siren", L"Tengu", L"Vampire", L"Wendigo", L"Werewolf", L"Wolf", L"Yokai", L"Zombie" };
static wstring largeMonsters[] = { L"Alpha Wolf", L"Behemoth", L"Demon King", L"Dire Wolf",
	L"Giantic Rat", L"Goblin King", L"Golem", L"Griffin", L"Hydra", L"Land Shark", L"Manticore",
	L"Minotaur", L"Ogre", L"Orc Captain", L"Scorpion Man", L"Were-bear" };
static wstring veryLargeMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring rareMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring veryRareMonsters[] = { L"Unicorn" };
static wstring veryLargeAndRareMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring giantMonsters[] = { L"Gamera" };
static wstring bossMonsters[] = { L"Crow", L"Rat", L"Worm" };

class monster {
public:
	wstring name;
	wstring type;
	wstring icon;
	int color = 0x000A;
	int x;
	int y;
	monster() {
		this->type = getMonsterType();
		this->name = getMonsterName(this->type);
		this->icon = tolower(this->name[0]);
		this->x = rand() % 200 - 100;
		this->y = rand() % 200 - 100;
	}
};

static wstring getMonsterType() {
	int i = rand() % 100;
	if (i == 99) {
		return L"very_large_and_rare";
	}
	else if ((i < 99) && (i >= 97)) {
		return L"rare";
	}
	else if ((i < 97) && (i >= 95)) {
		return L"very_large";
	}
	else if ((i < 95) && (i >= 90)) {
		return L"large";
	}
	else if ((i < 90) && (i >= 60)) {
		return L"normal";
	}
	else if ((i < 60) && (i >= 50)) {
		return L"small";
	}
	else {
		return L"trash";
	}
}

static wstring getMonsterName(wstring type) {
	wstring name = L"Garbage";
	if (type == L"trash") {
		name = trashMonsters[rand() % (sizeof(trashMonsters) / sizeof(trashMonsters[0]))];
	}
	else if (type == L"small") {
		name = smallMonsters[rand() % (sizeof(smallMonsters) / sizeof(smallMonsters[0]))];
	}
	else if (type == L"normal") {
		name = normalMonsters[rand() % (sizeof(normalMonsters) / sizeof(normalMonsters[0]))];
	}
	else if (type == L"large") {
		name = largeMonsters[rand() % (sizeof(largeMonsters) / sizeof(largeMonsters[0]))];
	}
	return name;
}

