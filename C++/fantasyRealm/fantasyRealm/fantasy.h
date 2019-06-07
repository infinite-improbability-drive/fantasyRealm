#pragma once
#ifndef __FANTASY_H__
#define __FANTASY_H__

#include "olcConsoleGameEngine.h"
#include "item.h"
#include "player.h"
#include "realm.h"
#include <string>
#include <vector>

using namespace std;

class fantasy : public olcConsoleGameEngine {
public:
	fantasy() {
		m_sAppName = L"fantasy realm";
	}
	void start();

private:
	vector<player> party;
	vector<player> npcs;
	// player player1;
	player current_player;
	player someone;
	player nobody;
	realm here;
	realm r;
	enum mode { play, pause, talk, menu_mode, shop, battle, random_battle, quit };
	enum menu { main, party_menu, status, items, equipment, exit_menu };
	map<menu, pair<wstring, bool>> menu_actions = { {party_menu, {L"Party", false}}, {status, {L"Status", false} }, {items, {L"Items", false }}, {equipment, {L"Equipment", false }}, {exit_menu, {L"Exit", false }} };
	mode current;
	menu current_menu;
	// vector<menu, int> mz = { {main, 0 }};
	vector<wstring> actions;
	vector<item> inventory;
	bool move;
	int enemy;

	wstring input();
	void drawHeader();
	void drawWindow(int left, int right, int top, int bottom, wstring title);
	void drawMessage(player player, player::dialogue message);
	void drawMenu(menu item);
	void drawParty(int start);
	void drawStatus(int start);
	void drawItems(int start);
	void drawEquipment(int start);
	void drawBattle();
	void drawQuit();
	int isMonster();

protected:
	virtual bool OnUserCreate();
	virtual bool OnUpdate();
	virtual bool OnUserUpdate(float fElapsedTime);
};

#endif