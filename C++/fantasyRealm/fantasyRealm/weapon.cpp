#include "pch.h"
#include "item.h"
#include "names.h"
#include "weapon.h"
#include <string>

using namespace std;

weapon::weapon() {
	this->name = L"Dead Fish";
}
weapon::weapon(wstring role) {
	names name;
	this->name = name.weaponName(role);
}
