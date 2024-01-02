// Pointers
// - pointer is data type that stores memory address of another piece of data
// - pointers point to memory address of data that they are associated with (principle like arrays but in memory)

/*
  key                                    locker                locker
POINTER ---------------------------> MEMORY ADRRESS ----> Content = VALUE 
2458                                     2458                         18 
*/
// - pointer is like key that stores address of locker that it is associated with
// - also enables pointer to gain access to content of what’s inside locker
// - advantage of using pointer is that you do not need to worry about value of data that pointer is pointing to
// - if data ever changes its value, pointer will still be able to access new data as long as pointer still points to data’s memory address

// Pointer Declaration
// - all pointers have data type and name that they are referred to
// - To declare pointer, you need to have following syntax in order: 
// data type of pointer (e.g. int, string, etc.).
// asterisk symbol *
// name for pointer
int* p;
cout << p << endl;
int * p; 
int *p;
cout << p << endl;

// - asterisk symbol can be placed anywhere between end of data type and variable name

int *p = 2;
cout << p << endl;
// - pointers can only be assigned memory address, which is why trying to assign 2 to pointer will result in error
// - pointers that are not assigned memory address will have default output of 0, referred to as null pointers


// Pointer Reference
// - pointer can only be assigned memory address
// - they cannot be assigned values that are int, double, string, etc
// - memory address is denoted with "&"symbol, called reference operator, and they go in front of variable thataddress is associated with
int a = 2;
int* p = &a;
cout << p << endl;
// 0x7fff0a89c30c
// 0x7ffe3dfb55fc (after runned again)

// Memory is dynamic in C++ so whenever programs are compiled or executed again, 
// they will often output memory addresses that are different from before

// Though memory address is dynamic, once pointer has been assigned memory address, 
// that association remains until program is re-compiled or re-executed

//-----------------------------------------------------------------------------------------------------------//
// Dereference Operator
// Pointer Dereference
// - Every memory address holds value and that value can be accessed by using dereference operator
// - dereference operator is denoted by asterisk symbol * 
int a = 5; //regular int variable set to 5
int* p = &a; //int pointer points to a's memory address
cout << *p << endl; //dereference p to print its content
// 5

// - pointer can only be assigned memory address of variable that holds value of same type as pointer 
// - if &a is memory address of int variable, then you cannot assign it to string pointer (string* p = &a)
// Though memory address is dynamic, once pointer has been assigned memory address, that association remains until program is re-compiled or re-executed

// Pointer to another Pointer
// It is possible to have pointer point to another pointer 
// To assign memory address of pointer to new pointer, that new pointer must be denoted with two asterisk symbols **
int a = 5;
int* p = &a;
int** p2 = &p;
cout << *p << endl;
cout << **p2 << endl;
cout << *p2 << endl;
// 100
// 100
// 0x7ffd89604b14 (dereferenced value of old pointer)

// - Dereferencing new pointer to old pointer will return memory address of old pointer
// - if that pointer is dereferenced again, then value of variable that old pointer pointed to will be returned
// - For example, **p2 and *p both returned 5 because p2 points to p which points to which equals 5
/*
:----------------------------------------------------------------------:
:  Variable             Memory Address (&)           Content/Value (*) :
:   (int)a                00x0                             5           :
:   (int*) p              0x01                            0x00         :
:   (int**) p2            0x02                            0x01         :
:----------------------------------------------------------------------: */

int array[] = {24, 52, 97};
cout << *array << endl;
// 24 

//-----------------------------------------------------------------------------------------------------------//
// Exercise 
//---------------------------------------------------------------------
// * = pointer creation 
// p = pointer (pointer is declared by *)
// *p = created pointer p 
//---------------------------------------------------------------------
// & = memory address 
// &f = f memory address 
//---------------------------------------------------------------------
// ** = dereference (change from memory address to value of variable)
// ** 
//---------------------------------------------------------------------
int f = 7; 
int* p = &f; 
int* p1 = p;
cout << f << endl; // 7 (output of variable f)
cout << p << endl; // 0x7ffec87825bc (output of variable pointer p which points to memory address of variable f)
cout << *p << endl; // 7 ()
cout << p1 << endl;  // 0x7ffec87825bc (output p1 which refferences pointer p and its )
cout << *p1 << endl; // 7 
//-----------------------------------------------------------------------------------------------------------//
// Exercise 2 
// Determine what output will be for each of following
int a = 123;
int b = 456;
int* p1 = &a;
int* p2 = &b;
int** p3 = &p1;
// cout << b; , cout << *p1; , cout << *p2; , cout << *p3; , cout << **p3;
/*
b is not pointer and will simply return 456
*p1 will return 123 because p1 —> a whose value is 123
*p2 will return 456 because p2 —> b whose value is 456
*p3 will return a's memory address because p3 —> p1 whose value is a’s memory address
**p3 will return 123 because p3 —> p1 —> a whose value is 123
*/

//-----------------------------------------------------------------------------------------------------------//
// Array Memory Usage vs Pointers Memory usage 

char names[3][6] = { "Alan", 
                     "Bob", 
                     "Carol" };
                     
for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
  cout << names[i] << endl;
}
// Alan
// Bob
// Carol

// - when working with string of characters, last character is always special character known as null character 
// - this character is often referred as NUL or \0 
// - maximum character length within this array is 'C','a','r','o','l','\0', which has 6 characters 
// - this is why to be able to store all of characters, column index must be set to 6

/*
main
names	(without assigned values, we can see)
array
 0,0	 0,1	 0,2	 0,3	 0,4	 0,5
char? char? char? char? char? char?
 1,0	 1,1	 1,2	 1,3	 1,4	 1,5
char? char? char? char? char? char?
2,0	   2,1	 2,2	 2,3	 2,4	 2,5
char? char? char? char? char? char?
*/

/*
main
names	(with values)
array
0,0	      0,1	    0,2	    0,3	   0,4	    0,5
char'A' char'l' char'a' char'n' char'\0' char'\0'
1,0	      1,1	    1,2	     1,3	   1,4	  1,5
char'B' char'o' char'b' char'\0' char'\0' char'\0'
2,0	     2,1	    2,2	   2,3	   2,4	    2,5
char'C' char'a' char'r' char'o' char'l' char'\0'
*/
// - code above creates array of characters where row index [3] refers to three starting characters:
// A for Alan, B for Bob, and C for Carol, 
// - column index 6 refers to how many character each of rows can hold which also includes null characters (NUL or \0)
// - !!! Notice how null characters also take up memory space !!!

// - we cannot asign to this array new name which would be longer that specified array, 
// - in case of needing larger array we create already larger array which leads to memory loss 


// Pointer Usage in above case 
// - this is where pointers come in handy because they can help system save memory
// - when using pointers for character arrays, pointers will only point to 3 leading characters A, B, and C
// - you do not need to specify column index
// - C++ requires keyword const for pointers thatpoint to characters within array
// - this forces characters to remain intact and prevents pointer from potentially pointing elsewhere
const char* names[] = { "Alan", 
                         "Bob", 
                         "ChristopherJones" };
                     
for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++) {
  cout << names[i] << endl;
}
// Alan
// Bob
// ChristopherJones
// - no need to include any index values, which means potential for wasting memory can be avoided
// - only reserved enough memory is needed to create 3 pointers 

/*
array
0	        1	      2	      3	      4
char'A' char'l' char'a' char'n' char'\0'
(this is in read-only storage, not the heap)

array
   0	     1	     2	     3
char'B' char'o' char'b' char'\0'
(this is in read-only storage, not heap)

array
   0	     1	     2	    3	      4	      5	       6	    7	      8	      9	      10	    11	    12	    13	    14	    15	    16
char'C' char'h' char'r' char'i' char's' char't' char'o' char'p' char'h' char'e' char'r' char'J' char'o' char'n' char'e' char's' char'\0'
*/

//-----------------------------------------------------------------------------------------------------------//
// Exercise 1 
// Dereference Message
// Fill in blanks below so that when printed, output message will be:
// ILoveComputerScience
string a = "I";
string b = "Love";
string c = "Computer";
string d = "Science";

string* p1 = &c;
string* p2 = &b;
string* p3 = &d;
string* p4 = &a;

cout << *p4;
cout << *p2;
cout << *p1;
cout << *p3;

// Exercise 2 
// Construct program using code blocks below so that 3.14 will be printed
double pi = 3.14;
double* p = & pi;
cout << *p;

//-----------------------------------------------------------------------------------------------------------//
// Pointers 
// - store memory address of particular variable
// - store the memory address of a particular variable
// - two important operators associated with pointers are reference & and dereference operators *
// - & operator returns memory address of variable and 
// - * operator returns value or content of variable being pointed to
bool b = true;
bool* p = &b;

cout << p << endl; //prints b's memory address
cout << boolalpha << *p << endl; //prints b's value
// 0x7fffc4649def
// true

// A pointer can also point to another pointer.
// - when doing so, new pointer will be denoted with two asterisk symbols **
// - ** is used to dereference pointer to variables value 
bool b = true;
bool* p = &b;
bool** p2 = &p; //p2 points to p

cout << p2 << endl; //prints p's memory address
cout << *p2 << endl; //prints p's content which is b's address
cout << boolalpha << **p2 << endl;
//p2 is dereferenced twice to print b's value
// 0x7ffda898eb38
// 0x7ffda898eb37
// true
cout << p << endl; // 0x7fffca244597
cout << *p << endl; // true
cout << **p << endl; // NOT EXIST we cannot derefference 3 times 

//exercise
// Fill in code below so that pointer p2 becomes associated with integer variable age and when printed, value of age is outputted
int age = 12;
int* p1 = &age; // points memory value of variable age and saves it to p1
                // p1 pointer holds value of 
int** p2 = &p1; // p2 pointer is derefferenced twice (points to memory value of )
// - first dereference will return memory address that p1 is pointing to, which is age's memory address
// - second dereference will return value of age which is 12
cout << **p2 << endl; 

// Main Exercise 
// You are trying to come up with set of pointers or keys that, when referred to, will be able to tell you age of each of your family members
// For example, the pointer amy should be associated with the variable age1.

 int age1 = 12;
  int age2 = 31;
  int age3 = 29;
  int* amy;
  int* bob;
  int** carol;
  
  //add code below this line
  
  
  amy = &age1;
  bob = &age2;
  
  int* p = &age3;
  carol = &p;
  
  cout << *amy << endl; //do not edit
  
  cout << *bob << endl; //do not edit
  
  cout << **carol << endl; //do not edit
  
  cout << "Amy's age is: ";
  cout << *amy << endl; //do not edit
  cout << "Bob's age is: ";
  cout << *bob << endl; //do not edit
  cout << "Carol's age is: ";
  cout << **carol << endl; //do not edit
  
  //add code above this line 
  
