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

//---------------------------------------------------------------------------------------------------//
// Getters 
// - while all attributes are private, that does not mean that user will not need to access values of these attributes
// - public function can be used to access private attribute
// - this type of function has special name, getter (also called an accessor)
// - whole purpose of getter is to return attribute
// - these functions get their name because they always start with Get followed by attribute name

#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line
    
class Phone {
  public:
    Phone(string mo, int s, int me) {
      model = mo;
      storage = s;
      megapixels = me;
    }

    string GetModel() {
      return model;
    }
  
  private:
    string model;
    int storage;
    int megapixels;
};

//add class definitions above this line

// - function GetModel is example of getter
// - Getters are very simple, straightforward functions that do only one thing — return private attribute
// - getters can be treated just as you would treat attribute (except for changing its value)
// - to test getter, you can call in main to see if it returns what is expected

int main() {
  
  //add code below this line

  Phone my_phone("iPhone", 256, 12);
  cout << my_phone.GetModel() << endl;

  //add code above this line
  
  return 0;
  
}
// Iphone 

// Try this ! 
// - create getters for storage and megapixels attributes
// - then call them within main

//class definitions
public:
  int GetStorage() {
    return storage;
  }

  int GetMegapixels() {
    return megapixels;
  }

//main function
cout << my_phone.GetStorage() << endl;
cout << my_phone.GetMegapixels() << endl;

//----------------------
// Benefits of getters 
// - using getter is same thing as accessing public attribute
// - why not make the attribute public? That would mean writing less code
// - is that not good thing? A public attribute makes no distinction between accessing its value and changing its value
// - if you can access it, you can change it (or vice versa)
// - using getter with private attribute makes this distinction clear; you can access value, but you cannot change it

  //add code below this line

  Phone my_phone("iPhone", 256, 12);
  cout << my_phone.GetModel() << endl;
  my_phone.model = "Pixel 5";

  //add code above this line

// - code above generates error because instance cannot alter private attribute
// - using getter allows limited access to an attribute, which is preferable to the full access public accessmodifier allows

// Semi-exercise Getters 
// - drag code blocks into box below, create best getter function for language attribute
class Country {
  public:
    Country(string n, vector<string>& l) {
      name = n;
      languages = l;
    }

  private:
    string name;
    vector<string> languages;
};

// answer: 
public:
vector<string> GetLanguages() {
return languages;
}

// - Getter functions are accessible to user, so they need to have public access modifier
// vector<string> GetLanguages() is only function that has correct return type (string vector)
// - getter function should do only one thing, return value of attribute
// - printing should not be done by getter function

//---------
// Setters 
// - setters are compliment to getters in that they allow you to set value of private attribute
// - setter functions are also called mutators
// - use Phone class from previous page

//add class definitions below this line
    
class Phone {
  public:
    Phone(string mo, int s, int me) {
      model = mo;
      storage = s;
      megapixels = me;
    }

    string GetModel() {
      return model;
    }

    int GetStorage() {
      return storage;
    }

    int GetMegapixels() {
      return megapixels;
    }
  
  private:
    string model;
    int storage;
    int megapixels;
};
  
//add class definitions above this line

// - add SetModel method to Phone class
// - as this is setter method, start name with Set followed by name of attribute
// - setters do not return anything
// - finally, setters have parameter — new value for attribute

  public:
    // Setter
    void SetModel(string new_model) {
      model = new_model;
    }

Now that you are implementing both getters and setters, you should now be able to access and modify private attributes.

  //add code below this line

  Phone my_phone("iPhone", 256, 12); 
  cout << my_phone.GetModel() << endl;
  my_phone.SetModel("XR");
  cout << my_phone.GetModel() << endl;
  
  //add code above this line


// Try this ! 
// - create setters for storage and megapixels attributes, then call them within main
//class definitions
public:
  void SetStorage(int new_storage) {
    storage = new_storage;
  }

  void SetMegapixels(int new_megapixels) {
    megapixels = new_megapixels;
  }

//main function
my_phone.SetStorage(128);
cout << my_phone.GetStorage() << endl;
my_phone.SetMegapixels(6);
cout << my_phone.GetMegapixels() << endl;

//------------------------------
// Comparing Getters and Setters
// - 
// Category	             Getters	Setters
// Has public keyword	      X	       X
// Has private keyword	    -	       -
// Has return statement	    X	       -
// Has void type	          -	       X
// Performs only 1 task	    X	       X
// Has parameter	          -	       X

// Semi-Exercise
// Given following code:
class Country {
  public:
    Country(string n, vector<string>& l) {
      name = n;
      languages = l;
    }

  private:
    string name;
    vector<string> languages;
};

// answer: 
public:
void SetLanguages(vector<string>& new_languages) {
languages = new_languages;
}
// Setter functions do not return a value, so their type should be void.
// Setter functions update an attribute to a new value, so they require a parameter that represents this new value.
// Setter functions need to be public so they can be called by users of the class.

//----------------
// Data Validation
// - C++ already has type system which will flag errors when boolean value is passed to function that takes integer
// - however, just because function takes integer does not mean that all integers are valid for that function
// - data validation is process of asking if this data is appropriate for its intended use
// - take look at the Person class

//add class definitions below this line
    
class Person {
  public :
    Person(string n, int a) {
      name = n;
      age = a;
    }

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
  
  private: 
    string name;
    int age;
};
  
//add class definitions above this line

// - SetAge function will assign any value to attribute age as long as value is integer
// - there are some integers which make no sense when thought of as age attribute
// - code sample below sets age of my_person to -100. -100 is valid integer, but it is not valid age
// - this is why data validation is important
// - C++’s compiler is not sufficient to catch all errors

  //add code below this line

  Person my_person("Calvin", 6);
  cout << my_person.GetName() << " is " << my_person.GetAge() << " years old." << endl;
  my_person.SetAge(-100);
  cout << my_person.GetName() << " is " << my_person.GetAge() << " years old." << endl;

  //add code above this line

// - another benefit of using setters is that data validation can take place before new value is assignedto attribute
// - modify SetAge so that it will only update age attribute if new value is greater than or equal to 0
// - this way you can ensure that Person object always has valid age

  void SetAge(int new_age) {
    if (new_age >= 0) {
      age = new_age;
    }
  }

// Try these ! 
// - change data validation for SetAge function so that values over 200 or less than 0 are not valid
  void SetAge(int new_age) {
    if (new_age >= 0 && new_age <= 200) {
      age = new_age;
    }
  }

// - add data validation to SetName function so that all strings with one or more characters are valid
 void SetName(string new_name) {
    if (new_name != "") {
      name = new_name;
    }
  }

// Semi-Exercise 
// Data Validation
// Select all of the true statements about data validation.
// a) Data validation is important because the C++ compiler cannot find all errors
// b) Data validation is done in setter method

// Data validation is done in a setter method
// Data validation is important because the C++ compiler cannot find all errors

// - job of getter function is to return value of attribute
// - these functions should never update value of attribute, so data validation should not be done in getter function
// - C++ compiler will find certain kinds of errors like incorrect data types
// - however, compiler does not always understand context of code
// - data validation is process of making sure value is appropriate for its intended use

//-----------
// Exercise 1
// Getter and Setter Terms
// - fill in blanks below with correct terms

// A getter returns the value of a private instance variable.
// A setter changes the value of a private instance variable.

//-----------
// Exercise 2 
// Getters and Setters Die
// Given class DieRoll:

class DieRoll {
  public:
    int GetRoll() {
      return roll;
    }

  private:
    int roll = 0;
};

// - drag and rearrange code blocks below to create setter that validates if rolled number is between 1 and 6 inclusive
// - if it is, roll will be updated to number that is rolled
// - you MUST include AT LEAST ONE access modifier in your code

// answer: 
public:
  void SetRoll(int new_roll) {
    if (new_roll > 0 && new_roll <= 6) {
      roll = new_roll;
    }
  }
// Setter functions should be public so users can access them
// Setter functions should start with void and include parameter that will be passed to it
// if parameter or argument is between 0 and 6 inclusive, roll attribute will be updated to what was rolled

//---------------------------------------------------------------------------------------------------//
// Lab 1 
// Encapsulation Lab 1
// - this lab will focus on building on idea of “black box.”
// - term “black box” is used to describe system in which internal workings are hidden from user. 
// - user is not expected to know how system works; they only need to know how to use it 
// - encapsulation allows you to create classes that are black boxes

// - in this lab, we are going to create function that gives user ability to put in vector of strings and our program will print out number of vowels in each string within that vector

  //add code below this line

    vector<string> list = {"house", "cake", "pancake"};
    Words vowels(list);
    vowels.CoutStrings();

  //add code above this line

// - if you run code above successfully in main, you should expect to see 3,2,3 as output

// - in this scenario, we are going to modify our previous Words class so that it can include vector 
// - all of following code will go into class definitions field
class Words {
  private:
    vector<string> list_of_words;
};
// - we don’t need to reinvent wheel; we previously worked on few functions that told us how many vowels exist in specific string
// - we are going to again re-use those functions
// - these are functions that user does not need to interact with
// - thus, they can be private, essentially making them act as part of “black box” 

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

// - now that all of data that we don’t want user to manipulate are properly encapsulated as private, we can start working on our public members such as constructor Words and function CoutStrings
// - in example above, we can see our constructor takes in one attribute

public:
  Words(vector<string>& n){
    list_of_words = n;
  }

// - another piece of information that we have from main function is that function CoutStrings is used
// - this function has no arguments, but is accessible to user
// - this function also has several other tasks:
// 1. It iterates through a given vector
// 2. Counts the number of vowels in each given string
// 3. Creates a vector storing the vowel sizes
// 4. Prints out the output in a defined fashion

void CoutStrings() {
   vector<int> vowel_sizes;
   int size;
   for (auto a : list_of_words) {
     size = CountVowels(a, a.length());
     vowel_sizes.push_back(size);
   }
   for (int i = 0; i < vowel_sizes.size(); i++) {
     if (i == vowel_sizes.size()-1) {
       cout << vowel_sizes.at(i) << endl;
     }
     else {
       cout << vowel_sizes.at(i) << ',';
     }
   }
 }

// whole code: 
#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Words {
  public:
    Words(vector<string>& n){
      list_of_words = n;
    }
  
    void CoutStrings() {
       vector<int> vowel_sizes;
       int size;
       for (auto a : list_of_words) {
         size = CountVowels(a, a.length());
         vowel_sizes.push_back(size);
       }
       for (int i = 0; i < vowel_sizes.size(); i++) {
         if (i == vowel_sizes.size()-1) {
           cout << vowel_sizes.at(i) << endl;
         }
         else {
           cout << vowel_sizes.at(i) << ',';
         }
       }
     }
  
  private:
    vector<string> list_of_words;
  
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


int main() {
  
  //add code below this line
  
    vector<string> list = {"house", "cake", "pancake"};
    Words vowels(list);
    vowels.CoutStrings();

  //add code above this line
  
  return 0;
  
}
// 3,2,3

// Challenge
// - can you modify code so that it prints number of non-vowels instead of vowels? 
// - for example, vector<string> list_of_words = {"house", "cake", "pancake"}; will have following output: 2,2,4

#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Words {
  public:
    Words(vector<string>& n){
      list_of_words = n;
    }
  
    void CoutStrings() {
       vector<int> counts;
       int size;
       for (auto a : list_of_words) {
         size = CountNonVowels(a, a.length());
         counts.push_back(size);
       }
       for (int i = 0; i < counts.size(); i++) {
         if (i == counts.size()-1) {
           cout << counts.at(i) << endl;
         }
         else {
           cout << counts.at(i) << ',';
         }
       }
     }
  
  private:
    vector<string> list_of_words;
  
    bool IsNonVowel(char ch) {
      ch = toupper(ch);
      return !(ch=='A' || ch=='E' || ch=='I' ||
               ch=='O' || ch=='U');
    }

    int CountNonVowels(string str, int n) {
      if (n == 1) {
        return IsNonVowel(str[n-1]);
      }
      return CountNonVowels(str, n-1) + IsNonVowel(str[n-1]);
    }
};

//add class definitions above this line


int main() {
  
  //add code below this line
  
    vector<string> list = {"house", "cake", "pancake"};
    Words nonvowels(list);
    nonvowels.CoutStrings();

  //add code above this line
  
  return 0;
  
}

//--------------------
// Encapsulation lab 2 
// - in this next lab, we’ll continuing building our Words class to include getter and setter
// - these should be public to enable main function to call them

// - first, we should determine what attribute to get and set
// - we currently have only one attribute, list_of_words, which is used to store list of strings
// - if we want to get particular string, or perhaps, set particular string at index

// - to be able to return string from vector, we’ll need to specify index or position
// - this means our getter function will need to take in an integer parameter
// - there is limitation to index we can specify
// - we cannot specify index position that does not exist
// - therefore, we’ll need to validate given parameter before returning anything

string GetString(int i) {
  if (i >= list_of_words.size()) {
    return "No string exists at this index.";
  }
  return list_of_words.at(i);
}

// - GetString checks to see if index exists before it returns string within vector
// - if index does not exist, no string exists at this index 
// - will be returned to user, otherwise, function will return string at specified index
// - let’s create our setter, this setter function will first check to see if index exists, then it will set particular string specified by user into that index
// - therefore, we’ll need two parameters for our setter

void SetString(string s, int i) {
  if (i >= list_of_words.size()) {
    cout << "No string exists at this index." << endl;
  }
  list_of_words.at(i) = s;
}

// - let’s test code with following commands in main

  //add code below this line
  
  vector<string> list = {"house", "cake", "pancake"};
  Words words(list);
  cout << words.GetString(0) << endl;
  words.SetString("mouse", 0);
  cout << words.GetString(0) << endl;

  //add code above this line

// - after vector is accepted as parameter, GetString function is able to return string specified at index 0 
// - this is why house is printed, then, SetString takes in mouse as parameter and replaces word at index 0 with it 
// GetString is then called again, since mouse has replaced house, mouse is printed during second call

// whole updated code: 
#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Words {
  public:
    Words(vector<string> n){
      list_of_words = n;
    }
  
    string GetString(int i) {
      if (i >= list_of_words.size()) {
        return "No string exists at this index.";
      }
      return list_of_words.at(i);
    }
  
    void SetString(string s, int i) {
      if (i >= list_of_words.size()) {
        cout << "No string exists at this index." << endl;
      }
      list_of_words.at(i) = s;
    }
  
    void CoutStrings() {
       vector<int> vowel_sizes;
       int size;
       for (auto a : list_of_words) {
         size = CountVowels(a, a.length());
         vowel_sizes.push_back(size);
       }
       for (int i = 0; i < vowel_sizes.size(); i++) {
         if (i == vowel_sizes.size()-1) {
           cout << vowel_sizes.at(i) << endl;
         }
         else {
           cout << vowel_sizes.at(i) << ',';
         }
       }
     }
  
  private:
    vector<string> list_of_words;
  
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


int main() {
  
  //add code below this line
  
  vector<string> list = {"house", "cake", "pancake"};
  Words words(list);
  cout << words.GetString(0) << endl;
  words.SetString("mouse", 0);
  cout << words.GetString(0) << endl;

  //add code above this line
  
  return 0;
  
}

//--------------
// Lab challenge

// Problem
// - write class named Person that has attributes string name, int age, and string occupation
// - these attributes should be private
// - create getters and setters for each attribute following C++ conventions

// given code: 
#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line



//add class definitions above this line


int main() {
  
  //DO NOT EDIT CODE BELOW THIS LINE

  Person p("Citra Curie", 16, "student");
  cout << p.GetName() << endl;
  p.SetName("Rowan Faraday");
  cout << p.GetAge() << endl;
  p.SetAge(18);
  cout << p.GetOccupation() << endl;
  p.SetOccupation("plumber");
  cout << p.GetName() << endl;
  cout << p.GetAge() << endl;
  cout << p.GetOccupation() << endl;

  //DO NOT EDIT CODE ABOVE THIS LINE
  
  return 0;
  
}

// Requirements
// Declare the instance Person("Citra Curie", 16, "student")
// The function GetName() returns Citra Curie
// The function SetName("Rowan Faraday") changes the name attribute to “Rowan Faraday”
// The function GetAge() returns 16
// The function SetAge(18) changes the age attribute to 18
// The function GetOccupation() returns student
// The function SetOccupation("plumber") changes the occupation attribute to “plumber”

// Expected output: 
// Citra Curie
// 16
// student
// Rowan Faraday
// 18
// plumber  

#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Person {
  public:
    Person(string n, int a, string o) {
      name = n;
      age = a;
      occupation = o;
    }
  
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
  
  private:
    string name;
    int age;
    string occupation;
};

//add class definitions above this line


int main() {
  
  //DO NOT EDIT CODE BELOW THIS LINE

  Person p("Citra Curie", 16, "student");
  cout << p.GetName() << endl;
  p.SetName("Rowan Faraday");
  cout << p.GetAge() << endl;
  p.SetAge(18);
  cout << p.GetOccupation() << endl;
  p.SetOccupation("plumber");
  cout << p.GetName() << endl;
  cout << p.GetAge() << endl;
  cout << p.GetOccupation() << endl;

  //DO NOT EDIT CODE ABOVE THIS LINE
  
  return 0;
  
}

// - your task is to create getter and setter functions for each of three private attributes name, age, and occupation
// - for getters, simply return appropriate attribute; however, be sure to specify correct returntype that matches type of attribute
// - setters typically have parameters to direct system how to modify attributes
// - each of setters should contain one parameter and this parameter will become new value of specified attribute
// - note that setters do not have return type, thus they are void

//---------------------------------------------------------------------------------------------------//

//-----------
// Exercise 1 
// - create Fruit class that contains two string attributes, name and color, as well as getter and setter functions

#include <iostream>
using namespace std;

int main() {
  
  //DO NOT EDIT CODE BELOW THIS LINE

  Fruit fruit("apple", "red");
  cout << fruit.GetName() << endl;
  cout << fruit.GetColor() << endl;
  fruit.SetName("orange");
  fruit.SetColor("orange");
  cout << fruit.GetName() << endl;
  cout << fruit.GetColor() << endl;

  //DO NOT EDIT CODE ABOVE THIS LINE
  
  return 0;
  
}

// Requirements
// - create Fruit class with string attributes, name and color
// - include getters called GetName and GetColor
// - include setters called SetName and SetColor
// - include BOTH public as well as private access modifiers in your class

// Expected Output
// apple
// red
// orange
// orange

// - parameters of constructor should be assigned to private attributes
// - getters should have return type of string while setters have void

// Solution:

class Fruit {
  public:
    Fruit(string n, string c) {
      name = n;
      color = c;
    }
  
    string GetName() {
      return name;
    }
  
    void SetName(string new_name) {
      name = new_name;
    }
  
    string GetColor() {
      return color;
    }
  
    void SetColor(string new_color) {
      color = new_color;
    }
  
  private:
    string name;
    string color;
};

//---------------------------------------------------------------------------------------------------//
// Exercise 2 

// - create Watch class following conventions of encapsulation

#include <iostream>
using namespace std;

int main() {

  Watch my_watch("Omega", "Speedmaster", 42, 50, "steel");
  cout << my_watch.GetManufacturer() << endl;
  cout << my_watch.GetModel() << endl;
  cout << my_watch.GetDiameter() << endl;
  cout << my_watch.GetWaterResistance() << endl;
  cout << my_watch.GetMaterial() << endl;
  my_watch.SetManufacturer("Rolex");
  my_watch.SetModel("Explorer");
  my_watch.SetDiameter(36);
  my_watch.SetWaterResistance(60);
  my_watch.SetMaterial("gold");
  my_watch.Summary();
  
  return 0;
  
}

// Requirements
// - create Watch class with following attributes:
// manufacturer - string that represents who makes watch
// model - string that represents specific watch
// diameter - integer that represents (in millimeters) diameter of watch
// water_resistance - integer that represents (in meters) water resistance of watch
// material - string that represents what watch is made of

// Expected Output
// Omega
// Speedmaster
// 42
// 50
// steel
// Manufacturer: Rolex
// Model: Explorer
// Diameter: 36 mm
// Water Resistance: 60 m
// Material: gold

// - connect constructor parameters to private attributes
// - setters are void functions, but make sure correct return type is labeled for each getter

// Solution:

class Watch {
  public:
    Watch(string mf, string mo, int d, int w, string mt) {
      manufacturer = mf;
      model = mo;
      diameter = d;
      water_resistance = w;
      material = mt;
    }
  
    string GetManufacturer() {
      return manufacturer;
    }

    void SetManufacturer(string new_manufacturer) {
      manufacturer = new_manufacturer;
    }

    string GetModel() {
      return model;
    }

    void SetModel(string new_model) {
      model = new_model;
    }

    int GetDiameter() {
      return diameter;
    }

    void SetDiameter(int new_diameter) {
      diameter = new_diameter;
    }

    int GetWaterResistance() {
      return water_resistance;
    }

    void SetWaterResistance(int new_water_resistance) {
      water_resistance = new_water_resistance;
    }

    string GetMaterial() {
      return material;
    }

    void SetMaterial(string new_material) {
      material = new_material;
    }

    void Summary() {
      cout << "Manufacturer: " << manufacturer << endl;
      cout << "Model: " << model << endl;
      cout << "Diameter: " << diameter << " mm" << endl;
      cout << "Water Resistance: " << water_resistance << " m" << endl;
      cout << "Material: " << material << endl;
    }
  
  private:
    string manufacturer;
    string model;
    int diameter;
    int water_resistance;
    string material;
};


//-----------
// Exercise 3

// - complete Song class which represents song on streaming service

#include <iostream>
using namespace std;

class Song {

  private:
    string artist;
    string title;
    string album;
    int play_count = 0;
    const double pay_rate = 0.001;
    double money_earned = 0;
    
    void UpdatePlayCount() {
      play_count++;
    }
  
    void UpdateMoneyEarned() {
      money_earned = play_count * pay_rate;
    }
};

int main() {

  Song my_song("Led Zeppelin", "Ten Years Gone", "Physical Graffiti");
  cout << my_song.GetArtist() << endl;
  cout << my_song.GetTitle() << endl;
  cout << my_song.GetAlbum() << endl;
  cout << my_song.GetPlayCount() << endl;
  cout << my_song.GetPayRate() << endl;
  cout << my_song.GetMoneyEarned() << endl;
  my_song.SetArtist("Michael Jackson");
  my_song.SetTitle("Beat It");
  my_song.SetAlbum("Thriller");
  my_song.Play(1000000);
  my_song.Stats();
  
  return 0;
  
}

// Requirements
// - complete Song class that includes all necessary getter and setter functions for each class attribute
// - there should be total of 6 getter functions
// - there should be total of 3 setter functions
// play_count, pay_rate and money_earned do not have setter functions because they are initialized to 0 or 0.001 when Song object is instantiated
// - include class function Play that takes in an int parameter and calls UpdatePlayCount and UpdateMoneyEarned that number of times
// - include class function Stats that prints all of class attributes according to their declaration order
// - include appropriate access modifier(s) in your class

// Expected Output
// Led Zeppelin
// Ten Years Gone
// Physical Graffiti
// 0
// 0.001
// 0
// Michael Jackson
// Beat It
// Thriller
// 1000000
// 0.001
// 1000

// Key Points:

// - connect constructor parameters to appropriate private attributes; not all of private attributes have to linked
// - label getters and setters appropriately; some setters are not needed
// - Play and Stats are void functions where Play calls the appropriate functions to update play_count and money_earned while Stats prints out requested output

// Solution:

  public:
    Song(string ar, string t, string al) {
      artist = ar;
      title = t;
      album = al;
    }
  
    string GetArtist() {
      return artist;
    }

    void SetArtist(string new_artist) {
      artist = new_artist;
    }

    string GetTitle() {
      return title;
    }

    void SetTitle(string new_title) {
      title = new_title;
    }

    string GetAlbum() {
      return album;
    }

    void SetAlbum(string new_album) {
      album = new_album;
    }

    int GetPlayCount() {
      return play_count;
    }

    double GetMoneyEarned() {
      return money_earned;
    }

    double GetPayRate() {
      return pay_rate;
    }

    void Play(int count) {
      for (int i = 0; i < count; i++) {
        UpdatePlayCount();
        UpdateMoneyEarned();
      }
    }
  
    void Stats() {
      cout << artist << endl;
      cout << title << endl;
      cout << album << endl;
      cout << play_count << endl;
      cout << pay_rate << endl;
      cout << money_earned << endl;
    }
