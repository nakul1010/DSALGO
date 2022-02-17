// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

 // } Driver Code Ends
//User function Template for C++

/*
struct Node
{   
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
public:

    unordered_map<Node*,string>status;//wants, provide, ok
    unordered_map<Node*,Node*>parent;//stores parent node
    
    int vaccine = 0;
    
    void Traverse(Node*curr)
    {
        if(!curr)
            return;
            
        Traverse(curr->left);
        Traverse(curr->right);
        
        // cout<<curr->data<<" : "<<status[curr];
        if(status[curr] == "want" && parent[curr]==NULL)
        {
            // cout<<"  1\n";
            vaccine++;
            if(curr->left && status[curr->left]=="want")
                status[curr->left] = "ok";
            if(curr->right && status[curr->right]=="want")
                status[curr->right] = "ok";
        }
        // if(status[curr] == "want" && parent[curr]!=NULL)
        else if(status[curr] == "want")
        {
            // cout<<"  2\n";
            vaccine++;
            Node* get_parent = parent[curr];
            status[get_parent] = "provide";
            
            //child
            if(get_parent && get_parent->left && status[get_parent->left]=="want")
                status[get_parent->left] = "ok";
            if(get_parent && get_parent->right && status[get_parent->right]=="want")
                status[get_parent->right] = "ok";
                
            //parent
            if(status[parent[get_parent]]=="want")
                status[parent[get_parent]]="ok";
        }
        
    }
    
    
    void Store_Parent(Node*curr)
    {
        queue<Node*>q;
        q.push(curr);
        parent[curr] = NULL;
        while(q.empty()==false)
        {
            curr = q.front();
            q.pop();
            
            status[curr] = "want";//intially everyone wants a vaccine
            
            if(curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    int supplyVaccine(Node* root)
    {
        Store_Parent(root);
        Traverse(root);
        // cout<<endl;
        return vaccine;
    }
};

// { Driver Code Starts.
int main() 
{
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout<<ob.supplyVaccine(root)<<"\n";
    }
    return 0;
}



  // } Driver Code Ends