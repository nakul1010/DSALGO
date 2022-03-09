/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(unordered_map<int, pair<int,int>>&mp,int data)
    {
        TreeNode* curr = new TreeNode(data);
        
        if(mp.find(data)!=mp.end() &&  mp[data].first != -1)
            curr->left = solve(mp, mp[data].first);
        
        if(mp.find(data)!=mp.end() && mp[data].second != -1)
            curr->right = solve(mp, mp[data].second);
        
        return curr;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        int  root = -1;
        unordered_set<int>s;
        unordered_map<int, pair<int,int>>mp;//left,right
        
        for(int i=0; i<descriptions.size(); i++)
        {
            s.insert(descriptions[i][0]);
            
            if(mp.find(descriptions[i][0])==mp.end())
            {
                if(descriptions[i][2]==1)
                    mp.insert({descriptions[i][0], {descriptions[i][1], -1}});
                else
                    mp.insert({descriptions[i][0], {-1, descriptions[i][1]}});
            }
            else if(descriptions[i][2]==1)
            {
                auto var = mp[descriptions[i][0]];
                mp[descriptions[i][0]].first = descriptions[i][1];
                // var.second.first = descriptions[i][1];
            }
            else if(descriptions[i][2]==0)
            {
                auto var = mp[descriptions[i][0]];
                mp[descriptions[i][0]].second = descriptions[i][1];
                // var.second.second = descriptions[i][1];
            }
        }
        for(int i=0; i<descriptions.size(); i++)
        {
            if(s.find(descriptions[i][1]) != s.end())
                s.erase(descriptions[i][1]);
        }
        
        for(auto it : s)
        {
            root = it;
        }
        
        // for(auto it: mp)
        // {
        //     cout<<it.first<<" , "<<it.second.first<<" : "<<it.second.second<<endl;
        // }
        // cout<<endl;
        
        
        return solve(mp,root);
    }
};