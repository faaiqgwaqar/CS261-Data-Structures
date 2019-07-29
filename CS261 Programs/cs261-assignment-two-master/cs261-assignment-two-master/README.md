# CS261 Assignment Two
Complete the missing functions in dynArray.c, stackapp.c, and bag2set.c. Submit only these three C files via TEACH (https://teach.engr.oregonstate.edu/)  by the deadline. 

You have to use the same names of files, functions, and variables as we specified in the skeleton code. This is because our grading will be automated, based on a test script which assumes that you use our dynArray.h, and that existing lines of code in  dynArray.c, stackapp.c, and bag2set.c are not modified.

Make sure your code compiles without errors using the provided Makefile on the ENGR server. 

 

## 2. Overview of HW2
Your task is to implement two data structures -- namely, stack and set. There are two main functions, one in stackapp.c  for implementing the stack, and the other in bag2set.c for implementing the set. This means that you will need to compile and test two separate executable files, as specified in Makefile.

The stack and set are implemented as dynamic arrays, where the implementation of a dynamic array is given in dynArray.c. That is, functions in stackapp.c and bag2set.c call directly some functions from dynArray.c. Your task is to complete the missing code in all three files dynArray.c, stackapp.c, and bag2set.c.

The two main functions in stackapp.c and bag2set.c provide some examples as to how to test your code. Use more alternative testing examples to check if you code works correctly. Note that the main function in stackapp.c  takes the input string of characters directly from the command line  when you execute the code.

 

## 3. Application of Stacks
Stacks can be used to check whether a mathematical expression has balanced parentheses ( ), braces { }, and brackets [ ]. For example, a balanced expression is "{(x + y), [x + (y + z)]}". An unbalanced expression: a) Closes an unopen parenthesis/brace/bracket; or b)  Closes a parenthesis/brace/bracket before closing the latest open parenthesis/brace/bracket; or c) Ends before closing all open parentheses/braces/brackets. For example, unbalanced expressions are "[x + (y + z)" or "[x + (y + z])".

Write the function int isBalanced(char* s) in stackapp.cPreview the document that returns 1 if the input expression is balanced, or 0 otherwise. Alternative solutions that produce correct results BUT DO NOT USE a stack will not receive credit.

Your function should read through the input string using the function nextChar(char* s), which has already been implemented for you. You may use the provided main function for testing your code. 

Note that you would need to fix the data type in dynArray.h as  #define TYPE char.

 

## 4. Convert a Bag into a Set
Complete the function that transforms a bag into a set in bag2set.cPreview the document. A set is a bag that does not have repeated instances of the same element. Your function void bag2set(struct DynArr *da) should call the functions that you implemented in dynArray.cPreview the document. In void bag2set(struct DynArr *da), you should also free the memory space allocated to the input bag, since the bag is not needed any more after exiting the function. 

Use the provided main function for testing your code.  Note that you would need to fix the data type in dynArray.h as #define TYPE double

 

## 5. Implementation of the Dynamic Array for Stack and Set
Complete the seven functions in dynArray.cPreview the document, listed below. Our comments in the code at the beginning of each of these functions will help you understand their purpose. 

void dynArrSetCapacity(DynArr *v, int newCap) 
void addDynArr(DynArr *v, TYPE val) 
void removeAtDynArr(DynArr *v, int idx) 
void removeDynArr(DynArr *v, TYPE val) 
void pushDynArr(DynArr *v, TYPE val) 
void popDynArr(DynArr *v) 
int containsDynArr(DynArr *v, TYPE val) 
 

## 6. Grading policy
The maximum number of points is 100.

All your code compiles without errors = 5 points
All your code runs without memory issues, but fails to give the correct output on all our test input examples for stacks and bags = 10 points
All your code for the stack application to balancing brackets runs without memory issues, but gives the correct output on:  
At least one out of our many test input examples of mathematical expressions = 30 points
                  or 

All but one test input example = 40 points
                 or

All test input examples = 60 points
All your code for converting bags to sets runs without memory issues, but gives the correct output on:
At least one out of our many test input examples of bags = 10 points
                 or

All test input examples = 25 points
