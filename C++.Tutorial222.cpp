// What is Recursion ? 
// - solving coding problem with functions involves breaking down problem into smaller problems
// - when these smaller problems are variations of larger problem (also know as self-similar), then recursion can be used 
// - mathematical function factorial is self-similar: 
// - five factorial (5!) is calculated as 5 * 4 * 3 * 2 * 1
// - see that 5! is really just 5 * 4!, and 4! is really just 4 * 3! and so on...

// 5! = 5 * 4 * 3 * 2 * 1 

// - because 5! is self-similar, recursion can be used to calculate answer
// - recursive functions are functions that call themselves

#include <iostream>
using namespace std;

//add function definitions below this line

/**
 * Calculates factorial using recursion
 * 
 * @param n, integer
 * @return factorial of n, integer
 */
int Factorial(int n) {
  if (n == 1) {
    return 1;
  }
  else {
    return n * Factorial(n - 1);
  }
}

//add function definitions above this line

int main() {
  
  //add code below this line
  
  cout << Factorial(5) << endl;
  return 0;
  
  //add code above this line
  
}
// 120 

// - recursion is abstract and difficult topic, so it might be bit hard to follow what is going on here
// - when n is 5, C++ starts multiplication problem of 5 * Factorial(4)
// - function runs again and multiplication problem becomes 5 * 4 * Factorial(3)
// - this continues until n is 1, C++ returns value 1, and C++ solves multiplication problem 5 * 4 * 3 * 2 * 1
// - video below should help explain how 5! is calculated recursively

factorial(5)
    5 * factorial(4)
        4 * factorial(3)
            3 * factorial(2)
                2 * factorial(1) 
                                  
factorial(5) = 120 
    5 * factorial(4) 24 = 120 
        4 * factorial(3) 6 = 24 
            3 * factorial(2) 2 = 6 
                2 * factorial(1) = 2 

//--------------
// The Base Case
// - each recursive function has two parts: recursive case (where function calls itself with different parameter) and base case (where function stops calling itself and returns value)
int Factorial(int n) {
    if (n==1) {
        return 1;       // BASE CASE 
    }
    else { 
        return n * Factorial(n-1);     // RECURSIVE CASE 
    }
}

// - base case is most important part of recursive function
// - without it, function will never stop calling itself

/**
 * This recursive function returns an error
 * 
 * @param n, integer
 * @return factorial of n, integer
 */
int Factorial(int n) {
  return n * Factorial(n - 1);
}
// error 

// - always start with base case when creating recursive function 
// - each time function is called recursively, program should get one step closer to base case

// What happens if you:
// Change the Factorial() function to look like:
int Factorial(int n) {
  if (n == 1) { //base case
    return 1;
  }
  else { //recursive case
    return n * Factorial(n - 1);
  }
}
// error 

// Exercise 
// Under what circumstance does it make sense to use recursion?
// b) Recursion works best when solution is self-similar 

// Fibonacci Sequence 
// Fibonacci number 
// - number which current number is sum of previous two fibonacci numbers 
// Defined as: Fn = Fn-1 + Fn-2       (F = function, n = parameter)
F0 F1 F2 F3 F4 F5 F6 F7 F8 ... 
 0  1  1  2  3  5  8 13 21 ... 
// - calculating Fibonacci number is self-similar, which means it can be defined with recursion
// - setting base case is important to avoid infinite recursion
// - when number n is 0 Fibonacci number is 0, and when n is 1 Fibonacci number is 1
// - so if n is less than or equal to 1, then return n = base case

/**
* @param n, integer
* @return Fibonacci number of n, integer
*/
int Fibonacci(int n) {
  if (n <= 1) {
    return n;
  } 
  else {
    return(Fibonacci(n-1) + Fibonacci(n-2));
  }
}

int main() {
  cout << Fibonacci(3) << endl;
  return 0;
}
// 2 

// What happens if you:
// Change the print statement to cout << Fibonacci(0) << endl;?
// 0
// Change the print statement to cout << Fibonacci(8) << endl;?
// 21 
// Change the print statement to cout << Fibonacci(30) << endl;?
// 832040

//-------------------
// Fibonacci Sequence 
// - fibonacci numbers are most often talked about as sequence
// - main() function below adds functionality of printing Fibonacci sequence of predetermined length 

int Fibonacci(int n) {
  if (n <= 1) {
    return n;
  } 
  else {
    return(Fibonacci(n-1) + Fibonacci(n-2));
  }
}

int main() {
  int fibonacci_length = 4;
  for (int i = 0; i < fibonacci_length; i++) {
    cout << Fibonacci(i) << endl;
  }
  return 0;
}
// 0
// 1 
// 1 
// 2 

// What happens if you:
// Change fibonacci_length to 10?
0, 1, 1, 2, 3, 5, 8, 13, 21, 34

//-----------
// Exercise 1
// Adding Numbers Recursively
// - drag and arrange code blocks below to create recursive function that finds sum of n integers

int FindSum(int n) {
  if (n == 0) {
    return 0;
  }
  else {
    return(n + FindSum(n-1));
  }
}
// - first function header is needed and only one is available: 
// int FindSum(int n) {
// - conditionals to create base and recursive cases
// - base case involves if (n == 0) { followed by return 0; 
// - recursive case which resides within else statement, return(n + FindSum(n-1));

// - reason why return(n + FindSum(n-1)); is correct choice is because first you are calculating sum so you’ll need to add n to another value 
// - recursive function needs way to get back to base case of n == 0 and only way to get there is for n to get smaller 
// - this can be accomplished with (n-1), otherwise, recursion will continue indefinitely

//-----------
// Exercise 2 
// Determine Base Case
// Assume you have following code snippet
bool IsPalindrome(string s) {
  ... {
    return true;
  }
  else {
    return s[0] == s[s.length() - 1]
    && IsPalindrome(s.substr(1, s.length() - 2));
  }
}

// Given this, determine what the base case will be that can replace ... in the code.
// a) if (s.length() <= 1)

//---------------------------------------------------------------------------------------------------//

// Recursion Exercise 1 
// - trees can be drawn recursively, draw branch, at end of branch, draw two smaller branches with one to left and other to right 
// - repeat until certain condition is true, this program will walk you through drawing tree in this way

// - let’s start by creating canvas screen and Turtle object tina in main() to allow Turtle object to move around on
// - function RecursiveTree() takes three parameters, branch_length, angle, and t
// - when passing object (like a Turtle), pass it as reference using & symbol (i.e. Turtle& t)

////////// DO NOT EDIT HEADER! //////////
#include <iostream>                    //
#include "CTurtle.hpp"                 //
#include "CImg.h"                      //
using namespace cturtle;               //
using namespace std;                   //
/////////////////////////////////////////

/**
 * @param branch_length An integer 
 * @param angle The angle of degree
 * @param t A Turtle object
 * @return A drawing symbolizing a tree branch
 */
void RecursiveTree(int branch_length, int angle, Turtle& t) {
  
  //add function definitions below
  
  
  
  //add function definitions above
  
}

int main(int argc, char** argv) {
  
  //add code below this line
  
  
  
  //add code above this line
  
  screen.exitonclick();
  return 0;
  
}

// - base case for this function is bit different 
// - function RecursiveTree() does not return value, it draws on screen instead
// - base case will be to keep recursing as long as branch_length is greater than some value
// - define base case as branch_length as being greater than 5


void RecursiveTree(int branch_length, int angle, Turtle& t) {
  
  //add function definitions below
  
  if (branch_length > 5) {
  
  }
  
  //add function definitions above
  
}

// - start drawing tree by going forward and turning right
// - call RecursiveTree() again, but reduce branch_length by 15 code should run, but tree will not look like tree
// - it looks more like curve made of series of line segments decreasing in size

void RecursiveTree(int branch_length, int angle, Turtle& t) {
  
  //add function definitions below
  
  if (branch_length > 5) {
    t.forward(branch_length);
    t.right(angle);
    RecursiveTree(branch_length - 15, angle, t);
  }
  
  //add function definitions above
  
}

// - in main(), let’s call RecursiveTree() function and pass in some initial values

int main(int argc, char** argv) {
  
  //add code below this line

  TurtleScreen screen(400, 300);
  Turtle tina(screen);
  RecursiveTree(45, 20, tina);
  
  //add code above this line
  
  screen.exitonclick();
  return 0;
  
}

// - next step is to draw branch that goes off to left
// - since turtle turned to right number of degrees that parameter angle represents, turtle needs to turn to left twice degrees of angle 
// - turning to left angle will put turtle back at its original heading
// - turtle needs to go further to left, then draw another branch whose length is reduced by 15

void RecursiveTree(int branch_length, int angle, Turtle& t) {
  
  //add function definitions below
  
  if (branch_length > 5) {
    t.forward(branch_length);
    t.right(angle);
    RecursiveTree(branch_length - 15, angle, t);
    t.left(angle * 2);
    RecursiveTree(branch_length - 15, angle, t);
  }
  
  //add function definitions above
  
}

// - tree is looking better, but there are two more things that need to be done
// - first, put turtle back to its original heading by turning right angle degrees, backwards length of branch. 
// - if you tweak some of arguments when calling RecursiveTree() function, you might notice tree changing

void RecursiveTree(int branch_length, int angle, Turtle& t) {
  
  //add function definitions below
  
  if (branch_length > 5) {
    t.forward(branch_length);
    t.right(angle);
    RecursiveTree(branch_length - 15, angle, t);
    t.left(angle * 2);
    RecursiveTree(branch_length - 15, angle, t);
    t.right(angle);
    t.backward(branch_length);
  }
  
  //add function definitions above
  
}

// Exercise 2 
// - drag and arrange code blocks below to create recursive function
// - assume that recursive function is called with this code:
MyRecursiveFunction(15);

int MyRecursiveFunction(int num) {
  if (num < 0) {
    return 1;
  }
  else {
    return num + MyRecursiveFunction(num - 1);
  }
}
// - recursive functions need to return values, not print them
// - since base case is testing if num is less than 0 and MyRecursiveFunction was initially called with parameter of 15, you need to use code block that says return num + MyRecursiveFunction(num - 1)
// - value of num must get to be equal to or less than 0, if not, recursive function will becomeinfinite loop

// Exercise 3 
// Problem: 
// - write recursive function called RecursivePower() that takes two integers as parameters
// - first parameter is base number and second parameter is exponent
// - return base number parameter to power of exponent
// DO NOT edit any existing code or you will not receive credit for your work!
#include <iostream>
using namespace std;

//add function definitions below this line



//add function definitions above this line

int main(int argc, char** argv) {
  cout << RecursivePower(stoi(argv[1]), stoi(argv[2])) << endl;
  return 0;
}

// Expected Output
// - if function call is RecursivePower(5, 3), then function will return 125
// - if function call is RecursivePower(4, 5), then function will return 1024

#include <iostream>
using namespace std;

//add function definitions below this line
int RecursivePower(int base, int exponent) {
    // Base case: if exponent is 0, return 1
    if (exponent == 0) {
        return 1;
    }
    // Recursive case: multiply base by RecursivePower(base, exponent - 1)
    // to calculate power
    else {
        return base * RecursivePower(base, exponent - 1);
    }
}
//add function definitions above this line

int main(int argc, char** argv) {
  cout << RecursivePower(stoi(argv[1]), stoi(argv[2])) << endl;
  return 0;
}
