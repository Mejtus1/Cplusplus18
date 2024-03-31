// What is Encapsulation?

// - encapsulation is concept in which related data and methods are grouped together, and in which access to data is restricted
// - grouping related data and functions makes thinking about your program bit easier
// - hiding or restricting how user interacts with data can keep user from making unwanted changes

// - two main ideas of data restriction are public and private keywords
// - these access modifiers (or keywords) can refer to classes, functions, and attributes
// public means that constructor, function, or attribute can be accessed both internally or externally
// private means that the constructor, attribute, or function can only be accessed internally within class itself

// Classes as Encapsulation
// - classes in C++ are form of encapsulation; they group together related data and functions
// - in code below, attributes num1 and num2 are grouped together with functions Describe and Sum
// - they are all part of ExampleClass
// - instance my_example is not part of the class itself; it is considered to be separate


#include <iostream>
using namespace std;

//add class definitions below this line

class ExampleClass {
    void SetN(int n1, int n2) {
      num1 = n1;
      num2 = n2;
    }
  
    void Describe() {
      cout << "My numbers are: " << num1 << " and " << num2 << endl;
    }
  
    int Sum() {
      return num1 + num2;
    }
  
    int num1;
    int num2;
};

//add class definitions above this line


int main() {
  
  //add code below this line
  
  ExampleClass my_example;
  my_example.SetN(5, 7);
  my_example.Describe();
  cout << my_example.Sum() << endl;

  //add code above this line
  
  return 0;
  
}

// code above results in an error, but we’ll find out why next

// Hiding Data
// - you’ve learned in Mutability chapter that class functions are typically public and attributes are typically private 
// - public access modifier enables other classes to have access to those functions
// - on other hand, private access modifier disables access to attributes to prevent users from imposing unwanted changes
// - moving forward, we’ll abide by access modifier rules within chart below

// Category	    Public	Private
// Constructor	  X	
// Functions	  X	      X
// Attributes		      X

// Why are functions both public and private?
// - in pages that follow, you will see when making functions public is good idea, and when keeping functions private is preferable 
// - well designed program will use mix of public and private functions
// - Previously, we've learned that helper functions can be kept private since they are not directly accessed externally

// - same ExampleClass from above
// - It now use public and private access modifiers to hide data or to make them accessible

#include <iostream>
using namespace std;

//add class definitions below this line

class ExampleClass {
  public:
    void SetN(int n1, int n2) {
      num1 = n1;
      num2 = n2;
    }
  
    void Describe() {
      cout << "My numbers are: " << num1 << " and " << num2 << endl;
    }
  
    int Sum() {
      return num1 + num2;
    }
  
  private:
    int num1;
    int num2;
};

//add class definitions above this line


int main() {
  
  //add code below this line
  
  ExampleClass my_example;
  my_example.SetN(5, 7);
  my_example.Describe();
  cout << my_example.Sum() << endl;

  //add code above this line
  
  return 0;
  
}
// My numbers are: 5 and 7
// 12

// - when no access modifier is specified within class, that attribute, function, or constructor is automatically declared as private by default
// - to make them public, you must specify public in code

// - code should run fine now because instance or object is only interacting with public information
// - try to print values for num1 and num2 attributes

  //add code below this line
  
  ExampleClass my_example;
  my_example.SetN(5, 7);
  cout << my_example.num1 << endl;
  cout << my_example.num2 << endl;

  //add code above this line

// error 

// - C++ produces error message because instance cannot directly access private attribute
// - example of hiding data 
// - my_example cannot print num1 or num2 because they are private
// - my_example can access public methods, which can then access private attributes

// exercise 
// What Is Encapsulation ? 
// - encapsulation occurs when you group together related data and functions, and when you hide or restrict access to data

//---------------------------------------------------------------------------------------------------//
// Public Attributes
// - while C++ allows you to make instance attributes public, this is not encouraged
// - in fact, encapsulation asks that all attributes remain private
// - C++ itself, however, allows for public attributes
// - following class has three attributes and all of them are public
// - instantiate Phone object and manipulate different attributes

#include <iostream>
using namespace std;

//add class definitions below this line
    
class Phone {
  public:
    Phone(string mo, int st, int me) {
      model = mo;
      storage = st;
      megapixels = me;
    }
  
    string model;
    int storage;
    int megapixels;
};

//add class definitions above this line


int main() {
  
  //add code below this line
  
  Phone my_phone("iPhone", 256, 12);
  cout << my_phone.model << endl;
  my_phone.storage = 64;
  cout << my_phone.storage << endl;
  cout << my_phone.megapixels + 10 << endl;

  //add code above this line
  
  return 0;
  
}

// - when attribute is public, user can do whatever they want to it
// - this can become problematic
// - in code above, phone’s storage was reduced by 75%
// - this should not happen
// - encapsulation limits what and how information is modified
// - by hiding data, you can ensure that users only manipulate class in approved manner

//-----------------
// Public Functions
// - since all attributes should be private, we will use this access modifier for following code sample
// - unlike attributes, you are encouraged to have public functions
// - if all of your functions are private, it would be impossible to interact with object
// - constructor is special kind of function, and this too should be public
// - real benefit of public function is that it can access private attributes
// - public functions are gateway to dealing with private data
// - create public function Describe that prints description of Phone object

#include <iostream>
using namespace std;

//add class definitions below this line
    
class Phone {
  public:
    Phone(string mo, int st, int me) {
      model = mo;
      storage = st;
      megapixels = me;
    }
  
    void Describe() {
      cout << "My " << storage << " gig " << model;
      cout << " has a " << megapixels << " megapixels camera." << endl;
    }
  
  private:
    string model;
    int storage;
    int megapixels;
};

//add class definitions above this line

// - instantiate Phone object and call describe method

int main() {
  
  //add code below this line
  
  Phone my_phone("iPhone", 256, 12);
  my_phone.Describe();

  //add code above this line
  
  return 0;
  
}
// My 256 gig iPhone has 12 megapixels camera

// Try this variation
// - change access modifier from public to private
// - why does this not work?
// - constructor is special kind of function that is called when object is created
// - once constructor is private, it cannot be called outside class
// - That is why C++ throws error message, only way private constructor can work is if class is declared inside another class
// - outer class can call the inner constructor even if it is private

//------------------------
// Private Access Modifier
// - as discussed on previous page, we will be making all attributes private
// - instance attributes, static attributes, constants — it does not matter, they will all be private

// Private Functions
// - functions too, can be private
// - just like private attributes, private functions are accessed by public functions

#include <iostream>
using namespace std;

//add class definitions below this line

class PrivateExample {
  public:
    PrivateExample(int n) {
      num = n;
    }
  
    void PublicFunction() {
      PrivateFunction();
    }
  
  private:
    int num;
  
    void PrivateFunction() {
      cout << "The double of " << num << " is: " << num * 2 << endl;
      cout << num << " squared is: " << num * num << endl;
    }
};

//add class definitions above this line


int main() {
  
  //add code below this line
  
  PrivateExample my_example(5);
  my_example.PrivateFunction();

  //add code above this line
  
  return 0;
  
}
// error 

// - C++ throws error message because instance cannot directly access private function
// - change function call to PublicMethod and run code again
// - this time it should work because public functions can access private functions and/or attributes

  //add code below this line
  
  PrivateExample my_example(5);
  my_example.PublicFunction();

  //add code above this line

//---------------------------
// Public and Private Methods
// - well written C++ program will make use of both public and private functions
// - deciding what to make public and what to make private comes down to how you want user to interact with your code 
// - only make public those functions you want the user to call
// - keep everything else private
// - example below is class that counts number of vowels in strings
// - first let’s add private functions and attributes
// - IsVowel and CountVowels functions will serve as helper functions in later function
// - this is why they do not need to be accessed directly by user and should be private

//add class definitions below this line

class Words {
  private:
    string word;
    int count;
  
    bool IsVowel(char ch) {
      ch = toupper(ch);
      return (ch=='A' || ch=='E' || ch=='I' ||
              ch=='O' || ch=='U');
    }
  
    int CountVowels(string str, int n) {
      if (n == 1) {
        return IsVowel(str[n-1]);
      }
      return CountVowels(str, n-1) + IsVowel(str[n-1]);
    }
};

//add class definitions above this line

// - next, add public components such as constructor Words
// - constructor instantiates object with word and count attributes
// - other public component is Printer function, which calls IsVowel and CountVowels functions
// - without this public Printer function, IsVowel and CountVowels will be completely inaccessible

#include <iostream>
using namespace std;

//add class definitions below this line

class Words {
  public:
    Words(string str, int n) {
      word = str;
      count = n;
    }

    void Printer() {
      cout << "The number of vowels in " << word;
      cout << " is " << CountVowels(word, count) << endl;
    }

  private:
    string word;
    int count;
  
    bool IsVowel(char ch) {
      ch = toupper(ch);
      return (ch=='A' || ch=='E' || ch=='I' ||
              ch=='O' || ch=='U');
    }
  
    int CountVowels(string str, int n) {
      if (n == 1) {
        return IsVowel(str[n-1]);
      }
      return CountVowels(str, n-1) + IsVowel(str[n-1]);
    }
};

// - finally, instantiate string to use as argument and Words object in order to run function Printer and see program output

int main() {
  
  //add code below this line
  
  string s = "house";
  Words vowels(s, s.length());
  vowels.Printer();

  //add code above this line
  
  return 0;
  
}

// exercise 
// True Statements
// The statement All attributes should be private is true because encapsulation dictates that access to attributes should be restricted.
// The statement Some functions should be private while others should be public is true because encapsulation says to restrict user access with private functions. However, if all functions are private then the user can not call them. Therefore, you need a mix of private and public functions.
// False Statements
// The statement It is impossible to access private attributes and functions is false because public functions can invoke private attributes and private functions.
// The statement Functions called by the user should be private is false because functions called by the user need to be public.


//-----------
// Exercise 1 
// -  code does not make proper use of encapsulation. Why?
class Dog {
  private:
    Dog(string n, string b) {
      name = n;
      breed = b;
    }

    void Bark() {
     cout << "Woof! Woof!" << endl;
    }

    string name;
    string breed;
};

// Everything is private. There is no way to instantiate Dog object or call the Bark function.

//-------------------------
// Exercise 2 
// Encapsulation requires use of the public and private keywords. 
// Fill in the blanks so that the proper access modifier(s) correspond to different parts of a program.

// Constructors should be public. If not, you cannot instantiate an object.
// The convention in C++ is to always make instance attributes private.
// Some functions need to be public while others can be private. Only functions needed by the user should be public; the rest should be private.

