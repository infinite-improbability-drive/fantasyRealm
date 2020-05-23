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
	bool current = false;
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

class rage : public ability {
public:
	vector<action> actions;
	// wstring name;
	rage();
};
class song : public ability {
public:
	// wstring name;
	song();
};
class holy : public ability {
public:
	// wstring name;
	holy();
};
class unholy : public ability {
public:
	// wstring name;
	unholy();
};
class shapeshift : public ability {
public:
	// wstring name;
	shapeshift();
};
class swordtech : public ability {
public:
	// wstring name;
	swordtech();
};
class holyarts : public ability {
public:
	// wstring name;
	holyarts();
};
class evade : public ability {
public:
	// wstring name;
	evade();
};
class flame : public ability {
public:
	// wstring name;
	flame();
};
class frost : public ability {
public:
	// wstring name;
	frost();
};
class bushido : public ability {
public:
	// wstring name;
	bushido();
};
class shinobi : public ability {
public:
	// wstring name;
	shinobi();
};
class assassin : public ability {
public:
	// wstring name;
	assassin();
};
class sorcery : public ability {
public:
	// wstring name;
	sorcery();
};
class royal : public ability {
public:
	// wstring name;
	royal();
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