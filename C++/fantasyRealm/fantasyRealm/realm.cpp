#include "pch.h"
#include "monster.h"
#include "names.h"
#include "place.h"
#include "realm.h"
#include "time.h"
#include <string>
#include <vector>

using namespace std;

realm::realm() {
	srand(clock() + rand() % 10000);
	this->name = realm::getName();
	this->type = L"realm";
	for (int i = 0; i < 80; i++) {
		places.push_back(place());
	}
	for (int i = 0; i < 240; i++) {
		monsters.push_back(monster());
	}
}
realm::realm(int wits, int brave) {
	srand(clock() + rand() % 10000);
	this->name = realm::getName();
	this->type = L"realm";
	for (int i = 0; i < wits * 10 + brave; i++) {
		places.push_back(place());
	}
	for (int i = 0; i < wits * 10 + brave * 30; i++) {
		monsters.push_back(monster());
	}
}
realm::realm(place here, realm *parent, int width, int height) {
	if (type != L"realm") {
		this->name = name;
		this->type = type;
		this->parent = parent;
		this->x = x;
		this->y = y;
		int m = rand() % (width - 2) + 1;
		int n = rand() % (height - 2) + 1;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (i == m && j == n) {
					places.push_back(place(L"exit", m, n));
				}
				if (i == 0 || j == 0 || i == width - 1 || j == height - 1) {
					places.push_back(place(L"X", L"X", i, j, true));
				}
			}
		}
		for (int i = 0; i < 240; i++) {
			monsters.push_back(monster());
		}
	}
}
vector<monster> realm::moveMonsters(vector<monster> monsters) {
	int i = 0;
	// move monsters
	for (monster monster : monsters) {
		int randomize = rand() % 7000 + 1;
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
		monsters[i] = monster;
		i += 1;
	}
	return monsters;
}

wstring realm::getName() {
	return names::realmName();
}
