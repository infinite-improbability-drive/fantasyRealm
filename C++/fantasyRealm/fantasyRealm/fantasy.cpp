/*
OneLoneCoder.com - Command Line player1
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
Classic player1! Controls are Arrow keys Left & Right, eat food, grow larger, avoid self!
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
#include <codecvt>
// #include <cstdlib>
#include <iostream>
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
	srand(clock() + time(nullptr));
	mode current = play;
	menu current_menu = main;
	move = true;
	party.push_back(player1);
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item(L"Map Crystal"));
	const realm here = realm(player1.wits, player1.brave);
	return true;
}

bool fantasy::OnUpdate() {
	if (current == play) {
		int i = 0;
		// move monsters
		for (monster monster : here.monsters) {
			int randomize = rand() % 10000 + 1;
			if (randomize == 1) {
				monster.x += 1;
			}
			else if (randomize == 2) {
				monster.y += 1;
			}
			else if (randomize == 3) {
				monster.x -= 1;
			}
			else if (randomize == 4) {
				monster.y -= 1;
			}
			else if (randomize == 5) {
				monster.x += 1;
				monster.y += 1;
			}
			else if (randomize == 6) {
				monster.x += 1;
				monster.y -= 1;
			}
			else if (randomize == 7) {
				monster.y += 1;
				monster.x -= 1;
			}
			else if (randomize == 8) {
				monster.x -= 1;
				monster.y -= 1;
			}
			else {
			}
			here.monsters[i] = monster;
			i += 1;
		}
	}
	return true;
}

bool fantasy::OnUserUpdate(float fElapsedTime) {

	// clear screen
	Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

// -------- LOGIC --------

	if (current == play) {

		// move player1
		// left
		if (m_keys[0x25].bPressed) {
			// check if solid 
			for (place place : here.places) {
				if ((place.y == player1.y) && (place.x + 1 == player1.x)) {
					if (place.solid) {
						move = false;
						break;
					}
				}
			}
			// check if monster
			enemy = isMonster();

			// move
			if (move) {
				player1.x -= 1; 
			}
		}
		// up
		if (m_keys[0x26].bPressed) {
			// check if solid object
			for (place place : here.places) {
				if ((place.x == player1.x) && (place.y + 1 == player1.y)) {
					if (place.solid) {
						move = false;
						break;
					}
				}
			}
			// check if monster
			enemy = isMonster();

			// move
			if (move) {
				player1.y -= 1;
			}
		}
		// right
		if (m_keys[0x27].bPressed) {	// right
			for (place place : here.places) {
				if ((place.y == player1.y) && (place.x - 1 == player1.x)) {
					if (place.solid) {
						move = false;
						break;
					}
				}
			}
			// check if monster
			enemy = isMonster();

			if (move) {
				player1.x += 1; 
			}
		}
		// down
		if (m_keys[0x28].bPressed) {	// down
			for (place place : here.places) {
				if ((place.x == player1.x) && (place.y - 1 == player1.y)) {
					if (place.solid) {
						move = false;
						break;
					}
				}
			}
			// check if monster
			enemy = isMonster();

			if (move) {
				player1.y += 1; 
			}
		}

		// random battle
		if ((m_keys[0x25].bPressed || m_keys[0x26].bPressed || m_keys[0x27].bPressed || m_keys[0x28].bPressed) && move) {
			if (rand() % 10000 < 2) {
				current = random_battle;
			}
		}
		move = true;
		// [ENTER] enter location
		if (m_keys[13].bPressed) {
			if (std::find(actions.begin(), actions.end(), L"Enter") != actions.end()) {
				for (place place : here.places) {
					if (player1.x == place.x && player1.y == place.y) {
						if (place.type == L"exit") {
							player1.x = here.x;
							player1.y = here.y;
							here = r;
							break;
						}
						else {
							int width = 60;
							int height = 30;
							realm location = realm(place, &here, width, height);
							r = here;
							here = location;
							here.parent = &r;
							player1.x = rand() % (width - 2) + 1;
							player1.y = rand() % (height - 2) + 1;
							someone = player();
							someone.x = rand() % (width - 2) + 1;
							someone.y = rand() % (height - 2) + 1;
							npcs.push_back(someone);
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
	if (m_keys[77].bPressed) {
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
			// left
			if (m_keys[0x25].bPressed) {
				current_menu = exit_menu;
				menu_actions.find(current_menu)->second.second = true;
			}
			// right
			else if (m_keys[0x27].bPressed) { 
				current_menu = party_menu; 
				menu_actions.find(current_menu)->second.second = true;
			}
		}

		// party
		else if (current_menu == party_menu) {
			// left
			if (m_keys[0x25].bPressed) { 
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
			// right
			else if (m_keys[0x27].bPressed) { 
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
			// up
			else if (m_keys[0x26].bPressed) {
				int i = 0;
				for (player member : party) { party[i].selected = false; i++; }
				// current_player = nobody;
				menu_actions.find(current_menu)->second.second = true;
			}
			// down
			else if (m_keys[0x28].bPressed) {
				// current_player = player1; 
				party.front().selected = true;
				menu_actions.find(current_menu)->second.second = false;
			}
			// if (current_menu != main) { menu_actions.find(current_menu)->second.second = true; }
		}
		else if (current_menu == status) {
			// menu_actions.find(current_menu)->second.second = true;
			// left
			if (m_keys[0x25].bPressed) { 
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
					current_menu = party_menu;
					// current_player = nobody;
					menu_actions.find(current_menu)->second.second = true;
				}
			}
			// right
			else if (m_keys[0x27].bPressed) { 
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
					current_menu = items;
				}
			}
			// up
			else if (m_keys[0x26].bPressed) {
				int i = 0;
				for (player member : party) { party[i].selected = false; i++; }
				menu_actions.find(current_menu)->second.second = true;
			}
			// down
			else if (m_keys[0x28].bPressed) {
				// current_player = player1;
				party.front().selected = true;
				menu_actions.find(current_menu)->second.second = false;
			}
		}
		else if (current_menu == items) {
			if (m_keys[0x25].bPressed) { current_menu = status; }			// left
			else if (m_keys[0x27].bPressed) { current_menu = equipment; }	// right
			menu_actions.find(current_menu)->second.second = true;
		}
		else if (current_menu == equipment) {
			if (m_keys[0x25].bPressed) { current_menu = items; }			// left
			else if (m_keys[0x27].bPressed) { current_menu = exit_menu; }	// right
			menu_actions.find(current_menu)->second.second = true;
		}
		else if (current_menu == exit_menu) {
			if (m_keys[0x25].bPressed) { current_menu = equipment; }		// left
			else if (m_keys[0x27].bPressed) { current_menu = main; }		// right
			else if (m_keys[13].bPressed) { current = play; }				// enter
			if (current_menu != main) { menu_actions.find(current_menu)->second.second = true; }
		}

		// if (current_menu != main && current_player.name == L"") { menu_actions.find(current_menu)->second.second = true; }

		// if (current_menu != party_menu) { current_player = nobody; }
		// else if (current_menu != status) { current_player = nobody; }

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
		if (m_keys[84].bPressed) {
			if (someone.thoughts == someone.greeting) { someone.thoughts = someone.introduction; }
			else if (someone.thoughts == someone.introduction) { someone.thoughts = someone.join; }
		}
		if (m_keys[89].bPressed && someone.thoughts == someone.join) {
			someone.thoughts = someone.joined;
			party.push_back(someone);
			int i = 0;
			for (player npc : npcs) {
				if (npc.x == someone.x && npc.y == someone.y) {
					break;
				}
				i++;
			}
			npcs.erase(npcs.begin() + i);
			someone = nobody;
		}

	}
	if (m_keys[84].bPressed) {
		if (std::find(actions.begin(), actions.end(), L"Talk") != actions.end()) {
			if (player1.x == someone.x && player1.y == someone.y) {
				current = talk;
			}
		}
		else {
			actions.push_back(L"Talk");
		}
	}
	// battle
	// [Y] win battle
	if (current == battle) {
			
	}
		
	// [Y] win battle
	if (m_keys[89].bPressed && current == battle) {
		here.monsters.erase(here.monsters.begin() + enemy);
		current = play;
	}
	// [Y] win battle
	if (m_keys[89].bPressed && current == random_battle) {
		current = play;
	}


	// [Q] quit
	if (m_keys[81].bPressed) {
		if (std::find(actions.begin(), actions.end(), L"Quit") != actions.end()) {
			current = quit;
		}
		else {
			actions.push_back(L"Quit");
		}
	}
	if (current == quit) {
		// [Y] quit game
		if (m_keys[89].bPressed) {
			exit(0);
		}

		// [N] return to game
		if (m_keys[78].bPressed) {
			current = play;
		}
	}

// -------- HEADER --------

	drawHeader();

// -------- GAME WORLD --------

	// draw realm
	for (place place : here.places) {
		if (((int) (ScreenHeight() / 2) + (5 / 2) + place.y - player1.y) > 5) {
			Draw((int) (ScreenWidth() / 2) + place.x - player1.x, (int) (ScreenHeight() / 2) + (5 / 2) + place.y - player1.y, place.name[0], FG_WHITE);
		}
	}

	// draw monsters
	for (monster monster : here.monsters) {
		if (((int) (ScreenHeight() / 2) + (5 / 2) + monster.y - player1.y) > 5) {
			Draw((int) (ScreenWidth() / 2) + monster.x - player1.x, (int) (ScreenHeight() / 2) + (5 / 2) + monster.y - player1.y, monster.icon, monster.color);
		}
	}

	// draw map hints
	// int i = 0;
	// vector<int> j;
	// for (item item : inventory) {
		// if (item.name == L"Map Crystal") {
			// j.push_back(rand() % here.places.size());
		// }
	// }
	for (place place : here.places) {
		// for (int k : j) {
			// if (i == k) {
				// top
				if (((int)(ScreenHeight() / 2) + (5 / 2) + place.y - player1.y) <= 5) {
					Draw((int)(ScreenWidth() / 2) + place.x - player1.x, 6, L"^"[0], FG_WHITE);
				}
				// bottom
				if (((int)(ScreenHeight() / 2) + (5 / 2) + place.y - player1.y) > ScreenHeight() - 1) {
					Draw((int)(ScreenWidth() / 2) + place.x - player1.x, ScreenHeight() - 1, L"v"[0], FG_WHITE);
				}
				// left
				if (((int)(ScreenWidth() / 2) + (5 / 2) + place.x - player1.x) < 2) {
					Draw(0, (int)(ScreenHeight() / 2) + (5 / 2) + place.y - player1.y, L"<"[0], FG_WHITE);
				}
				// right
				if (((int)(ScreenWidth() / 2) + (5 / 2) + place.x - player1.x) > ScreenWidth() + 1) {
					Draw(ScreenWidth() - 1, (int)(ScreenHeight() / 2) + (5 / 2) + place.y - player1.y, L">"[0], FG_WHITE);
				}
			// }
		// }
		// i++;
	}

	// draw player1
	Draw(ScreenWidth() / 2, ScreenHeight() / 2 + (5 / 2), player1.name[0], FG_WHITE);

	// draw someone
	if (here.type.compare(L"realm") != 0) {
		Draw((int)(ScreenWidth() / 2) + someone.x - player1.x, (int)(ScreenHeight() / 2) + (5 / 2) + someone.y - player1.y, someone.name[0], FG_WHITE);
	}

	// draw menus
	if (current == talk) { drawMessage(someone, someone.thoughts); }		// draw message
	if (current == menu_mode) { drawMenu(current_menu); }			// draw menu
	// if (current == status) { drawStatus(); }		// draw status
	// if (current == items) { drawItems(); }			// draw items
	// if (current == equipment) { drawEquipment(); }	// draw equipment
	if (current == battle) { drawBattle(); }		// draw battle
	if (current == quit) {	 drawQuit(); }			// draw quit


	return true;
}

int main() {

	// set character set to Unicode-16
	_setmode(_fileno(stdout), _O_U16TEXT);

	// username = start();


	// use olcConsoleGameEngine derived app
	fantasy game;
	game.start();

	game.ConstructConsole(150, 40, 8, 16);
	game.Start();

	return 0;
}


void fantasy::start() {

	wprintf(L"Welcome to the fantasy realm.\n");
	wprintf(L"Please enter your name:\n");
	player1.name = input();

	if (player1.name == L"") { player1.name = names::fullName(); }

	wprintf(L"Please choose your class-\n");
	wstring roles[] = { L"Bard", L"Knight", L"Sorcerer" };
	for (wstring role : roles) {
		if (role != roles[roles->length() - 2]) {
			wcout << role << ", ";
		}
		else {
			wcout << role << ".\n";
		}
	}
	player1.role = input();
	bool isRole;
	for (wstring role : roles) {
		if (player1.role == role) {
			isRole = true;
		}
		else {
			isRole = false;
		}

	}
	if (!isRole) { player1.role = L"Fool"; }

	wprintf(L"You must think you're pretty clever.\n");
	wprintf(L"Just how clever are you? (1-10):\n");
	cin >> player1.wits;
	while (player1.wits < 1 || player1.wits > 11) {
		wprintf(L"Try again. \n");
		wprintf(L"Just how clever are you? (1-10):\n");
		cin >> player1.wits;
	}

	wprintf(L"You must be brave to traverse these realms.\n");
	wprintf(L"How brave do you think you are? (1-10):\n");
	cin >> player1.brave;
	while (player1.brave < 1 || player1.brave > 11) {
		wprintf(L"Just how brave are you, really? (1-10):\n");
		cin >> player1.brave;
	}

	player1.x = 10;
	player1.y = 10;
	player1.level = 1;

	wcout << "Hello " << player1.name << " the " << player1.role << ".\n";
	wcout << "The " << player1.role << " class uses the ability " << player1.name << " and the " << player1._weapon.name << " starting weapon.\n";

	system("pause");
}

wstring fantasy::input() {
	string out;
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	getline(cin, out);
	return converter.from_bytes(out);
	// std::string narrow = converter.to_bytes(wide_utf16_source_string);
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

	// player1 title
	wstring title = L"" + player1.name + L" the Lv 1 " + player1.role;
	DrawStringAlpha(ScreenWidth() - title.length() - 2, 1, title, 0x000F);
	// player1 position
	DrawStringAlpha(ScreenWidth() - (to_wstring(-player1.y).length() + 6), 2, L"y = " + to_wstring(-player1.y), 0x000F);
	DrawStringAlpha(ScreenWidth() - (to_wstring(player1.x).length() + 6), 3, L"x = " + to_wstring(player1.x), 0x000F);
	// # of monsters
	DrawStringAlpha(ScreenWidth() - (to_wstring(here.monsters.size()).length() + 18), 4, L"# of monsters = " + to_wstring(here.monsters.size()), 0x000F);

	// collision detection
	for (place place : here.places) {
		if (player1.x == place.x && player1.y == place.y) {
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

	// bottom border
	DrawLine(0, 5, ScreenWidth(), 5, 0x003D, FG_WHITE);
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

void fantasy::drawMessage(player player, player::dialogue message) {

	int width = max(player.speak(message).length(), player.name.length()) + 4;
	int height = 5;
	int offset = 4;

	int left = (int)(ScreenWidth() / 2) + player.x - player1.x - (width / 2);
	int right = (int)(ScreenWidth() / 2) + player.x - player1.x + (width / 2);
	int top = (int)(ScreenHeight() / 2) + (5 / 2) - player.y + player1.y - (height / 2) - offset;
	int bottom = (int)(ScreenHeight() / 2) + (5 / 2) - player.y + player1.y + (height / 2) - offset;

	drawWindow(left, right, top, bottom, player.name);

	// message
	DrawStringAlpha(left + 2, top + 3, player.speak(message), 0x000F);

	// if (player.speak.next != nullptr) {}
}

void fantasy::drawMenu(menu item) {
	int margin = 10;

	int left = margin;
	int right = ScreenWidth() - margin;
	int top = margin;
	int bottom = ScreenHeight() - margin;

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

	if (current_menu == party_menu) { drawParty(left); }
	else if (current_menu == status) { drawStatus(left); }
	else if (current_menu == items) { drawItems(left); }
	else if (current_menu == equipment) { drawEquipment(left); }

}

void fantasy::drawParty(int start) {
	int i = 0;
	for (player player : party) {
		if (player.selected) {
			DrawStringAlpha(start + 3 + i, start + 5, L"[" + player.name + L"]", 0x000F);
			DrawStringAlpha(start + 3, start + 7, player.name + L" the " + to_wstring(player.level) + L" " + player.role, 0x000F);

		}
		else {
			DrawStringAlpha(start + 4 + i, start + 5, player.name, 0x000F);
		}
		i = i + player.name.length() + 2;
	}
}
void fantasy::drawStatus(int start) {
	int i = 0;
	for (player player : party) {
		if (player.selected) {
			DrawStringAlpha(start + 3 + i, start + 5, L"[" + player.name + L"]", 0x000F);
			DrawStringAlpha(start + 3, start + 7, player.name + L" the Lv " + to_wstring(player.level) + L" " + player.role, 0x000F);
			int k = 0;
			for (auto stat : player.stats) {
				DrawStringAlpha(start + 5, start + 8 + k, player.stats[k].name + L": " + to_wstring(player.stats[k].value), 0x000F);
				k++;
			}
		}
		else {
			DrawStringAlpha(start + 4 + i, start + 5, player.name, 0x000F);
		}
		i = i + player.name.length() + 2;
	}
}
void fantasy::drawItems(int start) {
	int i = 0;
	for (item item : inventory) {
		DrawStringAlpha(start + 4, start + 5 + i, item.name, 0x000F);
		i++;
	}
}
void fantasy::drawEquipment(int start) {
}

void fantasy::drawBattle() {
	int margin = 15;

	int left = margin;
	int right = ScreenWidth() - margin;
	int top = (margin / 2) + (5 / 2);
	int bottom = ScreenHeight() - (margin / 2) + (5 / 2);

	if (current == battle && enemy < here.monsters.size()) {
		drawWindow(left, right, top, bottom, L"Battle!: " + here.monsters[enemy].name + L" vs. " + player1.name);
	}

	// message
	DrawStringAlpha(left + 4, top + 3, L"Are you sure you want to win?", 0x000F);
	DrawStringAlpha(left + 4, top + 4, L"[Y] Yes [N] No", 0x000F);

	// draw player1
	Draw((ScreenWidth() * 3) / 4, ScreenHeight() / 2 + (5 / 2), player1.name[0], FG_WHITE);

	// draw monster
	if (current == battle && enemy < here.monsters.size()) {
		Draw(ScreenWidth() / 4, ScreenHeight() / 2 + (5 / 2), here.monsters[enemy].icon, here.monsters[enemy].color);
	}

}

void fantasy::drawQuit() {
	int margin = 17;

	int left = margin;
	int right = ScreenWidth() - margin;
	int top = margin;
	int bottom = ScreenHeight() - margin;

	drawWindow(left, right, top, bottom, L"Quit?");

	// message
	DrawStringAlpha(left + 4, top + 3, L"Are you sure you want to quit?", 0x000F);
	DrawStringAlpha(left + 4, top + 4, L"[Y] Yes [N] No", 0x000F);
}

int fantasy::isMonster() {
	// monster mon;
	int i = 0;
	for (monster monster : here.monsters) {
		if (((monster.y == player1.y) && ((monster.x + 1 == player1.x) || (monster.x - 1 == player1.x))) || 
			((monster.x == player1.x) && ((monster.y + 1 == player1.y) || (monster.y - 1 == player1.y)))) {
			current = battle;

			// return i;
			// here.monsters.erase(here.monsters.begin() + i);
			break;
		}
		i += 1;
	}
	return i;
}


