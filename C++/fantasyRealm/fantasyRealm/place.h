#pragma once
#ifndef __PLACE_H__
#define __PLACE_H__

#include <string>

using namespace std;

class place {
public:
	wstring name;
	wstring type;
	bool solid;
	int x;
	int y;
	place();
	place(wstring type, int x, int y);
	place(wstring name, wstring type, int x, int y, bool solid);
	static wstring getName(int i);
	static wstring getType(int i);
};

#endif