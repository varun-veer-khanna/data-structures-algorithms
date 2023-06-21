'''
Given string str, we need to print the reverse of individual words.
'''
str="Hello World"

stack=[]

str=str.split(" ")

print(str)

resultstr=""

for item in str:
    for x in item[::-1]:
        resultstr=resultstr+x
    resultstr=resultstr+" "

print(resultstr)