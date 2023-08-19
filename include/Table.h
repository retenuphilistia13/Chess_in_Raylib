#ifndef TABLE_H
#define TABLE_H


// #include "raygui.h"

#include"raylib.h"

#include<iostream>


using std::cout;

extern const Color darkGreen;
extern int cellSize;
class Table {

int counter;

   int tableRow ;
   int tableCol ;
   // Drawing
   // Calculate the total width and height of the grid
   float totalWidth;
   float totalHeight;

   float squareSize;

private:

      void adjustSquareSize();
 

   public:
float getSquareSize(){
	return squareSize;
}
Table(int row,int col);
Table();

void setRowCol(int row,int col);

void drawBoard();

};
#endif