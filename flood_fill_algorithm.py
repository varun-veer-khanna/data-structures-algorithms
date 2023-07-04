'''
Given a 2D screen array[][] where each array[i][j] is 
an integer representing the color of that pixel, 
also given the location of a pixel (X, Y) and a color C, 
the task is to replace the color of the given pixel 
and all the adjacent same-colored pixels with the given color.
'''

# creating a data structure for storing the coordinates of a
# point in the matrix/array

class Coordinates:
    def __init__(self, x, y):
        self.x=x
        self.y=y

def flood_fill_algorithm(array, original_point, original_colour, new_colour, queue):
    
    # assigning the new colour to the point
    array[original_point.x][original_point.y]=new_colour
    x=original_point.x
    y=original_point.y
    
    # checking out the colour of each and every point adjacent to the original point and
    # appending it to queue if required
    # exception handling has to be implemented to handle cases
    # in which the coordinate being checked is outside the coordinates of the matrix/array
    try:
        if array[x+1][y]==original_colour:
            new_point=Coordinates(x+1, y)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x+1][y+1]==original_colour:
            new_point=Coordinates(x+1, y+1)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x][y+1]==original_colour:
            new_point=Coordinates(x, y+1)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x-1][y+1]==original_colour:
            new_point=Coordinates(x-1, y+1)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x-1][y]==original_colour:
            new_point=Coordinates(x-1, y)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x-1][y-1]==original_colour:
            new_point=Coordinates(x-1, y-1)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x][y-1]==original_colour:
            new_point=Coordinates(x, y-1)
            queue.append(new_point)
    except IndexError:
        pass
    try:
        if array[x+1][y-1]==original_colour:
            new_point=Coordinates(x+1, y-1)
            queue.append(new_point)
    except IndexError:
        pass
    
    # if queue is not empty then
    # that means that there are more points adjacent which have the original colour
    if queue:
        original_point=queue.pop(0)
        array=flood_fill_algorithm(array, original_point, original_colour, new_colour, queue)
    else:
        return array

    
# function for printing the array
def print_array(array):
    for i in range(0, len(array)):
        for j in range(0, len(array[i])):
            print(array[i][j], end=' ')
        print()

# driver code
if __name__=='__main__':
    array = [
[1, 1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 0, 0],
[1, 0, 0, 1, 1, 0, 1, 1],
[1, 2, 2, 2, 2, 0, 1, 0],
[1, 1, 1, 2, 2, 0, 1, 0],
[1, 1, 1, 2, 2, 2, 2, 0],
[1, 1, 1, 1, 1, 2, 1, 1],
[1, 1, 1, 1, 1, 2, 2, 1],
    ]
    locx=4
    locy=4

    new_colour=3
    
    # queue is for storing point coordinates which have the original colour
    queue=[]
    
    # storing the value of the original point in the object of the Coordinates class
    original_point=Coordinates(locx, locy)
    queue.append(original_point)

    original_colour=array[locx][locy]
    
    flood_fill_algorithm(array, original_point, original_colour, new_colour, queue)
    
    print_array(array)