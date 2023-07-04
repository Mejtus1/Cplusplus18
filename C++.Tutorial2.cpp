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
