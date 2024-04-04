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

