class Solution {
public:
    int maxVowels(string str, int k) 
    {
        int n = str.size();
        deque<int>dq;
        int vowels = 0, max_vowels = 0;
        
        unordered_set<char>s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        
        for(int i=0;i<k;i++)
        {
            if(s.find(str[i])!=s.end())
                vowels++;
            dq.push_back(i);
        }
        max_vowels = max(max_vowels, vowels);
        // cout<<"vowels : "<<vowels<<endl;
        
        for(int i=k;i<n;i++)
        {
            if(s.find(str[dq.front()]) != s.end())
                vowels--;
            
            if(dq.front() == i-k)
                dq.pop_front();
            
            if(s.find(str[i])!=s.end())
                vowels++;
            // cout<<"i : "<<i<<"     vowels : "<<vowels<<endl;
            dq.push_back(i);
            max_vowels = max(max_vowels, vowels);
        }
        return max_vowels;
    }
};