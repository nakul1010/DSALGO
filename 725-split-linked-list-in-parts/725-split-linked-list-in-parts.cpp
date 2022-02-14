/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int Length(ListNode*head)
    {
        int len=0;
        while(head!=NULL)
            len++,head=head->next;
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*>vec(k,NULL);
        ListNode*curr = head , *prev=NULL;
        
        int length = Length(head);
        int mod = length%k;
        int divide = length/k;
        int cnt = 0;    
        
        // cout<<"divide : "<<divide<<"    mod : "<<mod<<endl;
        
        if(length > k)
        {
            while(curr!=NULL)
            {
               vec[cnt] = curr;
                cnt++;
               for(int i=0;i<divide;i++) 
               {
                   if(curr)
                   {
                        // cout<<curr->val<<" , ";
                       
                       prev = curr;
                       curr=curr->next;
                   }
                       
                }
                // cout<<"--"<<endl;
                if(curr && mod)
                    prev=curr, mod--,curr=curr->next;
                if(prev)
                    
                    prev->next = NULL;
            }
        }
        
        else
        {
            while(curr!=NULL)
            {
                vec[cnt] = curr;
                cnt++;
                prev = curr;
                curr=curr->next;
                prev->next = NULL;
            }
        }
        return vec;
    }
};