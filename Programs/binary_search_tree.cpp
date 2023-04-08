// Binary Search Tree

#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* left;
    Node* right;
} Node;


Node* insertNode(Node* node, int data)
{
    /*
    Function to insert node in BST

    PARAMETERS
        root: The root node of BST
        data: The value to insert

    RETURNS
        The inserted Node
    */
    

    if (node == nullptr)
    {
        Node * newNode = nullptr;
        try{
            newNode = new Node;
        }
        catch(bad_alloc&)
        {
            cout<<"Failed to allocate Memory to new node"<<endl;
        }

        // Insert data to new Node
        newNode -> data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        node = newNode;
        return node;
        
    }

    if (node->data < data)
        node->right = insertNode(node->right, data);

    else if (node-> data > data)
        node->left =  insertNode(node->left, data);

    return node;
}


void inorder(Node* root)
{
    /*
    Function to Print the in Order of BST

    PARAMETERS
        root: The root node of BST
    */

    if (root == nullptr)
        return;

    // Traverse the left subtree
    inorder(root->left);

    // Print root
    cout<<root->data<<"-->";

    // Traverse right subtree
    inorder(root->right);
    return;
}

void preorder(Node *root)
{
    /*
    Function to Print the Pre Order of BST

    PARAMETERS
        root: The root node of BST
    */

    if (root == nullptr)
        return;

    // Print root
    cout<<root->data<<"-->";

    // Traverse the left subtree
    preorder(root->left);

    // Traverse right subtree
    preorder(root->right);
    return;

}

void postorder(Node *root)
{
    /*
    Function to Print the Post Order of BST

    PARAMETERS
        root: The root node of BST
    */
    if (root == nullptr)
        return;

    // Traverse the left subtree
    postorder(root->left);

    // Traverse right subtree
    postorder(root->right);

    // Print root
    cout<<root->data<<"-->";
    return;

}


int main()
{
    Node *root = nullptr;
    root  = insertNode(root, 100);
    root = insertNode(root, 20);
    root = insertNode(root, 200);
    root  = insertNode(root, 10);
    root  = insertNode(root, 30);
    root  = insertNode(root, 150);
    root  = insertNode(root, 300);

    inorder(root);
    cout<<"\b\b\b   \n";

    preorder(root);
    cout<<"\b\b\b   \n";

    postorder(root);
    cout<<"\b\b\b   \n";
    return 0;
}