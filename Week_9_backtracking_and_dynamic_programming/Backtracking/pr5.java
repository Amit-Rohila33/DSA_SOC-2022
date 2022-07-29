// Backtracking – N Queens Problem



// Objective: In chess, a queen can move as far as she pleases, horizontally, vertically, or diagonally. A chess board has 8 rows and 8 columns. The standard 8 by 8 Queen’s problem asks how to place 8 queens on an ordinary chess board so that none of them can hit any other in one move.





/* Algorithm:

Place the queen’s column wise, starting from the left most column
If all queens are placed.
return true and print the solution matrix.
Else
Try all the rows in the current column.
Check if the queen can be placed here safely if yes mark the current cell in the solution matrix as 1 and try to solve the rest of the problem recursively.
If placing the queen in the above step leads to the solution returning true.
If placing the queen in the above step does not lead to the solution, BACKTRACK, mark the current cell in the solution matrix as 0 and return false.
If all the rows are tried and nothing worked, return false and print NO SOLUTION. */





// The code for the above problem is as follows:-



public class NQueensBT {
	public int[][] solution;

	public NQueensBT(int N) {
		solution = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				solution[i][j] = 0;
			}
		}
	}

	public void solve(int N) {
		if(placeQueens(0, N)){
			//print the result
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(" " + solution[i][j]);
				}
				System.out.println();
			}
		}else{
			System.out.println("NO SOLUTION EXISTS");
		}
	}

	public boolean placeQueens(int queen, int N) {
		// will place the Queens one at a time, for column wise
		if(queen==N){
			//if we are here that means we have solved the problem
			return true;
		}
		for (int row = 0; row < N; row++) {
			// check if queen can be placed row,col
			if (canPlace(solution, row, queen)) {
				// place the queen
				solution[row][queen] = 1;
				// solve  for next queen
				if(placeQueens(queen+1, N)){
					return true;
				}
				//if we are here that means above placement didn't work
				//BACKTRACK
				solution[row][queen]=0;
			}
		}
		//if we are here that means we haven't found solution
		return false;

	}

	// check if queen can be placed at matrix[row][column]
	public boolean canPlace(int[][] matrix, int row, int column) {
		// since we are filling one column at a time,
		// we will check if no queen is placed in that particular row
		for (int i = 0; i < column; i++) {
			if (matrix[row][i] == 1) {
				return false;
			}
		}
		// we are filling one column at a time,so we need to check the upper and
		// diagonal as well
		// check upper diagonal
		for (int i = row, j = column; i >= 0 && j >= 0; i--, j--) {
			if (matrix[i][j] == 1) {
				return false;
			}
		}

		// check lower diagonal
		for (int i = row, j = column; i < matrix.length && j >= 0; i++, j--) {
			if (matrix[i][j] == 1) {
				return false;
			}
		}
		// if we are here that means we are safe to place Queen at row,column
		return true;
	}

	public static void main(String[] args) {
		int N = 4;
		NQueensBT q = new NQueensBT(N);
		q.solve(N);

	}

}
