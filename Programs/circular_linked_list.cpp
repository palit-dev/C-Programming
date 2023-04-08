#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
} Node;


int insertBeg(int data, Node** rear)
{
    /*
    Function to Insert Node at the Beginning of Circular Linked List

    PARAMETERS
        data : The Data to be contained in the Node
        rear : The Pointer to the Last Node

    RETURNS
        -1 : Failure to allocate Memory for New Node;
         0 : Succesfully Node Created
    */
    Node* newNode = nullptr;
    
    try{
        newNode = new Node;
    }
    catch(bad_alloc&)
    {
        cout<<"Failed to allocate Memory for New node"<<endl;
        return -1;
    }

    // Add data to new Node
    newNode->data = data;

    // Check if it is the first element 
    if ((*rear)== nullptr)
    {
        // If it is the first element, then it points to itself.
        newNode->next = newNode;
        (*rear) = newNode;
    }
    else{
        // If the list is not empty, the new Node must point to the current first node
        // And the last node must point to the current one.
        newNode->next = (*rear)->next;
        (*rear)->next = newNode;
    }
    return 0;
}

int insertEnd(int data, Node** rear)
{
    /*
    Function to Insert Node at the End of the Circular Linked List

    PARAMETERS
        data : The Data to be contained in the Node
        rear : The Pointer to the Last Node

    RETURNS
        -1 : Failure to allocate Memory for New Node;
         0 : Succesfully Node Created
    */

    Node *newNode = nullptr;
    try{
        newNode = new Node;

    }
    catch(bad_alloc&)
    {
        cout<<"Failed to allocate memory to new node"<<endl;
        return -1;
    }

    newNode->data = data;
    if ((*rear)==nullptr)
    {
        // If list is empty, the node should self-point
        newNode->next = newNode;
        
    }
    else{
        
        // If list is not empty, it should point to the first Node
        newNode->next = (*rear)->next;

        // The current last Node must point top this Node
        (*rear)->next = newNode;

    }
    (*rear) = newNode;
    return 0;
}

int traverse(Node *rear)
{
    /*
    Function traverse the Circular Linked List

    PARAMETERS
        rear : The Pointer to the Last Node

    RETURNS
        -1 : Empty List
         0 : List Successfully Parsed.
    */
    if (rear == nullptr)
    {
        cout<<"List is empty"<<endl;
        return -1;
    }
    Node *temp= rear->next;
    cout<<"HEAD";
    
    do{
        cout<<"-->"<<temp->data;
        temp = temp->next;
    }while(temp != rear->next);
    cout<<"-->REAR"<<endl;
    return 0;
}


int main(){
    Node *rear = nullptr;
    insertBeg(12, &rear);
    insertBeg(14, &rear);
    insertEnd(11, &rear);
    traverse(rear);
    return 0;


}