#include "pch.h"
#include "names.h"
#include "player.h"
#include "ability.h"
#include "time.h"
#include "weapon.h"
#include <string>
#include <vector>

using namespace std;

player::player() {
	this->level = 1;
	this->race = L"Half-Orc";
	this->role = names::role();
	this->name = names::fullName(this->role);
	*this->stats = getStats(this->role, this->stats);
	this->_weapon = weapon(this->role);
	this->skills.push_back(fight());
	this->skills.push_back(ability(L"Item"));
	// this->thoughts = greeting;
	// this->selected = false;
	// enum statistics { strength, defense, stamina, perception, accuracy, agility, intellect, wisdom, spirit, charisma, luck };
}
player::player(wstring name) {
	this->name = name;
}
player::player(wstring name, wstring role, int wits, int brave) {
	this->name = name;
	this->role = role;
	this->wits = wits;
	this->brave = brave;
}
player::stat player::getStats(wstring role, player::stat stats[]) {
	srand(clock() + rand() % 10000);
	int i = rand() % 10;
	int points = i / 2;
	stats[luck].value = i;
	vector<int> bonuses;
	if (role == L"Barbarian") {			bonuses.push_back(strength);	bonuses.push_back(stamina);		bonuses.push_back(agility); }
	else if (role == L"Bard") {			bonuses.push_back(intellect);	bonuses.push_back(charisma);	bonuses.push_back(spirit); }
	else if (role == L"Cleric") {		bonuses.push_back(wisdom);		bonuses.push_back(spirit);		bonuses.push_back(stamina); }
	else if (role == L"Demon Hunter") {	bonuses.push_back(strength);	bonuses.push_back(intellect);	bonuses.push_back(agility); }
	else if (role == L"Druid") {		bonuses.push_back(intellect);	bonuses.push_back(agility);		bonuses.push_back(wisdom);		bonuses.push_back(spirit); }
	else if (role == L"Knight") {		bonuses.push_back(strength);	bonuses.push_back(defense);		bonuses.push_back(stamina);		bonuses.push_back(agility); }
	else if (role == L"Paladin") {		bonuses.push_back(strength);	bonuses.push_back(defense);		bonuses.push_back(wisdom);		bonuses.push_back(spirit); }
	else if (role == L"Pugilist") {		bonuses.push_back(strength);	bonuses.push_back(agility);		bonuses.push_back(accuracy); }
	else if (role == L"Pyromancer") {	bonuses.push_back(intellect);	bonuses.push_back(wisdom);		bonuses.push_back(charisma);	bonuses.push_back(luck); }
	else if (role == L"Samurai") {		bonuses.push_back(strength);	bonuses.push_back(defense);		bonuses.push_back(accuracy);	bonuses.push_back(agility); }
	else if (role == L"Sniper") {		bonuses.push_back(accuracy);	bonuses.push_back(agility);		bonuses.push_back(perception); }
	else if (role == L"Sorcerer") {		bonuses.push_back(intellect);	bonuses.push_back(intellect);	bonuses.push_back(wisdom); }
	else if (role == L"Thief") {		bonuses.push_back(agility);		bonuses.push_back(accuracy);	bonuses.push_back(luck); }
	else if (role == L"Princess") {		bonuses.push_back(intellect);	bonuses.push_back(wisdom);		bonuses.push_back(charisma); }
	else if (role == L"Fool") {			bonuses.push_back(charisma);	bonuses.push_back(agility);		bonuses.push_back(luck); }
	else {								bonuses.push_back(agility); }
	return randomStats(stats, bonuses, points);;
}
player::stat player::randomStats(player::stat stats[], vector<int> bonuses, int points) {
	for (int i = 0; i < points; i++) {
		int k = rand() % bonuses.size();
		stats[bonuses[k]].value += 1;
	}
	return *stats;
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


