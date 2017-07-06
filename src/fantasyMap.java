import java.awt.*;
import java.util.Random;

public class fantasyMap {
    static fantasyLocation[] locations;
    static Random random = new Random();

//*****************************************************************************

    public fantasyMap() {
        locations = new fantasyLocation[random.nextInt(50) + 1];
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
      String[] mapLines = new String[(mapSize * 2) + 3];
      String[] mapKeys = new String[(mapSize * 2) + 3];
      
      // Map heading
      System.out.println(
         "+----------------------------+" + 
         "\n| Ye Olde Adventuring Mappe: |" + 
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
   
                  // if for Top map border
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
                  else if ((mapPointer.x == fantasyPlayer.point.x
                                + mapSize + 1)&&
                           (mapPointer.x <= fantasyLocation.points[i].x)&&
                           (mapPointer.y == fantasyLocation.points[i].y)) {
                     mapData = "> ";
                     if (((mapPointer.y == fantasyPlayer.point.y
                            + mapSize + 1) &&
                        (mapPointer.x == fantasyPlayer.point.x
                            + mapSize + 1))||
                        ((mapPointer.y == fantasyPlayer.point.y
                            - mapSize - 1) &&
                        (mapPointer.x == fantasyPlayer.point.x
                            + mapSize + 1))) {
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
                  
                  // else if for Left map border
                  else if ((mapPointer.x == fantasyPlayer.point.x - mapSize - 1)&&
                           (mapPointer.x >= fantasyLocation.points[i].x)&&
                           (mapPointer.y == fantasyLocation.points[i].y)) {
                     mapData = "< ";
                     if (((mapPointer.y == fantasyPlayer.point.y + mapSize + 1) && (mapPointer.x == fantasyPlayer.point.x - mapSize - 1))||
                         ((mapPointer.y == fantasyPlayer.point.y - mapSize - 1) && (mapPointer.x == fantasyPlayer.point.x - mapSize - 1))) {
                     mapData = "  ";
                     }
                     break;
                  }  // End else if for Left map border
                  
                  // Else if for map border blank space
                  else if (((mapPointer.y == fantasyPlayer.point.y + mapSize + 1)||(mapPointer.x == fantasyPlayer.point.x + mapSize + 1)||
                            (mapPointer.y == fantasyPlayer.point.y - mapSize - 1)||(mapPointer.x == fantasyPlayer.point.x - mapSize - 1))) {
                     mapData = "  ";
                     
                  } // End map border blank space
   
                  else if (mapPointer.equals(fantasyPlayer.point)) {
                     mapData = (fantasyPlayer.name.substring(0, 1) + " ");
                     mapKeys[0] = ("[" + fantasyPlayer.name.substring(0, 1) + "] " + fantasyPlayer.name + " the " + fantasyPlayer.role + "\t| ");
                     if  (mapPointer.equals(fantasyLocation.points[i])) {
                        mapKeys[k] = ("[" + fantasyLocation.locations[i].substring(0, 1) + "] " + fantasyLocation.locations[i] + "\t| "); 
                        k++;        
                        break;
                     }
                  }
                  
                  else if (mapPointer.equals(fantasyLocation.points[i])) {
                     mapData = (fantasyLocation.locations[i].substring(0, 1) + " ");
                     mapKeys[k] = ("[" + fantasyLocation.locations[i].substring(0, 1) + "] " + fantasyLocation.locations[i] + "\t| "); 
                     k++;               
                     if (mapPointer.equals(fantasyPlayer.point)) {
                        mapData = (fantasyPlayer.name.substring(0, 1) + " ");
                        mapKeys[0] = ("[" + fantasyPlayer.name.substring(0, 1) + "] " + fantasyPlayer.name + " the " + fantasyPlayer.role + "\t| ");        
                     }
                     break;
                  }
   
   
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
               mapKeys[k] = " ";
            }
         System.out.println(mapLines[j] + "| " + mapKeys[k]);
         }
   
         System.out.println(
         "+--------------------------------------------------------------------+"
         );
   
      return;   
   }

//*****************************************************************************

}  // End fantasyMap