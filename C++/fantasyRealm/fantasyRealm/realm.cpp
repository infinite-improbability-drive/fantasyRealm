#include "pch.h"
#include "place.cpp"
// #include "player.cpp"
#include "monster.cpp"
#include <string>
#include <vector>

using namespace std;
// wstring getName();

class realm {
public:
	wstring name;
	wstring type;
	vector<place> places;
	vector<monster> monsters;
	realm* parent;
	int x;
	int y;
	realm() {
		this->name = L"Midgard";
		this->type = L"realm";
		for (int i = 0; i < 80; i++) {
			places.push_back(place());
		}
		for (int i = 0; i < 240; i++) {
			monsters.push_back(monster());
		}
	}
	realm(int wits, int brave) {
		this->name = L"Midgard";
		this->type = L"realm";
		for (int i = 0; i < wits * 10 + brave; i++) {
			places.push_back(place());
		}
		for (int i = 0; i < wits * 10 + brave * 30; i++) {
			monsters.push_back(monster());
		}
	}
	realm(place here, realm *parent, int width, int height) {
		if (type != L"realm") {
			this->name = here.name;
			this->type = here.type;
			this->parent = parent;
			this->x = here.x;
			this->y = here.y;
			int m = rand() % width;
			int n = rand() % height;

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
};

// wstring getName() { return L"Sanctuary Circle"; }
