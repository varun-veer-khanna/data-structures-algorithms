// Program to implement binary search.
#include<iostream>
using namespace std;

void array_input(int array[], int array_size) {	
    for(int i=0;i<array_size;i++)
    {
        cin>>array[i];
    }	
}

void print_array(int array[], int array_size) {
    for(int i=0;i<array_size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int binary_search(int low_index, int high_index, int array[], int search_item) {
    
    int middle_index=(low_index+high_index)/2;
    if((high_index-low_index)>-1)
    {
        if(array[middle_index]==search_item)
        {
            return middle_index;
        }
        else if(search_item<array[middle_index])
        {
            binary_search(low_index, middle_index-1, array, search_item);
        }
        else if(search_item>array[middle_index])
        {
            binary_search(middle_index+1, high_index, array, search_item);
        }
        
    }

}

int main() {
    int array_size,search_item;
    cout<<"Enter the array size ";
    cin>>array_size;
    int array[array_size];
    cout<<"Enter the numbers ";
    array_input(array,array_size);	
    cout<<"The entered array is ";
    print_array(array,array_size);
    cout<<"Enter the search item ";
    cin>>search_item;
    int low_index=0, high_index=(sizeof(array)/sizeof(int))-1;
    int location=binary_search(low_index,high_index,array,search_item);
    if(location==-1)
    {
        cout<<"The search item is not part of the array";
    }
    else
    {
        cout<<"The location of the search item is "<<location;
    }
}