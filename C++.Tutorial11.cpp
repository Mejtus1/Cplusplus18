// Arrays
// array is a data structure that stores a collection of data such as ints, doubles, strings
// Being able to store elements into an array helps reduce amount of time needed to declare and initialize variables
int Allan = 71;
int Bob = 42;
int Carol = 37;
int David = 5;
int Ellen = 18;

cout << Allan << endl; // 71 
// avoid repetitive task of declaring and initializing multiple variables
int ages[] = {71, 42, 37, 5, 18};

// You can create array without any elements, you will need to declare and specify array variable name and size before you can assign elements to array
int ages2[5];
// Method Syntax without Elements
// Specify the data type that the array will store (i.e. int)
// Declare the variable name for the array (i.e. ages) followed by the number of elements you want the array to hold within brackets (i.e.[5])
// when you declare an array without initializing any elements, system will still reserve enough memory for array to hold specified number of elements
// (This means that you can initialize elements within the array later on)

//   Array Details
// - if an element within an array has not been initialized yet, printing it will cause system to output random memory data
// - random memory data is often generated when array elements are not initialized
int ages[5];
cout << ages[0] << endl; // 1459620352, 1583352320
// ages[0] refers to index 0, element at first position is not initialized so printing first element will only output random memory data

// WHEN ARRAY IS CREATED in c++, Number of elements must be specified for array to hold --> other case = error 



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// Accessing an Array
// for access position in the array is needed
string names[] = {"Alan", "Bob", "Carol", "David", "Ellen"};
cout << names[0] << endl; // Alan 
cout << names[01 << endl; // Bob
cout << names << endl; // 0x7ffe8fbbbef0
// - printing names array without specifying index resulted in output that with mixture of numbers and letters
// - printing an array actually prints its memory location, not its elements

bool bools[] = {true, false, true};
cout << bools[0] << endl; // 1
cout << bools[1] << endl; // 0

int integers[1];
cout << integers[0] << endl; //0
integers[1] = {1.2};
cout << integers[0] << endl;
// - system will return an error message
// - by trying to initialize first element within integers array to 1.2, system will not allow it to put double element into integer array
// - it is possible to put integer element into double array because integers can be expressed as doubles but not vice versa

// Exercise
double tenths[] = {1.2, 2.3, 3.4, 4.5};
cout << tenths[0] << endl; 
// 1.2

cout << tenths[2] << endl; 
// 3.4

cout << tenths[4] << endl; 
// a memory address



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// Modifying an Array
// - to modify an element within an array, simply find index at which that element is stored and assign a new value to it
int grades[] = {85, 95, 48, 100, 92};
cout << grades[2] << endl;

grades[2] = 88; //88 will replace 48 at index 2
cout << grades[2] << endl;

// Modifying Multiple Arrays
string family[] = {"Dad", "Mom", "Brother", "Brother"};
int age[4];
age[0] = 50; //added later (first output random memory location which was selected for this specific array number)
age[1] = 45; //added later
age[2] = 25; //added later
age[3] = 20; //added later 

cout << family[0] << " " << age[0] << endl;
cout << family[1] << " " << age[1] << endl;
cout << family[2] << " " << age[2] << endl;
cout << family[3] << " " << age[3] << endl;

//Exercise
// Modifying Array Elements
// After outputting your code, you noticed that Friday is printed twice
// Your code is shown below:
string weekdays[] = {"Monday", "Tuesday", "Wednesday", 
                     "Friday", "Friday"};
// Which of following code snippets correctly modifies array so that Thursday is printed after Wednesday but before second Friday
// b) 
weekdays[3] = "Thursday";



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// Iterating an Array
// Array Iteration
string friends[] = {"Alan", "Bob", "Carol", "David", "Ellen", 
                    "Fred", "Grace", "Henry", "Ian", "Jen"};

cout << friends[0] << endl; 
cout << friends[1] << endl;
cout << friends[2] << endl;
cout << friends[3] << endl;
cout << friends[4] << endl;
cout << friends[5] << endl;
cout << friends[6] << endl;
cout << friends[7] << endl;
cout << friends[8] << endl;
cout << friends[9] << endl;
//Alan
//Bob
//Carol
//David
//Ellen
//Fred
//Grace
//Henry
//Ian
//Jen

// To print out all of our friends’ names without repeating print statement ten times, we can use a for loop to iterate 10 times

string friends[] = {"Alan", "Bob", "Carol", "David", "Ellen", 
                    "Fred", "Grace", "Henry", "Ian", "Jen"};

for (int i = 0; i < 10; i++) {
  cout << friends[i] << endl;
}
// output is the same 
//- print statement above includes i as index for friends 
//- i will take on values specified by the for loop
//- loop starts at 0 and increments by 1 until it reaches 9 (not including 10)
//- (friends[0] will print, then friends[1], so on and so forth until friends[9] is printed, then loop ends) 

//Array Size 
// - to make iteration process easier, we can use sizeof() operator to determine how many elements are in our array
string friends[] = {"Alan", "Bob", "Carol", "David", "Ellen", 
                    "Fred", "Grace", "Henry", "Ian", "Jen"};

cout << sizeof(friends) << endl; // 320 
// Why Does sizeof(friends) output 320?
// - unfortunately, sizeof() operator does not determine number of elements within an array
// - instead, sizeof() calculates size of array in bytes
// - in C++, string takes up 32 bytes and since there are 10 string elements in array, 
// size of array in bytes is 320

// to calculate number of elements within array, we will need to use sizeof() twice
string friends[] = {"Alan", "Bob", "Carol", "David", "Ellen", 
                    "Fred", "Grace", "Henry", "Ian", "Jen"};

cout << sizeof(friends) / sizeof(friends[0]) << endl; // 10 

// - sizeof(friends) calculates array’s size in bytes and sizeof(friends[0]) calculates first element’s size in bytes
// - by dividing array size by element’s size, we were able to determine number of elements that exist within array
// - it doesn’t matter if calculate first element’s size or second’s since all of elements are of same size (32 bytes each)

//Looping Through Elements
// - individual looping through elements
string friends[] = {"Alan", "Bob", "Carol", "David", "Ellen", 
                    "Fred", "Grace", "Henry", "Ian", "Jen"};

for (int i = 0; i < sizeof(friends) / sizeof(friends[0]); i++) {
  cout << friends[i] << endl;
}
//Alan
//Bob
//Carol
//David
//Ellen
//Fred
//Grace
//Henry
//Ian
//Jen

// - sizeof(friends) / sizeof(friends[0]) continues to keep track of how many elements are in our array even though we’ve made several changes

//exercise
double debt[] = {23.67, 82.96, 34.51};
for (int i = 0; i < sizeof(debt) / sizeof(debt[0]); i++) {
  cout << debt[i] << endl;
}

//Enhanced For Loop
// - enhanced for loop, also known as range-based for loop, can be used to iterate through array elements without having to refer to any array indices
// To use an enhanced for loop, you need the following:
// - keyword "for" followed by parentheses ()
// - typed iterating variable followed by colon: followed by array name
// - iterating variable must be of same type as array
// - commands that repeat within curly braces {}
// - when using an enhanced for loop, you can print iterating variable itself without using brackets []

string friends[] = {"Alan", "Bob", "Carol", "David", "Ellen", 
                    "Fred", "Grace", "Henry", "Ian", "Jen"};

for (string i : friends) {
  cout << i << endl;
}

main differences between regular for loop and enhanced for loop is that enhanced for loop does not refer to any index or position of elements in array 
Thus, if you need to access or modify array elements, you cannot use enhanced for loop
In addition, you cannot use an enhanced for loop to iterate through a part of the array. 
Think of enhanced for loop as all-or-nothing loop that prints all of array elements or nothing at all
Also note that iterating variable type must match the array type.
Fr example, you cannot use for (int i : friends) since friends is a string array and i is an integer variable.
Use for (string i : friends) instead.



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// Array Algorithms
// - arrays can be used with conditionals to help with tasks such as searching for a particular element, finding minimum or maximum element, or printing elements in reverse order

// Searching for a Particular Element
string cars[] = {"Corolla", "Camry", "Prius", "RAV4", "Highlander"};
string Camry = "A Camry is not available."; //default string value

for (string i : cars) { //enhanced for loop
  if (i == "Camry") { //if "Camry" is in array
    Camry = "A Camry is available."; //variable changes if "Camry" exists
  }
}
    
cout << Camry << endl; //print whether Camry exists or not
                       //"A Camry is available."
//-----------------------------------------------------------------------
//camry deleted from array
string cars[] = {"Corolla", "Prius", "RAV4", "Highlander"};
string Camry = "A Camry is not available."; //default string value

for (string i : cars) { //enhanced for loop
  if (i == "Camry") { //if "Camry" is in array
    Camry = "A Camry is available."; //variable changes if "Camry" exists
  }
}
    
cout << Camry << endl; //print whether Camry exists or not
// "Camry is not available"


//Finding a Minimum or Maximum Value
//1. lowest
int grades[] = {72, 84, 63, 55, 98};
int min = grades[0]; //set min to the first element in the array

for (int i : grades) { //enhanced for loop
  if (i < min) { //if element is less than min
    min = i; //set min to element that is less
  }
}
//elements are not modified so enhanced for loop can be used
cout << "The lowest grade is " << min << endl; //print lowest element
// The lowest grade is 55


//2. highest
// try to modify code so that algorithm will look for maximum element instead
int main() {
  
  //add code below this line

int grades[] = {42, 84, 63, 55, 98};
int max = grades[0]; //set max to first element in array

for (int i : grades) { //enhanced for loop
  if (max > i) { //if element is less than min
    max = i; //set max to element that is less
  }
}
//elements are not modified so enhanced for loop can be used
cout << "Highest grade is " << max << endl; //print highest element
}


// Printing Elements in Reverse Order
string letters[] = {"A", "B", "C", "D", "E"};
int elements = sizeof(letters) / sizeof(letters[0]); //number of elements
//start at index 4, then decrement by 1 until i < 0, then stop
for (int i = elements - 1; i >= 0; i--) {
  cout << letters[i] << endl;
}
//regular for loop needed to access each element index
// E
// D
// C
// B
// A

//Exercise 

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Exercises 


// 1. 
// program will print Even if the array element is an even number and Odd if it is odd.
int numbers[] = {15, 48, 22, 93, 75};

for (int i : numbers) {
  if (i % 2 == 0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}


// 2. 
// Modifying Test Scores
// Given following output:

// First test: 84
// Second test: 76
// Third test: 97

string test[] = {"First test: ", "Second test: ", "Third test: "};
int scores[3];

scores[0] = 84;
scores[1] = 76;
scores[2] = 97;

cout << test[0] << scores[0] << endl;
cout << test[1] << scores[1] << endl;
cout << test[2] << scores[2] << endl;


// 3 
// Conditional Array Output
// Given following code snippet:
int ages[] = {18, 21, 15, 2, 68};

for (int i : ages) {
  if (i >= 18) {
    cout << "Eligible" << endl;
  }
  else {
    cout << "Ineligible" << endl;
  }
}
// Determine output that will be produced by program

// Eligible
// Eligible
// Ineligible
// Ineligible
// Eligible






//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// Vectors 
// Vectors are dynamic (unlike arrays), meaning you can make changes to them while program is running 
// Vectors are particularly helpful when you don’t know how large your collection of elements will become 
// - you can add and remove elements later on if needed
// - in order to use vectors, you must include #include <vector> in header of your program

// Vector Creation
// to create a vector, you need to include following:
// - keyword vector followed by data type in angle brackets <>
// - variable name that refers to vector
// - number of elements vector can hold within parentheses ()
vector<int> numbers(3);
cout << numbers << endl; 

// Determining Vector Size
// - vectors use function size() to determine number of elements that exist instead of operator sizeof() which is used for arrays
vector<int> numbers(3);
int digits[3];

cout << numbers.size() << endl; // 3
cout << sizeof(digits) / sizeof(digits[0]) << endl; // 3 

// - arrays and vectors = must specify how many elements you expect them to hold
// - if you initialize array or vector upon declaration, then you don’t have to specify number 
// of elements since system can determine that automatically

vector<string> names(2); // correct vector syntax


//-----------------------------------------------------------------------------------------------------------//
// Adding and Removing Elements

// Adding Vector Elements
// - use push_back() function
// - push_back() function will add whatever element that is specified inside parentheses () to end of vector
// - If element is added to empty vector (vector<int> numbers(0)) that element will be first and only element in vector

vector<int> numbers(0); //vector with no elements
numbers.push_back(50); //add 50 as an element to end of vector
cout << numbers.at(0) << endl; //50 becomes first and only element 
// 50 
// push_back() function does not replace elements

vector<int> numbers(2); //vector with 2 uninitialized elements
numbers.push_back(50); //add 50 as element to end of vector
cout << numbers.at(0) << endl; //first uninitialized element
cout << numbers.at(1) << endl; //second uninitialized element 
cout << numbers.at(2) << endl; //50 is the third element now

// - arrays are strict when it comes to data type compatibility, however, vectors are more flexible
// - between four common data types, string is only type that cannot be associated with other three in vector
Integers, doubles, and booleans are all compatible with each other
Remember, in C++, true is 1 and false is 0
In addition, when doubles are converted into integers, their decimal value get eliminated
This is why pushing 50.99 into int vector causes it to turn into 50 without decimal value

// To add element to specific index in vector, you can use insert() along with the begin() functions
vector<int> numbers(5);
numbers.insert(numbers.begin()+2, 50); 
cout << numbers.at(0) << endl;
cout << numbers.at(1) << endl;
cout << numbers.at(2) << endl; // inserts number 50 at index 2
cout << numbers.at(3) << endl;
cout << numbers.at(4) << endl;
cout << numbers.at(5) << endl;

cout << "---------------------------" << endl;

numbers.insert(numbers.begin()+0, 100); 
cout << numbers.at(0) << endl; // inserts number 100 at index 0
cout << numbers.at(1) << endl;
cout << numbers.at(2) << endl; 
cout << numbers.at(3) << endl; // moves 50 to index 3 (why ?)
cout << numbers.at(4) << endl;
cout << numbers.at(5) << endl;

cout << "---------------------------" << endl;

numbers.insert(numbers.begin()+1, 170); 
cout << numbers.at(0) << endl; // 100 stays at index 0
cout << numbers.at(1) << endl; // adds 170 at index 1
cout << numbers.at(2) << endl; 
cout << numbers.at(3) << endl;
cout << numbers.at(4) << endl; // moves 50 to index 4 
cout << numbers.at(5) << endl;

cout << "---------------------------" << endl;

numbers.insert(numbers.begin()+0, 777); 
cout << numbers.at(0) << endl; // inserts 777 into index 0
cout << numbers.at(1) << endl; // moves 100 to index 1 
cout << numbers.at(2) << endl; // moves 170 to index 2 
cout << numbers.at(3) << endl;
cout << numbers.at(4) << endl; 
cout << numbers.at(5) << endl; // moves 50 to index 5

// begin() function always refer to first position in vector, which is also 0th index
// -  you want to refer to 1st index, use begin()+1
// - 2nd index, use begin()+2, so on and so forth

// output 
/*
0
0
50
0
0
0
---------------------------
100
0
0
50
0
0
---------------------------
100
170
0
0
50
0
---------------------------
777
100
170
0
0
50
*/


// Removing Vector Elements
// - to remove an element from end of a vector, use pop_back()
// - using pop_back will remove element and its index, thus decreasing size of vector by 1
vector<int> numbers(0); //empty vector
numbers.push_back(50); //add 50 to vector
numbers.push_back(100); //add 100 to vector
cout << numbers.at(0) << endl;
cout << numbers.at(1) << endl << endl;

numbers.pop_back(); //remove last element vector
cout << numbers.at(0) << endl;
cout << numbers.at(1) << endl; //100 has been deleted completely
/*
50
100

50
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 1) >= this->size() (which is 1)
Aborted (core dumped)
*/

// erase() function 
// - to remove an element from specific index in vector, use erase() function and specify index you want to erase with begin()
// - element and its index is removed from vector, all of elements to its right will be moved one place to left
vector<int> numbers(0); //empty vector
numbers.push_back(50); //add 50 to vector
numbers.push_back(100); //add 100 to vector
cout << numbers.at(0) << endl;
cout << numbers.at(1) << endl << endl;

numbers.erase(numbers.begin()); //removes 50
cout << numbers.at(0) << endl;
cout << numbers.at(1) << endl; //no longer exists

// exercise
vector<string> words(0);

words.push_back("I");
words.push_back("love");
words.erase(words.begin()+1);
words.push_back("hate");
words.insert(words.begin()+1, "really");
words.insert(words.begin()+3, "bean sprouts");

cout << words.at(0) << " " 
     << words.at(1) << " " 
     << words.at(2) << " " 
     << words.at(3);
/*
By following syntax for adding and removing vector elements, you should end up with output:
I really hate bean sprouts

Code Flow:
words.push_back("I"); —> I
words.push_back("love"); —> I love
words.erase(words.begin()+1); —> I
words.push_back("hate"); —> I hate
words.insert(words.begin()+1, "really"); —> I really hate
words.insert(words.begin()+3, "bean sprouts"); —> I really hate bean sprouts
*/

//-----------------------------------------------------------------------------------------------------------//
// Modifying Vector Elements
// To modify vector elements, use at() method to specify index number and then assign new element to it 
vector<string> contact(0);
contact.push_back("First name");
contact.push_back("Last name");
contact.push_back("Phone number");
cout << contact.at(0) << " " 
     << contact.at(1) << " " 
     << contact.at(2) << endl;

contact.at(2) = "Email"; //change element at index 2 to "Email"
cout << contact.at(0) << " " 
     << contact.at(1) << " " 
     << contact.at(2) << endl;

contact.at(1) = "Nick name"; //change element at index 1 to "Nick Name"
cout << contact.at(0) << " " 
     << contact.at(1) << " " 
     << contact.at(2) << endl;

// First name Last name Phone number
// First name Last name Email
// First name Nick name Email


// Initializing Vector Elements
// - itspossible to initialize elements inside vector without constantly using push_back()
// - following code will produce same result as original code above
vector<string> contact{"First name", "Last name", "Phone number"};
cout << contact.at(0) << " " 
     << contact.at(1) << " " 
     << contact.at(2) << endl;

contact.at(2) = "Email"; //change element at index 2 to "Email"
cout << contact.at(0) << " " 
     << contact.at(1) << " " 
     << contact.at(2) << endl;
//First name Last name Phone number
//First name Last name Email

// - when initializing elements within vector, you do not specify number of elements in parentheses
// - system will automatically know how many elements are being added to vector
// - initialized elements should be in curly braces {} and separated by commas ,

// exercise 
// Modifying Vector Elements
// Construct a program using the code blocks below so that the following will be printed:
// output: Parker
vector<string> name(0);
name.push_back("Peter");
name.at(0) = "Parker";
cout << name.at(0) << endl;

//-----------------------------------------------------------------------------------------------------------//
// Iterating Vector Elements
// - iterating through vector is very similar to iterating through array
// - main difference is that in vector, we use at() to access elements instead of brackets []
// - both of code blocks below use regular for to produce exact same results
// - first code block contains array and second contains vector

// Iterating through Array
int grades[] = {85, 95, 48, 100, 92};
for (int i = 0; i < sizeof(grades)/sizeof(grades[0]); i++) {
  cout << grades[i] << endl;
}
// 85
// 95
// 48
// 100
// 92

// Iterating thorugh Vector 
vector<int> grades{85, 95, 48, 100, 92};
for (int i = 0; i < grades.size(); i++) {
  cout << grades.at(i) << endl;
}
// 85
// 95
// 48
// 100
// 92

// Enhanced For Loop in Vector
// We can also use an enhanced for loop, or range-based for loop, to iterate through vector
vector<int> grades{85, 95, 48, 100, 92};
for (auto i : grades) { //can use int or auto for iterating variable!
  cout << i << endl;
}
// 85
// 95
// 48
// 100
// 92

// - when using enhanced for loop for vector, you must label iterating variable accordingly
// - if your elements are of type int then your iterating variable must also be int
// - if elements are strings then your variable must be typed as string
// - you can always use auto to force variable to match your element type

// exercise
// Fill in program below with code so that all elements of vector BMI are printed
// 18.5
// 25
// 30
vector<double> BMI(0);
BMI.push_back(18.5);
BMI.push_back(25.0);
BMI.push_back(30.0);

for (double d : BMI) {
  cout << d << endl;
}

//-----------------------------------------------------------------------------------------------------------//
// Vector vs. Array
// Which one is better: vector or array? 
//
// If you know how many elements you need in your collection and you don’t intend on changing order of those elements, then it is better to use an array
// if you don’t know how many elements you need and want to modify order of elements later on, then it is better to use vector
//
// Although array is shorter to write and arguably easier to use, it is static, meaning it is not possible to add additional elements to array after it has already been initialized
// vector is more dyanamic, meaning you can add, remove, and reorganize elements as needed later on
/*

Method/Types	     Vector	                                   Array
Create             vector<type> var(num)                     type var[num] or type var[]
                   vector<type> var{element, element…}       = {element, element…}

Find number 
of elements	       var.size()	                               sizeof(var)/sizeof(var[0])

Access an element	 var.at(index)	                           var[index]

Modify an element	 var.at(index) = element	                 var[index] = element

Add an element	   var.push_back(element)                    n/a
                   var.insert(var.begin()+index, element)	

Remove an element	 var.pop_back()                            n/a
                   var.erase(var.begin()+index)	

for loop	         for (int i = 0; i < var.size(); i++)      for (int i = 0; i < sizeof(var)/sizeof(var[0]); i++) {cout << var[i];}
                   {cout << var.at(i);}	  
                                  
Enhanced           for loop	for (type i : var) {cout << i}	 for (type i : var) {cout << i}
*/

//-----------------------------------------------------------------------------------------------------------//
// Using Both a Vector and Array
// Vectors and arrays can be used in tandem with each other. 
// - following code keeps track of top five students in class
string top[] = {"First: ", "Second: ", "Third: ", "Fourth: ", "Fifth: "};
vector<string> names(0);

names.push_back("Alan");
names.push_back("Bob");
names.push_back("Carol");
names.push_back("David");
names.push_back("Ellen");
  
names.at(0) = "Carol"; //switch Alan with Carol
names.at(2) = "Alan"; //and vice versa
names.at(3) = "Fred"; //Fred replaces David
names.insert(names.begin()+4, "Grace"); //Grace takes Ellen's place
names.pop_back(); //Ellen's "Sixth" place gets removed

for (int i = 0; i < 5; i++) {
  cout << top[i] << names.at(i) << endl;
}

// First: Alan
// Second: Bob
// Third: Carol
// Fourth: David
// Fifth: Ellen

//-----------------------------------------------------------------------------------------------------------//
// Helpful Vector Algorithms

// Vector Algorithms
// - vectors can be used to search for particular element and to find minimum or maximum element
// - Additionally, vectors can reverse order of elements rather than just simply printing elements in reverse order

// searching for particular element 
vector<string> cars(0);
string Camry = "A Camry is not available."; //default string value

cars.push_back("Corolla");
cars.push_back("Camry");
cars.push_back("Prius");
cars.push_back("RAV4");
cars.push_back("Highlander");

for (auto a : cars) { //enhanced for loop
  if (a == "Camry") { //if "Camry" is in vector
    Camry = "A Camry is available."; //variable changes if "Camry" exists
  }
}
    
cout << Camry << endl; //print whether Camry exists or not
// Camry is available 

// Finding a Minimum or Maximum Value
vector<int> grades(0);
grades.push_back(72);
grades.push_back(84);
grades.push_back(63);
grades.push_back(55);
grades.push_back(98);
int min = grades.at(0); //set min to first element in array

for (auto a : grades) { //enhanced for loop
  if (a < min) { //if element is less than min
    min = a; //set min to element that is less
  }
}
//elements are not modified so enhanced for loop can be used

cout << "The lowest grade is " << min << endl; //print lowest element
// The lowest grade is 55


// reversing order of elements 
vector<string> letters(0);
letters.push_back("A");
letters.push_back("B");
letters.push_back("C");
letters.push_back("D");
letters.push_back("E");
    
int original = letters.size(); //original size
    
//regular for loops needed to access element indices

for (int i = letters.size() - 1; i >= 0; i--) {
  letters.push_back(letters.at(i));
} //add elements in reverse order to the vector
    
for (int j = 0; j < original; j++) {
  letters.erase(letters.begin());
} //remove all the original elements

//enhanced for loop can be used for just printing
for (auto a : letters) {
  cout << a << " "; //print all new vector elements
}

// Note that we used letters.erase(letters.begin()) which causes system to delete both element and index 
// Thus, next element in vector becomes new 0th index which we want to continue to delete


// exercise
// On student’s first four tests, they received scores in following order: 
// 68, 92, 100, and 88.
// 
// Fill in blanks below with code so that program will print You got a perfect score! 
// if student scored as least one 100 and will print Keep up hard work! if they did not
vector<int> scores(0);
scores.push_back(68);
scores.push_back(92);
scores.push_back(100);
scores.push_back(88);
    
int string feedback = "";

for (auto a : scores) {
  if (a == 100) {
feedback = "You got a perfect score!";
    break;
}
else {
    feedback = "Keep up the hard work!";
  }
}
cout << feedback << endl;


