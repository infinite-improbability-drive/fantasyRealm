import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class fantasyCommand {
    public static String command;
    private static ArrayList<String> commands;
    private static Scanner scan;

//*****************************************************************************

    public fantasyCommand() {
        commands = new ArrayList<String>();
        commands.add("Fight");
        commands.add(fantasyPlayer.ability);
        commands.add("Items");
        commands.add("Run");
        command = "";
        scan = new Scanner(System.in);
    }

//*****************************************************************************

    public static void act() {
        if (command.equals("Fight")) {
            System.out.println("You have chosen to [" + command + "].");
//            fantasyBattle.target();
        }
        else if (command.equals(fantasyPlayer.ability)) {
            System.out.println(
                    "You have chosen to check your [" + command + "].");
        }
        else if (command.equals("Items")) {
            System.out.println(
                    "You have chosen to check your [" + command + "].");
        }
        else if (command.equals("Run")) {
            System.out.println(
                    "You have chosen to [" + command + "].");
        }
//       return;
    }

//*****************************************************************************

    public static String get() {
        if (!commands.isEmpty()) {
            System.out.println("What will you do?-\n" + commands + ": ");
        }
        else {
            System.out.println("What will you do?: ");
        }
        command = scan.nextLine();
        if (((command.equals("Fight"))||(command.equals("fight"))||
            (command.equals("F"))||(command.equals("f")))) {
            command = "Fight";
        }
        else if (((command.equals(fantasyPlayer.ability))||
            (command.equals(fantasyPlayer.ability.substring(0, 1)))||
            (command.equals(fantasyPlayer.ability.substring(0, 1)
                .toLowerCase()))||
            (command.equals(fantasyPlayer.ability.toUpperCase())))) {
            command = fantasyPlayer.ability;
        }
        else if (((command.equals("Items"))||(command.equals("items"))||
            (command.equals("I"))||(command.equals("i")))) {
            command = "Items";
        }
        else if (((command.equals("Run"))||(command.equals("run"))||
            (command.equals("R"))||(command.equals("r")))) {
            command = "Run";
        }
        else {
            System.out.println("You try to " + command + ", but it doesn't " +
                "work. Try something else. ");
            get();
        }
        return command;
    }

//*****************************************************************************

    public static String command() {
        return command;
    }

//*****************************************************************************   

}  // End fantasyCommand
