//Practical 2: Linear and Binary Search: Iterative and Recursive Approaches
//Problem 1
#include<iostream>
using namespace std;

//with iterative
int LI(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
            return i;
    }
    return -1;
}

//with recursive
int LR(int arr[],int n,int target,int index)
{
    if(index==n)
        return -1;

    if(arr[index]==target)
        return index;

    return LR(arr,n,target,index+1);
}

int main()
{
    int n,target;

    cout<<"Enter number of license plates:";
    cin>>n;

    int arr[n];

    cout<<"Enter license plate numbers:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter target plate:";
    cin>>target;

    int result1=LI(arr,n,target);

    if(result1!=-1)
        cout<<"\nIterative Search:Found at index"<<result1<<endl;
    else
        cout<<"\nIterative Search:Not Found"<<endl;

    int result2=LR(arr,n,target,0);

    if(result2!=-1)
        cout<<"Recursive Search:Found at index"<<result2<<endl;
    else
        cout<<"Recursive Search:Not Found"<<endl;

    return 0;
}