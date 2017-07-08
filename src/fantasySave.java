import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class fantasySave {
   static final String FILE_1 = "fantasySave_File_01.txt";    
   static final String FILE_2 = "fantasySave_File_02.txt";    
   static final String FILE_3 = "fantasySave_File_03.txt";    
   static final String SYSTEM_DATA = "fantasySave_File_System.txt";    
   static String FILE;
   static String line;

   static File inputDataFile;
   static Scanner inputFile;
   static FileWriter outputDataFile;
   static PrintWriter outputFile;
   static File inputSystemDataFile;
   static Scanner inputSystemFile;
   static FileWriter systemDataFile;
   static PrintWriter systemFile;
   static Scanner scan = new Scanner(System.in);

//*****************************************************************************

   public fantasySave() throws IOException {
      
//       final String FILE_1 = "fantasySave_file_01.txt";    
//       final String FILE_2 = "fantasySave_file_02.txt";    
//       final String FILE_3 = "fantasySave_file_03.txt";    
//       final String SYSTEM_DATA = "fantasySave_file_System.txt";    

      FILE = "";
      line = "";
      set();
      inputDataFile  = new File(FILE);
      inputFile      = new Scanner(inputDataFile);
      outputDataFile = new FileWriter(FILE);
      outputFile     = new PrintWriter(outputDataFile);
      
      systemDataFile = new FileWriter(SYSTEM_DATA);
      systemFile     = new PrintWriter(systemDataFile);
      
//       read();
   }

//*****************************************************************************

   public static String read() throws IOException {
      String line = "";
      inputSystemDataFile  = new File(SYSTEM_DATA);
      inputSystemFile      = new Scanner(inputSystemDataFile);
      while (inputSystemFile.hasNext()) {
         System.out.println("Reading system file... ");
         line += inputSystemFile.nextLine() + "\n";
      }
      System.out.print(line);
      inputSystemFile.close();
      return line;
   }

//*****************************************************************************

   public static void load() {}

//*****************************************************************************

   public static void set() {
      System.out.println("Please choose your file: ");
      int input = scan.nextInt();
      if (input == 1) {FILE = FILE_1;}
      else if (input == 2) {FILE = FILE_2;}
      else if (input == 2) {FILE = FILE_2;}
      else {}
      
   }

//*****************************************************************************

   public static void system() {
      systemFile.println(line);
//      systemFile.print("Name: " + fantasyPlayer.name);
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