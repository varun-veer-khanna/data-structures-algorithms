'''Python program to print the middle of linked list.'''
class Node:
    def __init__(self, data, next=None):
        self.data=data
        self.next=next


class LinkedList:
    def __init__(self):
        self.head=None
    
    def append(self, new_data):
        
        new_node=Node(new_data)

        if self.head is None:
            self.head=new_node
            return

        temp=self.head
        while (temp.next):
            temp=temp.next
        
        temp.next=new_node
    
    def printList(self):
        temp=self.head
        count=0
        
        print("The linked list is ")
        while (temp):
            print(temp.data)
            count=count+1
            temp=temp.next
        
        temp=self.head
        for x in range(int(count/2)):
            temp=temp.next
        print("The middle of linked list is ")
        print(temp.data)

if __name__=='__main__':
    list=LinkedList()

    list.append(1)
    list.append(2)
    list.append(3)
    list.append(4)
    list.append(5)
    list.append(6)
    list.printList()