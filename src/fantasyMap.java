import java.util.ArrayList;
import java.awt.*;
import java.util.Random;

public class fantasyMap {
    static ArrayList<fantasyLocation> locations;
    static ArrayList<fantasyLocation> unknown_locations;
    static ArrayList<fantasyLocation> unseen_locations;
    static Random random = new Random();

//*****************************************************************************

    public fantasyMap() {
        locations = new ArrayList<>(random.nextInt(50) + 1);
    }

//*****************************************************************************
   
    public static void print() {
        int i          = 0;
        int j          = 0;
        int k          = 1;
        int mapLevel   = 1;
        int mapSize    = mapLevel * 4;
        Point mapPointer = new Point();
        String mapData = "";
        String mapLine = "";
        String mapKey  = "";
        String pad_border = "---------------------------------------------------------------";
        String pad_empty  = "                                                               ";
        int x = 0;
        int y = 0;
        int z = 0;
        String[] mapLines = new String[(mapSize * 2) + 3];
        String[] mapKeys = new String[(mapSize * 2) + 3];
      
        // Map heading
        String heading = "Ye Olde Adventuring Mappe:";
        System.out.println(
            "+----------------------------+" +
            "\n| " + heading + " |" +
            "\n+--------------------------------------------------------------------+"
            );
      
        // Proper map loop
        for ( mapPointer.y = fantasyPlayer.point.y + mapSize + 1;
            mapPointer.y > fantasyPlayer.point.y - mapSize - 2;
            mapPointer.y--) {
            for ( mapPointer.x = fantasyPlayer.point.x - mapSize - 1; 
                mapPointer.x < fantasyPlayer.point.x + mapSize + 2;
                mapPointer.x++) {
                for (i = 0; i < fantasyLocation.points.length; i++) {
   
                    // Top map border
                    if (  (mapPointer.y == fantasyPlayer.point.y + mapSize + 1)&&
                        (mapPointer.y <= fantasyLocation.points[i].y)&&
                        (mapPointer.x == fantasyLocation.points[i].x)) {
                        mapData = "^ ";
                        if (((mapPointer.y == fantasyPlayer.point.y
                                + mapSize + 1) &&
                            (mapPointer.x == fantasyPlayer.point.x
                                - mapSize - 1))||
                            ((mapPointer.y == fantasyPlayer.point.y
                                + mapSize + 1) &&
                            (mapPointer.x == fantasyPlayer.point.x
                                + mapSize + 1))) {
                            mapData = "  ";
                        }
                        break;
                    }  // End if for Top map border
                  
                    // else if for Right map border
                    else if ((mapPointer.x == fantasyPlayer.point.x + mapSize + 1)&&
                             (mapPointer.x <= fantasyLocation.points[i].x)&&
                             (mapPointer.y == fantasyLocation.points[i].y)) {
                        mapData = "> ";
                        if (((mapPointer.y == fantasyPlayer.point.y + mapSize + 1) &&
                             (mapPointer.x == fantasyPlayer.point.x + mapSize + 1))||
                            ((mapPointer.y == fantasyPlayer.point.y - mapSize - 1) &&
                             (mapPointer.x == fantasyPlayer.point.x + mapSize + 1))) {
                            mapData = "  ";
                        }
                        break;
                    }  // End else if for Right map border
                  
                  // else if for Bottom map border
                  else if ((mapPointer.y == fantasyPlayer.point.y
                                - mapSize - 1)&&
                           (mapPointer.y >= fantasyLocation.points[i].y)&&
                           (mapPointer.x == fantasyLocation.points[i].x)) {
                     mapData = "v ";
                     if (((mapPointer.y == fantasyPlayer.point.y
                            - mapSize - 1) &&
                         (mapPointer.x == fantasyPlayer.point.x
                            + mapSize + 1))||
                         ((mapPointer.y == fantasyPlayer.point.y
                            - mapSize - 1) &&
                         (mapPointer.x == fantasyPlayer.point.x
                            - mapSize - 1))) {
                     mapData = "  ";
                     }
                     break;
                  }  // End else if for Bottom map border
                  
                  // Left map border
                  else if ((mapPointer.x == fantasyPlayer.point.x - mapSize - 1)&&
                           (mapPointer.x >= fantasyLocation.points[i].x)&&
                           (mapPointer.y == fantasyLocation.points[i].y)) {
                     mapData = "< ";
                     if (((mapPointer.y == fantasyPlayer.point.y + mapSize + 1) &&
                          (mapPointer.x == fantasyPlayer.point.x - mapSize - 1))||
                         ((mapPointer.y == fantasyPlayer.point.y - mapSize - 1) &&
                          (mapPointer.x == fantasyPlayer.point.x - mapSize - 1))) {
                     mapData = "  ";
                     }
                     break;
                  }  // End Left map border
                  
                  // Map border blank space
                  else if (((mapPointer.y == fantasyPlayer.point.y + mapSize + 1)||
                            (mapPointer.x == fantasyPlayer.point.x + mapSize + 1)||
                            (mapPointer.y == fantasyPlayer.point.y - mapSize - 1)||
                            (mapPointer.x == fantasyPlayer.point.x - mapSize - 1))) {
                        mapData = "  ";
                     
                    } // Map border blank space

                    // Player point
                    else if (mapPointer.equals(fantasyPlayer.point)) {
                        mapData = (fantasyParty.party.get(0).name.substring(0, 1) + " ");
                        mapKeys[0] = ("[" + fantasyParty.party.get(0).name.substring(0, 1) + "] " +
                            fantasyParty.party.get(0).name + " the " + fantasyParty.party.get(0).role);
                        if (y < mapKeys[0].length()) {y = mapKeys[0].length();}
                        if  (mapPointer.equals(fantasyLocation.points[i])) {
                            mapKeys[k] = ("[" + fantasyLocation.locations[i].substring(0, 1) + "] " +
                                fantasyLocation.locations[i]);
                            if (y < mapKeys[k].length()) {y = mapKeys[k].length();}
                            k++;
                            break;
                        }
                    } // End player point

                    // Location point
                    else if (mapPointer.equals(fantasyLocation.points[i])) {
                        mapData = (fantasyLocation.locations[i].substring(0, 1) + " ");
                        mapKeys[k] = ("[" + fantasyLocation.locations[i].substring(0, 1) + "] " +
                            fantasyLocation.locations[i]);
                        if (y < mapKeys[k].length()) {y = mapKeys[k].length();}
                     k++;
                     if (mapPointer.equals(fantasyPlayer.point)) {
                        mapData = (fantasyParty.party.get(0).name.substring(0, 1) + " ");
                        mapKeys[0] = ("[" + fantasyParty.party.get(0).name.substring(0, 1) + "] " +
                                fantasyParty.party.get(0).name + " the " + fantasyParty.party.get(0).role);
                         if (y < mapKeys[0].length()) {y = mapKeys[0].length();}
                     }
                     break;
                  } // End location point
   
                  else {
                     mapData = ". ";
                  }   
                           
               }
               mapLine += mapData;
                     
            }
            mapLines[j] = ("| " + mapLine);
            j++;
            
         mapLine = "";
         
      }
   
            for (j = 0, k = 0; j < ((mapSize * 2) + 3); j++, k++) {
                if (mapKeys[k] == null) {
                    mapKeys[k] = "";
                }
                if (mapKeys[k].length() < y) {
                    mapKeys[k] = mapKeys[k] +
                        pad_empty.substring(0, y - mapKeys[k].length()) + "|";
                }
                System.out.println(mapLines[j] + "| " + mapKeys[k]);
            }
   
         System.out.println(
         "+--------------------------------------------------------------------+"
         );
   
      return;

   }    // End print

//*****************************************************************************

}  // End fantasyMap