// Program to implement unordered linear search.

#include<iostream>


using namespace std;
//vv Implementing the search function
int search(int key, int size, int arr[])
{
    for(int i=0; i<size; i++)
    {
        //vv If key is found
        if(arr[i]==key)
        {
            return i;			
        }		
    }
    //vv else return -1	
    return -1;
}
int main()
{
    int size, key, i;
    cout<<"Enter the array size ";
    cin>>size;
    int arr[size];
    cout<<"Enter the numbers ";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the key ";
    cin>>key;
    //vv Calling the search function
    int result=search(key, size, arr);
    if (result==-1)
    {
        cout<<"The key was not found";			
    }
    else
    {
        cout<<"The key was found at location "<<result;
    }
    
}