#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int stack[n];
    int top=-1;

    int q;
    cin>>q;

    while(q--){
        string op;
        cin>>op;

        if(op=="place"){
            int x;
            cin>>x;

            if(top==n-1){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                stack[++top]=x;
                cout<<"Top: "<<stack[top]<<endl;
            }
        }
        else if(op=="take"){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
            }
            else{
                top--;
                if(top==-1)
                    cout<<"Stack Empty"<<endl;
                else
                    cout<<"Top: "<<stack[top]<<endl;
            }
        }
    }

    return 0;
}