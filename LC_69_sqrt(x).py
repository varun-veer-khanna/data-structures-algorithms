'''
LC_69
Given a non-negative integer x, 
return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
'''


class Solution:
    def mySqrt(self, x: int) -> int:
        start=0
        end=x
        if x==0 or x==1:
            return x
        while end>start:
            mid=(start+end)/2
            if int(mid*mid)==x:
                return int(mid)
            elif mid*mid>x:
                end=mid
            else:
                start=mid
        return int(end)



if __name__=='__main__':
    obj=Solution()
    x=8
    output=obj.mySqrt(x)
    print(output)