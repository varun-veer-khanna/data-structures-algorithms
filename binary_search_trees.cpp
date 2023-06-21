//Partly works
//To create a binary search tree from an array and to delete nodes from it.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// To create node structure
class node_class
{
    public:
    int data;
    node_class* left_child;
    node_class* right_child;
};

// Function to create a new node of tree
node_class* new_node(int data)
{
    node_class *ptr=new node_class;
    ptr->data=data;
    ptr->left_child=NULL;
    ptr->right_child=NULL;
    return ptr;
}

node_class* node_placer(node_class *node, int number)
{
    if(node==NULL)
    {
        node=new_node(number);
    }
    else if(number<node->data)
    {
        node->left_child=node_placer(node->left_child, number);
    }
    else if(number>node->data)
    {
        node->right_child=node_placer(node->right_child, number);
    }
    return node;
}

node_class* node_deleter(node_class *node, int number)
{
    if (node == NULL)
        return node;

    if(number<node->data)
    {
        node->left_child=node_deleter(node->left_child, number);
    }
    else if(number>node->data)
    {
        node->right_child=node_deleter(node->right_child, number);
    }

    if(node->right_child==NULL)
    {
        node_class *temp=node->left_child;
        delete node;
        return temp;
    }
    else if(node->left_child==NULL)
    {
        node_class *temp=node->right_child;
        delete node;
        return temp;

    }
    else
    {
        node_class *current=node->right_child;
        while(current && current->left_child != NULL)
        {
            current=current->left_child;
        }
        node->data=current->data;
        node_deleter(node->right_child, current->data);
    }




    return node;
}

// Function for inorder traversal : left child, root, right child.
void inorder_tree_traversal(node_class *node)
{
    if(node==NULL)
    {
        return;
    }
    inorder_tree_traversal(node->left_child);

    cout<<node->data<<"  ";

    inorder_tree_traversal(node->right_child);
}

node_class* bst_constructor(vector<int> &array)
{
    node_class *root=new_node(array[0]);
    for(int i=1; i<array.size(); i++)
    {
        node_placer(root, array[i]);
    }
    return root;
}

int main()
{
    vector<int> array={10,2,77,100,88,56,34,7,1,8,9};
    node_class* root=bst_constructor(array);
    cout<<"The binary search tree is :\n";
    inorder_tree_traversal(root);
    node_deleter(root, 2);
    cout<<"\nThe binary search tree after deletion is :\n";
    inorder_tree_traversal(root);
    return 0;
}
