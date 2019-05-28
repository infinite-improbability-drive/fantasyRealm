#include "pch.h"
#include "place.cpp"
#include <string>

using namespace std;
// wstring getName();

class realm {
public:
	wstring name;
	wstring type;
	place places[80];
	realm() {
		this->name = L"Midgard";
		this->type = L"realm";
	}
	realm(wstring name, wstring type) {
		if (type != L"realm") {
			this->name = name;
			this->type = type;
		}

	}
};

// wstring getName() { return L"Sanctuary Circle"; }
