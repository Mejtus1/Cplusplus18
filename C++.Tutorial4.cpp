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



//while loops drawing using turtle

//first drawing 
int i = 0;
  tina.forward(75);
  while (i < 4) {
    tina.right(90);
    tina.forward(25);
    tina.right(90);
    tina.forward(25);
    tina.right(90);
    tina.forward(100);
    i++;
    }

    //second
    int i = 0;
  while (i < 360) {
    tina.pencolor({"red"});
    tina.shape("square");
    tina.speed(TS_FASTEST);
    tina.forward(1);
    tina.right(1);
    i++;
    }

    //third
    int i = 10;
  while (i < 300) {
    tina.pencolor({"green"});
    tina.shape("triangle");
    tina.speed(TS_NORMAL);
    tina.forward(i);
    tina.right(90);
    i+=10;
    }

    //Break statement
    int main() {

  srand(time(NULL)); // start randomizer every time program runs
  while (true) {
    cout << "This is an infinite loop" << endl;
    int randNum = rand() % 100 + 1; // generate random number between 1 and 100
    
    if (randNum > 75) {
      cout << "The loop ends" << endl;
      break; // stop the loop
    } // end if condition
  } // end while loop
  
  cout << "The program ends" << endl;
  
  return 0;

}
//Even though while (true) will always evaluate as a true statement, 
//the loop never becomes infinite because of the break statement.


//exercise
int count = 0;
while (count < 10) {
  cout << "C++" << endl;
  count = count + 1;
  }

int total = 0;
while (true) {
  total = total + 1;
if (total > 99) {
break; }
}



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Nested loops 
//A nested loop is a loop that exists inside of another loop. 
//due to their complexity potential, it is rare to see the implementation of more than two nested loops.

for (int row = 0; row < 10; row++) { //outer loop
  for (int col = 0; col < 10; col++) { //inner loop
    cout << "#";
  }
  cout << "" << endl; //adds new line
}
//draws 10x10 row in console using hashtags

 for (int row = 0; row < 5; row++) { //outer loop
  for (int col = 0; col < 20; col++) { //inner loop
    cout << "#";
  }
  cout << "" << endl; //adds new line
}
//outputs 5 x 20 hashtags in console

//exercise
for (int row = 0; row < 7; row++) { //outer loop
  for (int col = 0; col < 11; col++) { //inner loop
    cout << "#";
  }
  cout << "" << endl; }

//example solution 
int row = 0;
while (row < 7) {
  int col = 0;
  while (col < 11) {
    cout << "#";
    col++;
  }
  cout << "" << endl;
  row++;
}



//exercise
for (int row = 0; row < 3; row++) { //outer loop
  cout << "<<<<<<<<<" << endl;
  for (int col = 1; col < 2; col++) { //inner loop
    cout << ">>>>>>>>>" << endl;
  }
}
//example solution 
for (int row = 0; row < 5; row++) {
  if (row % 2 == 0) {
    int col = 0;
    while (col < 10) {
      cout << "<";
      col++;
    }
    cout << "" << endl;
  }
  else {
    int col = 0;
    while (col < 10) {
      cout << ">";
      col++;
    }
    cout << "" << endl;
  }
}



//exercise
for (int row = 1; row <= 5; row++) {
  for (int col = 1; col <= row; col++) {
    cout << row;
  }
  cout << "" << endl;
}


//exercise
for (int line = 1; line <= 12; line++) {
  for (int num = 1; num <= line; num++) {
    cout << num << " ";
  }
  cout << "" << endl;
}

//exercise
for (int i = 0; i < 
4
; i++) {
  cout << "
&&
" << endl;
  for (int j = 0; j < 
3
; j++) {
    cout << "
*
" << endl;
  }
}
//First, it is necessary to determine the pattern that is being iterated. 
//Notice how a && symbol is followed by three * symbols and this pattern repeats exactly four times. 
//This means that the inner loop should run three times for every time the outer loop runs and we want the outer loop to run four times. 
//In other words, print three * for each of the four printed &&.

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//cin function (cin.input() and cin.output())
double result = 0;
double input;    
//The cin >> input; command records what a user enters on the screen and stores that information 
//in the variable input. Note that input is of type double.
while (true) { //while loop is set to true, so user can input how many values he wants
  cout << "Enter a number to add to sum. "; 
  cout << "Or enter a non-number to quit and calculate sum." << endl;
  cin >> input; //cin and storing variable input which we initialized before
  if (cin.good()) { //checks if cin is type of double = then outputs it
    result += input;
  }
  if (cin.fail()) { //checks if cin is not double = then program halts and breaks, 
    cout << "Sum = " << result << endl; //the sum of entered numbers is outputted 
    break;
  }
}
//cin.good() checks to see if the input entered by the user was successful 
//while cin.fail() checks to see if the input failed. Since input is of type double, 
//only numerical values entered by the user will cause cin >> input to be successful, 
//anything else will cause the input to fail

/*in the terminal we will have 
Enter a number to add to sum. Or enter a non-number to quit and calculate sum.
1 (we inputted 1 in terminal)
Enter a number to add to sum. Or enter a non-number to quit and calculate sum.
2 (we inputted 2 in terminal)
Enter a number to add to sum. Or enter a non-number to quit and calculate sum.
3 (we inputted 3 in terminal )
Enter a number to add to sum. Or enter a non-number to quit and calculate sum.
n (we inputted non-number character and the program cin.fail() method runs with break statement)
Sum = 6
*/

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Loops lap exercises

//For loops lab exercise
for (int x = 0; x < 11; x++) {
  if (x % 2 == 0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}
// Even, Odd, Even, Odd, Even, Odd, Even, Odd, Even, Odd, Even

/* Rearrange the code blocks below to create a program that outputs the following:
Even Odd Even
Odd Even Odd
Even Odd Even
Odd Even Odd
Even Odd Even*/
for (int x = 0; x < 5; x++) {
  if (x % 2 == 0) {
    cout << "Even Odd Even" << endl;
  }
  else {
    cout << "Odd Even Odd" << endl;
  }
}
//we are using modulation and when we count from 0 the Even Odd Even shall be first4

//While loop lab exercise
int counter = 0;
while (counter < 10) {
  cout << counter << endl;
  counter = counter + 1;
}
cout << "while loop ended" << endl;
//outputs 0-10 on new line and than string "while loop ended"
//Which of the following code snippets will result in an infinite while loop?
int lives = 10;
while (lives > 0) {
  cout << "You are still in the game." << endl;
  lives = lives + 1;
}
cout << "Game over." << endl;
//it was choice number 3

//Breaking from the While Loop exercise
while (true) {
  cout << "Enter a number to add to sum. "; 
  cout << "Or enter a non-number to quit and calculate sum." << endl;
  cin >> input; 
  if (cin.good()) {
    result += input;
  }
  if (cin.fail()) {
    cout << "Sum = " << result << endl;
    break; //we use the break statement here to stop the command from running 
  }
}

//the following program results in an infinite loop, what code solution will help to stop it 
string s;

while (true) {
  cout << "Enter a lowercase vowel." << endl;
  cin >> s;
  if (s=="a" || s=="e" || s=="i" || s=="o" || s=="u") {
    cout << "You successfully entered a vowel." << endl;
  }
  else {
    cout << "You did not enter a vowel." << endl;
  }
}
//b)Insert a break; statement on the line after cout << "You did not enter a vowel." << endl;.
//I didnt pick this one, because the whole program wouldnt run which 
//a)Insert a break; statement on the line after cout << "You successfully entered a vowel." << endl;.

//Loop patterns 
for (int x = 0; x < 3; x++) {
  cout << "XOXOXOXOX" << endl;
  for (int y = 0; y < 2; y++) {
    cout << "OXO" << endl; 
  }
}

for (int x = 0; x < 3; x++) {
  cout << "L" << endl;
  for (int y = 0; y < 3; y++) {
    cout << "M" << endl;
  }
}

for (int x = 0; x < 3; x++) {
  cout << "L"; 
  for (int y = 0; y < 3; y++) {
    cout << "M"; 
  }
}


//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Exercises
//Turtle object called tina, you want tina to move around on a screen and leave a trail that draws a triangle
for (int i = 0; i < 3; i++) {
      tina.left(120);
      tina.forward(100);
      }

//Exercise2
//Write a program that takes in a string x from the user as an argument and then prints that information ten times using a loop.
for (int i = 0; i < 10; i++)
  cout << x << endl;

//Exercise3
//You are trying to produce a program that takes in two integer arguments from the user and then prints the 
//consecutive sum of all numbers between those integers inclusively.
//Use any loop to find the consective sum between the integer variables a and b.
//If a and b are the same integers, then print either a or b as the sum.
//5 and 8
int sum = 0;
for (int iter = 5; iter <= 8; iter++) {
  sum += iter;
}
if (a == b) {
  sum = a;
}
cout << sum << endl; //26

//9 and 3
int sum = 0;
for (int iter = 9; iter <= 3; iter++) {
  sum += iter;
}
if (a == b) {
  sum = a;
}
cout << sum << endl; //0

//Exercise 4
//Breaking the Loop
//The following program (also shown in the text editor on the left) contains one or more infinite loops that prevent the program from printing the desired output.
//Using what you know about break statements, fix the program so that it runs, prints correctly, and terminates successfully.
for (int i = 100; i <= 100; i--) {
    if (i == 0) {
      cout << "Print me!" << endl;
      break; //break added here
    }
    else {
      while (true) {
        break; //break added here
        i++;
        cout << "Don't print me!" << endl;
      }
    }
  }

//Exercise 5
//produce output specified
  for (int i = 1; i < 6; i++) {
  for (int j = 5 - i; j > 0; j--) {
    cout << ".";
  }
  cout << i << endl;
}
