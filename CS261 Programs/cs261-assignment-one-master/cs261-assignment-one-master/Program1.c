/* CS261- HW1 - Program1.c*/
/* Name: Faaiq Waqar
 * Date: 4/12/19
 * Solution description:
 * Solution To Foo Function:
 * Increment A: When using a pointer address, incrementing an integer
 * requires that you use paranthesis aroung the subject pointer to 
 * manipulate it at its adress, and so this is done with a plus plus, 
 * meaning plus one.
 *
 * Decrement B: Similar to incrementing A, paranthesis encapsulate
 * the subject pinter and a minus minus is used as a decrement
 *
 * Assign A-B to C: Just arithmatic, using the values held in the
 * A and B pointers
 *
 * Return C: Use a return statement for variable C;
 *
 * Solution to Main Function:
 * Declaring three Integers and Randomizing: using the library time.h,
 * we can plant a random seed for rand using srand time null. Then, during 
 * the declaration of the three integers, using the rand function, select
 * between 0 through 10.
 *
 * Printing Values (both): using printf, integers are printed with
 * %d, and so, with that, formatting with /n for end lines, and descriptive
 * text.
 *
 * Passing the values: We want the addresses of X and Y to be passed into A
 * and B, and thus, we use the & operator to do so this isnt done with Z, because
 * it is passed be value
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */
	(*a)++;
    /* Decrement  b */
	(*b)--;
    /* Assign a-b to c */
	c = *a - *b;
    /* Return c */
	return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	srand(time(NULL));
	int x = rand() % 11;
	int y = rand() % 11;
	int z = rand() % 11;
	int fooReturn;
	
    /* Print the values of x, y and z */
	printf("Value X Before Foo is %d \n",x);
	printf("Value Y Before Foo is %d \n",y);
	printf("Value Z Before Foo is %d \n\n",z);

    /* Call foo() appropriately, passing x,y,z as parameters */
	fooReturn = foo(&x,&y,z);    

    /* Print the values of x, y and z */
 	printf("Value X After Foo is %d \n",x);
	printf("Value Y After Foo is %d \n",y);
	printf("Value Z After Foo is %d \n\n",z);
   
    /* Print the value returned by foo */
	printf("Value Returned By Foo is %d \n\n", fooReturn);	

    /* Is the return value different than the value of z?  Why? */
    /* No, Z and the return value are not the same. this is because, unlike
	 * x and y, z is passed in as a value, meaning foo is only manipulating a copy
	 * of z, and not z itself, and then passing back this manipulated version, but
	 * not manipulating the original z value*/

    return 0;
} 
