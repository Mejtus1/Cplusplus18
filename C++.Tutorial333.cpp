//-----------------
// BUILD IN OBJECTS 

// String Object and Others
// - you have already been using built-in C++ objects
// - strings are example of C++ object
string s = "I am a string";
cout << "s is a: " << typeid(s).name() << endl;
// s is a: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE

// Try these variations:
// - explore some of functions associated with string class
// Add line of code cout << boolalpha << s.empty() << endl;
// s is a: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
// false
// Add line of code cout << s.length() << endl;
// 13
// Add line of code s.push_back('s'); and then cout << s << endl;

  string s = "I am a string";
  cout << "s is a: " << typeid(s).name() << endl;
  cout << boolalpha << s.empty() << endl;
  cout << s.length() << endl;

  s.push_back('s');
  cout << s << endl;

// s is a: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
// false
// 13
// I am a strings

// - C++ says that class or type of s is NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE (which is string)
// - replace exiting code with one below and run program again
int arr[1];
cout << "arr is a: " << typeid(arr).name() << endl;
// arr is a: A1_i

// - resulting output says arr is a: A1_i
// - A1 stands for one dimensional array and i stands for integer

//-----------
// Vocabulary
// - in text above, words “class” and “object” are used in almost interchangeable manner
// - there are many similarities between classes and objects, but there is also important difference
// - working with objects has a lot of specialized vocabulary:

// Classes 
// - classes are collection of data and actions that can modify data
// - programming is very abstract task 
// - classes were created to give users mental model of how to think about data in more concrete way
// - classes act as blueprint
// - they tell C++ what data is collected and how it can be modified

// Objects 
// - objects are constructed according to blueprint that is class
// - in code above, variable "s" is string object
// - it is not class
// - string class tells C++ that "s" has functions like length, append, and replace
// - when programmer wants to use class, they create object

// Instance 
// - another way that programmers talk about objects is to say that object is instance of particular class
// - "s" is instance of string class

// Instantiation 
// - instantiation is process where object is created according to blueprint of class
// - phrase “define variable” means to create variable
// - variable is given name and value
// - once it has been defined, you can use variable
// - with objects, you use phrase "instantiate an object" 
// - that means to create object, give it name, store any data, and define actions object can perform


//---------------------
// USER DEFINED OBJECTS 

//-------------------
// Defining an Object
// - assume you want to collect information about actors
// - creating class is good way to keep this data organized
// - class keyword is used to define class

//add class definitions below this line
    
class Actor {
  
};
  
//add class definitions above this line

// - convention for naming classes in C++ is to use capital letter
// - lowercase letter will not cause error message, but it is not considered to be "correct" 
// - if class has name with multiple words, all of words are pushed together, and capital letter is used for first letter of each word
// - this is called camel case

// - classes are just blueprint 
// - to you use class, you need to instantiate object
// - here is object to represent Helen Mirren
// - be sure to put this code in main function

//add code below this line
  
Actor helen;
 
//add code above this line

// - you now have helen, which is now instance of Actor class

//------------------
// Adding Attributes
// - point of having class is to collect information and define actions that can modify data
// - actor class should contain things like name of actor, notable films, awards they have won, etc
// - these pieces of information related to class are called attributes
// - attributes are declared in class itself 
// - example below adds first_name and last_name attributes which are both strings
// - notice that keyword is also required public
// - public is considered to be access specifier which determines how accessible attributes are from outside class
// - adding this keyword just means that attributes first_name and last_name are readily accessible
// - for now, we will be using public as access specifier for our classes

//add class definitions below this line

class Actor {
  public:
    string first_name;
    string last_name;
};

//add class definitions above this line

// - you can change value of attribute with assignment operator, object_name.attribute = attribute_value
// - notice that you always use object_name.attribute to reference attribute
// - this is called dot notation
// - once attribute has value, you can treat it like any other variable
// - add following code to main function
// - you are assigning values to attributes fist_name and last_name, and then printing these values

//add code below this line
  
Actor helen;
helen.first_name = "Helen";
helen.last_name = "Mirren";
cout << helen.first_name +  ' ' + helen.last_name << endl;
 
//add code above this line

// Note 
// - many objects in C++ cannot be printed directly, thus cout << helen << endl; resulted in error
// - when printing objects, be sure to reference their attributes


//----------------
// CONSTRUCTOR  

//--------------
// Too Much Code
// - imagine that Actor class has more attributes than on previous page

//add class definitions below this line
    
class Actor {
  public:
    string first_name;
    string last_name;
    string birthday;
    int total_films;
    int oscar_nominations;
    int oscar_wins;
};
  
//add class definitions above this line

// - now create object for Helen Mirren with values for each attribute
// - adding each attribute individually requires several lines of code
// - this is especially true if you have more than one instance of Actor class

//add code below this line

Actor helen;
helen.first_name = "Helen";
helen.last_name = "Mirren";
helen.birthday = "July 26";
helen.total_films = 80;
helen.oscar_nominations = 4;
helen.oscar_wins = 1;
cout << helen.first_name + ' ' + helen.last_name << endl;

//add code above this line

// - class Actor creates class and its attributes 
// - it does not assign value to any attributes; user has to do this 
// - class is supposed to be blueprint
// - it should lay out all of attributes and their values for user
// - classes can do this when you use constructor

//------------
// Constructor 
// - constructor is special function for class 
// - its job is to assign value for attributes associated with object
// - these attributes can also be called instance variables
// - in C++, constructor is class name, parentheses, and curly brackets 
// - inside of constructor, give attributes their values

//add class definitions below this line
    
class Actor {
  public:
    string first_name;
    string last_name;
    string birthday;
    int total_films;
    int oscar_nominations;
    int oscar_wins;
  
  Actor() {
    first_name = "Helen";
    last_name = "Mirren";
    birthday = "July 26";
    total_films = 80;
    oscar_nominations = 4;
    oscar_wins = 1;
  }
};
  
//add class definitions above this line   

// - instantiating helen as instance of Actor class automatically calls constructor
// - since instance variables (attributes) have values, you can remove those lines of code from main function

//add code below this line

Actor helen;
cout << helen.first_name + ' ' + helen.last_name << endl;

//add code above this line

// - when you attempted to print cout << helen.first_name + ' ' + helen.last_name + " won " + helen.oscar_wins + " Oscar out of " + helen.oscar_nominations + " nominations" << endl;, 
// - you likely received very long error message
// - this happened because operator + only works with same-type objects or data
// - in print statement above, you tried to combine strings with integers which C++ did not like and therefore complained 
// - to solve this, simply change + to <<

//---------------------------
// CONSTRUCTOR AND PARAMETERS 

//---------------------------
// Constructor and Parameters
// - imagine that you want to use Actor class to instantiate object for Helen Mirren and Tom Hanks

//add class definitions below this line
    
class Actor {
  public:
    string first_name;
    string last_name;
    string birthday;
    int total_films;
    int oscar_nominations;
    int oscar_wins;
  
  Actor() {
    first_name = "Helen";
    last_name = "Mirren";
    birthday = "July 26";
    total_films = 80;
    oscar_nominations = 4;
    oscar_wins = 1;
  }
};
  
//add class definitions above this line

// - instantiate two Actor objects, one for Helen Mirren and other for Tom Hanks
// - print fist_name and last_name attributes for each object

//add code below this line

Actor helen;
Actor tom;
cout << helen.first_name << ' ' << helen.last_name << endl;
cout << tom.first_name << ' ' << tom.last_name << endl;

//add code above this line

// - constructor Actor class only creates object with information about Helen Mirren
// - you can make Actor class more flexible by passing it argument for each of attributes in constructor 
// - parameters for constructor function work just as they do for user-defined functions, be sure to indicate data type for each parameter

//add class definitions below this line
    
class Actor {
  public:
    string first_name;
    string last_name;
    string birthday;
    int total_films;
    int oscar_nominations;
    int oscar_wins;
  
  Actor(string fn, string ln, string bd, int tf, int on, int ow) {
    first_name = fn;
    last_name = ln;
    birthday = bd;
    total_films = tf;
    oscar_nominations = on;
    oscar_wins = ow;
  }
};
  
//add class definitions above this line

// - when you instantiate two Actor objects, you can pass constructor relevant information for both Helen Mirren and Tom Hanks 
// - code should now print correct first and last names

//add code below this line

Actor helen("Helen", "Mirren", "July 26", 80, 4, 1);
Actor tom("Tom", "Hanks", "July 9", 76, 5, 2);
cout << helen.first_name << ' ' << helen.last_name << endl;
cout << tom.first_name << ' ' << tom.last_name << endl;

//add code above this line

//---------------
// Default Values
// - we can assume that average actor probably has not been nominated or won Oscar 
// - instead of making these attributes parameters for constructor, we can give them default value of 0
// - these attributes can always be updated later on

//add class definitions below this line
    
class Actor {
  public:
    string first_name;
    string last_name;
    string birthday;
    int total_films;
    int oscar_nominations;
    int oscar_wins;
  
  Actor(string fn, string ln, string bd, int tf) {
    first_name = fn;
    last_name = ln;
    birthday = bd;
    total_films = tf;
    oscar_nominations = 0;
    oscar_wins = 0;
  }
};
  
//add class definitions above this line

// - you can update attributes once object has been instantiated if need be

//add code below this line

Actor helen("Helen", "Mirren", "July 26", 80);
cout << helen.oscar_nominations << endl;
cout << helen.oscar_wins << endl;

helen.oscar_nominations = 4;
helen.oscar_wins = 1;

cout << helen.oscar_nominations << endl;
cout << helen.oscar_wins << endl;

//add code above this line

//----------------
// COPYING OBJECTS 

//---------------
// Copying Object
// - in C++, you can initialize new object to existing one to create clone

//add class definitions below this line
    
class ComicBookCharacter {
  public:
    string name;
    int age;
    string type;
};
  
//add class definitions above this line

int main() {
  
  //add code below this line

  ComicBookCharacter a;
  a.name = "Calvin";
  a.age = 6;
  a.type = "human";
    
  ComicBookCharacter b = a;
  a.name = "Hobbes";
    
  cout << "Object a name: " << a.name << endl;
  cout << "Object a age: " << a.age << endl;
  cout << "Object a type: " << a.type << endl;
  cout << "Object b name: " << b.name << endl;
  cout << "Object b age: " << b.age << endl;
  cout << "Object b type: " << b.type << endl;
  
  //add code above this line

// - you’ll notice that initializing one object to another created exact copy of original object
// - each object is still treated as separate objects though so you can still freely change attribute of one object without affecting another

//-----------
// Exercise 1 
// - assume following code:
Dog fido;
fido.breed = "poodle";
// - rearrange code blocks below to declare Dog class that corresponds to code above

// answer: 
class Dog {
public:
string breed;
}
// - in given code, Dog class uses capital D, so should class definition
// - in given code, no arguments were passed to Dog when fido was instantiated
// - thus, there should be no constructor
// public: is needed to allow access to attribute
// - given code set value for breed, so breed should not be given default value when initialized

//-----------
// Exercise 2 
// - given constructor Car(string make, string model, int year), which of following Car objects are correctly constructed?
// a) Car t(Camry, 2012, Toyota);
// b) Car t(Toyota, Camry, 2012);
// c) Car t(Toyota, Camry, 2012, LE);
// d) Car t(2012, Toyota, Camry);

// correct answer: b) 
// - given that constructor is Car(string make, string model, int year), constructor needs to have same typed parameters
// - only choice with parameter types string, string, and int respectively is Car t(Toyota, Camry, 2012);
// - note that number of parameters should also match which is why Car t(Toyota, Camry, 2012, LE); is incorrect since it has 4 parameters

//---------------------------------------------------------------------------------------------------//
// Lab: Objects

//----------------------------------
// Lab 1: DEFINING YOUR FIRST OBJECT
// - when defining object, there are few criteria that must be met in order for object to be successfully created
// - 
class ClassName {
  public:
    type attribute1;
    type attribute2;
};

// 1. all objects are created inside classes, first step is use keyword class
// 2. give class name which is used to construct object
// 3. keyword public: is needed in order to provide access to object attributes that you define later on
// 4. give your object as many attributes as needed in order to make full use of your object
// 5. all attributes go within curly braces {} after class name declaration, make sure to end closing curly brace with semi-colon ;

//---------------
// Student Object
// - let’s define object called Student 
// - when we think of student, some information or attributes that we might associate with students are:
// Name
// Student ID number
// Major
// GPA
// Age
// Year of graduation

// - once we’ve narrowed down what attributes we want associated with our object, we can start defining them

class Student {
  public:
    string name;
    int ID;
    string major;
    double GPA;
    int age;
    int YOG;
};

//----------------
// Creating Object
// - once class has been established, we can create object by calling on object’s class and giving object name in main function

Student andy;
andy.name = "Andy";
andy.ID = 123456;
andy.major = "Computer Science";
andy.GPA = 3.45;
andy.age = 22;
andy.YOG = 2021;

//-----------------------------
// Printing Object’s Attributes
// - it is not sufficient to simply say cout << andy; in order to print attributes associated with andy
// - instead, we must use dot notation to specify what attribute of andy we want to output
// - to print andy's ID for example, use cout << andy.ID; 
// - or to print andy's major, use cout << andy.major; 
// - add following to existing code and click TRY IT button to see what is printed about andy

cout << andy.name << " is " << andy.age;
cout << " years old and is graduating with a degree in ";
cout << andy.major << " in " << andy.YOG << ".";


//---------------------------
// lab 2 BUILDING CONSTRUCTOR 
// - defining object and then having to use dot notation to assign values to it every time can be long and difficult task
// - to help alleviate that issue, we can build constructor to help us create object with specified attributes

//--------------------
// Default Constructor
// - constructor works similarly to function in that you can define parameters within constructor
// - then when it’s time to call constructor, you can just simply give it appropriate arguments and object can be made

//add class definitions below this line
    
class Student {
  public:
    string name;
    int ID;
    string major;
    double GPA;
    int age;
    int YOG;
    
  Student() {
    name = "Andy";
    ID = 123456;
    major = "Computer Science";
    GPA = 3.45;
    age = 22;
    YOG = 2021;
  }
};
  
//add class definitions above this line

int main() {
  
  //add code below this line

  Student mary;
  cout << mary.name << "'s student ID is " << mary.ID << "." << endl;
 
  mary.name = "Mary";
  mary.GPA = 3.78;
  
  cout << mary.name << " has a current GPA of " << mary.GPA << "." << endl;

  //add code above this line
  
  return 0;
  
}

// - before, we had to use dot notation to assign values to our object 
// - but having constructor, we can build it in way that it will have default values when object is created
// - notice how object mary has all of attributes of andy

//-----------------------------
// Constructors with Parameters
// - default constructor makes all objects andy object when they are built
// - to change attributes of object, we can still use dot notation (i.e. mary.name = "Mary";) 
// - most Students are unique and to have to reassign value every time default constructor is used can still be small challenge
// - to make constructor more flexible, we can give it parameters 
// - constructor with parameters works similarly to user-defined function in which you provide parameter types and user simply has to provide arguments

//add class definitions below this line
    
class Student {
  public:
    string name;
    int ID;
    string major;
    double GPA;
    int age;
    int YOG;
    
  Student(string n, int id, string m, double g, int a, int y) {
    name = n;
    ID = id;
    major = m;
    GPA = g;
    age = a;
    YOG = y;
  }
};
  
//add class definitions above this line

int main() {
  
  //add code below this line

  Student andy("Andy", 123456, "Computer Science", 3.45, 22, 2021);
  Student mary("Mary", 456789, "Mathematics", 3.78, 21, 2022);
  
  cout << mary.name << " is a student in the " << mary.major << " department." << endl;
  cout << mary.name << " is a junior while " << andy.name << " is a senior." << endl;

  //add code above this line
  
  return 0;
  
}

// - constructor with parameters enables user to decide what attributes to assign right when object is created
// - user just has to provide those attributes as arguments in parentheses (i.e. Student mary("Mary", 456789, "Mathematics", 3.78, 21, 2022);)

//--------------
// LAB CHALLENGE

// - create variable dog1, and instantiate it as object of Dog class 
// - this dog’s name is Marceline and she is German Shepherd
// - create variable dog2 and make it copy of dog1
// - dog2 should be named Cajun and have breed Belgian Malinois

// - your goal for this assignment is to design class Dog so that above can be implemented successfully

// Expected Output
// - test your code by printing name and breed of each dog to make sure they fulfill requirements above
// - most importantly, third print statement will print false

// Marceline German Shepherd
// Cajun Belgian Malinois
// false

#include <iostream>
using namespace std;

//add class definitions below this line
    
class Dog {
  public:
    string name;
    string breed;
  
  Dog(string a, string b) {
    name = a;
    breed = b;
  }
};
  
//add class definitions above this line

int main() {

Dog dog1("Marceline", "German Shepherd");
Dog dog2 = dog1;
dog2.name = "Cajun";
dog2.breed = "Belgian Malinois";
    
cout << dog1.name << " " << dog1.breed << endl;
cout << dog2.name << " " << dog2.breed << endl;
if (dog1.name == dog2.name && dog1.breed == dog2.breed) {
  cout << boolalpha << true;
}
else {
  cout << boolalpha << false;
}
  
  return 0;
  
}

// - based on code that’s been provided, you’ll need to create constructor that takes parameters as arguments
// - there are two parameters available in code name and breed, both of which are strings
// - once you’ve determine this, set up constructor and assign attributes of class to parameters within constructor

//---------------------------------------------------------------------------------------------------//

//-----------
// Exercise 1 

// - define class PracticeClass
// - it should have only single string attribute name
// - this class should not have constructor

// whole code: 
#include <iostream>
using namespace std;

//add class definitions below this line
    
class PracticeClass {
  public:
    string name;
};
  
//add class definitions above this line

int main() {
  
  PracticeClass obj;
  obj.name = "Class Object";
  cout << obj.name;
  
  return 0;
  
}
