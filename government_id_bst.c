#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char id[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char id[])
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insert(struct Node *root, char id[])
{
    if (root == NULL)
        return createNode(id);

    if (strcmp(id, root->id) < 0)
        root->left = insert(root->left, id);
    else if (strcmp(id, root->id) > 0)
        root->right = insert(root->right, id);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->id);
        inorder(root->right);
    }
}

int height(struct Node *root)
{
    int leftHeight;
    int rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int bstSearch(struct Node *root, char key[], int *comparisons)
{
    while (root != NULL)
    {
        (*comparisons)++;

        if (strcmp(key, root->id) == 0)
            return 1;

        if (strcmp(key, root->id) < 0)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int linearSearch(char ids[][20], int n, char key[], int *comparisons)
{
    int i;

    for (i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (strcmp(ids[i], key) == 0)
            return 1;
    }

    return 0;
}

void performSearches(struct Node *root, char ids[][20], int n)
{
    char searchKeys[4][20] =
    {
        "A102",
        "A45",
        "B12",
        "B3"
    };

    int i;
    int bstComparisons;
    int linearComparisons;

    printf("\nSearch Comparison:\n");

    printf("%-10s %-15s %-15s\n",
           "ID", "BST Search", "Linear Search");

    for (i = 0; i < 4; i++)
    {
        bstComparisons = 0;
        linearComparisons = 0;

        bstSearch(root, searchKeys[i], &bstComparisons);
        linearSearch(ids, n, searchKeys[i], &linearComparisons);

        printf("%-10s %-15d %-15d\n",
               searchKeys[i],
               bstComparisons,
               linearComparisons);
    }
}

int main()
{
    char original[8][20] =
    {
        "A102",
        "A25",
        "A7",
        "B100",
        "B12",
        "A120",
        "B3",
        "A45"
    };

    char changed[8][20] =
    {
        "A45",
        "A120",
        "B3",
        "A7",
        "B12",
        "A25",
        "B100",
        "A102"
    };

    struct Node *root1 = NULL;
    struct Node *root2 = NULL;

    int i;

    /* Original insertion order */
    for (i = 0; i < 8; i++)
        root1 = insert(root1, original[i]);

    printf("ORIGINAL INSERTION ORDER\n");

    printf("A102 A25 A7 B100 B12 A120 B3 A45\n");

    printf("\nInorder Traversal:\n");
    inorder(root1);

    printf("\nBST Height = %d\n", height(root1));

    performSearches(root1, original, 8);

    /* Changed insertion order */
    for (i = 0; i < 8; i++)
        root2 = insert(root2, changed[i]);

    printf("\n\nCHANGED INSERTION ORDER\n");

    printf("A45 A120 B3 A7 B12 A25 B100 A102\n");

    printf("\nInorder Traversal:\n");
    inorder(root2);

    printf("\nBST Height = %d\n", height(root2));

    return 0;
}