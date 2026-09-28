#include<iostream>
using namespace std;

struct SNode
{
    int data;
    SNode*next;
};

SNode*insertSingly(SNode*head,int value,int position)
{
    SNode*newNode=new SNode();
    newNode->data=value;

    if(head==NULL)
    {
        newNode->next=newNode;
        return newNode;
    }

    if(position==1)
    {
        SNode*temp=head;

        while(temp->next!=head)
            temp=temp->next;

        newNode->next=head;
        temp->next=newNode;

        return newNode;
    }

    SNode*temp=head;

    for(int i=1;i<position-1&&temp->next!=head;i++)
        temp=temp->next;

    newNode->next=temp->next;
    temp->next=newNode;

    return head;
}

SNode*deleteSingly(SNode*head,int value)
{
    if(head==NULL)
        return NULL;

    if(head->data==value)
    {
        if(head->next==head)
        {
            delete head;
            return NULL;
        }

        SNode*temp=head;

        while(temp->next!=head)
            temp=temp->next;

        SNode*del=head;
        head=head->next;
        temp->next=head;

        delete del;
        return head;
    }

    SNode*temp=head;

    while(temp->next!=head&&temp->next->data!=value)
        temp=temp->next;

    if(temp->next!=head)
    {
        SNode*del=temp->next;
        temp->next=del->next;
        delete del;
    }

    return head;
}

void displaySingly(SNode*head)
{
    if(head==NULL)
    {
        cout<<endl;
        return;
    }

    SNode*temp=head;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);

    cout<<endl;
}

struct DNode
{
    int data;
    DNode*prev;
    DNode*next;
};

DNode*insertDoubly(DNode*head,int value,int position)
{
    DNode*newNode=new DNode();
    newNode->data=value;

    if(head==NULL)
    {
        newNode->next=newNode;
        newNode->prev=newNode;
        return newNode;
    }

    if(position==1)
    {
        DNode*last=head->prev;

        newNode->next=head;
        newNode->prev=last;
        last->next=newNode;
        head->prev=newNode;

        return newNode;
    }

    DNode*temp=head;

    for(int i=1;i<position-1&&temp->next!=head;i++)
        temp=temp->next;

    newNode->next=temp->next;
    newNode->prev=temp;
    temp->next->prev=newNode;
    temp->next=newNode;

    return head;
}

DNode*deleteDoubly(DNode*head,int value)
{
    if(head==NULL)
        return NULL;

    DNode*temp=head;

    do
    {
        if(temp->data==value)
            break;

        temp=temp->next;
    }
    while(temp!=head);

    if(temp->data!=value)
        return head;

    if(temp->next==temp)
    {
        delete temp;
        return NULL;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    if(temp==head)
        head=temp->next;

    delete temp;

    return head;
}

void displayDoubly(DNode*head)
{
    if(head==NULL)
    {
        cout<<endl;
        return;
    }

    DNode*temp=head;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);

    cout<<endl;
}

int main()
{
    SNode*shead=NULL;

    shead=insertSingly(shead,10,1);
    shead=insertSingly(shead,20,2);
    shead=insertSingly(shead,30,3);

    cout<<"Singly Circular: ";
    displaySingly(shead);

    shead=deleteSingly(shead,20);

    cout<<"After Leave: ";
    displaySingly(shead);

    DNode*dhead=NULL;

    dhead=insertDoubly(dhead,10,1);
    dhead=insertDoubly(dhead,20,2);
    dhead=insertDoubly(dhead,30,3);

    cout<<"Doubly Circular: ";
    displayDoubly(dhead);

    dhead=deleteDoubly(dhead,20);

    cout<<"After Leave: ";
    displayDoubly(dhead);

    return 0;
}