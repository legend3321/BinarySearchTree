# BinarySearchTree
Binary Search Tree Implementation Using C language with Some Basic Functions as Creating a tree, transversing using different methods, etc.

## Including C's basic Header Files 

```c
#include <stdio.h>
#include <stdlib.h>
```

Here stdio.h is included for basic input and output functions, for eg printf and scanf statements.
Whereas stdlib is Standard Library of 'c' which cotains functions like malloc() and free(), which we will use further in our code.

## #define MAX 1000
Now max is a contant with value 1000
>We Used this contant to Give an initial size to our array which contains roots of diffenent Trees.

```c
int arr[MAX];
```

## Making Structure
Structures in c is a user-defined datatype(i.e, we define that what it will comtain) that can group different data-types into One. 
```c
typedef struct BST
{
    int info;
    struct BST *left;
    struct BST *right;
} bst;
```
Here we defined our struct BST as bst using ```typedef``` keyword which can redefine any keyword(including datatype) in c.
For eg if we write 
```c
typedef int integer;

```
Then in our code int will be written as "interger" instead if "int".

<br />
So, our new datatype "bst" contains 3 variables 
<ul>
  <li>int info</li>
  <li>struct BST *left</li>
  <li>struct BST *right</li>
</ul>

Where info contains the data for different nodes in Tree. Left pointer contains the address of node on the left of the parent node and right node contains the address of node right of parent node.
<br />
For Eg. One Node contains(say root) value 100 and we insert a new node in our tree with value 90, so according to Binary Search Tree address of that node(containing 90) will go to the left pointer of root Node ```root->left = node;```. Same will be done for right one, if data on new node is 110 then the address of it will be given to right pointer of root ```root->right = node;```.
>Note : We make pointers of bst as `struct BST;` type to that they can be self-refrensive(mean: that the pointer can contain direct address of `struct bst; ` type node i.e, no need of extra effort in excavating nodes with address. `right` and `left` pointers will directly point towards the other nodes. <br \>Or just be curious and make them as int * type and try to transverse the tree 😁.

## Function Declaration
In c we have to declare function before ```int main()``` in order to get top-bottom approach(in which finctions are declared before main() and then given definition later i.e., after main()). Or we can simply give function definition above ```int main()``` to get bottom-top approach. (srsly noboday cares 😅)
```c
void Menu();
int SelectTree(bst *[], int);
bst *Root();
void Insert(bst *, bst *);
void PreOrder(bst *);
void InOrder(bst *);
void PostOrder(bst *);
void Search(bst *, int);
```
In above declarations in `bst *Root();` ___*Root___ is written because the functions is returning pointer value to the main function.
```c
//main()
root[i] = Root();

//*Root()
return temp;
```
>Where root[] is array containing roots of different trees and i is the index of last tree created.

<br />

## The one and olny `main()` FUNCTION!!!
In main function we did omly 4-5 things. But first lets understand whats main in c. It is the keyword in c and main() is the first function of every c program which will be executed first when you run your code and is responsible for starting the execution and terminatoin of your program( like in this case we have main in BinarySearchTree.c file, at the moment when we hit run the complier will search for main function in our code and start executing out program form there).

### Variable Declarations
```c
int i = -1, choice = 1, info, sRoot = i;
bst *root[MAX], *node = NULL;
```
Where i is for the last index of arrat root, choice if for user input choices according to which we will call the functions. sRoot (selectedRoot) is made for current selected root from array root.
<br />
Now We have an array of type bst(because it will contain roots of different trees. And `*root[MAX]` is written because we will not directly put the roots in array, rather we will pit address of the roots. So basically they are pointers). node is created for new nodes and passing it to ```Insert()``` function for the further addition of nodes in tree.

#### ```Menu();```
Now we will call the `Menu()` function which is declared above and defined in `"functions.h"` header file.
<br />
```c
void Menu()
{
    printf("\n----------------------\n");
    printf("1>Make new Tree\n");
    printf("2>Select Tree\n");
    printf("3>Insert Into Tree\n");
    printf("4>PreOrder(NLR)\n");
    printf("5>InOrder(LNR)\n");
    printf("6>PostOrder(LRN)\n");
    printf("7>Search\n");

    printf("9>Print Menu\n");
    printf("0>Exit\n");
    printf("\n----------------------\n");
}
```
#### while Menu Loop
We will use an infinite while loop for repeted Input and Output. Generelly it is while(1) but here we have taken choice as condition. If choice is greater than 0  the loop will continue to execute. If user inputs 0 the `scanf` statement puts 0 into choice and while statement becomes `while(0)` where 0 represents `false` condition and loop will terminate.
```c
while (choice)
    {
        printf("\nCommand : ");
        scanf("%d", &choice);
        switch (choice)
        {
        ...
        
        ...
        }
    }
```
Inside while loop everytime choice in inputed and then gets compared using switch which will call respective functions like `Insert(), Search(), Preorder()` according to user choice/input.

#### case 1:
if choice is 1 then the `Root()` should be called, but before that appending a new root to our array we must check that out array is not full.
```c
case 1:
  if (i + 1 > MAX)
    printf("You Can't Make More Binary Search Trees :)");
  else
  {
    i++;
    root[i] = Root();
  }

  break;
```


