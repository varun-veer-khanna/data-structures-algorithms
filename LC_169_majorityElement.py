'''
LC_169

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Linear time and O(1) space.
'''

from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate=-1
        count=0
        for item in nums:
            if count==0:
                candidate=item
            
            if item==candidate:
                count=count+1
            else:
                count=count-1
        return candidate
    
if __name__=='__main__':
    nums=[3,3,4]
    obj=Solution()
    returnedElement=obj.majorityElement(nums)
    print(returnedElement)