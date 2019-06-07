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
#include <codecvt>
#include <ctime>
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
	// party.push_back(party.front());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item());
	inventory.push_back(item(L"Map Crystal"));
	const realm here = realm(party.front().wits, party.front().brave);
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

		// move party.front()
		// left
		if (m_keys[0x25].bPressed) {
			// check if solid 
			for (place place : here.places) {
				if ((place.y == party.front().y) && (place.x + 1 == party.front().x)) {
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
				party.front().x -= 1; 
			}
		}
		// up
		if (m_keys[0x26].bPressed) {
			// check if solid object
			for (place place : here.places) {
				if ((place.x == party.front().x) && (place.y + 1 == party.front().y)) {
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
				party.front().y -= 1;
			}
		}
		// right
		if (m_keys[0x27].bPressed) {	// right
			for (place place : here.places) {
				if ((place.y == party.front().y) && (place.x - 1 == party.front().x)) {
					if (place.solid) {
						move = false;
						break;
					}
				}
			}
			// check if monster
			enemy = isMonster();

			if (move) {
				party.front().x += 1; 
			}
		}
		// down
		if (m_keys[0x28].bPressed) {	// down
			for (place place : here.places) {
				if ((place.x == party.front().x) && (place.y - 1 == party.front().y)) {
					if (place.solid) {
						move = false;
						break;
					}
				}
			}
			// check if monster
			enemy = isMonster();

			if (move) {
				party.front().y += 1; 
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
					if (party.front().x == place.x && party.front().y == place.y) {
						if (place.type == L"exit") {
							party.front().x = here.x;
							party.front().y = here.y;
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
							party.front().x = rand() % (width - 2) + 1;
							party.front().y = rand() % (height - 2) + 1;
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
				// current_player = party.front();
				party.front().selected = true;
				menu_actions.find(current_menu)->second.second = false;
			}
			// if (current_menu != main) { menu_actions.find(current_menu)->second.second = true; }
		}
		else if (current_menu == status) {
			// menu_actions.find(current_menu)->second.second = true;
			// left
			if (m_keys[0x25].bPressed) { 
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
					// int i = 0;
					int j = 0;
					for (player member : party) {
						if (member.current) {
							party[j].selected = true;
							int k = 0;
							for (ability skill : member.skills) {
								// if (party[j].skills[0].selected) {
								party[j].skills[k].selected = false;
									// break;
								// }
								// else if (party[j].skills[k].selected) {
									// party[j].skills[k].selected = false;
									// party[j].skills[k - 1].selected = true;
									// break;
								// }
								k++;
							}
							break;
						}
						j++;
						// break;
						// i++;
					}
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
					current_menu = items;
				}
			}
			// up
			else if (m_keys[0x26].bPressed) {
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
						// break;
						// i++;
					}
				}
			}
			// down
			else if (m_keys[0x28].bPressed) {
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
				// current_player = party.front();
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
			if (party.front().x == someone.x && party.front().y == someone.y) {
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
		if (((int) (ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y) > header_rows) {
			Draw((int) (ScreenWidth() / 2) + place.x - party.front().x, (int) (ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y, place.name[0], FG_WHITE);
		}
	}

	// draw monsters
	for (monster monster : here.monsters) {
		if (((int) (ScreenHeight() / 2) + (header_rows / 2) + monster.y - party.front().y) > header_rows) {
			Draw((int) (ScreenWidth() / 2) + monster.x - party.front().x, (int) (ScreenHeight() / 2) + (header_rows / 2) + monster.y - party.front().y, monster.icon, monster.color);
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
				if (((int)(ScreenHeight() / 2) + (header_rows / 2) + place.y - party.front().y) <= header_rows) {
					Draw((int)(ScreenWidth() / 2) + place.x - party.front().x, header_rows + 1, L"^"[0], FG_WHITE);
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
			// }
		// }
		// i++;
	}

	// draw party.front()
	Draw(ScreenWidth() / 2, ScreenHeight() / 2 + (header_rows / 2), party.front().name[0], FG_WHITE);

	// draw someone
	if (here.type.compare(L"realm") != 0) {
		Draw((int)(ScreenWidth() / 2) + someone.x - party.front().x, (int)(ScreenHeight() / 2) + (header_rows / 2) + someone.y - party.front().y, someone.name[0], FG_WHITE);
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
	wstring name = input();

	if (name == L"") { name = names::fullName(); }

	wprintf(L"Please choose your class-\n");
	wstring roles[] = { L"Bard", L"Knight", L"Sorcerer" };
	for (wstring r : roles) {
		if (r != roles[roles->length() - 2]) {
			wcout << r << ", ";
		}
		else {
			wcout << r << ".\n";
		}
	}
	wstring role = input();
	bool isRole;
	for (wstring r : roles) {
		if (role == r) {
			isRole = true;
		}
		else {
			isRole = false;
		}

	}
	if (!isRole) { role = L"Fool"; }

	wprintf(L"You must think you're pretty clever.\n");
	wprintf(L"Just how clever are you? (1-10):\n");
	int wits;
	cin >> wits;
	while (wits < 1 || wits > 11) {
		wprintf(L"Try again. \n");
		wprintf(L"Just how clever are you? (1-10):\n");
		cin >> wits;
	}

	wprintf(L"You must be brave to traverse these realms.\n");
	wprintf(L"How brave do you think you are? (1-10):\n");
	int brave;
	cin >> brave;
	while (brave < 1 || brave > 11) {
		wprintf(L"Just how brave are you, really? (1-10):\n");
		cin >> brave;
	}


	wcout << "Hello " << name << " the " << role << ".\n";
	party.push_back(player(name, role, wits, brave));
	wcout << "The " << party.front().role << " class uses the ability " << party.front().name << " and the " << party.front()._weapon.name << " starting weapon.\n";

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

	// time_t rawtime;
	// time(&rawtime);
	// ctime(&rawtime);
	// std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringAlpha(2, 5, to_wstring(timenow), 0x000F);

	// bottom border
	header_rows = 6;
	DrawLine(0, header_rows, ScreenWidth(), header_rows, 0x003D, FG_WHITE);
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

	int left = (int)(ScreenWidth() / 2) + player.x - party.front().x - (width / 2);
	int right = (int)(ScreenWidth() / 2) + player.x - party.front().x + (width / 2);
	int top = (int)(ScreenHeight() / 2) + (header_rows / 2) - player.y + party.front().y - (height / 2) - offset;
	int bottom = (int)(ScreenHeight() / 2) + (header_rows / 2) - player.y + party.front().y + (height / 2) - offset;

	drawWindow(left, right, top, bottom, player.name);

	// message
	DrawStringAlpha(left + 2, top + 3, player.speak(message), 0x000F);

	// if (player.speak.next != nullptr) {}
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

	if (current_menu == party_menu) { drawParty(top, left); }
	else if (current_menu == status) { drawStatus(top, left); }
	else if (current_menu == items) { drawItems(top); }
	else if (current_menu == equipment) { drawEquipment(top); }

}

void fantasy::drawParty(int top, int left) {
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
void fantasy::drawStatus(int top, int left) {
	int i = 0;
	for (player player : party) {
		if (player.current) {
			if (player.selected) {
				DrawStringAlpha(left + 3 + i, top + 5, L"[" + player.name + L"]", 0x000F);
			}
			else {
				DrawStringAlpha(left + 4 + i, top + 5, player.name, 0x000F);
			}
			// DrawStringAlpha(left + 3 + i, top + 5, L"[" + player.name + L"]", 0x000F);
			DrawStringAlpha(left + 3, top + 7, player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role, 0x000F);
			int k = 0;
			for (auto stat : player.stats) {
				DrawStringAlpha(left + 5, top + 8 + k, player.stats[k].name + L": " + to_wstring(player.stats[k].value), 0x000F);
				k++;
			}
			drawSkills(top, left, player);
		}
		else {
			DrawStringAlpha(left + 4 + i, top + 5, player.name, 0x000F);
		}
		i = i + player.name.length() + 2;
	}
}

void fantasy::drawSkills(int top, int left, player you) {
	int max = 0;
	for (player player : party) {
		if (max < (player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role).length()) {
			max = (player.name + L" the Lv" + to_wstring(player.level) + L" " + player.role).length();
		}
	}
	int i = 0;
	for (ability skill : you.skills) {
		if (skill.selected) {
			DrawStringAlpha(left + max + 9, top + 9 + i, L"[" + skill.name + L"]", 0x000F);
		}
		else {
			DrawStringAlpha(left + max + 10, top + 9 + i, skill.name, 0x000F);
		}
		i++;
	}
}
void fantasy::drawItems(int start) {
	int i = 0;
	for (item item : inventory) {
		DrawStringAlpha(start + 4, start + header_rows + i, item.name, 0x000F);
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

	if (current == battle && enemy < here.monsters.size()) {
		drawWindow(left, right, top, bottom, L"Battle!: " + here.monsters[enemy].name + L" vs. " + party.front().name);
	}

	// message
	DrawStringAlpha(left + 4, top + 3, L"Are you sure you want to win?", 0x000F);
	DrawStringAlpha(left + 4, top + 4, L"[Y] Yes [N] No", 0x000F);

	// draw party.front()
	Draw((ScreenWidth() * 3) / 4, ScreenHeight() / 2 + (header_rows / 2), party.front().name[0], FG_WHITE);

	// draw monster
	if (current == battle && enemy < here.monsters.size()) {
		Draw(ScreenWidth() / 4, ScreenHeight() / 2 + (header_rows / 2), here.monsters[enemy].icon, here.monsters[enemy].color);
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
		if (((monster.y == party.front().y) && ((monster.x + 1 == party.front().x) || (monster.x - 1 == party.front().x))) || 
			((monster.x == party.front().x) && ((monster.y + 1 == party.front().y) || (monster.y - 1 == party.front().y)))) {
			current = battle;

			// return i;
			// here.monsters.erase(here.monsters.begin() + i);
			break;
		}
		i += 1;
	}
	return i;
}


