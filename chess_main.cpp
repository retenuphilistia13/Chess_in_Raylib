

#include <iostream>

#include<String>

#include<memory>
 ////game headers/////
#define RAYGUI_IMPLEMENTATION 
#include<raygui.h>//must add; even if your not using it, (for macro redefinition issue).

#include <raylib.h>

#include"Table.h"

#include"Button.h"


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

typedef enum UISTATE {
   MENU,
   GAME,
   SETTEING
}
UISTATE;


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



//////Start button property////
      const float buttonWidth = 150;
   const float buttonHeight = 70;

   Vector2 bSize;
   Vector2 bPosition;

   bPosition.x = (float) GetScreenWidth() / 2 - (buttonWidth / 2.0f);
   bPosition.y = (float) GetScreenHeight() / 2 - (buttonHeight / 2.0f);

   bSize.x = buttonWidth;
   bSize.y = buttonHeight;

   Button startButton("play game", bSize, bPosition);
////////////////


   UISTATE ui_state = MENU;

   Table table;

   // table.setRowCol(50,50);

   ///game loop////
   while (!WindowShouldClose()) {


      if (ui_state == MENU)
         startButton.update();//activate listner if button clicked or not 


      BeginDrawing();

      ClearBackground(BLACK);
      /// Update///


////drawing////
      table.drawBoard();

      // Handle button click without drawing the button
      if (startButton.isButtonClicked()) {
         startButton.buttonClicked = true;//mark button is clicked///
         ui_state = GAME;
      
      }

      // Draw the button if it was not clicked
      if (ui_state != GAME) {
         startButton.draw();
      }

      DrawText(titleCStr, x, 80, 40, WHITE);

      DrawFPS(10, 10);
      EndDrawing();

   }

   CloseWindow();
   return 0;
}

// ////////////Sublime_Build//////////////////
// {
//     "cmd": ["gcc", "-o", "$file_base_name", "$file" ,"Table.cpp","Button.cpp",
//      "-Iraylib-4.5.0_win64_mingw-w64/include","-Lraylib-4.5.0_win64_mingw-w64/lib","-Iinclude",
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

