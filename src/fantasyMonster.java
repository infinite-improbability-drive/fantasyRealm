import java.util.Random;

public class fantasyMonster {
    public static String type;
    public String name;
    static int HP;
    static int MP;
    public static String monster;
    public static String[] monsterTypes = {
            "Trash", "Small", "Normal", "Large", "Very Large", "Rare",
            "Very Rare", "Giant", "Boss"};
    static Random random = new Random();

//*****************************************************************************

    // Default constructor
    public fantasyMonster() {
        name = fantasyBattle.group_name;
        type = fantasyBattle.monster_type;
        HP = 100;
        MP = 10;
    }

//*****************************************************************************

    // Constructor with type parameter
    public fantasyMonster(String set_type) {
        type = set_type;
        name = monster();
    }

//*****************************************************************************

    public static String type() {
        int type_roll = random.nextInt(100) + 1;
        if (type_roll >= 99) {
            type = monsterTypes[6];     // Very Rare
        }
        else if ((type_roll < 99)&&(type_roll >= 95)) {
            type = monsterTypes[5];     // Rare
        }
        else if ((type_roll < 95)&&(type_roll >= 85)) {
            type = monsterTypes[4];     // Very Large
        }
        else if ((type_roll < 85)&&(type_roll >= 60)) {
            type = monsterTypes[3];     // Large
        }
        else if ((type_roll < 60)&&(type_roll >= 40)) {
            type = monsterTypes[2];     // Normal
        }
        else if ((type_roll < 40)&&(type_roll >= 20)) {
            type = monsterTypes[1];     // Small
        }
        else {
            type = monsterTypes[0];     // Trash
        }
//        System.out.println("Monster type = " + type);
        return type;
    }

//*****************************************************************************

    public static int number() {
        int number = 0;
        if (type.equals(monsterTypes[0])) {
            number = random.nextInt(3) + 1;
        }
        else if (type.equals(monsterTypes[1])) {
            number = random.nextInt(12) + 1;
        }
        else if (type.equals(monsterTypes[2])) {
            number = random.nextInt(3) + 2;
        }
        else if (type.equals(monsterTypes[3])) {
            number = random.nextInt(1) + 1;
        }
        else if (type.equals(monsterTypes[4])) {
            number = 1;
        }
        else if (type.equals(monsterTypes[5])) {
            number = random.nextInt(1) + 1;
        }
        else if (type.equals(monsterTypes[6])) {
            number = 1;
        }

        return number;
    }

//*****************************************************************************

    public static String monster() {
//        monster = trashMonster();
        if (type.equals(monsterTypes[0])) {
            monster = trashMonster();
        }
        else if (type.equals(monsterTypes[1])) {
            monster = smallMonster();
        }
        else if (type.equals(monsterTypes[2])) {
            monster = normalMonster();
        }
        else if (type.equals(monsterTypes[3])) {
            monster = largeMonster();
        }
        else if (type.equals(monsterTypes[4])) {
            monster = veryLargeMonster();
        }
        else if (type.equals(monsterTypes[5])) {
            monster = rareMonster();
        }
        else if (type.equals(monsterTypes[6])) {
            monster = veryRareMonster();
        }
        return monster;
    }

//*****************************************************************************

    public static String trashMonster() {
        String[] trashMonsters = {
                "Crow", "Rat", "Worm"};
        return trashMonsters[random.nextInt(trashMonsters.length)];
    }

//*****************************************************************************

    public static String smallMonster() {
        String[] smallMonsters = {
                "Cockatrice", "Enchanted Clothing", "Faery", "Goblin", "Hobbit",
                "Imp", "Jackelope", "Kodama", "Leprechaun", "Pirhana",
                "Pixie", "Rat", "Goblin", "Red Slime", "Slime",
                "Sprite", "Wisp"};
        String[] slimeColors = {
                "Blue", "Green", "Orange", "Pink", "Purple", "Red", "Yellow"};
        String small_monster =
                smallMonsters[random.nextInt(smallMonsters.length)];
        if (small_monster.equals("Slime")) {
            small_monster =
                    slimeColors[random.nextInt(slimeColors.length)] +
                    " " + "Slime";
        }
        return small_monster;
    }

//*****************************************************************************

    public static String normalMonster() {
        String[] normalMonsters = {
                "Bandit", "Basilisk", "Centaur", "Demon", "Djinn", "Dryad",
                "Elemental", "Enchanted Furniture", "Faun", "Ghoul",
                "Giant Rat", "Green Man", "Harpy", "Lamia", "Large Slime",
                "Mermaid", "Naga", "Orc", "Satyr", "Shapeshifter", "Siren",
                "Tengu", "Vampire", "Wendigo", "Werewolf", "Wolf", "Yokai",
                "Zombie",};
        return normalMonsters[random.nextInt(normalMonsters.length)];
    }

//*****************************************************************************

    public static String largeMonster() {
        String[] largeMonsters = {
                "Alpha Wolf", "Behemoth", "Demon King", "Dire Wolf",
                "Giantic Rat", "Goblin King", "Golem",
                "Griffin", "Hydra", "Land Shark", "Manticore", "Minotaur",
                "Ogre", "Orc Captain", "Scorpion Man", "Were-bear"};
        return largeMonsters[random.nextInt(largeMonsters.length)];
    }

//*****************************************************************************

    public static String veryLargeMonster() {
        return "Giant";
    }

//*****************************************************************************

    public static String rareMonster() {
        String[] rareMonsters = {
                "Doppelganger", "Leprechaun", "Master Tonberry", "Moon Rabbit",
                "Old Hero", "Pink Souffle"};
        return rareMonsters[random.nextInt(rareMonsters.length)];
    }

//*****************************************************************************

    public static String veryRareMonster() {
        return "Unicorn";
    }

//*****************************************************************************

}   // End fantasyMonster