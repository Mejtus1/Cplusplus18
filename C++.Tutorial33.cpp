// String length 
// - all strings have following characteristics:
//Characters - Strings are made up of characters between quotation marks (previously covered in “Fundamentals” section)
//Length - Each string has length (total number of characters)
//Index - Each character in string has position, called index

// To calculate length of string, use length() function
// This function will return integer that is sum of all of characters between quotation marks

string my_string = "Hello";
int len_string = my_string.length();
cout << len_string << endl;
// 5 
string my_string = "Hello world!";
int len_string = my_string.length();
cout << len_string << endl;
// 12
string my_string = "";
int len_string = my_string.length();
cout << len_string << endl;
// 0
string my_string = "-1";
int len_string = my_string.length();
cout << len_string << endl;
// 2
string my_string = "Привет";
int len_string = my_string.length();
cout << len_string << endl;
// 12 

// - although each character that you see on typical keyword usually has length of 1, 
// - there are other foreign characters that do not follow this convention
// - Привет, which stands for Hello in Russian, actually has length of 12 instead of 6


// - String Index
// - string has indices that correspond to position where each of its character resides
// - like vector and array indices, string indices also start at 0
// STRING     " H e l l o ! "
// INDICES      0 1 2 3 4 5 
// - quotation marks are required to declare value of string 
// - however, quotation marks are not part of string itself
// - that is why quotation marks are not counted with length() function and why they do not have index

// reference 
// - to reference character, use string name followed by at() function 
// - within parentheses (), provide index number of character you want system to return 
// - alternatively, you can also use brackets [] to enclose index number

string my_string = "Hello!";
char character = my_string.at(1);
cout << character << endl; // e 

char character = my_string.at(my_string.length()-1);
cout << character << endl; // !

char character = my_string.at(5);
cout << character << endl; // 

//exercise
/*
Strings are composed of a sequence of 
characters

The number of characters can be determined by using 
length()

Individual characters can be referenced by using the 
index */


//-----------------------------------------------------------------------------------------------------------//
// Mutability
string my_string = "House";
my_string.at(0) = "M";
cout << my_string << endl; // error 
// - unlike vectors and arrays where characters can be manipulated, string literals are immutable 
// - particular character can be changed within string

string my_string = "House";
my_string.at(0) = 'M';
cout << my_string << endl; // Mouse
// - difference lies within double quotes "" and single quotes ''
// - string literal cannot be changed, character at particular index can be changed 


// String Re-Assignment
// - other than string manipulation, entire string can be changed by overwriting itself with new value 
// 
string my_string = "House";
my_string = "Mouse";

cout << my_string << endl; // Mouse

// Mutability vs re-assignment
// - reassignment replaces whole value, while mutability changes just part of the string 

// exercise
// what does it mean that string is immutable ? 
// c) You cannot modify a string literal
// - string is immutable when you cannot change string literal
// - String literals are enclosed within double quotes ""
// - You can, however, alter individual character, enclosed within single quotes '', by specifying particular string index. 
// - my_string.at(0) = "A" is trying to change string literal, which is not allowed
// - but it is possible to change a single character at index 0 to A using my_string.at(0) = 'A'.

//-----------------------------------------------------------------------------------------------------------//
// find() function 
// - tells if character or string is present in another string and if so at what index it is at
// - returns integer index if character is present
// - returns 18446744073709551615 if integer is not present in index

// What is 18446744073709551615 ?
// - it is the largest integer value possible in C++
// - when find() is called and 18446744073709551615 is returned, means system has searched through all values and cannot locate specified value
// - it is equivalent to -1 as signed value 

string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find("dog") << endl;
// 10 

string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find("cat") << endl;
// 18446744073709551615

string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find("Dog") << endl;
// 18446744073709551615

string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find(" ") << endl;
// 3 

// if we want to start searching for string / character at particular index,
// specify particular index number after specified string

string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find("he", 4) << endl; //start at index 4
// 26
string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find("he", 27) << endl; //start at index 27
// 18446744073709551615
string my_string = "The brown dog jumps over the lazy fox.";
cout << my_string.find("he", 27) << endl; //start at index 27
// 1 

//-----------------------------------------------------------------------------------------------------------//
// substr() function 
// - subst() returns portion of string
// - within () provide: string to start, number of characters the system will start copying from

string my_string = "The brown dog jumps over the lazy fox.";
string my_slice = my_string.substr(4, 9); // 4 = start
cout << my_slice << endl;                 // 9 = number of characters 
// brown dog 

string my_string = "The brown dog jumps over the lazy fox.";
string my_slice = my_string.substr(1, 2);
cout << my_slice << endl; 
// he

string my_string = "The brown dog jumps over the lazy fox.";
string my_slice = my_string.substr();
cout << my_slice << endl;
// The brown dog jumps over the lazy fox.

string my_string = "The brown dog jumps over the lazy fox.";
string my_slice = my_string.substr(1, 1);
cout << my_slice << endl;
// h 

string my_string = "The brown dog jumps over the lazy fox.";
string my_slice = my_string.substr(2);
cout << my_slice << endl;
// e brown dog jumps over the lazy fox.

// EXERCISE
string my_string = "Calvin and Hobbes";
string my_slice = my_string.substr(3, 8);
// vin and 

//-----------------------------------------------------------------------------------------------------------//
// Escape character
// - escape character is character that has different interpretation in a string
// - \ = most common escape character, it is newline character \n (causes C++ to print on new line)
string my_string = "Hello\nworld";
cout << my_string << endl;
// Hello
// world
string my_string = "Hello\nworld";
cout << my_string << endl;
// Hello
// 
// World

// - \\ = prints a backslash
cout << "\\" << endl; // \

// - \' = prints a single quote
cout << "\'" << endl; // '

// - \" = prints a double quote
cout << "\"" << endl; // "

// - \t = prints a tab (spacing)
cout << "Hello\tworld" << endl; // Hello    world

//-----------------------------------------------------------------------------------------------------------//
// Quotes Inside Quotes

string my_string = "And then she said, 'Hi there.'";
cout << my_string << endl;

string my_string2 = 'And then she said, "Hi there."';
cout << my_string2 << endl;

string my_string = "And then she said, \"Hi there.\"";
cout << my_string << endl;

//-----------------------------------------------------------------------------------------------------------//
// Exercise
// Compare if string1 is longer than string2 
if (string1.length() > string2.length()) {
  cout << "string1 is longer" << endl;
}

// Exercise 2 
// Select all of the print statements below that will produce the following output:

// I am the first line,
// I am the second,
// and I am the third line!

cout << "I am the first line," << endl;
cout << "I am the second," << endl;
cout << "and I am the third line!";

cout << "I am the first line,\nI am the second,\nand I am the third line!";

