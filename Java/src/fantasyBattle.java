import java.util.Random;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class fantasyBattle {
    static String monster_type;
    int monster_amount;
    static Scanner scan = new Scanner(System.in);
    static String group_name;
    static String loner_name;
    static Random random = new Random();
    static ArrayList<fantasyMonster> monsters;
    static String[] loners = {"lone", "lonely", "single", "solitary",
            "wandering", "wayward"};

    //    static boolean mix_types;
//    static int[] monsterNumber;
//    static int number_of_types;
//    static int total_monsters;
//    static String monsterType;
//    static String monsterName;
//    static String[] monsterTypes;
//    fantasyMonster[] monsters;
//    static fantasyBattleGroup[] groups;

//*****************************************************************************

    public fantasyBattle() {
        monster_type = fantasyMonster.type();
        monster_amount = fantasyMonster.number();
        group_name = fantasyMonster.monster();
        monsters = new ArrayList<fantasyMonster>(0);

        // Add random amount of monsters of set type
        for (int i = 0; i < monster_amount; i++) {
            monsters.add(new fantasyMonster());
        }   // End add random amount of monsters of set type

        // Announce single attacker
        if (monsters.size() == 1) {
            if (((monsters.get(monsters.size() - 1).name.substring(0, 1)
                            .toLowerCase()).equals("a"))||
                    ((monsters.get(monsters.size() - 1).name.substring(0, 1)
                            .toLowerCase()).equals("e"))||
                    ((monsters.get(monsters.size() - 1).name.substring(0, 1)
                            .toLowerCase()).equals("i"))||
                    ((monsters.get(monsters.size() - 1).name.substring(0, 1)
                            .toLowerCase()).equals("o"))||
                    ((monsters.get(monsters.size() - 1).name.substring(0, 1)
                            .toLowerCase()).equals("u"))) {
                System.out.print("An ");
            }
            else {
                System.out.print("A ");
            }
            if (random.nextInt(10) > 7) {
                System.out.println(
                        loners[random.nextInt(loners.length)] + " " +
                        monsters.get(monsters.size() - 1).name + " attacks! ");
            }
            else {
                System.out.println(monsters.get(monsters.size() - 1).name +
                        " attacks! ");
            }
        }   // End announce single attacker

        // Announce multiple attackers
        if (monsters.size() > 1) {
            System.out.print("A group of " + monsters.size() + " ");
            // Check if alternate plural suffix needed
            if (((monsters.get(monsters.size() - 1).name.substring(
                    monsters.get(monsters.size() - 1).name.length() - 1,
                    monsters.get(monsters.size() - 1).name.length()))
                    .equals("f"))) {
                System.out.println(monsters.get(monsters.size() - 1).name.
                    substring(0, monsters.get(monsters.size() - 1).name.
                    length() - 1) + "ves attacks! ");
            }
            else if (((monsters.get(monsters.size() - 1).name.substring(
                    monsters.get(monsters.size() - 1).name.length() - 1,
                    monsters.get(monsters.size() - 1).name.length()))
                    .equals("y"))) {
                System.out.println(monsters.get(monsters.size() - 1).name.
                        substring(0, monsters.get(monsters.size() - 1).name.
                                length() - 1) + "ies attacks! ");
            }
            else if (((monsters.get(monsters.size() - 1).name.substring(
                    monsters.get(monsters.size() - 1).name.length() - 3,
                    monsters.get(monsters.size() - 1).name.length()))
                    .equals("Man"))) {
                System.out.println(monsters.get(monsters.size() - 1).name.
                        substring(0, monsters.get(monsters.size() - 3).name.
                                length() - 3) + "Men attacks! ");
            }
            else if (((monsters.get(monsters.size() - 1).name)
                       .equals("Djinn"))) {
                System.out.println(monsters.get(monsters.size() - 1).name +
                        " attacks! ");
            }
            // Normal plural suffix
            else {
                System.out.println(monsters.get(monsters.size() - 1).name +
                        "s attacks! ");
            }   // End normal plural suffix

        }   // End announce multiple attackers

        // Somewhat rarely add next level monster
        if (random.nextInt(20) < 16) {
            for (int i = 0; i < fantasyMonster.monsterTypes.length - 5; i++) {
                if (monster_type.equals(fantasyMonster.monsterTypes[i])) {
                    monster_type = fantasyMonster.monsterTypes[(i + 1)];
                    monsters.add(new fantasyMonster(monster_type));
                    System.out.println(
                            "A " + monsters.get(monsters.size() - 1).name +
                            " attacks! ");
                    break;
                }
            }
            monster_type = "";
        }   // End somewhat rarely add next level monster

        // Print loaded monsters
        for (int i = 0; i < monsters.size(); i++) {
            System.out.println("Monster #" + (i + 1) + " = " +
                    monsters.get(i).name);
        }

    }

//*****************************************************************************

    public static void battle() {
//        System.out.println("What will you do?");
        // Battle start
        // Choose starting turn; player or enemy
        boolean first_strike = random.nextBoolean();
//        String attacker = "";
        if (first_strike) {
//            attacker = "player";
            System.out.println("You strike first!");
            while (!monsters.isEmpty()) {
               playerTurn();
               enemyTurn();
            }
        }
        else {
//            attacker = "enemy";
            System.out.println("Enemy strikes first!");
            while (!monsters.isEmpty()) {
                enemyTurn();
                playerTurn();
            }
        }
        // End battle start



        // Choose starting defender
        // End Battle loop

        // Battle end
        // End battle end
    }

//*****************************************************************************

    public static void playerTurn() {
        fantasyCommand command = new fantasyCommand();
        int target_monster = 0;
        statusCheck();
        command.get();
        command.act();
        if (command.command.equals("Fight")) {
            if (monsters.size() == 1) {
                target_monster = 0;
            }
            else {
                target_monster = target();
            }
            attack(target_monster);
        }
        if (command.command.equals("Run")) {
            monsters = new ArrayList<fantasyMonster>();
        }
    }

//*****************************************************************************

    public static void enemyTurn() {
        return;
    }

//*****************************************************************************

    public static void statusCheck() {}

//*****************************************************************************

    public static int target() {
        System.out.println("Which monster will you attack? ");
//        fantasyMonster target;
        int input;
        for (int i = 0; i < monsters.size(); i++) {
            System.out.println("Monster #" + (i + 1) + " = " +
                    monsters.get(i).name);
        }
        System.out.print("[");
        for (int i = 0; i < monsters.size() - 1; i++) {
            System.out.print((i + 1) + ", ");
        }
        for (int i = monsters.size() - 1; i < monsters.size(); i++) {
            System.out.print((i + 1) + "] ");
        }
        input = scan.nextInt();
//        target = monsters.get(input - 1);
        System.out.println("You have chosen Monster #" + (input) + " = " +
            monsters.get(input - 1).name);
        return input - 1;
    }

//*****************************************************************************

    public static ArrayList<fantasyMonster> attack(int target_monster) {
        monsters.get(target_monster).HP -= 10;
        if (monsters.get(target_monster).HP <= 0) {
            System.out.println("You have defeated Monster #" +
                    (target_monster + 1) + " = " +
                    monsters.get(target_monster).name);
            monsters.remove(target_monster);
            if (monsters.isEmpty()) {
                System.out.println("You have defeated the monsters. ");
            }
        }
        else {
            System.out.println(monsters.get(target_monster).name + " HP: " +
                    monsters.get(target_monster).HP);
        }
        return monsters;
    }

//*****************************************************************************

}   // End fantasyBattle