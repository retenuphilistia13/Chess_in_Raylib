#include <iostream>

#include<String>

#include<memory>
////game headers/////
#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>



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

void drawBoard() {
    // Check if the animation is up or down based on countBackground value

    // if(!flagPause)

    
    // Drawing
    // Calculate the total width and height of the grid
    int totalWidth = 8 * cellSize;
    int totalHeight = 8 * cellSize;

    // Calculate the starting position to center the grid on the screen
    int startX = (GetScreenWidth() - totalWidth) / 2;
    int startY = (GetScreenHeight() - totalHeight) / 2;

    // Drawing
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            int x = startX + col * cellSize;
            int y = startY + row * cellSize;
            if ((row + col) % 2 == 0) {
                DrawRectangle(x, y, cellSize, cellSize, darkGreen);
            } else {
                DrawRectangle(x, y, cellSize, cellSize, BLUE);
            }
        }
    }
   //  std::cout << "backgroundState: " << backgroundStateToString(backgroundState) << std::endl;

      //  std::cout<<"countBackground: "<<countBackground<<std::endl;

}

typedef enum UISTATE{
   MENU,
   GAME,
   SETTEING
} UISTATE;


class Button{
private:
 Rectangle buttonRec;

public:
float buttonWidth=150;
float buttonHeight=70;

bool buttonClicked = false;

  string title="start game";
   Button(float width,float height,float x,float y){


   buttonRec = {
      x,
      y,
      width,
      height
   };

 title="start Game";

 update();

   }

   Button(const string bTitle){
 
    buttonRec = {
      (float) GetScreenWidth() / 2 -(buttonWidth/2.0f),
      (float) GetScreenHeight() / 2 -(buttonHeight/2.0f),
      buttonWidth,
      buttonHeight
   };

 title=bTitle;

 update();

}

   void draw(){
 // Calculate text position to center it within the rectangle
        int textWidth = MeasureText(getString(title), 20);
        int textHeight = 20;
        int textX = buttonRec.x + (buttonRec.width - textWidth) / 2;
        int textY = buttonRec.y + (buttonRec.height - textHeight) / 2;
        DrawRectangleRounded(buttonRec, 0.2, 0, DARKGRAY);
        DrawText(getString(title), textX, textY , 20, RAYWHITE);
   }

   void update(){
       buttonClicked = GuiButton(buttonRec, getString(title));
   }

bool isButtonClicked(){
   return buttonClicked;
}


};




int main() {

   const char * titleCStr = getString(Title);

  const int screenWidth = 800+200;
    const int screenHeight = 600+200;

    InitWindow(screenWidth, screenHeight, "Chess Enjoyer");

    // Calculate the appropriate cell size based on the screen dimensions and cell count
     cellSize = min(screenWidth / cellCount, screenHeight / cellCount);


std::cout<<"cellSize "<<cellSize;
   SetWindowPosition(250, 100);
   // layout_name: controls initialization
   //----------------------------------------------------------------------------------

   //----------------------------------------------------------------------------------
   SetTargetFPS(60);


   int textWidth = MeasureText(titleCStr, 40);
   int x = screenWidth / 2 - (textWidth / 2);


// float buttonWidth=150;
// float buttonHeight=70;
//    // Create a rectangle for the button
//    Rectangle buttonRec = {
//       (float) GetScreenWidth() / 2 -(buttonWidth/2.0f),
//       (float) GetScreenHeight() / 2 -(buttonHeight/2.0f),
//       buttonWidth,
//       buttonHeight
//    };

// bool buttonClicked = false;
Button startButton("play game");
UISTATE ui_state = MENU;
   ///game loop////
   while (!WindowShouldClose()) {

// if(!buttonClicked)
      if(ui_state==MENU)
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

    
drawBoard();
 

    // Handle button click without drawing the button
    if (startButton.isButtonClicked()) {
        startButton.buttonClicked = true;
        ui_state=GAME;
        // Your code here to respond to the button click
    }

    // Draw the button background if it was not clicked
    if (! startButton.buttonClicked) {
startButton.draw();
    }

      DrawText(titleCStr, x, 80, 40, WHITE);


      DrawFPS(10, 10);
      EndDrawing();

   }

   CloseWindow();
   return 0;
}

