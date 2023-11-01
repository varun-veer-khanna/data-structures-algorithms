/*
Example

To compute the product of 12345 and 6789, where B = 10, choose m = 3. We use m right shifts for decomposing the input operands using the resulting base (Bm = 1000), as:

12345 = 12 · 1000 + 345

6789 = 6 · 1000 + 789

Only three multiplications, which operate on smaller integers, are used to compute three partial results:

z2 = 12 × 6 = 72

z0 = 345 × 789 = 272205

z1 = (12 + 345) × (6 + 789) − z2 − z0 = 357 × 795 − 72 − 272205 = 283815 − 72 − 272205 = 11538

We get the result by just adding these three partial results, shifted accordingly (and then taking carries into account by decomposing these three inputs in base 1000 like for the input operands):

result = z2 · (Bm)2 + z1 · (Bm)1 + z0 · (Bm)0, i.e.

result = 72 · 10002 + 11538 · 1000 + 272205 = 83810205.

If the number of digits is four or more, the three multiplications in Karatsuba's basic step involve operands with fewer than n digits. Therefore, those products can be computed by recursive calls of the Karatsuba algorithm. The recursion can be applied until the numbers are so small that they can (or must) be computed directly.
*/
// Program to implement Karatsuba's algorithm for multiplication.

#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int x, y;
    cout<<"Enter the numbers ";
    cin>>x>>y;
    //vv Checking which of the two is larger and swapping if required.
    if(x<y)
    {
        x=x+y;
        y=x-y;
        x=x-y;
    }
    
    //vv Finding the exponent of 10 to be used.
    int xn=log10(x)+1;
    xn=xn/2+1;
    
    //vv Dividing the numbers
    int xa=x/pow(10, xn);
    int xb=pow(10, xn);
    xb=x%xb;
    
    int ya=y/pow(10, xn);
    int yb=pow(10, xn);
    yb=y%yb;
    
    //vv Doing the multiplications
    int z2=xa*ya;
    int z0=xb*yb;
    int z1=(xa+xb)*(ya+yb)-z2-z0;
    
    int result=z2*pow(10, 2*xn)+z1*pow(10, xn)+z0;
    
    cout<<"The product is "<<result;	
}