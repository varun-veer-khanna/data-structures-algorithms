/*   Program to create an general tree with the following structure
                 10
           /   /    \   \
           2  34    56   100
          / \         |   /  | \
         77  88       1   7  8  9
Then do level order traversal order on it.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// To create node structure
class node_class
{
    public:
    int data;
    vector<node_class*> child;
};

// Function to create a new node of tree
node_class* new_node(int data)
{
    node_class *ptr=new node_class;
    ptr->data=data;
    return ptr;
}

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
            //Process the stored value
            cout<<node->data<<"  ";
            //Pop the queue.
            queue_of_nodes.pop();
            //Push the child nodes of the stored node into the queue.
            for(int i=0; i<node->child.size(); i++)
            {
                queue_of_nodes.push(node->child[i]);
            }
            queue_size--;
        }
        //Change a line at every level of the tree.
        cout<<endl;
    }
}

//Driver code
int main()
{
    node_class *root=new_node(10);
    (root->child).push_back(new_node(2));
    (root->child).push_back(new_node(34));
    (root->child).push_back(new_node(56));
    (root->child).push_back(new_node(100));
    (root->child[0]->child).push_back(new_node(77));
    (root->child[0]->child).push_back(new_node(88));
    (root->child[2]->child).push_back(new_node(1));
    (root->child[3]->child).push_back(new_node(7));
    (root->child[3]->child).push_back(new_node(8));
    (root->child[3]->child).push_back(new_node(9));
    cout << "Level order traversal is \n";
    level_order_tree_traversal(root);
}
