class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long ans=(long(k)*(long(k+1)))/2;
        // be sure to use unique numbers in nums
        unordered_set<int>st(nums.begin(),nums.end());
        nums.clear();
        for(auto &i:st)
            nums.push_back(i);
        // sort nums
        sort(begin(nums),end(nums));
        int sz=nums.size();
        // iterate over the array
        for(int i=0;i<sz;i++){
            // if you have added a number in nums that was already present in nums then remove that and add next candidate that is k+1
          if(nums[i]<=k ){
                ans-=nums[i];
                ans+=k+1;
                k++;
            }
            else
                break;
        }
        return ans;
    }
};