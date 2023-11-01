// Program to find exponent using repeated squaring.
/*repeated squaring

(algorithm)

Definition: Compute the nth power of an expression in T(log n) steps by repeatedly squaring an intermediate result and multiplying an accumulating value by the intermediate result when appropriate.

Note: To find x13 one could multiple 13 x's together. This is slow if multiplication is time consuming (e.g., matrix multiplication) or the exponent is very large.

Instead, write the exponent in binary notation.

     13 = 1101 

Start with a "squares" value (s) equal x and an "accumulated" value (a) equal 1. Reading from least significant bit to most significant, when there is a 1 in the binary notation, multiply a by s. Keep squaring s.
  s  	  a   	
x1 	1 	
        Least significant bit of exponent is 1, so multiply a = a * s
x1 	x1 	
        Square s
x² 	x1 	
        Next bit is 0, so don't multiply
x² 	x1 	
        Square s
x4 	x1 	
        Next bit is 1, so multiply
x4 	x5 	
        Square s
x8 	x5 	
        Highest bit is 1, so multiply
x8 	x13 	

Why does this work? Consider the exponent decomposed into binary notation.

     x13 = x1101			
 						
         = x(1*2^3 + 1*2^2 + 0*2^1 + 1*2^0)		
 						
         = x1*2^3* x1*2^2* x0*2^1* x1*2^0		
 						
         = x2^3  * x2^2  *  1    * x2^0 
 						
         = x8    * x4            * x1 */
#include<iostream>
#include<cmath>
#include <bitset>

using namespace std;
# define N 16

int main() {
    long long int x;
    cout<<"Please enter base";
    cin>>x;
    long long int y;
    cout<<"Please enter exponent";
    cin>>y;
    //vv creating binary value of exponent
    bitset<N> n(y);
    int i=15;
    while (n[i]!=1)
    {
        //vv reducing size value of array
        i--;
    }
    //vv initializing new array on the basis of input
    int a[i+1];
    for(i;i>=0;i--)
    {
        a[i]=n[i];
    }
    long long int result=1; 
    int q=0;
    for(i=0; i<sizeof(a)/sizeof(int); i++)
    {
        //vv if binary bit is 1 do the following
        if(a[i]==1)
        {
            result=result*pow(x,pow(2,q));
            q++;
        }
        //vv if binary bit is 0 do the following
        else if (a[i]==0)
        {
            result=result*1;
            q++;
        }
    }
    cout<<"The result is "<<result;
}