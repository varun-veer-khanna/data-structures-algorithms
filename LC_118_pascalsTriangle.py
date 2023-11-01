'''
LC_118
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
'''


from typing import List
import math


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascalsRow=[]
        pascalsTriangle=[]
        for i in range(0, numRows):
            if (i==0):
                pascalsRow=[1]
                pascalsTriangle.append(pascalsRow)
            elif (i==1):
                pascalsRow=[1,1]
                pascalsTriangle.append(pascalsRow)
            else:
                newPascalsRow=[]
                for i in range(0, len(pascalsRow)-1):
                    newPascalsRow.append(pascalsRow[i]+pascalsRow[i+1])
                newPascalsRow.append(1)
                newPascalsRow.insert(0,1)
                pascalsRow=newPascalsRow
                pascalsTriangle.append(pascalsRow)
        return pascalsTriangle
    


if __name__=='__main__':
    numRows=7
    #cin>>numRows;
    obj=Solution()
    pascalsTriangle=obj.generate(numRows);
    print(pascalsTriangle)