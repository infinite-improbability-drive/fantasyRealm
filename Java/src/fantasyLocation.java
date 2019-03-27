import java.awt.*;
import java.util.Random;
import java.util.Scanner;

public class fantasyLocation {
    static int total_locations;
    public static Point[] points;
    public static String[] locations;
    static Random random = new Random();
    static Scanner scan = new Scanner(System.in);

    static String[] caves = new String[] {
        "Deepest", "Dark", "Deep", "Deeper", "Darker", "Darkest", "Mysterious",
        "Luminous", "Skull", "Faerie", "Troll", "Goblin", "Bandit", "Mercenary",
        "Demon's", "Dwarven", "Beast's"};
    static String[] cave = new String[] {
        "Underground Waterway", "Antlion's Den", "Manscorpion's Den",
        "Master's Ichor Chamber", "Underworld"};
    static String[] elements = new String[] {
        "Air","Earth", "Fire", "Water"};
    static String[] farms = new String[] {
        "Blueberry", "Raspberry", "Beetroot", "Wheat", "Carrot", "Potato",
        "Cranberry"};
    static String[] myLocations = new String[] {
        "Arcadia", "Crystal Caves", "Decrepid Crypt", "Fishing Village",
        "Nightmare Cathedral", "Northern Camp", "Orc Encampment",
        "Peasant Hamlet", "Royal Gardens", "Windswept Valley"};
    static String[] namedTowns = new String[] {

        // Dragon Quest
        "Tantagel Castle", "The Town of Brecconary", "Erdrick's Cave",
        "The Town of Garinham", "The Village of Kol", "Rock Mountain Cave",
        "Swamp Cave", "The Town of Rimuldar", "The Town of Cantlin",
        "Charlock Castle",

        // Final Fantasy
        "Cornelia", "Pravoka", "Elfheim", "Mount Duergar",
        "Melmond", "Crescent Lake", "Onrac", "Lufenia", "Gaia",

        // Final Fantasy II
        "Altair", "Gatrea", "Paloom", "Poft", "Salamand", "Bafsk",
        "Fynn", "Mysidia", "Tropical Island", "Machanon",

        // Final Fantasy VII
        "Sector 7 Slums", "Wall Market", "Kalm Town", "Fort Condor", "Junon",
        "Costa del Sol", "North Corel", "Gold Saucer", "Gongaga Village",
        "Nibelheim", "Rocket Town", "Wutai", "Bone Village", "Icicle Inn",
        "Mideel",

        // Final Fantasy VIII
        "Balamb Town", "Timber", "Dollet", "Deling City", "Fisherman's Horizeon",
        "Winhill", "Shumi Village", "Esthar City",

        // Final Fantasy IX
        "Alexandria", "Dali", "Lindblum", "Summit Station", "Cleyra", "Treno",
        "Conde Petie", "Black Mage Village", "Madain Sari", "Esto Gaza",
        "Daguerreo", "Bran Bal", "Burmecia",

        // Final Fantasy X
        "Besaid Village", "Kilika", "Luca", "Mi'ihen Highroad", "Guadosalam",
        "Thunder Plains", "Macalania", "Bevelle", "Calm Lands",

        // Final Fantasy XI
        "Republic of Bastok", "The Kingdom of San d'Oria",
        "The Federation of Windurst", "The Grand Duchy of Jeuno", "Aragoneu",
        "Derfland", "Fauregandi", "Gustaberg", "Kolshushu", "Norvallen",
        "Qufim", "Ronfaure", "Sarutabaruta", "Valdeaunia", "Zulkheim",
        "Arrapago Islands", "Halvung Territory", "Mamool Ja Savagelands",
        "Ruins of Alzadaal", "West Aht Urhgan", "Dynamis",

        // Shin Megami Tensei: Nocturne
        "Shinjuku", "Shibuya", "Amala Network", "Labyrinth of Amala",
        "Ginza", "Great Underpass of Ginza", "Ikebukuro",
        "Mantra Headquarters", "Assembly of Nihilo", "Kabukicho",
        "Asakusa", "The Obelisk", "Amala Temple", "Mifunashiro",
        "Diet Building", "Tower of Kagutsuchi",

        // Shin Megami Tensei: Digital Devil Saga
        "Ground Zero", "Muladhara", "Svadhisthana", "Manipura", "Anahata",
        "Coordinate 136", "Deserted Ship", "Embryon Base 2", "Vishuddha",
        "Ajna", "Karma Temple", "Samsara Tunnels",

        // Shin Megami Tensei: Digital Devil Saga 2
        "Underground City", "Internment Facility", "Karma Society Tower",
        "EGG Installation", "Power Plant", "Airport", "HAARP Facility", "Sun"
    };


    static String[] ores = new String[] {
            "Adamantyte", "Bauxite", "Chromium", "Copper", "Diamond", "Gold",
            "Iron", "Lead", "Manganese", "Mithril", "Nickel", "Platinum",
            "Silver", "Tin", "Titanium"
    };


//*****************************************************************************

    public fantasyLocation() {
        // point = randomPoint(10);
        // name = randomLocation();
        // npc = false;
        // shop = false;
        // smith = false;
        // inn = false;

        total_locations = random(50);
        points = new Point[random(25) + 10];
        locations = new String[points.length];
        start();
        // Set random locations
        for (int i = 0; i < points.length; i++) {
            points[i] = randomPoint(10);
            locations[i] = randomLocation();
        }
    }

//*****************************************************************************

    public static void start() {
        set();
        check();
        print();
    }

//*****************************************************************************

    private static void set() {
        for (int i = 0; i < points.length; i++) {
            points[i] = randomPoint(10);
            locations[i] = randomLocation();
        }
    }  // End set

//*****************************************************************************

    private static void check() {
        for (int i = 0; i < points.length; i++) {
            for (int j = 1; j < points.length; j++) {
                while (points[i] == points[j]) {
                    System.out.println("Duplicate point found! ");
                    points[i] = randomPoint(10);
                    break;
                }
                while (locations[i] == locations[j]) {
                    System.out.println("Duplicate location found! ");
                    locations[i] = randomLocation();
                    break;
                }
            }  // End inner loop
        }  // End outer loop
    }  // End check()

//*****************************************************************************

    private static void print() {
        for (int i = 0; i < points.length; i++) {
            System.out.println(locations[i] + " = " + points[i]);
        }
    }

//*****************************************************************************

    private static int random(int limit) {
        return random.nextInt(limit);
    }

//*****************************************************************************

    private static Point randomPoint(int size) {
        return new Point((random(size * 2) - size),
                (random(size * 2) - size));
    }

//*****************************************************************************

    private static String randomLocation() {
        String random_location = "";

        String[] directions = new String[] {
                "Northern", "Southern", "Eastern", "Western"};

        int roll = random(1000);

        if (roll == 1000) {
        }

        // Named Towns
        else if ((roll < 1000) && (roll >= 900)) {
            random_location = namedTowns[random(namedTowns.length)];
        }

        // My locations
        else if ((roll < 900) && (roll >= 800)) {
            random_location = myLocations[random(myLocations.length)];
        }

        // Caves
        else if ((roll < 800) && (roll >= 700)) {
            if (roll >= 775) {
                random_location = cave[random(cave.length)];
            }
            else if ((roll < 775) && (roll >= 760)){
                random_location = caves[random(caves.length)] + " Crypt";
            }
            else if ((roll < 760) && (roll >= 745)){
                random_location = caves[random(caves.length)] + " Cavern";
            }
            else {
                random_location = caves[random(caves.length)] + " Cave";
            }
        }

        // Peasant Dwellings
        else if ((roll < 700) && (roll >= 600)) {
            if (roll >= 675) {
                random_location = fantasyNames.last_names[random(
                        fantasyNames.last_names.length)] + " Farm";
            }
            else if ((roll < 675) && (roll >= 650)) {
                random_location = fantasyNames.last_names[random(
                        fantasyNames.last_names.length)] + " Village";
            }
            else if ((roll < 650) && (roll >= 625)) {
                random_location = fantasyNames.last_names[random(
                        fantasyNames.last_names.length)] + " Manor";
            }
            else if ((roll < 625) && (roll >= 613)) {
                random_location = fantasyNames.last_names[random(
                        fantasyNames.last_names.length)] + " Homestead";
            }
            else {
                random_location = "House " + fantasyNames.last_names[random(
                        fantasyNames.last_names.length)];
            }
        }

        // Specific farm goods
        else if ((roll < 600) && (roll >= 500)) {
            if (roll >= 575) {
                random_location =
                        fantasyNames.last_names[random(fantasyNames.last_names.length)] +
                                "'s " + farms[random(farms.length)] + " Farm";
            }
            else if ((roll < 575) && (roll >= 550)) {
                random_location =
                        fantasyNames.last_names[random(fantasyNames.last_names.length)] +
                                "'s " + farms[random(farms.length)] + " Ranch";
            }
            else if ((roll < 550) && (roll >= 525)) {
                random_location =
                        fantasyNames.last_names[random(fantasyNames.last_names.length)] +
                                "'s Dairy Farm";
            }
            else {
                random_location =
                        fantasyNames.last_names[random(fantasyNames.last_names.length)] +
                                "'s Vineyard";
            }
        }
        // End specific farm goods

        // Mines
        else if ((roll < 500) && (roll >= 400)) {
            random_location = ores[random(ores.length)] + " Mine";
            if (roll >= 475) {}
            else if ((roll < 475) && (roll >= 450)) {}
            else if ((roll < 450) && (roll >= 425)) {}
            else {}
        }
        // End Mines

        // Former Kings & Queens
        else if ((roll < 400) && (roll >= 300)) {
            if (roll >= 375) {
                random_location = elements[random(elements.length)] + " Temple";
            }
            else if ((roll < 375) && (roll >= 350)) {
                random_location = "Temple of " + fantasyNames.full_names[
                        random(fantasyNames.full_names.length)];
            }
            else if ((roll < 350) && (roll >= 325)) {
                if (roll >= 345) {
                    random_location = fantasyNames.full_names[
                            random(fantasyNames.full_names.length)] + "'s Sanctuary";
                }
                else if ((roll < 345) && (roll >= 340)) {
                    random_location = fantasyNames.full_names[
                            random(fantasyNames.full_names.length)] + "'s Archives";
                }
                else if ((roll < 340) && (roll >= 335)) {
                    random_location = fantasyNames.full_names[
                            random(fantasyNames.full_names.length)] + "'s Resting Place";
                }
            }
            else {
                random_location = fantasyNames.full_names[
                        random(fantasyNames.full_names.length)] + "'s Tomb";
            }
        }
        // End former kings and queens

        else if ((roll < 300) && (roll >= 200)) {
            random_location = "Castle " +
                    fantasyNames.last_names[random(fantasyNames.last_names.length)];
            if (roll >= 675) {}
            else if ((roll < 675) && (roll >= 650)) {}
            else if ((roll < 650) && (roll >= 625)) {}
            else {}
        }
        else if ((roll < 200) && (roll >= 100)) {
            random_location = "Unknown location";
            if (roll >= 675) {}
            else if ((roll < 675) && (roll >= 650)) {}
            else if ((roll < 650) && (roll >= 625)) {}
            else {}
        }
        else if ((roll < 100) && (roll > 0)) {
            random_location = "Unknown location";
            if (roll >= 675) {}
            else if ((roll < 675) && (roll >= 650)) {}
            else if ((roll < 650) && (roll >= 625)) {}
            else {}
        }
        else {
            random_location = "Unknown location";
            if (roll >= 675) {}
            else if ((roll < 675) && (roll >= 650)) {}
            else if ((roll < 650) && (roll >= 625)) {}
            else {}
        }
        return random_location;
    }

//*****************************************************************************

    public static void look() {
        System.out.println("You look around the [" + fantasyPlayer.location +
                "]. ");
    }

//*****************************************************************************

}  // End fantasyLocation

class location {}
