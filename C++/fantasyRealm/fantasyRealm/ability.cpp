#include "pch.h"
#include <string>

using namespace std;

class ability {
public:
	wstring name;
	ability() {
		this->name = L"Hubris";
	}
	ability(wstring name) {
		this->name = name;
	}

};
