//for loops 
//for loops 
// this is a recurring pattern
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;
cout << "Hello" << endl;

//we can simplify this by for loop
for (int i = 0; i < 5; i++) {
  cout << "Hello" << endl;
}

//for loops function like code blocks, they also use boolean values 
//additionaly there is a incrementation, declaration and initialization of variable ITERATOR

for (int i = 0; i < 5; i++) {
  cout << "Loop #" << i << endl;
}
//C++ starts at 0 so 0 - 4 is outputted 
// i++ tells the system to keep adding up until i < 5 is reached and stops the loop

for (int i = 0; i < 5; i++) {
  cout << "Loop #" << i + 1 << endl; // i + 1 outputs every value + 1 
}

for (int i = 0; i < 6; i++) { //i < 6 = outputs 0 - 5 
  cout << "Loop #" << i  << endl;
}

for (int i = 0; i <= 5; i++) { //we can also use <= operator and the output will include 5 
  cout << "Loop #" << i << endl;
}

for (int i = 0; i <= 5; i--) { // we can change i++ to i--, but because no stop condition is 
  cout << "Loop #" << i << endl; //specified, the loop would run forever
}
