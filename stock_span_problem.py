'''The stock span problem is a financial problem where we have a 
series of N daily price quotes for a stock and 
we need to calculate the span of the stock’s price for all N days. 
The span S of the stock’s price on a given day i is defined as 
the maximum number of consecutive days just before the given day, 
for which the price of the stock on the current day is 
less than its price on the given day. '''

def stockspan(price):
    S=[0]*len(price)
    checklist=[]
    for i in range(0, len(price)):
        if price:
            checking=price.pop(0)     
            checklist.append(checking)
            for j in range(len(checklist)-1, -1, -1):
                if checklist[j]<=checking:
                    S[i]=S[i]+1
                else:
                    break
                
    return S

if __name__=='__main__':
    price=[10, 4, 5, 90, 120, 80]
    counter=stockspan(price)
    print(*counter)