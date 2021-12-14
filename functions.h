
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
    printf("8>Count Nodes\n");
    printf("9>Count Leaves\n");

    printf("10>Print Menu\n");
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

    float info;

    printf("Enter New Root : ");
    scanf("%f", &info);
    printf("%f\n", info);

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

        if (root->info > node->info)
        {
            if (root->left == NULL)
            {
                root->left = node;
                return;
            }
            else
                Insert(root->left, node);
        }
        if (root->info < node->info)
        {
            if (root->right == NULL)
            {
                root->right = node;
                return;
            }
            else
                Insert(root->right, node);
        }
    }
}

void PreOrder(bst *root)
{
    if (root == NULL)
        return;

    printf("%f ,", root->info);

    PreOrder(root->left);

    PreOrder(root->right);
}

void InOrder(bst *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);

    printf("%f ,", root->info);

    InOrder(root->right);
}

void PostOrder(bst *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);

    PostOrder(root->right);

    printf("%f ,", root->info);
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

void CountNodes(bst *root, int *counter)
{
    if (root != NULL)
    {
        *counter += 1;

        CountNodes(root->left, counter);

        CountNodes(root->right, counter);
    }
}

void CountLeaf(bst *root, int *counter)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            *counter += 1;

        CountLeaf(root->left, counter);

        CountLeaf(root->right, counter);
    }
}
