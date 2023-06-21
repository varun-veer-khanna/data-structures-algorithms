// Program to implement various operations on stacks using linked list.
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// Class to create node of stack.
class node_class
{
    public :
    int data;
    node_class *next;
};

// Initializing a null stack.
node_class *head=NULL;

// Pushing the value on the stack.
void push(node_class **head, int data)
{
    node_class *new_node=new node_class();
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

//Deleting the first node of a stack.
void pop(node_class **head)
{
    *head=(*head)->next;
}

// Printing the contents of the stack.
void printStack(node_class *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

// Driver function.
int main()
{

    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    pop(&head);
    cout<<"Created stack is: ";
    printStack(head);
    return 0;
}
