#include"slot.cpp"

//-------------------------- MAIN FUNCTION-------------------------------

int main()
{
   const int NUMBER = 60;                            // number of times to cycle

   //int driver, mode;
   //driver = DETECT;                                  // set to best graphics mode

   int gd,gm=VGAMAX; gd=DETECT;
   initgraph(&gd,&gm,NULL);

   //initgraph(&driver, &mode, "\\tc\\bgi");
   rand(); //randomize();                                      // seed random number generator

   Wheel w1, w2, w3;                                 // make three wheels

   w1.set(100, 100);                                 // position in horizontal row
   w2.set(160, 100);
   w3.set(220, 100);

   for(int j=0; j<NUMBER; j++)
   {
       w1.draw();                                     // draw each wheel
       w2.draw();
       w3.draw();
       
       //sound(100);    
delay(20);     //nosound();       // click
      
       delay( j*j/20);                                // delay gets longer and longer
   }

//   sound(400);
     delay(400);                        // two tones to signal done
  // sound(500);     
delay(20);    //  nosound();
    
   getch();                                          // wait for keypress
 
   closegraph();                                      // close graphics system
return 0;

}
