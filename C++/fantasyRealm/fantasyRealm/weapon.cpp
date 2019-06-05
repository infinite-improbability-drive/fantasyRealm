#include "pch.h"
#include "item.h"
#include <string>

using namespace std;

class weapon : item {
public:
	wstring name;
	weapon() {
		this->name = L"Dead Fish";
	}
	weapon(wstring name) {
		this->name = name;
	}

};

// actions - enter, exit, look, menu, quit, 