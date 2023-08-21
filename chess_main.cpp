

#include <iostream>

#include<String>

#include<memory>

 ////game headers/////
#define RAYGUI_IMPLEMENTATION 
#include<raygui.h>//must add; even if your not using it, (for macro redefinition issue).

#include <raylib.h>

#include"Table.h"

#include"Button.h"

#include"UISTATE.h"

#include"HelperFunction.h"

using std::min;

const Color green = {
   173,
   204,
   96,
   255
};
const Color darkGreen = {
   43,
   51,
   24,
   255
};

int cellSize = 10;
const int cellCount = 12;

const std::string Title = "CHESS ENJOYER";



int main() {

   const char * titleCStr = getString(Title);

   const int screenWidth = 1000;
   const int screenHeight = 1000;

   InitWindow(screenWidth, screenHeight, titleCStr);

   // Calculate the appropriate cell size based on the screen dimensions and cell count
   cellSize = min(screenWidth / cellCount, screenHeight / cellCount);

   std::cout << "cellSize " << cellSize;

   SetWindowPosition(250, 100);

   SetTargetFPS(60);

   int textWidth = MeasureText(titleCStr, 40); //game title
   int x = screenWidth / 2 - (textWidth / 2);


//////////////////Gui intitilization//////////

//////Start button property////
   const float startButtonWidth = 150;
   const float startButtonHeight = 70;

   Vector2 bSize;
   Vector2 bPosition;

   bPosition.x = (float) GetScreenWidth() / 2 - (startButtonWidth / 2.0f);
   bPosition.y = (float) GetScreenHeight() / 3 - (startButtonHeight / 2.0f);

   bSize.x = startButtonWidth;
   bSize.y = startButtonHeight;

   Button startButton("play game", bSize, bPosition);

////////End start button ////////

////End Gui intitilization//////////



/////////////game initialization/////////

   UISTATE ui_state = MENU;

int tableWidth=3,tableHeight=3;

   Table table(tableWidth,tableHeight);

   float squareSize=table.getSquareSize();

  std::cout << "squareSize " << squareSize<<'\n';

   float totalWidth,totalHeight;

   totalWidth= (float)squareSize*tableWidth;
   totalHeight=(float)squareSize*tableHeight;

   std::cout << "totalWidth " << totalWidth<<'\n';
   std::cout << "totalHeight " << totalHeight<<'\n';

   table.setRowCol(8,8);
   table.init_cells();
///End Game initialization////


///////game loop////////
   while (!WindowShouldClose()) {


      BeginDrawing();

      ClearBackground(BLACK);
//////// UI Update ////////
      if (ui_state == MENU)//will draw a rectangle thats not rounded if nothing is rendered beneath it e.g(chess table)
         startButton.update();//activate listner if button clicked or not 

      // Handle button if clicked
      if (startButton.isButtonClicked()) {
         startButton.buttonClicked = true;//mark button as clicked///
         ui_state = GAME;
      }

////// Drawing ////////

      table.drawBoard();


      // Draw the button if it's not clicked
      if (ui_state != GAME) 
         startButton.draw();
      

      DrawText(titleCStr, x, 80, 40, WHITE);//draw Title

      DrawFPS(10, 10);
      EndDrawing();

   }

   CloseWindow();
   return 0;
}


