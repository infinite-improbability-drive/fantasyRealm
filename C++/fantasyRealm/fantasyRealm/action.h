#pragma once
#ifndef __ACTION_H__
#define __ACTION_H__

#include <string>

using namespace std;

class action {
public:
	wstring name;
	int physical_damage;
	int magic_damage;
	bool selected = false;
	bool current = false;
	action();	
	action(wstring name);
};

// actions - enter, exit, look, menu, quit, 

#endif