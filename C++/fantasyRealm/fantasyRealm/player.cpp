#include "pch.h"
#include "names.h"
#include "player.h"
#include "ability.h"
#include "weapon.h"
#include <string>
#include <vector>

using namespace std;

player::player() {
	names names;
	this->race = L"Half-Orc";
	this->role = names.role();
	this->name = names.fullName(this->role);
	this->_weapon = weapon(this->role);
	this->thoughts = greeting;
	this->level = 1;
	this->selected = false;
	// this->role = L"Shortstop";
	// this->stats.push_back({ L"Strength", 1 });
	// this->name = L"Billy";
	// this->name = L"Hubris";
}
player::player(wstring name) {
	this->name = name;
}
wstring player::speak(dialogue thoughts) {
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


