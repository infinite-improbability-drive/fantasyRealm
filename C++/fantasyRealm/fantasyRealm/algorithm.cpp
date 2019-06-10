#include "pch.h"
#include "algorithm.h"
#include <string>

using namespace std;

TunnelingAlgorithm::TunnelingAlgorithm() {
	// this->level = [];
	this->ROOM_MAX_SIZE = 15;
	this->ROOM_MIN_SIZE = 6;
	this->MAX_ROOMS = 30;
}

/*
void createRoom(rectangle room) {
	for (int x = room.left + 1; x < room.right; x++) {
		for (int y = room.top + 1; y < room.bottom; y++) {

		}
	}
}
*/

rectangle::rectangle(int x, int y, int width, int height) {
	this->left = x;
	this->top = y;
	this->right = x + width;
	this->bottom = y + height;
}
pair<int, int> rectangle::center(rectangle r) {
	return { (r.left + r.right) / 2, (r.top + r.bottom) / 2 };
}
bool rectangle::intersect(rectangle first, rectangle second) {
	return (first.left <= second.right && first.right >= second.left &&	first.top <= second.bottom && first.bottom >= second.top);
}