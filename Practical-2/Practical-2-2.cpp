//Practical 2: Linear and Binary Search: Iterative and Recursive Approaches
//Problem-2
#include <iostream>
using namespace std;
//with iteratiave
int BI(int arr[],int n,int target)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
    int mid=(low+high)/2;

    if(arr[mid]==target)
            return mid;

        else if(target<arr[mid])
            high=mid-1;
            else
            low=mid+1;
    }
    return -1;
}
//with recursive
int BR(int arr[],int low,int high,int target)
{
    if(low>high)
        return -1;

    int mid=(low+high)/2;

    if(arr[mid]==target)
        return mid;

    if(target<arr[mid])
        return BR(arr,low,mid-1,target);

    return BR(arr,mid+1,high,target);
}

int main()
{
    int n,target;

    cout<<"Enter number of book codes:";
    cin>>n;

    int arr[n];

    cout<<"Enter sorted book codes:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter target code:";
    cin>>target;

    int result1=BI(arr,n,target);

    if(result1!=-1)
        cout<<"\nIterative Binary Search is:Found at index "<<result1<<endl;
    else
        cout<<"\nIterative Binary Search is: Not Found"<<endl;

    int result2=BR(arr,0,n-1,target);

    if(result2!=-1)
        cout<<"Recursive Binary Search: Found at index"<<result2<<endl;
    else
        cout<<"Recursive Binary Search: Not Found"<<endl;

    return 0;
}