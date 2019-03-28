import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

// To do:
// Unify player + party_member as single arrayList<fantasyPlayer>


public class fantasyRealm {
   static boolean acting = false;
   static boolean moving = false;
   static String direction = "";
   static Random random = new Random();
   static Scanner scan  = new Scanner(System.in);
   static fantasyAction action     = new fantasyAction();
   static fantasyJournal journal   = new fantasyJournal();
   static fantasyLocation location = new fantasyLocation();
   static fantasyPlayer player     = new fantasyPlayer();
   // static ArrayList<fantasyLocation> locations = new ArrayList<fantasyLocation>();

   static fantasyParty party;
   static {
      try {
         party = new fantasyParty();
      } catch (IOException e) {
         e.printStackTrace();
      }
   }

   static fantasySave save;
   static {
      try {
         save = new fantasySave();
      } catch (IOException e) {
         e.printStackTrace();
      }
   }

   public static void main (String[] args) {
                  
//*****************************************************************************
      
      while (acting == false) {
            act();
      }
   
   }  // End main

//*****************************************************************************

   public static void act() {
      action.get();
      action.act();
   }

//*****************************************************************************

   public static void move() {
      // Depart
      player.depart();

      // Random battle
      if (random.nextInt(8) != 0) {
         System.out.println("A wild group of monsters appeared! ");
          fantasyBattle battle = new fantasyBattle();
          battle.battle();
      }

      // Arrive
      player.arrive();
   }

//*****************************************************************************
   
   public static void save(fantasySave save) {
//       fantasySave save         = new fantasySave();
      save.save();
   }

//*****************************************************************************

   public static void quit() {
      System.exit(0);
   }

//*****************************************************************************

}  // End fantasyRealm