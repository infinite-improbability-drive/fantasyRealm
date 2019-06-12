#pragma once
#ifndef __ABILITY_H__
#define __ABILITY_H__

#include "action.h"
#include <string>
#include <vector>

using namespace std;

class ability {
public:
	wstring name;
	bool selected = false;
	vector<action> actions;
	ability();
	ability(wstring role);
};

class fight : public ability {
public:
	// wstring name;
	action action;
	fight();
};

class slapstick : public ability {
public:
	// wstring name;
	slapstick();
};

class use : public ability {
public:
	// wstring name;
	use();
};



#endif