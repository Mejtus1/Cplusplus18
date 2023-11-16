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
