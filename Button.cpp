
#include"Button.h"

#include <raygui.h>


   Button::Button(const string Btitle,Vector2 size,Vector2 pos){

 title=Btitle;

   buttonRec = {
      pos.x,
      pos.y,
      size.x,
      size.y
   };



 update();

   }

   Button::Button(const string bTitle){
 
    buttonRec = {
      (float) GetScreenWidth() / 2 -(buttonWidth/2.0f),
      (float) GetScreenHeight() / 2 -(buttonHeight/2.0f),
      buttonWidth,
      buttonHeight
   };

 title=bTitle;

 update();

}

   void Button::draw(){
 // Calculate text position to center it within the rectangle
        int textWidth = MeasureText(getStringTitle(title), 20);
        int textHeight = 20;
        int textX = buttonRec.x + (buttonRec.width - textWidth) / 2;
        int textY = buttonRec.y + (buttonRec.height - textHeight) / 2;
        DrawRectangleRounded(buttonRec, 0.2, 0, DARKGRAY);
        DrawText(getStringTitle(title), textX, textY , 20, RAYWHITE);
   }

   void Button::update(){
       buttonClicked = GuiButton(buttonRec, getStringTitle(title));
   }

bool Button::isButtonClicked(){
   return buttonClicked;
}



