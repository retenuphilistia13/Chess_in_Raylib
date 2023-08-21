#ifndef TABLE_H
#define TABLE_H


// #include "raygui.h"

#include"raylib.h"

#include<iostream>

#include<vector>

using std::cout;
using std::vector;
extern const Color darkGreen;
extern int cellSize;


struct Cell{

Vector2 position;

Vector2 size;

 Color color;
};

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

vector<Cell> cells;

void adjustSquareSize();
 

   public:
void init_cells();
float getSquareSize(){
	return squareSize;
}

Table(int row,int col);
Table();

void setRowCol(int row,int col);

void drawBoard();

};
#endif