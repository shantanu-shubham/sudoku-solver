#pragma once
#define BSize 9		//board size
class SudokuFrame
{
	int sudokuFrame[BSize][BSize];
	bool color[BSize][BSize];
	void menu();
	void readFrameValues();
	void readFrameValuesFile();
	bool isValid(int value);
	void setColor(unsigned int color);
public:
	SudokuFrame();
	void setCellValue(int row, int col, int value);
	int getCellValue(int row, int col);
	void displayFrame();
	~SudokuFrame();
};

