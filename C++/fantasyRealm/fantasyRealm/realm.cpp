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
	realm() {
		this->name = L"Midgard";
		this->type = L"realm";
		for (int i = 0; i < 80; i++) {
			places.push_back(place());
		}
	}
	realm(wstring name, wstring type) {
		if (type != L"realm") {
			this->name = name;
			this->type = type;
		}

	}
};

// wstring getName() { return L"Sanctuary Circle"; }
