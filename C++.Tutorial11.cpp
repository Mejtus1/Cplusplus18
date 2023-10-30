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

