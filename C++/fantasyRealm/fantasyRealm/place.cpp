#include "pch.h"
#include "names.h"
#include "place.h"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

place::place() {
	// srand(clock() + rand() % 10000);
	int i = rand() % 1000;
	this->name = getName(i);
	this->type = getType(i);
	this->solid = false;
	this->x = rand() % 200 - 100;
	this->y = rand() % 200 - 100;
}
place::place(wstring type, int x, int y) {
	srand(clock() + rand() % 10000);
	int i = rand() % 1000;
	this->name = L"Exit";
	this->type = type;
	this->solid = false;
	this->x = x;
	this->y = y;
}
place::place(wstring name, wstring type, int x, int y, bool solid) {
	this->name = name;
	this->type = type;
	this->solid = solid;
	this->x = x;
	this->y = y;
}

wstring place::getName(int i) {
	if (i == 1000) { return L"Birthday Island"; }
	// named towns
	else if ((i < 1000) && (i >= 900)) { return names::townName(); }
	// special
	else if ((i < 900) && (i >= 800)) {
		return names::special();
	}
	// caves	
	else if ((i < 800) && (i >= 700)) {
		if (i >= 775) {						return names::cave(); }
		else if ((i < 775) && (i >= 760)) { return names::caveType() + L" Crypt"; }
		else if ((i < 760) && (i >= 745)) { return names::caveType() + L" Cavern"; }
		else {								return names::caveType() + L" Cave"; }
	}
	// peasant dwellings
	else if ((i < 700) && (i >= 600)) {
		if (i >= 675) {						return names::lastName() + L" Farm"; }		// estate?
		else if ((i < 675) && (i >= 650)) { return names::lastName() + L" Village"; }
		else if ((i < 650) && (i >= 625)) { return names::lastName() + L" Manor"; }
		else if ((i < 625) && (i >= 613)) { return names::lastName() + L" Homestead"; }
		else {								return L"House " + names::lastName(); }
	}
	// farms
	else if ((i < 600) && (i >= 500)) {
		if (i >= 575) {						return names::lastName() + L"'s " + names::farm() + L" Farm"; }
		else if ((i < 575) && (i >= 550)) { return names::lastName() + L"'s " + names::farm() + L" Ranch"; }
		else if ((i < 550) && (i >= 525)) { return names::lastName() + L"'s Dairy Farm"; }
		else {								return names::lastName() + L"'s Vineyard"; }
	}
	// mines
	else if ((i < 500) && (i >= 400)) {
		return names::ore() + L" Mine";
		if (i >= 475) {}
		else if ((i < 475) && (i >= 450)) {}
		else if ((i < 450) && (i >= 425)) {}
		else {}
	}
	// crypts
	else if ((i < 400) && (i >= 300)) {
		if (i >= 383) {						return names::element() + L" Temple"; }
		else if ((i < 383) && (i >= 366)) { return L"Temple of " + names::fullName(); }
		else if ((i < 366) && (i >= 349)) { return names::fullName() + L"'s Sanctuary"; }
		else if ((i < 349) && (i >= 332)) { return names::fullName() + L"'s Archives"; }
		else if ((i < 332) && (i >= 315)) { return names::fullName() + L"'s Resting Place"; }
		else {								return names::fullName() + L"'s Tomb"; }
	}
	// castles
	else if ((i < 300) && (i >= 200)) {
		return L"Castle " + names::lastName();
		if (i >= 275) {}
		else if ((i < 275) && (i >= 250)) {}
		else if ((i < 250) && (i >= 225)) {}
		else {}
	}
	// research facilities
	else if ((i < 200) && (i >= 100)) {
		if (i >= 175) {						return names::base() + L" Laboratory"; }
		else if ((i < 175) && (i >= 150)) {	return names::base() + L" Research Facility"; }
		else if ((i < 150) && (i >= 125)) {	return names::base() + L" Antarctic Base"; }
		else {								return names::base() + L" Antarctic Research Center";	}
	}
	else if ((i < 100) && (i > 0)) {
		return L"Unknown location";
		if (i >= 75) {}
		else if ((i < 75) && (i >= 50)) {}
		else if ((i < 50) && (i >= 25)) {}
		else {}
	}
	else { return L"Unknown location"; }
}

wstring place::getType(int i) {
	if (i == 1000) {					 return L"!!!Jackpot!!!"; }
	else if ((i < 1000) && (i >= 900)) { return L"town"; }
	else if ((i < 900) && (i >= 800)) {	 return L"special"; }
	else if ((i < 800) && (i >= 700)) {	 return L"cave"; }
	else if ((i < 700) && (i >= 600)) {	 return L"town"; }
	else if ((i < 600) && (i >= 500)) {	 return L"farm"; }
	else if ((i < 500) && (i >= 400)) {	 return L"mine"; }
	else if ((i < 400) && (i >= 300)) {	 return L"crypt"; }
	else if ((i < 300) && (i >= 200)) {	 return L"castle"; }
	else if ((i < 200) && (i >= 100)) {	 return L"laboratory"; }
	else if ((i < 100) && (i > 0)) {	 return L"unknown"; }
	else {								 return L"unknown"; }
}

