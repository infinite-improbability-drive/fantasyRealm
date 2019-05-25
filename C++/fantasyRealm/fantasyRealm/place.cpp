#include "pch.h"
#include "name.cpp"
#include <string>

using namespace std;

static wstring getName();

class place {
public: 
	wstring name = getName();
	wstring type = L"place";
	int x = rand() % 200 - 100;
	int y = rand() % 200 - 100;
};

static wstring getName() { 
	name names = name();
	wstring here;

	int i = rand() % 1000;


	if (i == 1000) {}

	// named towns
	else if ((i < 1000) && (i >= 900)) {	here = names.towns[rand() % (sizeof(names.towns) / sizeof(names.towns[0]))]; }

	// special
	else if ((i < 900) && (i >= 800)) {
		here = names.special[rand() % (sizeof(names.special) / sizeof(names.special[0]))];
	}

	// caves	
	else if ((i < 800) && (i >= 700)) {
		if (i >= 775) {						here = names.cave[rand() % (sizeof(names.cave) / sizeof(names.cave[0]))]; }
		else if ((i < 775) && (i >= 760)) { here = names.caves[rand() % (sizeof(names.caves) / sizeof(names.caves[0]))] + L" Crypt"; }
		else if ((i < 760) && (i >= 745)) { here = names.caves[rand() % (sizeof(names.caves) / sizeof(names.caves[0]))] + L" Cavern"; }
		else {								here = names.caves[rand() % (sizeof(names.caves) / sizeof(names.caves[0]))] + L" Cave"; }
	}

	// peasant dwellings
	else if ((i < 700) && (i >= 600)) {
		if (i >= 675) {						here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L" Farm"; }		// estate?
		else if ((i < 675) && (i >= 650)) { here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L" Village"; }
		else if ((i < 650) && (i >= 625)) { here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L" Manor"; }
		else if ((i < 625) && (i >= 613)) { here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L" Homestead"; }
		else {								here = L"House " + names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))]; }
	}

	// farms
	else if ((i < 600) && (i >= 500)) {
		if (i >= 575) {						here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L"'s " + names.farms[rand() % (sizeof(names.farms) / sizeof(names.farms[0]))] + L" Farm"; }
		else if ((i < 575) && (i >= 550)) { here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L"'s " + names.farms[rand() % (sizeof(names.farms) / sizeof(names.farms[0]))] + L" Ranch"; }
		else if ((i < 550) && (i >= 525)) { here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L"'s Dairy Farm"; }
		else {								here = names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))] + L"'s Vineyard"; }
	}

	// mines
	else if ((i < 500) && (i >= 400)) {
		here = names.ores[rand() % (sizeof(names.ores) / sizeof(names.ores[0]))] + L" Mine";
		if (i >= 475) {}
		else if ((i < 475) && (i >= 450)) {}
		else if ((i < 450) && (i >= 425)) {}
		else {}
	}

	// crypts
	else if ((i < 400) && (i >= 300)) {
		if (i >= 383) {						here = names.elements[rand() % (sizeof(names.elements) / sizeof(names.elements[0]))] + L" Temple"; }
		else if ((i < 383) && (i >= 366)) { here = L"Temple of " + names.full[rand() % (sizeof(names.full) / sizeof(names.full[0]))]; }
		else if ((i < 366) && (i >= 349)) { here = names.elements[rand() % (sizeof(names.elements) / sizeof(names.elements[0]))] + L"'s Sanctuary"; }
		else if ((i < 349) && (i >= 332)) { here = names.elements[rand() % (sizeof(names.elements) / sizeof(names.elements[0]))] + L"'s Archives"; }
		else if ((i < 332) && (i >= 315)) { here = names.elements[rand() % (sizeof(names.elements) / sizeof(names.elements[0]))] + L"'s Resting Place"; }
		else {								here = names.elements[rand() % (sizeof(names.elements) / sizeof(names.elements[0]))] + L"'s Tomb"; }
	}

	// castles
	else if ((i < 300) && (i >= 200)) {
		here = L"Castle " + names.last[rand() % (sizeof(names.last) / sizeof(names.last[0]))];
		if (i >= 275) {}
		else if ((i < 275) && (i >= 250)) {}
		else if ((i < 250) && (i >= 225)) {}
		else {}
	}
	else if ((i < 200) && (i >= 100)) {
		here = L"Unknown location";
		if (i >= 175) {}
		else if ((i < 175) && (i >= 150)) {}
		else if ((i < 150) && (i >= 125)) {}
		else {}
	}
	else if ((i < 100) && (i > 0)) {
		here = L"Unknown location";
		if (i >= 75) {}
		else if ((i < 75) && (i >= 50)) {}
		else if ((i < 50) && (i >= 25)) {}
		else {}
	}





	else { here = L"Unknown location"; }

	return here;
}
