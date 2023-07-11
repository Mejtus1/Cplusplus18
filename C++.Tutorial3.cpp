//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//If statement 
//Conditionals are pieces of code that make a decision about what the program is going to do next.
//The most common conditional is the if statement.
/*
If statements in C++ must contain the following items:
The keyword if.
A boolean expression in parentheses, ().
Curly braces, {}, surrounding all lines of code that will run if the boolean expression is true.
*/
if (5 > 4) {
  cout << "I print 1st if true" << endl;
  cout << "I print 2nd if true" << endl;
}   
cout << "I will always print" << endl;  



//If statement 2.0
//If else statements checks to see if a condition is true, and then has specific
//actions that take place. (boolean expression false or true)
//we use else keyword after if inside {} curly braces
//more than boolean expression is written with elif
if (5 > 4) {
  cout << "Print me if true" << endl;//command to run if true
}
else {
  cout << "Print me if false" << endl;//command to run if false
}

if (5 > 6) {//6
  cout << "Print me if true" << endl;
}
else {
  cout << "Print me if false" << endl;
}//false runs 

if (5 > 6) //without curly braces code runs too, but it is a good practice to use them 
  cout << "Print me if true" << endl;
else 
  cout << "Print me if false" << endl;

//When are curly braces Mandatory 
//whenever we have more than one command that is associated with if or else 
if (10 % 2 == 0)
  cout << "10 is even" << endl;
else
  cout << "10 is odd" << endl;
  cout << "False" << endl; 
//more tha one command in if else statement without braces will not run the program progperly
//SAME CODE USING braces 
if (10 % 2 == 0) { // mandatory curly braces
  cout << "10 is even" << endl;
  cout << "True" << endl;
}
else { // optional curly braces
  cout << "10 is odd" << endl;
}
//else statement is associated with false condition, altrough it doesnt need it(if returns true/ not true so if if is false automatically is run else code block)


//If else statement
bool my_bool = true;
if (my_bool) {
  cout << "The value of my_bool is true" << endl; } //true 
else {
  cout << "The value of my_bool is false" << endl; } //false



//Testing multiple choices
//testing same variable multiple times, for this is used if-else statement
int grade = 62;     
                                   {} &&
if (grade < 60) {                         //IN THIS CASE the program checks every value 
    cout << "F" << endl; }                //no matter of the variable, or if it already
if (grade >= 60 && grade < 70) {          //found what it was looking for 
    cout << "D" << endl; }
if (grade >= 70 && grade < 80) {
  cout << "C" << endl; }
if (grade >= 80 && grade < 90) {
  cout << "B" << endl; }
if (grade >= 90 && grade <= 100) {
  cout << "A" << endl; }


int grade2 = 62;                      //The nested structure causes the program to jump out of 
if (grade < 60) {                     //the structure once the correct is found.
  cout << "F" << endl; }              //This is able to occur because the other if cases are 
else if (grade < 70) {                //inside the else statement , which will only run when 
  cout << "D" << endl; }              //the previous boolean expression is false.
else if (grade < 80) {
  cout << "C" << endl; }
else if (grade < 90) {
  cout << "B" << endl; }
else if (grade < 100) {
  cout << "A" << endl; }


//Exercises if else

//Exercise 1 (weather is windy, but not rainy or cold) What is the output ? 
if (rainy) { //rainy is main if statement 
  if (windy) { //althrough it is windy outside RAINY must be run before windy to be true
    cout << "Wear a rain jacket." << endl;
  }             
  else {
    cout << "Bring an umbrella!" << endl;
  }
}
else {
  if (cold) {
    cout << "You might need a coat." << endl;
  }
  else { //so code skips rainy if statement and goes straight to else 
    cout << "Enjoy your day!" << endl;
  }
}

//Exercise 2 
bool sunny = true;
bool hot = false;
bool humid = true;

if (sunny) { //sunny true
  if (hot && humid) { //doesnt run because AND condition and it is not hot 
    cout << "Stay hydrated and wear sunscreen!" << endl;
  }
  else if (hot) {
    cout << "Stay cool and drink plenty of water." << endl;
  }
  else {
    cout << "Enjoy the sunshine!" << endl; //this code block runs 
  }
}
else {
  cout << "Have a great day!" << endl;
}



//-----------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------//
//Switch statement 
//The switch case statement is a way to make a decision with multiple possible outcomes. 
//Instead of nesting or sequencing many if statements.
int dayOfWeek = 3;
switch (dayOfWeek) { //wariable to be inside parenthesis, curly braces 

  case 1: cout << "Sunday"; //only prints if dayOfWeek == 1
          break;
  case 2: cout << "Monday"; //only prints if dayOfWeek == 2
          break;
  case 3: cout << "Tuesday"; //only prints if dayOfWeek == 3
          break;
  case 4: cout << "Wednesday"; //only prints if dayOfWeek == 4
          break;
  case 5: cout << "Thursday"; //only prints if dayOfWeek == 5
          break;
  case 6: cout << "Friday"; //only prints if dayOfWeek == 6
          break;
  case 7: cout << "Saturday"; //only prints if dayOfWeek == 7
          break;
  default: cout << "Invalid"; //only prints if none of the above are true
    
}
//there need to be a : after every case and break; after every case 
//very last case is used default: 
//if break is removed there is a outputted more values at once 



//Switch vs if else
//C++ allows you to use either switch case or a series of else if statements to handle decisions with multiple outcomes. 
//There are a couple of reasons why you would use one method over the other.

//Else If is used for ranges of values 
//Switch Case is for specific values

//switch case can only check for equality (e.g. num == 5), so if you need to check for a 
//range of values (e.g. num > 50 && num <= 60), use else If instead.
int grade = 62;                           
int letterGrade = grade / 10;            //
switch (letterGrade) {
  case 10: case 9: cout << "A"; 
          break;                        //using switch for range of values is possible 
  case 8: cout << "B";                  //but using else if is much easier and precise
          break;
  case 7: cout << "C"; 
          break;
  case 6: cout << "D"; 
          break;
  default: cout << "F";
}

int grade3 = 62;                     //using else if for range of values 
if (grade3 < 60) {                     
  cout << "F" << endl; }            
else if (grade3 < 70) {                
  cout << "D" << endl; }              
else if (grade3 < 80) {
  cout << "C" << endl; }
else if (grade3 < 90) {
  cout << "B" << endl; }
else if (grade3 < 100) {
  cout << "A" << endl; }


//ELSE IF is used for handling multiple variables 
/*switch case can only compare against values - not variables. For example, if you wanted to 
compare the inputted day of the week with the current day of the week, you would need to use 
else if. switch case can handle values 
(dayOfWeek == "Sunday") but not variables (dayOfWeek == today).*/


//Switch exercise
switch (years) {
case 5: cout << "5 year award"; 
break;
case 10: cout << "10 year award"; 
break; 
case 20: cout << "20 year award"; 
break;
case 30: cout << "30 year award"; 
break;
default: cout << "You are not eligible for a longevity award this year";
}

//more execises on switch, else, and if 
//exercise1
//if statement executes ceratin conditions 
int x = 5;
if (x < 10) {
  cout << "Less than 10" << endl;
}

//exercise2
//if statement is false so other code runs 
int x = 20;
if (x < 10) {
  cout << "Less than 10" << endl;
}
    
cout << "And the program continues...";

//If statement inside of if statement 
//if statements can be used to test multiple conditions. 
//These conditions exist as boolean expressions inside the parentheses (). 
//In addition, an if statement can exist inside another if statement.
int age = 15;
if (age < 20) {
  if (age > 10) {
    cout << "Teenager";
  }
}

int age2 = 15;
if ((age2 < 20) && (age2 > 10)) {
  cout << "Teenager";
}

//if statements only run their specified command(s) if their boolean expression or 
//conditional evaluates to true. In addition, if statements can be nested within each other 
//and can be used to evaluate compound conditionals.




//IF else statement 
//The if else statement gives your program the ability to ask a question, perform certain actions
//if the answer is true, and then perform another set of actions if the answer is false.
int x = 10;
if (x > 50) {
  cout << to_string(x) + " is greater than 50" << endl;
}
else {
  cout << to_string(x) + " is less than 50" << endl; //is less than 50
}

//switch statement
//The switch case statement gives your program the ability to perform different actions 
//based on the value of a given variable.
int size = 3;
switch (size) {
  case 1: cout << "Short"; break;
  case 2: cout << "Tall"; break;
  case 3: cout << "Grande"; break;
  case 4: cout << "Venti"; break;
  case 5: cout << "Trenta"; break;
  default: cout << "Grande";
}





//Write a program that determines the month of the year based on the value of 
//a variable called month. The variable will be a number from 1 to 12.

//my solution 
if (month == 1) {
  cout << "January" << endl; 
  }
else if (month == 2) { 
  cout << "February" << endl; 
  }
else if (month == 3) { 
  cout << "March" << endl; 
  }
else if (month == 4) { 
  cout << "April" << endl; 
  }
else if (month == 5) { 
  cout << "May" << endl; 
  }
else if (month == 6) { 
  cout << "June" << endl; 
  }
else if (month == 7) { 
  cout << "July" << endl; 
  }
else if (month == 8) { 
  cout << "August" << endl; 
  }
else if (month == 9) { 
  cout << "Suptember" << endl; 
  }
else if (month == 10) { 
  cout << "October" << endl; 
  }
else if (month == 11) { 
  cout << "November" << endl; 
  }
else if (month == 12) { 
  cout << "December" << endl; 
  }
else 
  cout << "Error" << endl;


//official solution 
string monthString;
  switch (month) {
    case 1:  monthString = "January"; break;
    case 2:  monthString = "February"; break;
    case 3:  monthString = "March"; break;
    case 4:  monthString = "April"; break;
    case 5:  monthString = "May"; break;
    case 6:  monthString = "June"; break;
    case 7:  monthString = "July"; break;
    case 8:  monthString = "August"; break;
    case 9:  monthString = "September"; break;
    case 10: monthString = "October"; break;
    case 11: monthString = "November"; break;
    case 12: monthString = "December"; break;
    default: monthString = "Invalid month";
  }
  cout << monthString << endl;




//Final exercises (if else switch statements)
  /*Use the variable x as you write this program. x will represent a positive integer. Write 
  a program that determines if x is between 0 and 25 or between 75 and 100. If yes, print the
  message:_ is between 0 and 25 or 75 and 100, where the blank (_) will be the value of x. 
  The program should do nothing if the value of x does not fit into either ranges.       */
  //my solution 
  int x = 15;
   if (x >= 0 && x <= 25) {
    cout << to_string(x) << " is between 0 and 25 or 75 and 100" << endl;
    }
  else if (x >= 75 && x <=100) {
    cout << to_string(x) << " is between 0 and 25 or 75 and 100" << endl;
    }
  else{}

//example solution 
  if (((x >= 0) && (x <= 25)) || ((x >= 75) && (x <= 100))) { 
  cout << to_string(x) + " is between 0 and 25 or 75 and 100"; 
  }


//final exercise 2 
//Use the variable x as you write this program. x will represent a positive integer. Write a 
//program that determines if x is divisible by 5. If yes, print _ is divisible by 5, where the 
//blank (_) is the value of x. If no, print _ is not divisible by 5, where the blank (_) is the value of x.
//my solution
if (x % 5 == 0) {
  cout << to_string(x) << " is divisible by 5" << endl;
}
else {
  cout << to_string(x) << " is not divisible by 5" << endl;
}
//example solution was the same 



/*Use the variable x as you write this program. x will represent a positive integer. Write a 
program that determines if x is divisible by 5 and is an even number. If yes, print _ is 
divisible by 5 and even, where the blank (_) is the value of x. If no, print _ is not 
divisible by 5 or it is odd, where the blank (_) is the value of x
*/
if (x % 5 == 0 && x % 2 == 0) {
    cout << to_string(x) << " is divisible by 5 and even" << endl;
    }
  else {
  cout << to_string(x) << " is not divisible by 5 or it is odd" << endl;
  }