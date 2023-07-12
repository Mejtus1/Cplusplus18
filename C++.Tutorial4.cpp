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

