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


