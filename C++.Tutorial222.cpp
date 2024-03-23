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
