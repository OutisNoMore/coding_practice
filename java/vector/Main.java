import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		try (Scanner newMenu = new Scanner(System.in)){
			Vector my2D = new Vector(newMenu);
			Vector3D my3D = new Vector3D(newMenu);
			
			my2D.menu();
			System.out.println();
			my3D.menu();
		}
		catch(NumberFormatException e) {
			System.out.println("Invalid input!");
		}
	}
}
