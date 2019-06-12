#include "pch.h"
#include "ability.h"
#include "action.h"
#include "names.h"
#include <string>

using namespace std;


ability::ability() {
	this->name = L"Hubris";
}
ability::ability(wstring role) {
	this->name = names::ability(role);
	this->actions.push_back(action());
}
fight::fight() {
	this->name = L"Fight";
	this->action = action::action(L"Fight");
}
use::use() {
	this->name = L"Items";
}
slapstick::slapstick() {
	this->name = L"Slapstick";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}