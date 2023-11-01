// Program to concatenate two strings using loops.
#include<iostream>
using namespace std;

int main() {
    int i,j;
    char a1[20]="Hello";
    char a2[]="World";
    j=strlen(a1);
    for(i=0;a2[i]!='\0';i++)
    {
        a1[j]=a2[i];
        j++;
    }
    cout<<a1;
}