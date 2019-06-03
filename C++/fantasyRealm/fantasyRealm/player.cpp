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
	// wstring speak();
};

// wstring player::speak() {
// 	return L"Hi how are you?";
// };
