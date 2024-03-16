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
