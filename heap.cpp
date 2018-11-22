#include<iostream>
using namespace std;
void max_heapify(int a[],int i,int n)
{
int largest_index;
 int left_child;
 int right_child;
  left_child=2*i+1;
  right_child=2*i+2;
  if (left_child<n && a[left_child]>a[i])
  {
    largest_index=left_child;

  }
  else{ largest_index=i;}

  if(right_child<n && a[right_child]>a[largest_index])
  {
     largest_index!=n;
      swap (a[i],a[largest_index]) ;
       max_heapify(a,largest_index,n);
  }

}
void build_max_heap(int a[],int n)
{
        for (int i=n/2-1;i>=0;i--)
        {
          max_heapify(a,i,n) ;
        }
}
void heapsort(int a[],int n)
{
        for(int i=n-1;i>=1;i--)
        {
                swap(a[0],a[i]);
                max_heapify(a,0,i);
        }
        cout<<"the sorted heap are"<<endl;
        for(int i=0;i<=n-1;i++)
        {
                cout<<a[i]<<" "<<endl;
        }
}
int main()
{
        int i,n;
        cout<<"enter the number:"<<endl;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
          cout<<"enter elements"<<endl;
          cin>>a[i];
         }
         build_max_heap(a,n);

        cout<<"max heap"<<endl;


         for (i =0;i<n; i++)
    {
        cout<<a[i]<<endl;
    }
    heapsort (a,n);
    return 0;
        }

