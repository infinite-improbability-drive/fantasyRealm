import java.util.ArrayList;

public class fantasyParty {
   public static ArrayList<String> party; 
   public static String partyMember;

//*****************************************************************************

   public fantasyParty() {
      String partyMember = "";
   }
   
//*****************************************************************************

   public static ArrayList<String> add() {
      party.add(partyMember);
      return party;      
   }

//*****************************************************************************

   public static void print() {
      System.out.println("Party members: ");   
      System.out.println(party);
      return;      
   }

//*****************************************************************************

}  // End fantasyParty