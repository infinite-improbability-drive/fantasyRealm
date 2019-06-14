/*
OneLoneCoder.com - Command Line party.front()
"Give me a break, I'm on holiday..." - @Javidx9
License
~~~~~~~
Copyright (C) 2018  Javidx9
This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it
under certain conditions; See license for details.
Original works located at:
https://www.github.com/onelonecoder
https://www.onelonecoder.com
https://www.youtube.com/javidx9
GNU GPLv3
https://github.com/OneLoneCoder/videos/blob/master/LICENSE
From Javidx9 :)
~~~~~~~~~~~~~~~
Hello! Ultimately I don't care what you use this for. It's intended to be
educational, and perhaps to the oddly minded - a little bit of fun.
Please hack this, change it and use it in any way you see fit. You acknowledge
that I am not responsible for anything bad that happens as a result of
your actions. However this code is protected by GNU GPLv3, see the license in the
github repo. This means you must attribute me if you use it. You can view this
license here: https://github.com/OneLoneCoder/videos/blob/master/LICENSE
Cheers!
Background
~~~~~~~~~~
Classic party.front()! Controls are Arrow keys Left & Right, eat food, grow larger, avoid self!
Author
~~~~~~
Twitter: @javidx9
Blog: www.onelonecoder.com
Video:
~~~~~~
https://youtu.be/e8lYLYlrGLg
Last Updated: 24/06/2017
*/

#include "pch.h"
#include <algorithm>
#include <ctime>
#include <chrono>
// #include <cstdlib>
#include <list>
#include <locale>
#include <string>
#include <thread>
#include <fcntl.h>
#include <io.h>
#include <time.h>
#include <vector>
#include <wchar.h>

using namespace std;
using std::vector;

#include "olcConsoleGameEngine.h"
#include "fantasy.h"
#include "item.h"
#include "names.h"
#include "player.h"
#include "realm.h"
#include <Windows.h>

bool fantasy::OnUserCreate() {
	// seed random number generator
	// int r = rand() % 1000;
	// srand(clock() + time(nullptr));
	mode current = play;
	menu current_menu = main;
	move = true;
	// party.push_back(party.front());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item(L"Map Crystal"));
	inventory.push_back(item(L"Map Crystal"));
	inventory.push_back(item(L"Map Crystal"));
	const realm here = realm(party.front().wits, party.front().brave);
	return true;
}

bool fantasy::OnUpdate() {
	if (current == play) {
		here.monsters = here.moveMonsters(here.monsters);
	}
	else if (current == normal_battle || current == random_battle) {
		int j = fight.heroes.size();
		for (player hero : fight.heroes) {
			if (!hero.living) {
				j--;
			}
		}
		if (j == 0) { current = game_over; }

		if (fight.current == fight.next) { fight = fight.getNext(fight); }
		else if (fight.current == fight.enemy) { 
			fight.current = fight.getNextState(fight.current); }
		else if (fight.current == fight.enemy_select_attack) {
			// fight.enemies = fight.selectAbility(fight.enemies); 
			fight.current = fight.getNextState(fight.current);
		}
		else if (fight.current == fight.enemy_select_target) {
			fight.heroes = fight.target(fight.heroes); fight.current = fight.getNextState(fight.current);
		}
		else if (fight.current == fight.enemy_attack) {
			int i = 0;
			for (player hero : fight.heroes) {
				for (monster enemy : fight.enemies) {
					if (enemy.current && hero.selected) {
						fight.heroes[i] = fight.attack(enemy, hero);
						break;
					}
				}
				i++;
			}
			// fight.heroes = fight.attack(fight.enemies); 
			fight.current = fight.getNextState(fight.current);
		}

		// fight.current = fight.getNextState(fight.current);
	}
	return true;
}

bool fantasy::OnUserUpdate(float fElapsedTime) {

	// clear screen
	Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

// -------- LOGIC --------

	if (current == play) {

		if (m_keys[left].bPressed) {	isSolid(); enemy = isMonster(); if (move) { party.front().x -= 1; } }
		if (m_keys[up].bPressed) {		isSolid(); enemy = isMonster(); if (move) { party.front().y -= 1; } }
		if (m_keys[right].bPressed) {	isSolid(); enemy = isMonster(); if (move) { party.front().x += 1; } }
		if (m_keys[down].bPressed) {	isSolid(); enemy = isMonster(); if (move) { party.front().y += 1; } }

		// random battle
		if ((m_keys[left].bPressed || m_keys[up].bPressed || m_keys[right].bPressed || m_keys[down].bPressed) && move) {
			if (rand() % 10000 < 2) {
				current = random_battle;
				fight = battle(party);
			}
		}
		move = true;
		// [ENTER] enter location
		if (m_keys[enter].bPressed) {
			if (std::find(actions.begin(), actions.end(), L"Enter") != actions.end()) {
				for (place place : here.places) {
					if (party.front().x == place.x && party.front().y == place.y) {
						if (place.type == L"exit") {
							party.front().x = here.x;
							party.front().y = here.y;
							here = r;
							break;
						}
						else {
							const int width = 120;
							const int height = 60;
							realm location = realm(place, &here, width, height, &party.front());
							r = here;
							here = location;
							here.parent = &r;
							break;
						}
					}
				}
			}
			else {
				actions.push_back(L"Enter");
			}
		}
	}


	// [M] menu
	if (m_keys[m].bPressed) {
		if (std::find(actions.begin(), actions.end(), L"Menu") != actions.end()) {
			current = menu_mode;
		}
		else {
			actions.push_back(L"Menu");
		}
	}
	// Menu Party Status Items Equipment Exit 
	if (current == menu_mode) {
		// main
		if (current_menu == main) {
			if (m_keys[left].bPressed) {
				current_menu = exit_menu;
				menu_actions.find(current_menu)->second.second = true;
			}
			else if (m_keys[right].bPressed) { 
				current_menu = party_menu; 
				menu_actions.find(current_menu)->second.second = true;
			}
		}

		// party
		else if (current_menu == party_menu) {
			if (m_keys[left].bPressed) { 
				int i = 0;
				bool selected = false;
				for (player member : party) {
					if (member.selected) {
						selected = true;
						break;
					}
					i++;
				}
				if (selected) {
					if (i == 0) {
						party[i].selected = false;
						party[party.size() - 1].selected = true;
					}
					else {
						party[i].selected = false;
						party[i - 1].selected = true;
					}
				}
				else {
					current_menu = main;
				}
			}
			else if (m_keys[right].bPressed) { 
				int i = 0;
				bool selected = false;
				for (player member : party) {
					if (member.selected) {
						selected = true;
						break;
					}
					i++;
				}
				if (selected) {
					if (i == party.size() - 1) {
						party[i].selected = false;
						party[0].selected = true;
					}
					else {
						party[i].selected = false;
						party[i + 1].selected = true;
					}
				}
				else {
					current_menu = status;
					menu_actions.find(current_menu)->second.second = true;
				}
			}
			else if (m_keys[up].bPressed) {
				int i = 0;
				for (player member : party) { party[i].selected = false; i++; }
				menu_actions.find(current_menu)->second.second = true;
			}
			else if (m_keys[down].bPressed) {
				party.front().selected = true;
				menu_actions.find(current_menu)->second.second = false;
			}
		}
		else if (current_menu == status) {
			if (m_keys[left].bPressed) { 
				if (menu_actions.find(current_menu)->second.second) {
					menu_actions.find(current_menu)->second.second = false;
					current_menu = party_menu;
					menu_actions.find(current_menu)->second.second = true;
				}
				int i = 0;
				bool selected = false;
				for (player member : party) {
					if (member.selected) {
						selected = true;
						break;
					}
					i++;
				}
				if (selected) {
					if (i == 0) {
						party[i].selected = false;
						party[i].current = false;
						party[party.size() - 1].selected = true;
						party[party.size() - 1].current = true;
					}
					else {
						party[i].selected = false;
						party[i].current = false;
						party[i - 1].selected = true;
						party[i - 1].current = true;
					}
				}
				else {
					int j = 0;
					for (player member : party) {
						if (member.current) {
							party[j].selected = true;
							int k = 0;
							for (ability skill : member.skills) {
								party[j].skills[k].selected = false;
								k++;
							}
							break;
						}
						j++;
					}
				}
			}
			else if (m_keys[right].bPressed) { 
				int i = 0;
				bool selected = false;
				for (player member : party) {
					if (member.selected) {
						selected = true;
						break;
					}
					i++;
				}
				if (selected) {
					if (i == party.size() - 1) {
						party[i].selected = false;
						party[i].current = false;
						party[0].selected = true;
						party[0].current = true;
					}
					else {
						party[i].selected = false;
						party[i].current = false;
						party[i + 1].selected = true;
						party[i + 1].current = true;
					}
				}
				else {
					menu_actions.find(current_menu)->second.second = false;
					current_menu = items;
					menu_actions.find(current_menu)->second.second = true;
				}
			}
			else if (m_keys[up].bPressed) {
				bool selected = false;
				for (player member : party) { if (member.selected) { selected = true; } }
				if (selected) {
					int i = 0;
					for (player member : party) { party[i].selected = false; party[i].current = false; i++; }
					menu_actions.find(current_menu)->second.second = true;
				}
				else {
					// int i = 0;
					int j = 0;
					for (player member : party) {
						if (member.current) {
							int k = 0;
							for (ability skill : member.skills) {
								if (party[j].skills[0].selected) {
									party[j].skills[0].selected = false;
									party[j].selected = true;
									break;
								}
								else if (party[j].skills[k].selected) {
									party[j].skills[k].selected = false;
									party[j].skills[k - 1].selected = true;
									break;
								}
								k++;
							}
						}
						j++;
					}
				}
			}
			else if (m_keys[down].bPressed) {
				if (menu_actions.find(current_menu)->second.second) {
					party.front().selected = true;
					party.front().current = true;
					menu_actions.find(current_menu)->second.second = false;
				}
				else {
					int i = 0;
					for (player member : party) { party[i].selected = false; i++; }
					int j = 0;
					int k = 0;
					for (player member : party) {
						if (member.current) {
							bool selected = false;
							for (ability skill : member.skills) {
								if (skill.selected) {
									selected = true;
									break;
								}
								k++;
							}
							if (selected) {
								if (k == member.skills.size() - 1) {
									party[j].skills[k].selected = false;
									party[j].skills[0].selected = true;
								}
								else {
									party[j].skills[k].selected = false;
									party[j].skills[k + 1].selected = true;
								}
							}
							else {
								party[j].skills.front().selected = true;
							}
							break;
						}
						j++;
					}

				}
			}
		}
		else if (current_menu == items) {

			if (m_keys[left].bPressed) { current_menu = status; menu_actions.find(current_menu)->second.second = true; int i = 0; for (item item : inventory) { inventory[i].selected = false; i++; } }
			else if (m_keys[right].bPressed) { current_menu = equipment; menu_actions.find(current_menu)->second.second = true; int i = 0; for (item item : inventory) { inventory[i].selected = false; i++; } }
			else if (m_keys[up].bPressed) {
				if (inventory.front().selected) {
					if (!menu_actions.find(current_menu)->second.second) { menu_actions.find(current_menu)->second.second = true; inventory.front().selected = false; }
				}
				else {
					int i = 0; bool selected = false;
					for (item item : inventory) { if (item.selected) { selected = true;	break; } i++; }
					if (selected) { inventory[i].selected = false; inventory[i - 1].selected = true; }
				}
			}
			else if (m_keys[down].bPressed) {
				menu_actions.find(current_menu)->second.second = false; 

				int i = 0;
				bool selected = false;
				for (item item : inventory) {
					if (item.selected) {
						selected = true;
						break;
					}
					i++;
				}
				if (selected) {
					if (i == inventory.size() - 1) { inventory[i].selected = false;	inventory[0].selected = true; }
					else { inventory[i].selected = false; inventory[i + 1].selected = true;	}
				}
				else { inventory.front().selected = true; }

			}
		}
		else if (current_menu == equipment) {
			if (m_keys[left].bPressed) { current_menu = items; }			// left
			else if (m_keys[right].bPressed) { current_menu = exit_menu; }	// right
			menu_actions.find(current_menu)->second.second = true;
		}
		else if (current_menu == exit_menu) {
			if (m_keys[left].bPressed) { current_menu = equipment; }		// left
			else if (m_keys[right].bPressed) { current_menu = main; }		// right
			else if (m_keys[13].bPressed) { current = play; }				// enter
			if (current_menu != main) { menu_actions.find(current_menu)->second.second = true; }
		}

		// [S] status
		if (m_keys[83].bPressed) { current_menu = status; }
		// [I] items
		if (m_keys[73].bPressed) { current_menu = items; }
		// [Q] equipment
		if (m_keys[81].bPressed) { current_menu = equipment; }
		// [E] return to game
		if (m_keys[69].bPressed) { current = play; }
	}

	// [T] talk
	if (current == talk) {
		for (int i = 0; i < 256; i++) {
			if (i == 84) { continue; }
			if (m_keys[i].bPressed) {
				current = play;
			}
		}
		int j = 0;
		for (player npc : here.npcs) {
			if (party.front().x == npc.x && party.front().y == npc.y) {
				if (m_keys[84].bPressed) {
					if (npc.thoughts == npc.greeting) {
						if (npc.role == L"Villager") {
							here.npcs[j].thoughts = npc.intro;
						}
						else {
							here.npcs[j].thoughts = npc.introduction;
						}
					}
					else if (npc.thoughts == npc.introduction || npc.thoughts == npc.intro) {
						if (npc.role == L"Innkeeper") {
							here.npcs[j].thoughts = npc.stay;
						}
						else if (npc.role == L"Shopkeep") {
							here.npcs[j].thoughts = npc.browse;
						}
						else if (npc.role == L"Blacksmith") {
							here.npcs[j].thoughts = npc.upgrade;
						}
						else {
							here.npcs[j].thoughts = npc.join;
						}
					}
				}
				if (m_keys[89].bPressed && npc.thoughts == npc.join) {
					here.npcs[j].thoughts = npc.joined;
					party.push_back(npc);
					here.npcs.erase(here.npcs.begin() + j);
				}
				break;
			}
			j++;
		}


	}
	if (m_keys[t].bPressed) {
		if (std::find(actions.begin(), actions.end(), L"Talk") != actions.end()) {
			for (player npc : here.npcs) {
				if (party.front().x == npc.x && party.front().y == npc.y) {
					current = talk;
					break;
				}
			}
		}
		else {
			actions.push_back(L"Talk");
		}
	}
	// battle
	if (current == normal_battle) {
		if (m_keys[up].bPressed) {
			int j = 0;
			for (player member : fight.heroes) {
				if (member.current) {
					int k = 0;
					for (ability skill : fight.heroes[j].skills) {
						if (fight.heroes[j].skills[0].selected) {
							fight.heroes[j].skills[0].selected = false;
							fight.heroes[j].current = true;
							break;
						}
						else if (skill.selected) {
							fight.heroes[j].skills[k].selected = false;
							fight.heroes[j].skills[k - 1].selected = true;
							break;
						}
						k++;
					}
					break;
				}
				j++;
			}
		}
		else if (m_keys[down].bPressed) {
			int i = 0;
			int j = 0;
			int k = 0;
			for (player member : fight.heroes) {
				if (member.current) {
					bool selected = false;
					for (ability skill : fight.heroes[j].skills) {
						if (skill.selected) {
							selected = true;
							break;
						}
						k++;
					}
					if (selected) {
						if (k == member.skills.size() - 1) {
							fight.heroes[j].skills[k].selected = false;
							fight.heroes[j].skills[0].selected = true;
						}
						else {
							fight.heroes[j].skills[k].selected = false;
							fight.heroes[j].skills[k + 1].selected = true;
						}
					}
					else {
						fight.heroes[j].skills.front().selected = true;
					}
					break;
				}
				j++;
			}
		}
		else if (m_keys[enter].bPressed) {
			fight.current = fight.next;
			int i = 0;
			for (player player : fight.heroes) {
				if (player.current) {
					int j = 0;
					for (ability skill : player.skills) {
						if (skill.selected) {
							if (skill.name == L"Fight") {
								fight.current = fight.hero_select_attack;
							}
							if (skill.name == fight.heroes[i].skills[j].name) {
								fight.current = fight.hero_select_skill;
							}
							if (skill.name == L"Items") {
								fight.current = fight.hero_select_item;
							}
							// fight.heroes[i].skills[j].selected = false;
							// fight.heroes[i].skills[j].current = true;
							break;
						}
						j++;
					}
					break;
				}
				i++;
			}
		}
	}
		
	// win battle
	if (m_keys[y].bPressed && current == normal_battle) {
		if (enemy == here.monsters.size()) {
			enemy -= 1;
		}
		here.monsters.erase(here.monsters.begin() + enemy);
		current = play;
		int i = 0;
		for (player hero : party) {
			party[i].EXP += 1;
			party[i].totalEXP += 1;
			if (hero.EXP >= hero.nextLevel) {
				party[i].EXP -= hero.nextLevel;
				party[i].level += 1;
				party[i].nextLevel = hero.getNextLevel();
			}
			i++;
		}
	}
	// [Y] win battle
	if (m_keys[89].bPressed && current == random_battle) {
		current = play;
	}


	// [Q] quit
	if (m_keys[q].bPressed) {
		if (std::find(actions.begin(), actions.end(), L"Quit") != actions.end()) {
			current = quit;
		}
		else {
			actions.push_back(L"Quit");
		}
	}
	if (current == quit) {
		// [Y] quit game
		if (m_keys[y].bPressed) {
			exit(0);
		}

		// [N] return to game
		if (m_keys[n].bPressed) {
			current = play;
		}
	}

// -------- DRAW --------

	drawHeader();
	drawRealm();

	return true;
}

int main() {

	// set character set to Unicode-16?
	_setmode(_fileno(stdout), _O_U16TEXT);

	// use olcConsoleGameEngine derived app
	fantasy game;
	game.party.push_back(player1());
	game.party.push_back(hero(rand() % 20 - 10, rand() % 20 - 10));
	game.party.push_back(hero(rand() % 20 - 10, rand() % 20 - 10));

	game.ConstructConsole(150, 40, 8, 16);
	game.Start();

	return 0;
}

void fantasy::drawHeader() {
	// top border
	DrawLine(0, 0, ScreenWidth(), 0, 0x003D, FG_WHITE);

	// realm name
	if (here.parent == nullptr) {
		DrawStringAlpha(2, 1, here.name + L" type = " + here.type, 0x000F);
	}
	else {
		DrawStringAlpha(2, 1, here.name + L" type = " + here.type + L" parent = " + here.parent->name, 0x000F);
	}

	// party.front() title
	wstring title = L"" + party.front().name + L" the Lv 1 " + party.front().role;
	DrawStringAlpha(ScreenWidth() - title.length() - 2, 1, title, 0x000F);
	// party.front() position
	DrawStringAlpha(ScreenWidth() - (to_wstring(-party.front().y).length() + 6), 2, L"y = " + to_wstring(-party.front().y), 0x000F);
	DrawStringAlpha(ScreenWidth() - (to_wstring(party.front().x).length() + 6), 3, L"x = " + to_wstring(party.front().x), 0x000F);
	// # of monsters
	DrawStringAlpha(ScreenWidth() - (to_wstring(here.monsters.size()).length() + 18), 4, L"# of monsters = " + to_wstring(here.monsters.size()), 0x000F);

	// collision detection
	for (place place : here.places) {
		if (party.front().x == place.x && party.front().y == place.y) {
			DrawStringAlpha(2, 2, L"You have arrived at " + place.name + L" type = " + place.type, 0x000F);
		}
	}
	// print current key
	for (int i = 0; i < 256; i++) {
		if (m_keys[i].bHeld) {
			DrawStringAlpha(2, 3, L"You are pressing " + to_wstring(i), 0x000F);
		}
	}
	// commands
	int i = 2;
	for (wstring action : actions) {
		DrawStringAlpha(i, 4, action, 0x000F);
		i = i + action.length() + 2;
	}

	// time
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());

	time_t curr_time;
	curr_time = time(NULL);
	tm *tm_local = localtime(&curr_time);

	int hours = tm_local->tm_hour;
	if (hours > 12) { hours -= 12; DrawStringAlpha(2, 5, L"\u2600" + to_wstring(hours) + L":" + to_wstring(tm_local->tm_min) + L"PM", 0x000F); }
	else {						   DrawStringAlpha(2, 5, L"\u263C" + to_wstring(hours) + L":" + to_wstring(tm_local->tm_min) + L"AM", 0x000F); }
	// bottom border
	header_rows = 6;
	DrawLine(0, header_rows, ScreenWidth(), header_rows, 0x003D, FG_WHITE);
}

void fantasy::drawRealm() {
	for (place place : here.places) {
		if (((int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y) > header_rows) {
			Draw((int)(ScreenWidth() / 2) + place.x - party.front().x, (int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y, place.name[0], place.color);
		}
	}

	// draw monsters
	for (monster monster : here.monsters) {
		if (((int)(ScreenHeight() / 2) + (header_rows / 2) + monster.y - party.front().y) > header_rows) {
			Draw((int)(ScreenWidth() / 2) + monster.x - party.front().x, (int)(ScreenHeight() / 2) + (header_rows / 2) + monster.y - party.front().y, monster.icon, monster.color);
		}
	}

	// draw map hints
	drawMapHints();

	// draw party.front()
	Draw(ScreenWidth() / 2, ScreenHeight() / 2 + (header_rows / 2), party.front().name[0], FG_WHITE);

	// draw npcs
	if (here.type.compare(L"realm") != 0) {
		for (player npc : here.npcs) {
			Draw((int)(ScreenWidth() / 2) + npc.x - party.front().x, (int)(ScreenHeight() / 2) + (header_rows / 2) + npc.y - party.front().y, npc.name[0], FG_WHITE);
			if (party.front().x == npc.x && party.front().y == npc.y) {
				// draw message
				if (current == talk) { drawMessage(npc, npc.thoughts); }
			}
		}
	}

	// draw menus
	if (current == menu_mode) { drawMenu(current_menu); }			// draw menu
	else if (current == normal_battle || current == random_battle) { drawBattle(); }		// draw battle
	else if (current == quit) { drawQuit(); }			// draw quit
	else if (current == game_over) { 
		drawGameOver(); }
}

void fantasy::drawMapHints() {
	// get base distance for comparison
	float d = sqrt(pow(abs(party.front().x - here.places[0].x), 2) + pow(abs(party.front().y - here.places[0].y), 2));

	// get lowest distance
	int c = 0;
	vector<float> distances;
	for (place place : here.places) {
		c = sqrt(pow(abs(party.front().x - place.x), 2) + pow(abs(party.front().y - place.y), 2));
		distances.push_back(c);
		if (c < d) {
			d = c;
		}
	}
	sort(distances.begin(), distances.end());

	// for each map crystal get next closest place
	// get number of map crystals
	int i = 0;
	int e = 0;
	vector<int> j;
	for (item item : inventory) {
		if (item.name == L"Map Crystal") {
			for (place place : here.places) {
				e = sqrt(pow(abs(party.front().x - place.x), 2) + pow(abs(party.front().y - place.y), 2));
				if (e == distances.front()) {
					distances.erase(distances.begin());
					j.push_back(i);
				}
				i++;
			}
		}
	}

	int m = 0;
	for (place place : here.places) {
		for (int k : j) {
			if (k == m) {
				// top
				if (((int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y) <= header_rows) {
					Draw((int)(ScreenWidth() / 2) + place.x - party.front().x, header_rows + 1, L""[0], FG_WHITE);
				}
				// bottom
				if (((int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y) > ScreenHeight() - 1) {
					Draw((int)(ScreenWidth() / 2) + place.x - party.front().x, ScreenHeight() - 1, L"v"[0], FG_WHITE);
				}
				// left
				if (((int)(ScreenWidth() / 2) + (header_rows / 2) + place.x - party.front().x) < 3) {
					Draw(0, (int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y, L"<"[0], FG_WHITE);
				}
				// right
				if (((int)(ScreenWidth() / 2) + (header_rows / 2) + place.x - party.front().x) > ScreenWidth() + 2) {
					Draw(ScreenWidth() - 1, (int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y, L">"[0], FG_WHITE);
				}
			}
		}
		m++;
	}
}

void fantasy::drawWindow(int left, int right, int top, int bottom, wstring title) {
	DrawLine(left, top + 1, left, bottom - 1, 0x2502, FG_WHITE);		// left
	DrawLine(left + 1, top, right - 1, top, 0x2500, FG_WHITE);			// top
	DrawLine(right, top + 1, right, bottom - 1, 0x2502, FG_WHITE);		// right
	DrawLine(left + 1, bottom, right - 1, bottom, 0x2500, FG_WHITE);	// bottom

	Draw(left, top, 0x250C, FG_WHITE);
	Draw(right, top, 0x2510, FG_WHITE);
	Draw(left, bottom, 0x2514, FG_WHITE);
	Draw(right, bottom, 0x2518, FG_WHITE);

	Fill(left + 1, top + 1, right, bottom, L' ');

	DrawStringAlpha(left + 2, top + 1, title, 0x000F);
}

void fantasy::drawWindow(vector<wstring> message) {

	int width = 0;
	for (wstring line : message) {
		if (line.size() > width) { width = line.size(); }
	}
	int height = message.size();

	// if (height == 1) { height++; }

	int left = (ScreenWidth() / 2) - (width / 2);
	int right = (ScreenWidth() / 2) + (width / 2) + 3;
	int top = (ScreenHeight() / 2) - (height / 2);
	int bottom = (ScreenHeight() / 2) + (height / 2) + 1;

	if (bottom == top + 1) { bottom++; }

	DrawLine(left, top + 1, left, bottom - 1, 0x2502, FG_WHITE);		// left
	DrawLine(left + 1, top, right - 1, top, 0x2500, FG_WHITE);			// top
	DrawLine(right, top + 1, right, bottom - 1, 0x2502, FG_WHITE);		// right
	DrawLine(left + 1, bottom, right - 1, bottom, 0x2500, FG_WHITE);	// bottom

	Draw(left, top, 0x250C, FG_WHITE);
	Draw(right, top, 0x2510, FG_WHITE);
	Draw(left, bottom, 0x2514, FG_WHITE);
	Draw(right, bottom, 0x2518, FG_WHITE);

	Fill(left + 1, top + 1, right, bottom, L' ');
	
	int i = 0;
	for (wstring line : message) {
		DrawStringAlpha(left + 2, top + i + 1, message[i], 0x000F);
		i++;
	}
}

void fantasy::drawWindow(int left, int top, vector<wstring> message) {

	int width = 0;
	for (wstring line : message) {
		if (line.size() > width) { width = line.size(); }
	}
	int height = message.size();
	int right = left + width + 3;
	int bottom = top + height + 1;

	DrawLine(left, top + 1, left, bottom - 1, 0x2502, FG_WHITE);		// left
	DrawLine(left + 1, top, right - 1, top, 0x2500, FG_WHITE);			// top
	DrawLine(right, top + 1, right, bottom - 1, 0x2502, FG_WHITE);		// right
	DrawLine(left + 1, bottom, right - 1, bottom, 0x2500, FG_WHITE);	// bottom

	Draw(left, top, 0x250C, FG_WHITE);
	Draw(right, top, 0x2510, FG_WHITE);
	Draw(left, bottom, 0x2514, FG_WHITE);
	Draw(right, bottom, 0x2518, FG_WHITE);

	Fill(left + 1, top + 1, right, bottom, L' ');

	int i = 0;
	for (wstring line : message) {
		DrawStringAlpha(left + 2, top + i + 1, message[i], 0x000F);
		i++;
	}
}

void fantasy::drawMessage(player player, player::dialogue message) {

	int width = max(player.speak(message).length(), player.name.length()) + 4;
	int height = 5;
	int offset = 4;

	int left = (int)(ScreenWidth() / 2) + player.x - party.front().x - (width / 2);
	int right = (int)(ScreenWidth() / 2) + player.x - party.front().x + (width / 2);
	int top = (int)(ScreenHeight() / 2) + (header_rows / 2) - player.y + party.front().y - (height / 2) - offset;
	int bottom = (int)(ScreenHeight() / 2) + (header_rows / 2) - player.y + party.front().y + (height / 2) - offset;

	drawWindow(left, right, top, bottom, player.name);

	// message
	DrawStringAlpha(left + 2, top + 3, player.speak(message), 0x000F);
}

void fantasy::drawMenu(menu item) {
	int margin = 9;

	int left = margin * 2;
	int right = ScreenWidth() - 1 - margin * 2;
	int top = margin;
	int bottom = ScreenHeight() - 1 - margin;

	drawWindow(left, right, top, bottom, L"Menu");

	// menu commands
	int i = 0;
	auto it = menu_actions.begin();
	while (it != menu_actions.end()) {
		if (it->first == item && it->second.second == true) {
			DrawStringAlpha(left + 3 + i, top + 3, L"[" + it->second.first + L"]", 0x000F);
		}
		else {
			DrawStringAlpha(left + 4 + i, top + 3, it->second.first, 0x000F);
		}
		i = i + it->second.first.size() + 2;
		it++;
	}

	if		(current_menu == party_menu) {  drawParty(left, top); }
	else if (current_menu == status) {		drawStatus(left, top); }
	else if (current_menu == items) {		drawItems(left, top); }
	else if (current_menu == equipment) {	drawEquipment(top); }

}

void fantasy::drawParty(int left, int top) {
	int i = 0;
	for (player player : party) {
		if (player.selected) {
			DrawStringAlpha(left + 3 + i, top + 5, L"[" + player.name + L"]", 0x000F);
			DrawStringAlpha(left + 3, top + 7, player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role, 0x000F);

		}
		else {
			DrawStringAlpha(left + 4 + i, top + 5, player.name, 0x000F);
		}
		i = i + player.name.length() + 2;
	}
}

void fantasy::drawStatus(int left, int top) {
	int max = 0;
	for (player player : party) {
		if (max < (player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role).length()) {
			max = (player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role).length();
		}
	}
	int i = 0;
	for (player player : party) {
		if (player.current) {
			if (player.selected) { DrawStringAlpha(left + 3 + i, top + 5, L"[" + player.name + L"]", 0x000F); }
			else {				   DrawStringAlpha(left + 4 + i, top + 5, player.name, 0x000F); }

			DrawStringAlpha(left + 3, top + 7, player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role, 0x000F);
			int k = 0;
			for (auto stat : player.stats) {
				DrawStringAlpha(left + 5, top + 8 + k, player.stats[k].name + L": " + to_wstring(player.stats[k].value), 0x000F);
				k++;
			}
			DrawStringAlpha(left + max + 9, top + 15, L"HP: " + to_wstring(player.HP) + L"/" + to_wstring(player.maxHP), 0x000F);
			DrawStringAlpha(left + max + 9, top + 16, L"MP: " + to_wstring(player.MP) + L"/" + to_wstring(player.maxMP), 0x000F);
			DrawStringAlpha(left + max + 9, top + 17, L"XP: " + to_wstring(player.EXP) + L"/" + to_wstring(player.nextLevel), 0x000F);
			DrawStringAlpha(left + max + 9, top + 18, L"Total XP: " + to_wstring(player.totalEXP), 0x000F);
			drawSkills(left + max + 9, top + 9, player);
		}
		else {
			DrawStringAlpha(left + 4 + i, top + 5, player.name, 0x000F);
		}
		i = i + player.name.length() + 2;
	}
}

void fantasy::drawSkills(int left, int top, player you) {
	vector<wstring> skills;
	int i = 0;
	for (ability skill : you.skills) {
		if (skill.selected) { skills.push_back(L"[" + skill.name + L"]"); }
		else {				  skills.push_back(L" " + skill.name + L" "); }
		i++;
	}
	drawWindow(left, top, skills);
}
void fantasy::drawItems(int left, int top) {
	int i = 0;
	for (item item : inventory) {
		if (item.selected) { DrawStringAlpha(left + 4, top + header_rows + i, L"[" + item.name + L"]", 0x000F); }
		else {				 DrawStringAlpha(left + 5, top + header_rows + i, item.name, 0x000F); }
		i++;
	}
}
void fantasy::drawEquipment(int start) {
}

void fantasy::drawBattle() {
	int margin = 15;

	int left = margin;
	int right = ScreenWidth() - margin;
	int top = (margin / 2) + (header_rows / 2);
	int bottom = ScreenHeight() - (margin / 2) + (header_rows / 2);

	if (current == normal_battle && enemy < here.monsters.size()) {
		drawWindow(left, right, top, bottom, L"Battle!: " + here.monsters[enemy].name + L" vs. " + party.front().name);
	}

	// message
	DrawStringAlpha(left + 4, top + 3, L"Are you sure you want to win?", 0x000F);
	DrawStringAlpha(left + 4, top + 4, L"[Y] Yes [N] No", 0x000F);

	if (fight.current == fight.hero) { DrawStringAlpha(left + 4, top + 5, L"Player Turn", 0x000F); }
	else {							   DrawStringAlpha(left + 4, top + 5, L"Enemy Turn", 0x000F); }

	// draw party
	int i = 0;
	for (player hero : fight.heroes) {
		Draw((ScreenWidth() * 3) / 4, ScreenHeight() / 2 + (header_rows / 2) + (i * 2), hero.name[0], FG_WHITE);
		DrawStringAlpha(((left + right) / 2) + 2, bottom - fight.heroes.size() + i, hero.name + L" HP" + to_wstring(hero.HP) + L"/" + to_wstring(hero.maxHP), 0x000F);
		if (hero.current) {
			Draw((ScreenWidth() * 3) / 4, ScreenHeight() / 2 + (header_rows / 2) + (i * 2) - 1, L"\u2193"[0], FG_WHITE);
			drawSkills((ScreenWidth() * 3) / 4, 30, hero);
		}
		if (hero.selected) {
			Draw((ScreenWidth() * 3) / 4 - 1, ScreenHeight() / 2 + (header_rows / 2) + (i * 2), L"\u2192"[0], FG_WHITE);
		}
		i++;
	}

	// draw monster
	int j = 0;
	if (current == normal_battle && enemy < here.monsters.size()) {
		for (monster monster : fight.enemies) {
			Draw(ScreenWidth() / 4, ScreenHeight() / 2 + (header_rows / 2) + (j * 2), monster.icon, monster.color);
			DrawStringAlpha(left + 2, bottom - fight.enemies.size() + j, monster.name + L" HP" + to_wstring(monster.HP) + L"/" + to_wstring(monster.maxHP), 0x000F);
			if (monster.current) {
				Draw(ScreenWidth() / 4, ScreenHeight() / 2 + (header_rows / 2) + (j * 2) - 1, L"\u2193"[0], monster.color);
			}
			if (monster.selected) {
				Draw(ScreenWidth() / 4 + 1, ScreenHeight() / 2 + (header_rows / 2) + (j * 2) - 1, L"\u2190"[0], monster.color);
			}
			j++;
		}
	}


}

void fantasy::drawQuit() {
	vector<wstring> text;
	text.push_back(L"Quit?");
	text.push_back(L"");
	text.push_back(L"Are you sure you want to quit?");
	text.push_back(L"[Y] Yes [N] No");
	drawWindow(text);
}

void fantasy::drawGameOver() {
	vector<wstring> text;
	text.push_back(L"Game Over!");
	// text.push_back(L"");
	drawWindow(text);
}

void fantasy::isSolid() {
	for (place place : here.places) {
		if (((m_keys[left].bPressed) && (place.y == party.front().y) && (place.x + 1 == party.front().x))	||
			((m_keys[up].bPressed) && (place.x == party.front().x) && (place.y + 1 == party.front().y))		||
			((m_keys[right].bPressed) && (place.y == party.front().y) && (place.x - 1 == party.front().x))  ||
			((m_keys[down].bPressed) && (place.x == party.front().x) && (place.y - 1 == party.front().y)))
		{
			if (place.solid) { move = false; break; }
		}
	}
}

int fantasy::isMonster() {
	int i = 0;
	for (monster monster : here.monsters) {
		if (((monster.y == party.front().y) && ((monster.x + 1 == party.front().x) || (monster.x - 1 == party.front().x))) ||
			((monster.x == party.front().x) && ((monster.y + 1 == party.front().y) || (monster.y - 1 == party.front().y))))
		{ current = normal_battle; fight = battle(party, monster); break; }	i ++; }
	return i;
}
