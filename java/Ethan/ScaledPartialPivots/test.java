public class test{
	public static void Gauss(int rows, double[][] matrix, int[] index){
		int j = 0;
		double r = 0.0;
		double rmax = 0.0;
		double smax = 0.0;
		double xmult = 0.0;
		double[] scales = new double[rows];

		for(int i = 0; i < rows; i++){
			index[i] = i;
			smax = 0;
			for(j = 0; j < rows; j++){
				smax = Math.max(smax, Math.abs(matrix[i][j]));
			}
			scales[i] = smax;
		}

		for(int k = 0; k < rows-1; k++){
			rmax = 0;
			for(int i = k; i < rows; i++){
				r = Math.abs(matrix[index[i]][k] / scales[index[i]]);
				if(r > rmax){
					rmax = r;
					j = i;
				}
			}

			int temp = index[j];
			index[j] = index[k];
			index[k] = temp;
			System.out.println("Swapping row: " + (index[j] + 1) + " with row: " + (index[k] + 1));
			System.out.println("Scale: " + scales[index[j]]);

			for(int i = k + 1; i < rows; i++){
				xmult = matrix[index[i]][k] / matrix[index[k]][k];
				matrix[index[i]][k] = xmult;
				for(j = k + 1; j < rows; j++){
					matrix[index[i]][j] = matrix[index[i]][j] - xmult*matrix[index[k]][j];
				}
			printMatrix(index, matrix);
			}
		}
			printMatrix(index, matrix);
	}
	
	public static void Solve(int rows, double[][] matrix, int[] index, double[] eq, double[] solutions){
		double sum = 0.0;
		for(int k = 0; k < rows - 1; k++){
			for(int i = k + 1; i < rows; i++){
				eq[index[i]] = eq[index[i]] - matrix[index[i]][k] * eq[index[k]];
			}
		}

		solutions[rows - 1] = eq[index[rows-1]]/matrix[index[rows-1]][rows-1];
		for(int i = rows - 2; i >= 0; i--){
			sum = eq[index[i]];
			for(int j = i + 1; j < rows; j++){
				sum = sum - matrix[index[i]][j] * solutions[j];
			}
			solutions[i] = sum/matrix[index[i]][i];
		}
	}

	public static void printMatrix(int[] index, double[][] matrix){
		for(int i = 0; i < index.length; i++){
			for(int j = 0; j < matrix[i].length; j++){
				System.out.print(matrix[index[i]][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	public static void main(String[] args){
		double[][] system = {{2, 3, 0},
												 {-1, 2, -1},
												 {3, 0, 2}};
		double[] eq = {8, 0, 9};

		int[] index = new int[3];
		double[] solutions = {-999,-999,-999};

		Gauss(3, system, index);
		Solve(3, system, index, eq, solutions);

		for(int i = 0; i < 3; i++){
			System.out.println(solutions[i]);
		}
	}
}
