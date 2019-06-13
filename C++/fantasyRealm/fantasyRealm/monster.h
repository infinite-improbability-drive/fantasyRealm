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
	bool current = false;
	bool selected = false;
	int color;
	int x;
	int y;
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