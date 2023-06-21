'''
Josephus Circle
There are n people standing in a circle waiting to be executed. 
The counting out begins at some point in the circle and 
proceeds around the circle in a fixed direction. 
In each step, a certain number of people are skipped 
and the next person is executed. 
The elimination proceeds around the circle 
(which is becoming smaller and smaller as the executed people are removed), 
until only the last person remains, who is given freedom. 
Given the total number of person n and 
a number k which indicates that k-1 persons are skipped and 
the kth person is killed in the circle. 
The task is to choose the place in the initial circle so that 
you are the last one remaining and so survive. (0-based indexing)
'''

class Node:
    def __init__(self, data):
        self.data=data
        self.next=None

def delete(prev, head):
    prev.next=head.next
    return head.next

def josephus(n, k):
    #constructing the linked list
    new_node=Node(0)
    head=new_node

    for x in range(1, n):
        new_node.next=Node(x)        
        new_node=new_node.next    
    #linking the last node with the head of the linked list
    new_node.next=head
    
    prev=head
    while head!=head.next:
    #while there is a node in the circular linked list    
        for x in range(0, k-1):
            #iterating up till the person to be executed
            prev=head
            head=head.next
        
        #executing the person    
        head=delete(prev, head)
    
    return head.data

if __name__ == '__main__':
    position=josephus(14, 2)
    print(position)