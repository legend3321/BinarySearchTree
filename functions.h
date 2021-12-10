
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

int SelectTree(bst *root[], int i)
{
    int sRoot = 1;
    if (i < 0)
        printf("No tree found Please Make One\n");
    else
    {
        printf("index : info \n");
        for (int j = 0; j <= i; j++)
            printf("%d : %d \n", j, root[j]->info);
        printf("Enter Index No. : ");
        scanf("%d", &sRoot);
    }
    return sRoot;
}

bst *Root()
{
    bst *temp;
    temp = (bst *)malloc(sizeof(bst));

    int info;

    printf("Enter New Root : ");
    scanf("%d", &info);

    temp->info = info;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void Insert(bst *root, bst *node)
{
    if (root == NULL)
    {
        printf("Please Select a tree Or Create one \n");
        Menu();
    }
    else
    {
        bst *temp = root;

        if (temp->info > node->info)
        {
            if (temp->left == NULL)
            {
                temp->left = node;
                return;
            }
            else
                Insert(temp->left, node);
        }
        if (temp->info < node->info)
        {
            if (temp->right == NULL)
            {
                temp->right = node;
                return;
            }
            else
                Insert(temp->right, node);
        }
    }
}

void PreOrder(bst *root)
{
    if (root == NULL)
        return;

    printf("%d ,", root->info);

    PreOrder(root->left);

    PreOrder(root->right);
}

void InOrder(bst *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);

    printf("%d ,", root->info);

    InOrder(root->right);
}

void PostOrder(bst *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);

    PostOrder(root->right);

    printf("%d ,", root->info);
}

void Search(bst *root, int info)
{
    if (root->info == info)
    {
        printf("Element found \n");
        return;
    }
    else if (info < root->info)
    {
        if (root->left != NULL)
            Search(root->left, info);
        else
            printf("Element Is Not present in Tree \n");
    }
    else if (info > root->info)
    {
        if (root->right != NULL)
            Search(root->right, info);
        else
            printf("Element Is Not present in Tree \n");
    }
}