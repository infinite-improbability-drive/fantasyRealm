#include "pch.h"
#include "time.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

static wstring getMonsterType();
static wstring getMonsterName(wstring type);
static wchar_t getMonsterIcon(wstring name);


static wstring trashMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring smallMonsters[] = { L"Gnome", L"Fairy", L"Cockatrice", L"Enchanted Clothing",
	L"Faery", L"Goblin", L"Hobbit", L"Imp", L"Jackelope", L"Kodama", L"Leprechaun", L"Pirhana",
	L"Pixie", L"Rat", L"Slime", L"Sprite", L"Wisp" };
static wstring normalMonsters[] = { L"Bandit", L"Basilisk", L"Centaur", L"Demon", L"Djinn",
	L"Dryad", L"Elemental", L"Enchanted Furniture", L"Faun", L"Ghoul", L"Giant Rat", L"Green Man",
	L"Harpy", L"Lamia", L"Large Slime", L"Mermaid", L"Naga", L"Orc", L"Satyr", L"Shapeshifter",
	L"Siren", L"Tengu", L"Vampire", L"Wendigo", L"Werewolf", L"Wolf", L"Yokai", L"Zombie" };
static wstring largeMonsters[] = { L"Alpha Wolf", L"Behemoth", L"Demon King", L"Dire Wolf",
	L"Giantic Rat", L"Goblin King", L"Golem", L"Griffin", L"Hydra", L"Land Shark", L"Manticore",
	L"Minotaur", L"Ogre", L"Orc Captain", L"Scorpion Man", L"Were-bear" };
static wstring veryLargeMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring rareMonsters[] = { L"Crow", L"Rat", L"Worm" };
static wstring veryRareMonsters[] = { L"Unicorn" };
static wstring veryLargeAndRareMonsters[] = { L"Nightwalker", L"Bigfoot" };
static wstring giantMonsters[] = { L"Gamera" };
static wstring bossMonsters[] = { L"Crow", L"Rat", L"Worm" };

static wstring animals[] = { L"Aardvark", L"Albatross", L"Alligator", L"Alpaca", L"Ant", L"Anteater", L"Antelope", L"Ape", L"Armadillo", L"Ass", L"Baboon", L"Badger", L"Barracuda", L"Bat", L"Bear", L"Beaver", L"Bee", L"Binturong", L"Bird", L"Bison", L"Bluebird", L"Boar", L"Bobcat", L"Buffalo", L"Butterfly", L"Camel", L"Capybara", L"Caracal", L"Caribou", L"Cassowary", L"Cat", L"Caterpillar", L"Chameleon", L"Chamois", L"Cheetah", L"Chicken", L"Chimpanzee", L"Chinchilla", L"Chough", L"Coati", L"Cobra", L"Cockroach", L"Cod", L"Cormorant", L"Cougar", L"Coyote", L"Crab", L"Crane", L"Cricket", L"Crocodile", L"Crow", L"Cuckoo", L"Curlew", L"Deer", L"Degu", L"Dhole", L"Dingo", L"Dinosaur", L"Dog", L"Dogfish", L"Dolphin", L"Donkey", L"Dotterel", L"Dove", L"Dragonfly", L"Duck", L"Dugong", L"Dunlin", L"Eagle", L"Echidna", L"Eel", L"Eland", L"Elephant", L"Elephant seal", L"Elk", L"Emu", L"Falcon", L"Ferret", L"Finch", L"Fish", L"Flamingo", L"Fly", L"Fox", L"Frog", L"Gaur", L"Gazelle", L"Gecko", L"Gerbil", L"Giant panda", L"Giraffe", L"Gnat", L"Gnu", L"Goat", L"Goldfinch", L"Goosander", L"Goose", L"Gorilla", L"Goshawk", L"Grasshopper", L"Grouse", L"Guanaco", L"Guinea fowl", L"Guinea pig", L"Gull", L"Hamster", L"Hare", L"Hawk", L"Hedgehog", L"Hermit crab", L"Heron", L"Herring", L"Hippopotamus", L"Hoatzin", L"Hoopoe", L"Hornet", L"Horse", L"Human", L"Hummingbird", L"Hyena", L"Ibex", L"Ibis", L"Iguana", L"Impala", L"Jackal", L"Jaguar", L"Jay", L"Jellyfish", L"Jerboa", L"Kangaroo", L"Kingfisher", L"Kinkajou", L"Koala", L"Komodo dragon", L"Kookaburra", L"Kouprey", L"Kudu", L"Lapwing", L"Lark", L"Lemur", L"Leopard", L"Lion", L"Lizard", L"Llama", L"Lobster", L"Locust", L"Loris", L"Louse", L"Lynx", L"Lyrebird", L"Macaque", L"Macaw", L"Magpie", L"Mallard", L"Also see Duck", L"Mammoth", L"Manatee", L"Mandrill", L"Marmoset", L"Marmot", L"Meerkat", L"Mink", L"Mole", L"Mongoose", L"Monkey", L"Moose", L"Mosquito", L"Mouse", L"Myna", L"Narwhal", L"Newt", L"Nightingale", L"Nine-banded armadillo", L"Octopus", L"Okapi", L"Opossum", L"Oryx", L"Ostrich", L"Otter", L"Owl", L"Oyster", L"Panther", L"Parrot", L"Panda", L"Partridge", L"Peafowl", L"Pelican", L"Penguin", L"Pheasant", L"Pig", L"Also see Boar", L"Pigeon", L"Pika", L"Polar bear", L"Pony", L"Porcupine", L"Porpoise", L"Prairie dog", L"Pug", L"Quail", L"Quelea", L"Quetzal", L"Rabbit", L"Raccoon", L"Ram", L"Rat", L"Raven", L"Red deer", L"Red panda", L"Reindeer", L"Rhea", L"Rhinoceros", L"Rook", L"Salamander", L"Salmon", L"Sand dollar", L"Sandpiper", L"Sardine", L"Sea lion", L"Seahorse", L"Seal", L"Shark", L"Sheep", L"Shrew", L"Siamang", L"Skunk", L"Sloth", L"Snail", L"Snake", L"Spider", L"Squid", L"Squirrel", L"Starling", L"Stegosaurus", L"Swan", L"Tamarin", L"Tapir", L"Tarsier", L"Termite", L"Tiger", L"Toad", L"Toucan", L"Turaco", L"Turkey", L"Turtle", L"Vicuña", L"Vinegaroon", L"Viper", L"Vulture", L"Wallaby", L"Walrus", L"Wasp", L"Water buffalo", L"Waxwing", L"Weasel", L"Whale", L"Wobbegong", L"Wolf", L"Wolverine", L"Wombat", L"Woodpecker", L"Worm", L"Wren", L"Yak", L"Zebra"
};

static map<wstring, int> animals1 = {
	{L"Aardvark", 0x0001},  {L"Albatross", 0x0001}, {L"Alligator", 0x0001}, {L"Alpaca", 0x0001}, {L"Ant", 0x0001}, {L"Anteater", 0x0001}, {L"Antelope", 0x0001}, {L"Ape", 0x0001}, {L"Armadillo", 0x0001}, {L"Ass", 0x0001}, {L"Baboon", 0x0001}, {L"Badger", 0x0001}, {L"Barracuda", 0x0001}, {L"Bat", 0x0001}, {L"Bear", 0x0001}, {L"Beaver", 0x0001}, {L"Bee", 0x0001}, {L"Binturong", 0x0001}, {L"Bird", 0x0001}, {L"Bison", 0x0001}, {L"Bluebird", 0x0001}, {L"Boar", 0x0001}, {L"Bobcat", 0x0001}, {L"Buffalo", 0x0001}, {L"Butterfly", 0x0001}, {L"Camel", 0x0001}, {L"Capybara", 0x0001}, {L"Caracal", 0x0001}, {L"Caribou", 0x0001}, {L"Cassowary", 0x0001}, {L"Cat", 0x0001}, {L"Caterpillar", 0x0001}, {L"Chameleon", 0x0001}, {L"Chamois", 0x0001}, {L"Cheetah", 0x0001}, {L"Chicken", 0x0001}, {L"Chimpanzee", 0x0001}, {L"Chinchilla", 0x0001}, {L"Chough", 0x0001}, {L"Coati", 0x0001}, {L"Cobra", 0x0001}, {L"Cockroach", 0x0001}, {L"Cod", 0x0001}, {L"Cormorant", 0x0001}, {L"Cougar", 0x0001}, {L"Coyote", 0x0001}, {L"Crab", 0x0001}, {L"Crane", 0x0001}, {L"Cricket", 0x0001}, {L"Crocodile", 0x0001}, {L"Crow", 0x0001}, {L"Cuckoo", 0x0001}, {L"Curlew", 0x0001}, {L"Deer", 0x0001}, {L"Degu", 0x0001}, {L"Dhole", 0x0001}, {L"Dingo", 0x0001}, {L"Dinosaur", 0x0001}, {L"Dog", 0x0001}, {L"Dogfish", 0x0001}, {L"Dolphin", 0x0001}, {L"Donkey", 0x0001}, {L"Dotterel", 0x0001}, {L"Dove", 0x0001}, {L"Dragonfly", 0x0001}, {L"Duck", 0x0001}, {L"Dugong", 0x0001}, {L"Dunlin", 0x0001}, {L"Eagle", 0x0001}, {L"Echidna", 0x0001}, {L"Eel", 0x0001}, {L"Eland", 0x0001}, {L"Elephant", 0x0001}, {L"Elephant seal", 0x0001}, {L"Elk", 0x0001}, {L"Emu", 0x0001}, {L"Falcon", 0x0001}, {L"Ferret", 0x0001}, {L"Finch", 0x0001}, {L"Fish", 0x0001}, {L"Flamingo", 0x0001}, {L"Fly", 0x0001}, {L"Fox", 0x0001}, {L"Frog", 0x0001}, {L"Gaur", 0x0001}, {L"Gazelle", 0x0001}, {L"Gecko", 0x0001}, {L"Gerbil", 0x0001}, {L"Giant panda", 0x0001}, {L"Giraffe", 0x0001}, {L"Gnat", 0x0001}, {L"Gnu", 0x0001}, {L"Goat", 0x0001}, {L"Goldfinch", 0x0001}, {L"Goosander", 0x0001}, {L"Goose", 0x0001}, {L"Gorilla", 0x0001}, {L"Goshawk", 0x0001}, {L"Grasshopper", 0x0001}, {L"Grouse", 0x0001}, {L"Guanaco", 0x0001}, {L"Guinea fowl", 0x0001}, {L"Guinea pig", 0x0001}, {L"Gull", 0x0001}, {L"Hamster", 0x0001}, {L"Hare", 0x0001}, {L"Hawk", 0x0001}, {L"Hedgehog", 0x0001}, {L"Hermit crab", 0x0001}, {L"Heron", 0x0001}, {L"Herring", 0x0001}, {L"Hippopotamus", 0x0001}, {L"Hoatzin", 0x0001}, {L"Hoopoe", 0x0001}, {L"Hornet", 0x0001}, {L"Horse", 0x0001}, {L"Human", 0x0001}, {L"Hummingbird", 0x0001}, {L"Hyena", 0x0001}, {L"Ibex", 0x0001}, {L"Ibis", 0x0001}, {L"Iguana", 0x0001}, {L"Impala", 0x0001}, {L"Jackal", 0x0001}, {L"Jaguar", 0x0001}, {L"Jay", 0x0001}, {L"Jellyfish", 0x0001}, {L"Jerboa", 0x0001}, {L"Kangaroo", 0x0001}, {L"Kingfisher", 0x0001}, {L"Kinkajou", 0x0001}, {L"Koala", 0x0001}, {L"Komodo dragon", 0x0001}, {L"Kookaburra", 0x0001}, {L"Kouprey", 0x0001}, {L"Kudu", 0x0001}, {L"Lapwing", 0x0001}, {L"Lark", 0x0001}, {L"Lemur", 0x0001}, {L"Leopard", 0x0001}, {L"Lion", 0x0001}, {L"Lizard", 0x0001}, {L"Llama", 0x0001}, {L"Lobster", 0x0001}, {L"Locust", 0x0001}, {L"Loris", 0x0001}, {L"Louse", 0x0001}, {L"Lynx", 0x0001}, {L"Lyrebird", 0x0001}, {L"Macaque", 0x0001}, {L"Macaw", 0x0001}, {L"Magpie", 0x0001}, {L"Mallard", 0x0001}, {L"Also see Duck", 0x0001}, {L"Mammoth", 0x0001}, {L"Manatee", 0x0001}, {L"Mandrill", 0x0001}, {L"Marmoset", 0x0001}, {L"Marmot", 0x0001}, {L"Meerkat", 0x0001}, {L"Mink", 0x0001}, {L"Mole", 0x0001}, {L"Mongoose", 0x0001}, {L"Monkey", 0x0001}, {L"Moose", 0x0001}, {L"Mosquito", 0x0001}, {L"Mouse", 0x0001}, {L"Myna", 0x0001}, {L"Narwhal", 0x0001}, {L"Newt", 0x0001}, {L"Nightingale", 0x0001}, {L"Nine-banded armadillo", 0x0001}, {L"Octopus", 0x0001}, {L"Okapi", 0x0001}, {L"Opossum", 0x0001}, {L"Oryx", 0x0001}, {L"Ostrich", 0x0001}, {L"Otter", 0x0001}, {L"Owl", 0x0001}, {L"Oyster", 0x0001}, {L"Panther", 0x0001}, {L"Parrot", 0x0001}, {L"Panda", 0x0001}, {L"Partridge", 0x0001}, {L"Peafowl", 0x0001}, {L"Pelican", 0x0001}, {L"Penguin", 0x0001}, {L"Pheasant", 0x0001}, {L"Pig", 0x0001}, {L"Also see Boar", 0x0001}, {L"Pigeon", 0x0001}, {L"Pika", 0x0001}, {L"Polar bear", 0x0001}, {L"Pony", 0x0001}, {L"Porcupine", 0x0001}, {L"Porpoise", 0x0001}, {L"Prairie dog", 0x0001}, {L"Pug", 0x0001}, {L"Quail", 0x0001}, {L"Quelea", 0x0001}, {L"Quetzal", 0x0001}, {L"Rabbit", 0x0001}, {L"Raccoon", 0x0001}, {L"Ram", 0x0001}, {L"Rat", 0x0001}, {L"Raven", 0x0001}, {L"Red deer", 0x0001}, {L"Red panda", 0x0001}, {L"Reindeer", 0x0001}, {L"Rhea", 0x0001}, {L"Rhinoceros", 0x0001}, {L"Rook", 0x0001}, {L"Salamander", 0x0001}, {L"Salmon", 0x0001}, {L"Sand dollar", 0x0001}, {L"Sandpiper", 0x0001}, {L"Sardine", 0x0001}, {L"Sea lion", 0x0001}, {L"Seahorse", 0x0001}, {L"Seal", 0x0001}, {L"Shark", 0x0001}, {L"Sheep", 0x0001}, {L"Shrew", 0x0001}, {L"Siamang", 0x0001}, {L"Skunk", 0x0001}, {L"Sloth", 0x0001}, {L"Snail", 0x0001}, {L"Snake", 0x0001}, {L"Spider", 0x0001}, {L"Squid", 0x0001}, {L"Squirrel", 0x0001}, {L"Starling", 0x0001}, {L"Stegosaurus", 0x0001}, {L"Swan", 0x0001}, {L"Tamarin", 0x0001}, {L"Tapir", 0x0001}, {L"Tarsier", 0x0001}, {L"Termite", 0x0001}, {L"Tiger", 0x0001}, {L"Toad", 0x0001}, {L"Toucan", 0x0001}, {L"Turaco", 0x0001}, {L"Turkey", 0x0001}, {L"Turtle", 0x0020}, {L"Vicuña", 0x0001}, {L"Vinegaroon", 0x0001}, {L"Viper", 0x0001}, {L"Vulture", 0x0001}, {L"Wallaby", 0x0001}, {L"Walrus", 0x0007}, {L"Wasp", 0x0001}, {L"Water buffalo", 0x0001}, {L"Waxwing", 0x0001}, {L"Weasel", 0x0001}, {L"Whale", 0x0001}, {L"Wobbegong", 0x0001}, {L"Wolf", 0x0007}, {L"Wolverine", 0x0001}, {L"Wombat", 0x0001}, {L"Woodpecker", 0x0001}, {L"Worm", 0x0001}, {L"Wren", 0x0001}, {L"Yak", 0x0001}, {L"Zebra", 0x0001}
};


class monster {
public:
	wstring name;
	wstring type;
	wchar_t icon;
	int color = 0x000A;
	int x;
	int y;
	monster() {
		this->type = getMonsterType();
		this->name = getMonsterName(this->type);
		// this->icon = tolower(this->name[0]);
		this->icon = getMonsterIcon(this->name);
		this->x = rand() % 200 - 100;
		this->y = rand() % 200 - 100;
	}
};

static wstring getMonsterType() {
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

static wstring getMonsterName(wstring type) {
	wstring name = L"Garbage";
	if (type == L"trash") {
		name = trashMonsters[rand() % (sizeof(trashMonsters) / sizeof(trashMonsters[0]))];
	}
	else if (type == L"small") {
		name = smallMonsters[rand() % (sizeof(smallMonsters) / sizeof(smallMonsters[0]))];
	}
	else if (type == L"normal") {
		name = normalMonsters[rand() % (sizeof(normalMonsters) / sizeof(normalMonsters[0]))];
	}
	else if (type == L"animal") {
		name = animals[rand() % (sizeof(animals) / sizeof(animals[0]))];
	}
	else if (type == L"large") {
		name = largeMonsters[rand() % (sizeof(largeMonsters) / sizeof(largeMonsters[0]))];
	}
	else if (type == L"very_large") {
		name = veryLargeMonsters[rand() % (sizeof(veryLargeMonsters) / sizeof(veryLargeMonsters[0]))];
	}
	else if (type == L"rare") {
		name = rareMonsters[rand() % (sizeof(rareMonsters) / sizeof(rareMonsters[0]))];
	}
	else if (type == L"very_rare") {
		name = veryRareMonsters[rand() % (sizeof(veryRareMonsters) / sizeof(veryRareMonsters[0]))];
	}
	else if (type == L"very_large_and_rare") {
		name = veryLargeAndRareMonsters[rand() % (sizeof(veryLargeAndRareMonsters) / sizeof(veryLargeAndRareMonsters[0]))];
	}
	else if (type == L"giant") {
		name = giantMonsters[rand() % (sizeof(giantMonsters) / sizeof(giantMonsters[0]))];
	}
	return name;
}

static wchar_t getMonsterIcon(wstring name) {
	// if (name == L"Rat") { return 'u\00A5'; }
	return tolower(name[0]);
}
