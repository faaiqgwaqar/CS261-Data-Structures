/* CS261 - HW1 - Program4.c*/
/* Name: Faaiq Waqar
 * Date: 04/16/18
 * Solution description:
 * sort:
 * the sort is comprised of 2 insertion sorts, which
 * contain a complexity of 0n^2... The first insertion sort
 * handles the first letter sort, and the second traverses and
 * reavalutes the seconf itials
 *
 * main:
 * user entry is using a scanf, and will intake an integer, 
 * and does error handling via a loop that only turns off with
 * propper input. this is stored in n and is allocated using malloc.
 * after this random ids are seeded and stored in the containers,
 * then printed, sent to the sort function, and are returned for printing.
 * At the end allocated memory is freed
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/     
	int i = 0;
	int j = 0;
	char temp1 = ' ';
	char temp2 = ' ';

	/*Insertion Sort, First Initial Only*/
	for(i = 1; i < n; i++){
		temp1 = students[i].initials[0];
		temp2 = students[i].initials[1];
		j = i - 1;
		
		while(j >= 0 && students[j].initials[0] > temp1){
			students[j+1].initials[0] = students[j].initials[0];
			students[j+1].initials[1] = students[j].initials[1];
			j--;
		}

		students[j+1].initials[0] = temp1;
		students[j+1].initials[1] = temp2;
		
	}
	
	/*Insertion Sort, Second Initial After the Fact*/
	for(i = 1; i < n; i++){
		temp1 = students[i].initials[0];
		temp2 = students[i].initials[1];
		j = i - 1;

		while(j >= 0 && students[j].initials[0] == temp1 && students[j].initials[1] > temp2){
			students[j+1].initials[1] = students[j].initials[1];
			j--;
		}
	
		students[j+1].initials[1] = temp2;
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	srand(time(NULL));
	int errHandle = 0;
	int n = 0;
	int i = 0;
	int j = 0;
	int studentScore = 0;
	char studentInitialA = ' ';
	char studentInitialB = ' ';
	
	/*User Entry and Error Handling*/
	printf("Enter A Value for Array Size: \n");
	while(errHandle == 0){
		scanf("%d", &n);
		printf("You Entered Value %d\n\n", n);

		if(n <= 0)
			printf("Invalid, Try Again\n");
	
		else
			errHandle = 1;
	}

    /*Allocate memory for n students using malloc.*/
	struct student* students = (struct student*) malloc(n * sizeof(struct student));
    	
    /*Generate random IDs and scores for the n students, using rand().*/
	for(i = 0; i < n; i++){
		for(j = 0; j < 2; j++){
			students[i].initials[j] = rand() % 26 + 'A';
		}
	
		students[i].score = rand() % 101;
	}

    /*Print the contents of the array of n students.*/
	printf("Unsorted List of Students: \n");

	for(i = 0; i < n; i++){
		studentInitialA = students[i].initials[0];
		studentInitialB = students[i].initials[1];
		studentScore = students[i].score;

		printf("%d. %c%c %d \n",(i+1),studentInitialA,studentInitialB,studentScore);
	}

    /*Pass this array along with n to the sort() function*/
	sort(students,n);  
 
    /*Print the contents of the array of n students.*/
    	printf("\nSorted List of Students: \n");

	for(i = 0; i < n; i++){
		studentInitialA = students[i].initials[0];
		studentInitialB = students[i].initials[1];
		studentScore = students[i].score;

		printf("%d. %c%c %d \n",(i+1),studentInitialA,studentInitialB,studentScore);
	}
    /*Free Up Space Allocated*/
	if(students)
		free(students);

    return 0;
}
