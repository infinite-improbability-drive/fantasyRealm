#include "pch.h"
#include "item.h"
#include <string>

using namespace std;

item::item() {
	this->name = L"Dirty Socks";
}
item::item(wstring name) {
	this->name = name;
}

// actions - enter, exit, look, menu, quit, 