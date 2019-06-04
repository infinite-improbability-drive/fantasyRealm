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
// #include "item.cpp"
#include "player.cpp"
#include "realm.cpp"
#include <Windows.h>


wstring input();

class fantasy : public olcConsoleGameEngine {
public:
	fantasy() {
		m_sAppName = L"fantasy realm";
	}
	void start();
	void drawHeader();
	void drawMessage(player player);
	void drawMenu();
	void drawBattle();
	void drawQuit();
	void isSolid();
	int isMonster();

private:
	vector<player> party;
	player player1;
	player someone;
	realm here;
	realm r;
	enum mode {play, pause, talk, menu, shop, battle, random_battle, quit};
	enum menu {status, items, equipment};
	vector<wstring> actions;
	vector<wstring> menu_actions = { L"Status", L"Items", L"Equipment", L"Exit" };
	vector<item> inventory;
	mode current;
	bool move;
	int enemy;

protected:
	virtual bool OnUserCreate() {
		// seed random number generator
		// int r = rand() % 1000;
		mode current = play;
		move = true;
		srand(clock() + time(nullptr));
		party.push_back(player1);
		const realm here = realm(player1.wits, player1.brave);
		return true;
	}

	virtual bool OnUpdate() {
		if (current == play) {
			int i = 0;
			// move monsters
			for (monster monster : here.monsters) {
				int randomize = rand() % 4096 + 1;
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

	virtual bool OnUserUpdate(float fElapsedTime) {

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

								// here = location;
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

		if (current == talk) {
			for (int i = 0; i < 256; i++) {
				if (m_keys[i].bPressed) {
					current = play;
				}
			}
		}
		// [M] menu
		if (m_keys[77].bPressed) {
			if (std::find(actions.begin(), actions.end(), L"Menu") != actions.end()) {
				current = menu;
			}
			else {
				actions.push_back(L"Menu");
			}
		}
			// [S] status
			if (m_keys[83].bPressed && current == menu) {
				current = play;
			}
			// [I] items
			if (m_keys[73].bPressed && current == menu) {
				current = play;
			}
			// [Q] equipment
			if (m_keys[81].bPressed && current == menu) {
				current = play;
			}
			// [E] return to game
			if (m_keys[69].bPressed && current == menu) {
				current = play;
			}

		// [T] talk
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

			// [Y] quit game
			if ((m_keys[89].bPressed) && current == quit) {
				exit(0);
			}

			// [N] return to game
			if (m_keys[78].bPressed && current == quit) {
				current = play;
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
		for (place place : here.places) {
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
		}

		// draw player1
		Draw(ScreenWidth() / 2, ScreenHeight() / 2 + (5 / 2), player1.name[0], FG_WHITE);

		// draw someone
		if (here.type.compare(L"realm") != 0) {
			Draw((int)(ScreenWidth() / 2) + someone.x - player1.x, (int)(ScreenHeight() / 2) + (5 / 2) + someone.y - player1.y, someone.name[0], FG_WHITE);
		}

		// draw menus
		if (current == talk) { drawMessage(someone); }		// draw message
		if (current == menu) {	 drawMenu(); }		// draw menu
		if (current == battle) { drawBattle(); }	// draw battle
		if (current == quit) {	 drawQuit(); }		// draw quit


		return true;
	}

};


int main() {

	// set character set to Unicode-16
	_setmode(_fileno(stdout), _O_U16TEXT);

	// username = start();


	// use olcConsoleGameEngine derived app
	static fantasy game;
	game.start();

	game.ConstructConsole(150, 40, 8, 16);
	game.Start();

	return 0;
}


void fantasy::start() {

	wprintf(L"Welcome to the fantasy realm.\n");

	wprintf(L"Please enter your name:\n");
	player1.name = input();

	wprintf(L"Please choose your class-\n");
	wstring roles[] = { L"Bard", L"Knight", L"Sorcerer" };
	for (wstring role : roles) {
		if (role != roles[roles->length() - 2]) {
			wcout << role << ", ";
		}
		else {
			wcout << role << ". ";
		}
	}
	wprintf(L"\n");
	player1.role = input();
	player1.weapon = weapon();
	player1.ability = ability();

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

	wcout << "Hello " << player1.name << " the " << player1.role << ".\n";
	wcout << "The " << player1.role << " class uses the ability " << player1.ability.name << " and the " << player1.weapon.name << " starting weapon.\n";

	system("pause");
	// wprintf(L"Press enter to begin:\n");
	// string enter;
	// while ((0x8000 & GetAsyncKeyState((unsigned char)('\x12'))) != 0); {
	// 	input();
	// }
}

wstring input() {
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

void fantasy::drawMessage(player player) {

	int width = player.speak(player.disgust).length() + 4;
	int height = 5;
	int offset = 5;

	int left = (int)(ScreenWidth() / 2) + player.x - player1.x - (width / 2);
	int right = (int)(ScreenWidth() / 2) + player.x - player1.x + (width / 2);
	int top = (int)(ScreenHeight() / 2) + (5 / 2) - player.y + player1.y - (height / 2) - offset;
	int bottom = (int)(ScreenHeight() / 2) + (5 / 2) - player.y + player1.y + (height / 2) - offset;


	// border
	DrawLine(left, top, left, bottom, 0x007C, FG_WHITE);	// left
	DrawLine(left, top, right, top, 0x002D, FG_WHITE);		// top
	DrawLine(right, top, right, bottom, 0x007C, FG_WHITE);	// right
	DrawLine(left, bottom, right, bottom, 0x002D, FG_WHITE);	// bottom

	// Draw((int) (ScreenWidth() / 2) + someone.x - player1.x, (int) (ScreenHeight() / 2) + (5 / 2) + someone.y - player1.y, someone.name[0], FG_WHITE);


	// name
	DrawStringAlpha(left + 2, top + 1, player.name, 0x000F);

	// message
	DrawStringAlpha(left + 2, top + 3, player.speak(player.disgust), 0x000F);

	// if (player.speak.next != nullptr) {}
}

void fantasy::drawMenu() {
	int margin = 10;

	DrawLine(margin, ScreenHeight() - margin, margin, margin, 0x007C, FG_WHITE);									// left		'|'
	DrawLine(margin, margin, ScreenWidth() - margin, margin, 0x002D, FG_WHITE);										// top		'-'
	DrawLine(ScreenWidth() - margin, margin, ScreenWidth() - margin, ScreenHeight() - margin, 0x007C, FG_WHITE);	// right	'|'
	DrawLine(margin, ScreenHeight() - margin, ScreenWidth() - margin, ScreenHeight() - margin, 0x002D, FG_WHITE);	// bottom	'-'

	// title
	DrawStringAlpha(margin + 3, margin + 1, L"Menu", 0x000F);

	// menu commands
	int i = menu_actions[0].length();
	for (wstring action : menu_actions) {
		DrawStringAlpha(margin + 3 + i, margin + 3, action, 0x000F);
		i = i + action.length() + 2;
	}
}

void fantasy::drawBattle() {
	int margin = 25;

	Fill(margin, margin, ScreenWidth() - margin, ScreenHeight() - margin, L' ');

	DrawLine(margin, ScreenHeight() - margin, margin, margin, 0x007C, FG_WHITE);									// left
	DrawLine(margin, margin, ScreenWidth() - margin, margin, 0x002D, FG_WHITE);										// top
	DrawLine(ScreenWidth() - margin, margin, ScreenWidth() - margin, ScreenHeight() - margin, 0x007C, FG_WHITE);	// right
	DrawLine(margin, ScreenHeight() - margin, ScreenWidth() - margin, ScreenHeight() - margin, 0x002D, FG_WHITE);	// bottom

	// title
	DrawStringAlpha(margin + 3, margin + 1 - 10, L"Battle!     " + here.monsters[enemy].name + L" vs. " + player1.name, 0x000F);

	// message
	DrawStringAlpha(margin + 7, margin + 1 - 8, L"Are you sure you want to win?", 0x000F);
	DrawStringAlpha(margin + 7, margin + 1 - 6, L"[Y] Yes [N] No", 0x000F);
}

void fantasy::drawQuit() {
	int margin = 25;

	Fill(margin, margin, ScreenWidth() - margin, ScreenHeight() - margin, L' ');

	DrawLine(margin, ScreenHeight() - margin, margin, margin, 0x007C, FG_WHITE);									// left
	DrawLine(margin, margin, ScreenWidth() - margin, margin, 0x002D, FG_WHITE);										// top
	DrawLine(ScreenWidth() - margin, margin, ScreenWidth() - margin, ScreenHeight() - margin, 0x007C, FG_WHITE);	// right
	DrawLine(margin, ScreenHeight() - margin, ScreenWidth() - margin, ScreenHeight() - margin, 0x002D, FG_WHITE);	// bottom

	// title
	DrawStringAlpha(margin + 3, margin + 1 - 10, L"Quit?", 0x000F);

	// message
	DrawStringAlpha(margin + 7, margin + 1 - 8, L"Are you sure you want to quit?", 0x000F);
	DrawStringAlpha(margin + 7, margin + 1 - 6, L"[Y] Yes [N] No", 0x000F);
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


