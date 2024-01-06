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


