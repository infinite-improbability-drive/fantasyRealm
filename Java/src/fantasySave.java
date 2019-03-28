import java.io.*;
import java.time.Clock;
import java.time.LocalTime;
import java.util.Scanner;

public class fantasySave {
    private static final String FILE_1 = "save_01.txt";
    private static final String FILE_2 = "save_02.txt";
    private static final String FILE_3 = "save_03.txt";
    private static final String SYSTEM_FILE = "system.txt";

    private static File SAVE;
    private static File SYSTEM;
    // private static String line;

    private static File inputDataFile;
    private static Scanner inputFile;
    private static FileWriter outputDataFile;
    private static PrintWriter outputFile;
    private static File inputSystemDataFile;
    private static Scanner inputSystemFile;
    private static FileWriter systemDataFile;
    private static PrintWriter systemFile;
    private static Scanner scan = new Scanner(System.in);

//*****************************************************************************

   public fantasySave() throws IOException {
      
//       final String FILE_1 = "save_01.txt";
//       final String FILE_2 = "save_02.txt";
//       final String FILE_3 = "save_03.txt";
//       final String SYSTEM_DATA = "system.txt";

      // line = "";
      setSaveFile();
      inputFile      = new Scanner(new File(FILE_1));
      outputDataFile = new FileWriter(FILE_1);
      outputFile     = new PrintWriter(outputDataFile);
      systemDataFile = new FileWriter(SYSTEM_FILE);
      systemFile     = new PrintWriter(systemDataFile);
      
//       read();
   }

//*****************************************************************************

    public static void load() {}

//*****************************************************************************

   public static void setSaveFile() {
      System.out.println("Please choose your file: ");
      int input = scan.nextInt();
      if (input == 1)      {SAVE = new File(FILE_1);}
      else if (input == 2) {SAVE = new File(FILE_2);}
      else if (input == 3) {SAVE = new File(FILE_3);}
      else {}
      
   }

//*****************************************************************************

    public static void setSystemFile() {
        File SYSTEM = new File(SYSTEM_FILE);
    }

//*****************************************************************************

    public static void readSystemFile() throws IOException {
        String line = "";
        inputSystemFile = new Scanner(new File(SYSTEM_FILE));
        while (inputSystemFile.hasNext()) {
            System.out.println("Reading system file... ");
            line += inputSystemFile.nextLine() + "\n";
        }
        System.out.print(line);
        inputSystemFile.close();
    }

//*****************************************************************************

    public static void saveSystemFile(int level, String name, String role) throws IOException {
        inputSystemFile = new Scanner(new File(SYSTEM_FILE));
        String line = "Lv " + level + " " + name + " the " + role + " " + LocalTime.now(Clock.systemDefaultZone()) + "\n";
        while (inputSystemFile.hasNext()) {
            line += inputSystemFile.nextLine() + "\n";
        }
        System.out.print(line);

        inputSystemFile.close();

        systemDataFile = new FileWriter(SYSTEM_FILE);
        systemFile     = new PrintWriter(systemDataFile);
        System.out.println("Writing to system file... ");
        systemFile.write(line);
        systemFile.close();
    }
   
//*****************************************************************************

   public static void save() {
      outputFile.print("Name: "
//              fantasyPlayer.name
      );
   }
   
//*****************************************************************************

   public static void close() {
      inputFile.close();
      outputFile.close();
   }
   
//*****************************************************************************

}  // End save