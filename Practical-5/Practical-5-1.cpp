#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*prev;
    Node*next;
};

Node*insertFront(Node*head,int value)
{
    Node*newNode=new Node();
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL)
        head->prev=newNode;

    return newNode;
}

Node*insertEnd(Node*head,int value)
{
    Node*newNode=new Node();
    newNode->data=value;
    newNode->next=NULL;

    if(head==NULL)
    {
        newNode->prev=NULL;
        return newNode;
    }

    Node*temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;

    return head;
}

Node*insertAfter(Node*head,int key,int value)
{
    Node*temp=head;

    while(temp!=NULL&&temp->data!=key)
        temp=temp->next;

    if(temp==NULL)
    {
        cout<<"Song not found"<<endl;
        return head;
    }

    Node*newNode=new Node();
    newNode->data=value;
    newNode->prev=temp;
    newNode->next=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;

    return head;
}

Node*deleteFirst(Node*head)
{
    if(head==NULL)
        return NULL;

    Node*temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    delete temp;

    return head;
}

int countSongs(Node*head)
{
    int count=0;
    Node*temp=head;

    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;
}

void display(Node*head)
{
    Node*temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    cout<<endl;
}

int main()
{
    Node*head=NULL;

    head=insertFront(head,10);
    display(head);

    head=insertEnd(head,20);
    display(head);

    head=insertEnd(head,30);
    display(head);

    head=insertAfter(head,20,25);
    display(head);

    head=deleteFirst(head);
    display(head);

    cout<<"Count: "<<countSongs(head)<<endl;

    return 0;
}