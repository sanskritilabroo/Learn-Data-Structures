/*a) Read 2 binary trees(Tree1 and Tree2) and display them
b) Find the largest element in Tree1 using inorder traversal
c) Merge the two trees to form a binary search tree (Tree3) and display it

(They didn’t explain part c properly and later had to explain it again)

E.g Tree1:
        1
       /   \
    2      3
            /
           4

Tree2:
        4
       /
     3
     /
   6
Largest in Tree1 is 4
Tree 3:
           5
         /     \
      3       6
        \
        4
Explanation for Tree3:
You add elements in corresponding positions in the two trees and create a BST out of that
Here we get
4+1, 3+2, 6, 3, 4
And so we create a bst out of these elements*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *l;
    struct node *r;
}Node;

Node* getNode(int val)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->l = newnode->r = NULL;
    return newnode;
}

Node* createTree(int val)
{
    int lc,rc;
    if(val!=-1)
    {
        Node *root = getNode(val);
        printf("Enter left child of %d: ", root->data);
        scanf("%d",&lc);
        root->l = createTree(lc);
        printf("Enter right child of %d: ", root->data);
        scanf("%d",&rc);
        root->r = createTree(rc);
        return root;
    }
    else
    return NULL;
}

int largest(Node *root)
{
    static int flag = -999;
    if (root)
    {
        largest(root->l);
        if (root->data > flag) 
        flag = root->data;
        largest(root->r);
    }
    return flag;
}

void display(Node* root)
{
    if (root)
    {
        display(root->l);
        printf("%d \t", root->data);
        display(root->r);
    }
}


Node* createBST(Node* root, int val)
{
    if(root==NULL)
    {
        root = getNode(val);
    }
    else
    {
        if(root->data > val)
        root->l = createBST(root->l,val);
        else if(root->data < val)
        root->r = createBST(root->r,val);
        // else
        // printf("Duplicates not allowed \n");
    }
    return root;
}

// void addbst(Node *root)
// {  
//     if(root)
//     {
//         addbst(root->l);
//         // printf("%d",root->data);
//         Tree3 = createBST(Tree3 , root->data);
//         addbst(root->r);
//     }
// }

Node *Tree3 = NULL;

void merge(Node *root1, Node *root2) {
    if (root1 || root2) {
        if (root1 && root2) {
            Tree3 = createBST(Tree3, root1->data + root2->data);
            merge(root1->l, root2->l);
            merge(root1->r, root2->r);
        } else if (root1) {
            Tree3 = createBST(Tree3, root1->data);
            // merge(root1->l, NULL);
            // merge(root1->r, NULL);
        } else {
            Tree3 = createBST(Tree3, root2->data);
            // merge(NULL, root2->l);
            // merge(NULL, root2->r);
        }
    }
}

int equality(Node *root1, Node *root2)
{
    static int flag = 0;  // Initialize the flag to 0
    if (root1 == NULL && root2 == NULL)
    {
        flag = 1;  // Both nodes are NULL, they are equal
    }
    else if (root1 != NULL && root2 != NULL)
    {
        if (root1->data == root2->data)
        {
            flag = equality(root1->l, root2->l);
            flag = equality(root1->r, root2->r);
        }
    }

    return flag;
}

void main()
{
    int val1,val2;
    printf("Enter data for tree 1:");
    scanf("%d", &val1);
    Node *tree1 = createTree(val1);
    printf("Enter data for tree 2:");
    scanf("%d", &val2);
    Node *tree2 = createTree(val2);


    display(tree1);
    printf("\n");
    display(tree2);
    printf("Are they equal? : %d" , equality(tree1,tree2));

    // printf("\n Largest element in tree 1: %d \n", largest(tree1));

    // // addbst(tree1);
    // // addbst(tree2);
    merge(tree1,tree2);
    printf("BST: \n");
    display(Tree3);
}

