'''Given a sorted doubly linked list of positive distinct elements, 
the task is to find pairs in a doubly-linked list whose sum is equal to given value x, 
without using any extra space'''

class Node:
	def __init__(self, data, next=None):
		self.data=data
		self.next=next

def insert(head, data):
	new_node=Node(data)

	if head==None:
		head=new_node
	else:
		new_node.next=head
		head=new_node

	return head

def append(head, data):
	new_node=Node(data)
	temp=head
	if head==None:

		head=new_node

	else:

		while(temp.next):
			temp=temp.next

		temp.next=new_node
	
	return head



def printList(head):

	while (head):
		print(head.data)
		head=head.next

def intersection(head1, head2):
	ptr1=head1
	ptr2=head2
	head3=None

	while (ptr1!=None and ptr2!=None):

		
		if ptr1.data==ptr2.data:

			head3=append(head3, ptr1.data)

			ptr1=ptr1.next
			ptr2=ptr2.next
			
		elif ptr1.data<ptr2.data:

			ptr1=ptr1.next
		else:

			ptr2=ptr2.next
	printList(head3)

	
	




if __name__=='__main__':
	head1 = None
	head1 = insert(head1, 6)
	head1 = insert(head1, 4)
	head1 = insert(head1, 3)
	head1 = insert(head1, 2)
	head1 = insert(head1, 1)
	

	head2 = None
	head2 = insert(head2, 8)
	head2 = insert(head2, 6)
	head2 = insert(head2, 4)
	head2 = insert(head2, 2)


	intersection(head1, head2)