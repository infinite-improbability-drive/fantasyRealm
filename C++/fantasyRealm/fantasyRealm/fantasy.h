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
public:
	fantasy() {
		m_sAppName = L"fantasy realm";
	}
	vector<player> party;
	void start();
private:
	enum mode { play, pause, talk, menu_mode, shop, normal_battle, random_battle, quit };
	mode current;
	enum menu { main, party_menu, status, items, equipment, exit_menu };
	int header_rows;
	vector<wstring> actions;
	menu current_menu;
	map<menu, pair<wstring, bool>> menu_actions = { {party_menu, {L"Party", false}}, {status, {L"Status", false} }, {items, {L"Items", false }}, {equipment, {L"Equipment", false }}, {exit_menu, {L"Exit", false }} };

	realm here;
	realm r;
	player current_player;
	vector<item> inventory;
	battle fight;
	bool move;
	int enemy;

	void drawHeader();
	void drawWindow(int left, int right, int top, int bottom, wstring title);
	void drawMessage(player player, player::dialogue message);
	void drawMenu(menu item);
	void drawParty(int top, int left);
	void drawStatus(int top, int left);
	void drawSkills(int top, int left, player player);
	void drawItems(int start);
	void drawEquipment(int start);
	void drawBattle();
	void drawQuit();
	void isSolid();
	int isMonster();

protected:
	virtual bool OnUserCreate();
	virtual bool OnUpdate();
	virtual bool OnUserUpdate(float fElapsedTime);
};

#endif