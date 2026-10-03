#include<iostream>
using namespace std;

struct Node{
    string data;
    Node*next;
};

int main(){
    Node*front=NULL;
    Node*rear=NULL;

    int q;
    cin>>q;

    while(q--){
        string op;
        cin>>op;

        if(op=="arrive"){
            string patient;
            cin>>patient;

            Node*newNode=new Node();
            newNode->data=patient;
            newNode->next=NULL;

            if(rear==NULL){
                front=rear=newNode;
            }
            else{
                rear->next=newNode;
                rear=newNode;
            }

            cout<<"Front: "<<front->data<<endl;
        }
        else if(op=="attend"){
            if(front==NULL){
                cout<<"Queue Empty"<<endl;
            }
            else{
                Node*temp=front;
                front=front->next;

                if(front==NULL)
                    rear=NULL;

                delete temp;

                if(front==NULL)
                    cout<<"Queue Empty"<<endl;
                else
                    cout<<"Front: "<<front->data<<endl;
            }
        }
    }

    return 0;
}