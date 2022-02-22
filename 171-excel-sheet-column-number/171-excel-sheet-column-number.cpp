class Solution {
public:
    int titleToNumber(string str) 
    {
        int no = 0, n = str.size();
        
        for( int i=0,j=n-1; i<n; i++,j--)
        {
            if(i==n-1)
                no = no +  (int(str[i]-'A')+1);
            else
                no = no + (pow(26,j) * (int(str[i]-'A')+1));
        }
        
        return no;
    }
};