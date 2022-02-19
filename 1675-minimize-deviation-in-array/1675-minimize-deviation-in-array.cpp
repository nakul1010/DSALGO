class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        priority_queue<int>pq;
        int diff = INT_MAX;
        int min_value = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)  
            {
                min_value = min(min_value, nums[i]*2);
                pq.push(nums[i]*2);
            }
                
            else
            {
                min_value = min(min_value, nums[i]);
                pq.push(nums[i]);
            }   
        }
        
        while(pq.empty()==false)
        {
            if(pq.top()%2==0)
            {
                int no = pq.top();
                pq.pop();
                pq.push(no/2);
                // diff = min(diff, abs(no -min_value) );
                
                diff = min(diff, abs(no-min_value));
                
                // cout<<"even   no : "<<no<<"  diff : "<<(no -min_value);
                min_value = min(min_value, no/2);
                // cout<<"    min : "<<min_value<<endl;
            }
            else
            {
                int no = pq.top();
                pq.pop();
                // diff = min(diff, abs(no-min_value) );
                
                diff = min(diff, abs(no-min_value));
                // cout<<"odd   no : "<<no<<"  diff : "<<(no-min_value)<<"   min : "<<min_value<<endl;
                break;
            }
        }
        return diff;
    }
};