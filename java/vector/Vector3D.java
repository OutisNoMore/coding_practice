//operations on 3 dimensional vecto
package vector;

import java.util.Scanner;

public class Vector3D extends Vector {
	private double z1 = -1;
	private double z2 = -1;
	
	public Vector3D(Scanner newScanner) {
		super(newScanner);
	}
	
	protected void getVector(Scanner s) {
		System.out.print("Vector 1 X: ");
		x1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Y: ");
		y1 = Double.parseDouble(s.nextLine());
		System.out.print("Vector 1 Z: ");
		z1 = Double.parseDouble(s.nextLine());
	}
	
	protected void getVectors(Scanner s) {
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

	protected double getMagnitude() {
		return Math.sqrt(x1*x1 + y1*y1 + z1*z1);
	}
	
	protected double getDotProduct() {
		return x1*x2 + y1*y2 + z1*z2;
	}
	
	protected String getSum() {
		double x = x1 + x2;
		double y = y1 + y2;
		double z = z1 + z2;
		return "<" + x + "," + y + "," + z + ">"; 
	}
	
	protected String getDifference() {
		double x = x2 - x1;
		double y = y2 - y1;
		double z = z2 - z1;
		return "<" + x + "," + y + "," + z + ">";
	}
	
	protected String getProduct() {
		double x = x1 * x2;
		double y = y1 * y2;
		double z = z1 * z2;
		return "<" + x + "," + y + "," + z + ">";
	}
	
	protected double getDistance() {
		return Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2) + Math.pow(z2-z1, 2));
	}
	
	protected String getUnitVector() {
		double x = getMagnitude()*x1;
		double y = getMagnitude()*y1;
		double z = getMagnitude()*z1;
		return "<" + x + "," + y + "," + z + ">";
	}

	@Override
	public String toString(){
		return "<" + x1 + ", " + y1 + ", " + z1 + ">";
	}
}
