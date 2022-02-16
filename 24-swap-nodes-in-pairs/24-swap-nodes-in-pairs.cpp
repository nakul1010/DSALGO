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
    
    ListNode* Reverse_Nodes_By_K(ListNode* head, int k)
    {
        int cnt = k;
        ListNode*prev=NULL,*curr=head,*forward=NULL;
        
        while(cnt!=0 && curr!=NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt--;
        }
        
        if(curr!=NULL)
            head->next = Reverse_Nodes_By_K(forward,k);
        return prev;
    }
    
    ListNode* swapPairs(ListNode* head) 
    {
        int k = 2;
        return Reverse_Nodes_By_K(head,k);
    }
};