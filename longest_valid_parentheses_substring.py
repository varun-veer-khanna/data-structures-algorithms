

def longest_valid_parentheses_substring(string):
    i=0
    maxlength=0
    stack=[]
    maxlength=0
    stack.append(-1)
    i=0
    while i<len(string):
        if string[i]=='(':
            stack.append(i)
        else:
            if len(stack)!=0:
                stack.pop()
            if len(stack)!=0:
                length=i-stack[len(stack)-1]
                maxlength=max(length, maxlength)
            else:
                stack.append(i)
        i=i+1

    return maxlength


if __name__=='__main__':
    string='((()()'
    length=longest_valid_parentheses_substring(string)
    print(length)