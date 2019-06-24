#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "SudokuFrame.h"
#define RED 4
#define DEFAULT 7


SudokuFrame::SudokuFrame()
{
	menu();
}

void SudokuFrame::menu()
{
	std::cout << "\n======================\n";
	std::cout << "    Sudoku Solver\n";
	std::cout << "======================\n\n";

	std::cout << "Welcome to Sudoku Solver!\n\n";
	std::cout << "Please provide sudoku board by either:-\n";
	std::cout << "\t1. Input the values manually in the console. (Enter 1)\n";
	std::cout << "\t2. Provide a text file with values. (Enter 2)\n";
	std::cout << "\t   The file must not have a name more than 20 characters.\n";
	std::cout << "\t   The file must be in the same directory as this C++ file.\n";
	std::cout << "\t   The file must have all the values seperated with spaces.\n";
	std::cout << "\t   Blank cells must be filled in as 0.\n";
	std::cout << "\t   --> ";

	int option;

	while (true) {

		std::cin >> option;

		if (option == 1) readFrameValues();
		else if (option == 2) readFrameValuesFile();
		else
		{
			std::cout << "\nPlease enter options 1 or 2.\n";
			std::cout << "\t   --> ";
			continue;
		}

		break;
	}
}

void SudokuFrame::readFrameValues()
{
	std::cout << "Enter the values row-wise.\n";
	std::cout << "Enter 0 for empty cell.\n";
	int rowIter, colIter;
	for (rowIter = 0; rowIter < BSize; rowIter++)
	{
		std::cout << "Enter values for row " << rowIter + 1 << ":\n";
		for (colIter = 0; colIter < BSize; colIter++)
		{
			while (true)
			{
				int enteredValue;
				std::cin >> enteredValue;
				if (isValid(enteredValue))
				{
					sudokuFrame[rowIter][colIter] = enteredValue;
					break;
				}
				else
				{
					std::cout << "Looks like last entered value was incorrect. Please try entering values between 0-9\n";
					continue;
				}
			}

			if (sudokuFrame[rowIter][colIter] == 0) color[rowIter][colIter] = 0;
			else color[rowIter][colIter] = 1;
		}
	}
}

void SudokuFrame::readFrameValuesFile()
{
	char filename[30];

	std::cout << "\nEnter the name of the file that contains the Sudoku Puzzle.\n";
	std::cout << "\t   --> ";
	std::cin >> filename;

	std::ifstream sudokuFile;
	sudokuFile.open(filename, std::ios::in);

	int rowIter, colIter;

	for (rowIter = 0; rowIter < BSize; rowIter++)
	{
		for (colIter = 0; colIter < BSize; colIter++)
		{
			int readValue;

			sudokuFile >> readValue;

			if (!isValid(readValue))
			{
				std::cout << "\nValue " << ((rowIter * 9) + colIter + 1) << " in " << filename;
				std::cout << " seems to be wrong! Correct the value and try again!\n";
				exit(EXIT_FAILURE);
			}

			sudokuFrame[rowIter][colIter] = readValue;

			if (sudokuFrame[rowIter][colIter] == 0) color[rowIter][colIter] = 0;
			else color[rowIter][colIter] = 1;

			if (sudokuFile.eof()) break;
		}
	}

	sudokuFile.close();
}

bool SudokuFrame::isValid(int value)
{
	return (value >= 0 && value <= 9);
}

void SudokuFrame::setCellValue(int row, int col, int value)
{
	if (color[row][col] == 0)
		sudokuFrame[row][col] = value;
}

int SudokuFrame::getCellValue(int row, int col)
{
	if (isValid(row) && isValid(col))
		return sudokuFrame[row][col];
}

void SudokuFrame::displayFrame()
{
	for (int rowIter = 0; rowIter < BSize; rowIter++)
	{
		for (int colIter = 0; colIter < BSize; colIter++)
		{
			if (color[rowIter][colIter] == 0)
			{
				setColor(RED);
				std::cout << sudokuFrame[rowIter][colIter] << " ";
				setColor(DEFAULT);
			}
			else std::cout << sudokuFrame[rowIter][colIter] << " ";
			if (colIter % 3 == 2) std::cout << "| ";
		}
		std::cout << "\n";
		if (rowIter % 3 == 2) std::cout << "------+-------+---------\n";

	}
}

void SudokuFrame::setColor(unsigned int color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

SudokuFrame::~SudokuFrame()
{
}
