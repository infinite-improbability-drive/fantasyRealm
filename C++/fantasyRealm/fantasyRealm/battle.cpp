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
	if (rand() % 2 > 0) { current = hero; this->heroes = selectHero(this->heroes); }
	else { current = enemy; selectMonster(); }
}

vector<player> battle::selectHero(vector<player> heroes) {
	int i = 0;
	for (player hero : heroes) {
		heroes[i].selected = true;
	}
	// int i = &heroes->size;
	// heroes[rand() % (i + 1) - 1].selected = true;
	return heroes;
}
void battle::selectMonster() {}


