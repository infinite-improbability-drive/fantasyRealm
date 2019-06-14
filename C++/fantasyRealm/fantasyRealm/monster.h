#pragma once
#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <map>
#include <string>

using namespace std;

class monster {
public:
	wstring name;
	wstring type;
	wchar_t icon;
	bool living = true;
	bool current = false;
	bool selected = false;
	int color;
	int maxHP;
	int maxMP;
	int HP;
	int MP;
	int x;
	int y;
	enum statistics { strength, defense, stamina, perception, accuracy, agility, intellect, wisdom, spirit, charisma, luck };
	struct stat { wstring name;	int value; };
	stat stats[luck + 1] = { {L"Strength", 1}, {L"Defense", 1}, {L"Stamina", 1}, {L"Perception", 1}, {L"Accuracy", 1}, {L"Agility", 1}, {L"Intellect", 1}, {L"Wisdom", 1}, {L"Spirit", 1}, {L"Charisma", 1}, {L"Luck", 1}, };

	monster();
	monster(int x, int y);
	static wstring getMonsterType();
	static wstring getMonsterName(wstring type);
	static wchar_t getMonsterIcon(wstring name);
	static int getMonsterColor(wstring name, wstring type);
	static int findColor(map<wstring, int> list, wstring name);

	static map<wstring, int> trash;
	static map<wstring, int> tiny;
	static map<wstring, int> normal;
	static map<wstring, int> ghosts;
	static map<wstring, int> undead;
	static map<wstring, int> large;
	static map<wstring, int> veryLarge;
	static map<wstring, int> rare;
	static map<wstring, int> veryRare;
	static map<wstring, int> veryLargeAndRare;
	static map<wstring, int> giant;
	static map<wstring, int> boss;
	static map<wstring, int> animals;
	static map<wstring, int> bears;

};

#endif