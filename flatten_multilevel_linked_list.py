'''
Given a linked list where in addition to the next pointer, 
each node has a child pointer, which may or may not point to a separate list. 
These child lists may have one or more children of their own, and so on, 
to produce a multilevel data structure. 
You are given the head of the first level of the list. 
Flatten the list so that all the nodes appear in a single-level linked list. 
You need to flatten the list in way that all nodes at the first level should come first, 
then nodes of second level, and so on.
'''


class Node:
    def __init__(self, data, next=None, child=None):
        self.data=data
        self.next=None
        self.child=None

class LinkedList:
 
    # Function to initialize head
    def __init__(self):
        self.head = None
 
    # This function is defined in Linked List class
    # Appends a new node at the end.*/
    def append(self, new_data):
 
        # 1. Create a new node
        # 2. Put in the data
        # 3. Set next as None
        new_node = Node(new_data)
 
        # 4. If the Linked List is empty, then make the
        #    new node as head
        if self.head is None:
            self.head = new_node
            return
 
        # 5. Else traverse till the last node
        last = self.head
        while (last.next):
            last = last.next
 
        # 6. Change the next of last node
        last.next =  new_node

    def flatten_multilevel_linked_list(self, head, queue):
        # traversing the entire level till tail
        while(head)!=None:
            # appending into the flattened list
            self.append(head.data)
            # if the node has a child then append to queue
            if head.child!=None:
                queue.append(head.child)
            # move to next node
            head=head.next
        
        # traversing the child lists
        if queue:
            head=queue.pop(0)
            # recursively calling the function to traverse the child lists
            self.flatten_multilevel_linked_list(head, queue)
        else:
            return self

    # printing the flattened list    
    def printList(self):
        temp = self.head
        while (temp):
            print(temp.data, end=" ")
            temp = temp.next

# driver code
if __name__=='__main__': 
    
    # constructing the multi-level linked list
    head=None
    head=Node(10)
    head.next=Node(5)
    head.next.next=Node(12)
    head.next.next.next=Node(7)
    head.next.next.next.next=Node(11)

    head.child=Node(4)
    head.child.next=Node(20)
    head.child.next.next=Node(13)

    head.child.next.child=Node(2)
    head.child.next.next.child=Node(16)

    head.child.next.next.child.child=Node(3)

    head.next.next.next.child=Node(17)
    head.next.next.next.child.next=Node(6)

    head.next.next.next.child.child=Node(9)
    head.next.next.next.child.child.next=Node(8)

    head.next.next.next.child.child.child=Node(19)
    head.next.next.next.child.child.child.next=Node(15)

    # initiating the flattened list
    flathead=LinkedList()

    # queue is for storing the children lists
    queue=[]

    # calling the function for flattening the list
    flathead.flatten_multilevel_linked_list(head, queue)

    #printing the flattened list
    flathead.printList()
