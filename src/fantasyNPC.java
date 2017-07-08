import java.util.Random;

public class fantasyNPC {
    static Random random = new Random();
    boolean party_member;
    int number;
    public String ability;
    public String name;
    public String role;
    public String weapon;

//*****************************************************************************

    public fantasyNPC() {
        number = random.nextInt(fantasyRoles.roles.length);
        role = fantasyRoles.roles[number];
        ability = fantasyAbility.abilities[number];
        weapon = fantasyWeapons.weapons[number];
        name = name(role);
    }

//*****************************************************************************

    static String name(String role) {
    //       "Barbarian", "Bard", "Cleric", "Demon Hunter", "Druid", "Knight", "Paladin", "Pugilist",
    //       "Pyromancer", "Samurai", "Sniper", "Sorcerer", "Thief", "Princess", "Fool"};
        if (role.equals(fantasyRoles.roles[0])) {
            return fantasyNames.role_names[0][
                random.nextInt(fantasyNames.role_names[0].length)];
        }
        else if (role.equals(fantasyRoles.roles[1])) {
            return fantasyNames.role_names[1][
                    random.nextInt(fantasyNames.role_names[1].length)];
        }
        else if (role.equals(fantasyRoles.roles[2])) {
            return fantasyNames.role_names[2][
                    random.nextInt(fantasyNames.role_names[2].length)];
        }
        else if (role.equals(fantasyRoles.roles[3])) {
            return fantasyNames.role_names[3][
                    random.nextInt(fantasyNames.role_names[3].length)];
        }
        else if (role.equals(fantasyRoles.roles[4])) {
            return fantasyNames.role_names[4][
                    random.nextInt(fantasyNames.role_names[4].length)];
        }
        else if (role.equals(fantasyRoles.roles[5])) {
            return fantasyNames.role_names[5][
                    random.nextInt(fantasyNames.role_names[5].length)];
        }
        else if (role.equals(fantasyRoles.roles[6])) {
            return fantasyNames.role_names[6][
                    random.nextInt(fantasyNames.role_names[6].length)];
        }
        else if (role.equals(fantasyRoles.roles[7])) {
            return fantasyNames.role_names[7][
                    random.nextInt(fantasyNames.role_names[7].length)];
        }
        else if (role.equals(fantasyRoles.roles[8])) {
            return fantasyNames.role_names[8][
                    random.nextInt(fantasyNames.role_names[8].length)];
        }
        else if (role.equals(fantasyRoles.roles[9])) {
            return fantasyNames.role_names[9][
                    random.nextInt(fantasyNames.role_names[9].length)];
        }
        else if (role.equals(fantasyRoles.roles[10])) {
            return fantasyNames.role_names[10][
                    random.nextInt(fantasyNames.role_names[10].length)];
        }
        else if (role.equals(fantasyRoles.roles[11])) {
            return fantasyNames.role_names[11][
                    random.nextInt(fantasyNames.role_names[11].length)];
        }
        else if (role.equals(fantasyRoles.roles[12])) {
            return fantasyNames.role_names[12][
                    random.nextInt(fantasyNames.role_names[12].length)];
        }
        else if (role.equals(fantasyRoles.roles[13])) {
            return fantasyNames.role_names[13][
                    random.nextInt(fantasyNames.role_names[13].length)];
        }
        else if (role.equals(fantasyRoles.roles[14])) {
            return fantasyNames.role_names[14][
                    random.nextInt(fantasyNames.role_names[14].length)];
        }
        else {
            return "Butt-breath";
        }
    }

//*****************************************************************************

}   // End fantasyNPC
