#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "ability.h"
#include "weapon.h"
#include <string>

using namespace std;

class player {
public:
	wstring name;
	wstring race;
	wstring role;
	weapon _weapon;
	ability ability;
	// vector<wstring, int> stats;
	int level;
	int wits;
	int brave;
	int x;
	int y;
	bool selected;
	player();
	player(wstring name);
	enum dialogue { greeting, introduction, exclamation, join, joined, disgust };
	dialogue thoughts;
	wstring speak(dialogue thoughts);
	enum stats { strength, defense, stamina, perception, accuracy, agility, intellect, wisdom, spirit, charisma, luck };
	// vector<wstring, stats> stats;
};

#endif