# CS261 Assignment One
## Program 1
**In Program1.c, write the function int foo(int* a, int *b, int c) that is supposed to do the following:

Increment a
Decrement b
Assign (a - b) to c
Return the value of c.
In the main function, declare three integers  x, y, z, and assign to them random integer values in the interval [0,10], using rand(). Print the values of x, y, z. Call foo() by appropriately passing x, y, z, as arguments. Print out the values of x, y, z, after foo(), as well as the value returned by foo().

Grading of Program 1: maximum 10 points
Printing x, y, z before calling foo() =  1 point
Printing x, y, z after foo() = 4 points
Return value of foo() = 4 points
Comparison of the return value of foo()  and z =  1 point
 

## Program 2
**In Program2.c, write the following functions and demonstrate their functionality by calling them (in the given order) from the main function:

struct student* allocate() that allocates memory for 10 students, and returns the pointer.
void generate(struct student* students) that generates random initials and random scores for each of the 10 students, and stores them in the array students. To generate two initial letters of a student you may use the following code: char c1 = rand()%26 + 'A'; char c2 = rand()%26 + 'A'; where % indicates the modulo operation. The random score for each student should take values in the interval [0, 100].
void output(struct student* students) that prints the initials and scores of all students.
void summary(struct student* students) that prints the minimum score, maximum score and average score of the 10 students.
void deallocate(struct student* students) that frees the memory allocated to students. Check that students is not NULL before you attempt to free it.
 

Grading of Program 2: maximum 25 points
Allocate  = 5 points
Generate = 5 points
Output = 5 points
Summary = 5 points
Deallocate = 5 points
 

## Program 3
**In Program3.c, write the function void sort(int* numbers, int n) to sort an array of n integers in the ascending order. In the main function:

Declare an integer n. Allocate memory for an array of n integers using malloc. Fill this array with random numbers using rand(). Make sure that you can handle the case when n=0.
Print the contents of the array.
Pass this array along with n to sort().
Print the contents of the sorted array after sort().
Grading of Program 3: maximum 25 points
Creation of the array of random numbers = 10 points
 Correctly sorted array of numbers in the ascending order = 15 points
 

## Program 4
**In Program4.c, we will consider the structure student from Program2.c. Modify the function sort() from Program3.c to sort an array of n students based on their initials. The function prototype is void sort(struct student* students, int n). In sort(), if two students have the same first initial, you should compare their second initial. As in Program2.c, initials and scores of students are to be generated randomly by rand(). Make sure that you can handle the case when the user provides input n=0.


Grading of Program 4: maximum 40 points
Sorts an array of student structures correctly = 40 points
A penalty of negative 10 points if your code does not correctly address the case when two students have the same first initial.
A penalty of negative 10 points if your code does not correctly address an empty array of students.
