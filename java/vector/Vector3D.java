//operations on 3 dimensional vectors
package vector;

import java.util.Scanner;

public class Vector3D {
	private double x1 = -1;
	private double y1 = -1;
	private double z1 = -1;
	private double x2 = -1;
	private double y2 = -1;
	private double z2 = -1;
	private Scanner menu;
	
	public Vector3D(Scanner newScanner) {
		menu = newScanner;
	}
	
	public void menu() {
		int option = 0;
		System.out.println("Welcome to the 3D vector calculator!");
		System.out.println("Here are your options:");
		System.out.println("1. Magnitude");
		System.out.println("2. Dot product");
		System.out.println("3. Addition");
		System.out.println("4. Subtraction");
		System.out.println("5. Multiplication");
		System.out.println("6. Distance between the points");
		System.out.println("7. Unit vector");
		System.out.print("What will it be? ");
		//Scanner menu = new Scanner(System.in);
		option = Integer.parseInt(menu.nextLine());	
			switch(option){
			case 1:
				getVector(menu);
				System.out.println("Magnitude of vector is: " + getMagnitude());
				break;
			case 2:
				getVectors(menu);
				System.out.println("Dot product of vectors is: " + getDotProduct());
				break;
			case 3: 
				getVectors(menu);
				System.out.println("Sum of both vectors is: " + getSum());
				break;
			case 4: 
				getVectors(menu);
				System.out.println("Difference of vector 2 and vector 1 is: " + getDifference());
				break;
			case 5:
				getVectors(menu);
				System.out.println("The product of Vector 1 and Vector 2 is: " + getProduct());
				break;
			case 6:
				getVectors(menu);
				System.out.println("The distance between the two points is: " + getDistance());
				break;
			case 7:
				getVector(menu);
				System.out.println("The unit vector of: " + "<" + x1 + "," + y1 + "," + z1 + "> " + "is " + getUnitVector());
				break;
			default:
				System.out.println("Not a valid option, please try again");
				break;
			}
	}
	
	public double getMagnitude() {
		return Math.sqrt(x1*x1 + y1*y1 + z1*z1);
	}
	
	public double getDotProduct() {
		return x1*x2 + y1*y2 + z1*z2;
	}
	
	public String getSum() {
		double x = x1 + x2;
		double y = y1 + y2;
		double z = z1 + z2;
		return "<" + x + "," + y + "," + z + ">"; 
	}
	
	public String getDifference() {
		double x = x2 - x1;
		double y = y2 - y1;
		double z = z2 - z1;
		return "<" + x + "," + y + "," + z + ">";
	}
	
	public String getProduct() {
		double x = x1 * x2;
		double y = y1 * y2;
		double z = z1 * z2;
		return "<" + x + "," + y + "," + z + ">";
	}
	
	public double getDistance() {
		return Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2) + Math.pow(z2-z1, 2));
	}
	
	public String getUnitVector() {
		double x = getMagnitude()*x1;
		double y = getMagnitude()*y1;
		double z = getMagnitude()*z1;
		return "<" + x + "," + y + "," + z + ">";
	}
	
	public void getVector(Scanner s) {
		System.out.print("Vector 1 X: ");
		x1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Y: ");
		y1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Z: ");
		z1 = Double.parseDouble(s.nextLine());
	}
	
	public void getVectors(Scanner s) {
		System.out.print("Vector 1 X: ");
		x1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Y: ");
		y1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Z: ");
		z1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 2 X: ");
		x2 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 2 Y: ");
		y2 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 2 Z: ");
		z2 = Double.parseDouble(s.nextLine());
	}
}
