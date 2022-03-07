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
    struct compare {
    bool operator()(Node*n1,Node*n2)
    {
        
        return n1->data > n2->data;
    }
};
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        Node *root = NULL,*tail = NULL;
        priority_queue<Node*,vector<Node*>,compare> pq;
        for(int i=0;i<K;i++){
            while(arr[i]){
                pq.push(arr[i]);
                arr[i] = arr[i]->next;
            }
        }
        root = pq.top();pq.pop();tail = root;
        while(!pq.empty()){
            tail->next = pq.top();pq.pop();
            tail = tail->next;
        }
        tail->next = NULL;
        return root;
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