// Program to add two large numbers using strings.
#include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

// Function to add the digits
int add_digits(int num1, int num2, int carry)
{
    return num1+num2+carry;
}

string add(string num1, string num2)
{
    //Initializing the variables.
    const int length1 = num1.length();
    reverse(num1.begin(), num1.end());
    char* num1_char_array = new char[length1];
    strcpy(num1_char_array, num1.c_str());

    const int length2 = num2.length();
    reverse(num2.begin(), num2.end());
    char* num2_char_array = new char[length2];
    strcpy(num2_char_array, num2.c_str());

    int carry=0;
    int sum, result_digit;
    string sum_string="";
    string result_string;

    //If length of first string is less.
    if(length1<=length2)
    {
        //Add digits upto the length of the shorter string.
        for(int i=0; i<length1; i++)
        {
            int digit1=int(num1_char_array[i]-'0');
            int digit2=int(num2_char_array[i]-'0');
            sum=add_digits(digit1, digit2, carry);
            //If carry is created.
            if(sum>9)
            {
                result_digit=sum-10;

                carry=1;
            }
            else
            {
                result_digit=sum;
                carry=0;
            }
            //Append to the string.
            result_string=to_string(result_digit);
            sum_string=result_string+sum_string;
        }
        for(int i=length1; i<length2; i++)
        {
            //Calculating the sum for the rest of the length of the longer string.
            int digit1=0;
            int digit2=int(num2_char_array[i]-'0');
            sum=add_digits(digit1, digit2, carry);
            //If carry is created.
            if(sum>9)
            {
                result_digit=sum-10;

                carry=1;
            }
            else
            {
                result_digit=sum;
                carry=0;
            }
            //Append to the string.
            result_string=to_string(result_digit);
            sum_string=result_string+sum_string;
        }
        //Append the final carry if required.
        if(carry==1)
        {
            sum_string="1"+sum_string;
        }
    }
    else
    {
        //Add digits upto the length of the shorter string.
        for(int i=0; i<length2; i++)
        {
            int digit1=int(num1_char_array[i]-'0');
            int digit2=int(num2_char_array[i]-'0');
            sum=add_digits(digit1, digit2, carry);
            //If carry is created.
            if(sum>9)
            {
                result_digit=sum-10;

                carry=1;
            }
            else
            {
                result_digit=sum;
                carry=0;
            }
            //Append to the string.
            result_string=to_string(result_digit);
            sum_string=result_string+sum_string;
        }
        for(int i=length2; i<length1; i++)
        {
            //Calculating the sum for the rest of the length of the longer string.
            int digit1=int(num1_char_array[i]-'0');
            int digit2=0;
            sum=add_digits(digit1, digit2, carry);
            //If carry is created.
            if(sum>9)
            {
                result_digit=sum-10;

                carry=1;
            }
            else
            {
                result_digit=sum;
                carry=0;
            }
            //Append to the string.
            result_string=to_string(result_digit);
            sum_string=result_string+sum_string;
        }
        //Append the final carry if required.
        if(carry==1)
        {
            sum_string="1"+sum_string;

        }
    }
    return sum_string;
}

//Driver function.
int main()
{
    cout<<"Enter the first large number ";
    string num1;
    cin>>num1;
    cout<<"Enter the second large number ";
    string num2;
    cin>>num2;
    cout<<"The sum is "<<add(num1, num2);
}
