#pragma once
#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

using namespace std;

class item {
public:
	wstring name;
	wstring description;
	bool selected;
	item();
	item(wstring name);
};

#endif