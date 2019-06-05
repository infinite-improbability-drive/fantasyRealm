#pragma once
#ifndef __NAMES_H__
#define __NAMES_H__

#include <string>

using namespace std;

class names {
public:

	// roles
	static wstring roles[15];
	static wstring role();
	static wstring weapons[15];
	static wstring weaponName(wstring role);
	static wstring magics[12];
	static wstring magic();

	// names
	static wstring first[5];
	static wstring firstName();
	static wstring last[479];
	static wstring lastName();
	static wstring full[528];
	static wstring fullName();
	static wstring fullName(wstring role);

	static wstring barbarian[6];
	static wstring bard[6];
	static wstring cleric[5];
	static wstring demon_hunter[5];
	static wstring druid[4];
	static wstring knight[12];
	static wstring paladin[3];
	static wstring pugilist[3];
	static wstring pyromancer[5];
	static wstring samurai[4];
	static wstring sniper[2];
	static wstring sorcerer[4];
	static wstring thief[6];
	static wstring princess[12];
	static wstring fool[4];

	// places
	static wstring towns[2363];
	static wstring townName();
	static wstring caves[10];
	static wstring cave();
	static wstring caveTypes[17];
	static wstring caveType();
	static wstring ores[15];
	static wstring ore();
	static wstring elements[6];
	static wstring element();
	static wstring farms[8];
	static wstring farm();

	// special
	static wstring specials[10];
	static wstring special();
	static wstring antarctic_bases[176];
	static wstring base();

	// monsters

};

#endif