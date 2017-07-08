import java.awt.*;
import java.util.Random;
import java.util.Scanner;

public class fantasyPlayer {
    // Static variables
    static Random random = new Random();
    static Scanner scan = new Scanner(System.in);
    public static Point point = new Point();
    public static String direction;
    public static String location;
    public final static String[] stats = new String[] {
            "Level", "XP", "Next Level", "HP", "Max HP", "MP", "Max MP",
            "Stamina", "Strength", "Agility", "Intelligence", "Wisdom", "Spirit",
    };

    // Instance variables
    private int number;
    public String ability;
    public String name;
    public String role;
    public String weapon;
    // Add helm, legs, gloves, chestpiece, 3 ring slots, other jewelery

//    public static int[] stat_levels;
    public int[] stat_levels;

//*****************************************************************************

    public fantasyPlayer() {
        number = random.nextInt(fantasyRoles.roles.length);
        role = fantasyRoles.roles[number];
        name = name(role);
        ability = fantasyAbility.abilities[number];
        weapon = fantasyWeapons.weapons[number];
        stat_levels = new int[stats.length];
        for (int i = 0; i < stats.length; i++) {
            stat_levels[i] = 10;
        }
//        role        =
//                fantasyRoles.roles[random.nextInt(fantasyRoles.roles.length)];
//        name        = name(role);
//        ability     = ability(role);
//        weapon      = weapon(role);
//       direction = "";
//       location  = "";
//       point = new Point();
//       start();
   }

//*****************************************************************************

   public void start() {
      System.out.println("Welcome to the fantasy realm. ");
      set();
      System.out.println("Welcome, [" + name + "] the [" + role + "]. ");
      System.out.println("The [" + role + "] class uses the [" + weapon + 
         "] and has the class ability [" + ability + "]. ");
      System.out.println("You begin your adventure at " +
              location + ". ");
      System.out.println("Player = " + point.x + ", " +
              point.y);
   } // End start

//*****************************************************************************
   
   private void set() {
      name      = setName();
      role      = setRole();
      weapon    = setWeapon();
      ability   = setAbility();
      setLocation();
//       System.out.print("Please enter a number: ");
   }   // End set

//*****************************************************************************

    public String setName() {
        System.out.print("Please enter your name: ");
        name = scan.nextLine();
        return name;
    }

//*****************************************************************************

    static String name(String role) {
        //       "Barbarian", "Bard", "Cleric", "Demon Hunter", "Druid", "Knight", "Paladin", "Pugilist",
        //       "Pyromancer", "Samurai", "Sniper", "Sorcerer", "Thief", "Princess", "Fool"};
        int i = 0;
        for (i = 0; i < fantasyRoles.roles.length; i++) {
            if (role.equals(fantasyRoles.roles[i])) {
                break;
//                return fantasyNames.role_names[i][
//                        random.nextInt(fantasyNames.role_names[i].length)];
            }
        }
        return fantasyNames.role_names[i][
                random.nextInt(fantasyNames.role_names[i].length)];
//        if (role.equals(fantasyRoles.roles[0])) {
//            return fantasyNames.role_names[0][
//                    random.nextInt(fantasyNames.role_names[0].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[1])) {
//            return fantasyNames.role_names[1][
//                    random.nextInt(fantasyNames.role_names[1].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[2])) {
//            return fantasyNames.role_names[2][
//                    random.nextInt(fantasyNames.role_names[2].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[3])) {
//            return fantasyNames.role_names[3][
//                    random.nextInt(fantasyNames.role_names[3].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[4])) {
//            return fantasyNames.role_names[4][
//                    random.nextInt(fantasyNames.role_names[4].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[5])) {
//            return fantasyNames.role_names[5][
//                    random.nextInt(fantasyNames.role_names[5].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[6])) {
//            return fantasyNames.role_names[6][
//                    random.nextInt(fantasyNames.role_names[6].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[7])) {
//            return fantasyNames.role_names[7][
//                    random.nextInt(fantasyNames.role_names[7].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[8])) {
//            return fantasyNames.role_names[8][
//                    random.nextInt(fantasyNames.role_names[8].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[9])) {
//            return fantasyNames.role_names[9][
//                    random.nextInt(fantasyNames.role_names[9].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[10])) {
//            return fantasyNames.role_names[10][
//                    random.nextInt(fantasyNames.role_names[10].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[11])) {
//            return fantasyNames.role_names[11][
//                    random.nextInt(fantasyNames.role_names[11].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[12])) {
//            return fantasyNames.role_names[12][
//                    random.nextInt(fantasyNames.role_names[12].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[13])) {
//            return fantasyNames.role_names[13][
//                    random.nextInt(fantasyNames.role_names[13].length)];
//        }
//        else if (role.equals(fantasyRoles.roles[14])) {
//            return fantasyNames.role_names[14][
//                    random.nextInt(fantasyNames.role_names[14].length)];
//        }
//        else {
//            return "Butt-breath";
//        }
    }   // End name()

//*****************************************************************************

   public String setRole() {
      System.out.println("Please choose your class- "); 
      fantasyRoles.print();
      role = scan.nextLine();
      for (int i = 0; i < fantasyRoles.roles.length; ++i) {
         if (fantasyRoles.roles[i].equals(role)) {
            break;
         }
         else if (fantasyRoles.roles[i].equals(fantasyRoles.roles[
                     fantasyRoles.roles.length - 1])) {
            role = fantasyRoles.roles[fantasyRoles.roles.length - 1];
            break;
         }
      }
      return role;
   }

//*****************************************************************************

    private String setAbility() {
        for (int i = 0; i < fantasyRoles.roles.length; ++i) {
            if (fantasyRoles.roles[i].equals(role)) {
                ability = fantasyAbility.abilities[i];
                break;
            }
        }
        return ability;
    }  // End set weapon

//*****************************************************************************

    private String setWeapon() {
        for (int i = 0; i < fantasyRoles.roles.length; ++i) {
            if (fantasyRoles.roles[i].equals(role)) {
                weapon = fantasyWeapons.weapons[i];
                break;
            }
        }
        return weapon;
    }  // End set weapon

//*****************************************************************************

    private void setLocation() {
        Point holder = new Point(
        fantasyLocation.points[random.nextInt(fantasyLocation.points.length)]);
        // Set starting point
        point.x = holder.x;
        point.y = holder.y;
            for (int i = 0; i < fantasyLocation.points.length; i++) {
                if (point.equals(fantasyLocation.points[i])) {
                    location = fantasyLocation.locations[i];
                }
            }
    }  // End set player location

//*****************************************************************************

   public static void depart() {
      System.out.println("Which way will you go?- ");
      System.out.print("[North, South, East or West]: ");
      direction = scan.nextLine();
      location = null;
      if ((direction.equals("North"))||(direction.equals("north"))||
         (direction.equals("N"))||(direction.equals("n"))) {
         direction = "North";
         point.y += 1;
      }
      else if ((direction.equals("South"))||(direction.equals("south"))||
         (direction.equals("S"))||(direction.equals("s"))) {
         direction = "South";
         point.y -= 1;
      }
      else if ((direction.equals("East"))||(direction.equals("east"))||
         (direction.equals("E"))||(direction.equals("e"))) {
         direction = "East";
         point.x += 1;
      }
      else if ((direction.equals("West"))||(direction.equals("west"))||
         (direction.equals("W"))||(direction.equals("w"))) {
         direction = "West";
         point.x -= 1;
      }
      else {depart();}
      System.out.println("You have decided to go [" + direction + "]. ");
      System.out.println("Player = " + point.x + ", " + point.y);   
   }  // End move()

//*****************************************************************************

   public static void arrive() {
      System.out.println("You have arrived " + direction + ". ");
      for (int i = 0; i < fantasyLocation.points.length; i++) {
         if (point.equals(fantasyLocation.points[i])) {
            System.out.println("You have arrived at " +
                    fantasyLocation.locations[i] + ". ");
            location = fantasyLocation.locations[i];
            if (random.nextInt(100) > 30) {
                fantasyParty.add();
            }
         }
      }
      if (random.nextInt(10) > 9) {

      }
   }

//*****************************************************************************

//   public static void stats() {
//      for (int i = 0; i < stats.length; i++) {
//         System.out.println(stats[i] + stat_levels[i]);
//      }
//   }

//*****************************************************************************

}  // End fantasyPlayer