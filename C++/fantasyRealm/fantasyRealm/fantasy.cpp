/*
OneLoneCoder.com - Command Line player
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
Classic player! Controls are Arrow keys Left & Right, eat food, grow larger, avoid self!
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
#include <cstdlib>
#include <iostream>
#include <list>
#include <locale>
#include <string>
#include <thread>
#include <fcntl.h>
#include <io.h>
#include <time.h>
#include <wchar.h>

using namespace std;

#include "olcConsoleGameEngine.h"
#include "realm.cpp"
#include <Windows.h>

wstring userrole;


wstring input();


class fantasy : public olcConsoleGameEngine {
public:
	fantasy() {
		m_sAppName = L"fantasy realm";
	}
	void start();
	void drawHeader();
	void drawMenu();
	void drawQuit();

private:
	struct player {
		wstring name;
		wstring role;
		vector<wstring> actions;
		vector<wstring> menu_actions = {L"Status", L"Items", L"Equipment", L"Exit"};
		int wits;
		int brave;
		int x;
		int y;
	};
	player player;
	realm here;
	realm r;
	enum mode {play, pause, menu, quit};
	enum menu {status, items, equipment};
	mode current;

protected:
	virtual bool OnUserCreate() {
		// seed random number generator
		// int r = rand() % 1000;
		mode current = play;
		srand(clock() + time(nullptr));
		const realm here = realm(player.wits);
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {

		// clear screen
		Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

// -------- LOGIC --------

		if (current == play) {
			// move player
			if (m_keys[0x25].bPressed)
				player.x -= 1;
			if (m_keys[0x26].bPressed)
				player.y -= 1;
			if (m_keys[0x27].bPressed)
				player.x += 1;
			if (m_keys[0x28].bPressed)
				player.y += 1;
		}

		// print current key
		for (int i = 0; i < 256; i++) {
			if (m_keys[i].bHeld) {
				DrawStringAlpha(2, 3, L"You are pressing " + to_wstring(i), 0x000F);
			}
		}

		// [ENTER] enter location
		if (m_keys[13].bPressed) {
			if (std::find(player.actions.begin(), player.actions.end(), L"Enter") != player.actions.end()) {
				for (place place : here.places) {
					if (player.x == place.x && player.y == place.y) {
						if (place.type == L"exit") {
							player.x = here.x;
							player.y = here.y;
							here = r;
							break;
						}
						else {
							realm location = realm(place.name, place.type, &here, place.x, place.y);
							r = here;
							here = location;
							here.parent = &r;
							player.x = rand() % 20 - 10;
							player.y = rand() % 20 - 10;
							// here = location;
							break;
						}
					}
				}
			}
			else {
				player.actions.push_back(L"Enter");
			}
		}		
		
		// [M] menu
		if (m_keys[77].bPressed) {
			if (std::find(player.actions.begin(), player.actions.end(), L"Menu") != player.actions.end()) {
				current = menu;
			}
			else {
				player.actions.push_back(L"Menu");
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


		// [Q] quit
		if (m_keys[81].bPressed) {
			if (std::find(player.actions.begin(), player.actions.end(), L"Quit") != player.actions.end()) {
				current = quit;
			}
			else {
				player.actions.push_back(L"Quit");
			}
		}

			// [Y] quit game
			if (m_keys[89].bPressed && current == quit) {
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
			if (((int)(ScreenHeight() / 2) + place.y - player.y) > 5) {
				Draw((int)(ScreenWidth() / 2) + place.x - player.x, (int)(ScreenHeight() / 2) + (5 / 2) + place.y - player.y, place.name[0], FG_WHITE);
			}
		}

		// draw map hints


		// draw player
		Draw(ScreenWidth() / 2, ScreenHeight() / 2 + (5 / 2), player.name[0], FG_WHITE);

		// draw menu
		if (current == menu) {
			drawMenu();
		}

		// draw quit
		if (current == quit) {
			drawQuit();
		}

		return true;
	}
};


int main() {

	// set character set to Unicode-16
	// _setmode(_fileno(stdout), _O_U16TEXT);

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
	player.name = input();

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
	player.role = input();

	wprintf(L"You must think you're pretty clever.\n");
	wprintf(L"Just how clever are you? (1-10):\n");
	cin >> player.wits;

	wprintf(L"You must be brave to traverse these realms.\n");
	wprintf(L"How brave do you think you are? (1-10):\n");
	cin >> player.brave;

	player.x = 10;
	player.y = 10;

	wcout << "Hello " << player.name << " the " << player.role << ".\n";
	wprintf(L"Press enter to begin:\n");
	// string enter;
	while ((0x8000 & GetAsyncKeyState((unsigned char)('\x12'))) != 0); {
		input();
	}
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

	// player title
	wstring title = L"" + player.name + L" the Lv 1 " + player.role;
	DrawStringAlpha(ScreenWidth() - title.length() - 2, 1, title, 0x000F);
	// player position
	DrawStringAlpha(ScreenWidth() - title.length() - 9, 1, L"y = " + to_wstring(-player.y), 0x000F);
	DrawStringAlpha(ScreenWidth() - title.length() - 16, 1, L"x = " + to_wstring(player.x), 0x000F);

	// collision detection
	for (place place : here.places) {
		if (player.x == place.x && player.y == place.y) {
			DrawStringAlpha(2, 2, L"You have arrived at " + place.name + L" type = " + place.type, 0x000F);
		}
	}

	// commands
	int i = 2;
	for (wstring action : player.actions) {
		DrawStringAlpha(i, 4, action, 0x000F);
		i = i + action.length() + 2;
	}

	// bottom border
	DrawLine(0, 5, ScreenWidth(), 5, 0x003D, FG_WHITE);
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
	int i = player.menu_actions[0].length();
	for (wstring action : player.menu_actions) {
		DrawStringAlpha(margin + 3 + i, margin + 3, action, 0x000F);
		i = i + action.length() + 2;
	}
}

void fantasy::drawQuit() {
	int margin = 25;

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
