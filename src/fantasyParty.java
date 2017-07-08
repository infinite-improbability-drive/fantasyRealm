import java.util.ArrayList;

public class fantasyParty {
   public static ArrayList<fantasyNPC> party;
//   public static String partyMember;

//*****************************************************************************

    public fantasyParty() {
        party = new ArrayList<>(10);
        party.add(new fantasyNPC());
    }
   
//*****************************************************************************

    public static ArrayList<fantasyNPC> add() {
       party.add(new fantasyNPC());
        return party;
    }

//*****************************************************************************

    public static void print() {
        System.out.println("Party members: ");
        for (int i = 0; i < party.size(); i++) {
            System.out.println(party.get(i).name + " the " + party.get(i).role);
        }
        return;
    }

//*****************************************************************************

}  // End fantasyParty