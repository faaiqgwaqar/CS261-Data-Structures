/* CS261- HW1 - Program3.c*/
/* Name: Faaiq Waqar
 * Date: 04/12/19
 * Solution description:
 * sort:
 * I did not come up with this sort myself. I learned this sort in 162,
 * it is an insertion sort. it works by holding a temporarily, and going
 * along the chain of elements, sorting each one by one till the end of
 * the array
 *
 * main:
 * a seed is used so that random variables can be assigned. Then a loop
 * is used to create random assiggnments in a malloc assigned array. values
 * are printed unsorted, put into the sort function, and then printed again.
 * then memory is deallocated
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/
	int i = 0;	
	int j = 0;
	int temp = 0;

	for(i = 1; i < n; i++){
		temp = number[i];
		j = i - 1;
		
		while(j >= 0 && number[j] > temp){
			number[j+1] = number[j];	
			j--;
		}
		
		number[j+1] = temp;
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	srand(time(NULL));
	int n = 20;
	int i = 0;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int *array = (int*) malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
	for(i = 0; i < n; i++){
		array[i] = rand();
	}
    
    /*Print the contents of the array.*/
	printf("\nUnsorted Contents: \n");

	for(i = 0; i < n; i++){
		printf("%d\n",array[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(array,n);
    
    /*Print the contents of the array.*/
	printf("\nSorted Contents: \n");

	for(i = 0; i < n; i++){
		printf("%d\n",array[i]);
	}

	free(array);

    return 0;
}
