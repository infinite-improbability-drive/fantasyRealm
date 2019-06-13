#include "pch.h"
#include "item.h"
#include <string>

using namespace std;

item::item() {
	this->name = L"Dirty Socks";
	this->selected = false;
}
item::item(wstring name) {
	this->name = name;
	this->selected = false;
}

// actions - enter, exit, look, menu, quit, 