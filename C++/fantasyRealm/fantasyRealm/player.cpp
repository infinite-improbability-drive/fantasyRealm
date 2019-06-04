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
		this->name = L"Billy";
		// this->name = L"Hubris";
	}
	player(wstring name) {
		this->name = name;
	}
	enum dialogue { greeting, introduction, exclamation, disgust };
	wstring speak(dialogue thoughts) {
		if (thoughts == greeting) {
			return L"Hi how are you?";
		}
		else {
			return L"Go away! I don't want to talk to you!";
		}
	}

};


