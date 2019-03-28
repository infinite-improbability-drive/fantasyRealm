import java.io.IOException;
import java.util.ArrayList;

public class fantasyParty {
   public static ArrayList<fantasyPlayer> party;
//   public static String partyMember;

//*****************************************************************************

    public fantasyParty() throws IOException {
        party = new ArrayList<>(0);
        party.add(new fantasyPlayer());
        party.get(0).start();
    }
   
//*****************************************************************************

    public static ArrayList<fantasyPlayer> add() {
        party.add(new fantasyPlayer());
        System.out.println(party.get(party.size() - 1).name + " the " +
            party.get(party.size() - 1).role + " has joined the party!");
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