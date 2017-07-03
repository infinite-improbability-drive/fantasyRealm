import java.util.Random;

public class fantasyMonster {
    public static String type;
    public String name;
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
        return "Worm";
    }

//*****************************************************************************

    public static String smallMonster() {
        return "Goblin";
    }

//*****************************************************************************

    public static String normalMonster() {
        return "Zombie";
    }

//*****************************************************************************

    public static String largeMonster() {
        return "Behemoth";
    }

//*****************************************************************************

    public static String veryLargeMonster() {
        return "Giant";
    }

//*****************************************************************************

    public static String rareMonster() {
        return "Leprechaun";
    }

//*****************************************************************************

    public static String veryRareMonster() {
        return "Unicorn";
    }

//*****************************************************************************

}   // End fantasyMonster

//        type = fantasyBattleGroup.group_type;
//        name = fantasyBattleGroup.group_name;
//        System.out.println("Name = " + fantasyBattleGroup.group_name);
//        monster = "";
//        name = fantasyBattle.group_name;
//        type = fantasyBattle.monster_type;
//        type = fantasyBattleGroup.group_type;
//        name = fantasyBattleGroup.group_name;
//        System.out.println("Name = " + fantasyBattleGroup.group_name);
//        monster = "";
//        else {
//            monster = veryRareMonster();
//        }
