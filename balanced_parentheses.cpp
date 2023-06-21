//Program to check if a given parentheses string has balanced parentheses using concept of stacks.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Class to create node of stack.
class node_class
{
    public :
    char data;
    node_class *next;
};

// Initializing a null stack.
node_class *head=NULL;

// Pushing the value on the stack.
void push(node_class **head, char data)
{
    node_class *new_node=new node_class();
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
}

//Deleting the first node of a stack.
char pop(node_class **head)
{
    char data=(*head)->data;
    *head=(*head)->next;
    return data;
}

int process(string str)
{
    //Initializing the variables.

    const int length = str.length();
    char* str_char_array = new char[length];
    strcpy(str_char_array, str.c_str());

    bool flag=0;
    int i=0;

    //Running the loop for the entire length of the string.
    while(i<length)
    {
        //Pushing into the stack if the character to be processed is an opening parenthesis.
        if(str_char_array[i]=='('||str_char_array[i]=='{'||str_char_array[i]=='[')
        {
            push(&head, str_char_array[i]);
            i++;
            flag=0;
        }
        //Popping the stack if the character to be processed is a closing parenthesis.
        else if (str_char_array[i]==')'||str_char_array[i]=='}'||str_char_array[i]==']')
        {
            int data=pop(&head);
            //Processing the two characters.
            if((str_char_array[i]==')'&&data=='(')
            ||
            (str_char_array[i]=='}'&&data=='{')
            ||
            (str_char_array[i]==']'&&data=='['))
            {
                //Flagging a balancing of the parenthesis.
                flag=1;
            }
            else
            {
                //Flagging a non-balancing of the parenthesis.
                flag=0;
                break;
            }
            i++;
        }
    }
    return flag;
}

int main()
{
    cout<<"Enter the parentheses string : ";
    string str;
    cin>>str;
    int result=process(str);
    if(result==0)
    {
        cout<<"The parentheses are not balanced.";
    }
    else if(result==1)
    {
        cout<<"The parentheses are balanced.";
    }
}
