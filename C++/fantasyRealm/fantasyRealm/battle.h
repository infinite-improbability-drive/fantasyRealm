#pragma once
#ifndef __BATTLE_H__
#define __BATTLE_H__

#include "monster.h"
#include "player.h"
#include <string>

using namespace std;

class battle {
public:
	vector<player> heroes;
	vector<monster> enemies;
	enum state {start, next, hero, hero_select_attack, hero_select_skill, hero_select_item, hero_select_target, hero_attack, enemy, enemy_select_attack, enemy_select_target, enemy_attack};
	state current = next;
	battle();
	battle(vector<player> party);
	battle(vector<player> party, monster monster);

	static state getNextState(state current);
	static battle getNext(battle fight);
	static vector<player>  select(vector<player> heroes);
	static vector<monster> select(vector<monster> monsters);
	static vector<player>  target(vector<player> heroes);
	static vector<monster> target(vector<monster> monsters);
	static player attack(monster monster, player player);
	static monster attack(player player, monster monster);

};

// actions - enter, exit, look, menu, quit, 

#endif