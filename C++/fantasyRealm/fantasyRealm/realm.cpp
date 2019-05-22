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

#include <Windows.h>


char ch;
int nScreenWidth = 120;
int nScreenHeight = 30;
wstring name;
wstring role;
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

struct player {
	int x;
	int y;
};

wstring start();
wstring input();

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	// wprintf(L"\x263a\x263b");

	name = start();

	// Create Screen Buffer
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	
	while (1)
	{

		// wsprintf(&screen[nScreenWidth + 5], L"Welcome to the fantasy realm.");

		// Reset to known state
		player player = { 60,15 };
		int nFoodX = 30;
		int nFoodY = 15;
		int nScore = 0;
		int nplayerDirection = 3;
		bool bDead = false;
		bool bKeyUp = false, bKeyDown = false, bKeyUpOld = false, bKeyDownOld = false;
		bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;

		while (!bDead)
		{
			// Frame Timing, compensate for aspect ratio of command line
			auto t1 = chrono::system_clock::now();
			while ((chrono::system_clock::now() - t1) < ((nplayerDirection % 2 == 1) ? 120ms : 200ms))
			{
				// Get Input, 
				bKeyLeft = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;
				bKeyRight = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
				bKeyUp = (0x8000 & GetAsyncKeyState((unsigned char)('\x28'))) != 0;
				bKeyDown = (0x8000 & GetAsyncKeyState((unsigned char)('\x26'))) != 0;

				if (bKeyUp && !bKeyUpOld)		{ player.y = player.y + 1;}
				if (bKeyDown && !bKeyDownOld)	{ player.y = player.y - 1;}
				if (bKeyRight && !bKeyRightOld) { player.x = player.x + 1;}
				if (bKeyLeft && !bKeyLeftOld)	{ player.x = player.x - 1;}

				bKeyUpOld = bKeyUp;
				bKeyDownOld = bKeyDown;
				bKeyLeftOld = bKeyLeft;
				bKeyRightOld = bKeyRight;
			}

			// ==== Logic

			// Collision Detect player V Food
			if (player.x == nFoodX && player.y == nFoodY)
			{
				nScore++;
				while (screen[nFoodY * nScreenWidth + nFoodX] != L' ')
				{
					nFoodX = rand() % nScreenWidth;
					nFoodY = (rand() % (nScreenHeight - 3)) + 3;
				}

				// for (int i = 0; i < 5; i++)
				// 	player.push_back({ player.back().x, player.back().y });
			}

			// Collision Detect player V World
			if (player.x < 0 || player.x >= nScreenWidth)
				bDead = true;
			if (player.y < 3 || player.y >= nScreenHeight)
				bDead = true;

			// ==== Presentation

			// Clear Screen
			for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';

			// Draw Stats & Border
			for (int i = 0; i < nScreenWidth; i++)
			{
				screen[i] = L'=';
				screen[2 * nScreenWidth + i] = L'=';
			}
			wsprintf(&screen[nScreenWidth + 5], L"%ls the Lv %d %ls", name.c_str(), 1, role.c_str());

			// Draw player
			screen[player.y * nScreenWidth + player.x] = bDead ? L'X' : name[0];

			// Draw food
			screen[nFoodY * nScreenWidth + nFoodX] = L'\x2116';

			if (bDead)
				wsprintf(&screen[15 * nScreenWidth + 40], L"    PRESS 'SPACE' TO PLAY AGAIN    ");

			// Display Frame
			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
		}

		// Wait for space
		while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
	}

	return 0;
}

wstring start() {
	wprintf(L"Welcome to the fantasy realm.\n");

	wprintf(L"Please enter your name:\n");
	name = input();
	wprintf(L"Please choose your class-\n");
	wstring roles[] = { L"Bard", L"Knight", L"Sorcerer"};

	for (wstring role : roles) {
		if (role != roles[roles->length() - 2]) {
			wcout << role << ", ";
		}
		else {
			wcout << role << ". ";
		}
	}
	wprintf(L"\n");
	role = input();

	wcout << "Hello " << name << " the " << role << ".\n";
	wprintf(L"Press enter to begin:\n");
	// string enter;
	while ((0x8000 & GetAsyncKeyState((unsigned char)('\x12'))) != 0); {
		input();
	}

	return name;
}

wstring input() {
	string out;
	getline(cin, out);
	// wstring wname = converter.from_bytes(out);
	// std::string narrow = converter.to_bytes(wide_utf16_source_string);
	return converter.from_bytes(out);
}

