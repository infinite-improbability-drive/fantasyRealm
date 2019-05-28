#include "pch.h"
#include "place.cpp"
#include <string>

using namespace std;
// wstring getName();

class realm {
public:
	wstring name;
	place places[80];
	realm() {
		this->name = L"Midgard";
	}
};

// wstring getName() { return L"Sanctuary Circle"; }
