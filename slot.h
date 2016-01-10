//slot.cpp
//models a slot machine
#include<graphics.h>                      // for graphics function
#include<stdlib.h>                        // for rand(), randomise()
#include<time.h>                          // for randomise()
//#include<conio.h>                         // for getche()
//#include<dos.h>                           // for dely(), sound(), nosound()
using namespace std;

const int W = 15;                           // 1/2 width of images
const int MAR = 10;                         // margin around images

class shape                                // base class
{
   protected:
   
   int xCo,yCo;                            // coordinates of center 
   int linecolor;                          // color of outline
   int fillcolor;                          // color of interior 
   
   public:
   
   shape();                                 // no-arg constructor 
   
   void set(int x, int y, int lc, int fc);
   void draw();

};

class ball : public shape
{ 
   public:
   
   ball() : shape()                          // no-arg constructor
   {}

   void set(int x, int y, int lc, int fc);    // set data
       
   void draw();                               // draw the ball
   
};

class rect : public shape
{ 
   public:
  
   rect() : shape()                         // no-arg constructor
   {}

   void set(int x, int y, int lc, int fc);   // set data
 
   void draw();                              // draw the rectangle
   
};

class tria : public shape
{
   public:
   
   tria() : shape()                         // no-arg constructor
   {}

   void set(int x, int y, int lc, int fc);   // set data
 
   void draw();                              // draw the rectangle
   
};

class noshape : public shape
{ 
   public:
  
   void erase();                                    // erase old shape
   
};

class Cherry : public ball, public noshape
{
   public:
   
   Cherry() : ball()                               // no-arg constructor
   {}
   
   void set(int x, int y);                          // set data
   
   void draw();                                     // draw a cherry
  
};

class Grape : public ball, public noshape
{
   public:
   
   Grape() : ball()                               // no-arg constructor
   {}
   
   void set(int x, int y);                          // set data
   
   void draw();                                     // draw a grape
   
};

class Square  : public rect, public noshape
{
   public:
   
   Square() : rect()                               // no-arg constructor
   {}
   
   void set(int x, int y);                          // set data
   
   void draw();                                     // draw a square
  
};

class Pyramid : public tria, public noshape
{
   public:
   
   Pyramid() : tria()                               // no-arg constructor
   {}
   
   void set(int x, int y);                          // set data
   
   void draw();                                     // draw a pyramid
   
};

class Wheel : public shape
{
   private:
   
   Cherry ch;                                      // make one pip of each kind
   Grape gr;
   Square sq;
   Pyramid py;

   public:
 
   Wheel();                                         // no-arg constructor
   
   void set(int x, int y);
   
   void draw();                                    // draw a random pip
};


