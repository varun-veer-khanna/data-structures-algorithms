// Program to find maximum and mimimum number in an array(better) with
// just 3n/2 steps rather than the required 2n-2 steps.

#include<iostream>


using namespace std;
//vv Implementing the function
int *max(int arr[], int size)
{
    int i;
    static int result[2];
    /*Static is a keyword in C++ used to give special characteristics to an element. 
    Static elements are allocated storage only once in a program lifetime in static storage area. 
    And they have a scope till the program lifetime. 
    Static Keyword can be used with following,

    1. Static variable in functions
    2. Static Class Objects
    3. Static member Variable in class
    4. Static Methods in class
    */
    result[0]=arr[0];//min
    result[1]=arr[1];//max
    
    for(i=0; i<size-1; i++)
    {
        if(arr[i]<arr[i+1])
        {
            if(result[0]>arr[i])
            {
                result[0]=arr[i];
            }
            if(result[1]<arr[i+1])
            {
                result[1]=arr[i+1];
            }			
        }
        else
        {
            if(result[0]>arr[i+1])
            {
                result[0]=arr[i+1];
            }
            if(result[1]<arr[i])
            {
                result[1]=arr[i];
            }
        }		
    }
    //vv return the array containing both the maximum and minimum numbers	
    return result;
}
int main()
{
    int size, i;
    cout<<"Enter the array size ";
    cin>>size;
    int arr[size];
    cout<<"Enter the numbers ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
      
    //vv Calling the function
       
    int* result=max(arr, size);
    
    cout<<"The minimum number is "<<result[0]<<endl;
    cout<<"The maximum number is "<<result[1];    
}