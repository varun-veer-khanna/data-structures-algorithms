
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    def hasCycle(self, head) -> bool:
        if head==None or head.next==None:
            return False
        elif head.val=='a':
            return True
        else:
            head.val='a'
            head=head.next
            return self.hasCycle(head)

if __name__=='__main__':
    '''head=ListNode(3)
    head.next=ListNode(2)
    head.next.next=ListNode(0)
    head.next.next.next=ListNode(-4)
    head.next.next.next.next=head.next'''
    head=ListNode(1)
    '''head.next=ListNode(2)
    head.next.next=head'''
    obj=Solution()
    flag=obj.hasCycle(head)
    if flag==False:
        print("The list has no cycle.")
    else:
        print("The list has cycle.")