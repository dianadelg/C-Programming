"#C-Programming" 

1.1 llist: Linked list
Write a program llist that maintains and manipulates a sorted linked list of integers according to
instructions received from standard input. The linked list is maintained in order, meaning that each
integer will be larger than the one preceeding it.
llist maintains a linked list containing zero or more integers, ordered from least to greatest.
llist will need to allocate space for new nodes as they are created using malloc; any allocated
space should be deallocated using free before llist terminates.
It supports two operations:
insert n Adds an integer n to the list. If n is already present in the list, it does nothing. The
instruction format is an i followed by a space and an integer n.
delete n Removes an integer n from the list. If n is not present in the list, it does nothing. The
instruction format is a d followed by a space and an integer n.
After each command, llist will print the length of the list followed by the contents of the list,
in order from first (least) to last (greatest).
Your program will halt once it reaches the end of standard input.
Input format Each line of the input contains an instruction. Each line begins with a letter (either
“i” or “d”), followed by a space, and then an integer. A line beginning with “i” indicates that the
integer should be inserted into the list. A line beginning with “d” indicates that the integer should
be deleted from the list.
Your program will not be tested with invalid input. You may choose to have llist terminate in
response to invalid input.
Output format After performing each instruction, llist will print a single line of text containing
the length of the list, a colon, and the elements of the list in order, all separated by spaces.
Usage Because llist reads from standard input, you may test it by entering inputs line by line
from the terminal. You may use any invalid input, such as #, to terminate your session.
$ ./llist
i 5
1 : 5
d 3
1 : 5
i 3
2 : 3 5
i 500
3 : 3 5 500
d 5
2 : 3 500
#
Alternatively, you may use the shell to provide a file to llist using input redirection, e.g.,
2
$ ./llist < tests/test.01.txt
1 : 10
2 : 10 11
3 : 9 10 11
2 : 9 10

1.2 mexp: Matrix exponentiation
Write a program mexp that multiplies a square matrix by itself a specified number of times. mexp
takes a single argument, which is the path to a file containing a square (k × k) matrix M and a
non-negative exponent n. It computes Mn and prints the result.
Note that the size of the matrix is not known statically. You must use malloc to allocate space
for the matrix once you obtain its size from the input file.
To compute Mn, it is sufficient to multiply M by itself n − 1 times. That is, M3 = M × M × M.
Naturally, a different strategy is needed for M0
.
Input format The first line of the input file contains an integer k. This indicates the size of the
matrix M, which has k rows and k columns.
The next k lines in the input file contain k integers. These indicate the content of M. Each line
corresponds to a row, beginning with the first (top) row.
The final line contains an integer n. This indicates the number of times M will be multiplied by
itself. n is guaranteed to be non-negative, but it may be 0.
For example, an input file file.txt containing
3
1 2 3
4 5 6
7 8 9
2
indicates that mexp must compute


1 2 3
4 5 6
7 8 9


2
.
Output format The output of mexp is the computed matrix Mn. Each row of Mn is printed on
a separate line, beginning with the first (top) row. The items within a row are separated by spaces.
Using file.txt from above,
$ ./mexp file1.txt
30 36 42
66 81 96
102 126 150

1.3 bst: Binary search trees
Write a program bst that manipulates binary search trees. It will receive commands from standard
input, and print resposes to those commands to standard output.
A binary search tree is a binary tree that stores integer values in its interior nodes. The value for
a particular node is greater than every value stored its left sub-tree and less than every value stored
in its right sub-tree. The tree will not contain any value more than once. bst will need to allocate
space for new nodes as they are created using malloc; any allocated space should be deallocated
using free before bst terminates.
This portion of the assignment has two parts.
Part 1 In this part, you will implement bst with three commands:
insert n Adds a value to the tree, if not already present. The new node will always be added as
the child of an existing node, or as the root. No existing node will change or move as as result
of inserting an item. If n is already present in the tree, bst will print duplicate. Otherwise,
it will print inserted. The instruction format is an i followed by a decimal integer n.
search n Searches the tree for a value n. If n is present, bst will print present. Otherwise, it will
print absent. The instruction format is an s followed by a space and an integer n.
print Prints the current tree structure, using the format in section 1.4.1.
Part 2 In this part, you will implement bst with an additional fourth command:
delete n Removes a value from the tree. See section 1.4.2 for further discussion of deleting nodes.
If n is not present, print absent. Otherwise, print deleted. The instruction format is a d
followed by a space and an integer n.

Input format The input will be a series of lines, each beginning with a command character (i, s,
p, or d), possibly followed by a decimal integer. When the input ends, the program should terminate.
Your program will not be tested with invalid input. A line that cannot be interpreted may be
treated as the end of the input.
Output format The output will be a series of lines, each in response to an input command.
Most commands will respond with a word, aside from p. The format for printing is described in
section 1.4.1.
Usage
$ ./bst
i 1
inserted
i 2
inserted
i 1
duplicate
s 3
absent
p
(1(2))
#
1.3.1 Printing nodes
An empty tree (that is, NULL) is printed as an empty string. A node is printed as a (, followed by
the left sub-tree, the item for that node, the right subtree, and ), without spaces.
For example, the output corresponding to fig. 1 is ((1)2((3(4))5(6))).
1.4.2 Deleting nodes
There are several strategies for deleting nodes in a binary tree. If a node has no children, it can
simply be removed. That is, the pointer to it can be changed to a NULL pointer. Figure 2a shows
the result of deleting 4 from the tree in fig. 1.
If a node has one child, it can be replaced by that child. Figure 2b shows the result of deleting 3
from the tree in fig. 1. Note that node 4 is now the child of node 5.
If a node has two children, its value will be changed to the maximum element in its left subtree.
The node which previously contained that value will then be deleted. Figure 2c shows the result of
deleting 5 from the tree in fig. 1. Note that the node that previously held 5 has been relabeled 4,
and that the previous node 4 has been deleted.
Note that the value being deleted may be on the root node.

1.4 queens: (N + 1)-queens
Write a program queens that implements part of the search process for solving the N-queens
problem. queens has one required argument and two optional arguments. The required argument
will always occur last: it is the name of a file containing a chessboard.
The two optional arguments may occur individually or together in any order. They are +2, which
indicates that queens should report whether two queens may be placed on the board (Part 2), and
-w, which allows for the presence of warrior queens (Part 3).
This portion of the assignment has three parts, two of which are required. The third part will be
counted as extra credit.
Background A chessboard is an 8 × 8 grid of squares, each of which may contain up to one chess
piece.
The queen is the most powerful piece in chess, capable of moving any number of squares vertically,
horizontally, or diagonally, provided that it does not change direction during the move.
The N-queens problem asks how many ways N queens can be arranged on a board such that no
queen can take another. That is, no queen can be moved to a square occupied by another queen in
a single move.
Part 1 Your program will be given a chessboard with some number of queens already placed.
Your program must first determine whether any queen can take any other queen. If so, it will print
Invalid. If not, it will determine, for each empty square, whether a queen placed there could be
taken by any other queen. It will print a new chessboard with these available squares marked with q.
Input format The input will contain a chessboard, specified as eight lines containing eight
characters. A . indicates an empty space, and a Q indicates a queen.
A W indicates a warrior queen. Behavior is unspecified if the chessboard contains a warrior queen,
but the -w option has not been given.
Your program will not be tested with incorrectly formatted chessboards.
9
Output format If any queens on the board may take another, queens will print Invalid and
terminate. Otherwise, queens will print a chessboard similar to the input, but with additional
symbols q and w to indicate squares where a queen or warrior queen may be placed. The mark w
will only be used if the -w option is given.
Next, if the +2 option is given, queens will print Zero, One, or Two or more, depending on how
many additional queens may be safely placed on the board.
Usage Assume the file board.txt contains the following chessboard:
........
........
....Q...
......Q.
........
..Q.....
........
........
Then,
$ ./queens board.txt
qq...q..
qq.....q
....Q...
......Q.
q.......
..Q.....
.....q.q
.q.q.q.q


