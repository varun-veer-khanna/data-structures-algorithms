//Program to input two arrays and return an intersection of elements of the two arrays.
//This problem is found in leetcode as well.
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void print_vector(set<int> &result)
{
    set<int>::iterator it;
    // Print the intersection array
    cout << "The elements in the intersection are :\n";
    for (it = result.begin(); it != result.end(); ++it)
        cout << *it << "  ";
    cout << '\n';
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> common;
    //Finding the common elements in the two vectors
    for(int i=0; i<nums1.size(); i++)
    {
        for(int j=0; j<nums2.size(); j++)
        {
            if(nums1[i]==nums2[j])
            {
                common.push_back(nums1[i]);
            }
        }
    }
    set<int> s;

    //Eliminating the common duplicate elements using a set data structure.
    for (int i = 0; i < common.size(); i++) {

        // insert into set
        s.insert(common[i]);
    }
    print_vector(s);
    //Writing the elements of the set into a vector.
    vector<int> result(s.begin(), s.end());
    return result;
}

void input_numbers(vector <int> &nums, int numbers)
{
    //Function to input the numbers of the sets.
    for(int i=0; i<numbers; i++)
    {
        int element;
        cin>>element;
        nums.push_back(element);
    }
}

//Driver code
int main()
{
    cout<<"Enter the number of elements in the first set ";
    int nums1_num;
    cin>>nums1_num;
    vector <int> nums1;
    input_numbers(nums1, nums1_num);
    cout<<"Enter the number of elements in the second set ";
    int nums2_num;
    cin>>nums2_num;
    vector <int> nums2;
    input_numbers(nums2, nums2_num);
    intersection(nums1, nums2);
}
