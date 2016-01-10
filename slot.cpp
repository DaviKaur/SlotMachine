#include"slot.h"

// Function defination 

shape::shape()                                 // no-arg constructor 
{ 
	xCo=0; yCo; linecolor=WHITE; fillcolor=WHITE; 
}

void shape :: set(int x, int y, int lc, int fc)
{
	xCo=x; yCo=y; linecolor=lc; fillcolor=fc;
}

void shape :: draw()
{
	setcolor(linecolor);                    // set line color
	//setfillstyle(SOLID_FILL, fillcolor);    // set fill color
}

void ball :: set(int x, int y, int lc, int fc)    // set data
{
	shape::set(x, y, lc, fc);
}

void ball :: draw()                               // draw the ball
{
	shape::draw();                         // set colors
	circle(xCo, yCo, W);                   // draw circle
	floodfill(xCo, yCo, linecolor);        // fill circle
}

void rect :: set(int x, int y, int lc, int fc)   // set data
{
   shape::set(x, y, lc, fc);
}

void rect :: draw()                              // draw the rectangle
{
   shape::draw();                               // set colors
   rectangle(xCo-W, yCo-W, xCo+W, yCo+W);       // draw rectangle
   floodfill(xCo, yCo, linecolor);              // fill rectangle
   moveto(xCo-W, yCo+W);                        // draw diagonal
   lineto(xCo+W, yCo-W);                        //     line
}

void tria :: set(int x, int y, int lc, int fc)   // set data
{
   shape::set(x, y, lc, fc);
}

void tria :: draw()                              // draw the rectangle
{
	int triarray[] = { xCo,    yCo-W,   // top
                       xCo+W,  yCo+W,     // bottom right
                       xCo-W,  yCo+W};    // bottom left
    shape::draw();                        // set colors
    fillpoly(3, triarray);                // draw rectangle
}

void noshape :: erase()                                    // erase old shape
   {
       int border[] =                              // rectangle to erase
		     { xCo-W-MAR, yCo-W-MAR,       // upper_left
                       xCo+W+MAR, yCo-W-MAR,       // upper_right
                       xCo+W+MAR, yCo+W+MAR,       // bottom_right
                       xCo-W-MAR, yCo+W+MAR };     // bottom-left
       //setfillstyle(SOLID_FILL, DARKGRAY);  // background color
       fillpoly(4, border);                        // fill it
   }

void Cherry :: set(int x, int y)                          // set data
   {
      ball::set(x, y, WHITE, RED);
      noshape::set(x, y, WHITE, RED);
   }

void Cherry :: draw()                                     // draw a cherry
   {
      erase();
      ball::draw();
   }

void Grape :: set(int x, int y)                          // set data
   {
      ball::set(x, y, WHITE, BLUE);
      noshape::set(x, y, WHITE, BLUE);
   }

void Grape :: draw()                                     // draw a grape
   {
      erase();
      ball::draw();
   }

void Square :: set(int x, int y)                          // set data
   {
      rect::set(x, y, WHITE, CYAN);
      noshape::set(x, y, WHITE, CYAN);
   }

void Square :: draw()                                     // draw a square
   {
      erase();
      rect::draw();
   }

void Pyramid :: set(int x, int y)                          // set data
   {
      tria::set(x, y, WHITE, GREEN);
      noshape::set(x, y, WHITE, GREEN);
   }

void Pyramid :: draw()                                     // draw a pyramid
   {
      erase();
      tria::draw();
   }

Wheel :: Wheel()                                         // no-arg constructor
   { 
      xCo=0; yCo=0;
   }

void Wheel :: set(int x, int y)
   {
      xCo=x; yCo=y;                                // set our position
      ch.set(xCo, yCo);                            // set four pips to
      gr.set(xCo, yCo);                            //    our position
      sq.set(xCo, yCo);
      py.set(xCo, yCo);
   }

void Wheel :: draw()                               // draw a random pip
{  
   setcolor(WHITE);                                // draw border
  
   rectangle(xCo-W-MAR, yCo-W-MAR, xCo+W+MAR, yCo+W+MAR);    
	int rr=rand()%4;
   switch(rr)                               // random number from 0 to 3
   {
      case 0 : ch.draw(); break;                   // draw one of the pipes
      case 1 : gr.draw(); break;                   // selected randomly
      case 2 : sq.draw(); break;
      case 3 : py.draw(); break;
   }
}
