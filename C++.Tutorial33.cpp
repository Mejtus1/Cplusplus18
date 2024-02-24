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

//-----------------------------------------------------------------------------------------------------------//
// String Functions 

// find() function 
// my_string.find("this", 2) = find this exact string ("this") and (2) start at the index of 2

// find_first_of() = searches for any matching characters within string, without specify first occurence, with specify after index first occurence
// my_string.find_first_of("this",2) = ("this") = find any of these characters, (2) = index where to start

// find_last_of() = searches for set of characters in string that occurs last

// The find_first_of() Function
// - find_first_of() function works similarly to how find() function does
// - find_first_of() function will search for any matching characters specified
// - given string "this is his string", my_string.find_first_of("his") will return 1 because character h within his appears first at index number 1
// - like find() function, you can optionally specify an index number to direct system where to start searching

string string1 = "The brown dog jumps over the lazy fox.";
string string2 = "brown";

cout << string1.find_first_of(string2) << endl; // 4 
cout << string1.find_first_of("wornb") << endl; // 4 
cout << string1.find_first_of(string2, 14) << endl; // 20 (first occurence of character from brown)
string string2 = "axe";
cout << string1.find_first_of(string2, 34) << endl; // 36 
string string2 = "i";
cout << string1.find_first_of(string2) << endl; // 18446744073709551615
// 18446744073709551615 = not found

// exercise
// Determine output of following code snippet:
string my_string = "Today is a great day.";
cout << my_string.find_first_of("aeiou", 11);
// 13 

//-----------------------------------------------------------------------------------------------------------//
// push_back() function 
// - push_back() function works same way in strings as it does in vectors
// - it adds specific character to end of string
// - '' SINGLE QUOTES ARE NECESARRY WHEN USING push_back()

string my_string = "Today is Satur";
my_string.push_back('d');

cout << my_string << endl;
// Today is Saturd

string my_string = "Today is Satur";
my_string.push_back('d');
my_string.push_back('ay');

cout << my_string << endl; // ERROR 


string my_string = "Today is Satur";
my_string.push_back('d');
my_string.push_back('a');
my_string.push_back('y');

cout << my_string << endl; // Today is Saturday

// - push_back() function cannot add multiple characters to and existing string

// insert() FUNCTION
// - insert function can add multiple characters to and existing string
// - it is necesarry to specify starting index number in insert() to work 
// - index specification comes before string to add 

// - in conjuction with insert function, is length() function which adds to the end of the string
string my_string = "Today is Satur";
my_string.insert(my_string.length(), "day");
cout << my_string << endl; // Today is Saturday
// my_string variable is called second time within insert function to add to end of my_string variable

string my_string = "Today is Satur";
my_string.insert(0, "day");
cout << my_string << endl; // dayToday is Satur

string my_string = "Today is Satur";
my_string.insert(my_string.length(), "day");
my_string.insert(9, "a good ");
cout << my_string << endl; // Today is a good Saturday 

//-----------------------------------------------------------------------------------------------------------//
// pop_back() function 
// - removes single character from end of string
// - nothing is included within parenthesis
string my_string = "Today is my birthday!";
my_string.pop_back();
cout << my_string << endl; // Today is my birthday

// erase() function 
// - can remove multiple characters from string or entire string itself 
// - to leave whole string () perenthesis is left empty
// - specify one index number to remove all characters starting at that index to end of string
// - specify two numbers to start at index and erase number of characters forward
string my_string = "Today is my birthday!";
my_string.erase(my_string.length()-1);
cout << my_string << endl; // Today is my birthday (! is erased)

string my_string = "Today is my birthday!";
my_string.erase(12);
cout << my_string << endl; // Today is my

string my_string = "Today is my birthday!";
my_string.erase(12, 5);
cout << my_string << endl; // Today is my day! (starting index 12 and 5 characters forward are erased)

string my_string = "Today is my birthday!";
my_string.erase(); 
cout << my_string << endl; // Command was successfully executed.

//-----------------------------------------------------------------------------------------------------------//
// replace() function 
// - combination of erase() and insert()
// - my_string.replace(1, 2, "3")
// - 1 represents start index
// - 2 how many characters to erase starting at index 1
// - "3" string, system will insert into string at index 1

string string1 = "Hello world!";
string string2 = "Codio.";
string string3 = string1.replace(6, 5, string2);
// erase all characters from index 6 plus 5 chars to the right in string1
// then insert string2 at index 6 within string1
cout << string3 << endl; // Hello Codio.!

string string1 = "Hello world!";
string string2 = "Codio.";
string string3 = string1.replace(6, 6, string2); 
cout << string3 << endl; // Hello Codio. (! is erased too now )

string string1 = "Hello world!";
string string2 = "Codio.";
string string3 = string1.replace(2, 3, "y");
cout << string3 << endl; // Hey world! 

// Exercise
string sunny = "Today is sunny";
string rainy = "rainy";
string output = sunny.replace(9, 5, rainy);
cout << output << endl; // Today is rainy

//-----------------------------------------------------------------------------------------------------------//
// append() function 
// - alternative way concatenate or combine strings
// - works same way as adding strings together
string a = "High";
string b = " Five";
cout << a.append(b) << endl; // High Five

string a = "High";
string b = " Five";
cout << a.append(b + "!") << endl; // High Five! 
cout << a.append("Five" + "!") << endl; // Error
cout << a.append(a + "Five" + "!") << endl; // HighFiveFive!

string a = "High";
int b = 5;
cout << a.append(b) << endl; // error 

// - append() is exlusively for strings (other data types need to be converted)
// - when using + operator make sure at least one of strings is string variable, 
// otherwise system will think you are trying to manipulate string literal

//-----------------------------------------------------------------------------------------------------------//
// toupper() function 
// - returns uppercase form of specified character
// - returns
// char(toupper(my_string.at(0)))
// - char = char converter
// - toupper = toupper function 
// - my_string.at = character or index

// - toupper() returns ASCII representation of Uppercase letter, we need char to convert to alphabetical

string my_string = "the big brown dog";
cout << char(toupper(my_string.at(0))) << endl; // T 

string my_string = "the big brown dog";
cout << char(toupper(my_string.at(my_string.length()-1))) << endl; // G (last character = -1)

cout << char(toupper('t')) << endl; // T 
cout << char(toupper(my_string)) << endl; // Error 

// tolower() function 
// - all technicalities of toupper()
// - returns lowercase form of specified character
string my_string = "THE BIG BROWN DOG";
cout << char(tolower(my_string.at(1))) << endl; // h

string my_string = "THE BIG BROWN DOG";
cout << char(tolower(my_string.at(my_string.length()-1))) << endl; // g

cout << char(tolower('B')) << endl; // b 
cout << char(tolower('&')) << endl; // %

// toupper() and tolower() returns ASCII code unless converted to char
// toupper() and tolower() can only accept and return one character at a time

//-----------------------------------------------------------------------------------------------------------//
// String Iteration
// Iteration: For loop

// Iterating over strings 
// Iterating over string allows you to deal with each character of string individually without having to repeat certain commands
string my_string = "Hello world";
for (int i = 0; i < my_string.length(); i++) {
  cout << my_string.at(i);
}

string my_string = "\u25A3\u25A8\u25D3\u25CC\u25A2";
for (int i = 0; i < my_string.length(); i++) {
  cout << my_string.at(i);
}              // ▣▨◓◌▢

string my_string = "10 , 20 , 30 , 40 , 50";
for (int i = 0; i < my_string.length(); i++) {
  cout << my_string.at(i);
}              // 10 , 20 , 30 , 40 , 50

string my_string = "10 , 20 , 30 , 40 , 50";
for (int i = 0; i < my_string.length(); i++) {
  cout << my_string;
}              // 10 , 20 , 30 , 40 , 50........ 
               // loop runs forever

// Range-based / Enhanced for loop 
// - can be used to iterate over strings
// - make sure to cast iterating variable as char

string my_string = "Hello world";
for (char c : my_string) {
  cout << c;
} // Hello world 

// exercise
for (char c : mystery_string) {
cout << c << endl;
} 
// m
// y
// s
// t
// e
// r
// y

//-----------------------------------------------------------------------------------------------------------//
// Iteration: While Loop
// - string iteration is most often done with for loop
// - however, while can be used as well
string my_string = "Calvin and Hobbes";
int i = 0;

while (i < my_string.length()) {
  cout << my_string.at(i);
  i++;
} // Calvin and Hobbes

string my_string = "Calvin and Hobbes";
int i = 0;

while (i < my_string.length()) {
  cout << my_string.at(i);
} // i++ is deleted
  // output: Terminated by output limit - loop runs forever

// For loops vs While loops used in strings 

// for loops 
string my_string = "C++";

for (int i = 0; i < my_string.length(); i++) {
  cout << my_string.at(i);
} // C++

// while loops 
string my_string = "C++";
int i = 0;

while (i < my_string.length()) {
  cout << my_string.at(i);
  i++;
} // C++

// - above are two ways of iterating through string
// - first way uses for loop and second uses while loop
// - both produces same result
// - for loop is usually preferred because it requires less code to accomplish same task
// - you can also use enhanced for loop, which requires least account of code, but enhanced while loop does not exist

string my_string = "Codio";
int len = my_string.length();
int i = 0;

while (i < len) {
  cout << my_string.at(i);
  i++;
}

// Exercises

// What does variable i represent?
string my_string = "Hello world";
for (int i = 0; i < my_string.length(); i++) {
  cout << my_string.at(i);
} 

// construct program that outputs :
// today is good day
// i represents each index or character of my_string
string my_string = "Today is a good day";
int i = 0;
while (i < my_string.length()) {
  cout << my_string.at(i);
  i++;
}
// Today is a good day


//-----------------------------------------------------------------------------------------------------------//
// Comparing with == 
// - "==" operator can be used with strings just like it is with numbers or boolean values
// - note that without boolalpha flag, system will return 1 if true and 0 if false
// - 1 represents string equality and 0 represents inequality

string string1 = "It's Friday!";
string string2 = "It's Friday!";
cout << (string1 == string2); // 1 means boolean true

string string1 = "It's Friday!";
string string2 = "It\'s Friday!";
cout << (string1 == string2); // 1 means boolean true

string string1 = "It's friday!";
string string2 = "It's Friday!";
cout << (string1 == string2); // 0, false

string string1 = "It's friday!";
string string2 = "It's Friday!";
cout << boolalpha << (string1 == string2); // false

// Comparing with !=
// You can also test for string inequality with != operator
string string1 = "It's Friday!";
string string2 = "It's Monday.";
cout << (string1 != string2); // 1 

string string1 = "It's Friday!";
string string2 = "It's Friday!";
cout << (string1 != string2); // 0 

string string1 = "It's Friday!";
string string2 = "It's Friday!";
cout << boolalpha << (string1 != string2); // false

string string1 = "I love Java";
string string2 = "I love J@va";
string string3 = "I love Java";

// Exercise 
// Fill in blanks below so that program will print 1 for all of listed print statements
cout << (string1 != string2) << endl;
cout << (string2 != string3) << endl;
cout << (string3 == string1) << endl;

// true
// true
// true

//-----------------------------------------------------------------------------------------------------------//
// Lexicographical Order
// - in C++, strings can be compared lexicographically, meaning they can be compared according to how they will appear in dictionary
// - zou can use compare() method to determine which of two strings comes first

// Lexicographically speaking, 
// empty strings always come first, 
// followed by numbers, 
// then uppercase letters, 
// and finally lowercase letters

// - return value negative integer means first string comes first, 
// - return value positive integer means second string comes first, 
// - return value of 0 means strings are equal and neither comes first

string string1 = "apple";
string string2 = "cat";

if (string1.compare(string2) < 0) {
  cout << "string1 comes first" << endl;
}
else if (string1.compare(string2) > 0) {
  cout << "string2 comes first" << endl;
}
else {
  cout << "the strings are equal" << endl;
} // string1 comes first


string string1 = "apple";
string string2 = "apple";

if (string1.compare(string2) < 0) {
  cout << "string1 comes first" << endl;
}
else if (string1.compare(string2) > 0) {
  cout << "string2 comes first" << endl;
}
else {
  cout << "the strings are equal" << endl;
} // strings are equal 


string string1 = "2";
string string2 = "10";

if (string1.compare(string2) < 0) {
  cout << "string1 comes first" << endl;
}
else if (string1.compare(string2) > 0) {
  cout << "string2 comes first" << endl;
}
else {
  cout << "the strings are equal" << endl;
} // string 2 comes first


string string1 = "apple";
string string2 = "";

if (string1.compare(string2) < 0) {
  cout << "string1 comes first" << endl;
}
else if (string1.compare(string2) > 0) {
  cout << "string2 comes first" << endl;
}
else {
  cout << "the strings are equal" << endl;
} // string 2 comes first


string string1 = "apple";
string string2 = "9";

if (string1.compare(string2) < 0) {
  cout << "string1 comes first" << endl;
}
else if (string1.compare(string2) > 0) {
  cout << "string2 comes first" << endl;
}
else {
  cout << "the strings are equal" << endl;
} // string 2 comes first


string string1 = "123";
string string2 = "9";

if (string1.compare(string2) < 0) {
  cout << "string1 comes first" << endl;
}
else if (string1.compare(string2) > 0) {
  cout << "string2 comes first" << endl;
}
else {
  cout << "the strings are equal" << endl;
} // string 1 comes first, because lexographically 1 comes before 9 

// exercise
// Given following strings: which comes first in lexicographical order 45, 5, bob, Bob, and b.
// - if precedence rule is being followed, empty strings < numbers < uppercase letters < lowercase letters

// - there are no empty strings, which means first two strings must be either 45 or 5
// - C++ checks characters from left to right and since 4 comes before 5, 45 is considered to be ordered before 5

// - there is only one uppercase string, Bob, so Bob will be next in order

// - bob and b are left. 
// - since b has fewer characters, b will come before bob just like how it will in dictionary

// Solution:
// 45 
// 5
// Bob
// b 
// bob

//-----------------------------------------------------------------------------------------------------------//
// Exercise 1 
// construct from code blocks program.
string string1 = "CS is awesome!";
string string2 = "Computer Science is awesome!";

if (string1 == string2) {
  cout << "The two strings are equal." << endl;
}
else {
  cout << "The two strings are not equal." << endl;
}

// Exercise 2 
// Given following code snippet:
string string1 = "C++";
string string2 = "C";
string string3 = "C++";

// Select all of the following statements that will print 0.
cout << (string1 == string3) << endl;
cout << (string1 == string2) << endl; // false = 0
cout << (string1.compare(string3)) << endl; // 0 outputs with compare function = true
cout << (string1.compare(string2)) << endl;

// - return value of 0 represents two different things between operator == and function compare() 
// - with ==, return value of 0 means strings are not equal
// - return value of 0 means that the strings are equal when utilizing the compare() function

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// PROJECT
// Counting Uppercase and Lowercase Characters 
// - write a program that takes a string and prints out two messages
// - one message tells how many uppercase characters are in string, other message tells how many lowercase characters
// - program will ignore all numbers and special characters

// isupper() - Returns integer greater than 0 if character is uppercase, 0 if character is not
// islower() - Returns integer greater than 0 if character is lowercase, 0 if character is not
int lower_count = 0;
int upper_count = 0;
string my_string = "Roses are Red, Violets are Blue";

for (char ch : my_string)

// Checking for uppercase and lowercase 
// - it does not matter if you check for uppercase character first or check for lowercase character
// - else statement is not enough, because special character returns too 0
if (islower(ch)) {
  lower_count += 1;
  }
else if (isupper(ch)) {
  upper_count += 1;
  }


// - printing results 
cout << "There are " << lower_count << " lowercase characters." << endl;
cout << "There are " << upper_count << " uppercase characters." << endl;

// Whole code example 
int lower_count = 0;
int upper_count = 0;
string my_string = "Roses are Red, Violets are Blue";

for (char ch : my_string) {
if (islower(ch)) {
  lower_count += 1;
  }
else if (isupper(ch)) {
  upper_count += 1;
  }
}

cout << "There are " << lower_count << " lowercase characters." << endl;
cout << "There are " << upper_count << " uppercase characters." << endl;

//-----------------------------------------------------------------------------------------------------------//
// Exercise
// Given the following code snippet:
for (char ch : my_string) {
}
// What does ch represent?
// ch represents each character of my_string from left to right

//-----------------------------------------------------------------------------------------------------------//
// PROJECT 
// Reverse a String
// - write program that takes string and prints it in reverse order
string my_string = "The brown dog jumps over the lazy fox";

// String Iteration
// - start at the end of string and iterate back to front
// - enhanced for loop will not do that (it only iterates from left to right)
// - for loop should start at back my_string,length()-1 and run as long as index is greater than or equal to 0
// - after each iteration, iterating variable should also decrement by 1 to allow loop to reverse
for (int i = my_string.length()-1; i >= 0; i--)

// - reversing string comes down to taking character from end printing that first, then go backwards
my_string.at(i);

// Printing result
cout << my_string.at(i);
// xof yzal eht revo spmuj god nworb ehT

// Whole Code Example
string my_string = "The brown dog jumps over the lazy fox";

for (int i = my_string.length()-1; i >= 0; i--) {
  cout << my_string.at(i);
}

//-----------------------------------------------------------------------------------------------------------//
// Exercise
// String Properties
// All of the following are true regarding strings except:
// String literals can be manipulated using the at() function.
//-----------------------------------------------------------------------------------------------------------//


//-----------------------------------------------------------------------------------------------------------//
// PROJECT
// Swapping Case of Characters
// - write program that takes string and prints new string where all of uppercase letters become lowercase, and lowercase letters become uppercase

// Variables
string original_string = "THE BROWN DOG JUMPS over the lazy fox!";
string modified_string;

// String iteration  
for (char ch : original_string)

// String Functions 
// isLower() will be used
// isUpper() will be used

// Conditional 
// - test if character is lowercase
if (islower(ch))
// - if true apply uppercase to variable
modified_string += toupper(ch);
// - if false append lowercase to modified_string
else {
  modified_string += tolower(ch);
}
// - special characters have no effect with uppercase or lowercase

cout << "The original string is: " + original_string << endl;
cout << "The modified string is: " + modified_string << endl;
// - printing results 


// Whole code 
string original_string = "THE BROWN DOG JUMPS over the lazy fox!";
string modified_string;

for (char ch : original_string) {
  if (islower(ch)) {
    modified_string += toupper(ch);
  }
  else {
    modified_string += tolower(ch);
  }
}

cout << "The original string is: " + original_string << endl;
cout << "The modified string is: " + modified_string << endl;

// The original string is: THE BROWN DOG JUMPS over the lazy fox!
// The modified string is: the brown dog jumps OVER THE LAZY FOX!

//-----------------------------------------------------------------------------------------------------------//
// Exercise
// Changing to Upper or Lowercase
// - given following code snippet 
if (islower(ch)) {
  modified_string += toupper(ch);
}
// toupper(ch) converts lowercase characters in original string to uppercase
//-----------------------------------------------------------------------------------------------------------//

//-----------------------------------------------------------------------------------------------------------//
// PROJECT
// Count Vowels
// - write program that counts number of vowels that apper in string
// - vowels are: a, e, i, o, u 

// Variables
string my_string = "The Brown Dog Jumps Over The Lazy Fox";
char ch;
int count = 0;

// String iteration 
for (int i = 0; i < my_string.length(); i++) {
  ch = my_string.at(i);
}

//Checking for Vowel 
if (ch == 'a' || ch == 'e' || ch == 'i' || 
    ch == 'o' || ch == 'u' || ch == 'A' ||
    ch == 'E' || ch == 'I' || ch == 'O' ||
    ch == 'U') 

// Incrementing counter 
count += 1;

// Printing Result
if (count == 0) {
  cout << "There are no vowels in the string." << endl;
}
else if (count == 1) {
  cout << "There is 1 vowel in the string." << endl;
}
else {
  cout << "There are " << count << " vowels in the string." << endl;
}

// Whole code 
string my_string = "The Brown Dog Jumps Over The Lazy Fox";
char ch;
int count = 0;

for (int i = 0; i < my_string.length(); i++) {
  ch = my_string.at(i);
  if (ch == 'a' || ch == 'e' || ch == 'i' || 
      ch == 'o' || ch == 'u' || ch == 'A' ||
      ch == 'E' || ch == 'I' || ch == 'O' ||
      ch == 'U') {
    count += 1;
  }
}

if (count == 0) {
  cout << "There are no vowels in the string." << endl;
}
else if (count == 1) {
  cout << "There is 1 vowel in the string." << endl;
}
else {
  cout << "There are " << count << " vowels in the string." << endl;
}
// There are 9 vowels in the string.

// == vs. find_first_of() for Characters
// Why is == operator used over find_first_of() function when checking to see how many specific characters are in string?
// find_first_of() function will stop and return once character is found
//-----------------------------------------------------------------------------------------------------------//

//-----------------------------------------------------------------------------------------------------------//
// PROJECT 
// Replacing Vowels with * 
// - write program that takes string called my_string and returns string but with * in place of vowels
// - assume that vowels are upper and lowercase a, e, i, o, u. 
// - if my_string = "Hello", then your program will print "H*ll*"


int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  char ch;
  
  //add code below this line
int count = 0;

for (int i = 0; i < my_string.length(); i++) {
        ch = my_string.at(i);
        if (ch == 'a' || ch == 'e' || ch == 'i' || 
            ch == 'o' || ch == 'u' || ch == 'A' || 
            ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            my_string[i] = '*';
        }
    }
    
    cout << "Modified string: " << my_string << endl;

  //add code above this line
  
  return 0;
  
}

//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
// Exercises

// ----------
// Exercise 1 
// - write program that takes input from user and prints first character of input and last character with some context
// - if baseball is string, then program will output b is first character and l is last character
// - if cat is string, then c is first character and t is last character will be printed

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  char first = my_string.at(0);
  char last = my_string.at(my_string.length()-1);

  cout << first << " is the first character and " << last << " is the last character" << endl;

  //add code above this line
  
  return 0;
  
}

// ----------
// Exercise 2
// - write program that captures input from user, prints input string as many times as its length, and prints as many lines of it as length of input string
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  for (int i = 0; i < my_string.length(); i++) {
    for (int j = 0; j < my_string.length(); j++) {
      if (j == my_string.length()-1) {
        cout << my_string << endl;
      }
      else {
        cout << my_string;
      }
    }
  }

  //add code above this line
  
  return 0;
  
}
// - nested for loop, inner and outer loops will run for duration of string’s length
// - j reaches end of string, direct system to print string with newline

// ----------
// Exercise 3
// - program that accepts input from user and creates another string that contains either a u, l, or - for each character of original string 
// - use u when character is uppercase, and use l when character is lowercase, 
// - if character is neither uppercase nor lowercase, use -. 
// - print  original string first, then print modified string
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string original = (argv[1]);
  string modified;
  char ch;
  
  //add code below this line

  for (char ch : original) {
    if (isupper(ch)) {
      modified += 'u';
    }
    else if (islower(ch)) {
      modified += 'l';
    }
    else {
      modified += '-';
    }
  }
    
  cout << original << endl;
  cout << modified << endl;

  //add code above this line
  
  return 0;
  
}

// ----------
// Exercise 4 
// - write program that takes input without white spaces from user, prints first half of string on one line, and the second half on another. In the case of string that has odd number of characters, second line will have extra character
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  int mid = my_string.length() / 2;

  for (int i = 0; i < mid; i++) {
    cout << my_string.at(i);
  }
  cout << endl;

  for (int j = mid; j < my_string.length(); j++) {
    cout << my_string.at(j);
  }
  cout << endl;


  //add code above this line
  
  return 0;
  
}

// ----------
// Exercise 5 
// - program that captures input from user and swaps letters two at time in string
// - first two characters change places, third and fourth characters change places ...
// - assume that program will only take even number of characters, otherwise, there will be error
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  for (int i = 0; i < my_string.length(); i++) {
    if (i % 2 == 0) {
      cout << my_string.at(i + 1);
    }
    else {
      cout << my_string.at(i - 1);
    }
  }

  //add code above this line
  
  return 0;
  
}
