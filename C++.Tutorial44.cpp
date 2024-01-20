// File Basics
// - This module is all about working with files
// - first step is to locate desired file, means being able to navigate file system
// - file we are going to use is called practice1.txt. 
// - it is located in text folder, which is inside folder called student
// - so file path is: student/text/practice1.txt.

//     /
//     :
//     :----- code 
//     : 
//     :----- student :----- csv
//     :              :     
//     :              :----- text ----- practice.txt
//     :    
//     :----- settings

// - use string to represent file path
// - this string will be passed to direct system to open file
string path = "student/text/practice1.txt";

// 

//-----------------------------------------------------------------------------------------------------------//
// Opening and Closing Files
// - one of most common ways to open, close, read, and write files is to use ifstream or ofstream data type
// - ifstream is used to read data from files
// - ofstream is used to write to files
// - both of these data types can be accessed and utilized by including #include <fstream> in header of your code file

// exercise: open practice1.txt as specified from above using ifstream
#include <fstream>

string path = "student/text/practice1.txt";

ifstream file;
file.open(path); // Command was successfully executed

// - "Command was successfully executed" is returned, which isn’t very helpful
// - to know if file was opened successfully, conditions need to be set up: 

string path = "student/text/practice1.txt";

ifstream file;
file.open(path);
if (file.is_open()) {
  cout << "File successfully opened." << endl;
}
else if (!file.is_open()) {
  cout << "File failed to open." << endl;
}

// primitive file existing script
string path = "student/text/practice1.txt";

ifstream file;
file.open(path);
if (file) {
  cout << "File exists." << endl;
}
else if (!file) {
  cout << "File doesn't exist." << endl;
}

// - before your program terminates, it is best practice to close file 
// - when file is opened, it takes up memory that will not free up until file is properly closed

string path = "student/text/practice1.txt"; // setting file path

ifstream file; //create a read-only data stream
file.open(path); //open the file as a stream
if (file) { //check if file exists
  cout << "File successfully opened." << endl;
}
else if (!file) { //check if file does not exist
  cout << "File failed to open." << endl;
}
file.close(); //close the file

//--------------------
// File Error Handling
// - basic template of code that returns specified errors to user when certain actions are not successful. 
// - if the user tries to open file and that file doesn’t exist (i.e. try block) 
// - system will throw error (i.e. throw block), and finally catch and print that error (i.e. catch block)
string path = "student/text/practice1.txt";

try { //try these actions
  ifstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open."); //throw error
  }
  file.close();
  cerr << "File successfully opened and closed." << endl;
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// File successfully opened and closed

string path = "student/text/practice2.txt";

try { //try these actions
  ifstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open."); //throw error
  }
  file.close();
  cerr << "File successfully opened and closed." << endl;
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
} 
// File failed to open 

// - with error messages being printed, cerr is preffered more than cout 
// - cerr = not bufferred, it is not stored in memory to be later printed on, it is only printed immediately

//-----------------------------------------------------------------------------------------------------------//
// Reading File
// Let’s start reading from a file that contains some text. 
// - First set the string path to student/text/readpractice.txt. 
// - Then open the file and handle any opening errors. 
// - To read from a file, use the getline() function. 
// - The getline() has at least two parameters; 
//     the first is the input stream to read from and 
//     the second is a string to store what is read.

string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read; //create string to store what is read into
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  getline(file, read);
  cout << read;
  file.close();
  cerr << "File successfully opened and closed." << endl;
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// You’ll notice from above that the system printed File successfully opened and closed. 
// - first and then C++ was created by Bjarne Stroustrup. was printed. 
// - This is due to cerr being unbuffered, which means it gets printed immediately. 
// - cout is buffered, so it will store its content into memory before printing, which explains the delay. 
// - This doesn’t mean that cerr always gets printed first, it just depends on what on quickly cout stores its content.
