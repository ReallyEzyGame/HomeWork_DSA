#include <iostream>
#define N 	8			// ChessBoard's size
 using namespace std;
 // Input: 8
 // Output: Number of solution: 92

 int board[N][N] = { 0 }; // Chessboard
 int solutions = 0;		// Count valid solutions

 // Function to check if a queen can be placed at board[row][col]
 bool isSafe(int row, int col)
 {
	 for (int i = 0; i < row; i++)
	 {
		 if (board[i][col] == 1)
			 return false; // Check column

		 if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
			 return false; // Check left diagonal

		 if (col + (row - i) < N && board[i][col + (row - i)] == 1)
			 return false; // Check right diagonal
	 }
	 return true;
 }

 // Backtracking function to place queens
 void solveNQueens(int row)
 {
	 if (row == N)
	 { // All queens placed successfully
		 ++solutions;
		 return;
	 }
	 for (int col = 0; col < N; col++)
	 {
		 if (isSafe(row, col))
		 {
			 board[row][col] = 1;		// Place queen
			 solveNQueens(row + 1);		// Recur for next row
			 board[row][col] = 0;		// Backtrack
		 }
	 }
 }

 // This is the Function use to solve the problem
 void N_Queens()
 {
	 int row = 0;
	 solveNQueens(row);
	 cout << "Number of solution: " << solutions << endl;
 }