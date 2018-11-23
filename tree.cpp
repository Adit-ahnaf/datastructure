
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct bin_tree
{
    bin_tree *left, *right;
    int data;
}*nodebst;

nodebst makenode(int value)
{
    bin_tree* newNodePtr = new bin_tree ;
    if (newNodePtr == NULL)

       {
         cout<<"Out of memory";
      return 0;
 }
 else
        {
        newNodePtr->data = value;
        newNodePtr->left= NULL;
        newNodePtr->right = NULL;
    	}
     return newNodePtr;
 }//write your code here


nodebst insert_node(nodebst ptr, int value)
{
   if( ptr==NULL)
   {
    ptr=makenode(value) ;
          //write your code here
   }
   else if (value< ptr->data)
   {
 ptr->left=insert_node( ptr->left,value);

   }
   else if(value> ptr->data)
   {
            ptr->right=insert_node(ptr->right,value);
   }
   return  ptr;
}

nodebst search_node(nodebst ptr, int value)
{
    if (ptr!=NULL)
    {
     if(value<ptr->data)
     {
      ptr=search_node(ptr->left,value);       //write your code here
    }
    else if (value>ptr->data)
    {
            ptr=search_node(ptr->right,value);
    }
   return ptr;
}
}

void inorder(nodebst ptr)
{
 if(ptr!=NULL)
 {
         inorder(ptr->left);
         cout<<ptr->data;
         inorder(ptr->right);//write your code here
  }
}

void preorder(nodebst ptr)
{
  if(ptr!=NULL)
  {
          cout<<ptr->data;
          preorder(ptr->left);
          preorder(ptr->right);
  }//write your code here

}

void postorder(nodebst ptr)
{
    if(ptr!=NULL)
    {
     postorder(ptr->left) ;
     postorder(ptr->right)  ;
     cout<<ptr->data;
    }//write your code here
}
int findmin(nodebst ptr)
{
   bin_tree *curr=ptr;
   while(curr->left!=NULL)
   {
       curr=curr->left;
   }
   return (curr->data);//write your code here
}

int findmax(nodebst ptr)

{
  bin_tree *curr=ptr;
  while(curr->right!=NULL)
  {
      curr=curr->right;
  }
  return (curr->data); //write your code here
}


int main()
{
    nodebst root = NULL, temp;
    int value, n;
    cout<<"Enter number of data: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin >> value;
        temp = root;
        if (root == NULL)
            root = insert_node(root,value);
        else
            temp = insert_node(temp,value);

    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"Min: "<<findmin(root)<<endl;
    cout<<"Max: "<<findmax(root)<<endl;

    cout<<"Enter value to search: ";
    cin >>value;

    nodebst a;
    a = search_node(root,value);

    if (a == NULL)
        cout<<"Not Found!!"<<endl;
    else
        cout<<"Found!!"<<endl;
    return 0;

}



