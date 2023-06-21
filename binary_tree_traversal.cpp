/*   Program to create an binary tree with the following structure
               10
           /       \
           2        56
          / \      /   \
         77  88   34    1
         /         /   / \
        100       7   8   9

Then do tree traversals on it, namely, level order, inorder, preorder and postorder.
You need a (pre-order and inorder) or (pre-order and post-order) traversal of a tree to construct a tree uniquely.
*/

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

//Function for level order traversal.
void level_order_tree_traversal(node_class *root)
{
    //Return if the node is null
    if(root==NULL)
    {
        return;
    }
    //Create a queue for the nodes to be traversed.
    queue<node_class*> queue_of_nodes;
    //Push the root into the queue.
    queue_of_nodes.push(root);
    //Loop till the queue is not empty
    while(!queue_of_nodes.empty())
    {
        int queue_size=queue_of_nodes.size();

        while(queue_size>0)
        {
            //Extract the value at the front of the queue.
            node_class *node=queue_of_nodes.front();
            //Pop the queue.
            queue_of_nodes.pop();
            //Process the stored value
            cout<<node->data<<"  ";
            //Push the child nodes of the stored node into the queue.
            for(int i=0; i<1; i++)
            {
                if(node->left_child!=NULL)
                {
                    queue_of_nodes.push(node->left_child);
                }
                if(node->right_child!=NULL)
                {
                    queue_of_nodes.push(node->right_child);
                }
            }
            queue_size--;
        }
        //Change a line at every level of the tree.
        cout<<endl;
    }
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

// Function for preorder traversal : root, left child, right child.
void preorder_tree_traversal(node_class *node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<"  ";

    preorder_tree_traversal(node->left_child);

    preorder_tree_traversal(node->right_child);
}

// Function for postorder traversal : left child, right child, root.
void postorder_tree_traversal(node_class *node)
{
    if(node==NULL)
    {
        return;
    }

    postorder_tree_traversal(node->left_child);

    postorder_tree_traversal(node->right_child);

    cout<<node->data<<"  ";
}

//Driver code
int main()
{
    node_class *root=new_node(10);
    root->left_child=new_node(2);
    root->right_child=new_node(56);
    root->left_child->left_child=new_node(77);
    root->left_child->right_child=new_node(88);
    root->left_child->left_child->left_child=new_node(100);
    root->right_child->left_child=new_node(34);
    root->right_child->left_child->left_child=new_node(7);
    root->right_child->right_child=new_node(1);
    root->right_child->right_child->left_child=new_node(8);
    root->right_child->right_child->right_child=new_node(9);
    cout << "Level order traversal is \n";
    level_order_tree_traversal(root);
    cout << "Inorder traversal is \n";
    inorder_tree_traversal(root);
    cout << "\nPreorder traversal is \n";
    preorder_tree_traversal(root);
    cout << "\nPostorder traversal is \n";
    postorder_tree_traversal(root);
}
