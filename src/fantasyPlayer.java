import java.awt.*;
import java.util.Random;
import java.util.Scanner;

public class fantasyPlayer {
   public static Point point;
   public static Random random;
   static Scanner scan;

   public static String ability;
   public static String name;
   public static String role;
   public static String weapon;
   public static String direction;
   public static String location;

   public final static String[] stats = new String[] {
      "HP", "MP", "Strength", "Dexterity", "Stamina", "Intelligence", "Wisdom", "Spirit", 
      };

   public static int[] levels;
   
//*****************************************************************************

   public fantasyPlayer() {
      ability   = "";
      direction = "";
      location  = "";
      name      = "";
      point = new Point();
      random = new Random();
      role = "";
      scan = new Scanner(System.in);
      start();
      levels = new int[8];
      for (int i = 0; i < stats.length; i++) {
         levels[i] = 10;
      }

   }

//*****************************************************************************

   public void start() {
      System.out.println("Welcome to the fantasy realm. ");
      set();
      System.out.println("Welcome, [" + name + "] the [" + role + "]. ");
      System.out.println("The [" + role + "] class uses the [" + weapon + 
         "] and has the class ability [" + ability + "]. ");
   } // End start

//*****************************************************************************
   
   private void set() {
      System.out.print("Please enter your name: ");
      name = scan.nextLine();
      role     = setRole();
      weapon   = setWeapon();
      ability  = setAbility();
      setLocation();
//       System.out.print("Please enter a number: ");
   }   // End set

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

   private void setLocation() {
      Point holder = new Point(
      fantasyLocation.points[random.nextInt(fantasyLocation.points.length)]);
      point.x = holder.x;
      point.y = holder.y;
         for (int i = 0; i < fantasyLocation.points.length; i++) {
            if (point.equals(fantasyLocation.points[i])) {
               location = fantasyLocation.locations[i];
            }
         }
      System.out.println("You begin your adventure at " + 
         location + ". ");
      System.out.println("Player = " + point.x + ", " + 
         point.y);
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
         }
      }
   }

//*****************************************************************************

   public static void stats() {
      for (int i = 0; i < stats.length; i++) {
         System.out.println(stats[i] + levels[i]);
      }
   }

//*****************************************************************************

}  // End fantasyPlayer