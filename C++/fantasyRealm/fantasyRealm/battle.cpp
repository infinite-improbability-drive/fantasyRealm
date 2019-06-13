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

battle::battle(vector<player> party, monster attacker) {
	this->heroes = party;
	this->enemies.push_back(attacker);
	this->enemies.push_back(attacker);
	int i = 0;
	for (player hero : this->heroes) {
		this->heroes[i].current = false;
		i++;
	}
	int j = 0;
	for (monster monster : this->enemies) {
		this->enemies[j].current = false;
		j++;
	}
	if (rand() % 2 > 0) { current = hero; this->heroes = selectHero(this->heroes); }
	else { current = enemy; this->enemies = selectMonster(this->enemies); }
}

vector<player> battle::selectHero(vector<player> heroes) {
	heroes[rand() % heroes.size()].current = true;
	return heroes;
}
vector<monster> battle::selectMonster(vector<monster> monsters) {
	monsters[rand() % monsters.size()].current = true;
	return monsters;
}



