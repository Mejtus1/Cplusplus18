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
// Parameters
// - function contains parameters within its definition, they are required to be present when function is called
// - in example below, function, Add(), adds two integer parameters together
// - parameters are types or values located in between parentheses
// - multiple parameters are separated by commas
void Add(int num1, int num2) {
    cout << num1 + num2 << endl; 
}

int main() {
    Add(5,7); 
    return 0;
}

// - function with 2 parameters 
#include <iostream>
using namespace std;

//add function definitions below this line

/**
 * This function adds two integers together
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 */
void Add(int num1, int num2) {
  cout << num1 + num2 << endl;
}

//add function definitions above this line
  
int main() {
  Add(5, 7);
  return 0;
}
// 12


// - empty function call 
#include <iostream>
using namespace std;

//add function definitions below this line

/**
 * This function adds two integers together
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 */
void Add(int num1, int num2) {
  cout << num1 + num2 << endl;
}

//add function definitions above this line
  
int main() {
  Add();
  return 0;
}
// code/functions/parameters.cpp: In function ‘int main()’:
// code/functions/parameters.cpp:19:7: error: too few arguments to function ‘void Add(int, int)’
//    Add();
//        ^
// code/functions/parameters.cpp:12:6: note: declared here
//  void Add(int num1, int num2) {
//       ^~~

// IMPORTANT
// - number of arguments within main() should match number of parameters specified in function 
// - if there are three parameters, then there should be three arguments as well

// - argument type should also match parameter type
// - if function requires three integers, then arguments should also consist of three integers 
// - you cannot provide string argument for integer parameter


//--------------------
// Order of Parameters
void AddSub(int num1, int num2, int num3) {
  System.out.printIn(num1+num2-num3);
}
  
int main() {
  AddSub(5,10,15);
  return 0;
}

// - much like how C++ programs run code from left to right and then top to bottom, parameters are also read same way
// - because of this, order of parameters is important first argument in function call will be matched with first parameter 
// in function header, second argument from function call will be second parameter in function header

#include <iostream>
using namespace std;

/**
 * This function adds the first two integers together,
 * then subtracts the third integer
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 * @param num3 The third integer
 */
void AddSub(int num1, int num2, int num3) {
  cout << num1 + num2 - num3 << endl;
}
  
int main() {
  AddSub(5, 10, 15);
  return 0;
}
// 0 

// Exercise 
// Matching arguments with parameters 
void MultDiv(double x, double y, double z) {
  cout << x * y / z << endl;
}
  
int main() {
  MultDiv(2, 5, 4);
  return 0;
}
// The argument for z is 4
// The argument for y is 5
// The argument for x is 2

//-------------------------
// Checking Parameter Usage

/**
 * This function divides one integer by the other
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 */
void Divide(int num1, int num2) {
  cout << num1 / num2 << endl;
}
  
int main() {
  Divide(5, 0);
  return 0;
}
// Floating point exception (core dumped)

// - code produces exception. 
// - exception occurs when operation cannot be successfully completed because rule is broken
// - dividing by 0 results in undefined answer
// - when divide 5 by 0 is called, exception is thrown as response 
// - not all exception messages are created equal, some are more clear than others
// - you may choose to clearly define exception by using try, throw, and catch

// Error exceptions defined 
void Divide(int num1, int num2) {
  try {                                               // try this action 
    if (num2 == 0) {
      throw runtime_error("Cannot divide by zero.");  // throw this error if condition is met 
    }
    else {
      cout << num1 / num2 << endl;
    }
  }
  catch (runtime_error& e) {
    cout << e.what() << endl; // Catch exception and print thrown error message 
  }
}

// Whole code with exceptions 
/**
 * This function divides one integer by the other
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 */
void Divide(int num1, int num2) {
  try {
    if (num2 == 0) {
      throw runtime_error("Cannot divide by zero.");
    }
    else {
      cout << num1 / num2 << endl;
    }
  }
  catch (runtime_error& e) {
    cout << e.what() << endl;
  }
}

int main() {
  Divide(5, 0);
  return 0;
}
// 

// What happens if you:
// Change the function call to Divide(5, 2);? 
// 2 
// Change the function call to Divide(0, 2);?
// 0
// Change the function call to Divide(14.5, 2);?
// 7
// Change the function call to Divide(14.5, "2");?
// error 

// - it’s important to note that when arguments are passed as parameters, C++ tries to implicitly cast arguments as specified parameter type(s) first 
// - in example above, both 14.5 and 2 get cast as ints, than 14.5 loses its trailing decimal places and becomes 14
// - on other hand, string "2" cannot be implicitly cast as int causing system to fail to compile
// - only C++ exceptions can be catched, not compilation errors
// - runtime_error() is one example of exception that can be used to produce specified error message
// - e is variable name for which you are calling exception by
// - in C++, exceptions are caught by reference, not value than runtime_error& e is preferred over runtime_error e
// - for list of other exceptions, visit: C++ Exceptions https://en.cppreference.com/w/cpp/error/exception

// Exercise 
// Which of the following can a try, throw, and catch block do?
// d) Catch exception
// - try, throw, and catch block can be used to catch exceptions 
// - it cannot be used to catch compilation errors, which is job of compiler itself

//-------------------------------------
// - Function with Different Parameters
// - in C++, you are allowed to define functions with same name as long as parameters are different in quantity or type 

/**
 * This function adds two integers together
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 */
void Add(int num1, int num2) {
  cout << num1 + num2 << endl;
}

/**
 * This function adds three integers together
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 * @param num3 The third integer
 */
void Add(int num1, int num2, int num3) {
  cout << num1 + num2 + num3 << endl;
}

int main() {
  Add(3, 14);
  return 0;
}
// 17 

// What happens if you:
// Change the function call to Add(3, 14, 9);?  
// 26
// Change the function call to Add(3, 14, 9, 2);?
// error 

// - two Add() functions above differ in number of parameters they have
// - example of two functions with same name but different parameter types: 

/**
 * This function adds two integers together
 * 
 * @param num1 The first integer
 * @param num2 The second integer
 */
void Add(int num1, int num2) {
  cout << num1 + num2 << endl;
}

/**
 * This function prints an integer followed
 * by a string
 * 
 * @param num1 The integer
 * @param num2 The string
 */
void Add(int num1, string num2) {
  cout << num1 << num2 << endl;
}

int main() {
  Add(3, 14);
  return 0;
}
// 17 

// What happens if you:
// Change function call to Add(3, "14");?
// 14
// Change function call to Add("14", 3);?
// error 

// Exercise 
// Functions and parameters 
void MyFunction(string x, int y) {
  cout << x << y << endl;
}

int main() {
  MyFunction("High", 5);
  return 0;
}

//----------------------------
// Alternative Parameter Types 
// - function parameters do not necessarily need to belong to one of four commonly used data types(int, string, double, bool)
// - parameters can be arrays/vectors and even objects

/**
 * This function prints all values of an array
 * 
 * @param array A string array
 */
void PrintArray(string array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << endl;
  }
}

int main() {
  string names[] = {"Alan", "Bob", "Carol"};
  int len = sizeof(names) / sizeof(names[0]);
  PrintArray(names, len);
  return 0;
}
// Alan
// Bob
// Carol

// What happens if you:
// Change string names[] = {"Alan", "Bob", "Carol"}; to string names[3];?
// done mark 
// Add names[0] = "Alan"; to line below string names[3];?
// Alan
//
// 
// Change first function parameter of string array[] to string* array?
// error 

// Why Doesn’t the Code Below Work?
/**
 * This function prints all values of an array
 * 
 * @param array A string array
 */
void PrintArray(string array[]) {
  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    cout << array[i] << endl;
  }
}

int main() {
  string names[] = {"Alan", "Bob", "Carol"};
  PrintArray(names);
  return 0;
}
// code/functions/altparameters.cpp: In function ‘void PrintArray(std::__cxx11::string*)’:
// code/functions/altparameters.cpp:13:35: warning: ‘sizeof’ on array function parameter ‘array’ will return size of ‘std::__cxx11::string* {aka std::__cxx11::basic_string<char>*}’ [-Wsizeof-array-argument]
//    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
//                                    ^
// code/functions/altparameters.cpp:12:30: note: declared here
// void PrintArray(string array[]) {

// IMPORTANT
// - when array is passed as function argument in C++, system treats array as pointer that points to first element within array
// - parameter string array[] is same as string* array
// - due to this, knowledge of size of array is lost, that is why it is good practice to include 
// integer parameter for functions involving arrays so that size can be calculated and stored before those functions are called

// Exercise 
// Vector Parameters
// Rearrange code blocks so that function takes in vector called vect and prints its element(s). 
// Within the main() function, a vector called names is created and the element Alan is added to it. 
// Then the PrintVector function is called.
// Hint: When referring to a vector as a parameter, it is always preferred that it be referred as a reference, 
// not value. For example, void MyFunction(vector<int>& my_vector) is preferred over void MyFunction(vector<int> my_vector).
void PrintVector(vector<string>& vect) {
  for (string s : vect) {
    cout << s << endl;
  }
}

int main() {
  vector<string> names;
  names.push_back("Alan");
  PrintVector(names);
  return 0;
}
// - function needs to be defined
// - only function available other than main() is void PrintVector(vector<string>& vect)
// - to print vector, you will need for loop, thus for (string s : vect) comes next
// - to print elements, simply use cout << s << endl
// - main() function, vector needs to be created before elements can be added
// - vector<string> names and names.push_back("Alan") are needed respectively 
// - to call function and provide vector as argument, use PrintVector(names) and then return 0

//-----------
// Exercise 1 
// Which of the following arguments are appropriate for the function:
void Combine(int x, int y, string z) {
  ...
}
// a) 5, 10, "15"

//------------
// Exercise 2 
// Complete program below so that function takes in double called diameter, calculates circumference, and prints it
void FindCircumference(double diameter) {
  cout << diameter * 3.14 << endl;
}

int main() {
  
FindCircumference
    (2.2);
      return 0;
}

//---------------------------------------------------------------------------------------------------//
// Local Scope 

// - take look at code below, 
// - first function declares variable my_var and then prints it
// - second function also prints my_var
// - what is result ? 
void MyFunction1() {
  string my_var = "Hello";
  cout << my_var << endl;
}

void MyFunction2() {
  cout << my_var << endl;
}

int main() {
  MyFunction1();
  MyFunction2();
  return 0;
}
// - C++ returns error such as error: ‘my_var’ was not declared in this scope at line containing cout << my_var << endl;within second function
// - this happens because variables declared inside function have local scope
// - variables with local scope can only be used within that function
// - outside of that function, those local variables cannot be accessed
// - in code below, light blue box represents scope of my_var
// - since MyFunction2 (denoted in light red box) is outside scope of my_var, error occurs

void MyFunction1() {
  string my_var2 = "Hello";
  cout << my_var2 << endl;
}

void MyFunction2() { 
  cout << my_var << endl; 
}

int main() { 
  MyFunction1();
  MyFunction2(); 
  return 0; 
}

//-----------------
// More Local Scope
// - each function has its own local scope 
// - that means you can declare two variables with same name as long as they are in separate functions
// - blue my_var exists only in light blue box, and red my_var exists only in light red box
// - boundaries of local scope keep C++ from overwriting value of first variable with contents of second

void MyFunction1() {
  string my_var = "Hello";
  cout << my_var << endl;
}

void MyFunction2() {
  string my_var = "Bonjour";
  cout << my_var << endl;
}

int main() {
  MyFunction1();
  MyFunction2();
  return 0;
}
// Hello
// Bonjour

// What happens if you:
// Declare MyFunction3() as:
void MyFunction3() {
  string my_var = "Hola";
  cout << my_var << endl;
}
// and call it by including MyFunction3(); within the main() function ? 
// Hello
// Bonjour
// Hola

// Exercise 
// Fill in the blanks below to accurately complete the statements.

// Variables
//  declared inside a function have 
// local
//  scope. This means you can only reference the variable from 
// inside
//  the function. Trying to reference the variable from 
// outside
//  the function will cause an error.

//-------------------------------------
// Global Scope - Referencing Variables 
// - when variable is declared inside function, it has local scope
// - when variable is declared outside of all existing functions, it has global scope
// - since global variables are declared outside of functions, they can be referenced inside any function

string greeting = "Hello"; //global variable

void SayHello() {
  cout << greeting << endl; //can access global variable greeting
}

int main() {
  SayHello();
  return 0;
}
// Hello 

//-----------------------------------
// Global Scope - Modifying Variables 
// - once global variable becomes available, function can modify content of that variable as needed
string greeting = "Hello";

void SayHello() {
  greeting = "Bonjour";
  cout << greeting << endl;
}

int main() {
  SayHello();
  return 0;
}
// Bonjour 

// What happens if you:
// Change greeting = "Bonjour"; within SayHello() to greeting = "Hola";?
// 
// Change the entire program to:
string greeting = "Hello";

void SayHello1() {
  greeting = "Bonjour";
  cout << greeting << endl;
}

void SayHello2() {
  cout << greeting << endl;
}

int main() {
  SayHello1();
  SayHello2();
  return 0;
}
// 

// - notice how in code above functions SayHello1() and SayHello2() end up printing same output 
// - result of greeting within SayHello2() is affected by modification of greeting within SayHello1()

// - greeting variable is declared outside of any function, making it global variable
// - when SayHello1() modifies greeting, it modifies global variable greeting because it is accessing global variable due to its name being same
// - in well-designed program, it's generally good practice to avoid relying on global variables and to instead pass variables as 
// parameters to functions or to use return values to communicate between functions
// - this helps prevent unintended side effects and makes code easier to understand and maintain
// - if you want SayHello1() to modify local variable instead of global one, you could declare local 
// variable named greeting within SayHello1(), and it would only affect local scope of that function

//----------------------
// Global vs Local Scope 
// - if variable is declared and initialized both locally and globally, that variable will retain its content depending on how it is used
// - in example below, my_var is declared and initialized globally as global scope and locally as local scope
// - since variable has differing scopes, it retains its value when called or printed
string my_var = "global scope";

void PrintScope() {
  string my_var = "local scope";
  cout << my_var << endl;
}

int main() {
  PrintScope();
  cout << my_var << endl;
}
// local scope 
// global scope 

// - exception to this rule is when function modifies global variable
// - in such case, content of global variable is changed

string my_var = "global scope";

void PrintScope() {
  my_var = "local scope";
  cout << my_var <<endl;
}

int main() {
  PrintScope();
  cout << my_var << endl;
}
// local scope 
// local scope 

// What happens if you:
// Change the code to:
string my_var = "global scope";

void PrintScope(string my_var) {
  my_var = "local scope";
  cout << my_var << endl;
}

int main() {
  PrintScope(my_var);
  cout << my_var << endl;
}
// local scope
// global scope

// - when global variable is also function parameter, it is considered to be same as if function declared and initialized its own local variable 
// - in this case, variable has both local and global scope and will retain its value depending on its scope

//-----------------
// "const" Keyword
// - if you want global variable to remain unchanged throughout program, you can declare variable as const
// - const variables are also referred to as constants
// - constants never change and are “named with leading ‘k’ followed by mixed case underscores can be used as separators in rare cases where capitalization cannot be used for separation”

// - another common way to label constants is to use names in all uppercase with words separated by underscore (_)
// - example: MY_CONSTANT

const string kMyConstant = "I NEVER CHANGE";

void PrintScope() {
  kMyConstant = "I CAN'T CHANGE";
  cout << kMyConstant << endl;
}

int main() {
  PrintScope();
  cout << kMyConstant << endl;
}
// error: assignment of read-only variable 'kMyConstant'


// What happens if you:
// Remove the keyword const from the code?
// I CAN'T CHANGE
// I CAN'T CHANGE

// Exercise 1
// Fill in blanks below with correct terms
// If a variable is declared and initialized both globally and locally, that variable will 
// retain its value depending on its scope.
// If a global variable is modified by a function, it will loseits global value and take on its local value instead.
// Variables that are labeled as const are also known as constants and cannot be modified after initialization.

// Exercise 2 
// Using Constants
// Fill in partial program below with code so that function IsEligible() will use constant kMinAge to determine voter eligibility.
const int kMinAge = 18;

void IsEligible(int age) {
  if (age >= kMinAge) {
    cout << "Eligible" << endl;
  }
  else {
    cout << "Not eligible" << endl;
  }
}
// - constants cannot be modified and are denoted with “k” followed by mixed cased words and underscores along with being declared as const (according to Google)
// - constant here is kMinAge and it is being used in comparison with integer parameter age
// - if age is greater than or equal to constant, then voter is eligible, if not, then voter is not eligible

// Exercise 3 
// Given the variable:
string result = "pass";
// Drag and arrange code blocks below so that the function PassFail(int grade) will modify result to "fail" if the grade is less than 65. 
// Finally, the function will print result.
void PassFail(int grade) {
  if (grade < 65) {
    result = "fail";
  }
  cout << result << endl;
}
// - first thing to notice is that grade is int because it is being compared to integer 65. 
// - we want < 65, not <= 65. Since result is being modified to "fail", you should not redeclare result string again
// - using string result = "fail"; will create local variable, which we do not want

//---------------------------------------------------------------------------------------------------//
// Return Keyword
// - instead of just printing data, functions can also return data
// - sizeof() and length() functions help return size or length (in integer) of array and string respectively
// - return value of these functions is of type int
// - both sizeof() and length() do not print anything to screen, they just return number 
// - From here on out, user-defined functions will avoid just printing to the screen. 
// - instead, they will return value
// - to return value, simply use return keyword

/**
 * This function adds 5 to an integer
 * 
 * @param num An integer
 * @return The integer added to 5
 */
int AddFive(int num) {
  return num + 5;
}

int main() {
  AddFive(10);
  return 0;
}

// - program no longer prints anything to screen, which is cause for message, Command was successfully executed
// - function only adds 5 to whatever parameter is passed to function and then returns it internally
// - to see result, explicitly tell C++ to print return value of function to screen
/**
 * This function adds adds 5 to an integer
 * 
 * @param num An integer
 * @return The integer added to 5
 */
int AddFive(int num) {
  return num + 5;
}

int main() {
  int newNum = AddFive(10);
  cout << newNum << endl;
  return 0;
}
// 15 

// What happens if you:
// - remove all lines of code within main() and replace them with just cout << AddFive(10) << endl; and then return 0;?
// error 

//-------------------
// Returning Values 
// - functions can return any value in C++ = ints, doubles, strings, vectors, ... 

/**
 * This function adds two integers together
 * 
 * @param x The first integer
 * @param y The second integer
 * @return x added to y
 */
int ReturnInt(int x, int y) { //int function
  return(x + y);
}

/**
 * This function adds two doubles together
 * 
 * @param x The first double
 * @param y The second double
 * @return x added to y
 */
double ReturnDouble(double x, double y) { //double function
  return(x + y);
}

/**
 * This function adds two strings together
 * 
 * @param x The first string
 * @param y The second string
 * @return x added to y
 */
string ReturnString(string x, string y) { //string function
  return(x + y);
}

int main() { //int function
  cout << ReturnInt(1, 2) <<endl;
  cout << ReturnDouble(1, 2) <<endl;
  cout << ReturnString("1", "2") << endl;
  return 0;
}
// 3 
// 3 
// 12 

//--------------------------------------------
// Can you write function that returns vector?
// If you want to return vector, one possible approach is to have vector be passed as parameter. 
// You can then modify vector in some way, and then return it to system.

// - code below takes vector of numbers as parameter for function MultiplyFive() 
// - function creates new empty vector, multiplies each element of parameter vector by 5, and then adds those new products to new vector
// - To print returned vector, use another enhanced for loop to iterate through vector after it has been initialized

vector<int> MultiplyFive(vector<int>& my_list) {
  vector<int> new_list;
  for (auto a : my_list) {
    new_list.push_back(a * 5);
  }
  return new_list;
}

int main() {
  vector<int> numbers;
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);

  vector<int> print_list = MultiplyFive(numbers);
  for (auto a : print_list) {
    cout << a << endl;
  }
  
  return 0;
}
// 5
// 10
// 15
// 20 
// 25 

// Exercise 
// Given the following function definition:
int* GetNumbersList(int* numbers) {
  return numbers;
}
// What is return type of the function?
// b) integer pointer 
// - return type is specified in every function header, return type is int* which represents pointer that points to int
// - note that numbers is representation for pointer, it is not actual data type

//-------------------------
// Helper Functions
// - Helper functions are functions that are called from within other functions
// - take, for example, formula for calculating area of circle:
// A = PIr**2

// - it would be quite easy to write C++ function to calculate area of circle 
// - instead of knowing radius of circle, you have X/Y coordinates for point at center of circle and another point on circle
// - distance formula (which is based on Pythagorean Theorem) can calculate radius of circle
// SQUARE ROOT OF((x2 - x1)**2 + (y2 - y1)**2)

// - FindRadius() function uses distance formula to calculate distance between 2 pairs of points
// - FindArea() function finds area of circle by relying on FindRadius() function
// - FindRadius() function is helper function
// - helper functions help shorten how much code is needed to accomplish certain tasks

#include <iostream>
#include <math.h>
#define M_PI  3.14159265358979323846 /* pi */
using namespace std;

/**
 * This function finds the radius of a circle given 
 * two coordinate points
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return The radius of a circle in double
 */
double FindRadius(double x1, double y1, double x2, double y2) {
  return(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

/**
 * This function finds the area of a circle given 
 * two coordinate points
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return The area of a circle in double
 */
double FindArea(double x1, double y1, double x2, double y2) {
  return(M_PI * pow(FindRadius(x1, y1, x2, y2), 2));
}

int main() {
  cout << FindArea(0.0, 0.0, 4.0, 4.0) << endl;
  return 0;
}
// 100.531

// Math Functions
// - in order to perform certain functions such as finding square or exponent, we need to include <math.h> in header 
// as well as to define M_PI which represents pi
// - if those are removed from program header, math functions associated with <math.h> will no longer work
// - these functions also serve as helper functions

//-----------
// Exercise 1
// Determine Helper Function
// Given code snippet:
double GetBaseHeight(double b, double h) {
  return b * h;
}
double GetTriangleArea(double b, double h) {
  return GetBaseHeight(b, h) / 2;
}
int main() {
  cout << GetTriangleArea(3, 4) << endl;
}
// d) GetBaseHeight()
// - GetBaseHeight() helps GetTriangleArea() perform particular task
// - this makes GetBaseHeight() helper function

//-----------
// Exercise 2
// - returning "Pass" or "Fail"
// - using code block below, construct function called passes() that takes in integer parameter called grade and returns boolean value of true if grade is "passing"
// - passing grade is defined as having grade of 65 or higher
// - remember to indent all associated commands or you will not receive credit for your work
bool passes(int grade) {
  return (grade >= 65);
}
// - first step is to determine return value of function. 
// - problem asks for boolean return value, therefore function header should be bool passes(int grade) 
// - note how parameter is int since function requires integer 
// - boolean statement needs to be returned as true if grade is greater than or equal to 65
// - rather than using conditional, we can simply return boolean expression: return (grade >= 65);

//-----------
// Exercise 3 
// Helper Math Functions
// In physics, velocity can be defined as velocity = change in position / time and change in position can be defined as p_change = p_final - p_start
// Fill in blanks below so that the function FindPositionChange() is called within FindVelocity().
// Sample Output:
// If cout << FindVelocity(0, 100, 10)) << endl; is printed, then the output will be 10.0.

double FindPositionChange(double p_start, double p_final) {
  double p_change = p_final - p_start;
  return p_change;
}

double FindVelocity(double p_start, double p_final, double time) {
  return FindPositionChange(p_start, p_final) / time;
}
// - first step is to determine return value for FindPositionChange()
// - since we know that p_start and p_final are doubles, it is best practice to also keep change in position as double
// - otherwise, valuable information will be lost if converted to int 
// - recognize that change in position p_change is difference between p_final and p_start 
// - then return p_change

// - for FindVelocity(), keep two parameters same, p_start and p_final
// - notice that there is third parameter called time
// - ss per formula, velocity = change in position / time, FindPositionChange(p_start, p_final) can be called to calculate change in position
// - all that’s left is to divide that calculation by time

//---------------------------------------------------------------------------------------------------//
// Functions Exercises 

//-----------
// Exercise 1 

// Slope Formula
// - write function that takes in 4 doubles as parameters
// - these parameters represent two sets of coordinate points labeled as x1, y1, x2, and y2
// - function will then use these points to calculate slope that their line creates and then prints that slope to user

// Function Header
// - set up function header, as usual, we will start off with our return type
// - result is simply printing slope, we will use void as return type
// - name function GetSlope()
void GetSlope() {
}

// Parameters
// - function should take 4 doubles as parameters named x1, y1, x2, and y2
void GetSlope(double x1, double y1, double x2, double y2) {
}

// Printing the Slope
// - final step is to print slope, but we’ll need slope formula in order to do that 
// - slope formula is defined as (y2 - y1) / (x2 - x1)
cout << (y2 - y1) / (x2 - x1) << endl;

// Testing Function
// - in order to use function, you’ll need to call it by specifying its name within main() function
// - function requires parameters so we’ll need to provide some arguments in order for function to work properly 
// - use points (3, 2) and (5, 6) as our coordinates which correspond to (x1, y1) and (x2, y2) respectively 
// - it is best practice to include return 0 as last statement inside main()
int main() {
  GetSlope(3, 2, 5, 6);
  return 0;
}

// GetSlope() function will apply slope formula (6 - 2) / (5 - 3) and print result 2.0 to the user

void GetSlope(double x1, double y1, double x2, double y2) {
  cout << (y2 - y1) / (x2 - x1) << endl;
}

int main() {
  GetSlope(3, 2, 5, 6);
  return 0;
}

//-----------
// Exercise 2

// Variable Scope: Local and Global Variables 
// - we are going to be adding local and global variables to our previously created GetSlope() function 
// - global variables exist outside of functions, local variables exist inside functions 
// - depending on how you declare your local and global variables, they will behave differently per situation

// Global Variables
// - let’s add some global variables to our program
double input1;
double input2;
double input3;
double input4;

// GetSlope() Function
// - as from before, function will still take 4 doubles as parameters named x1, y1, x2, and y2. 
// - implement two different calculations within function
// - calculate difference between y coordinates first, then calculate difference between x coordinates
// - these calculations will then be assigned to local variables called y_change and x_change
// - function will print quotient between y_change and x_change, which is also slope itself
void GetSlope(double x1, double y1, double x2, double y2) {
  double y_change = y2 - y1;
  double x_change = x2 - x1;
  cout << y_change / x_change << endl;
}

// Testing Function
// - to make things more dynamic, we’ll actually make use of cin within main() function 
// - cin will take in inputs from user and assign them to our 4 global variables input1, input2, input3, and input4
// - these inputs will later correspond to x1, y1, x2, and y2, having cin enables user to decide what coordinate points will be
int main() {
  cout << "Enter first x coordinate: " << endl;
  cin >> input1;
  cout << "Enter first y coordinate: " << endl;
  cin >> input2;
  cout << "Enter second x coordinate: " << endl;
  cin >> input3;
  cout << "Enter second y coordinate: " << endl;
  cin >> input4;
  
  GetSlope(input1, input2, input3, input4);
}

// - notice that you have access to Terminal which you will use to input any coordinate points you want 
// - If 3, 2, 5, is entered and 6 respectively, you should get 2 since cout removes all trailing zeros

#include <iostream>
#include <vector>
using namespace std;

//add code below this line

double input1; //global
double input2; //global
double input3; //global
double input4; //global

/**
 * This function prints the slope between two sets
 * of coordinate points by calculating their coordinate
 * changes separately
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return No return value
 */
void GetSlope(double x1, double y1, double x2, double y2) {
  double y_change = y2 - y1;
  double x_change = x2 - x1;
  cout << y_change / x_change << endl;
}

int main() {
  cout << "Enter first x coordinate: " << endl;
  cin >> input1;
  cout << "Enter first y coordinate: " << endl;
  cin >> input2;
  cout << "Enter second x coordinate: " << endl;
  cin >> input3;
  cout << "Enter second y coordinate: " << endl;
  cin >> input4;

  GetSlope(input1, input2, input3, input4);
}

//add code above this line

// Program Flow
// - after program is initiated, global variables will be created first
// - next main() will run, although commonly written last, main() will always be first function to run by default in C++
// - lines of code within main() will be executed in order of their appearance

//------------
//Exercise 2.1 
// Local & Global Variables
// Determine whether each statement below is true or false

// Any function can access any global variable: 
// true
// Any global variable can be assessed by any of the functions within the program.

// Local variables can be accessed by other functions: 
// false
// Local variables are exclusive to the functions they are declared in. 
// They cannot be accessed anywhere else.

// A local and global variable cannot be declared with the same name or the compiler will fail: 
// false
// Declared local and global variables are considered to be separate variables. 
// This means they do not affect each other and are allowed in C++.

// Global variables can be declared as function parameters: 
// true
// function parameters are similar to local variables; they are both declared within a function. 
// This separates them from global variables which means it is possible to declare parameters that share the same name as the global variables.


//-----------
// Exercise 3

// Returning Value 
// - when result of function is simply print statement, it is considered to be void function
// - void functions do not have return type, meaning they do not return data back to user
// - to return data, use keyword return followed by data
// - note that functions with return must be declared with same data type as data that they return
// - function that returns double must be declared in header as double function

double GetSlope(double x1, double y1, 
                double x2, double y2) { //replace void with double
  double y_change = y2 - y1;
  double x_change = x2 - x1;
  return y_change / x_change; //returns a double
}

// Modifying return value 
// - function returns single double, which is nice but not extremely helpful when it comes to determining rise and run for slopes (rise / run)
// - instead to express slope in rise / run format
// - rise is change in y values and run is change in x values
// - Unfortunately, we can’t simply do return y_change + " / " + x_change. Why? 
// - because " / " is string which is not compatible with current return value of double
// - way around this is to convert doubles into strings
// - doing so will force us to change our double function into string function

string GetSlope(double x1, double y1, 
                double x2, double y2) { //replace double with string
  double y_change = y2 - y1;
  double x_change = x2 - x1;
  return to_string(y_change) + " / " + to_string(x_change); //returns a string
}
// - to_string() to convert our doubles into strings

// Completing Program 
// - copy over the rest of previously written program

double input1;
double input2;
double input3;
double input4;
  
/**
 * This function returns the slope between two sets
 * of coordinate points by calculating their coordinate
 * changes separately
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return A string expression of the slope in rise / run format
 */
string GetSlope(double x1, double y1, 
                double x2, double y2) {
  double y_change = y2 - y1;
  double x_change = x2 - x1;
  return to_string(y_change) + " / " + to_string(x_change);
}
  
int main() {
  cout << "Enter first x coordinate: " << endl;
  cin >> input1;
  cout << "Enter first y coordinate: " << endl;
  cin >> input2;
  cout << "Enter second x coordinate: " << endl;
  cin >> input3;
  cout << "Enter second y coordinate: " << endl;
  cin >> input4;
  
  GetSlope(input1, input2, input3, input4);
}

// Printing Slope 
// - if we try to run the program, we will not see anything printed to screen, Why? 
// - because there is no print statement anywhere within the code
// - all program does is calculate and return values, returning values and printing them are not same thing
// - we need to include print statement if we want to actually see output
// - print statement cannot be just included because it is string function, not void one
// - use main() function to print our desired output

double input1;
double input2;
double input3;
double input4;
  
/**
 * This function returns the slope between two sets
 * of coordinate points by calculating their coordinate
 * changes separately
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return A string expression of the slope in rise / run format
 */
string GetSlope(double x1, double y1, 
                double x2, double y2) {
  double y_change = y2 - y1;
  double x_change = x2 - x1;
  return to_string(y_change) + " / " + to_string(x_change);
}

int main() {
  cout << "Enter first x coordinate: " << endl;
  cin >> input1;
  cout << "Enter first y coordinate: " << endl;
  cin >> input2;
  cout << "Enter second x coordinate: " << endl;
  cin >> input3;
  cout << "Enter second y coordinate: " << endl;
  cin >> input4;
  
  cout << GetSlope(input1, input2, input3, input4) << endl;
  //prints what is returned by the GetSlope() function
}

// Semi-Exercise 
// - Which of the following functions has an incorrect return type?

string MyFunction(int a, int b) { // a)
  return a + b;
}

int MyFunction(int a, int b) { // b)
  return a + b;
}

double MyFunction(int a, int b) { // c) 
  return a + b;
}

void MyFunction(int a, int b) { // d) 
  cout << a + b << endl;
}

// correct answer is a) and c) 
// a) 
// - has incorrect return type because it is trying to return int while being string function
// - without any conversion, C++ will not automatically convert integers into strings and will produce error
// c) 
// - works because int can be expressed as double. 
// - return statement is associated with int but function expects double to be returned
// - this causes function to return value that is different from its return type

// incorrect answers are b) and d) 
// - matching return types: int with int and void with cout


//-----------
// Exercise 4

// Helper Functions 
// - when function calls another function, it is using that function to help it perform particular action 
// - helper functions provide users with more flexibility when it comes to developing functions 
// - helper functions help reduce code repetition because same action only has to be written once

/**
 * This function returns the difference in y values
 * 
 * @param y1 A double of the first y-coordinate
 * @param y2 A double of the second y-coordinate
 * @return The difference of y1 and y2 as a double
 */
double GetRise(double y1, double y2) {
  return y2 - y1;
}

/**
 * This function returns the difference in x values
 * 
 * @param x1 A double of the first x-coordinate
 * @param x2 A double of the second x-coordinate
 * @return The difference of x1 and x2 as a double
 */
double GetRun(double x1, double x2) {
  return x2 - x1;
} 

// - above, are have two functions
// - one calculates rise of slope and another calculates run of slope
// - these two helper functions will come in handy in out later slope calculations

// Using helper functions 

/**
 * This function returns the slope in decimal form
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return A double expression of the slope
 */
double GetSlopeDecimal(double x1, double y1, 
                       double x2, double y2) {
  return GetRise(y1, y2) / GetRun(x1, x2);
}

/**
 * This function returns the slop in fraction form
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return A string expression of the slope in rise / run format
 */
string GetSlopeFraction(double x1, double y1, 
                        double x2, double y2) {
  return to_string(GetRise(y1, y2)) + " / " + to_string(GetRun(x1, x2));
  //need to convert doubles to strings!
}

// - notice how within two functions above GetSlopeDecimal() and GetSlopeFraction(), previous helper functions GetRise() and GetRun() are called
// - having 4 functions at our disposal provides us with flexibility that single function cannot offer
// - in this program, we can get slope in its decimal form and its fraction form in addition to rise and run individually
// - if we wanted, we can continue to build more into this program

// Complete and run program 

double input1;
double input2;
double input3;
double input4;
  
/**
 * This function returns the difference in y values
 * 
 * @param y1 A double of the first y-coordinate
 * @param y2 A double of the second y-coordinate
 * @return The difference of y1 and y2 as a double
 */
double GetRise(double y1, double y2) {
  return y2 - y1;
}

/**
 * This function returns the difference in x values
 * 
 * @param x1 A double of the first x-coordinate
 * @param x2 A double of the second x-coordinate
 * @return The difference of x1 and x2 as a double
 */
double GetRun(double x1, double x2) {
  return x2 - x1;
} 

/**
 * This function returns the slope in decimal form
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return A double expression of the slope
 */
double GetSlopeDecimal(double x1, double y1, 
                       double x2, double y2) {
  return GetRise(y1, y2) / GetRun(x1, x2);
}

/**
 * This function returns the slop in fraction form
 * 
 * @param x1 A double of the first x-coordinate
 * @param y1 A double of the first y-coordinate
 * @param x2 A double of the second x-coordinate
 * @param y2 A double of the second y-coordinate
 * @return A string expression of the slope in rise / run format
 */
string GetSlopeFraction(double x1, double y1, 
                        double x2, double y2) {
  return to_string(GetRise(y1, y2)) + " / " + to_string(GetRun(x1, x2));
}
  
int main() {
  cout << "Enter first x coordinate: " << endl;
  cin >> input1;
  cout << "Enter first y coordinate: " << endl;
  cin >> input2;
  cout << "Enter second x coordinate: " << endl;
  cin >> input3;
  cout << "Enter second y coordinate: " << endl;
  cin >> input4;
  
  cout << "Rise: ";
  cout << GetRise(input2, input4) << endl;
  cout << "Run: ";
  cout << GetRun(input1, input3) << endl;
  cout << "Calculated form: ";
  cout << GetSlopeDecimal(input1, input2, input3, input4) << endl;
  cout << "Slope form: ";
  cout << GetSlopeFraction(input1, input2, input3, input4) << endl;
}

// Semi-exercise 
// Calling Helper Function
// - to determine volume of cylinder, you first have to calculate base of cylinder and then multiply it by calculated height of cylinder
// - formula is cylinder_volume = base_area * height, given following helper function:
double GetBaseArea(double radius) {
  return M_PI * radius * radius;
}
// - function GetCylinderVolume() takes in two parameters, double radius and double height, and returns volume of cylinder as double
double GetCylinderVolume(double radius, double height) {
  return GetBaseArea(radius) * height;
}
// - first step is to determine correct function header
// - based on prompt, function should return double
// - this means function should be declared as double making double GetCylinderVolume(double radius, double height) correct header

// - next, you would want to call helper function GetBaseArea() to help you calculate part of volume
// - GetBaseArea(radius) satisfies function’s parameter requirement
// - based on formula, you’ll need to multiply calculated base by height to find total volume of cylinder
// - this makes return GetBaseArea(radius) * height; only acceptable return statement


//-----------
// Exercise 5

// Create Greeting Machine
// You are going to develop function that takes vector of strings as parameter, iterates through that vector and greets every element in it with "Hello" followed by newline

// Existing Code:
#include <iostream>
#include <vector>
using namespace std;

//add code below this line



//add code above this line

int main(int argc, char** argv) {
  vector<string> names;
  for (int i = 1; i < argc; i++) {
    names.push_back(argv[i]);
  }
  SayHello(names);
}

// answer: 
void SayHello(const vector<string>& names) {
    for (const string& name : names) {
        cout << "Hello " << name << endl;
    }
}

// Whole code 
#include <iostream>
#include <vector>
using namespace std;

//add code below this line

void SayHello(const vector<string>& names) {
    for (const string& name : names) {
        cout << "Hello " << name << endl;
    }
}

//add code above this line

int main(int argc, char** argv) {
  vector<string> names;
  for (int i = 1; i < argc; i++) {
    names.push_back(argv[i]);
  }
  SayHello(names);
}

//---------------------------------------------------------------------------------------------------//
//-----------
// Exercise 1 

// Functions Exercise 1
// - write function called GetAvg() that takes two double parameters and returns average of these two parameters as double
// - if either of parameters is not double or integer, program will catch exception and print One or more invalid arguments..

// exsiting code 
#include <iostream>
#include <vector>
using namespace std;

//add code below this line



//add code above this line

int main(int argc, char** argv) {
  try {
    double x = stod(argv[1]);
    double y = stod(argv[2]);
    cout << GetAvg(x, y) << endl;
  }
  catch (invalid_argument& e) {
    cout << "One or more invalid arguments." << endl;
  }
  return 0;
}

// Requirements
// You should not make any changes to code that already exists. 
// If you accidentally delete any existing code, you can copy and paste entire program from above.
// You can use any number of functions, loops, and/or conditionals to produce desired output.

// simple code 
double GetAvg(double x, double y) { 
    return (x + y) / 2; 
} 

// more complex code 
double GetAvg(double x, double y) {
    if (typeid(x) != typeid(double) || typeid(y) != typeid(double)) {
        throw invalid_argument("One or more invalid arguments.");
    }
    return (x + y) / 2.0;
}

// whole code 
#include <iostream>
#include <vector>
using namespace std;

//add code below this line

double GetAvg(double x, double y) { 
    return (x + y) / 2.0; 
} 

//add code above this line

int main(int argc, char** argv) {
  try {
    double x = stod(argv[1]);
    double y = stod(argv[2]);
    cout << GetAvg(x, y) << endl;
  }
  catch (invalid_argument& e) {
    cout << "One or more invalid arguments." << endl;
  }
  return 0;
}
// Test with 10 & 25
// 17.5 
// Test with 10 & cat
// One or more invalid arguments.
// Test with 2.5 & 3.5
// 3 

// - there are three important tasks in this exercise
// - first is to declare correct function type, second is to declare correct parameters, and third is to provide correct return statement
// - since function returns double, correct function header should be double followed by specified function name and parameter types GetAvg(double x, double y)
// - variable names do not have to be x and y. Next, calculate average of two arguments by adding them together, dividing by 2, and then returning calculation to user
// - main() already has code to capture exception and print error message so you do not have to worry about it


//-----------
// Exercise 2 

// Functions Exercise 2

// - write function called GetOddsEvens() that takes string and int vector as parameters 
// - if string parameter is "true", print only even integers separated by newline
// - if string parameter is "false", print only odd integers separated by newline
// - else, no output will be printed and you will see default message of Command was successfully executed

// exsiting code: 
#include <iostream>
#include <vector>
using namespace std;

//add code below this line



//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  vector<int> y;
  for (int i = 2; i < argc; i++) {
    y.push_back(stoi(argv[i]));
  }
  GetOddsEvens(x, y);
}

// Hint
// - main() functions job is to take first command and assign it to variable x
// - then take second command and every command after and turn those into integers
// - these integers are then added to vector y. 
// - your task is to check whether string is "true" or "false" and print only relevant integers within vector that correspond to those values

// Requirements
// - you should not make any changes to code that already exists
// - if you accidentally delete any existing code, you can copy and paste entire program from above
// - you can use any number of functions, loops, and/or conditionals to produce the desired output

// my code (not right, because of missing auto keyword)
void GetOddsEvens(string x, vector<int>& y) { 
  if (x == "true") {
    for (int i : y) { 
      if (y % 2 == 0) { 
        cout << y << endl; 
      }
    }
  } else if (flag == "false") { 
      for (int i : y) { 
        if (y % 2 != 0) {
          cout << y << endl; 
      }
    } 
  } else {
      return 0; 
  }
}

// correct code 
void GetOddsEvens(string x, vector<int>& y) {
  if (x == "true") {
    for (auto a1 : y) {
      if (a1 % 2 == 0) {
        cout << a1 << endl;
      }
    }
  }
  if (x == "false") {
    for (auto a2 : y) {
      if (a2 % 2 == 1) {
        cout << a2 << endl;
      }
    }
  }
}

// - auto is keyword used in C++ to automatically deduce data type of variable from its initializer
// for (auto a1 : y): 
// - in this loop, auto tells compiler to deduce data type of each element in vector y
// - so, a1 will take on data type of elements in y
// - it's essentially shorthand for explicitly specifying data type, like int, double, etc
// for (auto a2 : y): 
// - similar to previous loop, auto is used to deduce data type of each element in vector y
// - a2 will take on data type of elements in y, but this loop seems to be inteintended to iterate over odd numbers, as indicated by if (a2 % 2 == 1)


// Whole code: 

#include <iostream>
#include <vector>
using namespace std;

//add code below this line

void GetOddsEvens(string x, vector<int>& y) {
  if (x == "true") {
    for (auto a1 : y) {
      if (a1 % 2 == 0) {
        cout << a1 << endl;
      }
    }
  }
  if (x == "false") {
    for (auto a2 : y) {
      if (a2 % 2 == 1) {
        cout << a2 << endl;
      }
    }
  }
}
//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  vector<int> y;
  for (int i = 2; i < argc; i++) {
    y.push_back(stoi(argv[i]));
  }
  GetOddsEvens(x, y);
}

// Compile and test your code with a few different values
// Test with true & 13, 22, 8, 31
// 22
// 8
// Test with false & 13, 22, 8, 31
// 13
// 31 
// Test with true & 1, 2, 3, 4, 5
// 2
// 4 
// Test with false & 1, 2, 3, 4, 5
// 1
// 3
// 5 

// - in order for output to be printed to console, at least one function has to contain some sort of print statement
// - existing code has no print statement, therefore, GetOddsEvens() should incorporate one
// - one strategy is to make return type as void; this way, output can be returned and printed without requiring any specific return types. 
// - parameters must be typed as string and vector<int>& respectively in order to match main() function’s specifications 


//-----------
// Exercise 3

// Functions Exercise 3
// - write function called FindTerm() that takes string term and string vector as parameters
// - if term exists inside vector, then boolean value of true is returned
// - else, term does not exist and false is returned
// - capitalization matters, example: "cat"and "Cat" are not considered same term

// Existing Code:
#include <iostream>
#include <vector>
using namespace std;

//add code below this line



//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  vector<string> y;
  for (int i = 2; i < argc; i++) {
    y.push_back(argv[i]);
  }
  cout << boolalpha << FindTerm(x, y) << endl;
}

// Requirements
// You should not make any changes to the code that already exists. If you accidentally delete any existing code, you can copy and paste the entire program from above.
// You can use any number of functions, loops, and/or conditionals to produce the desired output.

bool FindTerm(string x, vector<string>& y) {
  bool b = false;
  for (auto a : y) {
    if (a == x) {
      b = true;
    }
  }
  return b;
}

// Test with Cat & dog, fish, cat
// false 
// Test with toy & water, toy, house
// true
// Test with mouse & box, car, hat, house
// false 

// - parameters of FindTerm() needs to be string and vector<string>& respectively
// - problem requests that return type of FindTerm() be bool
// - function header should be similar to something like bool FindTerm(string x, vector<string>& y)
// - as for function statements, you can use any statements as long as you check whether specified string parameter is equal to any of string elements inside vector

// Whole code: 
#include <iostream>
#include <vector>
using namespace std;

//add code below this line

bool FindTerm(string x, vector<string>& y) {
  bool b = false;
  for (auto a : y) {
    if (a == x) {
      b = true;
    }
  }
  return b;
}

//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  vector<string> y;
  for (int i = 2; i < argc; i++) {
    y.push_back(argv[i]);
  }
  cout << boolalpha << FindTerm(x, y) << endl;
}


//-----------
// Exercise 4

// - write function called IsPalindrome() that takes string as parameter
// - if string is palindrome (word that is spelled same forward and backward), then function will returnboolean of true
// - if string is not palindrome, then false is returned
// - note that capitalization matters, example, "Level" would not be considered palindrome because uppercase "L" and lowercase "l" are not same
// Existing code: 
#include <iostream>
#include <vector>
using namespace std;

//add code below this line



//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  cout << boolalpha << IsPalindrome(x) << endl;
}

// Hint
// Consider creating new empty string and populating it with characters of specified string in reverse order
// - then check two strings for equality
// - Remember that function should return boolean, therefore, you should declare boolean variable and have that boolean change based on certain conditions
// - then return that variable

// Requirements
// You should not make any changes to code that already exists, if you accidentally delete any existing code, you can copy and paste entire program from above
// You can use any number of functions, loops, and/or conditionals to produce desired output

// whole code: 

#include <iostream>
#include <vector>
using namespace std;

//add code below this line

bool IsPalindrome(string x) {
  bool palindrome = false;
  string y;
  for (int i = x.length() - 1; i >= 0; i--) {
    y += x.at(i);
  }
  if (x == y) {
    palindrome = true;
  }
  return palindrome;
}

//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  cout << boolalpha << IsPalindrome(x) << endl;
}

// Test with Level
// false 
// Test with anna
// true 
// Test with 022220
// true 
// Test with 10 
// false 

// - first step is to create boolean variable and empty string
// - boolean in sample solution is initialized to false but can also be initialized to true if preferred
// - once variables are created, create loop that iterates through given string from back to front 
// - during this process, every character should be appended to empty string
// - once loop is finished, new string should be reverse of given string, to check for equality, you can use ==. 
// - if strings are equal, change boolean value to true, then return boolean


//-----------
// Exercise 5

// Functions Exercise 5
// - like in Exercise 4, your task is to develop function called IsPalindrome() that takes string as parameter
// - if string is palindrome (word that is spelled same forward and backward), then function will return boolean of true
// - if string is not palindrome, then false is returned
// - difference between this exercise and Exercise 4, however, is that you will need to use helper function called Reverse() within IsPalindrome() 
// - Reverse() function takes string as parameter and reverses it
// - then reversed string is returned
// - capitalization matters, example, "Level" would not be considered palindrome because uppercase "L" and lowercase "l" are not same

// Existing Code:

#include <iostream>
#include <vector>
using namespace std;

string Reverse(string x) {
  string y;
  for (int i = x.length() - 1; i >= 0; i--) {
    y += x.at(i);
  }
  return y;
}

//add code below this line



//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  cout << boolalpha << IsPalindrome(x) << endl;
}

// Requirements
// You should not make any changes to the code that already exists. If you accidentally delete any existing code, you can copy and paste the entire program from above.
// You must include the helper function Reverse() within your IsPalindrome() function; otherwise, you will not receive credit for your work!

bool IsPalindrome(string x) {
  bool palindrome = false;
  if (x == (Reverse(x))) {
    palindrome = true;
  }
  return palindrome;
}

// whole code: 

#include <iostream>
#include <vector>
using namespace std;

string Reverse(string x) {
  string y;
  for (int i = x.length() - 1; i >= 0; i--) {
    y += x.at(i);
  }
  return y;
}

//add code below this line

bool IsPalindrome(string x) {
  bool palindrome = false;
  if (x == (Reverse(x))) {
    palindrome = true;
  }
  return palindrome;
}

//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  cout << boolalpha << IsPalindrome(x) << endl;
}


// Test with Level
// false 
// Test with anna
// true 
// Test with 022220
// true 
// Test with 10
// false  

// - helper function Reverse() is supposed to help IsPalindrome() reverse string parameter
// - You’ll still need to declare and initialize boolean variable but then all that’s left to do is to call 
// - Reverse() function and check to see if it returns string that is same as given one
// - if so, boolean value should be changed, than boolean is returned