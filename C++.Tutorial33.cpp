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
