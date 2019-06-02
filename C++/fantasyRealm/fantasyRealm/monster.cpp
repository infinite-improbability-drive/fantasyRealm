#include "pch.h"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

static wstring getMonsterName(wstring type);
static wstring getMonsterType();
static wstring trashMonsters[] = { L"Crow", L"Rat", L"Worm" };


class monster {
public:
	wstring name;
	wstring type;
	wstring icon;
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
	return name;
}

