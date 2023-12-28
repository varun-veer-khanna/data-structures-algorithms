'''
LC_160
Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode):
        permaA=headA
        permaB=headB

        while permaA!=permaB:
            if permaA==None:
                permaA=headB
            else:
                permaA=permaA.next
            if permaB==None:
                permaB=headA
            else:
                permaB=permaB.next
        
        return permaA

if __name__=='__main__':
    '''headC=ListNode(8)
    headC.next=ListNode(4)
    headC.next.next=ListNode(5)

    headA=ListNode(4)
    headA.next=ListNode(1)
    headA.next.next=headC

    headB=ListNode(5)
    headB.next=ListNode(6)
    headB.next.next=ListNode(1)
    headB.next.next.next=headC'''

    '''headC=ListNode(2)
    headC.next=ListNode(4)

    headA=ListNode(1)
    headA.next=ListNode(9)
    headA.next.next=ListNode(1)
    headA.next.next.next=headC

    headB=ListNode(3)
    headB.next=headC'''

    '''headA=ListNode(2)
    headA.next=ListNode(6)
    headA.next.next=ListNode(4)

    headB=ListNode(1)
    headB.next=ListNode(5)'''

    headA=ListNode(3)

    headB=ListNode(2)
    headB.next=headA

    obj=Solution()
    returnedNode=obj.getIntersectionNode(headA, headB)
    if returnedNode==None:
        print("No intersection")
    else:
        print(returnedNode.val)