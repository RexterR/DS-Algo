#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *NewNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *Insert(struct Node *node, int key)
{
    if (node == NULL)
    {
        return NewNode(key);
    }
    if (key < node->key)
    {
        node->left = Insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = Insert(node->right, key);
    }
    return node;
}

void InorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        printf("%d ", root->key);
        InorderTraversal(root->right);
    }
}

int main(int argc, char const *argv[])
{
    struct Node *bst = NULL;
    int bstChoice[] = {50, 30, 20, 40, 70, 60, 80};
    bst = Insert(bst,bstChoice[0]);
    for (int i = 1; i < 7; i++)
    {
        Insert(bst, bstChoice[i]);
    }
    
    printf("Inorder Traversal\n");
    InorderTraversal(bst);
    printf("\n");
    // while (1)
    // {
    //     printf("Enter Choice\n1.Insert\n2.Inorder Traverse\n3.Exit\n");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         int d;
    //         struct Node *temp;
    //         scanf("%d", &d);
    //         temp = Insert(bst, d);
    //         printf("Inserted %d \n", temp->key);
    //         break;
    //     }
    //     case 2:
    //     {
    //         InorderTraversal(bst);
    //         break;
    //     }
    //     case 3:
    //     {
    //         exit(0);
    //     }
    //     default:
    //         break;
    //     }
    // }

    return 0;
}
