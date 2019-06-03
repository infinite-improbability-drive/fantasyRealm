#include "pch.h"
#include <string>

using namespace std;

class item {
public:
	wstring name;
	item() {
		this->name = L"Dirty Socks";
	}
	item(wstring name) {
		this->name = name;
	}

};

// actions - enter, exit, look, menu, quit, 