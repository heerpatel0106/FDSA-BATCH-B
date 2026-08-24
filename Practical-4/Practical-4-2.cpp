#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

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

Node* deleteByValue(Node* head,int value)
{
    if(head==NULL)
        return head;

    if(head->data==value)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;

    while(temp->next!=NULL&&temp->next->data!=value)
    {
        temp=temp->next;
    }

    if(temp->next!=NULL)
    {
        Node* del=temp->next;
        temp->next=del->next;
        delete del;
    }

    return head;
}

void forwardPrint(Node* head)
{
    Node* temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

void reversePrint(Node* head)
{
    if(head==NULL)
        return;

    reversePrint(head->next);
    cout<<head->data<<" ";
}

int main()
{
    Node* head=NULL;

    head=insertEnd(head,10);
    head=insertEnd(head,20);
    head=insertEnd(head,30);
    head=insertEnd(head,40);

    cout<<"Original Queue: ";
    forwardPrint(head);

    head=deleteByValue(head,20);

    cout<<"After Deletion: ";
    forwardPrint(head);

    cout<<"Reverse Queue: ";
    reversePrint(head);
    cout<<endl;

    return 0;
}