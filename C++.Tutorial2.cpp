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
