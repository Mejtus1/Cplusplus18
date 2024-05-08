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
