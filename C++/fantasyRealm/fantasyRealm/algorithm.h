#pragma once
#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include "place.h"
#include "player.h"
#include "monster.h"
// #include <map>
#include <string>
#include <vector>

using namespace std;

// https://github.com/AtTheMatinee/dungeon-generation/blob/master/dungeonGenerationAlgorithms.py

class TunnelingAlgorithm {
public:
	class rectangle {
	public:
		int left, top, bottom, right;
		rectangle(int x, int y, int width, int height);
		pair<int, int> center(rectangle r);
		bool intersect(rectangle first, rectangle second);
	};
	vector<vector<int>> level;
	int ROOM_MAX_SIZE = 15;
	int ROOM_MIN_SIZE = 6;
	int MAX_ROOMS = 30;
	TunnelingAlgorithm();

	vector<vector<int>> generateLevel(int width, int height);
	void createRoom(rectangle room);	
	void createTunnelX(int left, int right, int y);	
	void createTunnelY(int top, int bottom, int x);
	// void createTunnelX();
	// void createTunnelY();
};

#endif