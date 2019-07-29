# CS261 Assingment Three
In this assignment you are going to first implement a Map using a Hash Table with Buckets, and then use the Map for implementing the Concordance function. Let us break each of those tasks down step-by-step.

## 1. Map
A Map is a data structure that stores (key,value) pairs. When you add an element to a Map, you provide both the key and value. When you read an element from a Map, you give a key, and the function is supposed to return the associated value. You can also test to see if any value is stored under a given key. The MAP interface includes the following:

   void initMap (struct hashMap * ht, int tableSize);

   int containsKey (struct hashMap * ht, KeyType k);

   void insertMap (struct hashMap * ht, KeyType k, ValueType v);

   ValueType atMap (struct hashMap * ht, KeyType k);

   void removeKey (struct hashMap * ht, KeyType k);

   int sizeMap (struct hashMap *ht); 

The function initMap() initializes the Hash Table with a given table size. The function containsKey() returns a non-zero integer if the key is found in the Map, and zero, otherwise. The function insertMap() overwrites any previous value associated with the input key. The function atMap() returns a value associated with the input key. It will give an exception if the key is not found, so the best is to test the key using containsKey() before calling atMap(). The function removeKey() removes an entry with the input key from the Hash Table. It does nothing if the key is not found in the table. The function sizeMap() returns the number of elements in the map.

 A Hash Table with Buckets is a combination of an array and a linked list. Elements of the array are pointers to links. Each link holds three items: key, value, and pointer to the next link. The following is a structure declaration that you could use to define the Hash Table:

   # define KeyType char *

   # define ValueType int

   struct hashLink {

      KeyType key;

      ValueType value;

      struct hashLink * next;

   };

   struct hashMap {

      struct hashLink ** table;

      int tableSize;

      int count;

   };

As can be seen, our keys are pointers to a string of character values. Use the following folding hash function to compute an integer value from a string key:

   int stringHash (char * str) {

       int i;

       int r = 0;

      for (i = 0; str[i] != 0; i++)  r += str[i];

       return r;

   }

## 2. Concordance
Once you have your Hash Table working, you will implement the concordance function using the Hash Table. Concordance is a function that counts the number of times each word is used in the input text file. For example, if the input text is:

   "It was the best of times,  It was the worst of times."

The output of the Concordance function will be:

   best: 1

   It: 2

   was: 2

   the: 2

   of: 2

   worst: 1

Given the input text, you will construct the Hash Table where keys are words found in the input text, and values are counts of how many times the corresponding words appear in the input text.

## 3. Main function
Your main function in main.c must accept one command line argument as the filename of the input text file. This text file will then be opened to count word frequencies. Your program should: a) Open the file input.txt, b) Read the file, c) Count the frequency of each word found in the input text file, and d) Print out the word frequencies. For the purposes of this assignment, a word may contain only small and capital letters a to z and A to Z, and numbers 0 to 9, and apostrophe, but no other symbols (e.g., dash, underscore, and period are not allowed). The case is important (e.g., It and it are different words). In the main function, you need to print out all words found in the input text file, and their frequencies. Note that the words can be printed in any order (not  necessarily by the order of appearance in the input text). Note that for grading this homework, we will use another, our own, input text file. 

## 4. Provided Files and Instructions
hashMap.c Preview the document-- Implementation of a Hash Table. You will implement some functions in this file.

hashMap.hPreview the document -- Header for hashMap.c. This file should NOT be changed.

linkedList.cPreview the document -- Implementation of a Linked List data structure. You will implement some functions in this file.

linkedList.hPreview the document -- Header for linkedList.c. This file should NOT be changed.

type.hPreview the document -- Header file that contains convenient macros. This file should NOT be changed.

structs.hPreview the document -- Header file that contains declarations of structures. This file should NOT be changed.

main.cPreview the document -- Implementation of Concordance. You will implement the main function as specified in Section 3.

Makefile -- The program’s makefile. This file should NOT be changed.

input.txtPreview the document -- Example text files that you can use to test your code.

Please do not change the names of already specified variables, functions, and files. In order to easier find which functions or parts of functions you are supposed to implement, please search for the comment "/*write this" in the files.

## 5. Homework Submission
Make sure your code compiles with our Makefile on the School's Linux CPU server. Please submit only the following three C files:

hashMap.c

linkedList.c

main.c
via the TEACH website (Links to an external site.)Links to an external site. by 10am on May 10.

6. Grading policy
Late submission: 25% reduction for each day after the deadline
25 points = Code compiles well, but has memory issues when running
50 points = Code runs well, but misses to print out some words from the input text, or gives wrong word counts
75 points = Code runs well, prints out all words from the input text, but gives no more than one wrong word count
100 points = Code runs well, prints out all words from the input text, but gives all correct word counts
