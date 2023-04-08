#include <iostream>
using namespace std;

// Node Structure
typedef struct Node {
    int data;
    Node* next;
    Node* prev;
} Node;


// Insert at beginning
int insertBeg (Node** head, int data)
{
    /*
    Function to Insert Node at the Beginning of Doubly Linked List

    PARAMETERS
        data : The Data to be contained in the Node
        head : The Pointer to the First Node

    RETURNS
        -1 : Failure to allocate Memory for New Node;
         0 : Succesfully Node Created
    */
    Node* newNode = nullptr;

    // Create the new Node
    try{
        newNode = new Node;
    }

    catch (bad_alloc&)
    {
        cout<<"Failed to allocate Memory for new Node"<<endl;
        return (-1);
    }
    

    // Add data to the Node
    newNode->data = data;

    // Previous should point to NULL
    newNode->prev = nullptr;

    // Next pointer should point to the Next Node
    newNode->next = (*head);

    if ((*head)!=nullptr)
        (*head)->prev = newNode;

    (*head) = newNode;
    return 0;
} 

int insertEnd(Node** head, int data)
{
    /*
    Function to Insert Node at the end of Doubly Linked List

    PARAMETERS
        data : The Data to be contained in the Node
        head : The Pointer to the First Node

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
        cout<<"Insufficient Memory for node allocation"<<endl;
        return -1;
    }

    // Add data 
    newNode-> data = data;
    // Last Node should point to NULL
    newNode->next = nullptr;

    // Previous node should point to the current last node;
    if ((*head) == nullptr)
    {
        newNode->prev = nullptr;
        (*head) = newNode;
        return 0;
    }
   
    Node* last = (*head);
    for(; last->next != nullptr; last = last->next);

    newNode->prev = last;
    last->next = newNode;
    return 0;
}

int insertMid(Node** head, int data)
{
    /*
    Function to Insert Node at the Middle of the Doubly Linked List in a sorted Manner.

    PARAMETERS
        data : The Data to be contained in the Node
        head : The Pointer to the First Node

    RETURNS
        -1 : Failure to allocate Memory for New Node;
         0 : Succesfully Node Created
    */
    Node* newNode = nullptr;
    try{
        newNode = new Node;
    }
    catch(bad_alloc&){
        cout<<"Insufficient Memory foor new Node creation"<<endl;
        return -1;
    }

    newNode->data = data;

    // Insert Sorted
    // If there are no elements in the list
    if ((*head)==nullptr){
        newNode->prev = nullptr;
        newNode->next = nullptr;
        (*head) = newNode;
        return 0;
    }
    // Find the most suitable node
    Node* nextNode = (*head);
    for(;(nextNode->next!=nullptr) && (nextNode->data < newNode->data); nextNode = nextNode->next);

    // If loop reaches the end of list
    if ((nextNode->next == nullptr) && (nextNode->data < newNode->data))
    {
        // If last node value is less than the new node value
        newNode->next = nullptr;
        newNode->prev = nextNode;
        nextNode->next = newNode;
    
        return 0;
    }
    // Add the new Node previous to the next Node
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    
    if (nextNode->prev != nullptr)
    {
        (nextNode->prev)->next = newNode;
        nextNode->prev = newNode;
    }
    else{
        (*head) = newNode;
    }
    return 0;
}

void traverse(Node* head){
    /*
    Function to traverse the Doubly Linked List

    PARAMETERS
        head : The Pointer to the First Node
    */
    cout<<"HEAD";
    for(;head!=nullptr;head=head->next)
    {
        cout<<"-->"<<head->data;
    }
    cout<<endl;
}

Node* middle(Node* start, Node*last)
{
    /*
    Function to determine the middle of a Linked List

    PARAMETERS
        start : The Pointer to the starting of list or sub-list.
        last : The Pointer to the endingb of list or sub-list.

    RETURNS
        Pointer to the middle Node
    */
    if (start == nullptr)
        return nullptr;

    Node* fast = start->next;
    Node* slow = start;
    while(fast != last)
    {
        fast = fast->next;
        if(fast!=last)
        {
            slow = slow->next;
            fast = fast->next;
        }

    }
    return slow;
}
int binarySearch(Node* head, int data)
{
    /*
    Function to search for an element in a doubly Linked List using Binary Search O(log n)

    PARAMETERS
        head : The Pointer to first Node in List.
        data : The data to search for in Linked List.

    RETURNS
        -1: If element not found
         1: If element is found
    */
    
    
    Node* last = nullptr;
    Node* start = head;

    while(last!=start)
    {
        Node* mid = middle(start, last);

        if (mid == nullptr)
            return -1;
        else if (mid->data == data)
        {
            cout<<"Found"<<endl;
            return 1;
        }
        else if (mid->data < data)
        {
            start = mid->next;
        }
        else
        {
            last = mid;

        }
    }
    return -1;
}

int main(){
    Node* head = nullptr;
    
    insertBeg(&head, 5);
    insertBeg(&head, 2);
    insertEnd(&head, 9);
    traverse(head);
    insertMid(&head, 4);
    insertMid(&head, 7);
    insertMid(&head,11);
    insertMid(&head,1);
    traverse(head);
    cout<<binarySearch(head,3)<<endl;
    return 0;
}