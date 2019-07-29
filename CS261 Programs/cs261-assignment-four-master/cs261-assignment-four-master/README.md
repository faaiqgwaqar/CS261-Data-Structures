# Computer Science Software Engineering Assignment 4
## 1. General Instructions
For this assignment you will implement functions in C for an  AVL Tree. You are given a skeleton C code in the following files:

avl.hPreview the document
avl.cPreview the document
main.cPreview the document
and the file with values that should be read and added to the AVL Tree for testing your code:

input.txtPreview the document
and a make file for compiling the code on the School's server:

Makefile
Complete the missing functions or parts of functions in the skeleton code. You should use the same names of files, functions, and variables as we specified in the skeleton code. This is because our grading will be based on a script that assumes that you use the same names. Make sure your code compiles without errors using the provided makefiles for the two abstract data structures on the ENGR server. 

What to submit: Please submit only the two completed C files -- avl.c and main.c -- via TEACH (Links to an external site.)Links to an external site. by the deadline. Please do not submit the header, compiled object or executable files.

Questions regarding HW4 should be posted to HW4 Discussions on Canvas for fast response.

 

## 2. AVL Tree
The main function performs the following:

Initializes an empty AVL tree.
Reads values from an input file and adds them to the AVL tree.
Prints on the terminal all values of the AVL tree in the breadth-first fashion.
Finds the minimum-cost path in the AVL tree (see details below).
Prints the execution time for finding the min-cost path, on the terminal.
Prints values of nodes that lie on the minimum-cost path in the AVL tree, on the terminal. The order of nodes in the print-out must strictly follow their order in the min-cost path from the root to the leaf.
Prints a cost of the min-cost path of the AVL tree, on the terminal.
Your task is to complete the missing functions or parts of functions in avl.cPreview the document and main.cPreview the document. Search for the comment "FIX ME" to find which functions you need to complete. The comments before each function are aimed at clarifying the function's input arguments, outputs, and what the function is supposed to do. Note that we will test your code with another input.txt file.

 

## 3. Specification of Min-Cost Path
The minimum-cost path (or min-cost path) of an AVL tree is defined as a path from the root to a leaf for which the total sum of absolute differences |child.value - parent.value| is minimum. More formally, let LaTeX: \pi π  denote a path from the root to a leaf of the AVL tree, and LaTeX: i i  and LaTeX: j j  denote child and parent nodes, respectively. Then, we define the minimum-cost path LaTeX: \pi^* π ∗  as


LaTeX: \pi^* = \arg\min_{\pi} \sum_{\substack{\text{forall}\ i~\in ~\pi\\ j \text{ is parent of } i}} |i.\text{value} - j.\text{value}| π ∗ = arg ⁡ min π ∑ forall   i   ∈   π j  is parent of  i | i . value − j . value |

When  LaTeX: i i   indicates the root in the formula above, we assume that  LaTeX:  |i.\text{value} - j.\text{value}| = i.\text{value} | i . value − j . value | = i . value .

For example, the AVL tree shown in the figure below has the following paths: 

 AVL.png
 

LaTeX: \pi_1 = 32 - 9 -8 - 4 π 1 = 32 − 9 − 8 − 4
LaTeX: \pi_2 = 32 - 9 - 14 - 13 π 2 = 32 − 9 − 14 − 13
LaTeX: \pi_3 = 32 - 9 - 14 - 19 π 3 = 32 − 9 − 14 − 19
LaTeX: \pi_4 = 32 - 72 - 59 - 69 π 4 = 32 − 72 − 59 − 69
LaTeX: \pi_5 = 32 - 72 - 99 π 5 = 32 − 72 − 99


Using the above formula, in this example, the minimum-cost path is:

LaTeX: \pi^* = \pi_1 = 32 - 9 - 8 - 4 π ∗ = π 1 = 32 − 9 − 8 − 4

 

## 4. Grading policy: Max 100 points
25 points: The code runs without memory issues, but does not print out the correct AVL tree, and does not compute the correct minimum-cost path.
50 points: The code prints out the correct AVL tree, but does not compute the correct minimum-cost path.
85 points: The code prints out the correct AVL tree, computes the correct minimum cost, but does not print out nodes of the min-cost path in the correct order from the root to the leaf (e.g., some nodes are missing, or wrongly  swapped).
100 points: The code prints out the correct AVL tree, and nodes of the min-cost path in the correct order from the root to the leaf.
