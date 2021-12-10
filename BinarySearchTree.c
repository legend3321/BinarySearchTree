#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct BST
{
    int info;
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

int main()
{
    int i = -1, choice = 1, info, sRoot = i;
    bst *root[MAX], *node = NULL, *temp = NULL;

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
            }

            break;

        case 2:
            sRoot = SelectTree(root, i);
            printf("Tree Selected With Info : %d\n", root[sRoot]->info);
            break;

        case 3:
            node = (bst *)malloc(sizeof(bst));

            printf("Enter Info For New Node : ");
            scanf("%d", &info);

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
            scanf("%d", &info);
            Search(root[sRoot], info);

            break;

        case 9:
            Menu();
            break;
        }
    }

    return 0;
}

#include "functions.h"