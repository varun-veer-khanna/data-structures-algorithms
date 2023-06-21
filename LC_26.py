class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        set={}
        set=set(nums)
        print(set)

list=[1,2,2,3,4,4,5,5,5,6]
obj=Solution()
obj.removeDuplicates(list)