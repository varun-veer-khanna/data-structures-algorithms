

s = "*+AB-CD"

stack=[]

s=s[::-1]


operators = set(['+', '-', '*', '/', '^'])

str=""

for x in s:
    if x in operators:
        a=stack.pop()
        b=stack.pop()
        str=a+b+x
        stack.append(str)
    else:
        stack.append(x)

print(*stack)