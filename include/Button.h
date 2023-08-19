#ifndef BUTTON_H
#define BUTTON_H



#include <raylib.h>

#include<string>



// #define RAYGUI_IMPLEMENTATION
// #include <raygui.h>

using std::string;

 
class Button{
private:
 Rectangle buttonRec;
const char * getStringTitle(const std::string title) {
   const char * titleCStr = title.c_str();
   return titleCStr;
}
public:
float buttonWidth=150;
float buttonHeight=70;

bool buttonClicked = false;

  string title;

   Button(const string Btitle,Vector2 size,Vector2 pos);

   Button(const string bTitle);


   void draw();

   void update();

bool isButtonClicked();


};

#endif
