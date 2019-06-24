#pragma once
#include "SudokuFrame.h"

class SudokuSolver
{
	SudokuFrame sudokuFrame;
	const int choices[BSize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool solve(int cell);
	bool isSafe(int value, int row, int col);
	bool isSafeRow(int value, int row);
	bool isSafeCol(int value, int col);
	bool isSafeBox(int value, int row, int col);
public:
	SudokuSolver();
	~SudokuSolver();
};
