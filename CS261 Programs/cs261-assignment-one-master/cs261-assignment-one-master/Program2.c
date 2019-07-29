/* CS261- HW1 - Program2.c*/
/* Name: Faaiq Waqar
 * Date: 04/12/19
 * Solution description:
 * allocate:
 * using the malloc function, 10 spaces are allocated of the type student
 * struct, assigned when declared as a pointer; this value is then returned
 * so it can be assigned in the main.
 *
 * generate:
 * because generate requires that a random numebrical value and a random char
 * be assigned, we assign a seed using srand time null from the time.h library.
 * with this, we can randomy assign using the rand() function, using for loops
 * to eliminate the need for repetive calls. THe student scores are assigned
 * out of 100
 *
 * output:
 * using printf statements, variables are declared, and a for loop is used to loop
 * through the student elements, and, a printf is used to format tho output
 *
 * summary:
 * there are three main summary components. Minimum and maximum are found usin a for
 * loop to scan, and using a temp to store the min or max value for comparison use. the
 * average sums using a loop, then divides by the number of elements. A print f function
 * is used in order to output these.
 *
 * deallocate:
 * this uses an if to check allocation, and free to deallocate
 *
 * main:
 * lots of function calls
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* students = (struct student*) malloc(10 * sizeof(struct student));     	
     /*return the pointer*/
	return students;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
	srand(time(NULL));
	int i = 0;
	int j = 0;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 2; j++){
			students[i].initials[j] = rand() % 26 + 'A';
		}
		
		students[i].score = rand() % 101;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	int i = 0;
	int studentScore = 0;
	char studentInitialA = ' ';
	char studentInitialB = ' ';
	
	
	for(i = 0;  i < 10; i++){
		studentInitialA = students[i].initials[0];
		studentInitialB = students[i].initials[1];
		studentScore = students[i].score;

		printf("%d. %c%c %d \n",(i+1),studentInitialA,studentInitialB,studentScore);
	}
}

void summary(struct student* students){
	/*Compute and print the minimum, maximum and average scores of the ten students*/
	/*Minimum Computation*/
	int i = 0;
	int temp = 0;
	int maximum = 0;
	int minimum = 0;
	int average = 0;

	temp = students[0].score;

	for(i = 1; i < 10; i++){
		if(students[i].score < temp){
			temp = students[i].score;
		}
	}
	
	minimum = temp;

	/*Maximum Computation*/

	temp = students[0].score;

	for(i = 1; i < 10; i++){
		if(students[i].score > temp){
			temp = students[i].score;
		}
	}

	maximum = temp;

	/*Average Computation*/
	for(i = 0; i < 10; i++){
		average += students[i].score;
	}
	average /= 10;
	/*Printing*/

	printf("Minimum Value: %d \n",minimum);
	printf("Maximum Value: %d \n",maximum);
	printf("Average Value: %d \n",average);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if(stud)
		free(stud);
}

int main(){
	struct student* stud = NULL;
    /*call allocate*/
    	stud = allocate();
    /*call generate*/
    	generate(stud);
    /*call output*/
    	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    
    return 0;
}
