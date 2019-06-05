#include "pch.h"
#include "names.h"
#include <string>

using namespace std;

wstring names::roles[15] = {
	L"Barbarian", L"Bard", L"Cleric", L"Demon Hunter", L"Druid", L"Knight", L"Paladin", L"Pugilist",
	L"Pyromancer", L"Samurai", L"Sniper", L"Sorcerer", L"Thief", L"Princess", L"Fool"
};

wstring names::first[5] = { L"Elsie", L"Charlotte", L"Harold", L"Leopold", L"Olga" };

wstring names::last[479] = {
	// World population = 7.55 billion
	// China - 1.40 billion
	L"Wang", L"Wong", L"Li", L"Lee", L"Zhang", L"Cheung", L"Liu", L"Lau", L"Chen",
	L"Chan", L"Yang", L"Yeung", L"Zhao", L"Chiu", L"Wu", L"Ng", L"Zhou", L"Chow",
	L"Xu", L"Tsui", L"Sun", L"Sun", L"Ma", L"Ma", L"Zhu", L"Chu", L"Hu", L"Woo", L"Guo",
	L"Kwok", L"He", L"Ho", L"Gao", L"Ko", L"L�n", L"Lam", L"Luo", L"Law",

	// India - 1.39 billion
	L"Patel", L"Singh", L"Kumar", L"Das", L"Kaur", L"Ram", L"Yadav", L"Kumari",
	L"Ali", L"Lal", L"Bibi", L"Khatun", L"Bai", L"Sharma", L"Sah", L"Khan", L"Mandal",
	L"Mandol", L"Patil", L"Rajput",

	// United States - 324.45 million
	L"Smith", L"Johnson", L"Williams", L"Brown", L"Jones", L"Miller", L"Davis",
	L"Garcia", L"Rodriguez", L"Wilson", L"Martinez", L"Anderson", L"Taylor",
	L"Thomas", L"Hernandez", L"Moore", L"Martin", L"Jackson", L"Thompson", L"White",
	L"Lopez", L"Lee", L"Gonzales", L"Harris", L"Clark", L"Lewis", L"Robinson",
	L"Walker", L"Perez", L"Hall", L"Young", L"Allen", L"Sanchez", L"Wright", L"King",
	L"Scott", L"Green", L"Baker", L"Adams", L"Nelson", L"Hill", L"Ramirez",
	L"Campbell", L"Mitchell", L"Roberts", L"Carter", L"Phillips", L"Evans",
	L"Turner", L"Torres", L"Parker", L"Collins", L"Edwards", L"Stewart", L"Flores",
	L"Morris", L"Nguyen", L"Murphy", L"Rivera", L"Cook", L"Rogers", L"Morgan",
	L"Peterson", L"Cooper", L"Reed", L"Bailey", L"Bell", L"Gomez", L"Kelly",
	L"Howard", L"Ward", L"Cox", L"Diaz", L"Richardson", L"Wood", L"Watson",
	L"Brooks", L"Bennet", L"Gray", L"James", L"Reyes", L"Cruz", L"Hughes", L"Price",
	L"Myers", L"Long", L"Foster", L"Sanders", L"Ross", L"Morales", L"Powell",
	L"Sullivan", L"Ortiz", L"Jenkins", L"Gutierrez", L"Perry", L"Butler", L"Barnes",
	L"Fisher",

	// Indonesia - 263.99 million
	L"Aipa", L"Akbar",
	// Brazil - 209.28 million

	// Pakistan - 197.01 million

	// Nigeria - 190.88 million

	// Bangladesh - 164.66 million

	// Russia - 143.98 million

	// Mexico - 129.16 million

	// Japan 127.48 million
	L"Sato", L"Suzuki", L"Takahashi", L"Tanaka", L"Watanabe", L"Ito", L"Yamamoto",
	L"Nakamura", L"Kobayashi", L"Kato", L"Yoshida", L"Yamada", L"Sasaki",
	L"Yamaguchi", L"Saito", L"Matsumoto", L"Inoue", L"Kimura", L"Hayashi",
	L"Yamazaki", L"Mori", L"Abe", L"Ikeda", L"Hashimoto", L"Yamashita", L"Ishikawa",
	L"Nakajima", L"Maeda", L"Fujita", L"Ogawa", L"Goto", L"Okada", L"Hasegawa",
	L"Murakami", L"Kondo", L"Ishii", L"Sakamoto", L"Aoki", L"Fujii", L"Nishimura",
	L"Fukida", L"Ota", L"Miura", L"Fujiwara", L"Okamoto", L"Matsuda", L"Nakagawa",
	L"Nakano", L"Harada", L"Ono", L"Tamura", L"Kaneko", L"Wada", L"Nakayama",
	L"Ishida", L"Ueda", L"Morita", L"Hara", L"Shibata", L"Sakai", L"Yokoyama",
	L"Miyazaki", L"Miyamoto", L"Uchida", L"Takagi", L"Ando", L"Taniguchi", L"Ohno",
	L"Maruyama", L"Imai", L"Takada", L"Fujimoto", L"Takeda", L"Murata", L"Ueno",
	L"Sugiyama", L"Masuda", L"Sugawara", L"Hirano", L"Kojima", L"Otsuka", L"Chiba",
	L"Kudo", L"Matsui", L"Iwasaki", L"Sakurai", L"Kinoshita", L"Noguchi",
	L"Matsuo", L"Nomura", L"Kikuchi", L"Sano", L"Onishi", L"Sugimoto", L"Arai",

	// Ethiopia 104.957 million

	// Philippines - 104.91 million

	// Egypt 97.55 million

	// Vietnam 95.54 million

	// Germany - 82.9 million - 9.54% european population
	L"M\u00fcller", L"Schmidt", L"Schneider", L"Fischer", L"Meyer", L"Weber", L"Schulz",
	L"Wagner", L"Becker", L"Hoffman", L"Sch\u00e4fer", L"Koch", L"Bauer", L"Richter",
	L"Klein", L"Wolf", L"Schr\u00f6der", L"Neumann", L"Schwarz", L"Zimmerman", L"Braun",
	L"Kr\u00f6ger", L"Hofmann", L"Hartmann", L"Lange", L"Schmitt", L"Werner", L"Schmitz",
	L"Werner", L"Shmitt", L"Krause", L"Meier", L"Lehmann", L"Schmid", L"Schulze",
	L"Maier", L"K\u00f6hler", L"Hermann", L"K\u00f6nig", L"Walter", L"Mayer", L"Huber",
	L"Kaiser", L"Fuchs", L"Peters", L"Lang", L"Scholz", L"M�ller", L"Weiss", L"Jung",
	L"Hahn", L"Schubert", L"Vogel", L"Friedrich", L"Keller", L"G�nther", L"Frank",
	L"Berger", L"Winkler", L"Roth", L"Beck", L"Lorenz", L"Baumann", L"Franke",
	L"Albrecht", L"Schuster", L"Simon", L"Ludwig", L"B\u00f6hm", L"Winter", L"Kraus",
	L"Martin", L"Schumacher", L"Kr\u00e4mer", L"Vogt", L"Stein", L"J\u00e4ger", L"Otto",
	L"Sommer", L"Gross", L"Seidel", L"Heinrich", L"Brandt", L"Schreiber", L"Graf",
	L"Schulte", L"Deitrich", L"Ziegler", L"Kuhn", L"K�hn", L"Pohl", L"Horn",
	L"Bergmann", L"Thomas", L"Voigt", L"Sauer", L"Arnold", L"Wolff", L"Pfeiffer",

	// Democratic Republic of Congo - 81.33 million

	// Iran - 81.16 million

	// Turkey - pop. 80.74 mil - 9.18%
	L"Yilmaz", L"Kaya", L"Demir", L"Sahin", L"�elik", L"Yildiz", L"Yildirim",
	L"�zt�rk", L"Aydin", L"�zdemir",

	// United Kingdom - 66.18 mil - 7.64%
	//    1. England
	L"Smith", L"Jones", L"Taylor", L"Brown", L"Williams", L"Wilson", L"Johnson",
	L"Davies", L"Robinson", L"Wright", L"Thompson", L"Evans", L"Walker", L"White",
	L"Roberts", L"Green", L"Hall", L"Wood", L"Jackson", L"Clarke",
	//    2. Northern Ireland
	L"Campbell", L"Kelly", L"Johnston", L"Moore", L"Smyth", L"O'Neill", L"Doherty",
	L"Stewart", L"Quinn", L"Murphy", L"Graham", L"Martin", L"McLaughlin",
	L"Hamilton", L"Murray", L"Hughes",
	//    3. Scotland
	L"Robertson", L"Thomson", L"Anderson", L"MacDonald", L"Reid", L"Clark", L"Ross",
	L"Young", L"Mitchell", L"Watson", L"Paterson", L"Morrison", L"Sanders",
	//    4. Wales
	L"Rees", L"Jenkins", L"Owen", L"Price", L"Phillips", L"Moss", L"Driscoll",

	// France - pop. 64.97 mil - 7.8%
	L"Martin", L"Bernard", L"Dubois", L"Thomas", L"Robert", L"Richard", L"Petit",
	L"Durand", L"Leroy", L"Moreau", L"Simon", L"Laurent", L"Lefebvre", L"Michel",
	L"Garcia", L"David", L"Bertrand", L"Roux", L"Vincent", L"Fournier", L"Morel",
	L"Girard", L"Andr�", L"Lef�vre", L"Mercier", L"Dupont", L"Lambert", L"Bonnet",
	L"Francois", L"Martinez",

	// Italy - 59.35 mil - 7.16%
	L"Rossi", L"Russo", L"Ferrari", L"Esposito", L"Bianchi", L"Romano", L"Columbo",
	L"Ricci", L"Marino", L"Greco", L"Bruno", L"Gallo", L"Conti", L"De Luca",
	L"Mancini", L"Costa", L"Giordano", L"Rizzo",

	// Tanzania - 57.31 mil

	// Spain - 46.4 mil - 5.44%

	// Poland - 38.4 mil - 4.52% 

	// Romania - 19.8 mil - 2.33%
	L"Popa", L"Popescu", L"Pop", L"Radu", L"Dumitru", L"Stan", L"Stoica",
	L"Gheorghe", L"Matei", L"Ciobanu", L"Ionescu", L"Rusu",

	// Kazakhstan - 17.5 mil - 2.06%

	// Netherlands - 17.0 mil - 1.99%

	// Greece - 10.7 mil - 1.26%

	// Czech Republic - 10.5 mil - 1.24

	// Portugal - 10.3 mil - 1.21%

	// Sweden - 9.8 mil - 1.15%

	// Hungary - 9.8 mil - 1.15%

};

wstring names::full[485] = {

	// Ancient Names
	// Sumerian 4500 BC - 2004 BC
	// Sumerian King List
	//  1. Antedeluvian
	L"Alulim", L"Alalngar", L"En-men-lu-ana", L"En-men-gal-ana",
	L"Duzumid, the Shepherd", L"En-sipad-zid-ana", L"En-men-dur-ana",
	L"Ubara-Tutu",
	//  2. 1st Dynasty of Kish
	L"Jushur", L"Kullassina-bel", L"Nangishlishma", L"En-tarah-ana", L"Babum",
	L"Puannum", L"Kalibum", L"Kalumum", L"Zuqaqip", L"Atab", L"A-ba", L"Mashda",
	L"Arwium", L"Etana", L"Balih", L"En-me-nuna", L"Melem-Kish", L"Barsal-nuna",
	L"Zamug", L"Tizqar", L"Ilku", L"Iltasadum", L"En-me-barage-si",
	L"Aga of Kish",
	//  3. 1st Rulers of Uruk
	L"Mesh-ki-ang-gasher of E-ana", L"Enmerkar", L"Lugalbanda", L"Duzumid",
	L"Dumuzi", L"Gilgamesh", L"Ur-Nungal", L"Udul-kalama", L"La-ba'shum",
	L"En-nun-tarah-ana", L"Mesh-he", L"Melem-ana", L"Lugal-kitun",
	//  4. 1st Dynasty of Ur
	L"Mesh-Ane-pada", L"Mesh-ki-ang-Nuna", L"Elulu", L"Balulu",
	//  5. Dynasty of Awan
	L"Awan",
	//  6. 2nd Dynasty of Kish
	L"Susuda", L"Dadasig", L"Mamagal", L"Kalbum", L"Tuge", L"Men-nuna",
	L"Enbi-Ishtar", L"Lugalngu",
	//  7. 1st Dynasty of Lagash
	L"Lagash",
	//  8. Dynasty of Hamazi
	L"Hamazi",
	//  9. 2nd Dynasty of Uruk
	L"En-shag-kush-ana", L"Lugal-kinishe-dudu", L"Lugal-ure", L"Argandea",
	//  10. 2nd Dynasty of Ur
	L"Nanni", L"Mesh-ki-ang-Nanna II",
	//  11. Dynasty of Adab
	L"Lugal-Ane-mundu",
	//  12. Dynasty of Mari
	L"Anbu", L"Anba", L"Bazi", L"Zizi of Mari", L"Limer", L"Sharrum-iter",
	//  13. 3rd Dynasty of Kish
	L"Kug-Bau", L"Kubaba",
	//  14. Dynasty of Akshak
	L"Unzi", L"Undalulu", L"Urur", L"Puzur-Nirah", L"Ishu-Il",
	L"Shu-Suen of Akshak",
	//  15. 4th Dynasty of Kish
	L"Puzur-Suen", L"Ur-Zababa", L"Zimudar", L"Usi-watar", L"Eshtar-muti",
	L"Ishme-Shamash", L"Shu-ilishu", L"Nanniya",
	//  15. 3rd Dynasty of Uruk
	L"Lugal-zage-si",
	//   16. Dynasty of Akkad
	L"Sargon of Akkad", L"Rimush of Akkad", L"Manishtushu",
	L"Naram-Sin of Akkad", L"Shar-kali-sharri", L"Irgigi", L"Imi", L"Nanum",
	L"Ilulu", L"Dudu of Akkad", L"Shu-Durul",
	//   17. 4th Dynasty of Uruk
	L"Ur-ningin", L"Ur-gigir", L"Kuda", L"Puzur-ili", L"Ur-Utu",
	L"Lugal-melem",
	//   18. Gutian Rule
	L"Inkishush", L"Inkicuc", L"Sarlagab", L"Zarlagab", L"Shulme",
	L"Yarlagash", L"Elulmesh", L"Silulumesh", L"Silulu", L"Inimabakesh",
	L"Duga", L"Igeshaush", L"Ilu-An", L"Yarlagab", L"Ibate of Gutium",
	L"Yarla", L"Yarlangab", L"Kurum", L"Apilkin", L"La-erabum", L"Irarum",
	L"Ibranum", L"Hablum", L"Puzur-Suen", L"Yarlaganda", L"Tirigan",
	//   19. 5th Dynasty of Uruk
	L"Utu-hengal",
	//   20. 3rd Dynasty of Ur
	L"Ur-Namma", L"Ur-Nammu", L"Shulgi", L"Amar-Suena", L"Shu-Suen",
	L"Ibbi-Suen",
	//   21. Dynasty of Isin
	L"Ishabi-Erra", L"Shu-Ilishu", L"Iddin-Dagan", L"Ishme-Dagan",
	L"Lipit-Eshtar", L"Ur-Ninurta", L"Bur-Suen", L"Lipit-Enlil",
	L"Erra-imitti", L"Enlil-bani", L"Zambiya", L"Iter-pisha", L"Ur-du-kuga",
	L"Suen-magir", L"Damiq-ilishu",


	// Maya 2000 BC - ~1697 AD
	//    1. King names
	L"Ah Cacao", L"Butz Chan", L" Chaan-muan", L"Chan Bahlum", L"Cocom",
	L"Cu Ix", L"Kam-Bahlum-Mo", L"Kan Boar", L"Pacal", L"Pacal Balam", L"Tutul Xiu",
	L"Yax Kuk Mo", L"Yax Pac", L"Yaxum Balam", L"Cauac Sky",
	// English
	L"Animal Skull", L"Curl Nose", L"Double Bird", L"Flint Sky", L"Jaguar-Paw",
	L"Jaguar-Paw Jaguar", L"Jeweled Skull", L"Mat Head", L"Moon Jaguar",
	L"Moon Zero Bird", L"Smoke Jaguar", L"Smoke Monkey", L"Smoke Skull",
	L"Smoking Frog", L"Smoking Squirrel", L"Spearthrower Owl", L"Stormy Sky",
	L"Waterlily Jaguar",

	// Aztec - 500AD -
	L"Acamapichtli", L"Huitzilihuitl", L"Chimalpopoca", L"Itzcoatl",
	L"Moctezuma I", L"Axayacatl", L"Tizoc", L"Ahuitzotl", L"Moctezuma II",
	L"Cuitlhuac", L"Cuauhtemoc",

	// Inca 1200AD - 1572 AD
	L"Mancho Capac", L"Sinchi Roca", L"Lloque Yunpanqui", L"Mayta Capac",
	L"Capac Yupanqui", L"Inca Roca", L"Yahuar Huacac", L"Pachacuti",
	L"Tupac Inca Yupanqui", L"Huayna Capac", L"Huascar", L"Atahualpa",
	L"Topa Huallpa", L"Manco Capac II", L"Sayri Tupac", L"Titu Cusi Yupanqui",
	L"Tupac Amaru",

	// British Monarchs
	L"Anne", L"George I", L"George II", L"George III", L"George IV",
	L"William IV", L"Victoria", L"Edward VII", L"George V", L"Edward VIII",
	L"George V", L"Elizabeth II",

	// French Monarchs
	// https://en.wikipedia.org/wiki/List_of_French_monarchs
	// Merovingians (486-751)
	L"Clovis I", L"Childebert I", L"Chlothar I", L"Charibert I",
	L"Guntram", L"Chilperic I", L"Sigebert I", L"Childebert II",
	L"Chlothar II", L"Dagobert I", L"Sigebert II", L"Clovis II",
	L"Chlothar III", L"Childeric II", L"Theuderic III", L"Clovis IV",
	L"Childebert III", L"Dagobert III", L"Chilperic II", L"Chlothar IV",
	L"Theuderic IV", L"Childeric III",

	// Carolingians, Robertians and Bosonids(751–987)
	L"Pepin the Short", L"Carloman I", L"Charlemagne", L"Charles I",
	L"Louis I", L"Charles II", L"Louis II", L"Louis III", L"Carloman II",
	L"Charles the Fat", L"Odo", L"Charles III", L"Robert I", L"Rudolph",
	L"Louis IV", L"Lothair", L"Louis V",

	// House of Capet (987–1328)
	L"Hugh Capet", L"Robert II", L"Henry I", L"Philip I", L"Louis VI",
	L"Louis VII", L"Philip II", L"Louis VIII", L"Louis IX", L"Philip III",
	L"Philip IV", L"Louis X", L"John I", L"Philip V", L"Charles IV",

	// House of Valois (1328–1589)
	L"Philip VI", L"John II", L"Charles V", L"Charles VI", L"Charles VII",
	L"Louis XI", L"Charles VIII", L"Louis XII", L"Francis I", L"Henry II",
	L"Francis II", L"Charles IX", L"Henry III",

	// House of Lancaster (1422–1453)
	L"Henry VI of England",

	// House of Bourbon (1589–1792)
	L"Henry IV", L"Louis XIII", L"Louis XIV", L"Louis XV", L"Louis XVI",
	L"Louis XVII",

	// First Republic (1792–1804)

	// First Empire (1804–1815)
	L"Napoleon I", L"Napoleon II",

	// Bourbon Restoration (1815–1830)
	L"Louis XVIII", L"Charles X", L"Louis XIX", L"Henry V",

	// July Monarchy (1830–1848)
	L"Louis Philippe I",

	// Second Republic (1848–1852)
	L"Jacques-Charles Dupont de l'Eure", L"Louis-Eugène Cavaignac",
	L"Louis-Napoléon Bonaparte",

	// Second Empire (1852–1870)
	L"Napoleon III",

	// Government of National Defense (1870–1871
	L"Louis-Jules Trochu",

	// Third Republic (1871–1940
	L"Adolphe Thiers", L"Patrice de MacMahon", L"Jules Grévy",
	L"Sadi Carnot", L"Jean Casimir-Perier", L"Félix Faure",
	L"Émile Loubet", L"Armand Fallières", L"Raymond Poincaré",
	L"Paul Deschanel", L"Alexandre Millerand", L"Gaston Doumergue",
	L"Paul Doumer", L"Albert Lebrun",

	// Vichy France (1940–1944)
	L"Philippe Pétain",

	// Provisional Government (1944–1947)
	L"Charles de Gaulle", L"Félix Gouin", L"Georges Bidault",
	L"Vincent Auriol", L"Léon Blum",

	// Fourth Republic (1947–1958)
	L"Vincent Auriol", L"René Coty",

	// Fifth Republic (1958–present)
	L"Charles de Gaulle", L"Alain Poher", L"Georges Pompidou",
	L"Alain Poher", L"Valéry Giscard d'Estaing", L"François Mitterrand",
	L"Jacques Chirac", L"Nicolas Sarkozy", L"François Hollande",
	L"Emmanuel Macron",

	// Japanese Emporers
	L"Jimmu", L"Suizei", L"Annei", L"Itoku", L"Kōshō", L"Kōan", L"Kōrei", L"Kōgen", L"Kaika", L"Sujin", L"Suinin", L"Keikō", L"Seimu", L"Chūai", L"Jingū", L"Ōjin", L"Nintoku", L"Richū", L"Hanzei", L"Ingyō", L"Ankō",	L"Yūryaku", L"Seinei", L"Kenzō", L"Ninken", L"Buretsu", L"Keitai", L"Ankan", L"Senka", L"Kinmei", L"Bidatsu", L"Yōmei", L"Sushun", L"Suiko", L"Jomei", L"Kōgyoku", L"Kōtoku", L"Saimei", L"Tenji", L"Kōbun", L"Tenmu", L"Jitō", L"Monmu", L"Genmei", L"Genshō", L"Shōmu", L"Kōken", L"Junnin", L"Shōtoku", L"Kōnin", L"Kanmu", L"Heizei", L"Saga", L"Junna", L"Ninmyō", L"Montoku", L"Seiwa", L"Yōzei", L"Kōkō", L"Uda", L"Daigo", L"Suzaku", L"Murakami", L"Reizei", L"En'yū", L"Kazan",	L"Ichijō", L"Sanjō", L"Go-Ichijō", L"Go-Suzaku", L"Go-Reizei", L"Go-Sanjō", L"Shirakawa", L"Horikawa", L"Toba", L"Sutoku", L"Konoe", L"Go-Shirakawa", L"Nijō", L"Rokujō", L"Takakura", L"Antoku",	L"Go-Toba", L"Tsuchimikado", L"Juntoku", L"Chūkyō", L"Go-Horikawa",	L"Shijō", L"Go-Saga", L"Go-Fukakusa", L"Kameyama", L"Go-Uda",	L"Fushimi", L"Go-Fushimi", L"Go-Nijō", L"Hanazono", L"Go-Daigo", L"Kōgon", L"Kōmyō", L"Sukō", L"Go-Kōgon", L"Go-En'yū", L"Go-Komatsu", L"Go-Murakami", L"Chōkei", L"Go-Kameyama", L"Go-Komatsu", L"Shōkō",	L"Go-Hanazono", L"Go-Tsuchimikado", L"Go-Kashiwabara", L"Go-Nara", L"Ōgimachi", L"Go-Yōzei", L"Go-Mizunoo", L"Meishō", L"Go-Kōmyō",	L"Go-Sai", L"Reigen", L"Higashiyama", L"Nakamikado", L"Sakuramachi", L"Momozono", L"Go-Sakuramachi", L"Go-Momozono", L"Kōkaku", L"Ninkō", L"Kōmei", L"Meiji", L"Taishō", L"Shōwa", L"Akihito", L"Naruhito"

	// cool names
	L"Bonesteel Flexhammer", L"Grim Deathson", L"Tom Spiderman", L"Grimgrace Shimshade", L"Flim-flam", L"Michael Bonesteel"


};

wstring names::barbarian[6] = { L"Conan", L"Erlich", L"Krudr", L"Gimleim", L"Kull", L"Sonya" };
wstring names::bard[6] = { L"Florian", L"Wolfgang", L"Carl", L"Elton", L"Gerald", L"Lenny" };
wstring names::cleric[5] = { L"Joan", L"Nelly", L"Maria", L"Pious", L"Simon" };
wstring names::demon_hunter[5] = { L"Blair", L"Bloodling", L"Damien", L"Jason", L"Michael" };
wstring names::druid[4] = { L"Crow Bear", L"Crazy Horse", L"Flying Snake", L"Wolf Spider" };
wstring names::knight[12] = { L"Alexander", L"Alfred", L"Arthur", L"Brianne", L"Charles", L"Cid", L"Edward", L"Henry", L"Heinrich", L"Richard", L"Seigfried", L"William" };
wstring names::paladin[3] = { L"Alfonse", L"Marcus", L"Sanford" };
wstring names::pugilist[3] = { L"Bonesaw", L"Hunter", L"Nikita" };
wstring names::pyromancer[5] = { L"Rose", L"Lorelei", L"Veronica", L"Nadia", L"Jack" };
wstring names::samurai[4] = { L"Mushashi", L"Miyamoto", L"Jubei", L"Saotome" };
wstring names::sniper[2] = { L"Apollo", L"Artemis" };
wstring names::sorcerer[4] = { L"Elektra", L"Esther", L"Helena", L"Nightshade" };
wstring names::thief[6] = { L"Martin", L"Jimmy", L"Katsumi", L"Hayato", L"Beau", L"Justin" };
wstring names::princess[12] = { L"Ariel", L"Augusta", L"Aurora", L"Euna", L"Eilonwy", L"Harmony", L"Irene", L"Maya", L"Melody", L"Priscilla", L"Rhythm", L"Sonya" };
wstring names::fool[4] = { L"Charlie", L"Homer", L"Lemmy", L"Zippo" };


wstring names::towns[2363] = {

	// Planet Earth
	// North America
	// USA
	L"New York City", L"Los Angeles", L"Chicago", L"Houston", L"Phoenix",
	L"Philadelphia", L"San Antonio", L"San Diego", L"Dallas", L"San Jose",
	L"Austin", L"Jacksonville", L"Fort Worth", L"Columbus",
	L"San Francisco", L"Charlotte", L"Indianapolis", L"Seattle", L"Denver",
	L"Washington, D.C.", L"Boston", L"El Paso", L"Detroit", L"Nashville",
	L"Portland", L"Memphis", L"Oklahoma City", L"Las Vegas", L"Louisville",
	L"Baltimore", L"Milwaukee", L"Albuquerque", L"Tucson", L"Fresno",
	L"Mesa", L"Sacramento", L"Atlanta", L"Kansas City",
	L"Colorado Springs", L"Miami", L"Raleigh", L"Omaha", L"Long Beach",
	L"Virginia Beach", L"Oakland", L"Minneapolis", L"Tulsa", L"Arlington",
	L"Tampa", L"New Orleans", L"Wichita", L"Cleveland", L"Bakersfield",
	L"Aurora", L"Anaheim", L"Honolulu", L"Santa Ana", L"Riverside",
	L"Corpus Christi", L"Lexington", L"Stockton", L"Henderson",
	L"Saint Paul", L"St. Louis", L"Cincinnati", L"Pittsburgh",
	L"Greensboro", L"Anchorage", L"Plano", L"Lincoln", L"Orlando",
	L"Irvine", L"Newark", L"Toledo", L"Durham", L"Chula Vista",
	L"Fort Wayne", L"Jersey City", L"St. Petersburg", L"Laredo",
	L"Madison", L"Chandler", L"Buffalo", L"Lubbock", L"Scottsdale", L"Reno",
	L"Glendale", L"Gilbert", L"Winston–Salem", L"North Las Vegas",
	L"Norfolk", L"Chesapeake", L"Garland", L"Irving", L"Hialeah",
	L"Fremont", L"Boise", L"Richmond", L"Baton Rouge", L"Spokane",
	L"Des Moines", L"Tacoma", L"San Bernardino", L"Modesto", L"Fontana",
	L"Santa Clarita", L"Birmingham", L"Oxnard", L"Fayetteville",
	L"Moreno Valley", L"Rochester", L"Glendale", L"Huntington Beach",
	L"Salt Lake City", L"Grand Rapids", L"Amarillo", L"Yonkers", L"Aurora",
	L"Montgomery", L"Akron", L"Little Rock", L"Huntsville", L"Augusta",
	L"Port St. Lucie", L"Grand Prairie", L"Columbus", L"Tallahassee",
	L"Overland Park", L"Tempe", L"McKinney", L"Mobile", L"Cape Coral",
	L"Shreveport", L"Frisco", L"Knoxville", L"Worcester", L"Brownsville",
	L"Vancouver", L"Fort Lauderdale", L"Sioux Falls", L"Ontario",
	L"Chattanooga", L"Providence", L"Newport News", L"Rancho Cucamonga",
	L"Santa Rosa", L"Oceanside", L"Salem", L"Elk Grove", L"Garden Grove",
	L"Pembroke Pines", L"Peoria", L"Eugene", L"Corona", L"Cary",
	L"Springfield", L"Fort Collins", L"Jackson", L"Alexandria", L"Hayward",
	L"Lancaster", L"Lakewood", L"Clarksville", L"Palmdale", L"Salinas",
	L"Springfield", L"Hollywood", L"Pasadena", L"Sunnyvale", L"Macon",
	L"Kansas City", L"Pomona", L"Escondido", L"Killeen", L"Naperville",
	L"Joliet", L"Bellevue", L"Rockford", L"Savannah", L"Paterson",
	L"Torrance", L"Bridgeport", L"McAllen", L"Mesquite", L"Syracuse",
	L"Midland", L"Pasadena", L"Murfreesboro", L"Miramar", L"Dayton",
	L"Fullerton", L"Olathe", L"Orange", L"Thornton", L"Roseville",
	L"Denton", L"Waco", L"Surprise", L"Carrollton", L"West Valley City",
	L"Charleston", L"Warren", L"Hampton", L"Gainesville", L"Visalia",
	L"Coral Springs", L"Columbia", L"Cedar Rapids", L"Sterling Heights",
	L"New Haven", L"Stamford", L"Concord", L"Kent", L"Santa Clara",
	L"Elizabeth", L"Round Rock", L"Thousand Oaks", L"Lafayette", L"Athens",
	L"Topeka", L"Simi Valley", L"Fargo", L"Norman", L"Columbia",
	L"Abilene", L"Wilmington", L"Hartford", L"Victorville", L"Pearland",
	L"Vallejo", L"Ann Arbor", L"Berkeley", L"Allentown", L"Richardson",
	L"Odessa", L"Arvada", L"Cambridge", L"Sugar Land", L"Beaumont",
	L"Lansing", L"Evansville", L"Rochester", L"Independence", L"Fairfield",
	L"Provo", L"Clearwater", L"College Station", L"West Jordan",
	L"Carlsbad", L"El Monte", L"Murrieta", L"Temecula", L"Springfield",
	L"Palm Bay", L"Costa Mesa", L"Westminster", L"North Charleston",
	L"Miami Gardens", L"Manchester", L"High Point", L"Downey", L"Clovis",
	L"Pompano Beach", L"Pueblo", L"Elgin", L"Lowell", L"Antioch",
	L"West Palm Beach", L"Peoria", L"Everett", L"Ventura", L"Centennial",
	L"Lakeland", L"Gresham", L"Richmond", L"Billings", L"Inglewood",
	L"Broken Arrow", L"Sandy Springs", L"Jurupa Valley", L"Hillsboro",
	L"Waterbury", L"Santa Maria", L"Boulder", L"Greeley", L"Daly City",
	L"Meridian", L"Lewisville", L"Davie", L"West Covina", L"League City",
	L"Tyler", L"Norwalk", L"San Mateo", L"Green Bay", L"Wichita Falls",
	L"Sparks", L"Lakewood", L"Burbank", L"Rialto", L"Allen", L"El Cajon",
	L"Las Cruces", L"Renton", L"Davenport", L"South Bend", L"Vista",
	L"Tuscaloosa", L"Clinton", L"Edison", L"Woodbridge", L"San Angelo",
	L"Kenosha", L"Vacaville",

	// South America
	// Argentina
	L"Buenos Aires", L"Córdoba", L"Rosario", L"Mendoza", L"La Plata", L"Tucumán", L"Mar del Plata", L"Salta", L"Santa Fe", L"San Juan", L"Resistencia", L"Santiago del Estero", L"Corrientes", L"Neuquén", L"Posadas", L"San Salvador de Jujuy", L"Bahía Blanca", L"Paraná", L"Formosa", L"San Fernando del Valle de Catamarca", L"San Luis", L"La Rioja", L"Comodoro Rivadavia", L"Río Cuarto",
	// Bolivia
	L"Santa Cruz de la Sierra", L"El Alto", L"La Paz", L"Cochabamba", L"Oruro", L"Sucre", L"Tarija", L"Potosí", L"Sacaba", L"Quillacollo", L"Montero", L"Trinidad", L"Riberalta", L"Warnes", L"La Guardia", L"Viacha", L"Yacuíba", L"Colcapirhua", L"Tiquipaya", L"Cobija", L"Vinto", L"Guayaramerín", L"Villazón", L"Yapacaní", L"Villamontes", L"Bermejo", L"Camiri", L"Tupiza", L"Llallagua", L"San Ignacio de Velasco", L"San Julián", L"Huanuni", L"Punata", L"Cotoca", L"Ascención de Guarayos", L"Achocalla", L"Mineros", L"Uyuni", L"San Borja", L"El Torno", L"Puerto Suárez", L"Portachuelo", L"Caranavi", L"Rurrenabaque", L"Challapata", L"Santa Ana del Yacuma", L"San José de Chiquitos", L"Sipe Sipe", L"Patacamaya", L"Puerto Quijarro", L"Vallegrande", L"Roboré", L"San Ignacio de Moxos",
	// Brazil
	L"São Paulo", L"Rio de Janeiro", L"Brasília", L"Salvador", L"Fortaleza", L"Belo Horizonte", L"Manaus", L"Curitiba", L"Recife", L"Goiânia", L"Belém", L"Porto Alegre", L"Campinas", L"Guarulhos", L"São Luís", L"São Gonçalo", L"Maceió", L"Duque de Caxias", L"Campo Grande", L"Natal", L"Teresina", L"São Bernardo do Campo", L"Nova Iguaçu", L"João Pessoa", L"Santo André", L"São José dos Campos", L"Jaboatão dos Guararapes", L"Osasco", L"Ribeirão Preto", L"Uberlândia", L"Sorocaba", L"Contagem", L"Aracaju", L"Feira de Santana", L"Cuiabá", L"Joinville", L"Aparecida de Goiânia", L"Juiz de Fora", L"Londrina", L"Ananindeua", L"Porto Velho", L"Niterói", L"Belford Roxo", L"Serra", L"Caxias do Sul", L"Campos dos Goytacazes", L"Macapá", L"Florianópolis", L"Vila Velha", L"São João de Meriti", L"Mauá", L"São José do Rio Preto", L"Mogi das Cruzes", L"Santos", L"Betim", L"Diadema", L"Maringá", L"Jundiaí", L"Campina Grande", L"Montes Claros", L"Rio Branco", L"Piracicaba", L"Carapicuíba", L"Olinda", L"Anápolis", L"Cariacica", L"Boa Vista", L"Bauru", L"Itaquaquecetuba", L"Caucaia", L"São Vicente", L"Vitória", L"Caruaru", L"Blumenau", L"Franca", L"Ponta Grossa", L"Canoas", L"Petrolina", L"Pelotas", L"Vitória da Conquista", L"Ribeirão das Neves", L"Uberaba", L"Paulista", L"Cascavel", L"Praia Grande", L"Guarujá", L"São José dos Pinhais", L"Taubaté", L"Petrópolis", L"Limeira", L"Santarém", L"Suzano", L"Mossoró", L"Camaçari", L"Palmas", L"Taboão da Serra", L"Várzea Grande", L"Santa Maria", L"Gravataí", L"Governador Valadares", L"Sumaré", L"Marabá", L"Volta Redonda", L"Juazeiro do Norte", L"Barueri", L"Embu das Artes", L"Ipatinga", L"Foz do Iguaçu", L"Imperatriz", L"Parnamirim", L"Viamão", L"Macaé", L"São Carlos", L"Indaiatuba", L"Novo Hamburgo", L"Cotia", L"Magé", L"São José", L"Colombo", L"Itaboraí", L"Sete Lagoas", L"Marília", L"Americana", L"Divinópolis", L"São Leopoldo", L"Itapevi", L"Araraquara", L"Jacareí", L"Arapiraca", L"Rio Verde", L"Rondonópolis", L"Hortolândia", L"Presidente Prudente", L"Maracanaú", L"Cabo Frio", L"Dourados", L"Santa Luzia", L"Chapecó", L"Itajaí", L"Juazeiro", L"Criciúma", L"Itabuna", L"Rio Grande", L"Alvorada", L"Cachoeiro de Itapemirim", L"Águas Lindas de Goiás", L"Sobral", L"Cabo de Santo Agostinho", L"Luziânia", L"Rio Claro", L"Parauapebas", L"Passo Fundo", L"Angra dos Reis", L"Castanhal", L"Araçatuba", L"Lauro de Freitas", L"Santa Bárbara d'Oeste", L"Ferraz de Vasconcelos", L"Nova Friburgo", L"Barra Mansa", L"Nossa Senhora do Socorro", L"Teresópolis", L"Guarapuava", L"Ibirité", L"Araguaína", L"São José de Ribamar", L"Mesquita", L"Jaraguá do Sul", L"Francisco Morato", L"Itapecerica da Serra", L"Itu", L"Linhares", L"Palhoça", L"Timon", L"Bragança Paulista", L"Pindamonhangaba", L"Poços de Caldas", L"Ilhéus", L"Valparaíso de Goiás", L"Caxias", L"Nilópolis", L"Itapetininga", L"São Caetano do Sul", L"Teixeira de Freitas", L"Maricá", L"Lages", L"Camaragibe", L"Abaetetuba", L"Jequié", L"Barreiras", L"Paranaguá", L"Parnaíba", L"Franco da Rocha", L"Patos de Minas", L"Alagoinhas", L"Mogi Guaçu", L"Queimados", L"Pouso Alegre", L"Jaú", L"Porto Seguro", L"Rio das Ostras", L"Botucatu", L"Araucária", L"Atibaia", L"Sapucaia do Sul", L"Teófilo Otoni", L"Sinop", L"Garanhuns", L"Balneário Camboriú", L"Toledo", L"Vitória de Santo Antão", L"Santana de Parnaíba", L"Barbacena", L"Cametá", L"Santa Rita", L"Sabará", L"Varginha", L"Apucarana", L"Araras", L"Simões Filho", L"Brusque", L"Crato", L"Pinhais", L"Araruama", L"Resende", L"Campo Largo", L"Cubatão", L"Santa Cruz do Sul", L"Marituba", L"Cachoeirinha", L"São Mateus", L"Itapipoca", L"Ji-Paraná", L"Conselheiro Lafaiete", L"Valinhos", L"Maranguape", L"Uruguaiana", L"Bragança", L"Itaguaí", L"Vespasiano", L"Trindade", L"São Félix do Xingu", L"Sertãozinho", L"Jandira", L"Guarapari", L"Ribeirão Pires", L"Codó", L"Birigui", L"Barcarena", L"Colatina", L"Barretos", L"Votorantim", L"Catanduva", L"Arapongas", L"Guaratinguetá", L"Bagé", L"Paço do Lumiar", L"Várzea Paulista", L"Tatuí", L"Caraguatatuba", L"Santana", L"Formosa", L"Três Lagoas", L"Itabira", L"Itatiba", L"Bento Gonçalves", L"Salto", L"Almirante Tamandaré", L"Paulo Afonso", L"Araguari", L"Poá", L"Igarassu", L"Ubá", L"Passos", L"Novo Gama", L"Altamira", L"Parintins", L"Ourinhos", L"São Lourenço da Mata", L"Eunápolis", L"Senador Canedo", L"Tucuruí", L"Paragominas", L"Açailândia", L"Piraquara", L"Corumbá", L"Umuarama", L"Coronel Fabriciano", L"Muriaé", L"Patos", L"Paulínia", L"Catalão", L"Ariquemes", L"Santa Cruz do Capibaribe", L"Cambé", L"Araxá", L"Erechim", L"Tubarão", L"Bacabal", L"Ituiutaba", L"Japeri", L"Assis", L"Tailândia", L"Itumbiara", L"Lagarto", L"Iguatu", L"São Pedro da Aldeia", L"Lavras", L"Itaperuna", L"Leme", L"Breves", L"Tangará da Serra", L"São Gonçalo do Amarante", L"Itaituba", L"Santo Antônio de Jesus", L"Itanhaém", L"Caieiras",
	// Chile
	L"Arica", L"Iquique", L"Alto Hospicio", L"Pozo Almonte", L"Antofagasta", L"Calama", L"Tocopilla", L"Chuquicamata", L"Taltal", L"Estación Zaldívar", L"Mejillones", L"María Elena", L"Copiapó", L"Vallenar", L"Caldera", L"Chañaral", L"El Salvador", L"Tierra Amarilla", L"Diego de Almagro", L"Huasco", L"Coquimbo", L"La Serena", L"Ovalle", L"Illapel", L"Vicuña", L"Salamanca", L"Los Vilos", L"Andacollo", L"Combarbalá", L"El Palqui", L"Monte Patria", L"Viña del Mar", L"Valparaíso", L"Quilpué", L"Villa Alemana", L"San Antonio", L"Quillota", L"Los Andes", L"San Felipe", L"La Calera", L"Limache", L"Concón", L"Quintero", L"La Ligua", L"Llay-Llay", L"Cartagena", L"Casablanca", L"Cabildo", L"Placilla de Peñuelas", L"La Cruz", L"Olmué", L"El Melón", L"Nogales", L"El Quisco", L"Hijuelas", L"San Esteban", L"Putaendo", L"Catemu", L"Santa María", L"Las Ventanas", L"Algarrobo", L"Rinconada", L"Calle Larga", L"Santo Domingo", L"El Tabo", L"Puente Alto", L"Maipú", L"La Florida", L"Las Condes", L"San Bernardo", L"Peñalolén", L"Santiago", L"Pudahuel", L"La Pintana", L"El Bosque", L"Ñuñoa", L"Cerro Navia", L"Recoleta", L"Renca", L"Conchalí", L"La Granja", L"Estación Central", L"Quilicura", L"Providencia", L"Pedro Aguirre Cerda", L"Lo Espejo", L"Macul", L"Lo Prado", L"Quinta Normal", L"San Joaquín", L"La Reina", L"San Ramón", L"La Cisterna", L"Vitacura", L"San Miguel", L"Huechuraba", L"Lo Barnechea", L"Cerrillos", L"Independencia", L"Peñaflor", L"Colina", L"Melipilla", L"Talagante", L"Buin", L"Padre Hurtado", L"El Monte", L"Paine", L"Curacaví", L"Lampa", L"Isla de Maipo", L"La Islita", L"Bajos de San Agustín", L"Hospital", L"Alto Jahuel", L"San José de Maipo", L"Tiltil", L"Pirque", L"Rancagua", L"San Fernando", L"Rengo", L"Machalí", L"Graneros", L"San Vicente de Tagua Tagua", L"Santa Cruz", L"Chimbarongo", L"Mostazal", L"Pichilemu", L"Requínoa", L"Lo Miranda", L"Doñihue", L"Peumo", L"Nancagua", L"Las Cabras", L"Quinta de Tilcoco", L"Gultro", L"Codegua", L"Palmilla", L"Talca", L"Curicó", L"Linares", L"Constitución", L"Cauquenes", L"Molina", L"Parral", L"San Javier", L"San Clemente", L"Teno", L"Longaví", L"Villa Alegre", L"Hualañé", L"Concepción", L"Talcahuano", L"Chillán", L"Los Ángeles", L"Coronel", L"Hualpén", L"Chiguayante", L"San Pedro de la Paz", L"Lota", L"Penco", L"Tomé", L"Curanilahue", L"San Carlos", L"Mulchén", L"Nacimiento", L"Lebu", L"Cañete", L"Chillán Viejo", L"Arauco", L"La Laja", L"Hualqui", L"Los Álamos", L"Cabrero", L"Bulnes", L"Coelemu", L"Yungay", L"Yumbel", L"Quirihue", L"Quillón", L"Coihueco", L"Santa Juana", L"Santa Bárbara", L"Huépil", L"Monte Águila", L"San Rosendo", L"Temuco", L"Angol", L"Padre Las Casas", L"Villarrica", L"Victoria", L"Lautaro", L"Nueva Imperial", L"Collipulli", L"Loncoche", L"Traiguén", L"Pucón", L"Pitrufquén", L"Curacautín", L"Carahue", L"Gorbea", L"Purén", L"Cunco", L"Labranza", L"Freire", L"Renaico", L"Valdivia", L"La Unión", L"Río Bueno", L"Panguipulli", L"Paillaco", L"Los Lagos", L"Lanco", L"Mariquina", L"Futrono", L"Puerto Montt", L"Osorno", L"Castro", L"Ancud", L"Puerto Varas", L"Quellón", L"Calbuco", L"Purranque", L"Llanquihue", L"Frutillar", L"Río Negro", L"Fresia", L"Los Muermos", L"Coyhaique", L"Puerto Aysén", L"Punta Arenas", L"Puerto Natales",
	// Columbia
	L"Bogotá", L"Leticia", L"El Encanto", L"La Chorrera", L"La Pedrera", L"La Victoria", L"Mirití-Paraná", L"Puerto Alegría", L"Puerto Arica", L"Puerto Nariño", L"Puerto Santander", L"Tarapacá", L"Medellín", L"Abejorral", L"Abriaquí", L"Alejandría", L"Amagá", L"Amalfi", L"Andes", L"Angelópolis", L"Angostura", L"Anorí", L"Anza", L"Apartadó", L"Arboletes", L"Argelia", L"Armenia", L"Barbosa", L"Bello", L"Belmira", L"Betania", L"Betulia", L"Briceño", L"Buriticá", L"Cáceres", L"Caicedo", L"Caldas", L"Campamento", L"Cañasgordas", L"Caracolí", L"Caramanta", L"Carepa", L"Carolina", L"Caucasia", L"Chigorodó", L"Cisneros", L"Ciudad Bolívar", L"Cocorná", L"Concepción", L"Concordia", L"Copacabana", L"Dabeiba", L"Don Matías", L"Ebéjico", L"El Bagre", L"El Carmen de Viboral", L"El Santuario", L"Entrerrios", L"Envigado", L"Fredonia", L"Frontino", L"Giraldo", L"Girardota", L"Gómez Plata", L"Granada", L"Guadalupe", L"Guarne", L"Guatapé", L"Heliconia", L"Hispania", L"Itagüí", L"Ituango", L"Jardín", L"Jericó", L"La Ceja", L"La Estrella", L"La Pintada", L"La Unión", L"Liborina", L"Maceo", L"Marinilla", L"Montebello", L"Murindó", L"Mutatá", L"Nariño", L"Nechí", L"Necoclí", L"Olaya", L"Peñol", L"Peque", L"Pueblorrico", L"Puerto Berrío", L"Puerto Nare", L"Puerto Triunfo", L"Remedios", L"Retiro", L"Rionegro", L"Sabanalarga", L"Sabaneta", L"Salgar", L"San Andrés de Cuerquía", L"San Carlos", L"San Francisco", L"San Jerónimo", L"San José de La Montaña", L"San Juan de Urabá", L"San Luis", L"San Pedro de los Milagros", L"San Pedro de Urabá", L"San Rafael", L"San Roque", L"San Vicente", L"Santa Bárbara", L"Santa Fe de Antioquia", L"Santa Rosa de Osos", L"Santo Domingo", L"Segovia", L"Sonsón", L"Sopetrán", L"Támesis", L"Tarazá", L"Tarso", L"Titiribí", L"Toledo", L"Turbo", L"Uramita", L"Urrao", L"Valdivia", L"Valparaíso", L"Vegachí", L"Venecia", L"Vigía del Fuerte", L"Yalí", L"Yarumal", L"Yolombó", L"Yondó", L"Zaragoza", L"Arauca", L"Arauquita", L"Cravo Norte", L"Fortul", L"Puerto Rondón", L"Saravena", L"Tame", L"Barranquilla", L"Baranoa", L"Campo de La Cruz", L"Candelaria", L"Galapa", L"Juan de Acosta", L"Luruaco", L"Malambo", L"Manatí", L"Palmar de Varela", L"Piojó", L"Polonuevo", L"Ponedera", L"Puerto Colombia", L"Repelón", L"Sabanagrande", L"Sabanalarga", L"Santa Lucía", L"Santo Tomás", L"Soledad", L"Suán", L"Tubará", L"Usiacurí", L"Cartagena", L"Achí", L"Altos del Rosario", L"Arenal del Sur", L"Arjona", L"Arroyohondo", L"Barranco de Loba", L"Calamar", L"Cantagallo", L"Carmen de Bolivar", L"Cicuco", L"Clemencia", L"Córdoba", L"El Guamo", L"El Peñón", L"Hatillo de Loba", L"Magangué", L"Mahates", L"Margarita", L"María La Baja", L"Montecristo", L"Morales", L"Pinillos", L"Regidor", L"Río Viejo", L"San Cristóbal", L"San Estanislao", L"San Fernando", L"San Jacinto del Cauca", L"San Jacinto", L"San Juan Nepomuceno", L"San Martín de Loba", L"San Pablo", L"Santa Catalina", L"Santa Cruz de Mompox", L"Santa Rosa del Sur", L"Santa Rosa", L"Simití", L"Soplaviento", L"Talaigua Nuevo", L"Tiquisio", L"Turbaco", L"Turbaná", L"Villanueva", L"Zambrano", L"Tunja", L"Almeida", L"Aquitania", L"Arcabuco", L"Belén", L"Berbeo", L"Betéitiva", L"Boavita", L"Boyacá", L"Briceño", L"Buenavista", L"Busbanzá", L"Caldas", L"Campohermoso", L"Cerinza", L"Chinavita", L"Chiquinquirá", L"Chíquiza", L"Chiscas", L"Chita", L"Chitaraque", L"Chivatá", L"Chivor", L"Ciénega", L"Cómbita", L"Coper", L"Corrales", L"Covarachía", L"Cubará", L"Cucaita", L"Cuítiva", L"Duitama", L"El Cocuy", L"El Espino", L"Firavitoba", L"Floresta", L"Gachantivá", L"Gámeza", L"Garagoa", L"Guacamayas", L"Guateque", L"Guayatá", L"Güicán", L"Iza", L"Jenesano", L"Jericó", L"La Capilla", L"La Uvita", L"La Victoria", L"Labranzagrande", L"Macanal", L"Maripí", L"Miraflores", L"Mongua", L"Monguí", L"Moniquirá", L"Motavita", L"Muzo", L"Nobsa", L"Nuevo Colón", L"Oicatá", L"Otanche", L"Pachavita", L"Páez", L"Paipa", L"Pajarito", L"Panqueba", L"Pauna", L"Paya", L"Paz de Río", L"Pesca", L"Pisba", L"Puerto Boyacá", L"Quípama", L"Ramiriquí", L"Ráquira", L"Rondón", L"Saboyá", L"Sáchica", L"Samacá", L"San Eduardo", L"San José de Pare", L"San Luis de Gaceno", L"San Mateo", L"San Miguel de Sema", L"San Pablo de Borbur", L"Santa María", L"Santa Rosa de Viterbo", L"Santa Sofía", L"Santana", L"Sativanorte", L"Sativasur", L"Siachoque", L"Soatá", L"Socha", L"Socotá", L"Sogamoso", L"Somondoco", L"Sora", L"Soracá", L"Sotaquirá", L"Susacón", L"Sutamarchán", L"Sutatenza", L"Tasco", L"Tenza", L"Tibaná", L"Tibasosa", L"Tinjacá", L"Tipacoque", L"Toca", L"Togüí", L"Tópaga", L"Tota", L"Tununguá", L"Turmequé", L"Tuta", L"Tutazá", L"Umbita", L"Ventaquemada", L"Villa de Leyva", L"Viracachá", L"Zetaquira", L"Manizales", L"Aguadas", L"Anserma", L"Aranzazu", L"Belalcázar", L"Chinchiná", L"Filadelfia", L"La Dorada", L"La Merced", L"Manzanares", L"Marmato", L"Marquetalia", L"Marulanda", L"Neira", L"Norcasia", L"Pácora", L"Palestina", L"Pensilvania", L"Riosucio", L"Risaralda", L"Salamina", L"Samaná", L"San José", L"Supía", L"Victoria", L"Villamaría", L"Viterbo", L"Florencia", L"Albania", L"Belén de Los Andaquies", L"Cartagena del Chairá", L"Curillo", L"El Doncello", L"El Paujil", L"La Montañita", L"Milán", L"Morelia", L"Puerto Rico", L"San José del Fragua", L"San Vicente del Caguán", L"Solano", L"Solita", L"Valparaíso", L"Yopal", L"Aguazul", L"Chameza", L"Hato Corozal", L"La Salina", L"Maní", L"Monterrey", L"Nunchía", L"Orocué", L"Paz de Ariporo", L"Pore", L"Recetor", L"Sabanalarga", L"Sácama", L"San Luis de Palenque", L"Támara", L"Tauramena", L"Trinidad", L"Villanueva", L"Popayán", L"Almaguer", L"Argelia", L"Balboa", L"Bolívar", L"Buenos Aires", L"Cajibio", L"Caldono", L"Caloto", L"Corinto", L"El Tambo", L"Florencia", L"Guapi", L"Inzá", L"Jambaló", L"La Sierra", L"La Vega", L"López", L"Mercaderes", L"Miranda", L"Morales", L"Padilla", L"Páez", L"Patía", L"Piamonte", L"Piendamó", L"Puerto Tejada", L"Puracé", L"Rosas", L"San Sebastián", L"Santa Rosa", L"Santander de Quilichao", L"Silvia", L"Sotara", L"Suárez", L"Sucre", L"Timbío", L"Timbiquí", L"Toribio", L"Totoró", L"Villa Rica", L"Valledupar", L"Aguachica", L"Agustín Codazzi", L"Astrea", L"Becerril", L"Bosconia", L"Chimichagua", L"Chiriguaná", L"Curumaní", L"El Copey", L"El Paso", L"Gamarra", L"González", L"La Gloria", L"La Jagua de Ibirico", L"La Paz", L"Manaure", L"Pailitas", L"Pelaya", L"Pueblo Bello", L"Río de Oro", L"San Alberto", L"San Diego", L"San Martín", L"Tamalameque", L"Quibdó", L"Acandí", L"Alto Baudó", L"Atrato", L"Bagadó", L"Bahía Solano", L"Bajo Baudó", L"Belén de Bajirá", L"Bojaya", L"Carmen del Atrato", L"Carmen del Darien", L"Cértegui", L"Condoto", L"El Cantón del San Pablo", L"Istmina", L"Juradó", L"Litoral de San Juan", L"Lloró", L"Medio Atrato", L"Medio Baudó", L"Medio San Juan", L"Nóvita", L"Nuquí", L"Río Iro", L"Río Quito", L"Riosucio", L"San José del Palmar", L"Sipí", L"Tadó", L"Unguía", L"Unión Panamericana", L"Montería", L"Ayapel", L"Buenavista", L"Canalete", L"Cereté", L"Chimá", L"Chinú", L"Ciénaga de Oro", L"Cotorra", L"La Apartada", L"Los Córdobas", L"Momil", L"Moñitos", L"Montelíbano", L"Planeta Rica", L"Pueblo Nuevo", L"Puerto Escondido", L"Puerto Libertador", L"Purísima", L"Sahagún", L"San Andrés de Sotavento", L"San Antero", L"San Bernardo del Viento", L"San Carlos", L"San Pelayo", L"Santa Cruz de Lorica", L"Tierralta", L"Valencia", L"Agua de Dios", L"Albán", L"Anapoima", L"Anolaima", L"Apulo", L"Arbeláez", L"Beltrán", L"Bituima", L"Bojacá", L"Cabrera", L"Cachipay", L"Cajicá", L"Caparrapí", L"Caqueza", L"Carmen de Carupa", L"Chaguaní", L"Chía", L"Chipaque", L"Choachí", L"Chocontá", L"Cogua", L"Cota", L"Cucunubá", L"El Colegio", L"El Peñón", L"El Rosal", L"Facatativá", L"Fómeque", L"Fosca", L"Funza", L"Fúquene", L"Fusagasugá", L"Gachalá", L"Gachancipá", L"Gachetá", L"Gama", L"Girardot", L"Granada", L"Guachetá", L"Guaduas", L"Guasca", L"Guataquí", L"Guatavita", L"Guayabal de Siquima", L"Guayabetal", L"Gutiérrez", L"Jerusalén", L"Junín", L"La Calera", L"La Mesa", L"La Palma", L"La Peña", L"La Vega", L"Lenguazaque", L"Macheta", L"Madrid", L"Manta", L"Medina", L"Mosquera", L"Nariño", L"Nemocón", L"Nilo", L"Nimaima", L"Nocaima", L"Pacho", L"Paime", L"Pandi", L"Paratebueno", L"Pasca", L"Puerto Salgar", L"Pulí", L"Quebradanegra", L"Quetame", L"Quipile", L"Ricaurte", L"San Antonio del Tequendama", L"San Bernardo", L"San Cayetano", L"San Francisco", L"San Juan de Río Seco", L"Sasaima", L"Sesquilé", L"Sibaté", L"Silvania", L"Simijaca", L"Soacha", L"Sopó", L"Subachoque", L"Suesca", L"Supatá", L"Susa", L"Sutatausa", L"Tabio", L"Tausa", L"Tena", L"Tenjo", L"Tibacuy", L"Tibirita", L"Tocaima", L"Tocancipá", L"Topaipí", L"Ubalá", L"Ubaque", L"Ubaté", L"Une", L"Útica", L"Venecia", L"Vergara", L"Vianí", L"Villagómez", L"Villapinzón", L"Villeta", L"Viotá", L"Yacopí", L"Zipacón", L"Zipaquirá", L"Inírida", L"Barranco Minas", L"Cacahual", L"La Guadalupe", L"Mapiripana", L"Morichal Nuevo", L"Pana Pana", L"Puerto Colombia", L"San Felipe", L"San José del Guaviare", L"Calamar", L"El Retorno", L"Miraflores", L"Neiva", L"Acevedo", L"Agrado", L"Aipe", L"Algeciras", L"Altamira", L"Baraya", L"Campoalegre", L"Colombia", L"El Pital", L"Elías", L"Garzón", L"Gigante", L"Guadalupe", L"Hobo", L"Iquira", L"Isnos", L"La Argentina", L"La Plata", L"Nátaga", L"Oporapa", L"Paicol", L"Palermo", L"Palestina", L"Pitalito", L"Rivera", L"Saladoblanco", L"San Agustín", L"Santa María", L"Suaza", L"Tarqui", L"Tello", L"Teruel", L"Tesalia", L"Timaná", L"Villavieja", L"Yaguará", L"Riohacha", L"Albania", L"Barrancas", L"Dibulla", L"Distracción", L"El Molino", L"Fonseca", L"Hatonuevo", L"La Jagua del Pilar", L"Maicao", L"Manaure", L"San Juan del Cesar", L"Uribia", L"Urumita", L"Villanueva", L"Santa Marta", L"Algarrobo", L"Aracataca", L"Ariguaní", L"Cerro San Antonio", L"Chibolo", L"Ciénaga", L"Concordia", L"El Banco", L"El Piñon", L"El Retén", L"Fundación", L"Guamal", L"Nueva Granada", L"Pedraza", L"Pijiño del Carmen", L"Pivijay", L"Plato", L"Puebloviejo", L"Remolino", L"Sabanas de San Angel", L"Salamina", L"San Sebastián de Buenavista", L"San Zenón", L"Santa Ana", L"Santa Bárbara de Pinto", L"Sitionuevo", L"Tenerife", L"Zapayán", L"Zona Bananera", L"Villavicencio", L"Acacías", L"Barranca de Upía", L"Cabuyaro", L"Castilla la Nueva", L"Cubarral", L"Cumaral", L"El Calvario", L"El Castillo", L"El Dorado", L"Fuente de oro", L"Granada", L"Guamal", L"La Macarena", L"Lejanías", L"Mapiripán", L"Mesetas", L"Puerto Concordia", L"Puerto Gaitán", L"Puerto Lleras", L"Puerto López", L"Puerto Rico", L"Restrepo", L"San Carlos de Guaroa", L"San Juan de Arama", L"San Juanito", L"San Martín", L"Uribe", L"Vista Hermosa", L"San Juan de Pasto", L"Albán", L"Aldana", L"Ancuyá", L"Arboleda", L"Barbacoas", L"Belén", L"Buesaco", L"Chachagüí", L"Colón", L"Consaca", L"Contadero", L"Córdoba", L"Cuaspud", L"Cumbal", L"Cumbitara", L"El Charco", L"El Peñol", L"El Rosario", L"El Tablón de Gómez", L"El Tambo", L"Francisco Pizarro", L"Funes", L"Guachucal", L"Guaitarilla", L"Gualmatán", L"Iles", L"Imués", L"Ipiales", L"La Cruz", L"La Florida", L"La Llanada", L"La Tola", L"La Unión", L"Leiva", L"Linares", L"Los Andes", L"Magüi", L"Mallama", L"Mosquera", L"Nariño", L"Olaya Herrera", L"Ospina", L"Policarpa", L"Potosí", L"Providencia", L"Puerres", L"Pupiales", L"Ricaurte", L"Roberto Payán", L"Samaniego", L"San Bernardo", L"San Lorenzo", L"San Pablo", L"San Pedro de Cartago", L"Sandoná", L"Santa Bárbara", L"Santacruz", L"Sapuyes", L"Taminango", L"Tangua", L"Tumaco", L"Túquerres", L"Yacuanquer", L"Cúcuta", L"Abrego", L"Arboledas", L"Bochalema", L"Bucarasica", L"Cachirá", L"Cácota", L"Chinácota", L"Chitagá", L"Convención", L"Cucutilla", L"Duranía", L"El Carmen", L"El Tarra", L"El Zulia", L"Gramalote", L"Hacarí", L"Herrán", L"La Esperanza", L"La Playa", L"Labateca", L"Los Patios", L"Lourdes", L"Mutiscua", L"Ocaña", L"Pamplona", L"Pamplonita", L"Puerto Santander", L"Ragonvalia", L"Salazar", L"San Calixto", L"San Cayetano", L"Santiago", L"Sardinata", L"Silos", L"Teorama", L"Tibú", L"Toledo", L"Villa Caro", L"Villa del Rosario", L"Mocoa", L"Colón", L"Leguízamo", L"Orito", L"Puerto Asís", L"Puerto Caicedo", L"Puerto Guzmán", L"San Francisco", L"San Miguel", L"Santiago", L"Sibundoy", L"Valle del Guamuez", L"Villagarzón", L"Armenia", L"Buenavista", L"Calarcá", L"Circasia", L"Córdoba", L"Filandia", L"Génova", L"La Tebaida", L"Montenegro", L"Pijao", L"Quimbaya", L"Salento", L"Pereira", L"Apía", L"Balboa", L"Belén de Umbría", L"Dosquebradas", L"Guática", L"La Celia", L"La Virginia", L"Marsella", L"Mistrató", L"Pueblo Rico", L"Quinchía", L"Santa Rosa de Cabal", L"Santuario", L"San Andrés", L"Providencia", L"Bucaramanga", L"Aguada", L"Albania", L"Aratoca", L"Barbosa", L"Barichara", L"Barrancabermeja", L"Betulia", L"Bolívar", L"Cabrera", L"California", L"Capitanejo", L"Carcasí", L"Cepitá", L"Cerrito", L"Charalá", L"Charta", L"Chima", L"Chipatá", L"Cimitarra", L"Concepción", L"Confines", L"Contratación", L"Coromoro", L"Curití", L"El Carmen de Chucurí", L"El Guacamayo", L"El Peñón", L"El Playón", L"Encino", L"Enciso", L"Florián", L"Floridablanca", L"Galán", L"Gambita", L"Guaca", L"Guadalupe", L"Guapotá", L"Guavatá", L"Güepsa", L"Hato", L"Jesús María", L"Jordán", L"La Belleza", L"La Paz", L"Landázuri", L"Lebrija", L"Los Santos", L"Macaravita", L"Málaga", L"Matanza", L"Mogotes", L"Molagavita", L"Ocamonte", L"Oiba", L"Onzaga", L"Palmar", L"Palmas del Socorro", L"Páramo", L"Piedecuesta", L"Pinchote", L"Puente Nacional", L"Puerto Parra", L"Puerto Wilches", L"Rionegro", L"Sabana de Torres", L"San Andrés", L"San Benito", L"San Gil", L"San Joaquín", L"San José de Miranda", L"San Juan de Girón", L"San Miguel", L"San Vicente de Chucurí", L"Santa Bárbara", L"Santa Helena del Opón", L"Simacota", L"Socorro", L"Suaita", L"Sucre", L"Suratá", L"Tona", L"Valle de San José", L"Vélez", L"Vetas", L"Villanueva", L"Zapatoca", L"Sincelejo", L"Buenavista", L"Caimito", L"Chalán", L"Coloso", L"Corozal", L"Coveñas", L"El Roble", L"Galeras", L"Guaranda", L"La Unión", L"Los Palmitos", L"Majagual", L"Morroa", L"Ovejas", L"Palmito", L"Sampués", L"San Benito Abad", L"San Juan de Betulia", L"San Marcos", L"San Onofre", L"San Pedro", L"San Luis de Sincé", L"Sucre", L"Tolú Viejo", L"Tolú", L"Ibagué", L"Alpujarra", L"Alvarado", L"Ambalema", L"Anzoátegui", L"Armero", L"Ataco", L"Cajamarca", L"Carmen de Apicalá", L"Casabianca", L"Chaparral", L"Coello", L"Coyaima", L"Cunday", L"Dolores", L"Espinal", L"Falan", L"Flandes", L"Fresno", L"Guamo", L"Herveo", L"Honda", L"Icononzo", L"Lérida", L"Líbano", L"Mariquita", L"Melgar", L"Murillo", L"Natagaima", L"Ortega", L"Palocabildo", L"Piedras", L"Planadas", L"Prado", L"Purificación", L"Rioblanco", L"Roncesvalles", L"Rovira", L"Saldaña", L"San Antonio", L"San Luis", L"Santa Isabel", L"Suárez", L"Valle de San Juan", L"Venadillo", L"Villahermosa", L"Villarrica", L"Cali", L"Alcalá", L"Andalucía", L"Ansermanuevo", L"Argelia", L"Bolívar", L"Buenaventura", L"Bugalagrande", L"Caicedonia", L"Calima", L"Candelaria", L"Cartago", L"Dagua", L"El Águila", L"El Cairo", L"El Cerrito", L"El Dovio", L"Florida", L"Ginebra", L"Guacarí", L"Guadalajara de Buga", L"Jamundí", L"La Cumbre", L"La Unión", L"La Victoria", L"Obando", L"Palmira", L"Pradera", L"Restrepo", L"Riofrío", L"Roldanillo", L"San Pedro", L"Sevilla", L"Toro", L"Trujillo", L"Tuluá", L"Ulloa", L"Versalles", L"Vijes", L"Yotoco", L"Yumbo", L"Zarzal", L"Mitú", L"Caruru", L"Pacoa", L"Papunahua", L"Taraira", L"Yavaraté", L"Puerto Carreño", L"Cumaribo", L"La Primavera", L"Santa Rosalía",
	// Ecuador
	// Guyana
	// Paraguay
	// Peru
	L"Lima", L"Arequipa", L"Trujillo", L"Chiclayo", L"Piura", L"Huancayo", L"Cusco", L"Chimbote", L"Iquitos", L"Tacna", L"Juliaca", L"Ica", L"Cajamarca", L"Pucallpa", L"Sullana", L"Ayacucho", L"Chincha", L"Huánuco", L"Huacho", L"Tarapoto", L"Puno", L"Paita", L"Huaraz", L"Tumbes", L"Pisco", L"Huaral", L"Jaén", L"Moyobamba", L"San Vicente de Cañete", L"Puerto Maldonado", L"Catacaos", L"Moquegua", L"Cerro de Pasco", L"Barranca", L"Yurimaguas", L"Chancay", L"Andahuaylas", L"Ilo", L"Talara", L"Abancay", L"Lambayeque", L"Chulucanas", L"Tingo María", L"Sicuani", L"Mala", L"Huancavelica", L"Ferreñafe", L"Chepén", L"Pacasmayo", L"Tarma", L"Sechura", L"Guadalupe", L"Bagua Grande",
	// Suriname
	L"Acaribo", L"Abenaston", L"Albina", L"Alliance", L"Anapaike", L"Apetina", L"Apoera", L"Aurora", L"Batavia", L"Benzdorp", L"Bitagron", L"Boskamp", L"Botopasi", L"Brokopondo", L"Brownsweg", L"Corneliskondre", L"Cottica", L"Djumu", L"Friendship", L"Goddo", L"Groningen", L"Jenny", L"Kajana", L"Kwakoegron", L"Kwamalasamutu", L"Lelydorp", L"Lebidoti", L"Moengo", L"Nieuw Amsterdam", L"Nieuw Jacobkondre", L"Nieuw Nickerie", L"Onverwacht", L"Paramaribo", L"Paranam", L"Pelelu Tepu", L"Pokigron", L"Pontoetoe", L"Totness", L"Wageningen", L"Wanhatti", L"Washoda", L"Zanderij",
	// Uraguay
	// Venezuela


	// Asia

	// Vietnam
	L"Cần Thơ", L"Đà Nẵng", L"Hải Phòng", L"Hà Nội", L"Hồ Chí Minh City", L"Bà Rịa", L"Bà Rịa", L"Bạc Liêu", L"Bảo Lộc", L"Bắc Giang", L"Bắc Kạn", L"Bắc Ninh", L"Biên Hòa", L"Bến Tre", L"Buôn Ma Thuột", L"Cẩm Phả", L"Cà Mau", L"Cam Ranh", L"Cao Bằng", L"Cao Lãnh", L"Châu Đốc", L"Chí Linh", L"Đà Lạt", L"Điện Biên Phủ", L"Đông Hà", L"Đồng Hới", L"Đồng Xoài", L"Hà Giang", L"Hà Tiên", L"Hà Tĩnh", L"Hạ Long", L"Hải Dương", L"Hòa Bình", L"Hội An", L"Huế", L"Hưng Yên", L"Kon Tum", L"Lai Châu", L"Lạng Sơn", L"Lào Cai", L"Long Khánh", L"Long Xuyên", L"Móng Cái", L"Mỹ Tho", L"Nam Định", L"Ninh Bình", L"Nha Trang", L"Phan Rang–Tháp Chàm", L"Phan Thiết", L"Phủ Lý", L"Phúc Yên", L"Pleiku", L"Quảng Ngãi", L"Quy Nhơn", L"Rạch Giá", L"Sa Đéc", L"Sầm Sơn", L"Sóc Trăng", L"Sơn La", L"Sông Công", L"Tam Điệp", L"Tam Kỳ", L"Tân An", L"Tây Ninh", L"Thái Bình", L"Thái Nguyên", L"Thanh Hóa", L"Thủ Dầu Một", L"Trà Vinh", L"Tuy Hòa", L"Tuyên Quang", L"Uông Bí", L"Vị Thanh", L"Việt Trì", L"Vinh", L"Vĩnh Long", L"Vĩnh Yên", L"Vũng Tàu", L"Yên Bái",

	// Dragon Quest
	L"Tantagel Castle", L"The Town of Brecconary", L"Erdrick's Cave",
	L"The Town of Garinham", L"The Village of Kol", L"Rock Mountain Cave",
	L"Swamp Cave", L"The Town of Rimuldar", L"The Town of Cantlin",
	L"Charlock Castle",

	// Final Fantasy
	L"Cornelia", L"Pravoka", L"Elfheim", L"Mount Duergar",
	L"Melmond", L"Crescent Lake", L"Onrac", L"Lufenia", L"Gaia",

	// Final Fantasy II
	L"Altair", L"Gatrea", L"Paloom", L"Poft", L"Salamand", L"Bafsk",
	L"Fynn", L"Mysidia", L"Tropical Island", L"Machanon",

	// Final Fantasy VII
	L"Sector 7 Slums", L"Wall Market", L"Kalm Town", L"Fort Condor", L"Junon",
	L"Costa del Sol", L"North Corel", L"Gold Saucer", L"Gongaga Village",
	L"Nibelheim", L"Rocket Town", L"Wutai", L"Bone Village", L"Icicle Inn",
	L"Mideel",

	// Final Fantasy VIII
	L"Balamb Town", L"Timber", L"Dollet", L"Deling City", L"Fisherman's Horizeon",
	L"Winhill", L"Shumi Village", L"Esthar City",

	// Final Fantasy IX
	L"Alexandria", L"Dali", L"Lindblum", L"Summit Station", L"Cleyra", L"Treno",
	L"Conde Petie", L"Black Mage Village", L"Madain Sari", L"Esto Gaza",
	L"Daguerreo", L"Bran Bal", L"Burmecia",

	// Final Fantasy X
	L"Besaid Village", L"Kilika", L"Luca", L"Mi'ihen Highroad", L"Guadosalam",
	L"Thunder Plains", L"Macalania", L"Bevelle", L"Calm Lands",

	// Final Fantasy XI
	L"Republic of Bastok", L"The Kingdom of San d'Oria",
	L"The Federation of Windurst", L"The Grand Duchy of Jeuno", L"Aragoneu",
	L"Derfland", L"Fauregandi", L"Gustaberg", L"Kolshushu", L"Norvallen",
	L"Qufim", L"Ronfaure", L"Sarutabaruta", L"Valdeaunia", L"Zulkheim",
	L"Arrapago Islands", L"Halvung Territory", L"Mamool Ja Savagelands",
	L"Ruins of Alzadaal", L"West Aht Urhgan", L"Dynamis",

	// Shin Megami Tensei: Nocturne
	L"Shinjuku", L"Shibuya", L"Amala Network", L"Labyrinth of Amala",
	L"Ginza", L"Great Underpass of Ginza", L"Ikebukuro",
	L"Mantra Headquarters", L"Assembly of Nihilo", L"Kabukicho",
	L"Asakusa", L"The Obelisk", L"Amala Temple", L"Mifunashiro",
	L"Diet Building", L"Tower of Kagutsuchi",

	// Shin Megami Tensei: Digital Devil Saga
	L"Ground Zero", L"Muladhara", L"Svadhisthana", L"Manipura", L"Anahata",
	L"Coordinate 136", L"Deserted Ship", L"Embryon Base 2", L"Vishuddha",
	L"Ajna", L"Karma Temple", L"Samsara Tunnels",

	// Shin Megami Tensei: Digital Devil Saga 2
	L"Underground City", L"Internment Facility", L"Karma Society Tower",
	L"EGG Installation", L"Power Plant", L"Airport", L"HAARP Facility", L"Sun"
};

wstring names::antarctic_bases[176] = {
	// Antarctica
// Research Stations
L"Aboa", L"Aguirre Cerda", L"Amundsen–Scott South Pole", L"Arctowski", L"Arrival Heights Laboratory", L"Arrival Heights Satellite", L"Artigas", L"Arturo Parodi", L"Arturo Prat", L"Asuka", L"Beaver Lake", L"Belgrano I", L"Belgrano II", L"Belgrano III", L"Bellingshausen", L"Bharati", L"Borga", L"Brockton", L"Brown", L"Byrd", L"Cámara", L"Carvajal", L"Station T", L"Casey", L"Charcot", L"Collins", L"Comandante Ferraz", L"Concordia", L"Dakshin Gangotri", L"Dallmann", L"Davis", L"Deception", L"Dirck Gerritsz Laboratory", L"Dobrowolski", L"Oasis", L"Dome Fuji", L"Drescher", L"Druzhba", L"Drúzhnaya 1", L"Drúzhnaya 2", L"Drúzhnaya 3", L"Drúzhnaya 4", L"Dumont d'Urville", L"E Base", L"East Base", L"Eco-Nelson", L"Eduardo Frei", L"and", L"Villa Las Estrellas", L"Eights", L"Ellsworth", L"Elichiribehety", L"Station D", L"Escudero", L"Esperanza", L"Filchner", L"Fossil Bluff", L"Station KG", L"Gabriel de Castilla", L"General Bernardo O'Higgins", L"Georg Forster", L"German Antarctic Receiving Station", L"Giacomo Bove", L"Gondwana", L"González Videla", L"Great Wall", L"Guillermo Mann", L"Hallett", L"Halley", L"Jang Bogo", L"Jinnah", L"Juan Carlos Primero", L"Jubany", L"Carlini", L"Julio Ripamonti", L"King Baudouin #1", L"King Baudouin #2", L"King Sejong", L"Kohnen", L"Komsomolskaya", L"Kunlun", L"Law", L"Lázarev", L"Lenie", L"Leningradskaya", L"Little America", L"Little Rockford", L"Machu Picchu", L"Maitri", L"Maldonado", L"Marambio", L"Mario Zucchelli", L"Matienzo", L"Maudheim", L"Mawson", L"McMurdo", L"Melchior", L"Mendel", L"Mir", L"Mirny", L"Mizuho", L"Molodyozhnaya", L"Neumayer I", L"Neumayer II", L"Neumayer III", L"Norway", L"Novolazarevskaya", L"Oasis", L"Dobrowolski", L"Oazis 2", L"Orcadas", L"Palmer", L"Petrel", L"Pionérskaya", L"Plateau", L"Pobeda", L"Pole of inaccessibility", L"Port Martin", L"Primavera", L"Princess Elisabeth", L"Progress", L"Risopatrón", L"Rothera", L"Station R", L"Russkaya", L"Salyut", L"San Martín", L"SANAE I", L"SANAE II", L"SANAE III", L"SANAE IV", L"Sarie Marais", L"Scott Base", L"Shirreff", L"Signy", L"Station H", L"Site 2", L"Syowa", L"Siple", L"Sobral", L"Sodrúzhestvo", L"South Ice", L"Sovetskaya", L"Soyuz", L"St. Kliment Ohridski", L"Station A", L"Station B", L"Station C", L"Station D", L"Station E", L"Station F", L"Faraday", L"Station G", L"Station J", L"Station N", L"Station O", L"Station P", L"Station T", L"Station V", L"Station W", L"Station Y", L"Svea", L"Taishan", L"Tor", L"Troll", L"Union Glacier", L"Vanda", L"Vechernyaya", L"Vernadsky", L"Vostok", L"Vostok I", L"Wasa", L"Weddell 1", L"World Park", L"Yelcho", L"Zhongshan",
};

wstring names::ores[15] = {
	L"Adamantyte", L"Bauxite", L"Chromium", L"Copper", L"Diamond", L"Gold",
	L"Iron", L"Lead", L"Manganese", L"Mithril", L"Nickel", L"Platinum",
	L"Silver", L"Tin", L"Titanium"
};

wstring names::caveTypes[17] = {
	L"Deepest", L"Dark", L"Deep", L"Deeper", L"Darker", L"Darkest", L"Mysterious",
	L"Luminous", L"Skull", L"Faerie", L"Troll", L"Goblin", L"Bandit", L"Mercenary",
	L"Demon's", L"Dwarven", L"Beast's"
};
wstring names::caves[10] = {
	L"Underground Waterway", L"Antlion's Den", L"Manscorpion's Den",
	L"Master's Ichor Chamber", L"Underworld"
};
wstring names::elements[6] = {
	L"Air", L"Chaos", L"Earth", L"Fire", L"Light", L"Water"
};
wstring names::farms[8] = {
	L"Blueberry", L"Raspberry", L"Barley", L"Beetroot", L"Wheat", L"Carrot", L"Potato", L"Cranberry"
};
wstring names::specials[10] = {
	L"Arcadia", L"Crystal Caves", L"Decrepid Crypt", L"Fishing Village",
	L"Nightmare Cathedral", L"Northern Camp", L"Orc Encampment",
	L"Peasant Hamlet", L"Royal Gardens", L"Windswept Valley"
};




wstring names::role() { return roles[rand() % (sizeof(roles) / sizeof(roles[0]))]; }
wstring names::firstName() { return first[rand() % (sizeof(first) / sizeof(first[0]))]; }
wstring names::lastName() { return last[rand() % (sizeof(last) / sizeof(last[0]))]; }
wstring names::fullName() { return full[rand() % (sizeof(full) / sizeof(full[0]))]; }
wstring names::fullName(wstring role) {
	int i = rand() % 20 + 1;
	if (i == 1) { 
		return full[rand() % (sizeof(full) / sizeof(full[0]))]; 
	} 
	else if (i == 20) {
		if (role == L"Barbarian") {			return barbarian[rand() % (sizeof(barbarian) / sizeof(barbarian[0]))]; }
		else if (role == L"Bard") {			return bard[rand() % (sizeof(bard) / sizeof(bard[0]))]; }
		else if (role == L"Cleric") {		return cleric[rand() % (sizeof(cleric) / sizeof(cleric[0]))]; }
		else if (role == L"Demon Hunter") { return demon_hunter[rand() % (sizeof(demon_hunter) / sizeof(demon_hunter[0]))]; }
		else if (role == L"Druid") {		return druid[rand() % (sizeof(druid) / sizeof(druid[0]))]; }
		else if (role == L"Knight") {		return knight[rand() % (sizeof(knight) / sizeof(knight[0]))]; }
		else if (role == L"Paladin") {		return paladin[rand() % (sizeof(paladin) / sizeof(paladin[0]))]; }
		else if (role == L"Pugilist") {		return pugilist[rand() % (sizeof(pugilist) / sizeof(pugilist[0]))]; }
		else if (role == L"Pyromancer") {	return pyromancer[rand() % (sizeof(pyromancer) / sizeof(pyromancer[0]))]; }
		else if (role == L"Samurai") {		return samurai[rand() % (sizeof(samurai) / sizeof(samurai[0]))]; }
		else if (role == L"Sniper") {		return sniper[rand() % (sizeof(sniper) / sizeof(sniper[0]))]; }
		else if (role == L"Sorcerer") {		return sorcerer[rand() % (sizeof(sorcerer) / sizeof(sorcerer[0]))]; }
		else if (role == L"Thief") {		return thief[rand() % (sizeof(thief) / sizeof(thief[0]))]; }
		else if (role == L"Princess") {		return princess[rand() % (sizeof(princess) / sizeof(princess[0]))]; }
		else if (role == L"Fool") {			return fool[rand() % (sizeof(fool) / sizeof(fool[0]))];	}
		else {								return L"Clarence Thompkins"; }
	}
	else { 
		return firstName() + L" " + lastName(); 
	} 
}

wstring names::townName() { return towns[rand() % (sizeof(towns) / sizeof(towns[0]))]; }
wstring names::cave() { return caves[rand() % (sizeof(caves) / sizeof(caves[0]))]; }
wstring names::caveType() { return caveTypes[rand() % (sizeof(caveTypes) / sizeof(caveTypes[0]))]; }
wstring names::ore() { return ores[rand() % (sizeof(ores) / sizeof(ores[0]))]; }
wstring names::element() { return elements[rand() % (sizeof(elements) / sizeof(elements[0]))]; }
wstring names::farm() { return farms[rand() % (sizeof(farms) / sizeof(farms[0]))]; }
wstring names::special() { return specials[rand() % (sizeof(specials) / sizeof(specials[0]))]; }
wstring names::base() { return antarctic_bases[rand() % (sizeof(antarctic_bases) / sizeof(antarctic_bases[0]))]; }

