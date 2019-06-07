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



#endif