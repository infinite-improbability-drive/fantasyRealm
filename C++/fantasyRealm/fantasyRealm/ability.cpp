#include "pch.h"
#include "ability.h"
#include <string>

using namespace std;


ability::ability() {
	this->name = L"Hubris";
}
ability::ability(wstring name) {
	this->name = name;
}