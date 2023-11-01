// Program to solve polynomial.
#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int degree,x;
    cout<<"Enter the degree of polynomial ";
    cin>>degree;
    int coeff[degree+1];
    cout<<"Enter value of x ";
    cin>>x;
    cout<<"Enter coefficients ";
    for(int i=0; i<degree+1; i++)
    {
        cin>>coeff[i];
    }
    int result1=0;
    for (int i=0; i<degree+1; i++)
    {
        //vv To improve the efficiency of the program you can use the repeated squaring algorithm
        //vv instead of the power function below.
        result1=result1+coeff[i]*pow(x,i);
    }
    cout<<"The result is "<<result1;
}