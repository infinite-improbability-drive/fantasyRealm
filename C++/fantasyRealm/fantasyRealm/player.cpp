#include "pch.h"
#include "ability.cpp"
#include "weapon.cpp"
#include <string>
#include <vector>

using namespace std;

class player {
public:
	wstring name;
	wstring role;
	vector<wstring> actions;
	vector<wstring> menu_actions = { L"Status", L"Items", L"Equipment", L"Exit" };
	vector<item> inventory;
	weapon weapon;
	ability ability;
	int wits;
	int brave;
	int x;
	int y;
	player() {
		this->name = L"Hubris";
	}
	player(wstring name) {
		this->name = name;
	}
};

