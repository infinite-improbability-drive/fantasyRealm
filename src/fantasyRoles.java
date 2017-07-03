public class fantasyRoles {
   public static String[] roles = new String[] {
      "Barbarian", "Bard", "Cleric", "Demon Hunter", "Druid", "Knight", "Paladin", "Pugilist", 
      "Pyromancer", "Samurai", "Sniper", "Sorcerer", "Thief", "Princess", "Fool"};
      
//*****************************************************************************

   public static void print() {
      int i = 0;
      System.out.print("(");
      for (i = 0; i < 5; ++i) {
      System.out.print(roles[i] + ", ");
      }
      System.out.print("\n");
      for (i = 5; i < 10; ++i) {
      System.out.print(roles[i] + ", ");
      }   
      System.out.print("\n");
      for (i = 10; i <= roles.length - 4; ++i) {
      System.out.print(roles[i] + ", ");
      }
      System.out.print(roles[(roles.length - 3)]);
      System.out.print("): ");
   }  // End print()

//*****************************************************************************

}  // End fantasyRoles