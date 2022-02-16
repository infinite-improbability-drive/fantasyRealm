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

	if (role == L"Barbarian") {
		this->actions.push_back(action());
	}
	else if (role == L"Bard") {
		this->actions.push_back(action());
	} 
	else if (role == L"Cleric") {
		this->actions.push_back(action());
	} 
	else if (role == L"Demon Hunter") {
		this->actions.push_back(action()); 
	} 
	else if (role == L"Druid") {
		this->actions.push_back(action()); 
	} 
	else if (role == L"Knight") {
		this->actions.push_back(action()); 
	} 
	else if (role == L"Paladin") { 
		this->actions.push_back(action());
	} 
	else if (role == L"Pugilist") {
		this->actions.push_back(action()); 
	} 
	else if (role == L"Pyromancer") { 
		this->actions.push_back(action()); 
	} 
	else if (role == L"Samurai") { 
		this->actions.push_back(action());
	} 
	else if (role == L"Sniper") { 
		this->actions.push_back(action());
	} 
	
	else if (role == L"Sorcerer") { 
		this->actions.push_back(action()); 
	} 
	else if (role == L"Thief") { 
		this->actions.push_back(action()); 
	} 
	else if (role == L"Princess") { 
		this->actions.push_back(action()); 
	} 
	else if (role == L"Fool") {
		this->actions.push_back(action());
	}
	
}
fight::fight() {
	this->name = L"Fight";
	this->action = action::action(L"Fight");
}
use::use() {
	this->name = L"Items";
}

rage::rage() {
	this->name = L"Rage";
	this->actions.push_back(action(L"Berserker"));
	this->actions.push_back(action(L"Faust"));
	this->actions.push_back(action(L"Skull Bash"));
}

song::song() {
	this->name = L"Song";
	this->actions.push_back(action(L"Bohemian Rhapsody"));
	this->actions.push_back(action(L"Smells Like Teen Spirit"));
	this->actions.push_back(action(L"Oops!.. I Did It Again"));
	this->actions.push_back(action(L"Harmony"));
	this->actions.push_back(action(L"Dissonance"));
}
holy::holy() {
	this->name = L"Holy";
	this->actions.push_back(action(L"Pray"));
	this->actions.push_back(action(L"Annoint"));
	this->actions.push_back(action(L"Consecrate"));
}
unholy::unholy() {
	this->name = L"Unholy";
	this->actions.push_back(action(L"Mind Wipe"));
	this->actions.push_back(action(L"Rend"));
	this->actions.push_back(action(L"Disembowel"));
}
shapeshift::shapeshift() {
	this->name = L"Shapeshift";
	this->actions.push_back(action(L"Shift"));
	this->actions.push_back(action(L"Meditate"));
	this->actions.push_back(action(L"Moonwell"));
}
swordtech::swordtech() {
	this->name = L"SwordTech";
	this->actions.push_back(action(L"Strike"));
	this->actions.push_back(action(L"Slash"));
	this->actions.push_back(action(L"Parry"));
	this->actions.push_back(action(L"Riposte"));
	this->actions.push_back(action(L"Shield Bash"));
	this->actions.push_back(action(L"Protect"));
	this->actions.push_back(action(L"Punch"));
}
holyarts::holyarts() {
	this->name = L"Holy Arts";
	this->actions.push_back(action(L"Pray"));
	this->actions.push_back(action(L"Holy Strike"));
	this->actions.push_back(action(L"Holy Slash"));
	this->actions.push_back(action(L"Holy Light"));
	this->actions.push_back(action(L"Protection"));
}
evade::evade() {
	this->name = L"Evade";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}
flame::flame() {
	this->name = L"Flame";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}
frost::frost() {
	this->name = L"Frost";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}
bushido::bushido() {
	this->name = L"Bushido";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}
shinobi::shinobi() {
	this->name = L"Shinobi";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}
assassin::assassin() {
	this->name = L"Assassin";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}
sorcery::sorcery() {
	this->name = L"Sorcery";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}

royal::royal() {
	this->name = L"Royal";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}

slapstick::slapstick() {
	this->name = L"Slapstick";
	this->actions.push_back(action(L"Juggling"));
	this->actions.push_back(action(L"Standup Comedy"));
	this->actions.push_back(action(L"Mime"));
}


// {L"Rage", L"Song", L"Holy", L"Unholy", L"Shapeshift", L"SwordTech", L"Holy Arts", L"Evade", L"Flame", L"Bushido", L"Assassin", L"Sorcery", L"Steal", L"Royal", L"Slapstick" };