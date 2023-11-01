// Program to find maximum number in an array(better).

#include<iostream>


using namespace std;
//vv Implementing the function
int max(int arr[], int size)
{
    //Point to be noted. Only a pointer of an array is passed to a function, so size of the array
    //must be passed as a parameter.
    int i,maximum;
    maximum=arr[0];
    for(i=0; i<size-1; i++)
    {
        
        if(arr[i]<arr[i+1])
        {
            maximum=arr[i+1];	
                                
        }
                
    }
    //vv return the maximum number	
    return maximum;
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
       
    int result=max(arr, size);
    cout<<"The maximum number is "<<result;    
}