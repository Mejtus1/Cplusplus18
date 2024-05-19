//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes 1)

// Defining Inheritance
// Imagine you want to create two C++ classes, Person and Superhero. These respective classes might look something like this:

// There are some similarities between the Person class and the Superhero class. If the Person class already exists, it would be helpful to “borrow” from the Person class so you only have to create the new attributes and functions for the Superhero class. This situation describes inheritance — one class copies the attributes and functions from another class.

#include <iostream>
using namespace std;

class Person {
  public:
    string GetName() {
      return name;
    }
  
    void SetName(string new_name) {
      name = new_name;
    }
  
    int GetAge() {
      return age;
    }
  
    void SetAge(int new_age) {
      age = new_age;
    }
  
    string GetOccupation() {
      return occupation;
    }
  
    void SetOccupation(string new_occupation) {
      occupation = new_occupation;
    }
  
    void SayHello() {
      cout << "Hello, my name is " << name << '.' << endl;
    }
  
    void SayAge() {
      cout << "I am " << age << " years old." << endl;
    }
  
  private:
    string name;
    int age;
    string occupation;
};

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

// Inheritance Syntax
// In the IDE on the left, the Person class is already defined. 
// To create the Superhero class that inherits from the Person class, add the following code at the end of the class definitions. 
// Notice how the Superhero class definition contains a colon : followed by public and then Person. 
// This is how you indicate to C++ that the Superhero class inherits from the Person class. 
// You can also say that Person is the base class and Superhero is the derived class. 
// A base class in C++ is also referred to as a superclass or parent class while a derived class is also referred to as a subclass or child class. 
// All of these terms can be used interchangeably.

//add class definitions below this line

class Superhero : public Person {
  
};
  
//add class definitions above this line

// Now declare an instance of the Superhero class and print the value of the name and age attributes using their getter functions.
  
Superhero s;
cout << s.GetName() << endl;
cout << s.GetAge() << endl;

// What does the output of the program above mean?
// In C++, reducing memory usage is important and initializing values to variables requires memory. Uninitialized variables do not get assigned specified values automatically. Thus, when printing the value of uninitialized variables, you might get random and unexpected output. The output is considered to be junk data that are left over at the variables' memory location.

// Accessibility of Inheritance
// C++ places some rules about how inheritance works. 
// Depending on the access modifier of the specified superclass, the subclass may or may not inherit certain class functions or attributes. 
// Here is a list showcasing each access modifier and its effect on the subclass.
// “public inheritance makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.”
// “protected inheritance makes the public and protected members of the base class protected in the derived class.”
// “private inheritance makes the public and protected members of the base class private in the derived class.”

// Notice how in each case, the derived class never inherits any private members from the base class. 
// Public inheritance causes the derived class to inherit the members as is. 
// Protected inheritance causes the derived class to inherit all public and protected members as protected only. 
// And private inheritance causes all inherited members to be private only.
// You can see how restrictive protected and private inheritance is, which is why they are rarely used.
// For this module, we will be using mainly public inheritance when creating derived classes.

// sub exercise 
// Inheritance Basics
// Given the following code:
class BaseClass {
  public:
    int a;
  protected:
    int b;
  private:
    int c;
};

class DerivedClass : protected BaseClass {

};
// Determine the access type of each of the attributes that were inherited by the DerivedClass from the BaseClass.

// a is 
// protected

// b is 
// protected

// c is 
// not accessible

// Due to the protected inheritance type, the derived class will inherit all members of the base class as protected. Remember, private members are never inherited.


//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 2/5 (Extending and Overriding)
//----------------------------
// Extending the Derived Class
// - idea of inheritance is to borrow from base class and then add on functionality
// - up until now, we have talked about borrowing from base class but have not gone into detail about adding additional functionality to derived class
// - process of adding functionality to derived class is known as either extending or overriding
// - extending class means that new attributes and functions are given to derived class
// - let’s continue working with our Person and Superhero classes

// - code below will first associate derived class constructor with base class constructor
// - however, we want to add additional attribute as parameter to derived class constructor
// - doing so will extend derived class because objects created will have 4 parameter attributes instead of 3
// - additional getter and setter functions are also added to extend derived class even further

//add class definitions below this line

class Superhero : public Person {
  public:
    Superhero(string n, int a, string o, string s) : Person(n, a, o) {
      secret_identity = s;
    }
  
    string GetSecretIdentity() {
      return secret_identity;
    }
  
    void SetSecretIdentity(string new_secret_identity) {
      secret_identity = new_secret_identity;
    }
  
  private:
    string secret_identity;
};

//add class definitions above this line

// - in main, instantiate Superhero object and print out each of attributes
// - you should see three attributes from Person class as well as new attribute secret_identity

  //add code below this line

  Superhero hero("Spider-Man", 16, "student", "Peter Parker");
  cout << hero.GetName() << endl;
  cout << hero.GetAge() << endl;
  cout << hero.GetOccupation() << endl;
  cout << hero.GetSecretIdentity() << endl;

  //add code above this line

// Inheritance Is One-Way Street
// - inheritance shares attributes and functions from base class to derived class
// - when derived class is extended, it cannot share new additions with its base class
// - in code above, Superhero class has access to attributes name, age, and occupation, but Person does not have access to secret_identity

// Try this variation:
// - rewrite Superhero class so that it extends Person class by adding string attribute nemesis
// - constructor will also include nemesis as last parameter with Doc Octopus as its argument 
// - remember to include relevant getter and setter functions too

//add class definitions below this line

class Superhero : public Person {
  public:
    Superhero(string n, int a, string o, string s, string ne) : Person(n, a, o) {
      secret_identity = s;
      nemesis = ne;
    }
  
    string GetSecretIdentity() {
      return secret_identity;
    }
  
    void SetSecretIdentity(string new_secret_identity) {
      secret_identity = new_secret_identity;
    }
  
    string GetNemesis() {
      return nemesis;
    }
  
    void SetNemesis(string new_nemesis) {
      nemesis = new_nemesis;
    }
  
  private:
    string secret_identity;
    string nemesis;
};

//add class definitions above this line

int main() {
  
  //add code below this line

  Superhero hero("Spider-Man", 16, "student", "Peter Parker", "Doc Octopus");
  cout << hero.GetName() << endl;
  cout << hero.GetAge() << endl;
  cout << hero.GetOccupation() << endl;
  cout << hero.GetSecretIdentity() << endl;
  cout << hero.GetNemesis() << endl;

  //add code above this line
  
  return 0;
  
}

//---------------------------------------------
// Extending a Class by Adding Unique Functions
// - another way to extend class is to create new functions that are unique to derived class 
(besides getter and setter functions)
// - currently, function SayHello will print superhero’s name, but it will not print their secret identity
// - create function RevealSecretIdentity to print greeting that reveals SecretIdentity

//add class definitions below this line

class Superhero : public Person {
  public:
    Superhero(string n, int a, string o, string s, string ne) : Person(n, a, o) {
      secret_identity = s;
      nemesis = ne;
    }
  
    string GetSecretIdentity() {
      return secret_identity;
    }
  
    void SetSecretIdentity(string new_secret_identity) {
      secret_identity = new_secret_identity;
    }
  
    string GetNemesis() {
      return nemesis;
    }
  
    void SetNemesis(string new_nemesis) {
      nemesis = new_nemesis;
    }
  
    void RevealSecretIdentity() {
      cout << "My real name is " << secret_identity << '.' << endl;
    }
  
  private:
    string secret_identity;
    string nemesis;
};

//add class definitions above this line

// - now test out newly added function
  
  //add code below this line

  Superhero hero("Spider-Man", 16, "student", "Peter Parker", "Doc Octopus");
  hero.RevealSecretIdentity();

  //add code above this line

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 2/5 (Extending and Overriding 2)
//--------------------
// Overriding Function
// - extending class means adding new attributes or functions to derived class
// - another way to add new functionality to derived class is through function overriding
// - overriding function means to inherit function from base class, keep its name, but change contents of function
// - extend Superhero class by overriding SayHello function
// - name attribute is part of base class and it is private, so you need to use GetName function to access this attribute
   
    //add class definitions below this line
  
    void SayHello() {
      cout << "My name is " << GetName() << ", and criminals fear me." << endl;
    }
  
    //add class definitions above this line
Instantiate a Superhero object and call the SayHello function on it.
  //add code below this line

  Superhero hero("Storm", 30, "Queen of Wakanda", "Ororo Munroe", "Shadow King");
  hero.SayHello();

  //add code above this line

//-----------------------------------------
// Differentiating Overriding and Extending

// - add and override SayAge function in the Superhero class so that it prints the string, Age is just a number., then call it on hero in the main function.

// - what Happens to Overridden Function?
// - if you can override function from base class, what happens to its original function? 
// - C++ defaults to instance or object type 
// - so hero.SayHello() will always use function from derived Superhero class 
// - but that does not mean you cannot call SayHello from base Person class
// - call original base class function, you can use hero.Person::SayAge() where hero represents derived class object, Person represents base class, and SayAge represents base class function
// - :: is called scope resolution operator and it is used to direct C++ to look for function SayAge inside Person class
// - make sure you have following class definitions in your code
    //add class definitions below this line
  
    void SayHello() {
      cout << "My name is " << GetName() << ", and criminals fear me." << endl;
    }

    void SayAge() {
      cout << "Age is just a number." << endl;
    }
  
    //add class definitions above this line

// - run following commands in main to see result

  //add code below this line

  Superhero hero("Storm", 30, "Queen of Wakanda", "Ororo Munroe", "Shadow King");
  hero.SayHello();
  hero.Person::SayHello();
  hero.SayAge();
  hero.Person::SayAge();
  
  //add code above this line

// Note 
// - how in code above, using scope resolution operator causes base class function to be called while not using it causes derived class function to be called
