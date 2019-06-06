#include "pch.h"
#include "action.h"
#include <string>

using namespace std;

action::action() {
	this->name = L"Weakling Punch";
	this->physical_damage = 1;
	this->magic_damage = 1;
}