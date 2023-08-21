
    #include"Table.h"



    void Table::adjustSquareSize(){
        counter=0;

         squareSize = (float) cellSize;

         totalWidth = (float) tableCol * squareSize;
         totalHeight = (float) tableRow * squareSize;

   const float maxWidth=GetScreenWidth()*0.75;//75% of the screen (750)in my case
   const float maxHeight=GetScreenHeight()*0.75;

    int i=0;
        while (totalWidth > maxWidth  || totalHeight > maxHeight  ) {

         squareSize -=  (++i)/cellSize ;
        

         //recalculating and assigning the new width and height
         totalWidth = tableCol * squareSize;
         totalHeight = tableRow * squareSize;
    counter++;
        }
        std::cout<<"counter "<<counter<<'\n';

    counter=0;
    i=0;


        while (totalWidth < maxWidth  && totalHeight < maxHeight  ) {//increase size until both width and height achived

         squareSize +=  (++i)/cellSize ;
         

         totalWidth = tableCol * squareSize;
         totalHeight = tableRow * squareSize;
    counter++;
        }
        std::cout<<"counter "<<counter<<'\n';

      }



    Table::Table() {
    //standart chess table///
    tableRow = 8;
    tableCol = 8;

    adjustSquareSize();

    }

  Table::Table(int row,int col){

   tableRow=row;
   tableCol=col;

  adjustSquareSize();
  }

void Table::setRowCol(int row,int col){
    tableCol=col;
    tableRow=row;

    adjustSquareSize();
}
void Table::init_cells(){
 // Calculate the starting position to center the grid on the screen
      float startX = (float)(GetScreenWidth() - totalWidth) / 2.0f;
      float startY = (float)(GetScreenHeight() - totalHeight) / 2.0f;

       for (int row = 0; row < tableRow; ++row) {
         for (int col = 0; col < tableCol; ++col) {

              Cell cell;
                cell.position = Vector2{startX + (col * squareSize),startY+ (row * squareSize) };
                cell.size = Vector2{ squareSize, squareSize };
            if ((row + col) % 2 == 0) {
               cell.color=BLUE;
            } else {
               cell.color=darkGreen;
            }
                cells.push_back(cell); // Add the cell to the vector

            // float x = (float) startX + col * squareSize;
            // float y = (float) startY + row * squareSize;
            // if ((row + col) % 2 == 0) {
            //    DrawRectangle(x, y, squareSize, squareSize, BLUE);
            // } else {
            //    DrawRectangle(x, y, squareSize, squareSize, darkGreen);
            // }
         }
      }

}
   void Table::drawBoard() {


for (const Cell& cell : cells) {

  DrawRectangle(cell.position.x,cell.position.y, cell.size.x,cell.size.y, cell.color);


    }
      // // Calculate the starting position to center the grid on the screen
      // float startX = (float)(GetScreenWidth() - totalWidth) / 2.0f;
      // float startY = (float)(GetScreenHeight() - totalHeight) / 2.0f;

      // Drawing
      // for (int row = 0; row < tableRow; ++row) {
      //    for (int col = 0; col < tableCol; ++col) {

              // Cell cell;
              //   cell.position = Vector2{startX + (col * squareSize),startY+ (row * squareSize) };
              //   cell.size = Vector2{ squareSize, squareSize };

              //   cells.push_back(cell); // Add the cell to the vector

            // float x = (float) startX + col * squareSize;
            // float y = (float) startY + row * squareSize;
            // if ((row + col) % 2 == 0) {
            //    DrawRectangle(x, y, squareSize, squareSize, BLUE);
            // } else {
            //    DrawRectangle(x, y, squareSize, squareSize, darkGreen);
      //       // }
      //    }
      // }

   }


