#include "pch.h"
#include "ability.h"
#include "action.h"
#include <string>

using namespace std;


ability::ability() {
	this->name = L"Hubris";
}
ability::ability(wstring name) {
	this->name = name;
	this->actions.push_back(action());
}
fight::fight() {
	this->name = L"Fight";
	this->action = action::action(L"Fight");
}
use::use() {
	this->name = L"Items";
}
