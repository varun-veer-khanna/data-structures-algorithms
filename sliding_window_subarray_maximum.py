'''
Given an array and an integer K, 
find the maximum for each and every contiguous subarray of size K.
'''

from collections import deque

def sliding_window_subarray_maximum(array, k):
    # creating deque structure
    queue=deque()

    # initializing the initial k values
    for i in range(0, k):
        queue.append(array[i])
    
    # finding the maximum of those initial values
    maxvalue=max(queue)
    print(maxvalue, end=" ")

    # sliding the window by looping through the rest of the array
    for j in range(k, len(array)):
        queue.popleft()
        queue.append(array[j])
        maxvalue=max(queue)
        print(maxvalue, end=" ")

# driver code
if __name__=='__main__':
    array=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    k=3
    sliding_window_subarray_maximum(array, k)