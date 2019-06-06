#pragma once
#ifndef __REALM_H__
#define __REALM_H__

#include "place.h"
#include "monster.h"
// #include <map>
#include <string>
#include <vector>

using namespace std;

class realm {
public:
	wstring name;
	wstring type;
	vector<place> places;
	vector<monster> monsters;
	realm* parent;
	int x;
	int y;
	realm();
	realm(int wits, int brave);
	realm(place here, realm *parent, int width, int height);
};

// wstring getName() { return L"Sanctuary Circle"; }

#endif