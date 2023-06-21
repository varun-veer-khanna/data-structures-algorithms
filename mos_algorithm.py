# Python program to compute sum of ranges for different range queries
 
import math
 
# Function that accepts array and list of queries and print sum of each query
def queryResults(arr,Q):
    Q.sort(key=lambda x:x[1])
    currL,currR,currSum = 0,0,0

    for i in range(len(Q)):
        L,R=Q[i]

        while currL<L:
            currSum=currSum-arr[currL]
            currL=currL+1

        while currL>L:
            currSum=currSum+arr[currL-1]
            currL=currL-1
        
        while currR>R+1:
            currSum=currSum-arr[currR-1]
            currR=currR-1

        while currR<=R:
            currSum=currSum+arr[currR]
            currR=currR+1
        print("Sum of",Q[i],"is",currSum)
    

arr = [1, 1, 2, 1, 3, 4, 5, 2, 8]
Q = [[0, 4], [1, 3], [2, 4]]
queryResults(arr,Q)