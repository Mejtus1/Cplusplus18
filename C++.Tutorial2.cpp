//Arithmetic Operators
//Addition 
cout << 7 + 3 << endl; //10

int a = 7; //two variables
int b = 3;
cout << a + b << endl; //10

  double a = 7.1; //double 
  int b = 3;
  cout << a + b << endl; //10.1

  double a = 7.1;
  int b = -3; //negative number
  cout << a + b << endl; //4.1

  double a = 7.1;
  int b = +3; //explicitly positive number 
  cout << a + b << endl; //10.1 (normal addition)



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Printing floating point numbers using printf 
//using cout is not always clear if you are using float or int 
int a = 1;
double b = 1.0;
cout << a << endl; //1 - althrough you are printing 1.0 cout will disregard .0
cout << b << endl; //1

//printf
//originates from C and is specific (you specifie the type of data you want to print before command)
int a = 1;
double b = 1.0;
cout << a << endl;
cout << b << endl;
printf("%d \n", a); // %d specifier tells the system to print an integer \functions like endl
printf("%f \n", b); // %f -//- -//- print an float 
                    //incorrect specifier results in error message 
printf("%d \n", a); //1
printf("%f \n", b); //1.000000 = float specifier results in 0.000000 decimal format by default
//COUT is used most of the time, printf is used only in specific situations 



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Incrementing variables 
//Incrementing means increasing value of the variable by 1
int a = 0;
a = a + 1; //typical variable incrementation by itself +1
cout << a << endl; //2

//a++ 
//a++ does the same thing as a = a + 1
int a = 0;
int b = 0;
a = a + 1;         //a++ (a = a + 1)
b++;               //b++ (b = b + 1)
cout << a << endl;
cout << b << endl;

int c = 2;
c+=5; // c = c + 5 (7)
c-=1; // c = c - 1 (1)


//String concatenation 
//Combining two strings together using (+ operator)
string a = "This is an ";
string b = "example string";
string c = a + b; //concatenates a + b variables which store strings 
cout << c << endl;

string a = "This is an ";
string b = "example string";
string c = a+=b; //does nothing outputs same thing like code above
cout << c << endl;

string a = "This is an ";
string b = "example string";
string c = a + b + 3; //error - 3 is an integer and we have data type string 
cout << c << endl;

string a = "This is an ";
string b = "example string";
string c = a + b + "3"; //outputs 3 as an string 
cout << c << endl;



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//subtraction 
int a = 10;
int b = 3;
int c = a - b; //
cout << c << endl;

int a = 10;
int b = -3;
int c = a - b; //10 - -3 = 13 (works like mathematical normal operation-
cout << c << endl;

int a = 10;
int b = 3;
int c = a - -b; // 13 
cout << c << endl;

int a = 10;
int b = -3; //-3
int c = a - -b; //10 - --3 = 7
cout << c << endl;

int a = 10;
int b = 3.1; //no matter what decimal value we assign to the 3
int c = a - b; //the output will be like we are subtracting 3
cout << c << endl; //7 (int disregards decimal places)

int a = 10;
bool b = true; //true = 1 (bool true = int 1, bool false = int 0)
int c = a - b; //9
cout << c << endl;

//SUBTRACTION CANNOT BE USED ON STRINGS 


//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Division 
//Division in C++ is done with the / operator.
double a = 25.0;
double b = 4.0;
printf("%f \n", a / b); //6.250000

double a = 25.0;
double b = 0.0;
printf("%f \n", a / b); //inf (infinity)
double b2 = 0;
printf("%f \n", a / b); //error

double a = 25.0;
double b = 0.5;
printf("%f \n", a / b); //50

int a = 5;
int b = 2;
cout << a / b << endl; //result is 2
                       //in decimal is exact result 2.5 but cout doesnt round it up, 
                       //it basically cuts it off decimals 



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Modulo (modulation)
//Modulo is the mathematical operation that performs division 
//but returns the remainder. The modulo operator is %.
int modulo = 5 % 2;
cout << modulo << endl; //1 

int modulo = 5 % -2; //does nothing with - operator 
int modulo = 5 % 0; //error (dumpred command)
int modulo = 5 % 0.5; //error, we have integer and modulation by float (two other data types)

//Multiplication 
int a = 5;
int b = 10;
cout << a * b << endl; //uses * sign for multiplication, * is multiplication operator 

int a = 5;
int b = 0.1; //0,1 outputs 0 because of int 
cout << a * b << endl;

int a = 5;
int b = -3;
cout << a * b << endl; //-15 (basic math)




//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Exponents and Square roots
/* By default, there are no operators for exponents and square roots. 
Instead, functions such pow( , ) and sqrt() are used to calculate powers and square roots respectively.
In order to use these functions, they must be imported by including #include <cmath> at top of the program header. 
For exponents, the base number goes before the , in pow( , ) and the exponent goes after the ,. 
For example, pow(4, 2) calculates 4 to the power of 2 and pow(4, 0.5) calculates 40 to the power of 0.5 or 40 to the 1/2
For square roots, the number goes inside the () in sqrt(). An example is sqrt(4) which calculates √4 */
cout << pow(2, 2) << endl; //4 
cout << pow(25, (1 / 2)) << endl; //1
cout << pow(25, (1.0 / 2.0)) << endl; //5 it ignoers decimals 
cout << sqrt(25) << endl; //5 

cout << pow(3, 7) << endl; //2187
cout << sqrt(100) << endl; //10

int a = 2;
int b = 3;
int c = 4;
double result = 3 * a - 2 / (b + 5) + c;
printf("%f \n", result); //10.000000

//C++ functions on PEMDAS or:
//(Parentheses/Brackets, Exponents/Orders, Multiplication/Division, and Addition/Subtraction)
//Mathematical order of operations 
//Modulo is a type of division, so it is performed along with 
//the / and * operators in order from left to right.



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Type Casting (Data type conversion)

int numerator = 40;
int denominator = 25;
int number = 0;
cout << boolalpha << (bool) number << endl; //we changed number data type to boolean, (result = false)
cout << numerator / denominator << endl;//result 1 because int cuts off 0.6 of the result
cout << (double) numerator / denominator << endl; //we changed data type of ints to double and result is 1.6
/*numerator and denominator are integers, but (double) converts numerator into a double. 
You can use (double), (int), and (bool) to cast any double, integer, or boolean between each other. 
Note that casting an integer of 0 or a double of 0.0 to a boolean will result in false. 
Any other integer or double values will result in true. */

//here are other examples 
int numerator = 40;
int denominator = 25;
int number = 5; //we assigned value 5 to number 
cout << boolalpha << (bool) number << endl; //results true, even when number is 5
cout << numerator / denominator << endl;// result = 1 like above
cout << (double) numerator / denominator << endl;// result 1.6 like above

printf("%d \n", numerator / denominator);//specified to print an int, result = 1

printf("%f \n", (double) numerator / denominator);//specified float, 
//changed numerator data type to double
//numerator is changed to double data type before the mathematical operation 

printf("%f \n", (double) (numerator / denominator));//specified float again,
//here division is done using integer arithmetic before the assignment of double data type to the result

//In the first snippet, the casting is done before the division, resulting in a floating-point division. 
//In the second snippet, the casting is done after the division, which performs integer division first 
//and then converts the result to a floating-point value.

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Data type compatibility 
//In C++, is compatibility between int, double and bool, so code like this 
int a = 5;
string b = "3"; //will result in an error, because string has no numerical value
cout << a + b << endl; //and can be added only to the other strings 
//STOI function, stoi();
//stoi() function can be used to convert strings, variables into numbers 
int a = 5;
string b = "3";
string c = "3.14";//we have 2 strings 
bool d = true;
cout << a + stoi(b) << endl; //result = 8, stoi() function converted to int 


int a = 5;
string b = "3";
string c = "3.14";
bool d = true;
cout << a + stoi(c) << endl; //result = 8, stoi(c) converted 3.14 to int = 3

//stod() function = for decimal numbers, exactly to double data type 
int a = 5;
string b = "3";
string c = "3.14";
bool d = true;
cout << a + stod(c) << endl; //result = 8,14, because of data type to double conversion 


int a = 5;
string b = "3";
string c = "3.14";
bool d = true; //to_string is used to convert bool d to string data type 
cout << a + to_string(d) << endl; //error, string and int cannot be added together


int a = 5;
string b = "3";
string c = "3.14";
bool d = true;
cout << b + to_string(d) << endl; //results in "31" in string data type 
//string "3" and bool d converted to string d "1"(because bool = true = 1 converted to string "1")



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Boolean operators

//Equal and not Equal to 
//C++ uses the == operator to determine equality. 
int a = 5;
int b = 5;
cout << boolalpha << (a == b) << endl; //true 

int c = 5;
int d = 1; //d = 1
cout << boolalpha << (a == b) << endl; //false

bool a = false; //0
bool b = true; //1
cout << boolalpha << (b == a) << endl;//false

//Not equal to 
//Checks to see if two values are not equal 

bool a = false; //0
bool b = 1; //1
cout << boolalpha << (b != a) << endl; //true

bool a = true; //true
bool b = 1;
cout << boolalpha << (b != a) << endl; //False

bool a = true;
bool b = false; //false
cout << boolalpha << (b != a) << endl; //true


//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Less than and less than or Equal to 
//The < operator is used to check if one value is less than another value.
int a = 5;
int b = 7;
cout << boolalpha << (a < b) << endl; //true

int a = 5;
  int b = 1; 
  cout << boolalpha << (a < b) << endl; //false

int a = 5;
  int b = 1;
  cout << boolalpha << (a < b) << endl; //false

int a = 5;
  int b = 5;
  cout << boolalpha << (a < b) << endl; //False



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Greater than, Greather than and equal to 
int a = 9;
int b = 17;
cout << boolalpha << (a > b) << endl; //false

int a = 9;
int b = 1; //1
cout << boolalpha << (a > b) << endl; //true

int a = 9;
int b = 9; //9
cout << boolalpha << (a > b) << endl; //False

int a = 9;
int b = false; //False
cout << boolalpha << (a > b) << endl; //true

int a = 9;
int b = true; //true
cout << boolalpha << (a > b) << endl; //true

//Greater than or equal to 
int a = 9;
int b = 17;
cout << boolalpha << (a >= b) << endl; //false


int a = 9;
int b = 9; //9
cout << boolalpha << (a >= b) << endl; //true

int a = true;  //true
int b = false; //false
cout << boolalpha << (a >= b) << endl; //true (1 > than 0)



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//AND, The && Operator
//The && (and) operator allows for compound (more than one) boolean expressions. 
//All boolean expressions must be true in order for the whole thing to be true. 
//If at least one boolean expressions is false, then the whole thing is false.
bool a = true;
bool b = true;
bool c = false;
cout << boolalpha << (a && b) << endl; //true

bool a = true;
bool b = true;
bool c = false;
cout << boolalpha << (a && c) << endl;//False

//Multiple && Statements
//You can chain several && expressions together. 
//They are evaluated in a left-to-right manner.
bool a = true;
bool b = true;
bool c = false;
cout << boolalpha << (a && b && c) << endl; //false
cout << boolalpha << (a && b && a) << endl; //true



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//OR
//The || Operator
