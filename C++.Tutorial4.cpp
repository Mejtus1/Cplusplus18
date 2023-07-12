//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//for loops 
//for loops 
// this is a recurring pattern
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;

//we can simplify this by for loop
for (int i = 0; i < 5; i++) {
  cout << "Hello" << endl;
}

//for loops function like code blocks, they also use boolean values 
//additionaly there is a incrementation, declaration and initialization of variable ITERATOR

for (int i = 0; i < 5; i++) {
  cout << "Loop #" << i << endl;
}
//C++ starts at 0 so 0 - 4 is outputted 
// i++ tells the system to keep adding up until i < 5 is reached and stops the loop

for (int i = 0; i < 5; i++) {
  cout << "Loop #" << i + 1 << endl; // i + 1 outputs every value + 1 
}

for (int i = 0; i < 6; i++) { //i < 6 = outputs 0 - 5 
  cout << "Loop #" << i  << endl;
}

for (int i = 0; i <= 5; i++) { //we can also use <= operator and the output will include 5 
  cout << "Loop #" << i << endl;
}

for (int i = 0; i <= 5; i--) { // we can change i++ to i--, but because no stop condition is 
  cout << "Loop #" << i << endl; //specified, the loop would run forever
}




//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//TURTLE GRAPHICS
//it is an C++ extension that can draw lines
//purpose of this is to create simple and graphical interfaces using code
//header info which needs to be included in order to run CPP.turtletina
#include <iostream>
#include "CTurtle.hpp"
#include "CImg.h"
using namespace cturtle;
using namespace std;

//typical commands are 
tina.forward(n)
tina.backward(n)
tina.right(n)
tina.left(n)


//this prints a line 
TurtleScreen screen(400, 300);
Turtle tina(screen);
tina.forward(100);
screen.exitonclick();

//this prints a square
TurtleScreen screen(400, 300);
Turtle tina(screen);
tina.forward(100);
tina.right(90);
tina.forward(100);
tina.right(90);
tina.forward(100);
tina.right(90);
tina.forward(100);
tina.right(90);

//exercise with for loops 
//these codes produce exact square
for (int i = 0; i < 4; i++) {
  tina.forward(100);
  tina.right(90);
}

for (int i = 1; i < 5; i++) {
  tina.forward(100);
  tina.right(90);
}

for (int i = 20; i < 24; i++) {
  tina.forward(100);
  tina.right(90);
}


//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//

//turtle graphics using for loops 
//additional commands 
tina.pencolor({"COLOR"}) //color of the pen drawing 
tina.width(W) //width of lines drawn
tina.shape("SHAPE") //shape it takes
tina.speed(SPEED) //TS_FASTEST, TS_FAST, TS_NORMAL, TS_SLOW, TS_SLOWEST

//
tina.right(90) //turns turtle 90 degrees but doesnt move it forward
tine.forward(100) //moves turtle

//exercise1
tina.forward(75);
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(100);

tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(100);

tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(100);

tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);

//using for loop to shorten this 
tina.forward(75);
for (int i = 0; i < 3; i++) {
    tina.right(90);
    tina.forward(25);
    tina.right(90);
    tina.forward(25);
    tina.right(90);
    tina.forward(100);
    }
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);
tina.right(90);
tina.forward(25);

//Exercise2
//drawing a circle
//(Circle has 360 degrees so 360/360 = 1)
for (int i = 0; i < 360; i++) {
  tina.speed(TS_FASTEST);
  tina.forward(1);
  tina.right(1);
}

//Exercise3
//
tina.pencolor({"green"}); //sets the pen color to green 
tina.width(2);            //sets the width of pen to 2 units
tina.shape("triangle");   //triagle shape
tina.speed(TS_NORMAL);    //normal speed

for (int i = 10; i <= 200; i+=10) { 
    tina.forward(i);    //we specify the measurements to move inside variable i
    tina.right(90);     //so every time for loop runs i gets incremented by 10 to 200 where it stops
}


//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//


//Formatie assesment 
//Construct a program using the code blocks below that incorporates a for loop to find the 
//sum of all numbers between 1 and 100, and then prints that cumulative sum.
int sum = 0;
for (int i = 1; i <= 100; i++) {
  sum += i;
}
cout << sum << endl;



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//while loops 
//while loops, like for loops, use curly braces {} and indents for all commands that should be repeated. 
//However, for loops generally contain 3 elements (an initialized variable, a boolean expression involving that variable, 
//and a change in the value of that variable) while a while loop usually contains just a boolean expression. 
//The for and while loops below produce the same results.

//difference between for and while 
for (int i = 0; i < 5; i++) {    //for 
  cout << "Loop#: " << i << endl;
}

int i = 0;    //while
while (i < 5) {
  cout << "Loop# " << i << endl;
  i++;
}
//same output 

//another example of while loop 
int count = 5; // some random number set by user
while (count > 0) {
  cout << "Hello" << endl;
  count--;      //everything happens inside parenthesis 
}


//infinite loops 
int count = 5; // some random number set by user
while (count > 0) {
  cout << "Hello" << endl;
}
//this code couses infinite loop which will run forever

//WHY USE WHILE LOOPS ? 
//while loops may seem similar to for loops, but they have their own place and functionality
//exact example is waiting for specific condition 

//Imagine you are making a video game. The game should continue until the player loses all of 
//their lives. You don’t know how long this will take, so a while loop is more appropriate. 
//On the other hand, if you have more specific loop parameters, a for loop will be better.
int player_lives = 3;
while (player_lives > 0) { //example of while loop
  // video game code
  // goes here
}