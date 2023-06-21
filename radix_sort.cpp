//Program to implement radix sort algorithm.
#include<iostream>
#include<cmath>

using namespace std;

void print_array(int array_to_be_sorted[], int size_of_array)
{
    // Function for printing the array.
    for(int i=0; i<size_of_array; i++)
    {
        cout<<array_to_be_sorted[i]<<"  ";
    }
    cout<<endl;
}

int find_max(int array_to_be_sorted[], int size_of_array)
{
    // The function to find the maximum value among the numbers to be sorted.
    int max=array_to_be_sorted[0];
    for(int i=0; i<size_of_array; i++)
    {
        if(array_to_be_sorted[i]>max)
        {
            max=array_to_be_sorted[i];
        }
    }
    return max;
}

void counting_sort(int array_to_be_sorted[], int size_of_array)
{
    // The function to implement counting sort.
    int max=find_max(array_to_be_sorted, size_of_array);

    // Initializing the counting array.
    int counter_array[max+1];
    for(int i=0; i<max+1; i++)
    {
        counter_array[i]=0;
    }

    // Counting the numbers.
    for(int i=0; i<size_of_array; i++)
    {
        int value=array_to_be_sorted[i];

        counter_array[value]++;
    }
    //Doing the cumulative summation
    for(int i=1; i<=max+1; i++)
    {
        counter_array[i]=counter_array[i]+counter_array[i-1];
    }
    int sorted_array[size_of_array];
    //Inserting the values to the sorted array
    for(int i=size_of_array-1; i>=0; i--)
    {
        int value=array_to_be_sorted[i];
        counter_array[value]--;
        int num=counter_array[value];
        sorted_array[num]=value;
    }
    //Inserting the values of the sorted array into the original array.
    for(int i=0; i<size_of_array; i++)
    {
        array_to_be_sorted[i]=sorted_array[i];
    }


}


void radix_sort(int array_to_be_sorted[], int size_of_array)
{

    int exponent=find_max(array_to_be_sorted, size_of_array);//Saving up on space by using the same variable
    exponent=floor(log10(exponent));//Saving up on space by using the same variable
    int remainder[size_of_array];
    for(int i=1; i<=exponent+1; i++)
    {
        int divisor=pow(10, i);


        for(int i=0; i<size_of_array; i++)
        {
        //Remainder array is for using the remainder of the numbers to be sorted.
            remainder[i]=array_to_be_sorted[i]%divisor;

        }
        counting_sort(remainder, size_of_array);

    }
    //Inserting the values of the remainder array into the original array.
    for(int i=0; i<size_of_array; i++)
    {
        array_to_be_sorted[i]=remainder[i];
    }

}

void input_array(int array_to_be_sorted[], int size_of_array)
{
    // Function to input the numbers to be sorted.
    for(int i=0; i<size_of_array; i++)
    {
        cin>>array_to_be_sorted[i];
    }

}

int main()
{
    cout<<"Enter the number of numbers to be sorted ";
    int size_of_array;
    cin>>size_of_array;
    int array_to_be_sorted[size_of_array];
    input_array(array_to_be_sorted, size_of_array);
    radix_sort(array_to_be_sorted, size_of_array);
    cout<<"The sorted numbers are ";
    print_array(array_to_be_sorted, size_of_array);
}
