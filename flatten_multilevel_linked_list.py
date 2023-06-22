

class Node:
    def __init__(self, data, next=None, child=None):
        self.data=data
        self.next=None
        self.child=None

def newNode(data):
    return Node(data)

def flatten_multilevel_linked_list(head, flathead, queue):
    while(head)!=None:
        print(head.data)
        flathead=newNode(head.data)
        if head.child!=None:
            queue.append(head.child)
        #flathead=flathead.next
        head=head.next
    
    if queue:
        head=queue.pop(0)
        flatten_multilevel_linked_list(head, flathead, queue)
    else:
        return flathead
    
def printList(head): 
    print("yoyoyoyyoy")
    if not head: 
        return
    while(head): 
        print("{}".format(head.data), end = " ") 
        head = head.next

if __name__=='__main__': 
    head=None
    head=newNode(10)
    head.next=newNode(5)
    head.next.next=newNode(12)
    head.next.next.next=newNode(7)
    head.next.next.next.next=newNode(11)

    head.child=newNode(4)
    head.child.next=newNode(20)
    head.child.next.next=newNode(13)

    head.child.next.child=newNode(2)
    head.child.next.next.child=newNode(16)

    head.child.next.next.child.child=newNode(3)

    head.next.next.next.child=newNode(17)
    head.next.next.next.child.next=newNode(6)

    head.next.next.next.child.child=newNode(9)
    head.next.next.next.child.child.next=newNode(8)

    head.next.next.next.child.child.child=newNode(19)
    head.next.next.next.child.child.child.next=newNode(15)

    flathead=None
    queue=[]

    flathead=flatten_multilevel_linked_list(head, flathead, queue)

    printList(flathead)
