// Program to implement various operations on queues using linked list.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Class to create node of queue.
class node_class
{
    public:
    int data;
    node_class *next;
};

// Initializing a null queue.
node_class *head=NULL;

// Adding a value to the queue.
void enQueue(node_class **head, int data)
{
    node_class *new_node=new node_class();
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

// Removing a value from the queue.
void deQueue(node_class *node)
{
    // Traverse the linked list to the end.
    while(node->next->next != NULL)
    {
        node=node->next;
    }
    node->next=node->next->next;
}

// Printing the contents of the queue.
void printQueue(node_class *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

//Driver code
int main()
{
    enQueue(&head, 5);
    enQueue(&head, 4);
    enQueue(&head, 3);
    enQueue(&head, 2);
    deQueue(head);
    cout<<"Created queue is: ";
    printQueue(head);
    return 0;
}
