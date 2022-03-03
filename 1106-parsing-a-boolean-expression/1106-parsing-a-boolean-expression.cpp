class Solution {
public:
    
    char and_truth_table(vector<char>&vec)
    {
        int false_cnt = 0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]=='f')
                false_cnt++;
        }
        if(false_cnt==0)
            return 't';
        return 'f';
    }
    char or_truth_table(vector<char>&vec)
    {
        int true_cnt = 0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]=='t')
                true_cnt++;
        }
        if(true_cnt>=1)
            return 't';
        return 'f';
    }
    char not_truth_table(vector<char>&vec)
    {
        if(vec[0]=='t')
            return 'f';
        return 't';
    }
    
    
    bool parseBoolExpr(string str) 
    {
        int n = str.size();
        if(n==1)
        {
            if(str[0]=='t')
                return true;
            return false;
        }
        
        stack<char>st;
        int i=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]==')')
            {
                char ch1 = '_', ch2 = '_', op = '_';
                vector<char>vec;
                while(st.top()!='&' && st.top()!='|' && st.top()!='!')
                {
                    vec.push_back(st.top());
                    st.pop();
                }
                op = st.top();
                st.pop();
                // cout<<ch1<<" "<<op<<" "<<ch2<<endl;
                if(op=='&')
                {
                    st.push(and_truth_table(vec));
                }
                else if(op=='|')
                {
                    st.push(or_truth_table(vec));
                }
                else
                {
                    st.push(not_truth_table(vec));
                }
            }
            else if(str[i]!='.' && str[i]!='(')
            {
                st.push(str[i]);
            }
        }
        if(st.top()=='t')
            return true;
        return false;
    }
};