#include "pch.h"
#include "battle.h"
#include <string>

using namespace std;


battle::battle() {
	this->heroes.push_back(player());
	this->enemies.push_back(monster());
}

battle::battle(vector<player> party) {
	this->heroes = party;
	this->enemies.push_back(monster());
	this->enemies.push_back(monster());
}

battle::battle(vector<player> party, monster monster) {
	this->heroes = party;
	this->enemies.push_back(monster);
	this->enemies.push_back(monster);
	if (rand() % 2 > 0) { current = hero; }
	else { current = enemy; }
}


