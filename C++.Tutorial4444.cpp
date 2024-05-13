//-------------------------------
// Objects Defined in Other Files
// - now that you’re familiar with creating, manipulating, and inheriting objects, we’ll discuss how these concepts all come together when programs are created
// - you may have noticed that lot of classes that you’ve previously worked with is fairly lengthy
// - in fact, it’s not typical to include class definitions within same file as main program
// - usually, classes are defined in other files but they can be accessed by main program if you set up correct encapsulation 

// “#include” in Header
// - ever noticed how #include <iostream> and using namespace std; are usually present in header of file? 
// - #include directs system to look for file or library iostream
// - then using namespace std; enables system to access functions from class std without having to use scope resolution operator ::

#include <iostream>
using namespace std;

int main() {
  
  //add code below this line

cout << "Hello world" << endl;

  //add code above this line
  
  return 0;
  
}
// Hello world 

// comment the header line using namespace std; and run the program again.

#include <iostream>
// using namespace std;

int main() {
  
  //add code below this line

cout << "Hello world" << endl;

  //add code above this line
  
  return 0;
  
}
// ERROR 

// - without using namespace std;, system has no clue which class to look into to use cout
// - revise code in main to look like this:
// std::cout << "Hello world" << std::endl;

#include <iostream>
// using namespace std;

int main() {
  
  //add code below this line

std::cout << "Hello world" << std::endl;

  //add code above this line
  
  return 0;
  
}

// - scope resolution operator :: does same job as using namespace std;
// - note that you will need to use std:: in front of every function you decide to call

//---------------------------------------
// Calling Functions From a Separate File
// - in upper left of text editor window, you will notice tab that says class.h. 

class.h // FILE 1 

#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

//add class definitions below this line

class Greeting {
  public:
    Greeting(string g) {
      greeting = g;
    }
  
    string GetGreeting() {
      return greeting;
    }
  
    void SetGreeting(string new_greeting) {
      greeting = new_greeting;
    }
  
    void PrintGreeting(){
      cout << GetGreeting() << endl;
    }
  
  private:
    string greeting;
};

//add class definitions above this line

#endif

// - this is header file which you can use to store your class definitions
// - there is some syntax (at beginning and end) that you have to include in order to specify that class.h is header file, but ultimately you can reduce number of code in your main program by creating header files
// - all header files should have #ifndef and #define (followed by their file name and then underscore _ and H) in their header and #endif towards end

// - now, go back into include.cpp, copy entire code below and TRY IT

include.cpp // FILE 

//#include <iostream>
//using namespace std;
#include "class.h"

int main() {
  
  //add code below this line

  Greeting g("Hello world");
  cout << g.GetGreeting() << endl;
  g.SetGreeting("Hi world");
  cout << g.GetGreeting() << endl;

  //add code above this line
  
  return 0;
  
}

// - notice how we used #include "class.h" in header of our file
// - this enables connection between main file and header file class.h where class definitions are found
// - also note that because #include <iostream> and using namespace std; are already included in class.h, you can comment out or remove them in main program

//------------------
// sub exercise 
// - #include Header Declaration
// What does having #include in header of your main program do?
// a) helps create link between main file and specified header file
// b) directs system to leave main file for duration of program
// c) disables user from adding class definitions to main file

// correct answer: a) 
// - purpose of including header file’s name in header of main program is to enable system to access content of header file (e.g. to search for class definitions)
// - user can still add class definitions to main program if they wish to
// - system will continue to run main until it terminates

//---------------------------------------------------------------------------------------------------//
// Manipulating Non-Object Variables
// - throughout this course, we’ve been creating class objects through use of constructor, which is required in order for object to access certain class functions
// - if we want to manipulate particular class attribute without having to instantiate that particular 
// object, you can use combination of static keyword plus scope resolution operator :: to manipulate attributes

#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    Player() {
      health = 100;
      score = 0;
    }
    void PrintLevel() {
      cout << level << endl;
    }
    static int ChangeLevel(int change) { //define static function
      level = change;
      return level;
    }
  
  private:
    int health;
    int score;
    static int level; //declare static variable
};

//add class definitions above this line

int Player::level = 0; //initalize static variable globally

int main() {
  
  //add code below this line

  Player mario;
  mario.PrintLevel(); //calling class function, object required
  cout << Player::ChangeLevel(5) << endl; //calling static function, object not needed
  
  //add code above this line
  
  return 0;
  
}
// 0, 5 

// - notice how when calling ChangeLevel function, we needed class name Player followed by scope resolution operator :: followed by function name ChangeLevel and any parameter arguments
// - calling static function enabled us to change attribute level to 5 without calling function on object itself

// When defining and calling static functions, keep following in mind:
// - within class, static functions can only access other static members; for example, if level was not static variable in example above, ChangeLevel would not be able to access it
// - static variable should be defined or initialized globally outside of any class or function, in other words, static variable should not be initialized within class or within main function
// - scope resolution operator :: as defined above to access static functions that modify static variables

//-----------------
// Static Variables
// - it’s important to note that static variables are variables that are created only once
// - they cannot be created again for duration of program

#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    Player() {
      health = 100;
      score = 0;
    }
    void PrintLevel() {
      cout << level << endl;
    }
    static int ChangeLevel(int change) {
      level = change;
      return level;
    }
  
  private:
    int health;
    int score;
    static int level;
};

//add class definitions above this line  

int Player::level = 5; //initialize static variable level to 5

int main() {
  
  //add code below this line

  Player mario;
  mario.PrintLevel();
  cout << Player::ChangeLevel(6) << endl;
  Player luigi;
  luigi.PrintLevel();
  
  //add code above this line
  
  return 0;
  
}
// 5, 6, 6

// - static variables are initialized outside of class globally
// - this is to prevent variable from being duplicated
// - by definition, static variables are only created once
// - this is why when Player object luigi is created, its level attribute is same as mario's even though its level was never changed
// - essentially, both objects share same static variable level
// - changes made to level will be reflected in all objects that have that attribute

//-------------
// sub exercise 
// - which of following is correct command for calling static function ChangeColor to change color attribute to "red" in main?

class Color {
  public:
    static string ChangeColor(string change_color) {
      color = change_color;
      return color;
    }

  private:
    static string color;
};

string Color::color;


// a) Color::ChangeColor("red");
// b) color.ChangeColor("red");
// c) ChangeColor("red");

// correct answer: a) 
// - syntax for accessing static functions using scope resolution operator is to include class name followed by function name and any parameter arguments
// - color.ChangeColor("red"); requires object called color which is not declared and ChangeColor("red"); does not have correct syntax for accessing static function

//------------------
// What are Structs?
// - structs are like classes, except everything inside struct is public
// - therefore, anything external to struct can alter its members
// For example:

#include <iostream>
using namespace std;

//add class definitions below this line

struct Person {
    string name;
    int age;
    double salary;
};

//add class definitions above this line

int main() {
  
  //add code below this line

  Person p;
  p.age = 50;
  cout << p.age << endl;

  //add code above this line
  
  return 0;
  
}
// 50 

// - in example above, after creating struct called Person, we are able to access age attribute by simply using dot notation and specifying attribute. 
// - if security is not issue, structs are useful at putting together collection of attributes that are highly modifiable and accessible

//--------------------------
// Setting Values with Enums
// - enums are similar to switch-case statements where particular values are assigned to particular cases
// See example below:

Grade = 90

// Cases (variables) of alphabet from A through D have been assigned to variable integers from 90 backwards to 60 in increments of 10
// - when you create grades enum, you can assign it to any of cases specified in enum definition
// - this will signal to system to assign grades enum to appropriate integer equivalent

// IMPORTANT: 
// - enum values must be integers 
// - you can’t create enum with string values

//--------------
// semi exercise
// Try this variation:

// Change enum grades {A = 90, B = 80, C = 70, D = 60}; in code above to enum grades {A, B, C, D};
// Grade = 0 
// Change grade = A; to grade = B;
// Grade = 1
// Change enum grades {A, B, C, D}; to enum grades {A = 90, B, C, D};
// Grade = 91
// Change enum grades {A = 90, B, C, D}; to enum grades {A, B, C = 5, D};
// Grade = 1 
// Change grade = B; to grade = D;.
// Grade = 6 

// NOTE: 
// - if enum variables are not assigned values, first variable will be 0 by default
// - second variable will be 1 and so on
// - additionally, incrementation of 1 happens following first value of initialized enum variable
// - enum fruit {apple = 5, banana, orange}; causes apple to have value of 5 and each variable after will have value incremented by 1
// - this means banana will have value of 6 and orange will have value of 7
// - other hand, enum fruit {apple, banana = 5, orange}; causes apple to be 0, banana to be 5, and orange to be 6

//---------
// Exercise 
// - fill in blanks below with correct enum syntax so that Color = 2 gets printed as result
enum colors {red = 1, blue, yellow};

int main() {

  colors color;

  color = blue;
  cout << "Color = " << color << endl;
  
  return 0;
  
}
// - in order to create enum variables, keyword enum must be declared
// - then within curly braces {}, user can declare as many enum variables as needed
// - in problem, variable red is initialized to 1 which means variables that follow will each be incremented by 1 automatically (blue will be 2 and yellow will be 3)
// - to create enum object, declare it with variable name (i.e. colors color;
// - then user can assign any enum variable to enum object
// - blue should be assigned to color because its value is equal to 2, which is what we want
// - finally, result is printed which will produce the output of Color = 2

//-----------------------
// Comparing Object Types
// - you can compare object types by implementing typeid function
// - code below showcases comparison between two Player objects called mario and luigi using typeid

#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    Player() {
      health = 100;
      score = 0;
      level = 1;
    }
  
  private:
    int health;
    int score;
    int level;
};

//add class definitions above this line 

int main() {
  
  //add code below this line

  Player mario;
  Player luigi;
  cout << boolalpha;
  cout << (typeid(mario) == typeid(luigi)) << endl;
  
  //add code above this line
  
  return 0;
  
}

// true 

// - since both mario and luigi are of class Player, their typeid will be same
// - this is why cout << (typeid(mario) == typeid(luigi)) << endl; returns true
// - unfortunately, typeid does not check to ensure that both objects contain same exact attribute values
// - however, you can create user-defined class to check for that

//-----------------------------
// Comparing Same-Class Objects
// - let’s create static member function called ComparePlayers
// - this function takes in two Player objects as parameters, then checks to see if each of their attributes is equal to other
// - if their attributes are equal, true is returned
// - else, false is returned
// - another member function called NextLevel is also created

//add class definitions below this line

class Player {
  public:
    Player() {
      health = 100;
      score = 0;
      level = 1;
    }
  
    static bool ComparePlayers(Player p1, Player p2) {
      if ((p1.health == p2.health) &&
          (p1.score == p2.score) &&
          (p1.level == p2.level)) {
        return true;
      }
      else {
        return false;
      }
    }
  
    void NextLevel() {
      level++;
    }
  
  private:
    int health;
    int score;
    int level;
};

//add class definitions above this line 

int main() {
  
  //add code below this line

  Player mario;
  Player luigi;
  cout << boolalpha;
  cout << Player::ComparePlayers(mario, luigi) << endl;
  
  //add code above this line
  
  return 0;
  
}

// true 

//--------------
// semi exercise 
// Try this variation:
// Replace code in main with:
  //add code below this line

  Player mario;
  Player luigi;
  cout << boolalpha;
  mario.NextLevel();
  cout << Player::ComparePlayers(mario, luigi) << endl;
  
  //add code above this line

// false 

// - notice how when mario's level changed, ComparePlayers function returns false when mario and luigi are compared

//---------
// Exercise 
// Object Equality
// - Which of following is true regarding typeid?
// a) typeid can determine if attributes of two objects are same values
// b) typeid is used to assign values of one object to another
// c) typeid can determine if two objects are from same class

// correct answer: c) 
// - typeid can determine if two objects are from same class
// - typeid by default can only check to see if two objects are from same class
// - it does not check to see if two objects have same attribute values

//----------- 
// Exercise 1 

// Fill in blanks below with correct syntax for both main and class/header files

// Key Points:

// main
// - main file should always contain int main()
// - for main file to access Greeting class, #include "class.h" is needed in header
// class
// - class or header file should include following syntax:
// #ifndef - followed by file name in all caps, underscore, and then finally H
// #define - has same syntax as #ifndef
// using namespace std; is needed to access cout commands without using scope resolution operator
// #endif - goes towards end of file

// solution: 

#include "class.h"

int main() {

  Greeting g("Hello world");
  cout << g.GetGreeting() << endl;
  g.SetGreeting("Hi world");
  cout << g.GetGreeting() << endl;
  
  return 0;
}

#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

class Greeting {
  public:
    Greeting(string g) {
      greeting = g;
    }
  
    string GetGreeting() {
      return greeting;
    }
  
    void SetGreeting(string new_greeting) {
      greeting = new_greeting;
    }
  
    void PrintGreeting(){
      cout << GetGreeting() << endl;
    }
  
  private:
    string greeting;
};

#endif

//-----------
// Exercise 2 
// - given following enum:
enum rating {everyone = 1, teens, mature};
// - drag and arrange code blocks below so that result prints:
Game category = 3

// solution: 
rating game;
game = mature;
cout << "Game category = " << game << endl;

// - enum is called rating with 3 variables (everyone, teens, and mature)
// - since variable everyone is initialized to 1, teens will automatically be assigned to 2 and mature will be 3
// - 3 is associated with mature which is what you want to print
// - create rating called game and set it to mature which is equal to 3
// - use cout to print desired result

//---------------------------------------------------------------------------------------------------//
// Labs advanced topics 

//------
// Lab 1 
// - Lab 1
// - in this module, we’ve learned how to create separate header files so that we can call them without having to place them into main file T
// - this will dramatically reduce length of code needed in main file
// - make sure your main file (lab1.cpp) and your header file (class.h) contain code below

lab1.cpp // FILE 

#include "class.h"

int main() {
  
  //add code below this line

  Greeting g("Hello world");
  cout << g.GetGreeting() << endl;
  g.SetGreeting("Hi world");
  cout << g.GetGreeting() << endl;

  //add code above this line
  
  return 0;
  
}

class.h // FILE 

#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

//add class definitions below this line

class Greeting {
  public:
    Greeting(string g) {
      greeting = g;
    }
  
    string GetGreeting() {
      return greeting;
    }
  
    void SetGreeting(string new_greeting) {
      greeting = new_greeting;
    }
  
    void PrintGreeting(){
      cout << GetGreeting() << endl;
    }
  
  private:
    string greeting;
};

//add class definitions above this line

#endif

// program output: 
// Hello world
// Hi world

//--------------
// Semi exercise
// - select all of following terms that are needed in header file (ends in .h) in order to make itcompatible with other program files
// a) #endif
// b) int main()
// c) #define
// d) return 0
// e) #ifndef

// correct answer: 
// a), c), e) 


//-------------
// Lab 2 
// - you are provided following header and main files:
// point.h, slope.h, lab2.cpp
// - in this lab, you’ll be working with these three files
// - idea is to create struct called point within point.h, then create static function called 
// - calculateSlope within slope.h, and finally run few commands within lab2.cpp to print some results

point.h // FILE 
#ifndef SLOPE_H
#define SLOPE_H

//add definitions below this line



//add definitions above this line

#endif

slope.h // FILE 
#ifndef SLOPE_H
#define SLOPE_H

//add definitions below this line



//add definitions above this line

#endif

lab2.cpp
#include <iostream>
using namespace std;
#include "point.h"
#include "slope.h"

int main() { // FILE 
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

//--------
// point.h
// - in this header file, we will create struct called point which contains just two attributes, int x and int y
// - remember, structs are public by default which means they are easily accessible

//add definitions below this line

struct point {
  int x;
  int y;
};

//add definitions above this line

//--------
// slope.p
// - in this header file, we will create class called Slope
// - this class only has one static member function called CalculateSlope
// - calculateSlope takes in two point structures and returns calculated slope between them

//add definitions below this line

class Slope {
  public:
    static double CalculateSlope(point a, point b) {
      return ( (double) (b.y - a.y) / (double) (b.x - a.x) );
    }
};

//add definitions above this line

//---------
// lab2.cpp
// - now it’s time to test our header files within main
// - we are going to create two point structures, assign values to their attributes, then call CalculateSlope on two points
// - note that we do not need to create Slope object before calling CalculateSlope since it is static function 
// - simply use scope resolution operator :: to access function as shown in code below

  //add code below this line

  point a;
  point b;
  a.x = 0;
  a.y = 0;
  b.x = 2;
  b.y = 2;
  cout << Slope::CalculateSlope(a, b) << endl;

  //add code above this line

// program output: 
// 1 

//--------------
// semi exercise
// Try these variations:
// Replace code in main with:
  //add code below this line

  point a;
  point b;
  a.x = 1;
  a.y = 2;
  b.x = 10;
  b.y = 20;
  cout << Slope::CalculateSlope(a, b) << endl;

  //add code above this line
Change the entire lab2.cpp to look like this:
#include <iostream>
using namespace std;

struct point {
  int x;
  int y;
};

class Slope {
  public:
    static double CalculateSlope(point a, point b) {
      return ( (double) (b.y - a.y) / (double) (b.x - a.x) );
    }
};

int main() {
  
  //add code below this line

  point a;
  point b;
  a.x = 1;
  a.y = 2;
  b.x = 10;
  b.y = 20;
  cout << Slope::CalculateSlope(a, b) << endl;

  //add code above this line
  
  return 0;
  
}  

// program output: 
// 2 

// - note that including header files produces same result as including struct point and class slope within main
// - header files enable main program to be less cluttered with definitions

//--------------
// semi exercise 
// Which of following items can be static in either class file or main file?
// a) Enums
// b) Functions
// c) Variables
// d) Structs

// answer: 
// c), b) 


//--------------
// Lab Chellenge
// Problem
// - create BankAccount struct in IDE to left which has two double attributes checking and savings
// - create function called ToString within struct that prints representation of BankAccount struct which includes these attributes
// - you MUST use struct within your code in order to receive credit for this challenge

Given Code
#include <iostream>
#include <iomanip>
using namespace std;

//add definitions below this line



//add definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  BankAccount account1;
  account1.checking = 2432;
  account1.savings = 89.52;
  BankAccount account2;
  account2.checking = 1998;
  account2.savings = 239.43;
  account1.ToString();
  account2.ToString();

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Setting decimal places
// You can use code cout << setprecision(2) << fixed followed by specified value to set that value to two decimal places

//-------------------
// Testing Your Code
// - code in main is used to test your definitions, DO NOT EDIT this code!

  BankAccount account1;
  account1.checking = 2432;
  account1.savings = 89.52;
  BankAccount account2;
  account2.checking = 1998;
  account2.savings = 239.43;
  account1.ToString();
  account2.ToString();

// Expected Result
// BankAccount[checking=2432.00, savings=89.52]
// BankAccount[checking=1998.00, savings=239.43]

//------------
// Solution: 
// - set up BankAccount struct with two attributes, double checking and double savings
// - ToString function should print results in format specified; use setprecision(2) and fixed to set up correct decimal places

struct BankAccount {
  double checking;
  double savings;
  
  void ToString() {
    cout << "BankAccount[checking=";
    cout << setprecision(2) << fixed << checking;
    cout << ", savings="; 
    cout << setprecision(2) << fixed << savings;
    cout << ']' << endl;
  }
};

//---------------------------------------------------------------------------------------------------//

//------
// Lab 1
// - create Student class that has following private class attributes:
// string name - name of the student
// - int grade - student’s grade level
// - int score - test score of student
// - put together all of class attributes

class Student {
  private:
    string name;
    int grade;
    int score;
};

// - define constructor Student with two parameters string n for student’s name and int g for student’s grade

class Student {
  public:
    Student(string n, int g) {
      name = n;
      grade = g;
    }

  private:
    string name;
    int grade;
    int score;
};

// - define class function called StudentStatus that takes student’s int score as parameter and checks whether score is passing score or notpassing score is 65 or higher 
// - if score is less than 65, then student did not pass their grade and will remain in same grade they are now
// - otherwise, if student has score of 65 or higher, then they have passed and will move on to next grade and their grade attribute will increase by 1
// - function should also output message providing some context regarding whether student has been promoted to next grade or not

//add class definitions below this line

class Student {
  public:
    Student(string n, int g) {
      name = n;
      grade = g;
    }
    void StudentStatus(int s) {
      if (s < 65) {
        score = s;
        cout << name << " has not graduated and will remain in grade ";
        cout << grade << "." << endl;
      }
      else {
        score = s;
        cout << name << " has graduated and will be promoted to grade ";
        cout << grade + 1 << "." << endl;
      }
    }

  private:
    string name;
    int grade;
    int score;
};

//add class definitions above this line

// - in main, try few test cases to see if StudentStatus updates alice's grade level correctly

  //add code below this line

  Student alice("Alice", 4);
  alice.StudentStatus(60);
  alice.StudentStatus(90);

  //add code above this line

// - since Alice received score of 65 first time, they were not promoted to next grade
// - once they got score of 90 second time around, they were promoted to next grade


// Whole code: 
#include <iostream>
using namespace std;

//add class definitions below this line

class Student {
  private:
    string name;
    int grade;
    int score;
};

//add class definitions above this line

int main() {
  
//add class definitions below this line

class Student {
  public:
    Student(string n, int g) {
      name = n;
      grade = g;
    }
    void StudentStatus(int s) {
      if (s < 65) {
        score = s;
        cout << name << " has not graduated and will remain in grade ";
        cout << grade << "." << endl;
      }
      else {
        score = s;
        cout << name << " has graduated and will be promoted to grade ";
        cout << grade + 1 << "." << endl;
      }
    }

  private:
    string name;
    int grade;
    int score;
};

  //add code below this line

  Student alice("Alice", 4);
  alice.StudentStatus(60);
  alice.StudentStatus(90);

  //add code above this line

//add class definitions above this line
  
  return 0;
  
}
// Alice has not graduated and will remain in grade 4.
// Alice has graduated and will be promoted to grade 5.

// sub exercise
// Mutability Vocabulary
// Match each mutability vocabulary to its correct definition

// Class
// - Typically contains class attributes, class functions, and constructor
// Privat
// - Access modifier type for class attributes.
// Public
// - Access modifier type for class functions and constructor
// Class function
// - Can be used to modify class attributes or to print related output

//------
// lab 2 
// - it is important to understand why class attributes are labeled as private
// - this provides level of protection for your code since it does not allow the user to interact with class attributes directly

//add class definitions below this line

class Student {
  public: 
    Student() {
      name;
      grade;
    }
  
  public:
    string name = "Alice";
    int grade = 4;
    int score = 65;
};

//add class definitions above this line

// - because code above has public class attributes, following code in main can change those attributes’ values directly

  //add code below this line

  Student steve;
  steve.name = "Steve";
  cout << steve.name << endl;

  //add code above this line

// - change class attributes from public to private, code in main will no longer work

//add class definitions below this line

class Student {
  public:
    Student() {
      name;
      grade;
    }
  
  private:
    string name = "Alice";
    int grade = 4;
    int score = 65;
};

//add class definitions above this line

// - this is why understanding how class functions work is important
// - class functions serve as intermediate step between objects and class attributes
// - they are ones interacting with class attributes instead of user

//add class definitions below this line

class Student {
  public:
    Student() {
      name;
      grade;
    }
    void ChangeName(string n) {
      name = n;
    }
    string ReturnName() {
      return name;
    }
  
  
  private:
    string name = "Alice";
    int grade = 4;
    int score = 65;
};

//add class definitions above this line

  //add code below this line

  Student steve;
  steve.ChangeName("Steve");
  cout << steve.ReturnName() << endl;

  //add code above this line

// - although using class functions may result in longer code, it prevents user from seeing and interacting with class attributes directly
// - this is why using class attributes is best practice

// sub exercise 
// - class Function Purpose
// - what is purpose of making class attributes private?

// a) There are no differences in how private class attributes and public class attributes are used
// b) private class attributes cannot be accessed by user directly, thus providing code with level of protection
// c) private class attributes are considered constant and cannot be changed for duration of program
// d) private class attributes generally require less code to accomplish same tasks as public ones

// Correct answer: b) 
// - correct answer is that private class attributes cannot be accessed by user directly, thus providing code with level of protection
// - when attributes are private, user cannot use dot notation to access attribute directly
// - class functions are then used instead to make any changes needed
// - this offers the code level of protection

//--------------
// Lab challenge 

//add class definitions below this line

class Zoo {
  public:
    Zoo(int bc, int p, int r, int b) {
      big_cats = bc;
      primates = p;
      reptiles = r;
      birds = b;
    }
  
  private:
    int big_cats; //for "big cats"
    int primates; //for "primates"
    int reptiles; //for "reptiles"
    int birds; //for "birds"
};

//add class definitions above this line

// Your task is to add following class functions to class:
// TotalAnimals - returns total number of animals
// TotalMammals - returns number of mammals (which includes big_cats and primates)
// MostAnimals - returns name of animal with most count assuming no two animals have same count

// Expected Result:
// 250
// 40
// birds
// 324
// 168
// big cats

// Whole code: 
#include <iostream>
using namespace std;

//add class definitions below this line

class Zoo {
  public:
    Zoo(int bc, int p, int r, int b) {
      big_cats = bc;
      primates = p;
      reptiles = r;
      birds = b;
    }
    int TotalAnimals() {
      return big_cats + primates + reptiles + birds;
    }

    int TotalMammals() {
      return big_cats + primates;
    }

    string MostAnimals() {
      int max = big_cats;
      string most_animal = "big cats";
      if (primates > max) {
        max = primates;
        most_animal = "primates";
      }
      if (reptiles > max) {
        max = reptiles;
        most_animal = "reptiles";
      }
      if (birds > max) {
        max = birds;
        most_animal = "birds";
      }
      return most_animal;
    }    
  
  private:
    int big_cats; //for "big cats"
    int primates; //for "primates"
    int reptiles; //for "reptiles"
    int birds; //for "birds"
};

//add class definitions above this line  

int main() {
  
  //DO NOT EDIT code below this line

  Zoo my_zoo(10, 30, 90, 120);
  cout << my_zoo.TotalAnimals() << endl;
  cout << my_zoo.TotalMammals() << endl;
  cout << my_zoo.MostAnimals() << endl;
  Zoo my_zoo2(123, 45, 67, 89);
  cout << my_zoo2.TotalAnimals() << endl;
  cout << my_zoo2.TotalMammals() << endl;
  cout << my_zoo2.MostAnimals() << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// int TotalAnimals() should return total number of animals at Zoo, thus return all of class attributes added together, return big_cats + primates + reptiles + birds;
// int TotalMammals() should return only number of big_cats + primates
// string MostAnimals() should return string as specified by prompt
// Set up two variables int max and string most_animal and set big_cats to be max and "big cats" to be most_animal 
// It doesn’t really matter what you initialize these variables to at first
// Next, create conditionals to compare big_cats with all of other class attributes in order to update max and most_animal appropriately
// Then return most_animal which should provide you with name of most number of animals at Zoo


//-----------------
// Coding Exercises

//-----------
// Exercise 1

// - you are given two files, one called exercise1.cpp, which is main file, and one called header.h, which is a header (or class) file
// - fill out header.h file to get expected output

//DO NOT EDIT///////////
                      //
#include "header.h"   //
                      //
int main() {          //
                      //
  Hello hello;        //
  hello.PrintHello(); //
                      //
  return 0;           //
                      //
}                     //
////////////////////////

// - one possible solution is to create class called Hello
// - since main contains function called PrintHello that is called on object hello, you can simply define that function within Hello by setting it up so that it will print Hello when it is used on object
// Solution:

class Hello {
  public:
    void PrintHello() {
      cout << "Hello" << endl;
    }
};

