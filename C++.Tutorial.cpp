//C++ Programming 
//comments are written like in javascript using double /

cout << "Hello World"; //cout << is used to output the code to the console
cout << "My name is Codio";

cout << "Hello"; //outputs code on one line and together 
cout << "world!"; //Helloworld!
cout << endl; //endl = command which adds the newline character.
cout << "My name is Codio." << endl; //returns string on new line 

cout << "Hi!" << endl; //The "Hi!" will print the text Hi! and the endl; will add a newline character. 




//Variables
//Each variable in C++ has a DATA TYPE, VALUE and NAME 
/* 
There are a few different actions taken involving variables:
Declaring - when you set or declare the data type and name of the variable. 
These two properties of a variable do not change. !!
Assigning - when you set the value of the variable. The value of a variable can change.
Accessing - when you retrieve the value of the variable by calling its name.
You must declare and assign a variable before you can access it.
*/
int main() {
	
  //declaring (giving the variable a type)
  int number;
  bool true_or_false;
  char letter;

  //assigning (giving the variable a value)
  number = 99;
  true_or_false = true;
  letter = 'a';
	
  //accessing (retrieving the value of the data by printing)
	cout <<number <<endl;
	cout << true_or_false << endl;
	cout << letter << endl;
	
	return 0;
	  
	}

//Data Type:
//Integers
//Integers (often called ints) are whole numbers. 
//They can be positive or negative. Do not use a comma when typing large numbers.
int number;
number = 50;
cout << number << endl; //50

int number = 50; //short version 
cout << number << endl; //50 

int number1 = 050; //40 octal numbers start with 0 so system converts it to octal 
int number2 = 5000; //5000
int number3 = "50"; //error 

//Data Type:
//Floating point numbers (Floats), 
//Floating point numbers (often called floats) are numbers with a decimal.
//They can be positive or negative.
double decimal = 0.5;
cout << decimal << endl; //0.5

//Why Use DOUBLE Instead of FLOAT? 
/* In C++, there is a data type called float, but as it only uses 4 bytes, 
it is insufficient for most math. 
Instead, we use double which uses 8 bytes or double the space of a float. */
double decimal2 = .0001 //0.0001
double decimal3 = 50. //50
cout << decimal2 << endl;

//Data type: Boolean
//A boolean variable (declared as a bool) can only take on the value of true or false.
bool thisIsFun = true;
cout << boolalpha << thisIsFun << endl; //true
cout << thisIsFun << endl; //1

bool thisIsFun2 = false; 
cout << boolalpha << thisIsFun << endl; //false
cout << thisIsFun << endl; //0

//Declaring True, False TRUE, FALSE will result in error

//Data type:
//Strings
//A string is a collection of text, numbers, or symbols. 
//Strings are always surrounded by quotation marks.
string words = "This is a string.";
cout << words << endl;
//String with capital S throws error, C++ is case sensitive
//'' single quotes cannot be used, throws error 

//Declaring variable
/*Declaring a variable has two parts - setting or declaring the data type and the name of the variable. 
These two properties of a variable do not change.
To declare a variable, type the data type and name of the variable you want to create, 
and a ; (semi-colon). */
string my_var; //variable not declared 
               //console outputs "Command sucessfully executed
               //that is because no value has been assigned yet. 
               //Thus, the message Command was successfully executed. appears"
               //The declaration step only sets aside empty memory.
/* RULES FOR VARIABLES IN C++
            Rule                           Correct                 Incorrect
Start with a letter or underscore	     variable,          _variable	1variable
Remainder of variable name is 
letters, numbers, or underscores	 var_i_able, var1able	  var-i-able, var!able
Cannot use a C++ keyword	               my_class	                  class
Variables are case sensitive: variable, Variable, and VARIABLE are all different variables
*/ 

//C++ key words
//C++ keys words are words that are reserved for specific functions or tasks within C++ programs. 
//These words cannot be used to name variables and will result in errors if they are not handled correctly.
//Examples are: if, variable, string, else, false, true ..... 

//Initializing and assigning values 
//We call the process of setting the initial value of a variable initialization. 
//Recall that you can do this separately after the declaration or combine it into the same statement as the declaration.
int my_int; //declare
my_int = 123; //initialize variable
my_int = 321; //overwrite old value and assign new 
//Since the value stored in a variable can change, we call changing the value assigning or re-assigning.

//Exercise
string greeting = "Hello!"; 
string dayOfWeek = "Monday";
string month = "July";
int day = 4;
int currentWaitMinutes = 15;

cout << greeting << " Today is " << dayOfWeek << ", " << month << " " << day << "." << endl;
cout << "The current wait time is " << currentWaitMinutes << " minutes" << endl;

//Exercise 2
 bool my_bool = true;
  cout << my_bool << endl;
  my_bool = test;
  cout << my_bool << endl;

//Exercise 3
int first_num = 1;
int second_num = 2;
int third_num = 3;

int my_int = first_num;
  cout << my_int << endl;
  my_int = second_num;
  cout << my_int << endl;
  my_int = third_num;
  cout << my_int << endl;

//Exercise 4
double number = 2.48;
double my_double = 3.14;
  cout << my_double << endl;
  my_double = number;
  cout << my_double; 

