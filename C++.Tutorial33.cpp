// String length 
We have already seen strings in the "Fundamentals"section. We are going to dig a little deeper with this data type. All strings have the following characteristics:
Characters - Strings are made up of characters between quotation marks (previously covered in the “Fundamentals” section).
Length - Each string has a length (total number of characters).
Index - Each character in a string has a position, called an index.

To calculate the length of a string, use the length() function. 
This function will return an integer that is the sum of all of the characters between the quotation marks.

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

Although each character that you see on typical keyword usually has length of 1, 
there are other foreign characters that do not follow this convention. 
For example, Привет, which stands for Hello in Russian, actually has a length of 12 instead of 6.


String Index
Previously in the vectors module, we learned that vectors and arrays have elements that reside in certain positions or indices. 
A string too has indices that correspond to the position where each of its character resides. Like vector and array indices, string indices also start at 0.
STRING     " H e l l o ! "
INDICES      0 1 2 3 4 5 
Quotation marks are required to declare the value of a string. 
However, quotation marks are not a part of the string itself. 
That is why quotation marks are not counted with the length() function and why they do not have an index.