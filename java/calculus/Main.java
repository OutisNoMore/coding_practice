package calculus;

import java.util.Scanner;

import vector.Vector2D;
import vector.Vector3D;

public class Main {
	public static void main(String args[]) {
		try (Scanner newMenu = new Scanner(System.in)){
			Vector2D my2D = new Vector2D(newMenu);
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
