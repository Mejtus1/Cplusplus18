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

