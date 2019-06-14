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
	enum state {start, next, hero, enemy, select_hero_attack, select_enemy_attack, select_skill, select_item, select_target, attack};
	state current;
	battle();
	battle(vector<player> party);
	battle(vector<player> party, monster monster);

	static vector<player> selectHero(vector<player> heroes);
	static vector<monster> selectMonster(vector<monster> monsters);
	static state getNextState(state current);
};

// actions - enter, exit, look, menu, quit, 

#endif