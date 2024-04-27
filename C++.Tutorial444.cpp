//-----------
// Exercise 1 

// - assume following code:

class Dog {
  public:
    string name;
    string breed;

  Dog() {
    name = "Fido";
    breed = "Golden Retriever";
  }
};

// - create external function ChangeBreed that updates breed attribute of Dog object

void ChangeBreed(Dog dog, string new_breed) {
  dog.breed = new_breed;
}

// - ChangeBreed function needs two parameters, Dog object being modified and new breed variable
// - that is why code block void ChangeBreed() is incorrect since function has no parameters
// - parameter dog represents Dog object being modified
// - to access breed attribute, you first need to reference dog
// - that is why code blocks d.breed = new_breed; and breed = new_breed; are incorrect

// void ChangeBreed(Dog dog, string new_breed) and dog.breed = new_breed; enable Dog object’s breed to be changed by specifying new breed with new_breed variable

//-----------
// Exercise 2 

// - Imagine there exists a Player class that represents a video game character. Fill in the blanks below to complete the function LevelUp. The function should do the following things:

Increase the Player object’s level attribute by 1
Increase the Player object’s health attribute by 10
Increase the Player object’s score attribute by 100
void LevelUp(Player p) {
  p.
level
 += 1;
  
p
.health += 10;
  
p.score
 += 100;
}

// - using first line of code, you see that Player p is parameter passed to LevelUp
// - since level increases by 1, first blank is level
// - second blank is p since health attribute cannot be accessed without reference to Player object
// - last blank is p.score since this is attribute that increases by 100 according to prompt


//---------------------------------------
// External Functions vs. Class Functions

//----------------
// Class Functions 
// - back in Introduction to Objects module, class was defined as “collection of data and actions that can modify data” 
// - constructor can build "collection of data", but nothing in class can modify data, instead, external functions were used to modify object
// - using external functions to modify objects is not good practice because changes are not always permanent
// - you will be introduced to class functions, also known as class or instance methods, that serve to modify data within objects more permanently
// - think of class function as function that is attached to object
// - class function is most common type of function when creating classes
// - notice how class functions are declared inside of class
// - these functions are called class functions because they have access to class variables (attributes declared in constructor)
// - class functions are invoked using dot-notation
// - take look at how function ChangeLevel affects object mario differently as external function versus asclass function

// - take look at how function ChangeLevel affects object mario differently as external function versus asclass function

// EXTERNAL FUNCTION EXAMPLE 
#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    int health;
    int score;
    int level;
  
  Player() {
    health = 100;
    score = 0;
    level = 1;
  }
};

//add class definitions above this line 

void ChangeLevel(Player p) {
  p.level += 1;
  cout << "External change: " << p.level << endl;
}

int main() {
  
  //add code below this line

  Player mario;
  ChangeLevel(mario);
  cout << "Object change: " << mario.level << endl;

  //add code above this line
  
  return 0;
  
}

// CLASS FUNCTION EXAMPLE 
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
    void ChangeLevel() {
      level += 1;
      cout << "Class change: " << level << endl;
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
  mario.ChangeLevel();

  //add code above this line
  
  return 0;
  
}

// - there are few notable differences between external functions and class functions
// - in order for external functions to work, class variables within class must be public
// - otherwise, function will not be able to act on object
// - this, however, is not good practice
// - in C++, it is best practice to make class variables private
// - doing so provides level of protection to class attributes and prevents them from being altered accidentally.
// - this is why class functions are preferred when modifying objects
// - everything within class is public in external function example 
// - in contrast, class attributes are private while constructors and functions are public in class function example
// - to modify object using external function, syntax is Function(Object) (i.e. ChangeLevel(mario))
// - on other hand, syntax for using class function is Object.Function() (i.e. mario.ChangeLevel())

Try these variations in the Class Function Example:
Add cout << "Object change: " << mario.level << endl; to line below mario.ChangeLevel(); in main.
Change private: to //private: to comment out the private access modifier.
Change the code in main to:
Player mario;
ChangeLevel(mario);
Why did this generate an error?
C++ says that 'ChangeLevel' was not declared in this scope even though the definition is within the class Player. This happens because the code is using an external function call. Currently, ChangeLevel is a class function within the Player class. In order to access a class function, dot notation must be used.

IMPORTANT
Did you notice the difference in output between the External Function Example and the Class Function Example? ChangeLevel as an external function only affected the object temporarily; however, ChangeLevel as a class function was able to affect the object permanently. This is why the level of mario was shown as 2 and then 1 in the external function example but 2 and 2 in the class function example.

//------------------------------
// Converting to Class Functions
// - given following external functions, PrintPlayer and ChangeHealth, see if you can convert them to class functions 
// - remember to include appropriate access modifiers and to change external function calls to class function calls

#include <iostream>
using namespace std;

//add class definitions below this line

class Player {
  public:
    int health;
    int score;
    int level;
  
  Player() {
    health = 100;
    score = 0;
    level = 1;
  }
};

//add class definitions above this line

void PrintPlayer(Player p) {
  if (p.health <= 0) {
    cout << "This player is dead. They died on level " << p.level;
    cout << " with a score of " << p.score << "." << endl;
  }
  else {
    cout << "This player has " << p.health << " health, a score of " << p.score;
    cout << ", and is on level " << p.level << "." << endl;
  }
}

void ChangeHealth(Player p, int amount) {
  p.health += amount;
  cout << "New health = " << p.health << endl;
}

int main() {
  
  //add code below this line

  Player player1;
  PrintPlayer(player1);
  ChangeHealth(player1, 20);
  PrintPlayer(player1);

  //add code above this line
  
  return 0;
  
}

// solutioin : 
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
    void PrintPlayer() {
      if (health <= 0) {
        cout << "This player is dead. They died on level " << level;
        cout << " with a score of " << score << "." << endl;
      }
      else {
        cout << "This player has " << health << " health, a score of " << score;
        cout << ", and is on level " << level << "." << endl;
      }
    }
    void ChangeHealth(int amount) {
      health += amount;
      cout << "New health = " << health << endl;
    }
  
  private:
    int health;
    int score;
    int level;
};

//add class definitions above this line

int main() {
  
  //add code below this line

  Player player1;
  player1.PrintPlayer();
  player1.ChangeHealth(20);
  player1.PrintPlayer();

  //add code above this line
  
  return 0;
  
}

// Why learn about external functions that modify objects when C++ has class functions?
// - it might seem like waste of time to learn how to write external functions that modify objects temporarily, but this approach builds upon concepts you have already seen — external functions and objects
// - this allows you to understand mutability without having to worry about class functions
// - once you understand how these ideas work, transforming external function into class function is much simpler
// - external functions that modify objects serve as intermediary step on way to learning about class functions

//-----------
// Exercise 1 

// External Functions vs. Class Functions
// - fill in blanks below with appropriate key definitions
 
// class function
// - is/are declared inside of class

// external function
// - is/are declared outside of class

// external and class functions
// - can temporally or permanently modify object

//----------------------------------
// More on Class Methods and Objects 
// - changes to objects should happen exclusively through class functions
// - this makes your code easier to organize and easier for others to understand
// - imagine you are going to create class that keeps track of meal
// - in this case, meal can be thought of as all of drinks, appetizers, courses, and desserts served
// - each one of these categories will become class variable (attribute)
// - assign each attribute vector of strings
// class variables/attribute are private

//add class definitions below this line

class Meal {
  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line   

// - add class function to add drink to Meal object
// - use push_back function to add element to vector
// - so drinks.push_back(drink) adds drink drink to vector drinks
// - then add class function PrintDrinks to print out all of elements inside drinks vector
// - class functions are public

//add class definitions below this line

class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      for (auto a: drinks) {
        cout << a << endl;
      }
    }
  
  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line   

// - create Meal object in main and then test your code with following added commands


  //add code below this line

  Meal dinner;
  dinner.AddDrink("water");
  dinner.PrintDrinks();

  //add code above this line

// - now create AddAppetizer class function for class
// - like AddDrink function above, AddAppetizer accepts string as parameter and adds it as element to appetizers attribute (which is vector)
// - then create PrintAppetizers function to print what’s inside appetizers vector

void AddDrink(string drink) {
  drinks.push_back(drink);
}
void PrintDrinks() {
  for (auto a: drinks) {
    cout << a << endl;
  }
}
void AddAppetizer(string app) {
  appetizers.push_back(app);
}
void PrintAppetizers() {
  for (auto a: appetizers) {
    cout << a << endl;
  }
}

// - add "bruschetta" as appetizer to dinner object, then call class function PrintAppetizers like below

  //add code below this line

  Meal dinner;
  dinner.AddDrink("water");
  dinner.PrintDrinks();
  dinner.AddAppetizer("bruschetta");
  dinner.PrintAppetizers();

  //add code above this line

//----------------
// semi exercise 
// - create following class functions:
// AddMainCourse - accepts string which represents main course and adds it to meal
// PrintMainCourses - prints all of main courses in meal
// AddDessert - accepts string which represents dessert and adds it to meal
// PrintDesserts - prints all of desserts in meal
// - test your code using "roast chicken" as main course and "chocolate cake" as dessert 
// - then use Print class functions you created to print out all of items of meal

#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      for (auto a: drinks) {
        cout << a << endl;
      }
    }
    void AddAppetizer(string app) {
      appetizers.push_back(app);
    }
    void PrintAppetizers() {
      for (auto a: appetizers) {
        cout << a << endl;
      }
    }
    void AddMainCourse(string mc) {
      main_courses.push_back(mc);
    }
    void PrintMainCourses() {
      for (auto a: main_courses) {
        cout << a << endl;
      }
    }
    void AddDessert(string dessert) {
      desserts.push_back(dessert);
    }
    void PrintDesserts() {
      for (auto a: desserts) {
        cout << a << endl;
      }
    }
  
  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line     

int main() {
  
  //add code below this line

  Meal dinner;
  dinner.AddDrink("water");
  dinner.PrintDrinks();
  dinner.AddAppetizer("bruschetta");
  dinner.PrintAppetizers();
  dinner.AddMainCourse("roast chicken");
  dinner.PrintMainCourses();
  dinner.AddDessert("chocolate cake");
  dinner.PrintDesserts();

  //add code above this line
  
  return 0;
  
}

//-----------
// Exercise 1 

// - assume you have Person class as defined below:

class Person {
  public:
    Person(string n, int a) {
      name = n;
      age = a;
    }

  private:
    string name;
    int age;
};

// - in addition, alice is object of Person class:
Person alice("Alice", 32);
// Drag and arrange code blocks below to create class function called Birthday that adds one year to Alice’s age
void Birthday() {
  age += 1;
}
// - class function Birthday should not be of type int because this function does not return integer
// - class function Birthday does not need parameter because this function always increases age attribute by 1
// - age attribute should be increased by 1, not by another integer passed to Birthday function


687 line (BELOW exercise 1)
//-------------
// sub exercise
// - assume class Author is defined as follows:

class Author {
  public:
    Actor(string author_name, string famous_book) {
      name = author_name;
      book = famous_book;
  }

  private:
    string name;
    string book;
}
// - fill in blanks below so that class function PrintAuthor is correctly implemented
void PrintAuthor() {
  cout << name << " is known for their book " << book << endl;
}

// - int is not correct because PrintAuthor class function does not utilize any integers
// - therefore, return type must be void
// - uthor_name and famous_book are not correct because those are parameter names for constructor, not attribute names


//-------------------
// Format Entire Meal
// - you have following code in text editor
#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      for (auto a: drinks) {
        cout << a << endl;
      }
    }
    void AddAppetizer(string app) {
      appetizers.push_back(app);
    }
    void PrintAppetizers() {
      for (auto a: appetizers) {
        cout << a << endl;
      }
    }
    void AddMainCourse(string mc) {
      main_courses.push_back(mc);
    }
    void PrintMainCourses() {
      for (auto a: main_courses) {
        cout << a << endl;
      }
    }
    void AddDessert(string dessert) {
      desserts.push_back(dessert);
    }
    void PrintDesserts() {
      for (auto a: desserts) {
        cout << a << endl;
      }
    }
  
  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line     

int main() {
  
  //add code below this line

  Meal dinner;
  dinner.AddDrink("water");
  dinner.PrintDrinks();
  dinner.AddAppetizer("bruschetta");
  dinner.PrintAppetizers();
  dinner.AddMainCourse("roast chicken");
  dinner.PrintMainCourses();
  dinner.AddDessert("chocolate cake");
  dinner.PrintDesserts();

  //add code above this line
  
  return 0;
  
}

// - what you want to do next is to print all of Meal attributes that you have in format that is concise, clear, and makes sense
// - ideal output should also take into consideration how many items there are
// 0 Item in the Category
// Drinks: None
// 1 Item in the Category
// Drinks: water
// 2 Items in the Category
// Drinks: water and lemonade
// 3 Items in the Category
// Drinks: water, lemonade, and tea

//-----------------------
// Modify Class Functions
// - in order to print desired results, you’ll have to modify class functions
// - in particular, you’ll want to include multiple conditionals to select for printing format that you want
// - enhanced for loop is used to iterate vectors
// - first three sample output is more straightforward because you can just use size function to check vector’ssize and then use at function to print either 0, 1, or 2 items like below:

void PrintDrinks() {
  if (drinks.size() == 0) {
    cout << "Drinks: None" << endl;
  }
  else if (drinks.size() == 1) {
    cout << "Drinks: " << drinks.at(0) << endl;
  }
  else if (drinks.size() == 2) {
    cout << "Drinks: " << drinks.at(0) << " and " << drinks.at(1) << endl;
  }
}

// - how will you select for categories that have 3 or more items? 
// - see if you can try doing so on your own
// - run your code couple of times using PrintDrinks after adding different amounts of elements using AddDrink
void PrintDrinks() { //class definition
  if (drinks.size() == 0) {
    cout << "Drinks: None" << endl;
  }
  else if (drinks.size() == 1) {
    cout << "Drinks: " << drinks.at(0) << endl;
  }
  else if (drinks.size() == 2) {
    cout << "Drinks: " << drinks.at(0) << " and " << drinks.at(1) << endl;
  }
  else {
    cout << "Drinks: ";
    for (int i = 0; i < drinks.size() - 1; i++) {
      cout << drinks.at(i) << ", ";
    }
    cout << "and " << drinks.at(drinks.size() - 1) << endl;
  }
}

  Meal dinner;
  dinner.PrintDrinks();                                                        
  dinner.AddDrink("water");
  dinner.PrintDrinks();
  dinner.AddDrink("lemonade");
  dinner.PrintDrinks();
  dinner.AddDrink("tea");
  dinner.PrintDrinks();
  dinner.AddDrink("coffee");                                                   
  dinner.PrintDrinks();

//------------------
// Print Entire Meal
// - once you’ve completed modifying one class function
// - to print entire meal, create class function called PrintMeal that incorporates all of other Print function
// - once you’ve done that, test your code with following statements in main:

Meal dinner;
dinner.AddDrink("Pepsi");
dinner.AddDrink("Sprite");
dinner.AddAppetizer("egg rolls");
dinner.AddAppetizer("pot stickers");
dinner.AddAppetizer("buffalo wings");
dinner.AddMainCourse("smoked salmon");
dinner.PrintMeal();

// whole code: 
#include <iostream>
#include <vector>
using namespace std;

//add class definitions below this line

class Meal {
  public:
    void AddDrink(string drink) {
      drinks.push_back(drink);
    }
    void PrintDrinks() {
      if (drinks.size() == 0) {
        cout << "Drink(s): None" << endl;
      }
      else if (drinks.size() == 1) {
        cout << "Drink(s): " << drinks.at(0) << endl;
      }
      else if (drinks.size() == 2) {
        cout << "Drink(s): " << drinks.at(0) << " and " << drinks.at(1) << endl;
      }
      else {
        cout << "Drink(s): ";
        for (int i = 0; i < drinks.size() - 1; i++) {
          cout << drinks.at(i) << ", ";
        }
        cout << "and " << drinks.at(drinks.size() - 1) << endl;
      }
    }
    void AddAppetizer(string app) {
      appetizers.push_back(app);
    }
    void PrintAppetizers() {
      if (appetizers.size() == 0) {
        cout << "Appetizers(s): None" << endl;
      }
      else if (appetizers.size() == 1) {
        cout << "Appetizers(s): " << appetizers.at(0) << endl;
      }
      else if (appetizers.size() == 2) {
        cout << "Appetizers(s): " << appetizers.at(0) << " and " << appetizers.at(1) << endl;
      }
      else {
        cout << "Appetizers(s): ";
        for (int i = 0; i < appetizers.size() - 1; i++) {
          cout << appetizers.at(i) << ", ";
        }
        cout << "and " << appetizers.at(appetizers.size() - 1) << endl;
      }
    }
    void AddMainCourse(string mc) {
      main_courses.push_back(mc);
    }
    void PrintMainCourses() {
      if (main_courses.size() == 0) {
        cout << "Main Course(s): None" << endl;
      }
      else if (main_courses.size() == 1) {
        cout << "Main Course(s): " << main_courses.at(0) << endl;
      }
      else if (main_courses.size() == 2) {
        cout << "Main Course(s): " << main_courses.at(0) << " and " << main_courses.at(1) << endl;
      }
      else {
        cout << "Main Course(s): ";
        for (int i = 0; i < main_courses.size() - 1; i++) {
          cout << main_courses.at(i) << ", ";
        }
        cout << "and " << main_courses.at(main_courses.size() - 1) << endl;
      }
    }
    void AddDessert(string dessert) {
      desserts.push_back(dessert);
    }
    void PrintDesserts() {
      if (desserts.size() == 0) {
        cout << "Dessert(s): None" << endl;
      }
      else if (desserts.size() == 1) {
        cout << "Dessert(s): " << desserts.at(0) << endl;
      }
      else if (desserts.size() == 2) {
        cout << "Dessert(s): " << desserts.at(0) << " and " << desserts.at(1) << endl;
      }
      else {
        cout << "Dessert(s): ";
        for (int i = 0; i < desserts.size() - 1; i++) {
          cout << desserts.at(i) << ", ";
        }
        cout << "and " << desserts.at(desserts.size() - 1) << endl;
      }
    }
    void PrintMeal() {
      PrintDrinks();
      PrintAppetizers();
      PrintMainCourses();
      PrintDesserts();
    }
  
  private:
    vector<string> drinks;
    vector<string> appetizers;
    vector<string> main_courses;
    vector<string> desserts;
};

//add class definitions above this line     

int main() {
  
  //add code below this line

Meal dinner;
dinner.AddDrink("Pepsi");
dinner.AddDrink("Sprite");
dinner.AddAppetizer("egg rolls");
dinner.AddAppetizer("pot stickers");
dinner.AddAppetizer("buffalo wings");
dinner.AddMainCourse("smoked salmon");
dinner.PrintMeal();

  //add code above this line
  
  return 0;
  
}

//-----------
// Exercise 1 
// - changing Mutable Objects
// - drag code blocks into box below so that class function Hello will print greeting using string name attribute
// - not all of code blocks will be used, and code blocks must be properly indented or you will not receive credit for your work!
void Hello() {
  cout << "Hello, " << name << endl;
}
// - there is only one body command to choose from, cout << "Hello, " << name << endl;, which hints that function has return type of void
// - only function that has incorrect syntax is void Hello()
// - name is attribute, so Hello does not need parameter; it can already access attribute

//-----------
// Exercise 2 
// - adding to Object Mutability
// - assume following code:
class Dog: {
  public:
    Dog(string n, string b) {
      name = n;
      breed = b;
    }
    void bark() {
      cout << "Woof, woof!" << endl;
    }

  private:
   string name;
   string breed;
};

int main {
  Dog my_dog("Brutus", "Pomeranian");
  return 0;
}

// What code would you add to print Woof, woof!?
// a) my_dog.bark("Brutus", "Pomeranian");
// b) my_dog.bark();
// c) cout << my_dog.bark << endl;
// d) bark();

// correct answer: b) 
// - bark(); is not correct because class functions are called with dot notation
// - dot notation requires object name followed by function name
// - this code snippet is missing object name
// - my_dog.bark("Brutus", "Pomeranian"); is not correct because bark function does not take any arguments
// - cout << my_dog.bark << endl; is not correct because bark function does not return value that can be printed

/-----------
// Exercise 1 

// - assume following code:

class Dog {
  public:
    string name;
    string breed;

  Dog() {
    name = "Fido";
    breed = "Golden Retriever";
  }
};

// - create external function ChangeBreed that updates breed attribute of Dog object

void ChangeBreed(Dog dog, string new_breed) {
  dog.breed = new_breed;
}

// - ChangeBreed function needs two parameters, Dog object being modified and new breed variable
// - that is why code block void ChangeBreed() is incorrect since function has no parameters
// - parameter dog represents Dog object being modified
// - to access breed attribute, you first need to reference dog
// - that is why code blocks d.breed = new_breed; and breed = new_breed; are incorrect

// void ChangeBreed(Dog dog, string new_breed) and dog.breed = new_breed; enable Dog object’s breed to be changed by specifying new breed with new_breed variable

//-----------
// Exercise 2 

// - Imagine there exists a Player class that represents a video game character. Fill in the blanks below to complete the function LevelUp. The function should do the following things:

Increase the Player object’s level attribute by 1
Increase the Player object’s health attribute by 10
Increase the Player object’s score attribute by 100
void LevelUp(Player p) {
  p.
level
 += 1;
  
p
.health += 10;
  
p.score
 += 100;
}

// - using first line of code, you see that Player p is parameter passed to LevelUp
// - since level increases by 1, first blank is level
// - second blank is p since health attribute cannot be accessed without reference to Player object
// - last blank is p.score since this is attribute that increases by 100 according to prompt

//------------------------
// Exercises Labs 

//------
// Lab 1 
// - for this lab, you will create Student class that has following private class attributes:
// string name - name of student
// int grade - student’s grade level
// int score - test score of student

// - put together all of class attributes

class Student {
  private:
    string name;
    int grade;
    int score;
};

// - next, let’s define constructor Student with two parameters string n for student’s name and int g for student’s grade

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

// - define class function called StudentStatus that takes student’s int score as parameter and checks whether score is passing score or not
// - passing score is 65 or higher
// - if score is less than 65, then student did not pass their grade and will remain in same grade they are now
// - if student has score of 65 or higher, then they have passed and will move on to next grade and their grade attribute will increase by 1
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

// whole code: 
#include <iostream>
using namespace std;

//add class definitions below this line

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

//add class definitions above this line

int main() {
  
  //add code below this line


  Student alice("Alice", 4);
  alice.StudentStatus(60);
  alice.StudentStatus(90);

  //add code above this line
  
  return 0;
  
}
// Alice has not graduated and will remain in grade 4
// Alice has graduated and will be promoted to grade 5

// - since Alice received score of 65 first time, they were not promoted to next grade
// - once they got score of 90 second time around, they were promoted to next grade

//-------------
// sub exercise 
// - match each mutability vocabulary to its correct definition

// Class
// - typically contains class attributes, class functions, and the constructor
// Private
// - access modifier type for class attributes
// Public
// - access modifier type for class functions and the constructor
// Class function
// - can be used to modify class attributes or to print related output

//------
// Lab 2
Lab 2
// - it is important to understand why class attributes are labeled as private
// - this provides level of protection for your code since it does not allow the user to interact withclass attributes directly

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

// - because code above has public class attributes, following code in main can change those attributes’ values directly

  Student steve;
  steve.name = "Steve";
  cout << steve.name << endl;

// - if you change class attributes from public to private, code in main will no longer work

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

// - this is why understanding how class functions work is important
// - class functions serve as intermediate step between objects and class attributes
// - they are ones interacting with class attributes instead of user

// whole code: 
#include <iostream>
using namespace std;

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

int main() {
  
  //add code below this line

  Student steve;
  steve.ChangeName("Steve");
  cout << steve.ReturnName() << endl;

  //add code above this line
  
  return 0;
  
}
// Steve 

// - although using class functions may result in longer code, it prevents user from seeing and interacting with class attributes directly
// - this is why using class attributes is best practice

//-------------
// sub exercuse 
// - what is purpose of making class attributes private?

// - correct answer is that private class attributes cannot be accessed by user directly, thus providing code with level of protection
// - when attributes are private, user cannot use dot notation to access attribute directly
// - class functions are then used instead to make any changes needed
// - this offers code level of protection
 

//----------
// Exercises 


//-----------
// Exercise 1 
// - code below creates CelestialBody class as well as external function ComparedToEarth

#include <iostream>
using namespace std;

//add class definitions below this line

class CelestialBody {
  public:
    CelestialBody(string n, double diam, double dist, int m) {
      name = n;
      diameter = diam;
      distance = dist;
      moons = m;
    }
    
    string name;
    double diameter;
    double distance;
    int moons;
};

//add class definitions above this line   

double ComparedToEarth(CelestialBody planet) {
  double earth = 12756.3;
  double relative_size = planet.diameter / earth;
  return relative_size;
}

int main() {
  
  CelestialBody planet("Jupiter", 142984, 778360000, 79);
  
  //Modify the code below
  
  cout << ComparedToEarth(planet) << endl;

  //Modify the code above

  return 0;
  
}

// - transform ComparedToEarth function so that it becomes class function of CelestialBody class but still maintains same functionalities as when it was external function
// - in particular, it returns how much larger or smaller specified CelestialBody object is compared to Earth
// - include private access modifier where appropriate

// expected Output
// 11.2089
// - units of Measure
// - kilometers are the units of measure for diameter and distance attributes
// - distance attribute refers to distance between celestial body and sun

// SOLUTION: 
#include <iostream>
using namespace std;

//add class definitions below this line

class CelestialBody {
  public:
    CelestialBody(string n, double diam, double dist, int m) {
      name = n;
      diameter = diam;
      distance = dist;
      moons = m;
    }
    double ComparedToEarth() {
      double earth = 12756.3;
      double relative_size = diameter / earth;
      return relative_size;
    }
    
  private:
    string name;
    double diameter;
    double distance;
    int moons;
};

//add class definitions above this line   

int main() {
  
  CelestialBody planet("Jupiter", 142984, 778360000, 79);
  
  //Modify the code below
  
  cout << planet.ComparedToEarth() << endl;

  //Modify the code above
  
  return 0;
  
}

// - private access modifier is added before class attributes to make them private
// - ComparedToEarth() external function has been removed and is replaced by class function
// - only differences between external and class functions are that planet.diameter is now just diameter in definitions and function call is changed from cout << ComparedToEarth(planet) << endl; to cout << planet.ComparedToEarth() << endl; in main



//-----------
// Exercise 2 
// - you are given the following code:
// Requirements
// - using same CelestialBody class, write class function CloserToSun that compares two CelectialBody objects and returns name of object that is closer to sun (smaller distance)
// Expected Output
// - if mercury is compared to venus using mercury.CloserToSun(venus), then function will return: Mercury

#include <iostream>
using namespace std;

//add class definitions below this line

class CelestialBody {
  public:
    CelestialBody(string n, double diam, double dist, int m) {
      name = n;
      diameter = diam;
      distance = dist;
      moons = m;
    }
    
  private:
    string name;
    double diameter;
    double distance;
    int moons;
};

//add class definitions above this line   

int main() {
  
  //DO NOT EDIT the code below
  
  CelestialBody mercury("Mercury", 4879.4, 57909000, 0);
  CelestialBody venus("Venus", 12103.6, 108160000, 0);
  cout << mercury.CloserToSun(venus) << endl;

  //DO NOT EDIT the code above
  
  return 0;
  
}

// SOLUTION 
#include <iostream>
using namespace std;

//add class definitions below this line

class CelestialBody {
  public:
    CelestialBody(string n, double diam, double dist, int m) {
      name = n;
      diameter = diam;
      distance = dist;
      moons = m;
    }
    string CloserToSun(CelestialBody cb) {
      if (distance < cb.distance) {
        return name;
      }
      else {
        return cb.name;
      }
    }
    
  private:
    string name;
    double diameter;
    double distance;
    int moons;
};

//add class definitions above this line   

int main() {
  
  //DO NOT EDIT the code below
  
  CelestialBody mercury("Mercury", 4879.4, 57909000, 0);
  CelestialBody venus("Venus", 12103.6, 108160000, 0);
  cout << mercury.CloserToSun(venus) << endl;

  //DO NOT EDIT the code above
  
  return 0;
  
}

// - mercury.CloserToSun(venus) is used to compare object mercury with object venus, compare their distance attribute
// - mercury‘s values can be referenced by calling default class attributes’ names such as distance while venus can be referenced by using dot notation such as cb.distance
// - use conditional statements to compare distance between two objects and return name of object with smaller distance
