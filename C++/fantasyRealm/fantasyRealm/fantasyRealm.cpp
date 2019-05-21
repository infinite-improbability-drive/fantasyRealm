/*
OneLoneCoder.com - Command Line Snake
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
Classic Snake! Controls are Arrow keys Left & Right, eat food, grow larger, avoid self!
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
using namespace std;

#include <Windows.h>

int nScreenWidth = 120;
int nScreenHeight = 30;

struct sSnakeSegment
{
	int x;
	int y;
};

int main()
{
	// Create Screen Buffer
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	bool bKeyUp = false, bKeyDown = false, bKeyUpOld = false, bKeyDownOld = false;
	bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;

	string name;
	wsprintf(&screen[nScreenWidth + 5], L"Welcome to the fantasy realm.");

	while (1)
	{

		wsprintf(&screen[nScreenWidth + 5], L"Welcome to the fantasy realm.");

		// Reset to known state
		list<sSnakeSegment> snake = { {60,15} };
		int nFoodX = 30;
		int nFoodY = 15;
		int nScore = 0;
		int nSnakeDirection = 3;
		bool bDead = false;
		// bool bKeyUp = false, bKeyDown = false, bKeyUpOld = false, bKeyDownOld = false;
		// bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;

		while (!bDead)
		{
			// Frame Timing, compensate for aspect ratio of command line
			auto t1 = chrono::system_clock::now();
			while ((chrono::system_clock::now() - t1) < ((nSnakeDirection % 2 == 1) ? 120ms : 200ms))
			{
				// Get Input, 
				bKeyLeft = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;
				bKeyRight = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;
				bKeyUp = (0x8000 & GetAsyncKeyState((unsigned char)('\x28'))) != 0;
				bKeyDown = (0x8000 & GetAsyncKeyState((unsigned char)('\x26'))) != 0;

				if (bKeyUp && !bKeyUpOld)
				{
					// nSnakeDirection = 1;
					snake.push_front({ snake.front().x, snake.front().y + 1 });
					// nSnakeDirection++;
					// if (nSnakeDirection == 4) nSnakeDirection = 0;
				}

				if (bKeyDown && !bKeyDownOld)
				{
					// nSnakeDirection = 2;
					snake.push_front({ snake.front().x, snake.front().y - 1 });
					// nSnakeDirection--;
					// if (nSnakeDirection == -1) nSnakeDirection = 3;
				}
				if (bKeyRight && !bKeyRightOld)
				{
					// nSnakeDirection = 1;
					snake.push_front({ snake.front().x + 1, snake.front().y });
					// nSnakeDirection++;
					// if (nSnakeDirection == 4) nSnakeDirection = 0;
				}

				if (bKeyLeft && !bKeyLeftOld)
				{
					// nSnakeDirection = 3;
					snake.push_front({ snake.front().x - 1, snake.front().y });
					// nSnakeDirection--;
					// if (nSnakeDirection == -1) nSnakeDirection = 3;
				}

				bKeyUpOld = bKeyUp;
				bKeyDownOld = bKeyDown;
				bKeyLeftOld = bKeyLeft;
				bKeyRightOld = bKeyRight;
			}

			// ==== Logic

			// Update Snake Position, place a new head at the front of the list in
			// the right direction
			/*
			switch (nSnakeDirection)
			{
			case 0: // UP
				snake.push_front({ snake.front().x, snake.front().y - 1 });
				break;
			case 1: // RIGHT
				snake.push_front({ snake.front().x + 1, snake.front().y });
				break;
			case 2: // DOWN
				snake.push_front({ snake.front().x, snake.front().y + 1 });
				break;
			case 3: // LEFT
				snake.push_front({ snake.front().x - 1, snake.front().y });
				break;
			}
			*/

			// Collision Detect Snake V Food
			if (snake.front().x == nFoodX && snake.front().y == nFoodY)
			{
				nScore++;
				while (screen[nFoodY * nScreenWidth + nFoodX] != L' ')
				{
					nFoodX = rand() % nScreenWidth;
					nFoodY = (rand() % (nScreenHeight - 3)) + 3;
				}

				for (int i = 0; i < 5; i++)
					snake.push_back({ snake.back().x, snake.back().y });
			}

			// Collision Detect Snake V World
			if (snake.front().x < 0 || snake.front().x >= nScreenWidth)
				bDead = true;
			if (snake.front().y < 3 || snake.front().y >= nScreenHeight)
				bDead = true;

			// Collision Detect Snake V Snake
			// for (list<sSnakeSegment>::iterator i = snake.begin(); i != snake.end(); i++)
			// 	if (i != snake.begin() && i->x == snake.front().x && i->y == snake.front().y)
			// 		bDead = true;

			// Chop off Snakes tail :-/
			// snake.pop_back();

			// ==== Presentation

			// Clear Screen
			for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';

			// Draw Stats & Border
			for (int i = 0; i < nScreenWidth; i++)
			{
				screen[i] = L'=';
				screen[2 * nScreenWidth + i] = L'=';
			}
			wsprintf(&screen[nScreenWidth + 5], L"Welcome to the fantasy realm.");


			// Draw Snake Body
			for (auto s : snake)
				screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L' ';

			// Draw Snake Head
			screen[snake.front().y * nScreenWidth + snake.front().x] = bDead ? L'X' : L'@';

			// Draw Food
			screen[nFoodY * nScreenWidth + nFoodX] = L'%';

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

