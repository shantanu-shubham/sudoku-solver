// SudokuSolver.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "SudokuSolver.h"


int main()
{
	SudokuSolver solver;
	return 0;
}

SudokuSolver::SudokuSolver()
{
	std::cout << "\nCalculating possibilities...\n";
	std::cout << "Backtracking across puzzle....\n";
	std::cout << "Validating cells and values...\n\n";

	solve(0);
	std::cout << "Your puzzle has been solved!\n\n";
	sudokuFrame.displayFrame();

	std::cout << "\n\n";
}

bool SudokuSolver::solve(int cell)
{
	if (cell == BSize * BSize) return true;

	int row = cell / BSize;
	int col = cell % BSize;

	if (sudokuFrame.getCellValue(row, col) != 0) return solve(cell + 1);

	for (int i = 0; i < BSize; i++)
	{
		int value = choices[i];
		if (isSafe(value, row, col))
		{
			sudokuFrame.setCellValue(row, col, value);
			if (solve(cell + 1)) return true;
			sudokuFrame.setCellValue(row, col, 0);
		}
	}
	return false;
}

bool SudokuSolver::isSafe(int value, int row, int col)
{
	return (isSafeRow(value, row) && isSafeCol(value, col) && isSafeBox(value, row, col));
}

bool SudokuSolver::isSafeRow(int value, int row)
{
	for (int col = 0; col < BSize; col++)
	{
		if (sudokuFrame.getCellValue(row, col) == value) return false;
	}
	return true;
}

bool SudokuSolver::isSafeCol(int value, int col)
{
	for (int row = 0; row < BSize; row++)
	{
		if (sudokuFrame.getCellValue(row, col) == value) return false;
	}
	return true;
}

bool SudokuSolver::isSafeBox(int value, int row, int col)
{
	int startRow = row - row % 3;
	int startCol = col - col % 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (sudokuFrame.getCellValue(startRow + i, startCol + j) == value) return false;
		}
	}
	return true;
}

SudokuSolver::~SudokuSolver()
{
}
