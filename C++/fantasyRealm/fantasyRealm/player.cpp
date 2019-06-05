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
	// vector<wstring, int> stats;
	int level;
	int wits;
	int brave;
	int x;
	int y;
	bool selected = false;
	player() {
		this->name = L"Billy";
		this->role = L"Shortstop";
		this->thoughts = greeting;
		// this->stats.push_back({ L"Strength", 1 });
		// this->name = L"Hubris";
	}
	player(wstring name) {
		this->name = name;
	}
	enum dialogue { greeting, introduction, exclamation, join, joined, disgust };
	dialogue thoughts;
	wstring speak(dialogue thoughts) {
		switch (thoughts) {
		case greeting:
			return L"Hi how are you?";
		case introduction:
			return L"My name is " + name + L" the " + role + L".";
		case join:
			return L"Would you have any need for a " + role + L" during your travels? [Y] Yes    [N] No";
		case joined:
			return L"Alright, let's have an adventure then!";
		case disgust:
			return L"Go away! I don't want to talk to you!";
		default:
			return L"This is a fine place.";
		}
	}

};


