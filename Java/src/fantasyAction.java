import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class fantasyAction {
   public static String action;
   
   private static ArrayList<String> actions;
   private static Scanner scan;
   
//*****************************************************************************
   
   public fantasyAction() {
      actions = new ArrayList<String>();
      action = "";
      scan = new Scanner(System.in);
   }

//*****************************************************************************

   public static void act() {
      if (action.equals("Items")) {}
      else if (action.equals("Journal")) {
         fantasyJournal.print();
      }
      else if (action.equals("Look")) {
         System.out.println("You decide to [" + action +
            "] around the [" + fantasyPlayer.location + "]. ");
         fantasyLocation.look();
      }
      else if (action.equals("Map")) {
         fantasyMap.print();
      }
      else if (action.equals("Party")) {
         fantasyParty.print();
      }
      else if (action.equals("Status")) {
//         fantasyPlayer.stats();
      }
      else if (action.equals("Exit")) {
         System.out.println("You have decided to " + action + ". ");
         fantasyRealm.move();
      }
      else if (action.equals("Quit")) {
         fantasyRealm.quit();         
      }
//       return;
   }

//*****************************************************************************

   public static String get() {
      if (!actions.isEmpty()) {
         System.out.print("What will you do?-\n" + actions + ": ");
      }
      else {
         System.out.print("What will you do?: ");
      }
      action = scan.nextLine();
      if (((action.equals("Items"))||(action.equals("items"))||
           (action.equals("I"))||(action.equals("i")))) {
         action = "Items";   
      }
      else if (((action.equals("Journal"))||(action.equals("journal"))||
           (action.equals("J"))||(action.equals("j")))) {
         action = "Journal";   
      }
      else if (((action.equals("Look"))||(action.equals("look"))||
           (action.equals("L"))||(action.equals("l")))) {
         action = "Look";   
      }
      else if (((action.equals("Map"))||(action.equals("map"))||
           (action.equals("M"))||(action.equals("m")))) {
         action = "Map";   
      }
      else if (((action.equals("Party"))||(action.equals("party"))||
           (action.equals("P"))||(action.equals("p")))) {
         action = "Party";   
      }
      else if (((action.equals("Status"))||(action.equals("status"))||
           (action.equals("S"))||(action.equals("s")))) {
         action = "Status";   
      }
      else if ((action.equals("Exit"))||(action.equals("exit"))||
           (action.equals("E"))||(action.equals("e"))) {
         action = "Exit";   
      }
      else if (((action.equals("Quit"))||(action.equals("quit"))||
           (action.equals("Q"))||(action.equals("q")))) {
         action = "Quit";   
      }
      if (check() == false) {learn();} 
      return action;
   }
   
//*****************************************************************************

   public static String action() {
      return action;
   }
   
//*****************************************************************************

   // action.actionCheck();
   public static boolean check() {
      boolean check = false;
      if (actions.contains(action)) {
         check = true;
      }
      else {
         check = false;
      }
      return check;
   }    
   
//*****************************************************************************

   public static List<String> learn() {
   
      // Learn items
      if (((action.equals("Items"))||(action.equals("items"))||
                (action.equals("I"))||(action.equals("i")))
              &&(!actions.contains("Items"))) {
         action = "Items";
         actions.add(action);
         if (actions.contains("Exit")) {
            actions.remove("Exit");
            actions.add("Exit");
         }
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to check your [" + action + "]. ");
      }         
      else if (((action.equals("Journal"))||(action.equals("journal"))||
           (action.equals("J"))||(action.equals("j")))
         &&(!actions.contains("Journal"))) {
         action = "Journal";
         actions.add(action);
         if (actions.contains("Exit")) {
            actions.remove("Exit");
            actions.add("Exit");
         }
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to check your [" + action + "]. ");
      }       
      else if (((action.equals("Look"))||(action.equals("look"))||
           (action.equals("L"))||(action.equals("l")))
         &&(!actions.contains("Look"))) {
         action = "Look";
         actions.add(action);
         if (actions.contains("Exit")) {
            actions.remove("Exit");
            actions.add("Exit");
         }
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to [" + action + "]. ");
      }       
      else if (((action.equals("Map"))||(action.equals("map"))||
                (action.equals("M"))||(action.equals("m")))
              &&(!actions.contains("Map"))) {
         action = "Map";
         actions.add(action);
         if (actions.contains("Exit")) {
            actions.remove("Exit");
            actions.add("Exit");
         }
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to check your [" + action + "]. ");
      }      
      else if (((action.equals("Party"))||(action.equals("party"))||
           (action.equals("P"))||(action.equals("p")))
         &&(!actions.contains("Party"))) {
         action = "Party";
         actions.add(action);
         if (actions.contains("Exit")) {
            actions.remove("Exit");
            actions.add("Exit");
         }
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to check your [" + action + "]. ");
      }       
      else if (((action.equals("Status"))||(action.equals("status"))||
                (action.equals("S"))||(action.equals("s")))
              &&(!actions.contains("Status"))) {
         action = "Status";
         actions.add(action);
         if (actions.contains("Exit")) {
            actions.remove("Exit");
            actions.add("Exit");
         }
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to check your [" + action + "]. ");
      }      
      else if (((action.equals("Exit"))||(action.equals("exit"))||
                (action.equals("E"))||(action.equals("e")))
              &&(!actions.contains("Exit"))) {
         action = "Exit";
         actions.remove(action);
         actions.add(action);
         if (actions.contains("Quit")) {
            actions.remove("Quit");
            actions.add("Quit");
         }
         System.out.println("You have learned how to [" + action + "]. ");
      }
      else if (((action.equals("Quit"))||(action.equals("quit"))||
                (action.equals("Q"))||(action.equals("q")))
              &&(!actions.contains("Quit"))) {
         action = "Quit";
         actions.remove(action);
         actions.add(action);
         System.out.println("You have learned how to [" + action + "]. ");
      }
      else {
         System.out.println("You try to " + action + ", but it just doesn't " + 
            "work. \nTry something else. ");
      }
      get();
      return actions;
   }
    
//*****************************************************************************   
   
}  // End fantasyAction
