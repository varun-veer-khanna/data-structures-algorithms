'''
LC_125
A phrase is a palindrome if, after converting all uppercase letters into 
lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
'''

import re

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = re.sub(r'[\W_]', '', s.lower())
        if len(s)%2==0:
            if s[:len(s)//2]==s[:len(s)//2-1:-1]:
                return True
            else:
                return False
        else:
            if s[:len(s)//2]==s[:len(s)//2:-1]:
                return True
            else:
                return False

if __name__=='__main__':
    s="aassa"
    obj=Solution()
    flag=obj.isPalindrome(s)
    if flag==True:
        print("The string is palindrome")
    else:
        print("The string is not palindrome")