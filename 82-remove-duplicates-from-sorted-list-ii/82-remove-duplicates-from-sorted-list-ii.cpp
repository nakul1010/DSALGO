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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *dummyhead = new ListNode(0,head);
        ListNode *prev = dummyhead, * curr = head;
        
        while(curr!=NULL)
        {
            bool duplicate = false;
            while(curr->next && curr->val == curr->next->val)
            {
                duplicate=true;
                curr = curr->next;
            }
            if(duplicate)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        return dummyhead->next;
    }
};