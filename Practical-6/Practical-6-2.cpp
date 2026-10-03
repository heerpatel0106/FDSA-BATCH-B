#include<iostream>
using namespace std;

struct Node{
    string page;
    Node*next;
};

int main(){
    Node*top=NULL;

    int q;
    cin>>q;

    while(q--){
        string op;
        cin>>op;

        if(op=="visit"){
            string page;
            cin>>page;

            Node*newNode=new Node();
            newNode->page=page;
            newNode->next=top;
            top=newNode;

            cout<<"Current Page: "<<top->page<<endl;
        }
        else if(op=="back"){
            if(top==NULL){
                cout<<"No History"<<endl;
            }
            else{
                Node*temp=top;
                top=top->next;
                delete temp;

                if(top==NULL)
                    cout<<"No Page"<<endl;
                else
                    cout<<"Current Page: "<<top->page<<endl;
            }
        }
    }

    return 0;
}