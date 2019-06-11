#include "pch.h"
#include "algorithm.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

TunnelingAlgorithm::TunnelingAlgorithm() {
	//this->level = [];
	this->ROOM_MAX_SIZE = 15;
	this->ROOM_MIN_SIZE = 6;
	this->MAX_ROOMS = 30;
}

vector<vector<int>> TunnelingAlgorithm::generateLevel(int width, int height) {

	// creates an empty 2D vector
	for (int x = 0; x < width; x++) {
		vector<int> column;
		for (int y = 0; y < height; y++) {
			column.push_back(1);
		}
		this->level.push_back(column);
	}

	vector<rectangle> rooms;
	int num_rooms = 0;

	for (int r = 0; r < MAX_ROOMS; r++) {

		// create new room with random width and height
		int w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
		int h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE) + ROOM_MIN_SIZE;
		// random position within map boundries
		int x = rand() % (width - w - 1);
		int y = rand() % (height - h - 1);

		rectangle room = rectangle(x, y, w, h);

		// check for overlap with previous rooms
		bool failed = false;
		for (rectangle other : rooms) {
			if (room.intersect(room, other)) {
				failed = true;
				break;
			}
		}

		if (!failed) {
			createRoom(room);
			pair<int, int> next = room.center(room);
			if (num_rooms != 0) {
				// all rooms after the first connect to the previous
				// center coordinates on previous room
				pair<int, int> previous = rooms[num_rooms - 1].center(rooms[num_rooms - 1]);

				// horizontal tunnel 
				if (rand() % 1 == 1) {
					createTunnelX(previous.first, next.first, previous.second);
					createTunnelY(previous.second, next.second, next.first);
				}
				else {
					createTunnelY(previous.second, next.second, next.first);
					createTunnelX(previous.first, next.first, previous.second);
				}
			}
			rooms.push_back(room);
			num_rooms += 1;
		}
	}
	return this->level;
}

void TunnelingAlgorithm::createRoom(rectangle room) {
	for (int x = room.left + 1; x < room.right; x++) {
		for (int y = room.top + 1; y < room.bottom; y++) {
			this->level[x][y] = 0;
		}
	}
}
void TunnelingAlgorithm::createTunnelX(int left, int right, int y) {
	for (int x = min(left, right); x < max(left, right) + 1; x++) {
		this->level[x][y] = 0;
	}
}void TunnelingAlgorithm::createTunnelY(int top, int bottom, int x) {
	for (int y = min(top, bottom); y < max(top, bottom) + 1; y++) {
		this->level[x][y] = 0;
	}
}


TunnelingAlgorithm::rectangle::rectangle(int x, int y, int width, int height) {
	this->left = x;
	this->top = y;
	this->right = x + width;
	this->bottom = y + height;
}
pair<int, int> TunnelingAlgorithm::rectangle::center(rectangle r) {
	return { (r.left + r.right) / 2, (r.top + r.bottom) / 2 };
}
bool TunnelingAlgorithm::rectangle::intersect(rectangle first, rectangle second) {
	return (first.left <= second.right && first.right >= second.left &&	first.top <= second.bottom && first.bottom >= second.top);
}