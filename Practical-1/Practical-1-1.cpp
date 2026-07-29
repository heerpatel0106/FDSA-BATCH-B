//Practical 1: Array Operations: Traversal, Rotation, and Frequency Analysis
//Problem-1
#include<iostream>
using namespace std;

int main(){
int n,h;
cout<<"Enter values of n:";
cin>>n;
cout<<"Enter values of h:";
cin>>h;
string arr[n];

cout<<"Enter Array:";
for(int i=0;i<n;i++)
cin>>arr[i];

int rotations=h%n;

for(int hour=0;hour<rotations;hour++){
    string first=arr[0];

    for(int i=0;i<n-1;i++)
    arr[i]=arr[i+1];

    arr[n-1]=first;
}
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";

}