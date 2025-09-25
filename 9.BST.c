#include <stdio.h>
#include <stdlib.h>
int choice, data;

struct dlist
{
    int data;
    struct dlist *left;
    struct dlist *right;
} *root = NULL;
typedef struct dlist node;

node* createNode(int data);
node* insert(node* root, int data);
node* Min(node* root);
node* deleteNode(node* root, int data);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);

int main()
{
    while (1)
    {
        printf("\n---BST OPERATIONS---\n");
        printf("\t1.Insert\n\t2.Delete\n\t3.Inorder Traverse\n\t4.Preorder Traversal\n\t5.Postorder\n\t6.EXIT\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("\nEnter the Value to Insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            }
            case 2:
            {
                printf("\nEnter the Value to Delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            }
            case 3:
            {
                printf("\nInorder Traversal:\n");
                inorder(root);
                break;
            }
            case 4:
            {
                printf("\nPreorder Traversal:\n");
                preorder(root);
                break;
            }
            case 5:
            {
                printf("\nPostorder Traversal:\n");
                postorder(root);
                break;
            }
            case 6:
            {
                printf("\nEXIT SUCCESSFULLY\n");
                exit (0);
            }
            default:
                printf("\nInvalid Choice\n");
        }
    }
}

node* createNode(int data)
{
    node *tmp;
    tmp = (node*)malloc(sizeof(node));
    tmp->data = data;
    tmp->left = tmp->right = NULL;
    return tmp;
}

node* insert(node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

node* Min(node* root)
{
    while (root && root->left!=NULL)
        root = root->left;
    return root;
}


node* deleteNode(node* root, int data)
{
    if (root==NULL)
        return root;
    if (data < root->data)
        root->left=deleteNode(root->left, data);
    else if (data > root->data)
        root->right=deleteNode(root->right, data);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            node* tmp = root;
            root = root->right;
            free(tmp);
        }
        else if(root->right==NULL)
        {
            node* tmp = root;
            root = root->left;
            free(tmp);
        }
        else
        {
            node* tmp = Min(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }
    return root;
}

void inorder(node* root)
{
    if (root == NULL)
        return;
    // left -> root -> right
    inorder(root->left);
    printf("\t%d", root->data);
    inorder(root->right);
}

void preorder(node* root)
{
    if (root == NULL)
        return;
    // root -> left -> right
    printf("\t%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if (root == NULL)
        return;
    // left -> right -> root
    postorder(root->left);
    postorder(root->right);
    printf("\t%d", root->data);
}
