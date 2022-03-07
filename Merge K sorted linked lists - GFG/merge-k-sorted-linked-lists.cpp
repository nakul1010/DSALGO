// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
   Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
   {
    //Write your code here
      if(head1==NULL && head2==NULL)
         return head1;
      if(head1==NULL)
         return head2;
      if(head2==NULL)
         return head1;
      Node *fh=NULL;
      Node *ft=NULL;
      if(head1->data<head2->data){
          fh=head1;
          ft=head1;
          head1=head1->next;
      }
      else{
          fh=head2;
          ft=head2;
          head2=head2->next;
      }
      while(head1!=NULL && head2!=NULL){
         if(head1->data<head2->data){
              ft->next=head1;
              ft=head1;
              head1=head1->next;
         }
         else{
            ft->next=head2;
            ft=head2;
            head2=head2->next;
         }     
      }
      if(head1!=NULL){
         ft->next=head1;
       
      }
      else{
         ft->next=head2;
      }
       return fh;
   }
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           if(k==1){
               return arr[0];
           }
           Node * result1 = mergeTwoSortedLinkedLists(arr[0],arr[1]);
           
           if(k==2){
               return result1;
           }
           for(int i=2;i<k;i++){
               result1 = mergeTwoSortedLinkedLists(result1,arr[i]);
           }
           return result1;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends