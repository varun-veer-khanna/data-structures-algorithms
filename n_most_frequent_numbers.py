'''
Given an array of N numbers and a positive integer K. 
The problem is to find K numbers with the most occurrences, 
i.e., the top K numbers having the maximum frequency. 
If two numbers have the same frequency then the number with a larger value 
should be given preference. 
The numbers should be displayed in decreasing order of their frequencies. 
It is assumed that the array consists of at least K numbers.
'''

def N_mostFrequentNumber(array, n, k):
    thisdict={}
    for x in array:
        y=thisdict.get(x)
        if y==None:
            thisdict.update({x: 1})
        else:
            thisdict.update({x: y+1})
    
    newlist=list(thisdict.items())

    newlist = sorted(newlist, key=lambda x:x[0])
    newlist = sorted(newlist, key=lambda x:x[1])

    for x in range(len(newlist)-1, len(newlist)-k-1, -1):
        print(newlist[x][0])

                

array=[3, 1, 4, 4, 5, 2, 6, 1]
k=2
N_mostFrequentNumber(array, len(array), k)