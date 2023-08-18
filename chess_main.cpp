#include <iostream>

#include<String>

#include<memory>
 ////game headers/////
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>


//////////////Sublime_Build//////////////////
// {
//     "cmd": ["gcc", "-o", "$file_base_name", "$file" ,
//      "-Iraylib-4.5.0_win64_mingw-w64/include","-Lraylib-4.5.0_win64_mingw-w64/lib",
//      "-lraylib", "-lopengl32", "-lgdi32", "-lwinmm", "-lstdc++",
//         "-Wno-enum-compare" ],

//     "working_dir": "$file_path",
//     "selector": "source.cpp",
//     "shell": true,

//     "variants": [
//         {
//             "name": "Run",
//             "cmd": ["start", "cmd", "/k", "$file_base_name"]
//         }
//     ]
// }
////////////////////

// Add this line to include the thread library
using namespace std;

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

const char * getString(const std::string title) {
   const char * titleCStr = title.c_str();
   return titleCStr;
}

class Table {

   int tableRow ;
   int tableCol ;
   // Drawing
   // Calculate the total width and height of the grid
   float totalWidth;
   float totalHeight;

   float newCellSize;
   public:
      Table() {
    //standart chess table///
    tableRow = 8;
    tableCol = 8;

         newCellSize = (float) cellSize;

         totalWidth = (float) tableCol * newCellSize;
         totalHeight = (float) tableRow * newCellSize;

      }

   void drawBoard() {
      // Check if the animation is up or down based on countBackground value
      // if(!flagPause)

      while (totalWidth > GetScreenWidth() - newCellSize || totalHeight > GetScreenHeight() - newCellSize) {

         newCellSize -= cellSize / 15;
         totalWidth = tableCol * newCellSize;
         totalHeight = tableRow * newCellSize;

      }

      // Calculate the starting position to center the grid on the screen
      float startX = (float)(GetScreenWidth() - totalWidth) / 2.0f;
      float startY = (float)(GetScreenHeight() - totalHeight) / 2.0f;

      // Drawing
      for (int row = 0; row < tableRow; ++row) {
         for (int col = 0; col < tableCol; ++col) {
            float x = (float) startX + col * newCellSize;
            float y = (float) startY + row * newCellSize;
            if ((row + col) % 2 == 0) {
               DrawRectangle(x, y, newCellSize, newCellSize, BLUE);
            } else {
               DrawRectangle(x, y, newCellSize, newCellSize, darkGreen);
            }
         }
      }

   }

};

typedef enum UISTATE {
   MENU,
   GAME,
   SETTEING
}
UISTATE;

class Button {
   private: Rectangle buttonRec;

   public: float buttonWidth = 150;
   float buttonHeight = 70;

   bool buttonClicked = false;

   string title;

   Button(const string Btitle, Vector2 size, Vector2 pos) {

      title = Btitle;

      buttonRec = {
         pos.x,
         pos.y,
         size.x,
         size.y
      };

      update();

   }

   Button(const string bTitle) {

      buttonRec = {
         (float) GetScreenWidth() / 2 - (buttonWidth / 2.0f),
         (float) GetScreenHeight() / 2 - (buttonHeight / 2.0f),
         buttonWidth,
         buttonHeight
      };

      title = bTitle;

      update();

   }

   void draw() {
      // Calculate text position to center it within the rectangle
      int textWidth = MeasureText(getString(title), 20);
      int textHeight = 20;
      int textX = buttonRec.x + (buttonRec.width - textWidth) / 2;
      int textY = buttonRec.y + (buttonRec.height - textHeight) / 2;
      DrawRectangleRounded(buttonRec, 0.2, 0, DARKGRAY);
      DrawText(getString(title), textX, textY, 20, RAYWHITE);
   }

   void update() {
      buttonClicked = GuiButton(buttonRec, getString(title));
   }

   bool isButtonClicked() {
      return buttonClicked;
   }

};

int main() {

   const char * titleCStr = getString(Title);

   const int screenWidth = 1000;
   const int screenHeight = 1000;

   InitWindow(screenWidth, screenHeight, "Chess Enjoyer");

   // Calculate the appropriate cell size based on the screen dimensions and cell count
   cellSize = min(screenWidth / cellCount, screenHeight / cellCount);

   std::cout << "cellSize " << cellSize;
   SetWindowPosition(250, 100);
   // layout_name: controls initialization
   //----------------------------------------------------------------------------------

   //----------------------------------------------------------------------------------
   SetTargetFPS(60);

   int textWidth = MeasureText(titleCStr, 40); //game title
   int x = screenWidth / 2 - (textWidth / 2);

   const float buttonWidth = 150;
   const float buttonHeight = 70;

   Vector2 bSize;
   Vector2 bPosition;

   bPosition.x = (float) GetScreenWidth() / 2 - (buttonWidth / 2.0f);
   bPosition.y = (float) GetScreenHeight() / 2 - (buttonHeight / 2.0f);

   bSize.x = buttonWidth;
   bSize.y = buttonHeight;

   Button startButton("play game", bSize, bPosition);

   UISTATE ui_state = MENU;

   Table table;
   ///game loop////
   while (!WindowShouldClose()) {

      // if(!buttonClicked)
      if (ui_state == MENU)
         startButton.update();
      // buttonClicked = GuiButton(buttonRec, "Start game");

      BeginDrawing();

      ClearBackground(BLACK);
      // Update

      if (IsKeyDown(KEY_Q)) {
         // running = false;
      }
      ////Reatart game///////
      else if (IsKeyDown(KEY_R)) {

         // running = false;

      }

      table.drawBoard();

      // Handle button click without drawing the button
      if (startButton.isButtonClicked()) {
         startButton.buttonClicked = true;
         ui_state = GAME;
         // Your code here to respond to the button click
      }

      // Draw the button background if it was not clicked
      if (!startButton.isButtonClicked()) {
         startButton.draw();
      }

      DrawText(titleCStr, x, 80, 40, WHITE);

      DrawFPS(10, 10);
      EndDrawing();

   }

   CloseWindow();
   return 0;
}