//operations on 2 dimensional vectors
package vector;

import java.util.Scanner;

public class Vector {
	protected double x1 = -1;
	protected double y1 = -1;
	protected double x2 = -1;
	protected double y2 = -1;
	private Scanner menu;
	
	public Vector(Scanner newScanner) {
		menu = newScanner;
	}
	
	public void menu() {
		int option = 0;
		System.out.println("Welcome to the vector calculator!");
		System.out.println("Here are your options:");
		System.out.println("1. Magnitude");
		System.out.println("2. Dot product");
		System.out.println("3. Addition");
		System.out.println("4. Subtraction");
		System.out.println("5. Multiplication");
		System.out.println("6. Distance between points");
		System.out.println("7. Unit vector");
		System.out.print("What will it be? ");
		option = Integer.parseInt(menu.nextLine());
		
		if(option == 1 || option == 7){
			getVector(menu);	
		}else{
			getVectors(menu);	
		}
		
		System.out.println();
		switch(option) {
		case 1:
			getMagnitude();
			System.out.println("Magnitude of vector is: " + getMagnitude());
			break;
		case 2:
			System.out.println("Dot product of vectors is: " + getDotProduct());
			break;
		case 3: 
			System.out.println("Sum of both vectors is: " + getSum());
			break;
		case 4: 
			System.out.println("Difference of vector 2 and vector 1 is: " + getDifference());
			break;
		case 5:
			System.out.println("The product of Vector 1 and Vector 2 is: " + getProduct());
			break;
		case 6:
			System.out.println("The distance between point 1 and point 2 is: " + getDistance());
			break;
		case 7:
			System.out.println("The unit vector of: " + this + " is " + getUnitVector());
			break;
		default:
			System.out.println("Not a valid option, please try again");
			break;
		}
	}

	protected double getMagnitude() {
		return Math.sqrt(x1*x1 + y1*y1);
	}
	
	protected double getDotProduct() {
		return x1*x2 + y1*y2;
	}
	
	protected String getSum() {
		double x = x1 + x2;
		double y = y1 + y2;
		return "<" + x + "," + y + ">"; 
	}
	
	protected String getDifference() {
		double x = x2-x1;
		double y = y2 - y1;
		return "<" + x + "," + y + ">";
	}
	
	protected String getProduct() {
		double x = x1 * x2;
		double y = y1 * y2;
		return "<" + x + "," + y + ">";
	}
	
	protected double getDistance() {
		return Math.sqrt(Math.pow((x2-x1),2) + Math.pow((y2 - y1),2));
	}
	
	protected String getUnitVector() {
		double x = getMagnitude()*x1;
		double y = getMagnitude()*y1;
		return "<" + x + "," + y + ">";
	}
	
	protected void getVector(Scanner s){
		System.out.print("Vector 1 X: ");
		x1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Y: ");
		y1 = Double.parseDouble(s.nextLine());
	}
	
	protected void getVectors(Scanner s){
		System.out.print("Vector 1 X: ");
		x1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Y: ");
		y1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 2 X: ");
		x2 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 2 Y: ");
		y2 = Double.parseDouble(s.nextLine());
	}

	@Override
	public String toString(){
		return "<" + x1 + ", " + y1 + ">";
	}
}
