#pragma once
#ifndef __REALM_H__
#define __REALM_H__

#include "place.h"
#include "player.h"
#include "monster.h"
// #include <map>
#include <string>
#include <vector>

using namespace std;

class realm {
public:
	wstring name;
	static enum realmType {planet, moon, asteroid};
	map<realmType, wstring> realmList = { {planet, L"Planet"}, {moon, L"Moon"}, {asteroid, L"Asteroid"} };
	static realmType rtype;
	wstring type;
	vector<place> places;
	vector<player> npcs;
	vector<monster> monsters;
	realm* parent;
	int x;
	int y;
	realm();
	realm(int wits, int brave);
	realm(place here, realm *parent, int width, int height, player *player);
	static wstring getName();
	static vector<monster> moveMonsters(vector<monster> monsters);
};

// return L"Sanctuary Circle"; 

#endif