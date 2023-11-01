// Program to implement insertion sort.
#include<iostream>
using namespace std;

void array_input(int array[], int array_size)
{	
    for(int i=0;i<array_size;i++)
    {
        cin>>array[i];
    }	
}

void print_array(int array[], int array_size)
{
    for(int i=0;i<array_size;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void subarray_move(int array[], int start_index_of_subarray, int end_index_of_subarray)
{
    for(int i=end_index_of_subarray; i>=start_index_of_subarray;i--)
    {
        array[i]=array[i-1];			
    }	
}

void start_index_of_subarray_func(int array[],int end_index_of_subarray,int temp_num_for_sort)
{
    int start_index_of_subarray;
    for(int i=0;i<=end_index_of_subarray;i++)
    {		
        if(array[i]>=temp_num_for_sort)
        {			
            start_index_of_subarray=i;
            break;
        }		
    }
    subarray_move(array, start_index_of_subarray, end_index_of_subarray);	
    array[start_index_of_subarray]=temp_num_for_sort;
}

void choose_number(int array[], int test_index_number)
{
    int temp_num_for_sort, end_index_of_subarray;
    if(array[test_index_number-1]>array[test_index_number])
    {
        temp_num_for_sort=array[test_index_number];
        end_index_of_subarray=test_index_number;
        start_index_of_subarray_func(array,end_index_of_subarray,temp_num_for_sort);        
    }
}

void insertion_sort(int array[], int array_size)
{	
    for(int test_index_number=1; test_index_number<array_size;test_index_number++)
    {
        choose_number(array,test_index_number);
    }	
}

int main()
{
    int array_size;
    cout<<"Enter the array size ";
    cin>>array_size;
    int array[array_size];
    cout<<"Enter the numbers ";
    array_input(array,array_size);	
    cout<<"The unsorted array is ";
    print_array(array,array_size);
    insertion_sort(array,array_size);
    cout<<"The sorted array is ";
    print_array(array,array_size);	
}