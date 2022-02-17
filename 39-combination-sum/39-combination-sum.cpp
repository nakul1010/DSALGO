class Solution {
public:
    vector<vector<int>>ans;
        
    void Combination_Recur(vector<int>& candidates,vector<int>&vec, int n, int target)
    {
        if(target==0)
        {
            ans.push_back(vec);
            return;
        }
        if(target<0 || n<0)
            return;
        
        //excl
        Combination_Recur(candidates,vec, n-1, target);
        
        //incl
        vec.push_back(candidates[n]);
        Combination_Recur(candidates,vec, n, target-candidates[n]);
        vec.pop_back();
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>vec;
        int n = candidates.size();
        
        Combination_Recur(candidates, vec, n-1, target);
        return ans;
    }
};