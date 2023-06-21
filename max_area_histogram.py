'''
Find the largest rectangular area possible in a given histogram 
where the largest rectangle can be made 
of a number of contiguous bars whose heights are given in an array. 
For simplicity, assume that all bars have the same width and the width is 1 unit. '''


'''To solve the problem follow the below idea:

Find the previous and the next smaller element for every element of the histogram, 
as this would help to calculate the length of the subarray in which 
this current element is the minimum element. 
So we can create a rectangle of size (current element * length of the subarray) 
using this element. Take the maximum of all such rectangles.'''


def max_area_histogram(histogram):
    areas=[]
    if histogram:
        count=0
        for i in range(0, len(histogram)):
            if histogram[i]==0:
                count=0
                break
            else:
                count=1
                for j in range(i-1, -1, -1):
                    if histogram[j]<histogram[i]:
                        break
                    else:
                        count=count+1
                for j in range(i+1, len(histogram)):
                    if histogram[j]<histogram[i]:
                        break
                    else:
                        count=count+1
            areavalue=histogram[i]*count
            areas.append(areavalue)
    return max(areas)

if __name__=='__main__':
    histogram=[6, 2, 5, 4, 5, 1, 6]
    area=max_area_histogram(histogram)
    print(area)