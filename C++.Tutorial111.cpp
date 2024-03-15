//---------------------------------------------------------------------------------------------------//
// Function Definition

// Function Syntax 
// - you have seen and used built-in functions like length function (my_string.length())
// - user-defined functions, they are composed of two parts, header and body
void GreetTwice( ) {  ------------------ Function Header 
    cout << "Hello" << endl; ----------- Function Body 
    cout << "Hello" << endl; ----------- Function Body 
}
// - function header may contain several keywords to determine function type
// - next name of function 
// - “Ordinarily, functions should start with capital letter and have capital letter for each new word
// - some examples include: GreetTwice, AddThree, FindArea, 
// - Parentheses are required but parameter(s) within them are not 
// - any command(s) associated with function should be indented as best practice and enclosed within curly braces {}

//----------------
// Function Header
void GreetTwice( )

// key labels of header: 
// void = Return value 
// ( ) = Parameters
// GreetTwice = Function 

// void - Determines whether there is return value or not for function
// - if function has no return value, use void 
// - if function returns integer, use int, etc
// GreetTwice - example of function name 
// () - Parentheses are required for all functions. 
// - any parameters that function takes in will go into parentheses but they are optional

//--------------
// Function Body

void GreetTwice( ){ 
    cout << "Hello" << endl; 
    cout << "Hello" << endl; 
}
// - function body is list of actions function performs
// - all of code for function body should be enclosed within curly braces {} and indented as best practice to show association
// - this convention is similar to how conditionals and loops are written

// Exercise 
// Determine what error is present within the function below:
void SayBye() 
  cout << "Good bye!" << endl;
// answer: command cout << "Good bye!" << endl; should be enclosed within curly braces {}.

//-----------------
// Calling Function

#include <iostream>
using namespace std;

void GreetTwice() {
  cout << "Hello" << endl;
  cout << "Hello" << endl;
}

// - when this functino is called error is thrown 
// /usr/lib/gcc/x86_64-linux-gnu/7/../../../x86_64-linux-gnu/Scrt1.o: In function `_start':
// (.text+0x20): undefined reference to `main'
// collect2: error: ld returned 1 exit status
// - error is produced, happens because when running C++ programs, main function is required

#include <iostream>
using namespace std;

void GreetTwice() {
  cout << "Hello" << endl;
  cout << "Hello" << endl;
}

int main() {
  
}
// Command was succesfully executed 
// - nothing is outputted when program is executed
// - creating function alone does not cause C++ to run it
// - function needs to be explicitly called to run 
// - functions are usually called within main function
// - to call function, simply start with its name, provide any parameters if needed, and end with semicolon
#include <iostream>
using namespace std;

void GreetTwice() {
  cout << "Hello" << endl;
  cout << "Hello" << endl;
}

int main() {
  GreetTwice();
}
// Hello 
// Hello 

#include <iostream>
using namespace std;

void GreetTwice() {
  cout << "Hello" << endl;
  cout << "Hello" << endl;
  cout << "Goodbye" << endl; // added line 
}

int main() {
  GreetTwice();
  GreetTwice(); // added function call 
  return 0;     // return 0 
}
// - adding return 0 to main() in code above doesn’t really cause any changes to program
// - in older versions of C++, command return 0 was required because main() function has return type of int 
// - means function expects some integer value to be returned at end of function 
// return 0 - is another way for program to denote that function has successfully completed
// - Nnewer versions of C++ can run int main() without return 0, however, it is still best practice to include it
// - return type of main() shouldnt be changed to anything other than int = standard in C++ and should remain so

//------------------------------
// Order of Function Definitions
// - order of function definitions is important in C++
// - how regular C++ program runs, function is executed line by line from top to bottom
// - order of statements within function will determine what actions are performed first, second, etc

//-----------------------------
// Order of Different Functions 
// - order of functions themselves also matter
#include <iostream>
using namespace std;

int main() {
  GreetTwice();
  GreetTwice();
  return 0;
}

void GreetTwice() {
  cout << "Goodbye" << endl;
  cout << "Hello" << endl;
  cout << "Hello" << endl;
}
// code/functions/functioncall.cpp: In function ‘int main()’:
// code/functions/functioncall.cpp:5:3: error: ‘GreetTwice’ was not declared in this scope
//    GreetTwice();
//    ^~~~~~~~~~

// - error such as GreetTwice was not declared in this scope
// - how function definitions are read line by line from top to bottom, functions are also read same way 
// - when program gets to first GreetTwice(); within main(), it doesn’t know what to do because functionhas not been declared yet 
// - whenever function is called, make sure it is declared and defined

// Exercise 
// Given following function:
void SayThanks() {
  cout << "Thanks" << endl;
}
// Which of the following function calls will be correctly executed if it was to be called within main()?
// answer: SayThanks();

//--------------
// Documentation

// C++ Code Documentation
// - including C++ code documentation prior to function definitions is standard
// - doing so enables users to gain clarity on purpose of function, any parameters that are used, and what function returns
// - users can also see who wrote function as well as what version function is on. 
// - there are several ways to document C++ code, however style that we will be using for this module models that of Java’s (also known as Javadoc) 
// example: 
/**
 * This is an example of C++ documentation
 * 
 * @author  FirstName LastName
 * @version 1.0
 */
#include <iostream>
using namespace std;

/**
 * This function greets the user twice
 * 
 * @param   specify parameters if any
 * @return  specify return value if any
 */
void GreetTwice() {
  cout << "Hello" << endl;
  cout << "Hello" << endl;
}

int main() {
  GreetTwice();
  return 0;
}

// - C++ code documentation does not affect output of code
// - it provides more clarity to how function is used 
// - Generally speaking, documentation for authors and program version goes at start of program while 
// documentation for parameters and return value goes directly before declared function
// - documentation for the main() function is not required


// ------------
// Doxygen Tool
// - online tool Doxygen = can help generate C++ code documentation
// https://www.doxygen.nl/index.html

//-----------
// Exercise 1 
// - type into blanks below correct C++ documentation code (according to Javadoc style)

// Specifies any parameters that are used within the function: @param
// Specifies any values that are returned from the function: @return
// Specifies the names of those who wrote or developed the function: @author
// Specifies what version the method is currently on: @version

//-----------
// Exercise 2 
// Calling Defined Function

// The main() function of program calls user-defined function by name of PrintActors(). 
// Here is the output of the program:
// Ben Affleck
// Kevin Bacon
// George Clooney
// Drag and arrange the code blocks below so that the output above is printed when PrintActors(); is called.
void PrintActors() {
  cout << "Ben Affleck" << endl;
  cout << "Kevin Bacon" << endl;
  cout << "George Clooney" << endl;
}

//-----------
// Exercise 3 
// Documenting Function
// Fill in blanks below with correct documentation (according to Javadoc) and function syntax

/**
 * This function prints the message "This is my function"
 * 
 * 
@author
  FirstName LastName
 * 
@version
 2.0

*/
// - there are two parts to this problem
// - first part is recognizing that Javadoc is involved and second part is completing function
// - all documentation starts with /** and ends with */ 
// - documentation includes FirstName and LastName which represent author and decimal number which represents version of that function
// - @author and @version are needed respectively 
// - function header needs to have parentheses () following function name by definition

void MyFunction
()
 {
  cout << "This is my function" << endl;
}

//---------------------------------------------------------------------------------------------------//
