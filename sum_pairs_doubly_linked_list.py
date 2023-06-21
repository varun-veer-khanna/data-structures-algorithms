'''Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in a doubly-linked list whose sum is equal to given value x, 
without using any extra space'''

# Structure of node of doubly linked list
class Node:
	
	def __init__(self, x, prev=None, next=None):
		
		self.data = x
		self.next = next
		self.prev = prev

# Function to find pair whose sum
# equal to given value x.
def pairSum(head, sum):
	ptr1=head	
	while ptr1 != None:
		ptr2=ptr1.next
		while ptr2 != None:
			if ptr1.data+ptr2.data==sum:
				print("(",ptr1.data,",",ptr2.data,")")
			ptr2=ptr2.next			
		ptr1=ptr1.next

# A utility function to insert a new node
# at the beginning of doubly linked list
def insert(head, data):
	 
	temp = Node(data)
	 
	if not head:
		head = temp
	else:
		temp.next = head
		head.prev = temp
		head = temp		 
	return head
  

def printList(head):
	while (head):
		print(head.data,end=" ")
		head = head.next

# Driver code
if __name__ == '__main__':
	
	head = None
	head = insert(head, 9)
	head = insert(head, 8)
	head = insert(head, 6)
	head = insert(head, 5)
	head = insert(head, 4)
	head = insert(head, 2)
	head = insert(head, 1)
	x = 7

	pairSum(head, x)

# This code is contributed by mohit kumar 29
