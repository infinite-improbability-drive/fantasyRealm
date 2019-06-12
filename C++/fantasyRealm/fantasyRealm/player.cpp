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
}

player::player(wstring name) {
	this->name = name;
}

player1::player1() {

	wprintf(L"Welcome to the fantasy realm.\n");
	wprintf(L"Please enter your name:\n");
	this->name = input();

	if (name == L"") { this->name = names::fullName(); }

	wprintf(L"Please choose your class-\n");
	wstring roles[] = { L"Bard", L"Knight", L"Sorcerer" };
	for (wstring r : roles) {
		if (r != roles[roles->length() - 2]) {
			wcout << r << ", ";
		}
		else {
			wcout << r << ".\n";
		}
	}
	this->role = input();
	bool isRole;
	for (wstring r : roles) {
		if (role == r) {
			isRole = true;
			break;
		}
		else {
			isRole = false;
		}

	}
	if (!isRole) { this->role = L"Fool"; }

	wprintf(L"You must think you're pretty clever.\n");
	wprintf(L"Just how clever are you? (1-10):\n");
	cin >> this->wits;
	while (wits < 1 || wits > 11) {
		wprintf(L"Try again. \n");
		wprintf(L"Just how clever are you? (1-10):\n");
		cin >> this->wits;
	}

	wprintf(L"You must be brave to traverse these realms.\n");
	wprintf(L"How brave do you think you are? (1-10):\n");
	cin >> this->brave;
	while (brave < 1 || brave > 11) {
		wprintf(L"Just how brave are you, really? (1-10):\n");
		cin >> this->brave;
	}

	this->level = 1;
	this->nextLevel = 1;
	this->EXP = 0;
	this->totalEXP = 0;
	this->x = rand() % (wits * 100) - (wits * 50);
	this->y = rand() % (wits * 100) - (wits * 50);
	*this->stats = getStats(this->role, this->stats);

	this->maxHP = getMaxHP(this->stats);
	this->maxMP = getMaxMP(this->stats);

	this->HP = rand() % (this->maxHP / 2) + (this->maxHP / 2);
	this->MP = rand() % (this->maxMP - 3) + 3;

	this->_weapon = weapon(this->role);
	this->skills.push_back(fight());
	if (this->role == L"Fool") { this->skills.push_back(slapstick()); }
	else { this->skills.push_back(ability(this->role)); }
	this->skills.push_back(use());

	wcout << "Hello " << this->name << " the " << this->role << ".\n";
	wcout << "The " << this->role << " class uses the ability " << this->skills[1].name << " and the " << this->_weapon.name << " starting weapon.\n";

	system("pause");
}

hero::hero(int x, int y) {
	this->level = 1;
	this->EXP = 0;
	this->nextLevel = 1;
	this->totalEXP = 0;
	this->x = x;
	this->y = y;
	this->race = L"Half-Orc";
	this->role = names::role();
	this->name = names::fullName(this->role);

	*this->stats = getStats(this->role, this->stats);
	this->maxHP = getMaxHP(this->stats);
	this->maxMP = getMaxMP(this->stats);
	this->HP = rand() % (this->maxHP / 2) + (this->maxHP / 2);
	this->MP = rand() % this->maxMP + 1;

	this->_weapon = weapon(this->role);
	this->skills.push_back(fight());
	this->skills.push_back(ability(this->role));
	this->skills.push_back(use());
}

npc::npc(int x, int y) {
	this->name = names::fullName();
	this->role = L"Villager";
	this->x = x;
	this->y = y;
}

inn::inn(int x, int y) {
	this->name = names::fullName();
	this->role = L"Innkeeper";
	this->x = x;
	this->y = y;
}

shop::shop(int x, int y) {
	this->name = names::fullName();
	this->role = L"Shopkeep";
	this->x = x;
	this->y = y;
}

smith::smith(int x, int y) {
	this->name = names::fullName();
	this->role = L"Blacksmith";
	this->x = x;
	this->y = y;
}

wstring player::input() {
	string out;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	getline(cin, out);
	return converter.from_bytes(out);
	// std::string narrow = converter.to_bytes(wide_utf16_source_string);
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

int player::getMaxHP(player::stat stats[]) {
	int max = 10;
	for (int i = 0; i < stats[luck].value; i++) {
		max += rand() % 4 + 1;
	}
	for (int j = 0; j < stats[stamina].value; j++) {
		max += rand() % 12 + 1;
	}

	return max;
}

int player::getMaxMP(player::stat stats[]) {
	int max = 3;
	for (int i = 0; i < stats[luck].value; i++) {
		max += rand() % 2;
	}
	for (int j = 0; j < stats[intellect].value; j++) {
		max += rand() % 3 + 1;
	}
	for (int j = 0; j < stats[wisdom].value; j++) {
		max += rand() % 2 + 1;
	}
	return max;
}

int player::getNextLevel() { return rand() % 10; }

wstring player::speak(dialogue thoughts) {
	switch (thoughts) {
	case greeting:
		return L"Hi how are you?";
	case intro:
		return L"My name is " + name + L".";
	case introduction:
		return L"My name is " + name + L" the " + role + L".";
	case stay:
		return L"Would you like a room for the night? [Y] Yes    [N] No";
	case browse:
		return L"Would you like to buy anything? [Y] Yes    [N] No";
	case upgrade:
		return L"Would you like to upgrade your weapons and armor? [Y] Yes    [N] No";
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

