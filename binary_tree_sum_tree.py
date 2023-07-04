'''Write a function that 
returns true if the given Binary Tree is SumTree else false. 
Sum Tree is a binary tree. 
A binary tree is a tree data structure where each parent node 
has a maximum of 2 child nodes. 
Sum tree is a special kind of binary tree where 
the value of a parent node is equal to 
the sum of the values of its children.'''

# creating the node data structure
class Node:
    def __init__(self, data, left=None, right=None):
        self.data=data
        self.left=None
        self.right=None

# function for checking if the binary tree is sum tree
def binary_tree_sum_tree(head, flag):
    # flag is 1 if the sum tree condition is satisfied, otherwise it is -1
    if flag==1:
        # checking if the node being checked is a lef node
        if head.left==None and head.right==None:
            flag=1
            return flag
        # checking if node just has a left child
        elif head.left!=None and head.right==None:
            # checking if the left child has the same value as the node itself then
            # it still satisfies the condition of a sum tree
            if head.left.data==head.data:
                flag=binary_tree_sum_tree(head.left, flag)
            # if not then the sum tree condition is not satisfied
            else:
                flag=-1
                return flag
        # doing the same if the node just has a right child
        elif head.left==None and head.right!=None:
            # checking if the right child has the same value as the node itself then
            # it still satisfies the condition of a sum tree
            if head.right.data==head.data:
                flag=binary_tree_sum_tree(head.right, flag)
            # if not then the sum tree condition is not satisfied
            else:
                flag=-1
                return flag
        # checking if the data of the node is the sum of data of left and right children
        elif head.data==head.left.data+head.right.data:
            flag=1
            # calling the function recursively for the left and right node sub-trees
            flag=binary_tree_sum_tree(head.left, flag)
            flag=binary_tree_sum_tree(head.right, flag)

            return flag
        # if the above conditions are not being satisfied then that means that
        # the tree is not a sum tree
        else:
            flag=-1
            return flag
    # if the binary tree is not a sum tree then return the value of -1
    elif flag==-1:
        return flag

# drive code
if __name__=='__main__':
    # constructing the binary tree
    head=Node(26)
    head.left=Node(10)
    head.right=Node(16)
    head.left.left=Node(3)
    head.left.right=Node(7)
    head.right.left=Node(10)
    head.right.right=Node(6)
    head.right.left.left=Node(5)
    head.right.left.right=Node(5)
    head.right.left.left.right=Node(5)

    # creating a flag with value 1 implying a sum tree
    flag=1
    
    # calling the function
    flag=binary_tree_sum_tree(head, flag)


    if flag==-1:
        print("Tree is not sum tree")
    else:
        print("Tree is sum tree")