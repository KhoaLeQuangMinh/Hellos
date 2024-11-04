
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data)
{
    struct Node * node = malloc(sizeof (struct Node));
    node->data = data;
    return node;
}

/* build the following tree
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
struct Node * InsertToTree(struct Node * root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data > root->data){
        if (root->right == NULL){
            root -> right = createNode(data);
        }
        else{
            InsertToTree(root -> right, data);
        }
    }
    else{
        if (root -> left == NULL){
            root -> left = createNode(data);
        }
        else{
            InsertToTree(root -> left, data);
        }
    }
    return root;
}

void freeMemory(struct Node * root)
{
    if(root == NULL){
        return;
    }

    freeMemory(root -> left);
    freeMemory(root -> right);

    free(root);
}

// A utility function to do inorder traversal of BST
void inorder(struct Node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


int main()
{
    struct Node * root = NULL;
    root = InsertToTree(root, 50);
    InsertToTree(root, 70);
    InsertToTree(root, 60);
    InsertToTree(root, 80);
    InsertToTree(root, 30);
    InsertToTree(root, 20);
    InsertToTree(root, 40);


    inorder(root);

    freeMemory(root);
    return 0;
}
