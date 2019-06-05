#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "ability.h"
#include "weapon.h"
#include <map>
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
	enum statistics { strength, defense, stamina, perception, accuracy, agility, intellect, wisdom, spirit, charisma, luck };
	// std::map<statistics, pair<wstring, int>> stats;
	struct stat {
		wstring name;
		int value;
	};
	stat stats[luck + 1] = { {L"Strength", 1}, {L"Defense", 1}, {L"Stamina", 1}, {L"Perception", 1}, {L"Accuracy", 1}, {L"Agility", 1}, {L"Intellect", 1}, {L"Wisdom", 1}, {L"Spirit", 1}, {L"Charisma", 1}, {L"Luck", 1}, };

};

#endif