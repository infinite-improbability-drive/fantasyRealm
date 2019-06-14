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

battle::state battle::getNextState(state current) {
	switch (current) {
	case start: return next;
	case next: 	if (rand() % 2 > 0) { return hero; }
				else { return enemy; };
	case hero: return select_hero_attack;
	case enemy: return select_enemy_attack;
	// case select_hero_attack: return select_target;
	case select_skill: return select_target;
	case select_item: return select_target;
	case select_enemy_attack: return select_target;
	case select_target: return attack;
	case attack: return next;
	}
}


