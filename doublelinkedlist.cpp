
#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next,*prev;
}*nodeptr;
nodeptr head=NULL,tail=NULL;
void insert(int n)
{
    int value;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        nodeptr newnode= new Node;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL&&tail==NULL)
        {
           head=newnode;
           tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
        }
        tail=newnode;
    }
}
void insertAtFirst(int value)
{
    nodeptr newnode=new Node;
    newnode->data=value;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
void insertAtLast(int value)
{
    nodeptr  newnode=new Node;
    newnode->data=value;
    tail->next = newnode;
    newnode->prev=tail;
    newnode->next=NULL;
    tail=newnode;
}

void insertAtK(int value,int p)
{

    nodeptr newnode= new Node;
    newnode->data=value;
    nodeptr ptr=head;
    while(ptr->data!=p)
       {

        ptr=ptr->next;
    if(ptr->data==p)
        newnode->next = ptr->next;
        ptr->next->prev=newnode;
        ptr->next=newnode;
        newnode->prev=ptr;
       }

}

void deletFirst()
{
   nodeptr ptr=head;
   head= head->next;
   head->prev=NULL;
   delete(ptr);
}
void deletLast()

{
     if(head->next !=NULL)
       {    nodeptr ptr =tail;
            tail->prev->next = NULL;
            tail = tail->prev;
       }
      else
      {
          head=NULL;
          tail=NULL;
      }
}


void deletAtK(int p)
{

    nodeptr ptr=head;
    while(ptr->data!=p)
       {
        ptr=ptr->next;
        if(ptr->data==p)
        {
            nodeptr x=ptr->next;
            nodeptr y=ptr->prev;
            y->next=x;
            x->prev=y;
        }

       }
}
int Search(int p)
{
   int position=0;
    bool found = false ;
    nodeptr ptr=head;
      while(ptr!=NULL)
      {
          position ++;
          if (ptr->data==p)
          {
              found=true;
              return position;
          }
          else
          {
              ptr=ptr->next;
          }
      }

}
void displayF()
{
    nodeptr ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void displayB()
{
    nodeptr ptr=tail;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    insert(n);
    cout<<endl;
    cout<<"1. Insert at first "<<endl;
    cout<<"2. Insert at last "<<endl;
    cout<<"3. Insert at k position "<<endl;
    cout<<"4. Delete at first"<<endl;
    cout<<"5. Delete at last"<<endl;
    cout<<"6. Delete at k position"<<endl;
    cout<<"7. Forward Display "<<endl;
    cout<<"8. Backward Display "<<endl;
    cout<<"9. Search "<<endl;
    while(1)
    {
        int query;
        cout<<"Choose a menu: "<<endl;
        cin>>query;
        if(query==1)
        {
            int data;
            cout<<"Provide a value to insert at first: "<<endl;
            cin>>data;
            insertAtFirst(data);
        }
        else if(query==2)
        {
            int data;
             cout<<"Provide a value to insert at last: "<<endl;
            cin>>data;
            insertAtLast(data);
        }
        else if(query==3)
        {
            int data,k;
             cout<<"Provide a value to insert at k position: "<<endl;
            cin>>data>>k;
            insertAtK(data,k);
        }
        else if(query==4)
        {
            int data;
             /*cout<<"Provide a value to delete at first: "<<endl;
            cin>>data;*/
            deletFirst();
        }
        else if(query==5)
        {
            int data;
             /*cout<<"Provide a value to delete at last: "<<endl;
            cin>>data;*/
            deletLast();
        }
        else if(query==6)
        {
            int data;
            cout<<"Provide a value to delete at k position: "<<endl;
            cin>>data;
            deletAtK(data);
        }
        else if(query==7)
        {
            cout<<"The list is in forward order: "<<endl;
            displayF();
        }
        else if(query==8)
        {
            cout<<"The list is in backward order: "<<endl;
            displayB();
        }
        else if(query==9)
        {
            int data;
            cout<<"Provide a value to search: "<<endl;
            cin>>data;
            int status = Search(data);
            if(status)
            {
                 cout<<"Element Found\n"<<endl;
            }
            else
            {
                 cout<<"Element Not Found\n"<<endl;

            }
        }
    }
    return 0;

}
