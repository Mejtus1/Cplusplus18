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

//---------------------------------------------------------------------------------------------------//

//-----------
// Exercise 1

// Recursion Exercise 1

// Problem
// - write recursive function called RecursiveSum() that takes integer as parameter
// - then it returns sum of all integers between 0 and integer passed to RecursiveSum()
// - if argument is 5, then returned value will be 0 + 1 + 2 + 3 + 4 + 5 which is 15

#include <iostream>
using namespace std;

//add function definitions below this line

int RecursiveSum(int c) {
  if (c == 0) {
    return 0; 
  }
  else {
    return(c + RecursiveSum(c - 1));
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  cout << RecursiveSum(stoi(argv[1])) << endl;
  return 0;
}

// COMPILE AND TEST WITH 0
// 0 
// COMPILE AND TEST WITH 10
// 55

// 1. function RecursiveSum is called with argument c = 10
// 2. inside function, it checks if c is equal to 0, since it is not, else block executes
// 3. returns sum of c and result of calling RecursiveSum with argument c - 1, c = 10, so it returns 10 + RecursiveSum(9)
// 4. function is called recursively with c = 9, it repeats same process
// 5. this continues until c becomes 0, when c becomes 0, base case is reached, and function returns 0
// 6. at this point, recursion "unwinds" or starts resolving, each recursive call returns its value, and previous recursive call adds its current c to it
// 7. sum is computed as follows:
// RecursiveSum(0) returns 0
// RecursiveSum(1) returns 1 + RecursiveSum(0), which is 1
// RecursiveSum(2) returns 2 + RecursiveSum(1), which is 3
// RecursiveSum(3) returns 3 + RecursiveSum(2), which is 6
// ...                ...             ...          ... 
// RecursiveSum(10) returns 10 + RecursiveSum(9), which is 55
// 8. final result is 55, which is sum of integers from 1 to 10

// - recursive pattern is to take num passed as parameter and add it to RecursiveSum() with number minus 1
// - base case is when number passed is 0, what this means is that every recursive call adds specified number followed by adding that same number but subtracted by 1. 


//-----------
// Exercise 2 

// Recursion Exercise 2 
// - write recursive function called ListSum() that takes vector of integers as parameter
// - then it returns sum of all of integers in array


#include <iostream>
#include <vector>
using namespace std;

//add function definitions below this line


int ListSum(vector<int>& nums) {
  if (nums.size() == 1) {
    return nums.at(0);
  }
  else {
    vector<int> new_vector(nums.begin() + 1, nums.begin() + nums.size());
    return nums.at(0) + ListSum(new_vector);
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  vector<int> nums;
  for (int i = 1; i < argc; i++) {
    nums.push_back(stoi(argv[i]));
  }
  cout << ListSum(nums) << endl;
  return 0;
}

// Compile and test with 0 
// 0 
// Compile and test with 2,4,6,8
// 20 

// - recursive pattern is to take first element from nums and add it to ListSum() of original vector from element 1 to end of vector
// - this vector is called new_vector  
// - base case is when vector has just one element in it, if so then function will return this element only

// 1. function first checks if size of vector nums is 1, if it is, it means there's only one element in vector, so it returns that element
// 2. if size of vector is not 1, it means there are multiple elements in vector
// 3. it creates new vector new_vector containing all elements of nums except first element this is achieved by using constructor of vector class that accepts two iterators, specifying range of elements to be included in new vector
// 4. returns sum of first element of nums and result of recursively calling ListSum with new_vector
// 5. this recursive process continues until vector nums has only one element, at which point base case is reached, and recursion stops
// 6. recursion unwinds, each recursive call returns its value, and previous recursive call adds its current element to it
// 7. final result is sum of all elements in original vector nums

// - after creating new_vector, function ListSum proceeds to perform recursive call with this modified vector
// - what happens in detail:


// Process Explained of net vector: 
// 1. Creating new vector (new_vector):
vector<int> new_vector(nums.begin() + 1, nums.begin() + nums.size());
nums.begin() + 1 
// - specifies iterator pointing to second element of original vector nums
nums.begin() + nums.size() 
// - specifies iterator pointing to one position past last element of original vector nums
// - this effectively creates new vector containing all elements of nums except first element

// 2. Recursive call with modified vector:
return nums.at(0) + ListSum(new_vector);
nums.at(0) retrieves the first element of the original vector nums
ListSum(new_vector) recursively calls the ListSum function with the new_vector as its argument
// - function computes sum of all elements in new_vector recursively, according to logic described earlier
// - sum of first element of nums and sum of elements in new_vector (returned by recursive call) is then computed and returned

// 3. Base case termination:
// - recursion continues until nums vector has only one element, at which poin base case is reached
// - in base case, function simply returns single element in vector, effectively terminating recursion



// Specific Example: 
// - example with specific set of numbers to illustrate how ListSum function works
// - following vector:
vector<int> nums = {1, 2, 3, 4, 5};

// First Recursive Call:
nums.at(0) 
// - retrieves first element, which is 1
// - new_vector is created by excluding first element, resulting in {2, 3, 4, 5}
// - recursive call is made with new_vector

// Second Recursive Call:
nums.at(0) 
// - retrieves first element of current vector, which is 2
// - new_vector is created by excluding first element, resulting in {3, 4, 5}
// - another recursive call is made with new_vector

// Third Recursive Call:
nums.at(0) 
// - retrieves first element of current vector, which is 3
// - new_vector is created by excluding first element, resulting in {4, 5}
// - another recursive call is made with new_vector

// Fourth Recursive Call:
nums.at(0) 
// - retrieves first element of current vector, which is 4
// - new_vector is created by excluding the first element, resulting in {5}
// - another recursive call is made with new_vector

// Fifth Recursive Call (Base Case):
nums.size() 
// - is 1, so base case is reached
// - function returns single element of current vector, which is 5

// In the fifth call, ListSum({5}) returns 5
// In the fourth call, ListSum({4, 5}) returns 4 + 5 = 9
// In the third call, ListSum({3, 4, 5}) returns 3 + 9 = 12
// In the second call, ListSum({2, 3, 4, 5}) returns 2 + 12 = 14
// In the first call, ListSum({1, 2, 3, 4, 5}) returns 1 + 14 = 15
// - final sum of the elements in the vector {1, 2, 3, 4, 5} is 15

// IN SIMPLE TERMS, new_vector HOLDS REMAINING ELEMENTS of original nums vector UNTIL they are all added together in nums in one number 

//---------------------------------------------------------------------------------------------------//
// Recursion Exercise 3 
// Problem
// - write recursive function called BunnyEars() that takes number of bunnies (integer) as parameter
// - then it returns number of bunny ears (2 per bunny) 
// - use addition instead of multiplication in your code

// - if function call is BunnyEars(8), then function will return 16
// - if function call is BunnyEars(1), then function will return 2

// existing code: 
#include <iostream>
using namespace std;

//add function definitions below this line



//add function definitions above this line

int main(int argc, char** argv) {
  cout << BunnyEars(stoi(argv[1])) << endl;
  return 0;
}


// - problem is asking you to calculate how many bunny ears there are per given number of bunnies
// - this problem is essentially multiplication problem that is solved through additive recursion
// - recursive pattern is adding 2 and then calling BunnyEars() with number of bunnies minus 1
// - that means every call results in 2 extra ears and 1 fewer bunny
// - base case is when number of bunnies is 0 which means there are no more bunnies to count

int BunnyEars(int n) {
  if (n == 0) {
    return 0;
  }
  else {
    return 2 + BunnyEars(n - 1);
  }
}

// whole code: 
#include <iostream>
using namespace std;

//add function definitions below this line

int BunnyEars(int n) {
  if (n == 0) {
    return 0;
  }
  else {
    return 2 + BunnyEars(n - 1);
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  cout << BunnyEars(stoi(argv[1])) << endl;
  return 0;
}

// - function recursively calls itself and adds for each number (2) bunny ears

// COMPILE AND TEST WITH 4
// 8
// COMPILE AND TEST WITH 0
// 0

//---------------------------------------------------------------------------------------------------//
// Recursion Lab 4 
// - write recursive function called ReverseString() that takes a string as parameter
// - then it returns string in reverse order

#include <iostream>
using namespace std;

//add function definitions below this line



//add function definitions above this line

int main(int argc, char** argv) {
  cout << ReverseString(argv[1]) << endl;
  return 0;
}

// - if function call is ReverseString("cat"), then function will return tac
// - if function call is ReverseString("house"), then function will return esuoh

// - recursive pattern is to take last character from string passed (s.substr(s.length() - 1)) and concatenate it with ReverseString() using string minus last character as parameter
// - this is done with ReverseString(s.substr(0, s.length() - 1))
// - base case is when length of string is 1, then you return string itself which is just single character
// - this means that if string is Codio, then o gets returned first, then Codi is passed and i is returned, so on and so forth

string ReverseString(string s) {
  if (s.length() == 1) {
    return s;
  }
  else {
    return s.substr(s.length() - 1) + ReverseString(s.substr(0, s.length() - 1));
  }
}

// COMPILE AND TEST WITH LOWERCASE "HELLO"
// olleh
// COMPILE AND TEST WITH UPPERCASE "CODIO"
// oidoC
// COMPILE AND TEST WITH "!"
// !
  
// whole code: 
#include <iostream>
using namespace std;

//add function definitions below this line

string ReverseString(string s) {
  if (s.length() == 1) {
    return s;
  }
  else {
    return s.substr(s.length() - 1) + ReverseString(s.substr(0, s.length() - 1));
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  cout << ReverseString(argv[1]) << endl;
  return 0;
}

// - use substr function to return substring of another string
// - s.substr(s.length() - 1) + ReverseString(s.substr(0, s.length() - 1)) will add last character of string and then pass characters before it as parameter
// - note that last character is not included as part of parameter when recursive function is called

// - recursive pattern is to take last character from string passed (s.substr(s.length() - 1)) and concatenate it with ReverseString() using string minus last character as parameter
// - this is done with ReverseString(s.substr(0, s.length() - 1))
// - base case is when length of string is 1, then you return string itself which is just single character
// - this means that if string is Codio, then o gets returned first, then Codi is passed and i is returned, so on and so forth

// 1. function takes string s as input
// 2. in base case, if length of string s is 1 (i.e., it contains only one character), function returns string s itself, this is termination condition for recursion
// Otherwise, in recursive case:
// - it extracts last character of string s using s.substr(s.length() - 1), which returns last character as substring
// - it then recursively calls itself with substring s.substr(0, s.length() - 1), which excludes last character from original string
// - finally, it concatenates last character with result of the recursive call to reverse remaining substring

//---------------------------------------------------------------------------------------------------//

//---------------------
// Recursion Exercise 5
// Problem
// - write recursive function called GetMax() that takes vector of integers as parameter
// - then it returns largest integer in array

// - create new integer vector and then use function new_vector(nums.begin() + 1, nums.begin() + nums.size()) to create partial copy of vector after each recursive call
// - use function max(int1, int2) to return integer that is larger (int1 or int2) where int1 represents current integer and int2 is next integer that gets accessed

// - if GetMax() function is called wit vector elements of {1, 2, 3, 4, 5} then it will return 5
// - if GetMax() function is called with vector elements of {11, 22, 3, 41, 15} then it will return 41

// - recursive pattern is to select larger value between first/current element in vector and GetMax() which takes rest of vector as parameter to determine whether any of remaining elements is larger
// - base case is when vector only has one element in it
// - function returns that number 
// - if {11, 22, 3, 41, 15} is in vector, then 11 gets compared with all of elements after it, then 22 gets compared with those after it, and so on and so forth 
// - eventually, 41 will be accessed as largest integer in vector

// whole code: 
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//add function definitions below this line

int GetMax(vector<int>& nums) {
  if (nums.size() == 1) {
    return nums.at(0);
  }
  else {
    vector<int> new_vector(nums.begin() + 1, nums.begin() + nums.size());
    return max(nums.at(0), GetMax(new_vector));
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  vector<int> nums;
  for (int i = 1; i < argc; i++) {
    nums.push_back(stoi(argv[i]));
  }
  cout << GetMax(nums) << endl;
  return 0;
}

// COMPILE AND TEST WITH 22
// 22
// COMPILE AND TEST WITH 18, 42, 3, 42
// 42

// 1. function takes a reference to vector of integers nums as input
// 2. in base case, if size of vector nums is 1 (i.e., it contains only one element), function returns element at index 0 using nums.at(0), this is termination condition for recursion
// 3. otherwise, in recursive case:
// - it creates new vector new_vector containing all elements of nums except first one, 
// this is done using vector constructor with two iterators, nums.begin() + 1 (which points to element after first one) and nums.begin() + nums.size() (which points to end of vector)
// - it recursively calls itself with new vector new_vector
// - it uses max() function to compare first element of original vector nums (at index 0) with maximum element found in recursive call
// - returns maximum of these two values

// - recursion continues until vector contains only one element, at which point maximum element is determined by comparing it with itself, and process of unwinding recursion begins
