#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* insertFront(Node* head,int value)
{
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=head;
    return newNode;
}

Node* insertEnd(Node* head,int value)
{
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL)
        return newNode;

    Node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    return head;
}

Node* insertAtPosition(Node* head,int value,int position)
{
    if(position<=0)
    {
        cout<<"Invalid position"<<endl;
        return head;
    }

    if(position==1)
    {
        return insertFront(head,value);
    }

    Node* temp=head;

    for(int i=1;i<position-1&&temp!=NULL;i++)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"Invalid position"<<endl;
        return head;
    }

    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}

void display(Node* head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int main()
{
    Node* head=NULL;

    head=insertFront(head,10);
    display(head);

    head=insertEnd(head,20);
    display(head);

    head=insertEnd(head,30);
    display(head);

    head=insertAtPosition(head,15,2);
    display(head);

    return 0;
}