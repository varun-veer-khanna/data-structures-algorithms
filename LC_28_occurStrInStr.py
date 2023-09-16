'''
LC_28
Given two strings needle and haystack, 
return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.'''


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        output=-1
        for i in range(0, len(haystack)-len(needle)+1):
            if haystack[i:i+len(needle)]==needle:
                output=i
                break
        return output

if __name__=='__main__':
    obj=Solution()
    haystack="a"
    needle="a"
    output=obj.strStr(haystack, needle)
    print(output)