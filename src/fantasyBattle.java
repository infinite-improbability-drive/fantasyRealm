import java.util.Random;
import java.util.ArrayList;
import java.util.List;

public class fantasyBattle {
    static String monster_type;
    int monster_amount;
    static String group_name;
    static String loner_name;
    static Random random = new Random();
    static ArrayList<fantasyMonster> monsters;

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
        }

        // Announce single attacker
        if (monsters.size() == 1) {
            System.out.println("A " + monsters.get(monsters.size() - 1).name + " attacks! ");
        }
        // Announce multiple attackers
        if (monsters.size() > 1) {
            System.out.println("A group of " + monsters.size() + " " +
                    monsters.get(monsters.size() - 1).name + "s attacks! ");
        }

        // Somewhat rarely add next level monster
        if (random.nextInt(20) < 16) {
            for (int i = 0; i < fantasyMonster.monsterTypes.length - 3; i++) {
                if (monster_type.equals(fantasyMonster.monsterTypes[i])) {
                    monster_type = fantasyMonster.monsterTypes[(i + 1)];
                    monsters.add(new fantasyMonster(monster_type));
                    System.out.println("A " + monsters.get(monsters.size() - 1).name + " attacks! ");
                    break;
                }
            }
            monster_type = "";
        }

        // Print loaded monster
        for (int i = 0; i < monsters.size(); i++) {
            System.out.println("Monster #" + (i + 1) + " = " +
                    monsters.get(i).name);
        }

    }

//*****************************************************************************

    public static void battle() {
        System.out.println("What will you do?");
        // Battle start
        // Choose starting turn; player or enemy
        // first_strike = random.nextInt(2);
        // if (first_strike == 1) {
        //     attacker = "player";
        // }
        // else {
        //     attacker = "enemy";
        // }
        // End battle start

        // Battle loop
        // while (player_turn = true) {
        //     player_turn = false;
        //     enemy_turn = true;
        // }
        // while (enemy_turn = true) {
        //     enemy_turn = false;
        //     player_turn = true;
        // }
        // Choose starting attacker
        // if (attacker.equals("player")) {
        //
        // }

        // else {
        // }

        // Choose starting defender
        // End Battle loop

        // Battle end
        // End battle end
    }

//*****************************************************************************

}   // End fantasyBattle

//*****************************************************************************
//
// JUNK CODE
//
//            System.out.println("Monster #" + (i + 1) + " = " + monsters.get(i).name);
//        System.out.println("Type = " + monster_type + ", Amount = " + monster_amount);
//                    System.out.println("Type = " + monster_type);
//                    System.out.println("Type = " + monster_type);
//        fantasyMonster[] monsters = new fantasyMonster[monster_amount];
//                    loner_name = fantasyMonster.monster();
//                    fantasyMonster tmp = new fantasyMonster();
//            monsters[i] = new fantasyMonster();
//        // Set number of types
//        number_of_types = random.nextInt(100) + 1;
//        if (number_of_types > 96) {
//            number_of_types = 3;
//        }
//        else if ((number_of_types <= 96)&&(number_of_types > 81)) {
//            number_of_types = 2;
//        }
//        else {
//            number_of_types = 1;
//        }
//        System.out.println("Number of types = " + number_of_types);
//        // End set number of types
//
//        // Set outer array
//        fantasyBattleGroup[] groups = new fantasyBattleGroup[number_of_types];
//
//        // Set inner arrays
//        for (int i = 0, total_monsters = 1; i < groups.length; i++) {
////            System.out.println("Creating Group #" + (i + 1));
//            groups[i] = new fantasyBattleGroup();
////            System.out.println("Populating Group #" + (i + 1));
//            for (int j = 0; j < groups[i].monsters.length; j++, total_monsters++) {
//                groups[i].monsters[j] = new fantasyMonster();
////                System.out.println("Monster #" + (j + 1) + " = " + groups[i].monsters[j].name);
//                System.out.println("Monster #" + (total_monsters) + " = " + groups[i].monsters[j].name);
////                System.out.println("Total = " + total_monsters);
//            }
//        }
//        fantasyMonster[] battle_monsters = new fantasyMonster[total_monsters];
//
//        for (int i = 0, k = 0; i < groups.length; i++) {
//            for (int j = 0; j < groups[i].monsters.length; j++, k++) {
////                battle_monsters[k] = new fantasyMonster();
//                battle_monsters[k] = groups[i].monsters[j];
//            }
//        }
//        System.out.println("A wild groupPP of " + groups[0].number_of_monsters + " " +
//                groups[0].group_name + "s appeared!");
//        if (groups[1] != null) {
//            System.out.println("A wild groupPP of " + groups[1].number_of_monsters + " " +
//                    groups[1].group_name + "s appeared!");
//        }
//        if (groups[2] != null) {
//            System.out.println("A wild groupPP of " + groups[2].number_of_monsters + " " +
//                    groups[2].group_name + "s appeared!");
//        }
//        System.out.println("A wild groupPP of " + groups[2].number_of_monsters + " " +
//                groups[2].group_name + "s appeared!");
//        int k = 0;
//        fantasyMonster[] battle_monsters = new fantasyMonster[total_monsters];
// Print groups with names and numbers
//            System.out.println("A wild groupPP of " + groups[i].number_of_monsters + " " +
//                    groups[i].group_name + "s appeared!");
////            System.out.println("Creating Group #" + (i + 1));
//            groups[i] = new fantasyBattleGroup();
////            System.out.println("Populating Group #" + (i + 1));
//                battle_monsters[k] = new fantasyMonster();
//                battle_monsters[k] = groups[i].monsters[j];
////                System.out.println("Monster #" + (j + 1) + " = " + groups[i].monsters[j].name);
//                System.out.println("Monster #" + (total_monsters) + " = " + groups[i].monsters[j].name);
////                System.out.println("Total = " + total_monsters);
// Merge arrays
//        int k = 0;
//        fantasyMonster[] new_group = new fantasyMonster[total_monsters];
//        for (int i = 0; i < groups.length; i++) {
////            System.out.println("Creating Group #" + (i + 1));
////            groups[i] = new fantasyBattleGroup();
////            System.out.println("Populating Group #" + (i + 1));
//            for (int j = 0; j < groups[i].monsters.length; j++, k++) {
////                new_group[k] = new fantasyMonster();
//                new_group[k] = groups[i].monsters[j]; // = new fantasyMonster();
//                System.out.println("Monster #" + (k + 1) + " = " + new_group[k].name);
////                System.out.println("Total = " + total_monsters);
//            }
//        }

//        for (int i = 0; i < number_of_types; i++) {
//            System.out.println("Creating Group #" + (i + 1));
//            groups[i] = new fantasyBattleGroup();
//        }
//        for each in groups
//
//                fantasyBattleGroup new_group = new fantasyBattleGroup();
//            groups[i].monsters[i] = new fantasyMonster();
//            System.out.println(groups[i].group_type);
//            groups[i] = new fantasyMonster[new_group.number_of_monsters];
//            System.out.println("Group # " + (i + 1) + ": " + groups[i].group_type);
//            System.out.println("Group # " + (i + 1) + " contains: " + groups[i].number_of_monsters);
//            System.out.println("Number of types = " + number_of_types);
//
//        // Set outer array of groups
//        for (int i = 0; i < number_of_types; i++) {
//            fantasyBattleGroup[] groups = new fantasyBattleGroup[number_of_types];
//        }
//
//        // Set inner array of monsters within each group
//        for (int i = 0; i < number_of_types; i++) {
//            for (int j = 0; j < 3; j++) {
//                fantasyMonster[] monsters = new fantasyMonster[3];
//            }
//        }
//
//        int l = 0;
//        // Set inner array of monsters within each group
//        for (int i = 0; i < number_of_types; i++) {
//            for (int j = 0; j < groups.length; j++) {
//                for (int k = 0; k < monsters.length; k++) {
//                    monsters[j][k]  = new fantasyMonster();
//                    l++;
//                }
//            }
//        }
//
//            groups[i] = monsters[i];
//
//        monsterTypes = new String[number_of_types];
//        monsterNumber = new int[number_of_types];
//        int l = 0;
//
//        for (int i = 0; i < number_of_types; i++) {
//            System.out.println("Creating group #" + (i + 1));
//            fantasyBattleGroup[] groups = new fantasyBattleGroup[number_of_types];
//            System.out.println("Creating monsters in group #" + (i + 1));
//            groups[i] = new fantasyBattleGroup();
//        }
//        for (int i = 0; i < number_of_types; i++) {
//            for (int j = 0; j < groups.length; i++) {
//                System.out.println("Creating monsters in group #" + (i + 1));
//                groups[j] = new fantasyBattleGroup();
//            }
//        }
//        for (int i = 0; i < number_of_types; i++) {
//            for (int j = 0; j < groups.length; i++) {
//                for (int k = 0; j < groups.length; i++) {
//                System.out.println("Creating monsters in group #" + (i + 1));
//                groups[i] = new fantasyBattleGroup();
//                }
//            }
//        }
//
//        for (int i = 0; i < number_of_types; i++) {
//            System.out.println("Monster #" + (i + 1) + ": " + group[i]);
//        }
//            monsterTypes[i] = fantasyMonster.type();
//            for (int j = 0; j < monsterTypes.length; j++) {
//                monsterNumber[i] = fantasyMonster.number();
//                for (int k = 0; k < monsterNumber.length; k++) {
//                    group[l] = new fantasyMonster();
//                    total_monsters++;
//                }
//            }
//        }
//            group = new fantasyMonster[monsterNumber];
//
//        if (number_of_types == 1) {
//            monsterType = fantasyMonster.type();
//            System.out.println("Monster type = " + monsterType);
//            monsterNumber = fantasyMonster.number();
//            System.out.println("Monster number = " + monsterNumber);
//            monsterName = fantasyMonster.name;
//            System.out.println("Monster  = " + monsterName);
//            group = new fantasyMonster[monsterNumber];
//            for (int i = 0; i < group.length; i++) {
//                group[i] = new fantasyMonster();
//            }
//        }
//        else if (number_of_types == 2) {
//            monsterType = fantasyMonster.type();
//            System.out.println("Monster type = " + monsterType);
//            monsterNumber = fantasyMonster.number();
//            System.out.println("Monster number = " + monsterNumber);
//            monsterName = fantasyMonster.name;
//            System.out.println("Monster  = " + monsterName);
//            group = new fantasyMonster[monsterNumber];
//            for (int i = 0; i < group.length; i++) {
//                group[i] = new fantasyMonster();
//            }
//            for (int i = 0; i < group.length; i++) {
//                group[i] = new fantasyMonster();
//            }
//        }
//        else if (number_of_types == 3) {
//        }
//
//
//        // Print
//        if (total_monsters == 1) {
//            System.out.println("A wild " + group[0].name + " appeared!");
//        }
//        else if (total_monsters > 1) {
//            System.out.println("A wild group of " + total_monsters + " " +
//                    group[0].name + "s appeared!");
//        }
//        for (int i = 0; i < group.length; i++) {
//            System.out.println("Monster #" + (i + 1) + " = " +
//                    group[i].name);
//        }
