# CS Software Development Bonus
## 1. General Instructions
In this assignment, you will implement a "to-do list" application with a Heap-based Priority Queue. The application allows the user to manage their prioritized to-do lists using console commands for operations such as adding new tasks, retrieving, or removing the highest priority task. Additionally, the user can save the list to a file or load the list from a file. Please refer to Worksheets 33 and 34 for more details regarding the heap implementation of the priority queue interface and the heap-sort algorithm.



## 2. Tasks
Complete the implementation of the heap-based priority queue in dynArray.cPreview the document

Implement two functions, one for saving a to-do list to a file, and the other for loading a to-do list from a file. These two functions are in toDoList.cPreview the document

Implement the heap sort algorithm by completing the functions _buildHeap() and sortHeap() in dynArray.cPreview the document

Implement the print function intoDoList.cPreview the document that prints a to-do list in the priority order. To this end, feel free to use a helper function copyDynArr() provided in file dynArray.cPreview the document

 

## 3. Provided Files
dynArray.cPreview the document --- Implementation of dynamic array and heap-based priority queue. You will complete functions for heap-based priority queue in this file. Search for the comment "FIX".

toDoList.cPreview the document --- Implementation of functions specialized for a to-do list application, such as saveList() and loadList(). You will complete these two functions.

main.cPreview the document --- Tests your to-do list application. 

main2.cPreview the document --- Tests your heap sort algorithm. You will need to change the Makefile and function names in main.cPreview the document and main2.cPreview the document accordingly to switch between testing your to-do list application and the heap sort algorithm.

dynArray.hPreview the document --- Header file for dynArray.cPreview the document. This file should not be changed.

toDoList.hPreview the document --- Header file for toDoList.cPreview the document. This file should not be changed.

type.hPreview the document --- Header file for the Task structure. This file should not be changed.

todo.txtPreview the document --- An example file that contains a to-do list, which was saved by the function saveList(). Your function saveList()  should save a to-do list in a file using the same formatting. You may use this file to test your function loadList().

program_demo.txtPreview the document --- Examples of command lines showing how a user can interact with the program. 

Makefile --- The program's makefile.


## 4. What to Turn in?
Please submit on TEACH (Links to an external site.)Links to an external site. the following  completed files:

dynArray.c
toDoList.c
answer.txt -- Name of the file in which you saved the to-do list using saveList(); when running your code, enter 's' and then for the question "Please enter the filename: " you should enter: answer.txt
Please use this file-naming convention. Make sure your code compiles using the provided Makefile on the School's server. Design a number of test examples to thoroughly check for any errors in your code.

