#include "pch.h"
#include "algorithm.h"
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
realm::realm(place here, realm *parent, int width, int height, player *player) {
	if (type != L"realm") {
		this->name = here.name;
		this->type = here.type;
		this->parent = parent;
		this->x = here.x;
		this->y = here.y;

		vector<vector<int>> tunnel =  tunnels.generateLevel(width, height);

		int i = 0;
		int j = 0;
		int k = 0;
		int l = 0;
		for (i = 0; i < width; i++) {
			for (j = 0; j < height; j++) {
				if (i == 0 || j == 0 || i == width - 1 || j == height - 1) {
					places.push_back(place(L"X", L"X", i, j, 0x0006, true));
				}
				else if (tunnel[i][j] == 1) {
					places.push_back(place(L"\u2591", L"X", i, j, 0x0006, true));
				}
				else if (tunnel[i][j] == 0) {
					k++;
				}
			}
		}

		int a = rand() % k;
		int b = rand() % k;
		int c = rand() % k;
		int d = rand() % k;
		int e = rand() % k;
		int f = rand() % k;
		int g = rand() % k;

		for (i = 0; i < width; i++) {
			for (j = 0; j < height; j++) {
				if (tunnel[i][j] == 0) {
					if (l == a) {			this->npcs.push_back(hero(i, j)); }
					else if (l == b) {		this->npcs.push_back(npc(i, j)); }
					else if (l == c) {		this->npcs.push_back(inn(i, j)); }
					else if (l == d) {		this->npcs.push_back(shop(i, j)); }
					else if (l == e) {		this->npcs.push_back(smith(i, j)); }
					else if (l == f) {		places.push_back(place(L"exit", i, j)); }
					else if (l == g) {		player->x = i; player->y = j; }
					if (rand() % 120 < 3) { monsters.push_back(monster(i, j)); }
					l++;
				}
			}
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
