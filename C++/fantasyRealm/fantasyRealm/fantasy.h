#pragma once
#ifndef __FANTASY_H__
#define __FANTASY_H__

#include "olcConsoleGameEngine.h"
#include "battle.h"
#include "item.h"
#include "player.h"
#include "realm.h"
#include <string>
#include <vector>

using namespace std;

class fantasy : public olcConsoleGameEngine {
	//friend class realm;
public:
	fantasy() {
		m_sAppName = L"fantasy realm";
	}
	vector<player> party;
	void start();
private:
	enum mode { play, pause, talk, menu_mode, shop, normal_battle, random_battle, battle_win, quit, game_over };
	mode current;
	enum menu { main, party_menu, status, items, equipment, exit_menu };
	static enum key { left = 0x25, up = 0x26, right = 0x27, down = 0x28, enter = 13, m = 77, n = 78, q = 81, t = 84, y = 89 };
	int header_rows;
	vector<wstring> actions;
	menu current_menu;
	map<menu, pair<wstring, bool>> menu_actions = {
		{party_menu, {L"Party", false}}, 
		{status, {L"Status", false} }, 
		{items, {L"Items", false }}, 
		{equipment, {L"Equipment", false }}, 
		{exit_menu, {L"Exit", false }} 
	};

	realm here;
	realm r;
	player current_player;
	vector<item> inventory;
	battle fight;
	bool move;
	int enemy;

	void drawHeader();
	void drawRealm();
	void drawMapHints();
	void drawWindow(int left, int right, int top, int bottom, wstring title);
	void drawWindow(int left, int top, vector<wstring> message);
	void drawWindow(vector<wstring> message);
	void drawMessage(player player, player::dialogue message);
	void drawMenu(menu item);
	void drawParty(int left, int top);
	void drawStatus(int left, int top);
	void drawSkills(int left, int top, player player);
	void drawSkill(int left, int top, ability ability);
	void drawItems(int left, int top);
	void drawEquipment(int start);
	void drawBattle();
	void drawBattleWin();
	void drawGameOver();
	void drawQuit();
	void isSolid();
	int isMonster();

protected:
	virtual bool OnUserCreate();
	virtual bool OnUpdate();
	virtual bool OnUserUpdate(float fElapsedTime);
};

#endif