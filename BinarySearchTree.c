#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct BST
{
    float info;
    struct BST *left;
    struct BST *right;
} bst;

void Menu();
int SelectTree(bst *[], int);
bst *Root();
void Insert(bst *, bst *);
void PreOrder(bst *);
void InOrder(bst *);
void PostOrder(bst *);
void Search(bst *, int);
void CountNodes(bst *, int *);
void CountLeaf(bst *, int *);

int main()
{
    int i = -1, choice = 1, sRoot = i, counter = 0;
    bst *root[MAX], *node = NULL;
    float info;

    Menu();

    while (choice)
    {
        printf("\nCommand : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (i + 1 > MAX)
                printf("You Can't Make More Binary Search Trees :)");
            else
            {
                i++;
                root[i] = Root();
                sRoot = i;
                printf("Tree Selected With Info : %f\n", root[sRoot]->info);
            }

            break;

        case 2:
            sRoot = SelectTree(root, i);
            printf("Tree Selected With Info : %f\n", root[sRoot]->info);
            break;

        case 3:
            node = (bst *)malloc(sizeof(bst));

            printf("Enter Info For New Node : ");
            scanf("%f", &info);

            node->info = info;
            node->left = NULL;
            node->right = NULL;
            Insert(root[sRoot], node);

            break;

        case 4:
            printf("PreOrder(NLR) : \n");
            PreOrder(root[sRoot]);
            printf("\n");

            break;

        case 5:
            printf("InOrder(LNR) : \n");
            InOrder(root[sRoot]);
            printf("\n");

            break;

        case 6:
            printf("PostOrder(LRN) : \n");
            PostOrder(root[sRoot]);
            printf("\n");

            break;

        case 7:
            printf("Enter Value to Search : ");
            scanf("%f", &info);
            Search(root[sRoot], info);

            break;

        case 8:
            counter = 0;
            CountNodes(root[sRoot], &counter);
            printf("%f Nodes Are present in Tree\n", counter);

            break;

        case 9:
            counter = 0;
            CountLeaf(root[sRoot], &counter);
            printf("%f Leaf Are present in Tree\n", counter);

            break;

        case 10:
            Menu();
            break;
        }
    }

    return 0;
}

#include "functions.h"