//Practical 1: Array Operations: Traversal, Rotation, and Frequency Analysis
//Problem-2
#include<iostream>
using namespace std;
int main(){

    int n,i,j,count;
cout<<"Enter Number of Books Borrowed:";
cin>>n;
int book[n]; //it will create array for borrowed books

cout<<"Enter the book id:";
for(i=0;i<n;i++){
    cin>>book[i]; //here I have taken input for each borrowed book.
}

cout<<"Books Borrowd More Than Once:";
for(i=0;i<n;i++){
bool duplicate = false; //here checking if there is any id repeating again,default-false
for(int k=0;k<i;k++){ //it is checking only previous element
    if(book[i]==book[k]){
        duplicate=true; 
        break;
     }
}
if(duplicate)
    continue;

count=0; //for frequency
for(j=0;j<n;j++){
    if(book[j]==book[i]){
     count++; 
    }
}

if(count>1){ //checking if frequency is greater than 1
    cout<<book[i]<<" "; //printing whose freq. is more than 1
           }
    }
return 0;
}

