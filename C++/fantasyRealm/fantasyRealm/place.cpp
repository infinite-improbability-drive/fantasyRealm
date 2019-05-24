#include "pch.h"
#include "name.cpp"
#include <string>

using namespace std;

static wstring getName();

class place {
public: 
	wstring name = getName();
	int x = rand() % 200 - 100;
	int y = rand() % 200 - 100;
};

static wstring getName() { 
	return L"Taos"; 
}
