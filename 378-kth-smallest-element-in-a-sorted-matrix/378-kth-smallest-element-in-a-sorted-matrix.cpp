class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size(), size=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                pq.push(matrix[i][j]);
            }
        }
        size = (n*n) -k;
        while(size!=0)
        {
            pq.pop();
            size--;
        }
        return pq.top();
    }
};