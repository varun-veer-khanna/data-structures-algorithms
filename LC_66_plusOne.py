''' 
LC_66
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
'''



from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # running the entire length of the list
        for i in range(len(digits)-1, -1, -1):
            # if the digit is 9 then replace it with 0, else increment by 1
            if digits[i]==9:
                digits[i]=0
            else:
                digits[i]=digits[i]+1
                break
            # if the leading digit is to be incremented then add addition 1
            # as the new leading digit
            if i==0 and digits[i]==0:
                digits.insert(0, 1)
        return digits

# driver code
if __name__=='__main__':
    obj=Solution()
    digits=[9,9,9]
    digits=obj.plusOne(digits)
    print(digits)