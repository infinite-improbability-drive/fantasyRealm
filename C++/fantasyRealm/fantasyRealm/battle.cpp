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
	this->getNext(*this);
}

battle::state battle::getNextState(state current) {
	switch (current) {
	case start: return next;
	case next: 	if (rand() % 2 > 0) { return hero; }
				else { return enemy; };
	case hero: return hero_select_attack;
	// case select_hero_attack: return select_target;
	case hero_select_skill: return hero_select_target;
	// case hero_select_item: return hero_select_target;
	case hero_select_target: return hero_attack;
	case hero_attack: return next;
	case enemy: return enemy_select_attack;
 	case enemy_select_attack: return enemy_select_target;
	case enemy_select_target: return enemy_attack;
	case enemy_attack: return next;
	}
}
battle battle::getNext(battle fight) {
	if (rand() % 2 > 0) { int j = 0; for (monster monster : fight.enemies) { fight.enemies[j].current = false; j++;} fight.current = hero; fight.heroes = select(fight.heroes); }
	else {				  int i = 0; for (player hero : fight.heroes) {	fight.heroes[i].current = false; i++; }	fight.current = enemy; fight.enemies = select(fight.enemies); }
	return fight;
}

vector<player> battle::select(vector<player> heroes) {
	int i = 0;
	for (player hero : heroes) {
		heroes[i].current = false;
		i++;
	}
	int k = 0;
	k = rand() % heroes.size();
	heroes[k].current = true;
	heroes[k].skills[0].selected = true;
	return heroes;
}
vector<monster> battle::select(vector<monster> monsters) {
	int j = 0;
	for (monster monster : monsters) {
		monsters[j].current = false;
		j++;
	}
	monsters[rand() % monsters.size()].current = true;
	return monsters;
}

vector<player> battle::target(vector<player> heroes) {
	int i = 0;
	for (player hero : heroes) {
		heroes[i].selected = false;
		i++;
	}
	heroes[rand() % heroes.size()].selected = true;
	return heroes;
}
vector<monster> battle::target(vector<monster> monsters) {
	int j = 0;
	for (monster monster : monsters) {
		monsters[j].selected = false;
		j++;
	}
	monsters[rand() % monsters.size()].selected = true;
	return monsters;
}

monster battle::attack(player player, monster monster) {
	monster.HP -= rand() % (player.stats[player.strength].value * 5) + 1;
	if (monster.HP <= 0) {
		monster.HP = 0;
		monster.living = false;
	}
	monster.selected = false;
	return monster;
}

player battle::attack(monster monster, player player) {
	player.HP -= rand() % (monster.stats[monster.strength].value * 5) + 1;
	if (player.HP <= 0) {
		player.HP = 0;
		player.living = false;
	}
	player.selected = false;
	return player;
}

