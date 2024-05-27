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
// file 2222, week 2 1/5 (Base and Derived Classes 2) 

// Access Modifiers Review
// Before we can look at the effects of inheritance types, we will need to review some access modifier vocabulary:
// private - private members of a class can only be accessed by other members within the same class.
// protected - protected members of a class can be accessed by other members within the same class or by a derived class.
// public - public members of a class can be accessed by other members within the same class, by a derived class, or by an external or outside class.

#include <iostream>
using namespace std;

class Base {
  public:
    void Public(string s) {
      s = "public";
      cout << s << endl;
    }
  
  protected:
    void Protected(string s) {
      s = "protected";
      cout << s << endl;
    }
    
  private:
    void Private(string s) {
      s = "private";
      cout << s << endl;
    }
};

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //add code below this line
  
  string s_main;
  Derived dc;
  dc.ReturnProtected(s_main);
  dc.Public(s_main);

  //add code above this line
  
  return 0;
  
}

// Accessing Class Members
// In the text editor, the Base class has already been defined. 
// Within this base class, you’ll see that there is a public function, a protected function, and a private function. Add the following derived class to your code:

class Derived : public Base {
  public:
    void ReturnPublic(string s) {
      Public(s_derived); //public function inherited from Base
    }
  
  private:
    string s_derived;
};

// The derived class Derived has one public function and one private attribute and it publicly inherits all public and protected members of the base class Base.
// This means that it can call and use any functions or attributes of Base with the exception of anything that is private.
// Next, add the following code into the main function:
  
  string s_main;
  Derived dc;
  dc.ReturnPublic(s_main);


// In main, a string s_main and a Derived object dc are created. 
// Then ReturnPublic() is called on dc with s_main as the parameter. 
// ReturnPublic is a public member function of the Derived class which takes a string as a parameter and calls the Public member function of the Base class on s_derived. 
// The entire process sounds very complicated but can be explained visually in the flowchart below.

// The reason why main is able to call ReturnPublic is due to the fact that ReturnPublic is a public member function within Derived.

// Try this variation:
// Revise Derived to look like:
class Derived : public Base {
  protected:
    void ReturnPublic(string s) {
      Public(s_derived);
    }
  
  private:
    string s_derived;
};

// When the ReturnPublic member function of Derived is protected, main is no longer able to access it. Remember, external classes can only access public members of other classes, unless it is a derived class. Derived classes can access protected members in addition to public ones.
// Next, let’s change Derived and main to look like this:

//add class definitions below this line

class Derived : public Base {
  public:
    void ReturnPublic(string s) {
      Public(s_derived); //public function inherited from Base
    }
  
    void ReturnProtected(string s) {
      Protected(s_derived); //protected function inherited from Base
    }
  
  private:
    string s_derived;
};

//add class definitions above this line

  //add code below this line
  
  string s_main;
  Derived dc;
  dc.ReturnProtected(s_main);
  dc.Public(s_main);

  //add code above this line

// Notice how main can call Public and also ReturnProtected from Derived because those functions are public. 
// Additionally, Derived can call the protected function Protected in ReturnProtected from Base because Derived is a derived class of Base.

// sub exercise 
// Determine the Derived Class's Access
// Given the following code snippet:

class Base {
  public:
    int x;
  
  protected:
    int y;
    
  private:
    int z;
};

class Derived : public Base {
  
};

// Select all class members of Base that Derived has access to.
// a) x
// b) y
// c) z
// d) None of the members of Base are accessible to Derived

// a), b) 
// Because Derived is a derived class of Base, it will have access to all public and protected class members of Base. 
// Therefore, it can access both x and y.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes 3) 

// How Inheritance Works

#include <iostream>
using namespace std;

class Base {
  public:
    void Public(string s) {
      s = "public";
      cout << s << endl;
    }
  
  protected:
    void Protected(string s) {
      s = "protected";
      cout << s << endl;
    }
    
  private:
    void Private(string s) {
      s = "private";
      cout << s << endl;
    }
};

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //add code below this line
  
  string s_main;
  Derived dc;
  dc.ReturnProtected(s_main);
  dc.Public(s_main);

  //add code above this line
  
  return 0;
  
}

// Now that you’re more comfortable with access modifiers, let’s take a look at how inheritance types affect derived classes. 
// Make sure your Derived and main code look like what’s below. 
// Note that Derived now inherits from Base through protected inheritance instead of public.
//add class definitions below this line

class Derived : protected Base {
  public:
    void ReturnPublic(string s) {
      Public(s_derived);
    }
  
    void ReturnProtected(string s) {
      Protected(s_derived);
    }
  
  private:
    string s_derived;
};

//add class definitions above this line
  //add code below this line
  
  string s_main;
  Derived dc;
  dc.ReturnProtected(s_main);
  dc.Public(s_main);

  //add code above this line

// You’ll notice that an error is produced saying that ‘Base’ is not an accessible base of ‘Derived’. This occurs because when a derived class inherits from a base class through protected inheritance, all public and protected members of the base class become protected in the derived class. 
// This means that the Public function within Derived was inherited as a protected function and is therefore no longer accessible within main.
// On the other hand, ReturnProtected is still a public function within Derived, which allows main to access it even though it calls the protected function Protected from Base. 
// Comment out the command dc.Public(s_main); and run the code again to see the result.
// Though not explicitly shown, Derived can be represented like this:

class Derived : protected Base {
  public:
    void ReturnPublic(string s) {
      Public(s_derived);
    }
  
    void ReturnProtected(string s) {
      Protected(s_derived);
    }
  
  /*protected:
    void Public(string s) { (inherited as protected from Base)
      s = "public";
      cout << s << endl;
    }
  
    void Protected(string s) { (inherited as protected from Base)
      s = "protected";
      cout << s << endl;
    }*/
  
  private:
    string s_derived;
};

// If you ever get confused with inheritance types, you can always imaginatively rewrite all of the functions that were inherited and label them appropriately to help you visualize the derived class better. Here are some more examples:

class Base {
  public:
    int x;
  
  protected:
    int y;
  
  private:
    int z;
};

class Derived : public Base {
  //public:
    //int x;
  
  //protected:
    //int y;
};
class Base {
  public:
    int x;
  
  protected:
    int y;
  
  private:
    int z;
};

class Derived : protected Base {
  //protected:
    //int x;
    //int y;
};
class Base {
  public:
    int x;
  
  protected:
    int y;
  
  private:
    int z;
};

class Derived : private Base {
  //private:
    //int x;
    //int y;
};

// Note that private members are never inherited. 
// Also, the examples are provided to help you visualize what the derived classes look like after inheritance. 
// If you were to actually add the member attributes into Derived without comments, those attributes will count as being part of the Derived class instead of being inherited from the Base class.

// sub exercise 
// Accessible Functions

Given the following code snippet:

class Base {
  public:
    void SetName(string nm) {
      name = nm;
    }
  
  protected:
    void SetAge(int a) {
      age = a;
    }
    
  private:
    string name;
    int age;
};

class Derived : protected Base {
  
};

// Determine which of the following code in the main function will successfully execute.

// a) 
// Base bc;
// bc.SetName("Peter Parker");

// b) 
// Base bc;
// bc.SetAge(13);

// c) 
// Derived dc;
// dc.SetName("Peter Parker");

// d) 
// Derived dc;
// dc.SetAge(13);

// answer: 
// a) 

// First, notice that Derived inherits members from Base through protected inheritance. 
// This inheritance will cause all inherited functions in Derived to be protected. 
// Remember, main is not part of the Base nor Derived class, which means that it can only call functions that are public. 
// The only available public function exists within Base and that is the void SetName(string nm) function. 
// To call this function, you’ll need to create a Base object and then call SetName on that object.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes 4) 

// Inheriting the Constructor

#include <iostream>
using namespace std;

class Person {
  public:
    Person(string n1, int a1) {
      name = n1;
      age = a1;
    }
  
    void ReturnPerson() {
      cout << name << endl;
      cout << age << endl;
    }
  
  private:
    string name;
    int age;
};

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

// How are Constructors Inherited?
// Unlike functions and attributes, the constructor that is inherited by the derived class needs to get linked or associated with that of the base class. To connect the derived constructor to the base constructor, follow this syntax:
// Derived class name
// Parentheses ()
// Parameters with specified data types within parentheses
// Colon :
// Base class name
// Parentheses ()
// Parameters of derived class as arguments in parentheses
// Any additional commands in curly braces {} or leave them empty
// Sample Code:
// Constructor2(Param p1, Param p2) : Constructor1(p1, p2) {}
// Add the following code to the class definitions field:
//add class definitions below this line

class Superhero : public Person {
  public:
    Superhero(string n2, int a2) : Person(n2, a2) {}
};

//add class definitions above this line

// And the following to main:

  //add code below this line

  Superhero s("Spider-Man", 16);
  s.ReturnPerson();

  //add code above this line

// By associating the derived constructor with the base constructor, C++ is able to pass the parameters specified in the derived constructor as arguments of the base constructor. 
// In the code above, the arguments Spider-Man and 16 are passed to the Superhero constructor and then transferred over to the Person constructor where they get assigned to name and age respectively. 
// Then, the ReturnPerson function is used to print name which is now Spider-Man and age which is now 16.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes 5) 

// Determining a Derived Class’s Base Class

#include <iostream>
using namespace std;

class Person {
  public:
    void Greeting() {
      cout << "I'm a Person" << endl;
    }
};

class Superhero : public Person {
  public:
    void Greeting() {
      cout << "I'm a Superhero" << endl;
    }
};

class Animal {
  public:
    void Greeting() {
      cout << "I'm an Animal" << endl;
    }
};

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

// How do you determine if a derived class actually belongs to a base class? One common way to determine this is to use the is_base_of<Base, Derived>::value function. Just substitute Base with the name of the base class and Derived with the name of the derived class.

  //add code below this line

  cout << boolalpha;
  cout << "B is derived from A: " << is_base_of<A, B>::value << endl;
  cout << "C is derived from B: " << is_base_of<B, C>::value << endl;
  cout << "A is derived from C: " << is_base_of<C, A>::value << endl;

  //add code above this line

// Here is an example:

  //add code below this line

  cout << boolalpha;
  cout << "Superhero is derived from Person: " << is_base_of<Person, Superhero>::value << endl;
  cout << "Animal is derived from Superhero: " << is_base_of<Superhero, Animal>::value << endl;
  cout << "Person is derived from Animal: " << is_base_of<Animal, Person>::value << endl;

  //add code above this line

// Try this variation:
// Add the following to main:
  cout << "Person is derived from Superhero: ";
  cout << is_base_of<Superhero, Person>::value << endl;

// You’ll notice that the function returns true if the derived class inherits from the base class and false when that is not the case.

// Determining an Object’s Base Class
// Unfortunately, C++ has no built-in function to determine if an object is from a class that inherits from another class. Instead, use typeid(<object_name>).name() to try and extract the object’s type, and then use the is_base_of<Base, Derived>::value to see if that object’s class is derived from another specified class. Replace <object_name> with the name of the object.
// Remove all existing code in main and add the following:

  //add code below this line

  Superhero s;
  cout << "s is of type: " << typeid(s).name() << endl;

  //add code above this line

// Your output may look something like s is of type: 9Superhero. The 9 is just a number that is produced by the compiler, which can be ignored. Once you determine the object’s class, you can then compare that class to another class to see if it is a derived class.

  //add code below this line

  Superhero s;
  cout << "s is of type: " << typeid(s).name() << endl;
  cout << boolalpha;
  cout << "Superhero is derived from Person: ";
  cout << is_base_of<Person, Superhero>::value << endl;

  //add code above this line

// The functions provided above can help you determine an object’s class and compare it with another known class. There is unfortunately no function to determine an object’s base class directly.

// sub exercise 
// Comparing Base and Derived Classes

// What does the function is_base_of<X, Y>::value do?

// a) Determines if X is an object of Y.
// b) Determines if Y is a derived class of X.
// c) Determines if X is a derived class of Y.
// d) Determines if Y is an object of X.

// answer: 
// b) 
// The is_base_of<X, Y>::value function compares classes, not objects. 
// The first argument X represents the base class and the second argument Y represents the derived class. 
// Therefore, the correct choice is Determines if Y is a derived class of X.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes 6) 

// Substitution Principle

#include <iostream>
using namespace std;

//add class definitions below this line

class Person {
  public:
    void Greeting() {
      cout << "I'm a Person" << endl;
    }
};

class Superhero : public Person {
  public:
    void Greeting() {
      cout << "I'm a Superhero" << endl;
    }
};

class Animal {
  public:
    void Greeting() {
      cout << "I'm an Animal" << endl;
    }
};

//add class definitions above this line

//add function definitions below this line



//add function definitions above this line

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

// When one class inherits from another, C++ considers them to be related. 
// They may contain different data types, but C++ allows a derived class to be used in place of the base class. 
// This is called Liskov’s Substitution Principle.
// In the text editor you’ll notice that Superhero inherits from Person, but Animal does not.
// All classes have the Greeting function which prints a statement specific to the class.

//add class definitions below this line

class Person {
  public:
    void Greeting() {
      cout << "I'm a Person" << endl;
    }
};

class Superhero : public Person {
  public:
    void Greeting() {
      cout << "I'm a Superhero" << endl;
    }
};

class Animal {
  public:
    void Greeting() {
      cout << "I'm an Animal" << endl;
    }
};

//add class definitions above this line

// According to the Substitution Principle, an object of Superhero can be used in a situation that expects an object of Person. 
// Add the Substitution function below which explicitly requires a parameter of a Person object.

//add function definitions below this line

void Substitution(Person p) {
  p.Greeting();
}

//add function definitions above this line

// Instantiate an object of Superhero and pass it to the Substitution function. 
// Even though the object s has the wrong data type, the code should still work due to the Substitution Principle. 
// Because Superhero is derived from Person, object s can be used in place of an object of type Person. 
// Run the code to verify the output.

  //add code below this line

  Superhero s;
  Substitution(s);

  //add code above this line

// Try this variation:
// Revise main to:
  Animal a;
  Substitution(a);
// Why did this produce an error?
// The Animal class is not derived from Person, therefore the Substitution Principle no longer applies.

// The Substitution Principle is a One-Way Relationship
// Let’s revise the Substitution function and main to look like below:

//add function definitions below this line

void Substitution(Superhero s) {
  s.Greeting();
}

//add function definitions above this line

  //add code below this line

  Person p;
  Substitution(p);

  //add code above this line

// The code above produces an error stating that the object p cannot be converted to a Superhero object. 
// Kind of like how a square is considered to be a rectangle, but a rectangle is not considered to be a square, inheritance works the same way. 
// A Superhero object is considered to be a Person object, but a Person object is not considered to be Superhero object.

// Inheritance Can Be Extended
// Inheritance can be extended, which means that a derived class can inherit attributes of another derived class. 
// Revise the class definitions to look like below:

//add class definitions below this line

class Person {
  public:
    void Greeting() {
      cout << "I'm a Person" << endl;
    }
};

class Hero : public Person {
  public:
    void Greeting() {
      cout << "I'm a Hero" << endl;
    }
};

class Superhero: public Hero {
  public:
    void Greeting() {
      cout << "I'm a Superhero" << endl;
    }
};

//add class definitions above this line

// You’ll notice that we have an intermediate class called Hero which is a derived class of Person. 
// The Superhero class is then derived from the Hero class. 
// When there are multiple levels of inheritance, the immediate upper class is considered to be a direct base class and all higher classes are considered to be indirect base classes. 
// This means that Hero is a direct base class of Superhero while Person is an indirect base class of Superhero. 
// Superhero is still considered to be a derived class of both Hero and Person.
// See what happens when you you revise the Substitution function and main to look like below:

//add function definitions below this line

void Substitution(Person p) {
  p.Greeting();
}

//add function definitions above this line

  //add code below this line

  Superhero s;
  Substitution(s);
  Hero h;
  Substitution(h);

  //add code above this line

// Whether the object is of class Superhero or Hero, the Substitution function still works because both are derived classes of Person.

// sub exercise 
// Substitution Principle
// Fill in the blanks below with the correct vocabulary.

// The Substitution Principle states that a substitution can be made if a 
// main
// derived class
//  object is used in place of its 
// main
// base class
//  object.

// C++ allows a derived class to be used in place of the base class according to Liskov’s Substitution Principle.


//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes exercise 1) 

// Formative Assessment 1
// Creating a Derived Class

// Given the following class:

class Pet {
  private:
    string name;
};

// Select the code that creates the Dog class that inherits from Pet.

// a) class Dog inherits public Pet {
// };

// b) class Dog(class Pet) {
// };

// c) class Dog extends public Pet {
// };

// d) class Dog : public Pet {
// };

// answer: d) 
// To create a derived class, the following syntax should be fulfilled in the following order:

// Keyword class
// Name of derived class
// Colon :
// Access modifier
// Name of base class


//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 1/5 (Base and Derived Classes exercise 2) 

// Deriving a Class from a Base Class
// Given the following code:
class Dog {
  public:
    Dog(string n1, string b1) {
      name = n1;
      breed = b1;
    }

  private:
    string name;
    string breed;
};

// Drag and drop the code blocks into the highlighted field below to create the derived class Pug that calls the constructor from the base class Dog with arguments.

class Pug : public Dog {
public:
Pug(string n2, string b2) : Dog(n2, b2) {}
};

// First create the derived class, Pug, that inherits from the base class Dog. 
// Note that public inheritance should be used over private, otherwise, the derived class constructor will not be able to access the base class constructor. 
// The constructor of the derived class Pug should contain the same parameter types as that of the base class. 
// Therefore, Pug needs two string parameters (i.e. string n2 and string b2). 
// Then associate the derived class constructor with a colon : followed by the name of the base class constructor as well as its arguments and finally empty braces ({}). 
// Note that the Pug constructor itself should be made public: and this declaration must be made before the constructor and association, otherwise, creating a Pug object within main() will not be possible. 
// Finally, end with the ending curly brace } followed by a semicolon (;).


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

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 2/5 (Extending and Overriding exercise 1)
// Formative Assessment 1
// Extending a Derived Class
// Given the following base class:

class Car {
  public:
    Car(string ma, string mo, string c) {
      make = ma;
      model = mo;
      color = c;
    }

    string GetMake() {
      return make;
    }

    string GetModel() {
      return model;
    }

    string GetColor() {
      return color;
    }

  private:
    string make;
    string model;
    string color;
};

// Drag and rearrange the code blocks below to create a derived class called Sedan that gets extended with the Describe function. 
// This function prints the string I am a red Toyota Camry. where red is the object’s color, Toyota is the object’s make, and Camry is the object’s model.

// Note: Not all code blocks will be used. 
// Indentation is also disabled for this particular assessment and you will have just ONE ATTEMPT with this problem.

class Sedan : public Car {
  public:
    Sedan(string ma, string mo, string c) : Car(ma, mo, c) {}
    void Describe() {
      cout << "I am a " << GetColor() << ' ';
      cout << GetMake() << ' ' << GetModel() << '.' << endl;
    }
};

// The Sedan class should inherit from the Car class, so be sure to use correct inheritance syntax. Specifically, you should use public instead of private as the access modifier.
// The Sedan class needs to invoke a Car constructor to pass it three arguments. Use the : operator and correct constructor syntax for this.
// Since the Describe function does not return anything, use void instead of string as the return type.
// The make, model, and color attributes are private within the base class, so you need to use the getter functions to access these values.

