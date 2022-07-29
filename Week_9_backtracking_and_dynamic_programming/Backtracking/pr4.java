// Backtracking – Rat In A Maze Puzzle



// Given a maze, NxN matrix. A rat has to find a path from source to destination. maze[0][0] (left top corner)is the source and maze[N-1][N-1](right bottom corner) is destination. There are a few cells that are blocked, which means the rat cannot enter those cells. The rat can move in any direction ( left, right, up, and down).



// Approach:

// 1). Create a solution matrix of the same structure as the maze.
// 2). Whenever the rat moves to a cell in a maze, mark that particular cell in the solution matrix.
// 3). At the end print the solution matrix, follow that 1’s from the top left corner, it will be that path for the rat.



/* Algorithm:

1). If the rat reaches the destination
        (i) print the solution matrix.
        (ii) Else
            (a) Mark the current cell in the solution matrix as 1
            (b) If the previous step is not in the vertical direction (upwards) then move forward in the vertical direction(downwards) and recursively check if this movement leads to the solution.
            (c) If movement in the above step doesn’t lead to the solution and If the previous step is not in the horizontal direction (towards the left) then move forward in the horizontal direction(towards the right) and recursively check if this movement leads to the solution.
2). If movement in the above step doesn’t lead to the solution and If the previous step is not in the vertical direction (downwards) then move forward in the horizontal direction(upwards) and recursively check if this movement leads to the solution.
3). If movement in the above step doesn’t lead to the solution and If the previous step is not in the horizontal direction (towards the right) then move forward in the horizontal direction(towards the left) and recursively check if this movement leads to the solution.
4). If none of the above solutions works then BACKTRACK and mark the current cell as 0. */




public class RatInMaze {

	public int[][] solution;

	//initialize the solution matrix in constructor.
	public RatInMaze(int N) {
		solution = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				solution[i][j] = 0;
			}
		}
	}

	public void solveMaze(int[][] maze, int N) {
		if (findPath(maze, 0, 0, N, "down")) {
			print(solution, N);
		}else{
			System.out.println("NO PATH FOUND");
		}
		
	}

	public boolean findPath(int[][] maze, int x, int y, int N, String direction) {
		// check if maze[x][y] is feasible to move
		if(x==N-1 && y==N-1){//we have reached
			solution[x][y] = 1;
			return true;
		}
		if (isSafeToGo(maze, x, y, N)) {
			// move to maze[x][y]
			solution[x][y] = 1;			
			// now rat has four options, either go right OR go down or left or go up
			if(direction!="up" && findPath(maze, x+1, y, N, "down")){ //go down
				return true;
			}
			if(direction!="left" && findPath(maze, x, y+1, N,"right")){ //go right
				return true;
			}
			if(direction!="down" && findPath(maze, x-1, y, N, "up")){ //go up
				return true;
			}
			if(direction!="right" &&  findPath(maze, x, y-1, N, "left")){ //go left
				return true;
			}
			//if none of the options work out BACKTRACK undo the move
			solution[x][y] = 0;
			return false;
		}
		return false;
	}

	// this function will check if mouse can move to this cell
	public boolean isSafeToGo(int[][] maze, int x, int y, int N) {
		// check if x and y are in limits and cell is not blocked
		if (x >= 0 && y >= 0 && x < N  && y < N && maze[x][y] != 0) {
			return true;
		}
		return false;
	}
	public void print(int [][] solution, int N){
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				System.out.print(" " + solution[i][j]);
			}
			System.out.println();
		}
	}
	public static void main(String[] args) {
		int N = 5;
		int[][] maze = { { 1, 0, 1, 1,1 }, { 1, 1, 1, 0,1 }, { 0, 0,0, 1, 1 },
				{ 0, 0, 0, 1,0 },{ 0, 0,0, 1, 1 } };
		RatInMaze r = new RatInMaze(N);
		r.solveMaze(maze, N);
	}

}