

def find_celebrity(matrix):
    if matrix:
        for i in range(len(matrix)):
            for k in range(len(matrix[i])):
                if matrix[i][k]==0:
                    flag=True
                else:
                    flag=False
        for i in range(len(matrix)):
            for k in range(len(matrix[i])):
                if matrix[j][i]==1:
                    return -1
                else:
                    return i

if __name__=='__main__':
    matrix = [[0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 0], [0, 0, 1, 0]]
    celebrity_id = find_celebrity(matrix)
    if celebrity_id != -1:
        print("Celebrity is : ", celebrity_id)
    else:
        print("No celebrity")