#include "pch.h"
#include "time.h"
#include <iostream>
#include <string>

using namespace std;

static wstring getName(int i);
static wstring getType(int i);

class monster {
public:
	wstring name;
	wstring type;
	wstring icon;
	int x;
	int y;
	monster() {
		this->name = L"slime";
		this->type = L"slime";
		this->icon = L"s";
		this->x = rand() % 200 - 100;
		this->y = rand() % 200 - 100;
	}
};
