#include "pch.h"
#include <string>

using namespace std;

class name {
public:

	// first names
	wstring first[4] = { L"Elsie", L"Olga", L"Harold", L"Charlotte" };

	// last names
	wstring last[479] = {
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

	// full names
	wstring full[479] = {

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
		L"Jimmu", L"Suizei", L"Annei", L"Itoku", L"Kōshō", L"Kōan", L"Kōrei", 
		L"Kōgen", L"Kaika", L"Sujin", L"Suinin", L"Keikō", L"Seimu", L"Chūai", 
		L"Jingū", L"Ōjin", L"Nintoku", L"Richū", L"Hanzei", L"Ingyō", L"Ankō",
		L"Yūryaku", L"Seinei", L"Kenzō", L"Ninken", L"Buretsu", L"Keitai", 
		L"Ankan", L"Senka", L"Kinmei", L"Bidatsu", L"Yōmei", L"Sushun", 
		L"Suiko", L"Jomei", L"Kōgyoku", L"Kōtoku", L"Saimei", L"Tenji", 
		L"Kōbun", L"Tenmu", L"Jitō", L"Monmu", L"Genmei", L"Genshō", L"Shōmu", 
		L"Kōken", L"Junnin", L"Shōtoku", L"Kōnin", L"Kanmu", L"Heizei", L"Saga", 
		L"Junna", L"Ninmyō", L"Montoku", L"Seiwa", L"Yōzei", L"Kōkō", L"Uda", 
		L"Daigo", L"Suzaku", L"Murakami", L"Reizei", L"En'yū", L"Kazan", 
		L"Ichijō", L"Sanjō", L"Go-Ichijō", L"Go-Suzaku", L"Go-Reizei", 
		L"Go-Sanjō", L"Shirakawa", L"Horikawa", L"Toba", L"Sutoku", L"Konoe", 
		L"Go-Shirakawa", L"Nijō", L"Rokujō", L"Takakura", L"Antoku", 
		L"Go-Toba", L"Tsuchimikado", L"Juntoku", L"Chūkyō", L"Go-Horikawa", 
		L"Shijō", L"Go-Saga", L"Go-Fukakusa", L"Kameyama", L"Go-Uda", 
		L"Fushimi", L"Go-Fushimi", L"Go-Nijō", L"Hanazono", L"Go-Daigo", 
		L"Kōgon", L"Kōmyō", L"Sukō", L"Go-Kōgon", L"Go-En'yū", L"Go-Komatsu", 
		L"Go-Murakami", L"Chōkei", L"Go-Kameyama", L"Go-Komatsu", L"Shōkō", 
		L"Go-Hanazono", L"Go-Tsuchimikado", L"Go-Kashiwabara", L"Go-Nara", 
		L"Ōgimachi", L"Go-Yōzei", L"Go-Mizunoo", L"Meishō", L"Go-Kōmyō", 
		L"Go-Sai", L"Reigen", L"Higashiyama", L"Nakamikado", L"Sakuramachi", 
		L"Momozono", L"Go-Sakuramachi", L"Go-Momozono", L"Kōkaku", L"Ninkō", 
		L"Kōmei", L"Meiji", L"Taishō", L"Shōwa", L"Akihito", L"Naruhito"

	};

	wstring barbarian[6] = { L"Conan", L"Erlich", L"Krudr", L"Gimleim", L"Kull", L"Sonya" };
	wstring bard[6] = { L"Florian", L"Wolfgang", L"Carl", L"Elton", L"Gerald", L"Lenny" };
	wstring cleric[5] = { L"Joan", L"Nelly", L"Maria", L"Pious", L"Simon" };
	wstring demon_hunter[5] = { L"Blair", L"Bloodling", L"Damien", L"Jason", L"Michael" };
	wstring druid[4] = { L"Crow Bear", L"Crazy Horse", L"Flying Snake", L"Wolf Spider" };
	wstring knight[12] = { L"Alexander", L"Alfred", L"Arthur", L"Brianne", L"Charles", L"Cid", L"Edward", L"Henry", L"Heinrich", L"Richard", L"Seigfried", L"William" };
	wstring paladin[3] = { L"Alfonse", L"Marcus", L"Sanford" };
	wstring pugilist[3] = { L"Bonesaw", L"Hunter", L"Nikita" };
	wstring pyromancer[5] = { L"Rose", L"Lorelei", L"Veronica", L"Nadia", L"Jack" };
	wstring samurai[4] = { L"Mushashi", L"Miyamoto", L"Jubei", L"Saotome" };
	wstring sniper[2] = { L"Apollo", L"Artemis" };
	wstring sorcerer[4] = { L"Elektra", L"Esther", L"Helena", L"Nightshade" };
	wstring thief[6] = { L"Martin", L"Jimmy", L"Katsumi", L"Hayato", L"Beau", L"Justin" };
	wstring princess[12] = { L"Ariel", L"Augusta", L"Aurora", L"Euna", L"Eilonwy", L"Harmony", L"Irene", L"Maya", L"Melody", L"Priscilla", L"Rhythm", L"Sonya" };
	wstring fool[4] = { L"Charlie", L"Homer", L"Lemmy", L"Zippo" };


	wstring towns[131] = {

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

	wstring ores[15] = {
		L"Adamantyte", L"Bauxite", L"Chromium", L"Copper", L"Diamond", L"Gold",
		L"Iron", L"Lead", L"Manganese", L"Mithril", L"Nickel", L"Platinum",
		L"Silver", L"Tin", L"Titanium"
	};

	wstring caves[17] = {
		L"Deepest", L"Dark", L"Deep", L"Deeper", L"Darker", L"Darkest", L"Mysterious",
		L"Luminous", L"Skull", L"Faerie", L"Troll", L"Goblin", L"Bandit", L"Mercenary",
		L"Demon's", L"Dwarven", L"Beast's"
	};
	wstring cave[10] = {
		L"Underground Waterway", L"Antlion's Den", L"Manscorpion's Den",
		L"Master's Ichor Chamber", L"Underworld"
	};
	wstring elements[6] = {
		L"Air", L"Chaos", L"Earth", L"Fire", L"Light", L"Water"
	};
	wstring farms[8] = {
		L"Blueberry", L"Raspberry", L"Barley", L"Beetroot", L"Wheat", L"Carrot", L"Potato", L"Cranberry"
	};
	wstring special[10] = {
		L"Arcadia", L"Crystal Caves", L"Decrepid Crypt", L"Fishing Village",
		L"Nightmare Cathedral", L"Northern Camp", L"Orc Encampment",
		L"Peasant Hamlet", L"Royal Gardens", L"Windswept Valley"
	};

};

// L"Barbarian", L"Bard", L"Cleric", L"Demon Hunter", L"Druid", L"Knight", L"Paladin", L"Pugilist",
// L"Pyromancer", L"Samurai", L"Sniper", L"Sorcerer", L"Thief", L"Princess", L"Fool"};
