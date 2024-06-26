// What is Polymorphism?
// - polymorphism is concept in object-oriented programming in which single interface takes different forms (polymorphism means “many forms”)
// - often this means similar operations are grouped together with same name
// - these operations with same name will produce different results

  //add code below this line
   
  int a = 5;
  int b = 10;
  cout << (a + b) << endl;
    
  string c = "5";
  string d = "10";
  cout << (c + d) << endl;
  
  bool e = true;
  bool f = false;
  cout << (e + f) << endl;
  
  //add code above this line

// - notice how plus operator (+) can add together two numbers, concatenate two strings, and add two booleans
// - you have single interface ( + ) taking different forms — one that works with integers, another that works with strings, and even one that works with booleans
// - this is example of polymorphism

// - because plus operator can work with different forms, we can say that it is overloaded
// - C++ overloads this operator by default, user cannot manually overload operator

// sub exercise
// - change your code to look like this
  //add code below this line

  int a = 5;
  string b = "true";
  cout << (a + b) << endl;
    
  //add code above this line

// Why is there an error?
// Polymorphism allows C++ to use the plus operator with different data types, but that does not mean that the plus operator can be used with all data types. The example above causes an error message because the plus operator cannot be used with an integer and a string. There are limits to polymorphism.
// Change string b = "true"; in the code above to bool b = true;.
// Why does the code above work?
// Remember that a boolean value of true is equivalent to an integer value of 1. This is why it is possible to add boolean and integer values together.

// Function overriding is another example of polymorphism that you have already seen. 
// Overriding a function means that you have two functions with the same name, but they perform different tasks. 
// Again you see a single interface (the function name) being used with different forms (the base class and the derived class)

//--------------------
// Function Overriding  
// - function overriding is another example of polymorphism that you have already seen
// - overriding function means that you have two functions with same name, but they perform different tasks
// - again you see single interface (function name) being used with different forms (base class and derived class)
//add class definitions below this line

class Alpha {
  public:
    void Show() {
      cout << "I am from class Alpha" << endl;
    }
};

class Bravo: public Alpha {
  public:
    void Show() {
      cout << "I am from class Bravo" << endl;
    }
};

//add class definitions above this line

// Then instantiate Alpha object and call the Show function.

  //add code below this line

  Alpha test_object;
  test_object.Show();
    
  //add code above this line

// - as expected, script prints I am from class Alpha
// - now change line of code in which you instantiate object test_object to Bravo object like below
// - make no other changes and run code again

//   Bravo test_object;

// - now script prints I am from class Bravo
// - function call did not change, but output did
// - single interface (Show function) works with multiple forms (Alpha and Bravo data types)
// - this is why function overriding is example of polymorphism

// Try this variation:
// - create and overload function Hello that prints Hello from Alpha and Hello from Bravo to Alpha and Bravo classes respectively
// - test function on both class types by calling it on their respective objects

//add class definitions below this line

class Alpha {
  public:
    void Show() {
      cout << "I am from class Alpha" << endl;
    }

    void Hello() {
      cout << "Hello from Alpha" << endl;
    }
};

class Bravo: public Alpha {
  public:
    void Show() {
      cout << "I am from class Bravo" << endl;
    }

    void Hello() {
      cout << "Hello from Bravo" << endl;
    }
};

//add class definitions above this line

int main() {

  //add code below this line

  Alpha test_object; //Then test with Bravo test_object
  test_object.Hello();

  //add code above this line

  return 0;

}

//-------------
// sub exercise 
// - function Overriding in Polymorphism
// - why is function overriding example of polymorphism?
// a) Function overriding has single interface (function name) and works with different forms (base and derived classes)

// - polymorphism occurs when there is single interface that works with multiple forms
// - when overriding function, two functions have same name (shared interface) and they work with different forms (base and derived classes)
// - this is why function overriding is example of polymorphism

//---------------------
// Function Overloading
// - function overloading is another example of polymorphism
// - function overloading occurs when you have single function name that can take different sets of parameters
// - imagine you want to write function Sum that can sum up to three numbers
// - math involved with three parameters is slightly different than two parameters, which is different from 1 parameter
// - traditionally, if you declare function that takes three parameters but only pass two, C++ will throw error message
// - instead, let’s create class that has two Sum functions; one with two parameters and another with three parameters

//add class definitions below this line

class TestClass {
  public:
    int Sum(int n1, int n2, int n3) {
      return n1 + n2 + n3;
    }

    int Sum(int n1, int n2) {
      return n1 + n2;
    }
};

//add class definitions above this line

// - create object of type TestClass and call both versions of Sum function
// - be sure you are passing three arguments for one function and two arguments for other

  //add code below this line

  TestClass tc;
  cout << tc.Sum(1, 2, 3) << endl;
  cout << tc.Sum(1, 2) << endl;

  //add code above this line

// - C++ looks at number and types of arguments and, as long there is matching function definition, runs code without error
// - defining same function with different sets of arguments is called overloading
// - it is also example of polymorphism

//-------------
// sub exercise 
// Try this variation:
// - continue to overload Sum function such that it can take up to five numbers as parameters (which means 4 functions total)
// - be sure to test all possible function calls in main
//add class definitions below this line

class TestClass {
  public:
    int Sum(int n1, int n2, int n3, int n4, int n5) {
      return n1 + n2 + n3 + n4 + n5;
    }

    int Sum(int n1, int n2, int n3, int n4) {
      return n1 + n2 + n3 + n4;
    }

    int Sum(int n1, int n2, int n3) {
      return n1 + n2 + n3;
    }

    int Sum(int n1, int n2) {
      return n1 + n2;
    }
};

//add class definitions above this line

int main() {

  //add code below this line

  TestClass tc;
  cout << tc.Sum(1, 2, 3, 4, 5) << endl;
  cout << tc.Sum(1, 2, 3, 4) << endl;
  cout << tc.Sum(1, 2, 3) << endl;
  cout << tc.Sum(1, 2) << endl;

  //add code above this line

  return 0;

}

//------------------------
// Overloading Constructor
// - C++ will also allow you to overload constructor so that objects are instantiated in variety of ways
// - person class has default constructor (no arguments) and constructor with three arguments

//add class definitions below this line

class Person { 
  public: 
    Person() {}

    Person(string na, int nu, string s) {
      name = na;
      number = nu;
      street = s;
    }

    string Info() {
      return (name + " lives at " + to_string(number) + ' ' + street + '.');
    }
  
  private:
    string name;
    int number;
    string street;
};

//add class definitions above this line

// - when you create Person object with no arguments, Info function still works
// - however, information that is printed may look jarring since C++ will use left-over “junk” memory data to fill in for variables that are not initialized
// - you can also instantiate an object with three arguments
// - like function overloading, constructor overloading is form of polymorphism

  //add code below this line
  
  Person p1;
  Person p2("Calvin", 37, "Main Street");
  cout << p1.Info() << endl;
  cout << p2.Info() << endl;
    
  //add code above this line

// Random Values
// - unlike other programming languages, C++ does not automatically initialize variables that are not initialized by the user
// - this is done to preserve memory, thus, you might get "randomly" generated data for certain uninitialized variables

//---------------
// sub exercise 
// Try these variations:

//add class definitions below this line

class Person { 
  public: 
    //Person() {}

    //Person(string na, int nu, string s) {
      //name = na;
      //number = nu;
      //street = s;
    //}

    string Info() {
      return (name + " lives at " + to_string(number) + " " + street + ".");
    }
  
  private:
    string name;
    int number;
    string street;
};

//add class definitions above this line

  //add code below this line
  
  Person p1;
  //Person p2("Calvin", 37, "Main Street");
  cout << p1.Info() << endl;
  //cout << p2.Info() << endl;
    
  //add code above this line

// Why does this work?
// When you do not declare a constructor, C++ will use the default constructor and give each of the attributes their default value.

// Uncomment only the constructor with three arguments.
//add class definitions below this line

class Person { 
  public: 
    //Person() {}

    Person(string na, int nu, string s) {
      name = na;
      number = nu;
      street = s;
    }

    string Info() {
      return (name + " lives at " + to_string(number) + " " + street + ".");
    }
  
  private:
    string name;
    int number;
    string street;
};

//add class definitions above this line

// Why is there an error?
// C++ automatically uses the default constructor when there are no constructors defined. If, however, a constructor exists, the object that gets instantiated must contain the same number of arguments as specified by that constructor's parameters. Otherwise, an error will be produced.

//-----------
// Exercise 1
// Function Overloading in Polymorphism
class ExampleClass {
  public:
    int TotalChars(string s1, string s2, string s3) {
      return s1.length() + s2.length() + s3.length();
    }

    int TotalChars(string s1) {
      return s1.length();
    }
};

int main() {
  
  ExampleClass e ;
  cout << e.TotalChars("hello", "world") << endl;
  
  return 0;

}
// What is the output of the program?
// a) Error message
// - this code would generate error message
// - function TotalChars is overloaded, but it does not have version that takes two string argument
// - function call must match one of overloaded function definition

//-----------------
// Abstract Classes
// - another form of polymorphism in C++ involves abstract functions
// - these functions, however, require knowledge of abstract classes
// - before continuing discussion on polymorphism, talk about abstract classes

// Concrete Classes
// - any class that is not abstract class is considered to be concrete class
// - no need to use keyword to indicate that class is concrete

// - defining characteristic of abstract class is that abstract class has at least one abstract, or pure virtual, function
// - abstract function is function that is defined as being equal to 0 in base class, but is expected to be redefined in derived class

//----------------------------------
// Abstract (Pure Virtual) Functions
// - when will there be need for abstract functions? 
// - abstract functions are used when derived classes are expected to use particular abstract function from base class differently 

//add class definitions below this line

class Shape {
  public:
    virtual double Area() = 0;
};

//add class definitions above this line

// - as seen in above code, virtual function Area is defined as being equal to 0
// - we do this because we expect classes that are derived from Shape to have Area functions that behave differently
// - example, calculating area of Triangle object is different from calculating the area of Rectangle object
// - we define Area as abstract function in base class Shape
// - note that when you redefine abstract functions in derived classes, you do not include virtual keyword nor assign function to 0

//add class definitions below this line

class Shape {
  public:
    virtual double Area() = 0;
  
    double GetBase() {
      return base;
    }
  
    void SetBase(double new_base) {
      base = new_base;
    }
  
    double GetHeight() {
      return height;
    }
  
    void SetHeight(double new_height) {
      height = new_height;
    }
  
  protected:
    double base;
    double height;
};

class Triangle : public Shape {
  public:
    Triangle(double b, double h) {
      base = b;
      height = h;
    }
  
    double Area() {
      return base * height / 2;
    }
};

class Rectangle : public Shape {
  public:
    Rectangle(double b, double h) {
      base = b;
      height = h;
    }
  
    double Area() {
      return base * height;
    }
};

//add class definitions above this line

// - you can see above that two classes are derived from Shape, Triangle class and Rectangle class
// - also notice how Shape contains additional getters and setters as well as protected attributes
// -we encapsulate them as protected in order for our derived classes to access them
// - this way, we don’t have to declare additional attributes in Triangle and Rectangle
// - next, let’s test our code in main

  //add code below this line
  
  Triangle t(4, 4);
  cout << t.Area() << endl;
  Rectangle r(4, 4);
  cout << r.Area() << endl;
  
  //add code above this line

// - as expected, code returns correct calculations for Triangle and Rectangle objects

//-------------
// sub exercise
// Try this variation:
/// Change cout << t.Area() << endl; to cout << t.Shape::Area() << endl;
// Replace entire code in main with
  //add code below this line
  
  Shape s;
  
  //add code above this line

// Why are there errors?
// You cannot create an object of an abstract class nor can you call an abstract function. This is why using encapsulation and inheritance is important in redefining functions so that they can be used in derived classes. Because abstract functions get redefined and used differently, they are considered to be a concept of polymorphism.

//-----------
// Exercise 1
// Formative Assessment 1
// - mark all of ways in which polymorphism can be implemented
// - hint, there is more than one correct answer
// b) Function overriding
// c) Function overloading
// d) Abstract functions

// - inheritance by itself is not form of polymorphism
// - if inheritance uses function overriding, then that would be a form of polymorphism
// - you can have inheritance without function overriding, therefore inheritance is not automatically connected to polymorphism
// - encapsulation is about hiding and sharing information in objects
// - this is not form of polymorphism

//-----------
// Exercise 2 
// Formative Assessment 2
// Assume following code:
class Square {
  public:
    Square(double s) {
      side = s;
    }
    double Area() {
      return side * side;
    }
  private:
    double side;
};

class Rectangle : public Square {
  public:
    Rectangle(double l, double w) : Square(l) {
      length = l;
      width = w;
    }
    double Area() {
      return length * width;
    }
  private:
    double length;
    double width;
};

// Which example of polymorphism is present in the code above?
// a) Function Overloading - There is more than one instance of the function Area that have different definitions (number of parameters).
// b) Abstract Function - Rectangle extends the abstract class Square and must define the abstract function Area.
// c) Function Overriding - The derived class Rectangle creates the function Area that replaces the Area function from the base class Square.

// Correct answer: c) 
// - this is not function overloading because you would need more than one function in same class
// - there are two versions of Area, but one is in base class and other is in derived class
// - in addition, these functions have same definition (neither one takes parameter)
// - there is no abstract function involved since Square is not abstract class, and function Area is not an abstract function

//-----------------
// Coding Exercises

//-----------
// Exercise 1 
// - use VectorAddThree class to left as base class
// - create VectorAddSix class as derived class of VectorAddThree
// - override Add function so that it returns vector of six integers

#include <iostream>
#include <vector>
using namespace std;

//DO NOT EDIT/////////////////
class VectorAddThree {      //
  public:                   //
    vector<int> Add() {     //
      nums.push_back(num1); //
      nums.push_back(num2); //
      nums.push_back(num3); //
      return nums;          //
    }                       //
                            //
  protected:                //
    int num1 = 1;           //
    int num2 = 2;           //
    int num3 = 3;           //
                            //
  private:                  //
    vector<int> nums;       //
};                          //
//////////////////////////////

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line
   
  VectorAddSix v6;
  for (int i : v6.Add()) {
    cout << i << endl;
  }

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Testing Your Code
// - code below instantiates VectorAddSix object
// - then loop is created to iterate through object to add each element into vector elements are printed 
   
  VectorAddSix v6;
  for (int i : v6.Add()) {
    cout << i << endl;
  }

// Expected Output
// 1
// 2
// 3
// 4
// 5
// 6

// Solution:

class VectorAddSix : public VectorAddThree {
  public:
    vector<int> Add() {
      nums.push_back(num1);
      nums.push_back(num2);
      nums.push_back(num3);
      nums.push_back(num4);
      nums.push_back(num5);
      nums.push_back(num6);
      return nums;
    }
  
  protected:
    int num4 = 4;
    int num5 = 5;
    int num6 = 6;
  
  private:
    vector<int> nums;
};

// Key Points:

// VectorAddSix should inherit from VectorAddThree
// Since there is no constructor in VectorAddThree, you do not necessarily need to have one in VectorAddSix
// Override the Add function so that 6 numbers are added instead of 3
// Having protected field enables VectorAddSix to access certain information from VectorAddThree; this is why VectorAddSix is able to access num1, num2, and num3 without needing any getter functions

//-----------
// Exercise 2 

// - vehicle is abstract class
// - create Airplane class as derived class of Vehicle
// - extend and override Airplane so that it has constructor
// - distance function, and one attribute (double speed)
// - distance function should return distance treveled by Airplane object
// - distance is calculated by multiplying speed by time

#include <iostream>
#include <vector>
using namespace std;

//DO NOT EDIT/////////////////////////////////
class Vehicle {                             //
  public:                                   //
    virtual void Distance(double time) = 0; //
};                                          //
//////////////////////////////////////////////

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line
  
  Airplane a(550.0);
  a.Distance(2);
  a.Distance(3.15);
  a.Distance(10.63);
  Airplane a2(228.5);
  a2.Distance(2);
  a2.Distance(3.15);
  a2.Distance(10.63);

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Testing Your Code
// code in main is used to test your class definitions
  
  Airplane a(550.0);
  a.Distance(2);
  a.Distance(3.15);
  a.Distance(10.63);
  Airplane a2(228.5);
  a2.Distance(2);
  a2.Distance(3.15);
  a2.Distance(10.63);

// Expected Output
// 1100
// 1732.5
// 5846.5
// 457
// 719.775
// 2428.96

// Solution: 

class Airplane : public Vehicle {
  public:
    Airplane(double s) {
      speed = s;
    }
  
    void Distance(double time) {
      cout << speed * time << endl;
    }
    
  private:
    double speed;
};

// Airplane should inherit from Vehicle
// Airplane has one attribute speed and constructor should take in parameter that gets assigned to speed
// Distance function should be redefined so that it prints calculated distance (speed * time)

//-----------
// Exercise 3 
// - temperature class is abstract class with two abstract functions
// - create Conversion class which inherits from Temperature
// - use formulas below to help with temperature conversions

// Convert Fahrenheit to Celsius
// °C=°F−321.8
 
// Convert Celsius to Fahrenheit
// °F=°C∗1.8+32

#include <iostream>
#include <vector>
using namespace std;

//DO NOT EDIT/////////////////////////////////////
class Temperature {                             //
  public:                                       //
    virtual double Celsius(double temp) = 0;    //
    virtual double Fahrenheit(double temp) = 0; //
};                                              //
//////////////////////////////////////////////////

int main() {
     
  Conversion c;
  cout << c.ConvertTo('c', 212.0) << endl;
  cout << c.ConvertTo('C', 78.0) << endl;
  cout << c.ConvertTo('h', 23.0) << endl;
  cout << c.ConvertTo('F', 0.0) << endl;
  cout << c.ConvertTo('f', 29.0) <<endl;
  cout << c.ConvertTo('3', 112.0) << endl;
  
  return 0;
  
}

// - code in main is used to test your class definitions
   
  Conversion c;
  cout << c.ConvertTo('c', 212.0) << endl;
  cout << c.ConvertTo('C', 78.0) << endl;
  cout << c.ConvertTo('h', 23.0) << endl;
  cout << c.ConvertTo('F', 0.0) << endl;
  cout << c.ConvertTo('f', 29.0) <<endl;
  cout << c.ConvertTo('3', 112.0) << endl;

// - calling ConvertTo function with specified arguments should produce return values shown below
// - capitalization for char argument should not affect output
// - invalid char argument will result in return value of -0.0001

// Expected Output
// 100
// 25.5556
// -0.0001
// 32
// 84.2
// -0.0001

// Solution:

class Conversion : public Temperature {
  public:
    double ConvertTo(char unit, double temp) {
      if (unit == 'C' || unit == 'c') {
        return Celsius(temp);
      } 
      else if (unit == 'F' || unit == 'f') {
        return Fahrenheit(temp);
      }
      return -0.0001;
    }
  
  private:
    double Celsius(double temp) {
      return (temp - 32) / 1.8;
    }
  
    double Fahrenheit(double temp) {
      return temp * 1.8 + 32;
    }
};

// - conversion should inherit from Temperature
// - set Celsius and Fahrenheit functions so that they return appropriate conversion calculations
// - ConvertTo function is more flexible function that either calls Celsius or Fahrenheit depending on char parameter argument; it should return -0.0001 if char argument is invalid
// - since Celsius and Fahrenheit functions are not explicitly called within main, they act only as helper functions and should therefore be private; however, this is not required to earn full credit


//-----------
// Exercise 4 

// - create Median class that has function CalculateMedian that calculates median of integers passed to function. 
// - use function overloading so that this function can accept anywhere from two to five integer parameters

// How to calculate median
// - median can be thought of as "middle" number in ordered list of numbers
// - if there are two numbers in "middle", median is average of these two numbers (add two numbers and then divide by 2).

// How to sort vector of integers
// - to sort vector of integers, you can use sort(vector_name.begin(), vector_name.end()) where vector_name represents vector object
// include bits/stdc++.h in your program header in order to use sort function

// Given code: 
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//add class definitions below this line



//add class definitions above this line


int main() {
  
  //DO NOT EDIT code below this line
   
  Median m;
  cout << m.CalculateMedian(3, 5, 1, 4, 2) << endl;
  cout << m.CalculateMedian(8, 6, 4, 2) << endl;
  cout << m.CalculateMedian(9, 3, 7) << endl;
  cout << m.CalculateMedian(5, 2) << endl;
  Median m2;
  cout << m2.CalculateMedian(24, 22, 21, 23, 20) << endl;
  cout << m2.CalculateMedian(12, 18, 9, 3) << endl;
  cout << m2.CalculateMedian(0, 1, 0) << endl;
  cout << m2.CalculateMedian(5, 3) << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Expected Output
// IMPORTANT: 
// - you will need to cast return values using (double) in order for certain doubles to print properly
// - otherwise, system will print return values as integers which will eliminate decimal digits
// - for example (5 + 2) / 2 will produce 3 while (double) (5 + 2) / 2 will produce 3.5
// 3
// 5
// 7
// 3.5
// 22
// 10.5
// 0
// 4

// Solution:

class Median {
  public:
    double CalculateMedian(int n1, int n2) {
      return (double) (n1 + n2) / 2;
    }
  
    double CalculateMedian(int n1, int n2, int n3) {
      vector<int> nums = {n1, n2, n3};
      sort(nums.begin(), nums.end());
      return nums.at(1);
    }

    double CalculateMedian(int n1, int n2, int n3, int n4) {
      vector<int> nums = {n1, n2, n3, n4};
      sort(nums.begin(), nums.end());
      return (double) (nums.at(1) + nums.at(2)) / 2;
    }

    double CalculateMedian(int n1, int n2, int n3, int n4, int n5) {
      vector<int> nums = {n1, n2, n3, n4, n5};
      sort(nums.begin(), nums.end());
      return nums.at(2);
    }
};

// - if CalculateMedian function has two parameters, their average should be returned; remember to cast return value as double
// - if CalculateMedian function has between three and five parameter arguments:
// - their arguments should first be stored in structure like vector
// - then arguments should be sorted (i.e. sort(nums.begin(), nums.end());)
// - if there are three or five arguments, “middle” number should be returned
// - if there are four arguments, average of two “middle” numbers should be returned; remember to cast return value as double

//-----------
// Exercise 5 

// - create Substitute class which is derived class of base class Words
// - substitute has just one attribute called input_string and function called SubstituteChar which takes in string and replaces every fifth character with string HELLO

// example:
// - if word is Morning, then function will return MornHELLOng
// - if word is Teddy, then function will return TeddHELLO
// - if word has fewer than 5 characters, then message Not enough characters will be returned

// Given code: 
#include <iostream>
#include <vector>
using namespace std;

//DO NOT EDIT///////////////////////////////////////////
class Words {                                         //
  public:                                             //
    Words(string s1) {                                //
      original = s1;                                  //
    }                                                 //
                                                      //
    string SubstituteChar() {                         //
      string sub;                                     //
      if (original.length() < 3) {                    //
        return "Not enough characters";               //
      }                                               //
      else {                                          //
        for (int i = 0; i < original.length(); i++) { //
          if (i == 2) {                               //
            sub += "HELLO";                           //
          }                                           //
          else {                                      //
            sub += original.at(i);                    //
          }                                           //
        }                                             //
      }                                               //
      return sub;                                     //
    }                                                 //
                                                      //
  private:                                            //
    string original;                                  //
};                                                    //
////////////////////////////////////////////////////////

//add class definitions below this line



//add class definitions above this line


int main() {
  
  //DO NOT EDIT code below this line
  
  Substitute s1("dog");
  cout << s1.SubstituteChar() << endl;
  Substitute s2("string");
  cout << s2.SubstituteChar() << endl;
  Words w("string");
  cout << w.SubstituteChar() << endl;
  
  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Expected Result
// Not enough characters
// striHELLOg
// stHELLOing

// Solution:

class Substitute : public Words {
  public:
    Substitute(string s2) : Words(s2) {
      input_string = s2;
    }
  
    string SubstituteChar() {
      string sub;
      if (input_string.length() < 5) {
        return "Not enough characters";
      }
      else {
        for (int i = 0; i < input_string.length(); i++) {
          if (i == 4) {
            sub += "HELLO";
          }
          else {
            sub += input_string.at(i);
          }
        }
      }
      return sub;
    }
  
  private:
    string input_string;
};

