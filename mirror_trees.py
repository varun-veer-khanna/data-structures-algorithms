'''Given two Binary Trees, write a function that determines 
if two trees are mirror of each other.
For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true: 

Their root node’s key must be same
Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
Right subtree of ‘a’ and left subtree of ‘b’ are mirror.'''

# creating a data structure for storing the node of the tree
class Node:
    def __init__(self, data, left=None, right=None):
        self.data=data
        self.left=left
        self.right=right

# function to determine is the trees a mirror trees
def mirror_trees(head1, head2, flag):

    # flag value if 1 if tree is mirror tree or it is -1
    if flag==1:
        # if both trees are having no nodes or the function call has
        # traversed beyond the leaf nodes of the tree
        if head1==None and head2==None:
            flag=1
            return flag
        # if there is a node in one tree and no node in the other tree
        elif head1!=None and head2==None:
            flag=-1
            return flag
        # similary checking the same condition for the other tree
        elif head1==None and head2!=None:
            flag=-1
            return flag
        # if there are two nodes in the mirror position then checking
        # if the values in the nodes are equal
        elif head1.data==head2.data:
            flag=1
            flag=mirror_trees(head1.left, head2.right, flag)
            flag=mirror_trees(head1.right, head2.left, flag)
            return flag
        # If the above conditions are not satisfied then the trees are not mirror trees
        else:
            flag=-1
            return flag        
    # if the trees are not mirror trees
    elif flag==-1:
        return flag

# driver code    
if __name__=='__main__':
    
    # constructing the first tree
    head1=Node(1)
    head1.left=Node(3)
    head1.left.left=Node(6)
    head1.right=Node(2)
    head1.right.left=Node(5)
    head1.right.right=Node(4)

    # constructing the second tree
    head2=Node(1)
    head2.right=Node(3)
    head2.right.right=Node(6)
    head2.left=Node(2)
    head2.left.right=Node(5)
    head2.left.left=Node(4)

    # creating a flag with value 1 implying a mirror tree
    flag=1

    # calling the function
    flag=mirror_trees(head1, head2, flag)

    if flag==-1:
        print("Trees are not mirror trees")
    else:
        print("Trees are mirror trees")