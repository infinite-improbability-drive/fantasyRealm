#include "pch.h"
#include "monster.h"
#include "place.h"
// #include "player.cpp"
#include "realm.h"
#include <string>
#include <vector>

using namespace std;

realm::realm() {
	this->name = L"Midgard";
	this->type = L"realm";
	for (int i = 0; i < 80; i++) {
		places.push_back(place());
	}
	for (int i = 0; i < 240; i++) {
		monsters.push_back(monster());
	}
}
realm::realm(int wits, int brave) {
	this->name = L"Midgard";
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
		this->name = here.name;
		this->type = here.type;
		this->parent = parent;
		this->x = here.x;
		this->y = here.y;
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

// wstring realm::getName() { return L"Sanctuary Circle"; }
