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
