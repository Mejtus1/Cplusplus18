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

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 2/5 (Extending and Overriding exercise 2)

// The SportsCar class inherits from the Car class and the Acceleration function overrides a function from Car. 
//If the original base function within Car is:

class Car {
  public:
    Car(string ma, string mo, string c) {
      make = ma;
      model = mo;
      color = c;
    }

    void Acceleration(double v, double t) {
      velocity = v;
      time = t;
      cout << "I can accelerate as fast as " << velocity/time;
      cout << " meters per second squared." << endl;
    }

  private:
    string make;
    string model;
    string color;
    double velocity;
    double time;
};

// What is wrong with the Acceleration function within SportsCar as shown below?

class SportsCar : public Car {
  public:
    SportsCar(string ma, string mo, string c, double a) : Car(ma, mo, c) {
      acceleration = a;
    }

    void Acceleration() {
      cout << "I can accelerate as fast as " << velocity/time;
      cout << " meters per second squared." << endl;
    }

  private:
    double acceleration;
};

// a) SportsCar does not have access to velocity and time within Car. Therefore, acceleration should be used instead of velocity/time.
// b) The Acceleration function parameters in SportsCar must look exactly the same as Acceleration in Car.
// c) It should be double Acceleration() instead of void Acceleration() in SportsCar.
// d) There is nothing wrong with the Acceleration function in SportsCar.

// answer: 
// Remember, function overriding involves a function in the base class being overridden by the function of the derived class. 
// The goal is to create a unique function that contains the same name as the original function but different in terms of functionality. 
// Therefore, the function parameters within the derived class do not have to be the same as that of the base class.
// Acceleration does not return anything, so void is the correct return type.
// velocity and time within Car are private attributes and are therefore not accessible within SportsCar.
// Due to these reasons, SportsCar does not have access to velocity and time within Car. Therefore, acceleration should be used instead of velocity/time is the correct answer choice.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 3/5 (1)

// Multiple Inheritance
// Multiple inheritance is a condition where a class inherits from more than one base class. 
// C++ allows multiple inheritance for both associated and unassociated base classes; however, for this particular section, we will only go over multiple inheritance with associated base classes, meaning one base class is derived from another base class.
// Multilevel Inheritance
// Multiple inheritance with associated base classes is called multilevel inheritance. 
// This is a condition where a class inherits from more than one base class, but each base class is associated with each other. 
// The image below shows ClassC inheriting from ClassB, which in turn inherits from ClassA. 
// This is an example of multilevel inheritance.

// The classes Carnivore and Dinosaur are already defined. Carnivore is the base class for Dinosaur. Create the Tyrannosaurus class which is a derived class of Dinosaur. The constructor for Tyrannosaurus takes a string and two doubles and gets associated with the constructor from the Dinosaur class.

//add class definitions below this line

  class Tyrannosaurus : public Dinosaur {
    public:
      Tyrannosaurus(string d, double s, double w) : Dinosaur(d, s, w) {}
  };

//add class definitions above this line

// Instantiate a Tyrannosaurus object with the appropriate arguments. 
// This t-rex tiny is 12 meters tall, weighs 14 metric tons, and eats whatever it wants. 
// Print the size attribute to make sure inheritance is working as expected.

  //add code below this line

  Tyrannosaurus tiny("whatever it wants", 12, 14);
  cout << tiny.GetSize() << endl;

  //add code above this line


// sub exercise

// Which of the following is true regarding multilevel inheritance?

// a) Multilevel inheritance can only occur through protected inheritance. It cannot work with public and private inheritance.
// b) Multilevel inheritance can occur when a base class of a derived class is derived from another base class.
// c) Multilevel inheritance occurs when there is just one base class and one derived class.
// d) Multilevel inheritance occurs when a derived class inherits from two classes that are not associated with each other.

// answer: b) 
// By definition, multilevel inheritance occurs when a derived class inherits from another derived class in which case all classes are associated with each other. 
// Therefore, the correct answer choice is Multilevel inheritance can occur when a base class of a derived class is derived from another base class.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 3/5 (2)

#include <iostream>
using namespace std;

class ClassA {
  public:
    void Hello() {
      cout << "Hello from Class A" << endl;
    }
};

class ClassB : public ClassA {
  public:
    void Hello() {
      cout << "Hello from Class B" << endl;
    }
};

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

// Extending a Class within Multilevel Inheritance
// Multilevel inheritance works just like single inheritance except there are more than one derived class. 
// Add the following code as class definitions in the text editor.

//add class definitions below this line

class ClassC : public ClassB {
  public:
    void Bonjour() {
      cout << "Bonjour" << endl;
    }
};

//add class definitions above this line

// Instantiate a ClassC object to call the Bonjour function. 
// Then use the scope resolution operator : to invoke the Hello function from both ClassB and ClassA.

  //add code below this line

  ClassC c;
  c.Bonjour();
  c.ClassB::Hello();
  c.ClassA::Hello();

  //add code above this line

//----------------------------------------------------
// Overriding a Function within Multilevel Inheritance
// Like extending a class, overriding a function works the same in multilevel inheritance as it does in single inheritance. 
// Change ClassC so that it overrides the Hello function.

//add class definitions below this line

class ClassC : public ClassB {
  public:
    void Hello() {
      cout << "Hello from Class C" << endl;
    }
};

//add class definitions above this line

// Now replace the call to Bonjour with a call to Hello.

  //add code below this line

  ClassC c;
  c.Hello();
  c.ClassB::Hello();
  c.ClassA::Hello();

  //add code above this line

// Notice how calling the Hello function automatically defaults to the function within theobject’s specified class. 
// If you want to call the same function as specified from within another base class, simply use the scope resolution operator : as shown above.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 3/5 (3 exercise )

// Multilevel Inheritance Statements

// Given the following code snippet:

class Foxtrot : public Golf {
  public: 
    void Hello() {
      cout << "hello" << endl;
      Golf::Hello();
    }
};

class Echo : public Foxtrot {
  public:
    void Hello() {
      cout << "hello world" << endl;
    }
};

// Select all of the statements below that are true.


// a) Class Foxtrot is a base class to Echo and a derived class to Golf.
// b) Class Echo is an example of multilevel inheritance.
// c) Class Foxtrot overrides the Hello function.
// d) You can substitute a Golf object for an Echo object.

// answer: a), b), c) 

// The correct answers are:

// Class Foxtrot overrides the Hello function. This is true because Golf::Hello() means that another Hello function exists in the base class Golf. Adding new functionality is considered function overriding.
// Class Foxtrot is a base class to Echo and a derived class to Golf. This is true because Foxtrot inherits from Golf and Echo inherits from Foxtrot.
// Class Echo is an example of multilevel inheritance. This is true because Echo inherits from Foxtrot which in turn inherits from Golf.

// According to the Liskov’s Substitution Principle, substitution only works when you substitute a derived class for a base class. 
// Golf is a base class to Echo, so the substitution does not work.


//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 3/5 (4 exercise)

// Multilevel Inheritance with Attributes

// Assume following code:
class Human {
  public:
    Human(string n) {
      name = n;
    }

  private:
    string name;
};

class Adult : public Human {
  public:
    Adult(string n, int c) : Human(n) {
      num_children = c;
    }

  private:
    int num_children;
};

class Parent : public Adult {
  public:
    Parent(string n, int c) : Adult(n, c) {}
};

// The Parent class should have the name and num_children attributes. To do that, inherit from Adult which then inherits from Human.
// The constructor uses the variable n, so the parameter should be string n, not string name.
// The constructor has the parameter c, so the variable should be c, not num_children.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 4/5 (1 exercise lab)

// Lab 1 - Making the Base Class and Derived Class
// In this lab, we will be creating a base class called Line. 
// Line has only one attribute, int length, which is used in the class function DrawLine. 
// DrawLine takes an integer parameter and outputs * as many times as specified in length. 
// To retrieve length, we also have the getter function GetLength. 
// Line does not have a setter function.

#include <iostream>
using namespace std;

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

//add class definitions below this line

class Line {
  public:
    Line(int l) {
      length = l;
    }
  
    int GetLength() {
      return length;
    }
  
    void DrawLine() {
      for (int i = 0; i < length; i++) {
        cout << '*';
      }
      cout << endl;
    }
  
  private:
    int length;
};

//add class definitions above this line

// To test our Line class, create its object and then call the DrawLine function on it in main.

  //add code below this line

  Line line(10);
  line.DrawLine();

  //add code above this line

// The output is a line drawn with 10 * symbols. Next, we will create a derived class, Box, that inherits from Line.
// Box has one attribute, int width, which will present the width of the Box object.
// The Box constructor takes two parameters, one of which is presented by width and the other is presented by length which is inherited from the Line constructor. 
// Box has two class functions, the getter GetWidth and DrawBox. 
// Notice how inheritance enables us to borrow functions and attributes from the base class to further extend the derived class.
// DrawBox utilizes the width attribute to tell the system how many times to call DrawLine. 
// The end result is a draw of a “box” that is created from multiple "lines".

//add class definitions below this line

class Line {
  public:
    Line(int l) {
      length = l;
    }
  
    int GetLength() {
      return length;
    }
  
    void DrawLine() {
      for (int i = 0; i < length; i++) {
        cout << '*';
      }
      cout << endl;
    }
  
  private:
    int length;
};

class Box : public Line {
  public:
    Box(int l, int w) : Line(l) {
      width = w;
    }
  
    int GetWidth() {
      return width;
    }
  
    void DrawBox() {
      for (int i = 0; i < width; i++) {
        DrawLine();
      }
    }
  
  private:
    int width;
};

//add class definitions above this line

  //add code below this line

  Box box(10, 10);
  box.DrawBox();

  //add code above this line


// sub exercise
// Select all of the following statements that are false regarding inheritance.

// a) The derived class can access the member functions and attributes of the base class if they are protected or public.
// b) You must declare the same exact attributes in the derived class as the ones in the base class.
// c) The base class can access the member functions and attributes of the derived class as long as they are not private.
// d) The base class can access the member functions and attributes of the derived class only if they are protected.

// Guide:
// The base class can access the member functions and attributes of the derived class as long as they are not private.

// False - Inheritance is a one-way street. Only the derived class can access certain members of base class, never the other way around.
// The base class can access the member functions and attributes of the derived class only if they are protected.

// False - Again, base classes do not have access to derived classes.
// You must declare the same exact attributes in the derived class as the ones in the base class.

// False - This is not a requirement. Though a derived class cannot access private members of the base class directly, they can usually do so through public getter functions.
// The derived class can access the member functions and attributes of the base class if they are protected or public.

// True - A derived class can access all members of a base class as long as they are not private.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 4/5 (2 exercise lab)

// Lab 2 - Applying Multilevel Inheritance
// Previously in Lab 1, we created the base class Line and the derived class Box. 
// In this lab, we will create another derived class that inherits from Box directly and Line indirectly.
// This concept of a derived class inheriting from another derived class is called multilevel inheritance.

#include <iostream>
using namespace std;

//add class definitions below this line

class Line {
  public:
    Line(int l) {
      length = l;
    }
  
    int GetLength() {
      return length;
    }
  
    void DrawLine() {
      for (int i = 0; i < length; i++) {
        cout << '*';
      }
      cout << endl;
    }
  
  private:
    int length;
};

class Box : public Line {
  public:
    Box(int l, int w) : Line(l) {
      width = w;
    }
  
    int GetWidth() {
      return width;
    }
  
    void DrawBox() {
      for (int i = 0; i < width; i++) {
        DrawLine();
      }
    }
  
  private:
    int width;
};

//add class definitions above this line

int main() {
  
  //add code below this line



  //add code above this line
  
  return 0;
  
}

// Our new derived class is called Pattern. 
// This class builds off of Box and Line by utilizing their getter functions GetLength and GetWidth. 
// First we need to build the Pattern constructor which inherits the Box constructor exactly. 
// Then we will create a new function called DrawPattern that will output a modified “box” with a pattern. 
// Note that Pattern does not have any private members. 
// It is simply an extension of the Box class.

//add class definitions below this line

class Line {
  public:
    Line(int l) {
      length = l;
    }
  
    int GetLength() {
      return length;
    }
  
    void DrawLine() {
      for (int i = 0; i < length; i++) {
        cout << '*';
      }
      cout << endl;
    }
  
  private:
    int length;
};

class Box : public Line {
  public:
    Box(int l, int w) : Line(l) {
      width = w;
    }
  
    int GetWidth() {
      return width;
    }
  
    void DrawBox() {
      for (int i = 0; i < width; i++) {
        DrawLine();
      }
    }
  
  private:
    int width;
};

class Pattern : public Box {
  public:
    Pattern(int l, int w) : Box(l, w) {} 
  
    void DrawPattern() {
      for (int i = 0; i < GetLength(); i++) {
        if (i % 2 == 0) {
          for (int j = 0; j < GetWidth(); j++) {
            if ( (j % 2 == 0) ) {
              cout << '*';
            }
            else {
              cout << ' ';
            }
          }
          cout << endl;
        }
        if (i % 2 == 1) {
          for (int j = 0; j < GetWidth(); j++) {
            if ( (j % 2 == 0) ) {
              cout << ' ';
            }
            else {
              cout << '*';
            }
          }
          cout << endl;
        }
      }
    }
};

//add class definitions above this line

// Rather than create a “box” of "lines", a “pattern” is created by specifying certain indices to output * while others output a white space (' '). In particular, this is the pattern (note the pattern starts at index 0 for both rows and columns):
// even row + even column = *
// even row + odd column = ' '
// odd row +even column = ' '
// odd row + odd column = *

// Try the following code in main to see the output.
  //add code below this line

  Pattern pattern(10, 10);
  pattern.DrawPattern();

  //add code above this line


// sub exercise 

// Adopting Multilevel Inheritance
// Given the following code:

class ClassA {
  public:
    void PrintA() {
      cout << "Class A" << endl;
    }
};

class ClassB : public ClassA {
  public:
    void PrintB() {
      cout << "Class B" << endl;
    }
};

class ClassC : public ClassB {
  public:
    void PrintC() {
      cout << "Class C" << endl;
    }
};

int main() {

  ClassA a;
  ClassB b;
  ClassC c;

  return 0;
}

// Determine the output of each of the following commands.

a.PrintA(); // prints: Class A
a.PrintB(); // prints: an error
a.PrintC(); // prints: an error
b.PrintA(); // prints: Class A
b.PrintB(); // prints: Class B
b.PrintC(); // prints: an error
c.PrintA(); // prints: Class A
c.PrintB(); // prints: Class B
c.PrintC(); // prints: Class C

// Recall that objects can only call on functions within their own class or from a class in which they inherit. 
// For example, ClassB inherits from ClassA, so a ClassB object can call on functions from ClassB or from ClassA, but NOT from ClassC. See solution below.

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 4/5 (3 exercise lab)

// Problem
// In the IDE to the left, the class MP3 is already defined. Complete the class Podcast that inherits from MP3. This class should do the following things:
// Inherit the constructor such that Podcast has the following attributes:
// title - a string that is the title of the episode
// length - an integer that has the length of the podcast in seconds
// genre - a string that is the genre of the podcast
// name - a string that is the name of the podcast
// date - a string that represents when the podcast was released to the public

#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class MP3 {
  public: 
    MP3(string t, int l, string g, string al, string ar) {
      title = t;
      album = al;
      length = l;
      genre = g;
      artist = ar;
    }

    string GetTitle() {
      return title;
    }

    void SetTitle(string new_title) {
      title = new_title;
    }

    int GetLength() {
      return length;
    }

    void SetLength(int new_length) {
      length = new_length;
    }

    string GetGenre() {
      return genre;
    }

    void SetGenre(string new_genre) {
      genre = new_genre;
    }

    string GetAlbum() {
      return album;
    }

    void SetAlbum(string new_album) {
      album = new_album;
    }
  
    string GetArtist() {
      return artist;
    }

    void SetArtist(string new_artist) {
      artist = new_artist;
    }
  
  private:
    string title;
    int length;
    string genre;
    string album;
    string artist;
};

//DO NOT EDIT code above this line
  
//add class definitions below this line
  
//DO NOT EDIT///////////////////
class Podcast : public MP3 {  //
////////////////////////////////

  
  
  
  
//add class definitions above this line 

int main() {
  
  //DO NOT EDIT code below this line

  Podcast p("Hollywood Black List", 1460, "economics", "Planet Money", "10 July 2020");
  p.DisplayTitle();
  p.DisplayLength();
  p.DisplayGenre();
  p.DisplayName();
  p.DisplayDate();

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Hint: Connecting the Constructors
// Note that a few of the attributes are present in both the MP3 and Podcast classes. To connect their constructors, you can use the same parameter values for the attributes that are the same, then use different parameter values for the attributes that are different. Finally, set the attributes to the parameters appropriately for the ones that are different. For example:
Podcast(string t, int l, string g, string n, string d) : MP3(t, l, g, n, d) {
  name = n;
  date = d;
}

// Expected Output
// The title is Hollywood Black List
// The length is 1460
// The genre is economics
// The name is Planet Money
// The date is 10 July 2020

// Connect the constructors using Podcast(string t, int l, string g, string n, string d) : MP3(t, l, g, n, d)
// Only two attributes are required, string name and string date
// Utilize the GetTitle(), GetLength(), and GetGenre() functions to access the base class attributes
// All of the functions should be void because they all print to the screen

// Sample Solution:

//DO NOT EDIT///////////////////
class Podcast : public MP3 {  //
////////////////////////////////
  public:
    Podcast(string t, int l, string g, string n, string d) : MP3(t, l, g, n, d) {
      name = n;
      date = d;
    }
  
    void DisplayTitle() {
      cout << "The title is " << GetTitle() << endl;
    }
  
    void DisplayLength() {
      cout << "The length is " << GetLength() << endl;
    }
  
    void DisplayGenre() {
      cout << "The genre is " << GetGenre() << endl;
    }
  
    void DisplayName() {
      cout << "The name is " << name << endl;
    }
  
    void DisplayDate() {
      cout << "The date is " << date << endl;
    }
  
  private:
    string name;
    string date;
};

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 5/5 (1 exercise)

// Exercise 1
// Use the CelestialBody class to the left as the base class. 
// Create the Satellite and Planet classes, both of which are derived classes of CelestialBody. 
// The Satellite class has the attribute string host_planet while the Planet class has the attribute string host_star.

#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class CelestialBody {
  public:
    CelestialBody(double s, double m, string c, string n) {
      size = s;
      mass = m;
      atm_composition = c;
      name = n;
    }

    double GetSize() {
      return size;
    }

    double GetMass() {
      return mass;
    }

    string GetComposition() {
      return atm_composition;
    }

    string GetName() {
      return name;
    }
  
  private:
    double size;
    double mass;
    string atm_composition;
    string name;
};

//DO NOT EDIT code above this line

//add class definitions below this line

//DO NOT EDIT//////////////////////////////
class Satellite : public CelestialBody { //
///////////////////////////////////////////

  
  
  

//DO NOT EDIT///////////////////////////
class Planet : public CelestialBody { //
////////////////////////////////////////

  
  
  

//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  Satellite s(2651, 3716, "helium", "Moon", "Earth");
  Planet p(5349, 8910, "nitrogen", "Earth", "Sun");
  Satellite s2(3199, 13452, "nitrogen", "Titan", "Saturn");
  Planet p2(82713, 56834, "hydrogen", "Saturn", "Sun");
  cout << "Satellite name = " << s.GetName() << ", size = " << s.GetSize();
  cout << ", mass = " << s.GetMass() << ", atmospheric composition = " << s.GetComposition();
  cout << ", host planet = " << s.GetHostPlanet() << endl;
  cout << "Planet name = " << p.GetName() << ", size = " << p.GetSize();
  cout << ", mass = " << p.GetMass() << ", atmospheric composition = " << p.GetComposition();
  cout << ", host star = " << p.GetHostStar() << endl;
  cout << "Satellite name = " << s2.GetName() << ", size = " << s2.GetSize();
  cout << ", mass = " << s2.GetMass() << ", atmospheric composition = " << s2.GetComposition();
  cout << ", host planet = " << s2.GetHostPlanet() << endl;
  cout << "Planet name = " << p2.GetName() << ", size = " << p2.GetSize();
  cout << ", mass = " << p2.GetMass() << ", atmospheric composition = " << p2.GetComposition();
  cout << ", host star = " << p2.GetHostStar() << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Requirements
// Produce the expected output using concepts of inheritance.

// Expected Output
// Satellite name = Moon, size = 2651, mass = 3716, atmospheric composition = helium, host planet = Earth
// Planet name = Earth, size = 5349, mass = 8910, atmospheric composition = nitrogen, host star = Sun
// Satellite name = Titan, size = 3199, mass = 13452, atmospheric composition = nitrogen, host planet = Saturn
// Planet name = Saturn, size = 82713, mass = 56834, atmospheric composition

// Both constructors of Satellite and Planet should be linked to the base constructor (i.e. CelestialBody(s, m, c, n))
// Both classes should include their appropriate getter functions
// The setter functions are included but are not required to receive full credit
// Satellite has host_planet as a private string while Planet has host_star

//DO NOT EDIT//////////////////////////////
class Satellite : public CelestialBody { //
///////////////////////////////////////////
  public: 
    Satellite(double s, double m, string c, string n, string hp) : CelestialBody(s, m, c, n) {
      host_planet = hp;
    }

    string GetHostPlanet() {
      return host_planet;
    }

    void SetHostPlanet(string new_host_planet) {
      host_planet = new_host_planet;
    }
  
  private: 
    string host_planet;
};

//DO NOT EDIT///////////////////////////
class Planet : public CelestialBody { //
////////////////////////////////////////
  public: 
    Planet(double s, double m, string c, string n, string hs) : CelestialBody(s, m, c, n) {
      host_star = hs;
    }

    string GetHostStar() {
      return host_star;
    }

    void SetHostStar(string new_host_star) {
      host_star = new_host_star;
    }
  
  private: 
    string host_star;
};

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 5/5 (2 exercise)

// Exercise 2
// Use the Book class to the left as the base class. Create the derived class BlogPost so that it has the following attributes:
// title - a string that represents the title of the blog post
// author - a string that represents the author of the blog post
// genre - a string that represents the genre of the blog post
// website - a string that represents the website hosting the blog post
// word_count - an integer that represents the number of words in the blog post
// page_views - an integer that represents the page views for the blog post

#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class Book {
  public:
    Book(string t, string a, string g) {
      title = t;
      author = a;
      genre = g;
    }

    string GetTitle() {
      return title;
    }

    void SetTitle(string new_title) {
      title = new_title;
    }

    string GetAuthor() {
      return author;
    }

    void SetAuthor(string new_author) {
      author = new_author;
    }

    string GetGenre() {
      return genre;
    }
  
    void SetGenre(string new_genre) {
      genre = new_genre;
    }
  
  private: 
    string title;
    string author;
    string genre;
};

//DO NOT EDIT code above this line

//add class definitions below this line

//DO NOT EDIT////////////////////
class BlogPost : public Book { //
/////////////////////////////////

  
  

  
//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  BlogPost my_post("Hot Summer Trends", "Amy Gutierrez", "fashion", "Vogue", 2319, 2748);
  cout << my_post.GetTitle() << endl;
  cout << my_post.GetAuthor() << endl;
  cout << my_post.GetGenre() << endl;
  cout << my_post.GetWebsite() << endl;
  cout << my_post.GetWordCount() << endl;
  cout << my_post.GetPageViews() << endl;
  BlogPost codio("Adopting Codio", "Anh Le", "computer science", "Codio", 2500, 5678);
  cout << codio.GetTitle() << endl;
  cout << codio.GetAuthor() << endl;
  cout << codio.GetGenre() << endl;
  cout << codio.GetWebsite() << endl;
  cout << codio.GetWordCount() << endl;
  cout << codio.GetPageViews() << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Expected Output
// Hot Summer Trends
// Amy Gutierrez
// fashion
// Vogue
// 2319
// 2748
// Adopting Codio
// Anh Le
// computer science
// Codio
// 2500
// 5678

// Connect the base and derived constructors using BlogPost(string t, string a, string g, string w, int wc, int pv) : Book(t, a, g)
// There are three additional attributes in BlogPost - string website, int word_count, and int page_views
// Note that title, author, and genre do not have to be created again
// Create the appropriate getter functions for BlogPost
// Optionally create the appropriate setter functions for BlogPost

//DO NOT EDIT////////////////////
class BlogPost : public Book { //
/////////////////////////////////
  public:
    BlogPost(string t, string a, string g, string w, int wc, int pv) : Book(t, a, g) {
      website = w;
      word_count = wc;
      page_views = pv;
    }
  
    string GetWebsite() {
      return website;
    }

    void SetWebsite(string new_website) {
      website = new_website;
    }

    int GetWordCount() {
      return word_count;
    }

    void SetWordCount(int new_word_count) {
      word_count = new_word_count;
    }

    int GetPageViews() {
      return page_views;
    }

    void SetPageViews(int new_page_views) {
      page_views = new_page_views;
    }

  private:
    string website;
    int word_count;
    int page_views;
};


//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 5/5 (3 exercise)

// Exercise 3
// Create the class Child such that the following criteria are met:
// Child is a derived class of Parent2 which is a derived class of Parent1
// Override Identify in Child so that it returns This function is called from Child
// Create the function Identify2 that invokes the Identify function from Parent2 by using the scope resolution operator (Parent2::Identify())
// Create the function Identify3 that invokes the Identify function from Parent1 by using the scope resolution operator (Parent1::Identify())

#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class Parent1 {
  public:
    string Identify() {
      return "This function is called from Parent1";
    }
};

class Parent2 : public Parent1 {
  public:
    string Identify() {
      return "This function is called from Parent2";
    }
};

//DO NOT EDIT code above this line

//add class definitions below this line



//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  Child c;
  cout << c.Identify() << endl;
  cout << c.Identify2() << endl;
  cout << c.Identify3() << endl;
  
  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Expected Output
// This function is called from Child
// This function is called from Parent2
// This function is called from Parent1

class Child : public Parent2 {
  public:
    string Identify() {
      return "This function is called from Child";
    }
  
    string Identify2() {
      return Parent2::Identify();
    }
  
    string Identify3() {
      return Parent1::Identify();
    }
};

// Create the class Child that inherits from Parent2
// All of the Child class functions are string because they each return one
// Use the scope resolution operator Parent2::Identify() to access Identify() in the Parent2 class
// Use the scope resolution operator Parent1::Identify() to access Identify() in the Parent1 class

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 5/5 (4 exercise)

// Exercise 4
// Use the base class PiggyBank to help you solve this exercise. Create the derived class Cash so that it has the following functions:
// DisplayBills - function that prints all of the dollar bills’ quantity in order of increasing amount
// DisplayCashTotal - function that prints the value of all of the dollar bills combined

#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class PiggyBank {
  public:
    PiggyBank(int o, int f, int tn, int tw) {
      ones = o;
      fives = f;
      tens = tn;
      twenties = tw;
    }
  
    int GetOnes() {
      return ones;
    }
  
    void SetOnes(int new_ones) {
      ones = new_ones;
    }
  
    int GetFives() {
      return fives;
    }
  
    void SetFives(int new_fives) {
      fives = new_fives;
    }
  
    int GetTens() {
      return tens;
    }
  
    void SetTens(int new_tens) {
      tens = new_tens;
    }
  
    int GetTwenties() {
      return twenties;
    }
  
    void SetTwenties(int new_twenties) {
      twenties = new_twenties;
    }
  
  private:
    int ones;
    int fives;
    int tens;
    int twenties;
};

//DO NOT EDIT code above this line

//add class definitions below this line

//DO NOT EDIT/////////////////////
class Cash : public PiggyBank { //
//////////////////////////////////

  
  
  
  
//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  Cash c(1, 2, 3, 4);
  c.DisplayBills();
  c.DisplayCashTotal();
  Cash c2(9, 8, 7, 6);
  c2.DisplayBills();
  c2.DisplayCashTotal();

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Expected Output
// One-dollar bill: 1
// Five-dollar bill: 2
// Ten-dollar bill: 3
// Twenty-dollar bill: 4
// Total amount: 121
// One-dollar bill: 9
// Five-dollar bill: 8
// Ten-dollar bill: 7
// Twenty-dollar bill: 6
// Total amount: 239

//DO NOT EDIT/////////////////////
class Cash : public PiggyBank { //
//////////////////////////////////
  public:
    Cash(int o, int f, int tn, int tw) : PiggyBank(o, f, tn, tw) {}
  
    void DisplayBills() {
      cout << "One-dollar bill: " << GetOnes() << endl;
      cout << "Five-dollar bill: " << GetFives() << endl;
      cout << "Ten-dollar bill: " << GetTens() << endl;
      cout << "Twenty-dollar bill: " << GetTwenties() << endl;
    }
  
    void DisplayCashTotal() {
      cout << "Total amount: "; 
      cout << GetOnes() + GetFives() * 5 + GetTens() * 10 + GetTwenties() * 20;
      cout << endl;
    }
};

// Connect the derived and base constructors using Cash(int o, int f, int tn, int tw) : PiggyBank(o, f, tn, tw) {}
// DisplayBills and DisplayCashTotal should be void functions since they do not return a data type
// DisplayBills uses getters from the PiggyBank class to print the bills’ quantity
// DisplayCashTotal multiplies each dollar bill quantity by its value, then adds the individual totals to print the grand total amount

//-----------------------------------------------------------------------------------------------------------//
// file 2222, week 2 5/5 (5 exercise)

// Exercise 5
// Use the Person class to the left to help you solve this exercise. First, complete the derived classes CardHolder that inherits from Person so that it includes the following:
// Getters and setters for account_number, balance, and credit_limit
// Sale - function that takes a sale price (double) as a parameter and adds it to balance
// Payment - function that takes an amount (double) and subtracts it from balance
// Next, complete the PlatinumClient class that inherits from CardHolder. It should have the following:
// Getters and setters for cash_back and rewards
// Sale - overrides the Sale function in CardHolder by:
// Taking price (double) as a parameter
// Multiplies price by cash_back and add that value to rewards
// Calls SetBalance so that balance is increased by price

#include <iostream>
using namespace std;

//DO NOT EDIT code below this line

class Person {
  public:
    Person(string n, string a) {
      name = n;
      address = a;
    }
  
    string GetName() {
      return name;
    }

    void SetName(string new_name) {
      name = new_name;
    }

    string GetAddress() {
      return address;
    }

    void SetAddress(string new_address) {
      address = new_address;
    }

    string Info() {
      return name + " lives at " + address + ".\n";
    }
  
  private:
    string name;
    string address;
};

//DO NOT EDIT code above this line

//add class definitions below this line

//DO NOT EDIT/////////////////////////////////////////////////
class CardHolder : public Person {                          //
  public:                                                   //
    CardHolder(string n, string a, int an) : Person(n, a) { //
      account_number = an;                                  //
      balance = 0;                                          //
      credit_limit = 5000;                                  //
    }                                                       //
//////////////////////////////////////////////////////////////
  


  
  
//DO NOT EDIT/////////////////////////////////////////////////////////////
class PlatinumClient : public CardHolder {                              //
  public:                                                               //
    PlatinumClient(string n, string a, int an) : CardHolder(n, a, an) { //
      cash_back = 0.02;                                                 //
      rewards = 0;                                                      //
    }                                                                   //
//////////////////////////////////////////////////////////////////////////


  
  
  
//add class definitions above this line

int main() {
  
  //DO NOT EDIT code below this line

  PlatinumClient pc("Sarah", "101 Main Street", 123364);
  pc.CardHolder::Sale(100);
  cout << pc.GetRewards() << endl;
  pc.Sale(100);
  cout << pc.GetRewards() << endl;
  cout << pc.GetBalance() << endl;
  pc.Payment(50);
  cout << pc.GetBalance() << endl;
  cout << pc.Info() << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}

// Expected Output
// 0
// 2
// 200
// 150
// Sarah lives at 101 Main Street.

// CardHolder class:
// Create the appropriate getters and setters
// Sale and Payment should be void functions that each takes a double parameter
// Sale adds the parameter to balance
// Payment subtracts the parameter from balance
// PlatinumClient class
// Create the appropriate getters and setters
// Sale should be a void function that takes a double parameter
// The parameter is multiplied by cash_back and the value is added to rewards
// SetBalance is called to modify balance by adding the parameter to it

//DO NOT EDIT/////////////////////////////////////////////////
class CardHolder : public Person {                          //
  public:                                                   //
    CardHolder(string n, string a, int an) : Person(n, a) { //
      account_number = an;                                  //
      balance = 0;                                          //
      credit_limit = 5000;                                  //
    }                                                       //
//////////////////////////////////////////////////////////////
  
    int GetAccountNumber() {
      return account_number;
    }

    void SetAccountNumber(int new_account_number) {
      account_number = new_account_number;
    }

    double GetBalance() {
      return balance;
    }

    void SetBalance(double new_balance) {
      balance = new_balance;
    }

    int GetCreditLimit() {
      return credit_limit;
    }

    void SetCreditLimit(int new_credit_limit) {
      credit_limit = new_credit_limit;
    }

    void Sale(double price) {
      balance += price;
    }

    void Payment(double amount) {
      balance -= amount;
    }
  
  private:
    int account_number;
    double balance;
    int credit_limit;
};

//DO NOT EDIT/////////////////////////////////////////////////////////////
class PlatinumClient : public CardHolder {                              //
  public:                                                               //
    PlatinumClient(string n, string a, int an) : CardHolder(n, a, an) { //
      cash_back = 0.02;                                                 //
      rewards = 0;                                                      //
    }                                                                   //
//////////////////////////////////////////////////////////////////////////

    double GetCashBack() {
      return cash_back;
    }

    void SetCashBack(double new_cash_back) {
      cash_back = new_cash_back;
    }

    double GetRewards() {
      return rewards;
    }

    void SetRewards(double new_rewards) {
      rewards = new_rewards;
    }

    void Sale(double price) {
      rewards += cash_back * price;
      SetBalance(GetBalance() + price);
    }
  
  private:
    double cash_back;
    double rewards;
};