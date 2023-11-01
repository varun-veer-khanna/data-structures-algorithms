// Program to implement Horner's method for polynomial evaluation.
// It requires n steps and is an optimal algorithm.
/*To implement a polynomial -
f(x0) = a0 + a1x0 + a2x02 + ... + anx0n
This can, also, be written as:
f(x0) = a0 + x0(a1 + x0(a2 + x0(a3 + ... + (an-1 + anx0)....) */

#include<iostream>

using namespace std;

int main() {
    int x, i, degree;
    cout<<"Enter the degree of polynomial ";
    cin>>degree;
    cout<<"Enter value of x ";
    cin>>x;
    int coeff[degree+1];
    cout<<"Enter coefficients ";
    for(i=0; i<degree+1; i++)
    {
        cin>>coeff[i];
    }
    int result=0, pow=1;
    //Implementing Horner's method.
    for(i=0;i<degree+1;i++)
    {
        result=result+pow*coeff[i];
        pow=x*pow;		
    }
    cout<<"The result is "<<result;
}