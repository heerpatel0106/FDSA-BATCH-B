#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int queue[n];
    int front=-1,rear=-1;

    int q;
    cin>>q;

    while(q--){
        string op;
        cin>>op;

        if(op=="join"){
            int x;
            cin>>x;

            if(rear==n-1){
                cout<<"Queue Overflow"<<endl;
            }
            else{
                if(front==-1)
                    front=0;

                rear++;
                queue[rear]=x;

                cout<<"Front: "<<queue[front]<<endl;
            }
        }
        else if(op=="serve"){
            if(front==-1||front>rear){
                cout<<"Queue Underflow"<<endl;
            }
            else{
                front++;

                if(front>rear){
                    front=-1;
                    rear=-1;
                    cout<<"Queue Empty"<<endl;
                }
                else{
                    cout<<"Front: "<<queue[front]<<endl;
                }
            }
        }
    }

    return 0;
}