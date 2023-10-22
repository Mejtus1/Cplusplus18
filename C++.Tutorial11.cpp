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
