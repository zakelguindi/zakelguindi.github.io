import java.util.Scanner;

public class App {
  public static Scanner keyboard = new Scanner(System.in); 
    public static void main(String[] args) throws Exception {
        System.out.println("i took my aderall this morning");
        int aderall = 0; 
        System.out.println("How many aderall things did you take this morning"); 
        aderall = keyboard.nextInt(); 
        if(aderall > 1) {
          System.out.println("Jesus fucking christ"); 
        } else {
          System.out.println("nice");
        }
    }
}
