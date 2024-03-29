#include "pch.h"
#include "time.h"
#include "monster.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<wstring, int> monster::trash = { {L"Crow", 0x0008}, {L"Rat", 0x0008}, {L"Worm", 0x0008} };
map<wstring, int> monster::tiny = { {L"Brownie", 0x0008}, {L"Cockatrice", 0x0008}, {L"Enchanted Clothing", 0x000F}, {L"Faery", 0x000D}, {L"Fairy", 0x000E}, {L"Gnome", 0x000E}, {L"Goblin", 0x0002}, {L"Hobbit", 0x0006}, {L"Imp", 0x0005}, {L"Kodama", 0x000F}, {L"Pirhana", 0x000F}, {L"Pixie", 0x000F}, {L"Rat", 0x000F}, {L"Slime", 0x000F}, {L"Sprite", 0x000F}, {L"Welp", 0x000F}, {L"Will-o'-the-wisp", 0x000F}, {L"Will-o'-wisp", 0x000F}, {L"Wisp", 0x000F} };
map<wstring, int> monster::normal = { {L"Bandit", 0x0006}, {L"Basilisk", 0x0002}, {L"Centaur", 0x000F}, {L"Demon", 0x000C}, {L"Djinn", 0x000F}, {L"Dryad", 0x000A}, {L"Elemental", 0x000F}, {L"Enchanted Furniture", 0x000F}, {L"Faun", 0x000F}, {L"Ghoul", 0x000F}, {L"Giant Rat", 0x000F}, {L"Green Man", 0x000F}, {L"Harpy", 0x000F}, {L"Lamia", 0x0001}, {L"Large Slime", 0x0002}, {L"Mermaid", 0x000B}, {L"Naga", 0x000B}, {L"Nymph", 0x000B}, {L"Orc", 0x000A}, {L"Satyr", 0x0006}, {L"Siren", 0x000E}, {L"Tengu", 0x0005},  {L"Wendigo", 0x0008}, {L"Werewolf", 0x0008}, {L"Wolf", 0x0008}, {L"Yokai", 0x000B} };
map<wstring, int> monster::ghosts = { {L"Animal Spirit", 0x0008}, {L"Banshee", 0x0008}, {L"Geist", 0x0008},  {L"Ghost", 0x0008}, {L"Poltergeist", 0x0008}, {L"Preta", 0x0008}, {L"Wraith", 0x0008} };
map<wstring, int> monster::undead = { {L"Ghoul", 0x0008}, {L"Mummy", 0x0008}, {L"Vampire", 0x000F}, {L"Zombie", 0x000A} };
map<wstring, int> monster::large = { {L"Alpha Wolf", 0x000F}, {L"Alpha Werewolf", 0x0008},{L"Behemoth", 0x000F}, {L"Chimera", 0x000F}, {L"Cyclops", 0x000F}, {L"Demon King", 0x000F}, {L"Dire Wolf", 0x000F}, {L"Giantic Rat", 0x000F}, {L"Goblin King", 0x000F}, {L"Golem", 0x000F}, {L"Griffin", 0x000F}, {L"Hydra", 0x000F}, {L"Land Shark", 0x000F}, {L"Manticore", 0x000F}, {L"Minotaur", 0x000F}, {L"Ogre", 0x000F}, {L"Orc Captain", 0x000F}, {L"Scorpion Man", 0x000F}, {L"Were-bear", 0x000F} };
map<wstring, int> monster::veryLarge = { {L"Dragon", 0x000F}, {L"Giant", 0x0008}, {L"Man-Eating Tree", 0x000A}, {L"John Henry", 0x0008} };
map<wstring, int> monster::rare = { {L"Doppelg\u00E4nger", 0x0001},  {L"Shapeshifter", 0x0001},  {L"Golden Worm", 0x0006}, {L"Pink Slime", 0x000F} , {L"Master Tonberry", 0x000F} };
map<wstring, int> monster::veryRare = { {L"Jackelope", 0x000F}, {L"Leprechaun", 0x000F}, {L"Moon Rabbit", 0x000F}, {L"Pepsi Man", 0x000F}, {L"Unicorn", 0x000F}, };
map<wstring, int> monster::veryLargeAndRare = { {L"Bigfoot", 0x000F}, {L"Nightwalker", 0x000F}, {L"Phoenix", 0x000F},{L"Thunderbird", 0x000F}, };
map<wstring, int> monster::giant = { {L"Gamera", 0x0008}, {L"Godzilla", 0x0008}, };
map<wstring, int> monster::boss = { {L"Cybertrike X-9000D", 0x0008} };
map<wstring, int> monster::animals = { {L"Aardvark", 0x0001}, {L"Albatross", 0x0001}, {L"Alligator", 0x0020}, {L"Alpaca", 0x0001}, {L"Ant", 0x0001}, {L"Anteater", 0x0006}, {L"Antelope", 0x0001}, {L"Ape", 0x0001}, {L"Armadillo", 0x0006}, {L"Ass", 0x0006}, {L"Baboon", 0x0001}, {L"Badger", 0x0001}, {L"Barracuda", 0x0030}, {L"Bat", 0x0001}, {L"Bear", 0x0008}, {L"Beaver", 0x0001}, {L"Bee", 0x000E}, {L"Binturong", 0x0001}, {L"Bird", 0x0009}, {L"Bison", 0x0006}, {L"Bluebird", 0x0009}, {L"Boar", 0x0001}, {L"Bobcat", 0x0001}, {L"Buffalo", 0x0001}, {L"Butterfly", 0x000D}, {L"Camel", 0x0006}, {L"Capybara", 0x0001}, {L"Caracal", 0x0001}, {L"Caribou", 0x0001}, {L"Cassowary", 0x0001}, {L"Cat", 0x0001}, {L"Caterpillar", 0x0001}, {L"Chameleon", 0x000A}, {L"Chamois", 0x0001}, {L"Cheetah", 0x0001}, {L"Chicken", 0x000F}, {L"Chimpanzee", 0x0001}, {L"Chinchilla", 0x0001}, {L"Chough", 0x0001}, {L"Coati", 0x0001}, {L"Cobra", 0x0001}, {L"Cockroach", 0x0001}, {L"Cod", 0x000B}, {L"Cormorant", 0x0001}, {L"Cougar", 0x0001}, {L"Coyote", 0x0006}, {L"Crab", 0x000C}, {L"Crane", 0x0001}, {L"Cricket", 0x000A}, {L"Crocodile", 0x000A}, {L"Crow", 0x0008}, {L"Cuckoo", 0x0001}, {L"Curlew", 0x0001}, {L"Deer", 0x0001}, {L"Degu", 0x0001}, {L"Dhole", 0x0001}, {L"Dingo", 0x0006}, {L"Dinosaur", 0x0003}, {L"Dog", 0x0001}, {L"Dogfish", 0x0001}, {L"Dolphin", 0x0001}, {L"Donkey", 0x0008}, {L"Dotterel", 0x0001}, {L"Dove", 0x000F}, {L"Dragonfly", 0x000B}, {L"Duck", 0x0001}, {L"Dugong", 0x0001}, {L"Dunlin", 0x0001}, {L"Eagle", 0x0006}, {L"Echidna", 0x0004}, {L"Eel", 0x000B}, {L"Eland", 0x0001}, {L"Elephant", 0x0008}, {L"Elephant Seal", 0x0008}, {L"Elk", 0x0006}, {L"Emu", 0x0001}, {L"Falcon", 0x0001}, {L"Ferret", 0x0001}, {L"Finch", 0x0001}, {L"Fish", 0x0001}, {L"Flamingo", 0x0001}, {L"Fly", 0x0008}, {L"Fox", 0x0006}, {L"Frog", 0x000A}, {L"Gaur", 0x0001}, {L"Gazelle", 0x0001}, {L"Gecko", 0x000A}, {L"Gerbil", 0x0001}, {L"Giant panda", 0x000F}, {L"Giraffe", 0x0001}, {L"Gnat", 0x0001}, {L"Gnu", 0x0001}, {L"Goat", 0x0001}, {L"Goldfinch", 0x0006}, {L"Goosander", 0x0001}, {L"Goose", 0x0001}, {L"Gorilla", 0x0008}, {L"Goshawk", 0x0001}, {L"Grasshopper", 0x0001}, {L"Grouse", 0x0001}, {L"Guanaco", 0x0001}, {L"Guinea fowl", 0x0001}, {L"Guinea pig", 0x0006}, {L"Gull", 0x0001}, {L"Hamster", 0x0006}, {L"Hare", 0x0001}, {L"Hawk", 0x0001}, {L"Hedgehog", 0x0001}, {L"Hermit crab", 0x000C}, {L"Heron", 0x0001}, {L"Herring", 0x0001}, {L"Hippopotamus", 0x0008}, {L"Hoatzin", 0x0001}, {L"Hoopoe", 0x0001}, {L"Hornet", 0x000E}, {L"Horse", 0x0008}, {L"Human", 0x0001}, {L"Hummingbird", 0x0001}, {L"Hyena", 0x0008}, {L"Ibex", 0x000F}, {L"Ibis", 0x0001}, {L"Iguana", 0x000A}, {L"Impala", 0x0006}, {L"Jackal", 0x0006}, {L"Jaguar", 0x0001}, {L"Jay", 0x0001}, {L"Jellyfish", 0x000B}, {L"Jerboa", 0x0001}, {L"Kangaroo", 0x0006}, {L"Kingfisher", 0x0001}, {L"Kinkajou", 0x0001}, {L"Koala", 0x0008}, {L"Komodo dragon", 0x000A}, {L"Kookaburra", 0x0001}, {L"Kouprey", 0x0001}, {L"Kudu", 0x0001}, {L"Lapwing", 0x0001}, {L"Lark", 0x0001}, {L"Lemur", 0x0006}, {L"Leopard", 0x0001}, {L"Lion", 0x0001}, {L"Lizard", 0x000A}, {L"Llama", 0x000F}, {L"Lobster", 0x0001}, {L"Locust", 0x000A}, {L"Loris", 0x0001}, {L"Louse", 0x0001}, {L"Lynx", 0x0001}, {L"Lyrebird", 0x0001}, {L"Macaque", 0x0001}, {L"Macaw", 0x0001}, {L"Magpie", 0x0001}, {L"Mallard", 0x0001}, {L"Also see Duck", 0x000A}, {L"Mammoth", 0x0004}, {L"Manatee", 0x0001}, {L"Mandrill", 0x0001}, {L"Marmoset", 0x0001}, {L"Marmot", 0x0006}, {L"Meerkat", 0x0006}, {L"Mink", 0x0001}, {L"Mole", 0x0001}, {L"Mongoose", 0x0001}, {L"Monkey", 0x0006}, {L"Moose", 0x0001}, {L"Mosquito", 0x0001}, {L"Mouse", 0x0001}, {L"Myna", 0x0001}, {L"Narwhal", 0x0008}, {L"Newt", 0x0001}, {L"Nightingale", 0x0001}, {L"Nine-banded armadillo", 0x0001}, {L"Octopus", 0x0001}, {L"Okapi", 0x0001}, {L"Opossum", 0x0001}, {L"Oryx", 0x0001}, {L"Ostrich", 0x0001}, {L"Otter", 0x0001}, {L"Owl", 0x0001}, {L"Oyster", 0x0006}, {L"Panther", 0x0001}, {L"Parrot", 0x0001}, {L"Panda", 0x000F}, {L"Partridge", 0x0001}, {L"Peafowl", 0x0001}, {L"Pelican", 0x000F}, {L"Penguin", 0x0001}, {L"Pheasant", 0x0001}, {L"Pig", 0x0005}, {L"Also see Boar", 0x0001}, {L"Pigeon", 0x0001}, {L"Pika", 0x0001}, {L"Polar bear", 0x000F}, {L"Pony", 0x0001}, {L"Porcupine", 0x0001}, {L"Porpoise", 0x0001}, {L"Prairie dog", 0x0001}, {L"Pug", 0x000F}, {L"Quail", 0x0008}, {L"Quelea", 0x0001}, {L"Quetzal", 0x000A}, {L"Rabbit", 0x0008}, {L"Raccoon", 0x0008}, {L"Ram", 0x0006}, {L"Rat", 0x0008}, {L"Raven", 0x0008}, {L"Red deer", 0x0004}, {L"Red panda", 0x0004}, {L"Reindeer", 0x0006}, {L"Rhea", 0x0001}, {L"Rhinoceros", 0x0001}, {L"Rook", 0x0001}, {L"Salamander", 0x0002}, {L"Salmon", 0x000C}, {L"Sand dollar", 0x000F}, {L"Sandpiper", 0x0001}, {L"Sardine", 0x000B}, {L"Sea lion", 0x0008}, {L"Seahorse", 0x000E}, {L"Seal", 0x0001}, {L"Shark", 0x0003}, {L"Sheep", 0x000F}, {L"Shrew", 0x0006}, {L"Siamang", 0x0001}, {L"Skunk", 0x0008}, {L"Sloth", 0x0002}, {L"Snail", 0x000B}, {L"Snake", 0x000A}, {L"Spider", 0x0008}, {L"Squid", 0x000B}, {L"Squirrel", 0x0008}, {L"Starling", 0x0009}, {L"Stegosaurus", 0x0002}, {L"Swan", 0x000F}, {L"Tamarin", 0x0001}, {L"Tapir", 0x0001}, {L"Tarsier", 0x0001}, {L"Termite", 0x0001}, {L"Tiger", 0x0006}, {L"Toad", 0x000A}, {L"Toucan", 0x000E}, {L"Turaco", 0x0001}, {L"Turkey", 0x0001}, {L"Turtle", 0x0002}, {L"Vicu�a", 0x0001}, {L"Vinegaroon", 0x0006}, {L"Viper", 0x0001}, {L"Vulture", 0x0001}, {L"Wallaby", 0x0001}, {L"Walrus", 0x0008}, {L"Wasp", 0x0001}, {L"Water buffalo", 0x0001}, {L"Waxwing", 0x0001}, {L"Weasel", 0x0001}, {L"Whale", 0x0030}, {L"Wobbegong", 0x0001}, {L"Wolf", 0x0007}, {L"Wolverine", 0x0001}, {L"Wombat", 0x0001}, {L"Woodpecker", 0x0001}, {L"Worm", 0x0008}, {L"Wren", 0x0001}, {L"Yak", 0x0001}, {L"Zebra", 0x000F}
};
map<wstring, int> monster::bears = { {L"Cinnamon Bear", 0x0008}, {L"Florida Black Bear", 0x0008}, {L"Glacier Bear", 0x0008}, {L"Haida Gwaii Black Bear", 0x0008}, {L"Louisiana Black Bear", 0x0008}, {L"Newfoundland Black Bear", 0x0008}, {L"Baluchistan Bear", 0x0008}, {L"Pakistan Black Bear", 0x0008}, {L"Formosan Black Bear", 0x0008}, {L"Himalayan Black Bear", 0x0008}, {L"Japanese Black Bear", 0x0008}, {L"Ussuri Black Bear", 0x0008}, {L"Alaska Peninsula Brown Bear", 0x0006}, {L"Atlas Bear", 0x0006}, {L"Bergman's Bear", 0x0006}, {L"Blue Bear", 0x0006}, {L"California Grizzly Bear", 0x0006}, {L"Cantabrian Brown Bear", 0x0006}, {L"Eurasian Brown Bear", 0x0006}, {L"European Brown Bear", 0x0006}, {L"Gobi Bear", 0x0006}, {L"Grizzly Bear", 0x0006}, {L"Himalayan Brown Bear", 0x0006}, {L"Kamchatka Brown Bear", 0x0006}, {L"Kodiak Bear", 0x0006}, {L"Marsican Brown Bear", 0x0006}, {L"Mexican Grizzly Bear", 0x0006}, {L"East Siberian Brown Bear", 0x0006}, {L"Sitka Brown Bear", 0x0006}, {L"Stickeen Brown Bear", 0x0006}, {L"Syrian Brown Bear", 0x0006}, {L"Ussuri Brown Bear", 0x0006}, {L"California Grizzly Bear", 0x0006}, {L"Cave Bear", 0x0006}, {L"Grizzly-Polar Bear Hybrid", 0x0006}, {L"Short-Faced Bear", 0x0006}, {L"Kermode Bear", 0x000F}, {L"Polar Bear", 0x000F}, {L"Spirit Bear", 0x000F}, {L"Dwarf Giant Panda", 0x000F}, {L"Giant Panda", 0x000F}, {L"Quinling Panda", 0x000F}, {L"Sloth Bear", 0x000B}, {L"Sri Lankan Sloth Bear", 0x000B}, {L"Spectacled Bear", 0x000E}, {L"Sun Bear", 0x000E}
};

monster::monster() {
	this->type = getMonsterType();
	this->name = getMonsterName(this->type);
	this->icon = getMonsterIcon(this->name);
	this->color = getMonsterColor(this->name, this->type);
	this->x = rand() % 200 - 100;
	this->y = rand() % 200 - 100;
	this->maxHP = rand() % 60 + 50;
	this->maxMP = rand() % 60 + 50;
	this->HP = rand() % this->maxHP + 1;
	this->MP = rand() % this->maxMP + 1;
}

monster::monster(int x, int y) {
	this->type = getMonsterType();
	this->name = getMonsterName(this->type);
	this->icon = getMonsterIcon(this->name);
	this->color = getMonsterColor(this->name, this->type);
	this->x = x;
	this->y = y;
	this->maxHP = rand() % 150 - 50;
	this->maxMP = rand() % 150 - 50;
	this->HP = rand() % this->maxHP + 1;
	this->MP = rand() % this->maxMP + 1;
}

wstring monster::getMonsterType() {
	int i = rand() % 100;
	if (i == 99) {
		return L"very_large_and_rare";
	}
	else if ((i < 99) && (i >= 97)) {
		return L"rare";
	}
	else if ((i < 97) && (i >= 95)) {
		return L"very_large";
	}
	else if ((i < 95) && (i >= 90)) {
		return L"large";
	}
	else if ((i < 90) && (i >= 75)) {
		return L"normal";
	}
	else if ((i < 75) && (i >= 60)) {
		return L"animal";
	}
	else if ((i < 60) && (i >= 50)) {
		return L"small";
	}
	else {
		return L"trash";
	}
}

wstring monster::getMonsterName(wstring type) {
	wstring name = L"Garbage";
	map<wstring, int> list;
	if (type == L"trash") {						list = trash; }
	else if (type == L"small") {				list = tiny; }
	else if (type == L"normal") {				list = normal; }
	else if (type == L"animal") {
		list = animals;
		auto it = next(begin(animals), rand() % animals.size());
		if (it->first == L"Bear") {
			list = bears;
		}
	}
	else if (type == L"large") {				list = large; }
	else if (type == L"very_large") {			list = veryLarge; }
	else if (type == L"rare") {					list = rare; }
	else if (type == L"very_rare") {			list = veryRare; }
	else if (type == L"very_large_and_rare") {	list = veryLargeAndRare;	}
	else if (type == L"giant") {				list = giant; }
	// auto it = next(begin(list), rand() % list.size())->first;
	// name = it->first;
	return next(begin(list), rand() % list.size())->first;
}

wchar_t monster::getMonsterIcon(wstring name) {
	if (name == L"Crow") { return 0x04AB; }
	else if (name == L"Rat") { return 0x036C; }
	else if (name == L"Worm") { return 0x0360; }
	else if (name.find(L"Bear") != std::string::npos) {
		return 'b';
	}
	else {
		return tolower(name[0]);
	}
}

int monster::getMonsterColor(wstring name, wstring type) {
	if (type == L"trash") {						return findColor(trash, name); }
	else if (type == L"small") {				return findColor(trash, name); }
	else if (type == L"normal") {				return findColor(normal, name); }
	else if (type == L"animal") {
		if (name.find(L"Bear") != std::string::npos) {
												return findColor(bears, name);
		}
		else {									return findColor(animals, name); }
	}
	else if (type == L"large") {				return findColor(large, name); }
	else if (type == L"very_large") {			return findColor(veryLarge, name); }
	else if (type == L"rare") {					return findColor(rare, name); }
	else if (type == L"very_rare") {			return findColor(veryRare, name); }
	else if (type == L"very_large_and_rare") {	return findColor(veryLargeAndRare, name); }
	else if (type == L"giant") {				return findColor(giant, name); }
	else { return 0x000A; }
}

int monster::findColor(map<wstring, int> list, wstring name) {
	auto it = list.begin();
	int color = 0;
	while (it != list.end()) {
		if (it->first == name) {
			color = it->second;
			break;
		}
		it++;
	}
	return color;
}