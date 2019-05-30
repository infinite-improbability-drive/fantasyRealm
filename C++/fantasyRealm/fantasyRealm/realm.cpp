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
	realm(wstring name, wstring type, realm *parent, int x, int y) {
		if (type != L"realm") {
			this->name = name;
			this->type = type;
			this->parent = parent;
			places.push_back(place(L"exit"));
			this->x = x;
			this->y = y;
		}
	}
};

// wstring getName() { return L"Sanctuary Circle"; }
