#include "pch.h"
#include "place.cpp"
#include <string>
#include <vector>

using namespace std;
// wstring getName();

class realm {
public:
	wstring name;
	wstring type;
	vector<place> places;
	realm* parent;
	int x;
	int y;
	realm() {
		this->name = L"Midgard";
		this->type = L"realm";
		for (int i = 0; i < 80; i++) {
			places.push_back(place());
		}
	}
	realm(int wits, int brave) {
		this->name = L"Midgard";
		this->type = L"realm";
		for (int i = 0; i < wits * 10 + brave; i++) {
			places.push_back(place());
		}
	}
	realm(wstring name, wstring type, realm *parent, int x, int y) {
		if (type != L"realm") {
			this->name = name;
			this->type = type;
			this->parent = parent;
			this->x = x;
			this->y = y;
			places.push_back(place(L"exit"));
			for (int i = 0; i < 60; i++) {
				for (int j = 0; j < 30; j++) {
					if (i == 0 || j == 0 || i == 59 || j == 29) {
						places.push_back(place(L"X", L"X", i, j, true));
					}
				}
			}
		}
	}
};

// wstring getName() { return L"Sanctuary Circle"; }
