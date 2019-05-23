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
#include <iostream>
#include <list>
#include <string>
#include <thread>
#include <fcntl.h>
#include <io.h>
#include <locale>
#include <codecvt>
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

private:
	struct player {
		int x;
		int y;
		wstring name;
		wstring role;
	};
	player player;
	realm here = realm();

protected:
	virtual bool OnUserCreate() {
		// seed random number generator
		srand(clock());

		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {

		// clear screen
		Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

// -------- LOGIC --------

		// move player
		if (m_keys[0x25].bPressed)
			player.x -= 1;
		if (m_keys[0x26].bPressed)
			player.y -= 1;
		if (m_keys[0x27].bPressed)
			player.x += 1;
		if (m_keys[0x28].bPressed)
			player.y += 1;

// -------- HEADER --------

		// top border
		DrawLine(0, 0, ScreenWidth(), 0, 0x003D, FG_WHITE);

		// realm name
		DrawStringAlpha(2, 1, here.name, 0x000F);

		// player title
		wstring title = L"" + player.name + L" the Lv 1 " + player.role;
		DrawStringAlpha(ScreenWidth() - title.length() - 2, 1, title, 0x000F);
		// player position

		// collision detection
		if (player.x == here.there.x && player.y == here.there.y) {
			DrawStringAlpha(2, 2, L"You have arrived at " + here.there.name, 0x000F);
		}

		// bottom border
		DrawLine(0, 3, ScreenWidth(), 3, 0x003D, FG_WHITE);

// -------- GAME WORLD --------

		// draw realm
		// for (place place : player.here.here) {
		Draw((ScreenWidth() / 2) + here.there.x - player.x, (ScreenHeight() / 2) + here.there.y - player.y, here.there.name[0], FG_WHITE);
		// }

		// draw string
		DrawStringAlpha((ScreenWidth() / 2) + 15 - player.x, (ScreenHeight() / 2) + 22 - player.y, L"Hi how are you", 0x000F);

		// draw player
		Draw(ScreenWidth() / 2, ScreenHeight() / 2, player.name[0], FG_WHITE);

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