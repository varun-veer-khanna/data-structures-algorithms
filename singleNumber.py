from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        try:
            for i in range(0, len(nums), 2):
                storedNumber1=nums[i]
                storedNumber2=nums[i+1]
                if storedNumber1==storedNumber2:
                    pass
                else:
                    return storedNumber1
        except IndexError:
            return nums[-1]

if __name__=='__main__':
    nums=[1]
    obj=Solution()
    singleNumber=obj.singleNumber(nums)
    print(singleNumber)