//Practical 1: Array Operations: Traversal, Rotation, and Frequency Analysis
//Problem-3
#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter the Number of words:";
    cin>>n;
    cout<<"Enter The Line:";
string word,longest=" ";
for(i=0;i<n;i++){
        cin>>word;
if(word.length()>longest.length()){
        longest=word;
}
}
    cout<<"Longest Word is:"<<longest<<endl;
    cout<<"Length:"<<longest.length();
    return 0;
}
