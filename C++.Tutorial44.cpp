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
// File successfully opened and closed.
// C++ was created by Bjarne Stroustrup.

// - notice from above that system printed File successfully opened and closed
// - first and then C++ was created by Bjarne Stroustrup was printed 
// - this is due to cerr being unbuffered, which means it gets printed immediately
// - cout is buffered, so it will store its content into memory before printing, which explains delay
// - this doesn’t mean that cerr always gets printed first, it just depends on what on quickly cout stores its content

// - If you take look at content of file, you’ll see that it has more text than just C++ was created byBjarne Stroustrup.
// - reason why only one line of text was printed is because getline() only reads up until newlinecharacter is reached
// - to continue to read more lines of text, wrap getline() inside while loop

1. 

string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read; //create string to store what is read into
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    cout << read; 
  }
  file.close();
  cerr << "File successfully opened and closed." << endl;
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// File successfully opened and closed.
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

cout << read << endl;
// - file successfully opened and closed was printed at two different locations before and after << endl was added
// - this depends on how quickly cerr and cout work behind scenes
// - to avoid inconsistencies in printing, we’ll avoid printing success message moving forward

// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.
// File successfully opened and closed.

2. 

string path = "student/text/readpractice.txt";

try {
  ifstream file;
  char ch; //create string to store what is read into
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (file.get(ch)) {
    cout << ch;
  }
  file.close();
  cerr << "File successfully opened and closed." << endl;
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// File successfully opened and closed.
// The official mascot for C++ is a rat named Keith.

// - get() function in new code works similarly to getline() function
// - however, get() reads character by character instead of by strings

//-----------------------------------------------------------------------------------------------------------//
// Reading a Buffer
// - getline() and get() functions require variable to store its content 
// - if all you want to do is to read file however, then variable becomes useful and simply takes up extra memory 
// - when file is opened, its content is buffered or stored in memory until it gets closed 
// - during this buffering stage, you can use function rdbuf() to read content of file without having to create any variables

string path = "student/text/readpractice.txt";  

try {
  ifstream file;
  file.open(path); //content of file goes into memory buffer
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  cout << file.rdbuf(); //read the buffered content
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

//-----------------------------------------------------------------------------------------------------------//
// Delimiters
// - delimiters are predefined character that separates one piece of information from another 
// - some common delimiters involve white spaces (' ') and commas (',')
// - when using getline() previously, we only made use of two of its parameters
// - it actually has third parameter which is reserved for delimiter
// - by default, this delimiter is newline character ('\n'), thus parameters for getline(x, y, z) are:
// a) stream source (x)
// b) string variable to store what is read (y)
// c) delimiter to separate the content of the stream source (z)

// -specify getline() function to use comma as delimiter
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  getline(file, read, ','); //specify comma as delimiter
  cout << read;
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October

// Full file format 
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

// - when delimiter is applied, system will read only up to that delimiter
// - this is why you only see content up through first comma occurrence 
// - if you want to continue reading further and get to other comma occurrences, you can put command inside while loop
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ',')) { //specify comma as delimiter
    cout << read;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October 1985.
// Version 20 was released in December 2020.
// The official mascot for C++ is a rat named Keith.

// - code above continues to read stream and separates content via delimiter, ,
// - this is why there are no commas present in output 
// - however, it doesn’t look very clear that stream has been separated since system continues to print remainder of stream 
// - you can add << endl to output so that system will print newline after each delimiter is reached so that you can see clearer where content is separated

// File content 
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ',')) { //specify comma as delimiter
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October
// 1985.
// Version 20 was released in December
// 2020.
// The official mascot for C++ is a rat named Keith.


// Changed delimeter argument to ' '
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ' ')) { //specify comma as delimiter
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++
// was
// created
// by
// Bjarne
// Stroustrup.
// It
// serves
// as
// an
// extension
// to
// the
// C
// language.
// The
// first
// commercial
// edition
// of
// C++
// was
// released
// in
// October,
// 1985.
// Version
// 20
// was
// released
// in
// December,
// 2020.
// The
// official
// mascot
// for
// C++
// is
// a
// rat
// named
// Keith.

// Changed delimeter to 'a'
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, 'a')) { //specify comma as delimiter
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// C++ w
// s cre
// ted by Bj
// rne Stroustrup.
// It serves 
// s 
// n extension to the C l
// ngu
// ge.
// The first commerci
// l edition of C++ w
// s rele
// sed in October, 1985.
// Version 20 w
// s rele
// sed in December, 2020.
// The offici
// l m
// scot for C++ is 
// r
// t n
// med Keith.

// Delimeter character set to '\n'
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, '\n')) { //specify comma as delimiter
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
  //add code above this line
  
  return 0;
  
}
// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

// Exercise
// Which of following characters is default delimiter parameter for function getline()?
// " "
// '\n'
// ' '
// ','
// - by default, getline() uses newline character '\n' as delimiter
// - to specify another delimiter, simply provide it as third argument for getline()
// - note that getline() only accepts character as delimiter, it cannot accept string
//-----------------------------------------------------------------------------------------------------------//
// Tokens
// - when we apply delimiter to break up stream or string, resulting separated strings are sometimes referred to as tokens
// - tokens are useful if you want to use their data for further analysis later on
// - you can store each token as element in vector in which you can extract further information from later on

// - names.txt contains first and last names of 5 individuals:
// Jason Seymore Jackie Simmons Jennifer Small Jane Smith John Smith

string path = "student/text/names.txt";
vector<string> names;
string last_name = "Smith";
int count = 0;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ' ')) {
    names.push_back(read);
  }
  file.close();
  for (int i = 0; i < names.size(); i++) {
    if (i % 2 == 1) {
      if (names.at(i) == last_name) {
        count++;
      }
    }
  }
  cout << "There are " << count << " people whose last name is Smith." << endl;
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// There are 2 people whose last name is Smith.

// - code above enables you to do several things:
// a) break stream into several tokens separated by white space
// b) store tokens into vector
// c) iterate through vector to count how many people have last name "Smith"

// Try to search for a first name such as "Jackie" instead?
string path = "student/text/names.txt";
vector<string> names;
string first_name = "Jackie"; //change variable to first name
int count = 0;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ' ')) {
    names.push_back(read);
  }
  file.close();
  for (int i = 0; i < names.size(); i++) {
    if (i % 2 == 0) { //start checking index 0 and then every other index
      if (names.at(i) == first_name) { //first name found
        count++;
      }
    }
  }
  cout << "There are " << count << " people whose first name is Jackie." << endl;
} //change the print statement as needed

catch (exception& e) {
  cerr << e.what() << endl;
}
// There are 1 people whose first name is Jackie.

// --------------------------
// Applying Another Delimiter
// - if you need to further break down your tokens, you can use nested loop to iterate through those tokens to break them down even further
// - list of names was organized like this:
// Jason Seymore 
// Jackie Simmons 
// Jennifer Small 
// Jane Smith 
// John Smith

// - then using code above will cause issues since it only takes white space as delimiter, not newline
// - to include both newline and white space as delimiters, you can use stringstream data type (#include <sstream>) to create another string stream off of string variable read
// - first getline() function will separate stream using newline as delimiter and second getline() will use white space as delimiter
string path = "student/text/names2.txt";
vector<string> names;
string last_name = "Smith";
int count = 0;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) { //newline delimiter
    stringstream ss(read); //create a string stream of read
    while (getline(ss, read, ' ')) { //white space delimiter
      names.push_back(read);
    }
  }
  file.close();
  for (int i = 0; i < names.size(); i++) {
    if (i % 2 == 1) {
      if (names.at(i) == last_name) {
        count++;
      }
    }
  }
  cout << "There are " << count << " people whose last name is Smith." << endl;
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// There are 2 people whose last name is Smith.

// - if path is changed to names.txt, output will be same. 

// Exercise 
// Tokenizing Stream
// - Rearrange code blocks below so that system will tokenize stream file using newline character \n as first delimiter and then comma , as second
while (getline(file, read)) { 
  stringstream ss(read);
  while (getline(ss, read, ',')) {
    cout << read << endl;
  }
}
//-----------------------------------------------------------------------------------------------------------//
// The Ignore Function
// - ignore function takes integer as parameter, and causes C++ to go to specific character in text file
// - integer is index for text file, ignore(0) is first character of file, ignore(1) is second character, etc

// 1. 
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// C++ was created by Bjarne Stroustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

// 2. 
// - C++ will ignore first 29 characters and start reading only from character at position 30
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file.ignore(30); //ignore all chars before index 30
  while (getline(file, read)) {
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// ustrup.
// It serves as an extension to the C language.
// The first commercial edition of C++ was released in October, 1985.
// Version 20 was released in December, 2020.
// The official mascot for C++ is a rat named Keith.

// 3. 
// - set ignore argument to 40
// - changes starting position 41 position 

// 4. 
// - set ignore argument to 400
string path = "student/text/readpractice.txt";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file.ignore(400); //ignore all chars before index 30
  while (getline(file, read)) {
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Command was successfully executed.

// - text file only has 242 characters total, which include white spaces and newlines
// - ignoring all characters before index 400 is like ignoring entire file
// - nothing gets read or printed which is why system returned Command was successfully executed

// Exercise 1 
// - select all of following code snippets that will print all of content of file text.txt
// a) ifstream file;
//    file.open("text.txt");
//    cout << file.rdbuf();
//    file.close();
// 
// b) ifstream file;
//    char ch;
//    file.open("text.txt");
//    while (file.get(ch)) {
//    cout << ch;
//    }
//    file.close();
// 
// c) ifstream file;
//    string read;
//    file.open("text.txt");
//    while (getline(file, read)) {
//    cout << read << endl;
//    }
//    file.close();
// 
// d) ifstream file;
//    string read;
//    file.open("text.txt");
//    getline(file, read);
//    cout << read;
//    file.close();

// a), b), c) are correct, d) reads only one line of code, so it is incorrect 


// Exercise 2 
// Fill in code snippet so that string stream file is read, then tokenized using dash '-' as delimiter, and finally tokens are printed
try {
  
ifstream
 file;
  string read;
  file.
open
("text.txt");
  
while
 (getline(
file
, read, 
'-'
)) {
    cout << 
read
 << endl;
  }
  file.
close
();
}

//-----------------------------------------------------------------------------------------------------------//
// Writing to File
// - ofstream is used to write to a file 

string path = "student/text/practice1.txt";

try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file << "Hello there";
  file.close();
  cerr << "Finished writing to file.";
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// practice1.txt = Hello World


// - if file is successfully opened, you can start writing to file using insertion operator << followed by what you want to write in double quotes ""
// - to close file, and if you want, you can print message at end telling user that that file was successfully written to


string path = "student/text/practice1.txt";

try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file << "Goodbye";
  file.close();
  cerr << "Finished writing to file.";
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// practice1.txt = Goodbye 

// - delete this file and run command 
string path = "student/text/practice1.txt";

try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file << "";
  file.close();
  cerr << "Finished writing to file.";
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// 
// empty file is created 

//-----------------------------------------------------------------------------------------------------------//
// Reading a Written File
// - if you want to read from file after it was written to, you can create ifstream to read from file

string path = "student/text/practice1.txt";

try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file << "Hello there";
  file.close();
  
  ifstream stream;
  string read;
  stream.open(path);
  while (getline(stream, read)) {
    cout << read << endl;
  }
  stream.close();
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// Hello there


// Change "Hello there" to "Hi!".
// Add file << " My name is AI." << endl; to line after file << "Hi!"; string path = "student/text/practice1.txt";
try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file << "Hi";
  file << " My name is AI." << endl;
  file.close();
  
  ifstream stream;
  string read;
  stream.open(path);
  while (getline(stream, read)) {
    cout << read << endl;
  }
  stream.close();
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// Hi My name is AI.

// Exercise 
// - which of following commands will write ¡Hola! to file called my_file?
// a) cout << my_file;
// b) cout << "¡Hola!";
// c) my_file.write("¡Hola!");
// d) my_file << "¡Hola!";

// right answer is d) 

//-----------------------------------------------------------------------------------------------------------//
// Multiline Strings
// - In addition to being able to write and output string literals (e.g. file << "Hi!";), 
// we can also write and output content of variables (e.g. file << var;)

string path = "student/text/practice2.txt";

try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  string text1 = "Hello, ";
  string text2 = "your balance is: ";
  string text3 = "12.34";
  file << text1 + text2 + text3;
  file.close();
  
  ifstream stream;
  string read;
  stream.open(path);
  while (getline(stream, read)) {
    cout << read << endl;
  }
  stream.close();
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// Hello, your balance is: 12.34
// practice2.txt = Hello, your balance is: 12.34

//-----------------------------------------------------------------------------------------------------------//
// Appending to File
// - every time file is opened using ofstream object, new file is always created, even if one already exists (system just overwrites existing file)
// - if you want to add to an existing file, you have to tell C++ to open the file in append mode

string path = "student/text/practice3.txt";

try {
  ofstream file;
  file.open(path, ios::app); //open file in append mode
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  string text = "Adding to the file.";
  file << text;
  file.close();
  
  ifstream stream;
  string read;
  stream.open(path);
  while (getline(stream, read)) {
    cout << read << endl;
  }
  stream.close();
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}

// - since there is no practice3.txt file at start ofprogram, C++ will create one
// - notice that output Adding to file shows up twice in file
// - this happens because we have included tag ios::app as second parameter when we opened up file practice3.txt. 
// - ofstream object has flag ios::out as second parameter, which causes file to always get overwritten
// - by changing parameter to ios::app, we’re telling system to add to file instead of overwriting it

// - if you follow through challenges above, you’ll notice that when flag is set to input mode ios::in, 
// system will overwrite content without creating new file or overwriting old one
// - ios::app will add to end of existing content 
// - ios::out creates completely new file and writes to it

// Exercise 1 
// - fill in code snippet below so that file is read from and then content of it is written to file2

string path = "student/text/readpractice.txt";
string path2 = "student/text/readpractice2.txt";

ifstream file;
ofstream file2;
string read;
  
file.open(path);
file2.open(path2);
while (getline(file, read)) {
  file2 << read << endl;
}
  
file.close();
file2.close();

// - from existing code, you know that file is ifstream object while file2 is ofstream object
// - that means you’ll need to read from file, store its content into variable, and then write that content into file2
// - variable storing content should be string variable in order to hold all of characters
// - read is of type string
// - before reading and writing can happen, you have to open files first and give them appropriate string path
// - then iterate through ifstream file and store content into read
// - this can be accomplished using while (getline(file, read))
// - to write content to ofstream file2, use insertion operator and choose read as content variable, file2 << read << endl;
// - this will write everything that was stored in read to file2
// - finally, close() files to clear memory


// Exercise 2 
// Drag and arrange the code blocks below so that the following is written to text.txt:
// Writing to files
// is fun!

ofstream file;
file.open("text.txt");
file << "Writing to files" << endl << "is fun!";

// - to write to file, you need to create ofstream object instead of ifstream
// - then open appropriate file using file.open("text.txt")
// - Finally, use insertion operator to write desired message to file, file << "Writing to files" << endl << "is fun!"
// - note that endl is newline character, which is needed to write expected content
// - file << "Writing to files" and file << "is fun!" do not contain newline character, making them incorrect choices

// CSV Files 
// - C++ can work with files besides just text files
// - Comma Separated Value (CSV) files are example of commonly used file format for storing data
// - CSV files are similar to spreadsheet in that data is stored in rows and columns
// - each row of data is on its own line in file, and commas are used toindicate a new column
// - CSV can be red in same way you read text file
// - create ifstream object and then open CSV file using it

string path = "student/csv/monty_python_movies.csv";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ',')) {
    cout << read + ' ';
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Movie Title Rating
// Monty Python and the Holy Grail 5
// Monty Python's Life of Brian 4
// Monty Python Live at the Hollywood Bowl 4
// Monty Python's The Meaning of Life 5 

// - to iterate through CSV file, we use while (getline(file, read, ','))
// - since CSV files contain commas that separate information, we set delimiter to ','
// - print content by using cout << read + ' '
// - add space to separate tokens from each other since it is not apparent that information is tokenized from using just cout << read;

string path = "student/csv/monty_python_movies.csv";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ',')) {
    cout << read;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Movie TitleRating
// Monty Python and the Holy Grail5
// Monty Python's Life of Brian4
// Monty Python Live at the Hollywood Bowl4
// Monty Python's The Meaning of Life5

// - by using cout << read << endl; each token line by line 
// - depending on your preference, you can choose to arrange tokens in variety of different formats

// Ignoring Header
// - first row of CSV file is helpful because header values provide context for data
// - first row is not useful if you want to know how many rows of data there are, or to calculate avg value, etc
// - also can be used ignore() function to skip specific number of characters

string path = "student/csv/monty_python_movies.csv";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file.ignore(19); //Ignore the first 19 characters from index 0-18
  while (getline(file, read, ',')) {
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// Monty Python and the Holy Grail
// 5
// Monty Python's Life of Brian
// 4
// Monty Python Live at the Hollywood Bowl
// 4
// Monty Python's The Meaning of Life
// 5

string path = "student/csv/monty_python_movies.csv";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file.ignore(500, '\n'); //Ignore the first 500 characters until newline 
  while (getline(file, read, ',')) {
    cout << read << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Monty Python and the Holy Grail
// 5
// Monty Python's Life of Brian
// 4
// Monty Python Live at the Hollywood Bowl
// 4
// Monty Python's The Meaning of Life
// 5

// - file.ignore(500, '\n'); command tells system to skip first 500 characters or up through newline character \n 
// - since there are fewer than 500 characters, system will skip everything up through first occurrence of newline
// - you can add additional ignore commands to ignore more lines of data if needed

// Exercise 
// Ignoring Lines of Data
// Assuming maximum number of characters there are per line in CSV file, file, is 20 characters, which of following commands will ignore first three lines of data?

// a) file.ignore(20, '\n');
//    file.ignore(20, '\n');
//    file.ignore(20, '\n');
// b) file.ignore(60, '\n');
// c) file.ignore(20, '\n');
// d) file.ignore(0, '\n');

// a) is true answer 

// - newline characters are included in character count as well 
// - if maximum number of characters is 20, file.ignore(20, '\n'); will effectively ignore single line of text since each line contains 20 or fewer characters 
// - if line contains fewer than 20 characters, then newline will be reached
// - in either case, file.ignore(20, '\n'); three times will cause 3 lines of text to be ignored
// - file.ignore(0, '\n'); will not ignore any characters since 0 means that system will start reading from index 0. file.ignore(20, '\n'); 
// only ignores one line of text at most. file.ignore(60, '\n'); also ignores one line of text because the newline is reached before 60 characters are read

//---------------------------------------------------------------------------------------------------//
// Printing CSV Data
// - iterating over CSV file and printing each line does not produce visually pleasing output
// - code below produces three columns of data, but there is no consistency in spacing between columns
// - when printed, data looks very disorganized and difficult to read

string path = "student/csv/homeruns.csv";

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, ',')) {
    cout << read + " ";
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// Player Home Runs Active Player
// Barry Bonds 762 No
// Hank Aaron 755 No
// Babe Ruth 714 No
// Alex Rodriguez 696 No
// Willie Mays 660 No
// Albert Pujols 656 Yes
// Ken Griffey Jr. 630 No
// Jim Thome 612 No
// Sammy Sosa 609 No
// Frank Robinson 586 No 

// - to better organize our CSV data, we can store data into vector and then format and print elements in way that looks more organized

// - to organize our data, we use conditionals to split our elements into three columns
// - if (i % 3 == 0) refers to elements in first column, else if (i % 3 == 1) refers to second column, and else refers to the third 
// - we use setw() function to provide padding for our elements. 
// - setw(20) means that system will reserve 20 characters for elements, if element does not take up 20 characters, then white spaces will occupy those spaces. 
// - to use setw(), you’ll need #include <iomanip> in header of your file, left tag forces element to be aligned to left side

string path = "student/csv/homeruns.csv";
vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      data.push_back(read);
    }
  }
  file.close();
  for (int i = 0; i < data.size(); i++) {
    if (i % 3 == 0) {
      cout << setw(20) << left << data.at(i);
    }
    else if (i % 3 == 1) {
      cout << setw(15) << left << data.at(i);
    }
    else {
      cout << data.at(i) << endl;
    }
  }
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// Player              Home Runs      Active Player
// Barry Bonds         762            No
// Hank Aaron          755            No
// Babe Ruth           714            No
// Alex Rodriguez      696            No
// Willie Mays         660            No
// Albert Pujols       656            Yes
// Ken Griffey Jr.     630            No
// Jim Thome           612            No
// Sammy Sosa          609            No
// Frank Robinson      586            No


string path = "student/csv/homeruns.csv";
vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      data.push_back(read);
    }
  }
  file.close();
  for (int i = 0; i < data.size(); i++) {
    if (i % 3 == 0) {
      cout << setw(15) << left << data.at(i);
    }
    else if (i % 3 == 1) {
      cout << setw(10) << left << data.at(i);
    }
    else {
      cout << data.at(i) << endl;
    }
  }
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// IMPORTANT
// - order or placement of where you use left and setw() can affect all streams that follow 
// - it’s important to keep track of changes that take place as you print = outputting

//---------------------------------------------------------------------------------------------------//
// Writing to CSV Files
// - writing to CSV files is similar to writing to text file
// - create ofstream object to open CSV file
// - write to CSV file using insertion operator << 
// - to read CSV file, you can use same syntax that was previously shown

string path = "student/csv/writepractice.csv";

try {
  ofstream file;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file << "Greeting,Language" << endl;
  file << "Hello,English" << endl;
  file << "Bonjour,French" << endl;
  file << "Hola,Spanish";
  file.close();
  
  ifstream file2;
  string read;
  file2.open(path);
  while (getline(file2, read, ',')) {
    cout << read + ' ';
  }
  file2.close();
}
  
catch (exception& e) { //catch error
  cerr << e.what() << endl;
}
// Greeting Language
// Hello English
// Bonjour French
// Hola Spanish 

// - to organize CSV data, you can add each token into vector and then use conditionals to format and print data 

string path = "student/csv/writepractice.csv";
vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      data.push_back(read);
    }
  }
  file.close();
  for (int i = 0; i < data.size(); i++) {
    if (i % 2 == 0) {
      cout << setw(15) << left << data.at(i);
    }
    else {
      cout << data.at(i) << endl;
    }
  }
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Greeting       Language
// Hello          English
// Bonjour        French
// Hola           Spanish

// --------
// Exercise 
// Files Vocabulary
// Fill in each blank below with correct vocabulary term

// ifstream - object that can be used to read text or CSV files
// ofstream - n object that can be used to write to text or CSV files
// delimiter - predefined character that separates one piece of data from another
// token - piece of data that has been separated from its original content
// padding - number of character spaces reserved for piece of data

// ----------
// Exercise 2 
// - assume that variable path contains file path to CSV file and that string variable read has already been created
// - drag and arrange code blocks below to open and read file, tokenize what is read using comma as delimiter, and then print each token line by line 
// - finally, close file

ifstream file;
file.open(path);
while (getline(file, read, ',')) {
  cout << read << endl;
}
file.close();

// - to read file, you’ll need to create ifstream object first and then open file using that object, file.open(path)
// - CSV files contain commas, as you iterate through file, make sure to use comma as delimiter (while (getline(file, read, ','))) 
// - output tokens that are stored within read line by line using cout << read << endl;. 
// - close file with file.close().

//-----------
// Exercise 3 
// While reading from CSV file, you notice that output is not tokenized correctly, given following code: 
ifstream file;
string read;
file.open("data.csv");
while (getline(file, read)) {
  cout << read;
}
file.close();

// answer: delimiter defaults to newline since its parameter is not specified

// - if data is not tokenized properly, then delimiter is source of issue
// - notice how delimiter parameter is not specified in while (getline(file, read))
// - this means function will default to newline delimiter
// - since CSV files should be tokenized based on commas, correct syntax should be while (getline(file, read, ',')) instead

//---------------------------------------------------------------------------------------------------//
// Lab 1 

// - what happens if you want to go back to specific line of text? 
// - common practice that comes with reading text from file is to store that information into something like a vector
// - before reading file, create path variable with file path, and instantiate string vector text

string path = "student/labs/fileslab1.txt";
vector<string> text; // vector inilialized

// - use try, throw and catch blocks to handle input/output exceptions
// - in try portion, create ifstream object to read through file and store its content into string variable
// - add each line to vector text
// - print any errors in catch portion 
// - optionally print message that file has successfully been read, but that is not required

string path = "student/labs/fileslab1.txt";
vector<string> text;

try {                                                 // use try
  ifstream file;                                      // try portion, ifstream
  string read;                                        // store inside string variable 
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");      // use throw 
  }
  while (getline(file, read)) {
    text.push_back(read);                             // add each line to vector text 
  }
  file.close();
}
  
catch (exception& e) {                                // print any errors in catch portion 
  cerr << e.what() << endl;
}

// - content of text file now resides in vector variable text
// - code above only adds text from file into vector
// - to print what was stored in vector, use loop to iterate vector’s elements first followed by cout command
string path = "student/labs/fileslab1.txt";
vector<string> text;                                   // content resides 

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    text.push_back(read);
  }
  for (int i = 0; i < text.size(); i++) {              // loop to iterate through vectors elements 
    cout << text.at(i) << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Having had some time at my disposal when in London, I had visited the British Museum, and made search among the books and maps in the library regarding Transylvania; it had struck me that some foreknowledge of the country could hardly fail to have some importance in dealing with a nobleman of that country. I find that the district he named is in the extreme east of the country, just on the borders of three states, Transylvania, Moldavia and Bukovina, in the midst of the Carpathian mountains; one of the wildest and least known portions of Europe. I was not able to light on any map or work giving the exact locality of the Castle Dracula, as there are no maps of this country as yet to compare with our own Ordnance Survey maps; but I found that Bistritz, the post town named by Count Dracula, is a fairly well-known place. I shall enter here some of my notes, as they may refresh my memory when I talk over my travels with Mina.

// - there should be seen passage from Bram Stoker’s Dracula
// - output is just collection of text grouped together
// - if first element in vector would be printed, result will be same 
// - entire file was read and stored as first element in vector
// - default delimiter is newline and there is only 1 occurrence of newline at end of file

// - change delimiter into period . so that text will be tokenized into sentences
// - each token will represent one sentence from passage
string path = "student/labs/fileslab1.txt";
vector<string> text;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, '.')) { //set delimiter as a period
    text.push_back(read);
  }
  for (int i = 0; i < text.size(); i++) {
    cout << text.at(i) << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// Having had some time at my disposal when in London, I had visited the British Museum, and made search among the books and maps in the library regarding Transylvania; it had struck me that some foreknowledge of the country could hardly fail to have some importance in dealing with a nobleman of that country
// I find that the district he named is in the extreme east of the country, just on the borders of three states, Transylvania, Moldavia and Bukovina, in the midst of the Carpathian mountains; one of the wildest and least known portions of Europe
// I was not able to light on any map or work giving the exact locality of the Castle Dracula, as there are no maps of this country as yet to compare with our own Ordnance Survey maps; but I found that Bistritz, the post town named by Count Dracula, is a fairly well-known place
// I shall enter here some of my notes, as they may refresh my memory when I talk over my travels with Mina

// - passage is tokenized using period . as delimiter
// - when delimiter is specified, system extracts period from text, this is why you do not see periods in output
// - to put periods back into vector, simply include + '.' in push_back() statement
string path = "student/labs/fileslab1.txt";
vector<string> text;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, '.')) {
    text.push_back(read + '.'); //add period to end
  }
  for (int i = 0; i < text.size(); i++) {
    cout << text.at(i) << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// Having had some time at my disposal when in London, I had visited the British Museum, and made search among the books and maps in the library regarding Transylvania; it had struck me that some foreknowledge of the country could hardly fail to have some importance in dealing with a nobleman of that country.
// I find that the district he named is in the extreme east of the country, just on the borders of three states, Transylvania, Moldavia and Bukovina, in the midst of the Carpathian mountains; one of the wildest and least known portions of Europe.
// I was not able to light on any map or work giving the exact locality of the Castle Dracula, as there are no maps of this country as yet to compare with our own Ordnance Survey maps; but I found that Bistritz, the post town named by Count Dracula, is a fairly well-known place.
// I shall enter here some of my notes, as they may refresh my memory when I talk over my travels with Mina.

// - vector now includes 4 elements, each representing sentence from passage extracted from file fileslab1.txt
// - to bring focus to particular sentence, use at() function and specify position of sentence you are interested in

string path = "student/labs/fileslab1.txt";
vector<string> text;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, '.')) {
    text.push_back(read + '.');
  }
  cout << text.at(1); //print the second element/sentence
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// I find that the district he named is in the extreme east of the country, just on the borders of three states, Transylvania, Moldavia and Bukovina, in the midst of the Carpathian mountains; one of the wildest and least known portions of Europe.

// - to erase first leading white space, use text.at(1).erase(0, 1)
// - this will take system to first position, index 0, and erase just 1 character in that string

string path = "student/labs/fileslab1.txt";
vector<string> text;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read, '.')) {
    text.push_back(read + '.');
  }
  cout << text.at(1).erase(0, 1) << endl; //erase the first string char
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// I find that the district he named is in the extreme east of the country, just on the borders of three states, Transylvania, Moldavia and Bukovina, in the midst of the Carpathian mountains; one of the wildest and least known portions of Europe.

// Test Exercise 
// - file is tokenized into 5 tokens each separated by default newline delimiter
// - tokens are now stored in vector days and looks like this when printed:
// Monday
// Tuesday
// Wednesday
// Thursday
// Friday

// Which of the following commands will output Friday?
// c) cout << days.at(4); 
// (because elements in vector start at 0)

//---------------------------------------------------------------------------------------------------//
// Lab 2 
// - this lab uses comma delimited CSV file fileslab2.csv, which contains integers 
// - there are three columns and four rows
// - program below will print sum for each row in CSV
// - this is what file currently looks like:
// 1,4,5
// 18,34,99
// 0,12,51
// 37,29,61
// - direct path to a file, create vector to store data, create ifstream and string to read and hold content of file temporarily
// - use try, catch, throw code blocks to handle issues opening file 
string path = "student/labs/fileslab2.csv";
vector<string> nums;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// - after use getline() function to iterate through file and store its content as tokens in vector 
// - go through file twice and include stringstream object to further help tokenize data
string path = "student/labs/fileslab2.csv";
vector<string> nums;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      nums.push_back(read);
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    cout << nums.at(i) << endl;
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// 1
// 4
// 5
// 18
// 34
// 99
// 0
// 12
// 51
// 37
// 29
// 61

// - list of numbers after code runs 
// - Although you see numbers, they are currently strings which means we cannot do calculations on them directly 
// - strings must be converted into integers, using stoi()
// - data is stored in vector which is one dimensional but we want to calculate totals for multiple rows 
// - use double nested for loop to iterate through vector in chunks of three elements which will allow to calculate totals of each row
string path = "student/labs/fileslab2.csv";
vector<string> nums;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      nums.push_back(read);
    }
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

for (int i = 0; i < nums.size(); i+=3) {
  int total = 0;
  for (int j = 0; j < 3; j++) {
    total += stoi(nums.at(i + j));
  }
  cout << "Total: " << total << endl;
}
// Total: 10
// Total: 151
// Total: 63
// Total: 127

// Exercise - stringstream Object
// What is purpose of stringstream ss() in following code snippet?
while (getline(file, read)) {
  stringstream ss(read);
  while (getline(ss, read, ',')) {
    nums.push_back(read);
  }
}
// a) stringstream ss() enables system to temporarily store data so that data can be iterated over again

// - in order to iterate through file twice, stringstream object is created to temporarily store  data that was iterated first time so that it can be iterated again
// - in some instances, it might be necessary to tokenize stream twice using two different delimiters, which is why storing temporary data into stringstream object is very useful

//---------------------------------------------------------------------------------------------------//
// Lab 3 
// - goal of this lab is to rely on user input for data 
// - continuously ask user to enter name of superhero followed name of their power 
// - if user enters lowercase q, system will stop collecting data and write all of data collected to CSV file superheroes.csv

// - create our string path, ofstream object, read string, and exception blocks like usual
string path = "student/labs/superheroes.csv";

try {
  ofstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
// - create variables for our user input
// - additionally, continuously ask user for output until they enter q, after q is detected, information entered will be written to our CSV file
string path = "student/labs/superheroes.csv";
string name;
string power;

try {
  ofstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  
  while (true) {
    cout << "Please enter a superhero name (or enter q to quit): ";
    cin >> name;
    if (name == "q") {
      break;
    }
    cout << "Please enter a superhero power (or enter q to quit): ";
    cin >> power;
    if (power == "q") {
      break;
    }
    file << name << ',' << power;
  }
  
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

// Exercise - Overwriting vs. Appending
// - following code snippet causes system to create new files every time program is run
ofstream file;
file.open("data.csv");
// If you want to continue to add or append data to file instead of creating file, which of following commands would you use instead?
// a) file.open("data.csv", ios::app);

// - only file.open("data.csv", ios::app); will enable system to continue to add to content within file 
// - file.open("data.csv", ios::in); will overwrite content 
// - file.open("data.csv", ios::out); will create new file every time causing data to be lost
// - ifstream is used only for reading Files

//---------------------------------------------------------------------------------------------------//
// Lab Challenge 
// - write program that reads text file . this file is stored in variable path
// - file contains several instances of word Burma
// - replace each instance of Burma with Myanmar, and print results of this transformation
// - final output of your program should be:
// Myanmar is a country in Southeast Asia.
// The capital of Myanmar is Naypyidaw.
// Its population is about 54 million people.
// Myanmar is a former British colony.
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

void FindAndReplace(string& lines, string burma, string myanmar) {
  // Get the first string occurrence
  size_t pos = lines.find(burma);
  // Repeat till end of string
  while( pos != string::npos) {
    // Replace this occurrence of Sub String
    lines.replace(pos, burma.size(), myanmar);
    // Get the next occurrence from the current position
    pos = lines.find(burma, pos + myanmar.size());
  }
}

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

void FindAndReplace(string& lines, string burma, string myanmar) {
  // Get the first string occurrence
  size_t pos = lines.find(burma);
  // Repeat till end of string
  while( pos != string::npos) {
    // Replace this occurrence of Sub String
    lines.replace(pos, burma.size(), myanmar);
    // Get the next occurrence from the current position
    pos = lines.find(burma, pos + myanmar.size());
  }
}  

  //add code above this line
  
  return 0;
  
}

// - solution contains several steps:

// 1. Creates string variable lines to store final output.
// 2. Creates ifstream to open and store text file.
// 3. Creates string variable read to temporarily store buffered content.
// 4. Throws exception if file cannot be opened.
// 5. Iterates through file and stores tokens into read with newline delimiter.
// 6. Stores all of tokens into lines including newline character.
// 7. Closes file.
// 8. Performs function FindAndReplace() on string lines to replace Burma with Myanmar.
// 9. Prints final output lines.

week 4 4/4 

// Files Coding Exercises 

// Exercise 1 
// Problem:
// Write a program that reads a text file and returns the number of lines as well as the total number of characters in the file.
// Expected Output

// You may add additional helper functions if you’d like, but your program must include the following line of code:
// string path = argv[1];

// The variable path allows for different text files to be sent to your program for testing. The TRY IT button below will send a test file to your program. You should see the following output:
// 4 line(s)
// 228 character(s)

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

try {
  ifstream file;
  string read;
  int lines = 0;
  int chars = 0;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    lines++;
    chars += read.length();
  }
  file.close();
  cout << lines << " line(s)" << endl;
  cout << chars << " character(s)"; 
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}

    //add code above this line
  
  return 0;
  
}

// Guide:
// Create an ifstream object to open the file.
// Create a string read to store buffered data.
// Create 2 ints to keep track of the number of lines and characters.
// Iterate through the file and increment the number of lines by 1 every time a line is read; also increment the number of characters by the length of the line (which is also the number of characters).
// Print the appropriate results in the specified format.

//-----------
// Exercise 2 

// Problem
// Write program that reads comma delimited CSV file with four columns and returns the average of each column in the file. Assume that the CSV files used will only contain 3 rows and 4 columns.
// Expected Output
// The CSV file looks like the one below.
// 1,5,10,30
// 19,15,10,15
// 10,4,-2,15

// You may add additional helper functions if you’d like, but your program must include the following line of code:
// string path = argv[1];

// The variable path allows for different text files to be sent to your program for testing. The TRY IT button below will send a test file to your program. You should see the following output:
// 10 8 6 20
// Where 10 represents average of numbers in first column, 8 represents average of numbers in second column, etc.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      data.push_back(read);
    }
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
  
int col1 = 0;
int col2 = 0;
int col3 = 0;
int col4 = 0;
for (int i = 0; i < data.size(); i++) {
  if (i == 0 || i == 4 | i == 8) {
    col1 += stoi(data.at(i));
  }
  if (i == 1 || i == 5 | i == 9) {
    col2 += stoi(data.at(i));
  }
  if (i == 2 || i == 6 | i == 10) {
    col3 += stoi(data.at(i));
  }
  if (i == 3 || i == 7 | i == 11) {
    col4 += stoi(data.at(i));
  }
}
  
cout << col1 / 3 << " ";
cout << col2 / 3 << " ";
cout << col3 / 3 << " ";
cout << col4 / 3;

  //add code above this line
  
  return 0;
  
}

// Guide:
// Create a vector, ifstream, and string to read and store the data.
// Iterate through the file twice to tokenize the file into standalone strings. Note that you may need to create a stringstream object to iterate through the file a second time.
// Store the resulting tokens into the vector.
// Create four int variables to hold each column’s calculated average.
// Use a loop and four conditionals to align the correct numbers to the correct column and to add them accordingly. Remember to convert the strings into integers before adding.
// Divide each column’s sum by 3 to calculate its average and then print the result in the correct format.

//-----------
// Exercise 3 

// Problem: 
// Write a program that reads a text file and prints the contents in reverse order.

// Expected Output
// You may add additional helper functions if you’d like, but your program must include the following line of code:
// string path = argv[1];

// The variable path allows for different text files to be sent to your program for testing. The TRY IT button below will send a test file to your program. You should see the following output:
// The child still struggled and loaded me with epithets which carried despair to my heart; I grasped his throat to silence him, and in a moment he lay dead at my feet.
// ‘Frankenstein! you belong then to my enemy—to him towards whom I have sworn eternal revenge; you shall be my first victim.’
// ‘Hideous monster! Let me go. My papa is a syndic—he is M. Frankenstein—he will punish you. You dare not keep me.’
// ‘Boy, you will never see your father again; you must come with me.’
// He struggled violently. ‘Let me go,’ he cried; ‘monster! Ugly wretch! 

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read)) {
      data.push_back(read);
    }
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
  
for (int i = data.size() - 1; i >= 0; i--) {
  cout << data.at(i) << endl;
}

  //add code above this line
  
  return 0;
  
}

// Create a vector, ifstream, and string to read and store the data.
// Iterate through the file twice to tokenize the file into standalone strings. Note that you may need to create a stringstream object to iterate through the file a second time.
// Store the resulting tokens into the vector.
// Iterate through the vector by starting from the back of the vector and working to the front of the vector.
// Once printed, the elements will appear in reverse order.

//-----------
// Exercise 4 

// Problem
// Write a program that reads a tab ('\t') delimited CSV file and prints the name of the oldest person in the file. Assume that there are no two people with the same age.

// Expected Output
// The CSV file looks like the one below.
// Peter   38  Doctor
// Paul    41  Lawyer
// Mary    32  Systems Engineer

// You may add additional helper functions if you’d like, but your program must include the following line of code:
// string path = argv[1];

// The variable path allows for different text files to be sent to your program for testing. The TRY IT button below will send a test file to your program. You should see the following output:
// The oldest person is Paul.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, '\t')) {
      data.push_back(read);
    }
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
  
int max = 0;
string person;
  
for (int i = 1; i < data.size(); i+=3) {
  if (stoi(data.at(i)) > max) {
    max = stoi(data.at(i));
    person = data.at(i - 1);
  }
}
  
cout << "The oldest person is " << person << ".";

  //add code above this line
  
  return 0;
  
}

// Create a vector, ifstream, and string to read and store the data.
// Iterate through the file twice to tokenize the file into standalone strings. Note that you may need to create a stringstream object to iterate through the file a second time.
// Store the resulting tokens into the vector.
// Iterate through the vector starting with the first element and skipping through every 3 elements. Notice that these elements are in the second column where we want to extract the information from.
// Compare each element in the second column to max which was initialized to 0 at first. If the element (converted to an integer) is greater than max, then the element will become the new max value.
// During this process, the elements prior to max is also kept track of in the string person variable. If max gets updated, then the person who preceded max will become the value for the person variable.
// Print the appropriate data using the specified format.

//-----------
// Exercise 5

// Problem
// Write a program that reads a comma delimited CSV file and prints all of the cities which reside in the Southern Hemisphere. Note, any latitude with a negative value is south of the equator.

// Expected Output
// The CSV file looks like the one below.

// City,Country,Latitude,Longitude
// Beijing,China,39,116
// Perth,Australia,-57,115
// Port Moresby,Papua New Guinea,-25,147
// Tokyo,Japan,35,139

// You may add additional helper functions if you’d like, but your program must include the following line of code:
// string path = argv[1];

// The variable path allows for different text files to be sent to your program for testing. The TRY IT button below will send a test file to your program. You should see the following output:
// The following cities are in the Southern Hemisphere: Perth, Port Moresby.

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

vector<string> data;

try {
  ifstream file;
  string read;
  file.open(path);
  if (!file) {
    throw runtime_error("File failed to open.");
  }
  while (getline(file, read)) {
    stringstream ss(read);
    while (getline(ss, read, ',')) {
      data.push_back(read);
    }
  }
  file.close();
}
  
catch (exception& e) {
  cerr << e.what() << endl;
}
  
string cities;
cout << "The following cities are in the Southern Hemisphere: ";
  
for (int i = 6; i < data.size(); i+=4) {
  if (stoi(data.at(i)) < 0) {
    cities += (data.at(i - 2) + ", ");
  }
}
  
cities.pop_back();
cities.pop_back();
cities += ".";
  
cout << cities;

  //add code above this line
  
  return 0;
  
}

// Create a vector, ifstream, and string to read and store the data.
// Iterate through the file twice to tokenize the file into standalone strings. Note that you may need to create a stringstream object to iterate through the file a second time.
// Store the resulting tokens into the vector.
// Create a string to store the names of the cities.
// Print the output cout << "The following cities are in the Southern Hemisphere: ";
// Notice that we do not care about the headers in the first row so skip through those elements by iterating the vector starting from index 6. We really only care about the latitude column.
// While iterating the latitude column, check if the converted integer element is less than 0. If so, store the name of the city with that latitude into the string variable followed by a comma.
// Since the last city’s name will end in a period instead of comma and space, we cannot use the pop_back() function to remove the last two characters. Then append a period to the string variable.
// Finally, print the string variable which now includes all of the cities’ names in the correct format.