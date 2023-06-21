// Program to implement various operations on linked lists.
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// Class to create node.
class node_class
{
    public :
    int data;
    node_class *next;
};

// Initializing a null linked list.
node_class *head=NULL;

// Inserting at the head of a linked list.
void insert_at_head(node_class **head, int data)
{
    node_class *new_node=new node_class();
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

//Deleting the first node of a linked list.
void delete_from_head(node_class **head)
{
    *head=(*head)->next;
}

//Insert node at a specified position in the linked list.
void insert_at_position(node_class *node, int pos, int data)
{
    // If position is 0 then call insert at head.
    if(pos==0)
    {
        node=head;
        insert_at_head(&head, data);
    }
    else
    {
        // Traverse the linked list to the specified position.
        for(int i=1; i<=pos-1; i++)
        {
            node=node->next;
        }
        // Do the insertion.
        node_class *new_node=new node_class();
        new_node->data=data;
        new_node->next=node->next;
        node->next=new_node;
    }
}

//Replace a node at a specified position.
void replace_at_position(node_class *node, int pos, int data)
{
    if(pos==0)
    {
        node=head;
        node->data=data;
    }
    else
    {
        for(int i=1; i<=pos-1; i++)
        {
            node=node->next;
        }
        node->next->data=data;

    }
}

// Inserting a node at the tail of a linked list.
void insert_at_tail(node_class *node, int data)
{
    // Traverse the linked list to the end.
    while(node->next != NULL)
    {
        node=node->next;
    }
    node_class *new_node=new node_class();
    new_node->data=data;
    new_node->next=node->next;
    node->next=new_node;
}

// Delete a node at a specified position.
void delete_at_position(node_class *node, int pos)
{
    // If position is 0 then call delete from head.
    if(pos==0)
    {
        node=head;
        delete_from_head(&head);
    }
    else
    {
        // trqaversing the linked list to the specified postion.
        for(int i=1; i<=pos-1; i++)
        {
            node=node->next;
        }
        node->next=node->next->next;
    }
}

// Printing the linked list.
void printList(node_class *node)
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

    insert_at_position(head, 0, 5);
    insert_at_position(head, 0, 4);
    insert_at_position(head, 0, 3);
    insert_at_position(head, 0, 2);
    insert_at_position(head, 0, 1);
    insert_at_position(head, 0, 6);
    insert_at_position(head, 2, 3);
    insert_at_head(&head, 8);
    insert_at_tail(head, 7);
    replace_at_position(head, 0, 9);
    replace_at_position(head, 7, 21);
    delete_at_position(head, 0);
    delete_at_position(head, 6);
    cout<<"Created Linked list is: ";
    printList(head);
    return 0;
}
