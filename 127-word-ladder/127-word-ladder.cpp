class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set< string >s;//can use wordlist but set will save time
        for(int i=0;i<wordList.size();i++)
            s.insert(wordList[i]);
        
        if(s.find(endWord)==s.end())
            return 0;
        
        queue<string>q;
        q.push(beginWord);
        q.push("NULL");
        int len=0;
        
        while(q.empty()==false)
        {
            string str = q.front();
            q.pop();
            if(str == "NULL")
            {
                q.push("NULL");
                
                str = q.front();
                q.pop();
                len++;
            }
            if(str == "NULL")
            {
                break;
            }
            string save_str = str;
            
            for(int i=0;i<str.length();i++)
            {
                str = save_str;
                for(char ch='a';ch<='z';ch++)
                {
                    str[i] = ch;
                    
                    if(str==endWord)
                    {
                        // cout<<"--"<<save_str<<" : "<<str<<"   len : "<<len<<endl;
                        return len + 2;
                    }
                    
                    if(s.find(str)!=s.end())
                    {
                        // cout<<save_str<<" : "<<str<<"   len : "<<len<<endl;
                        s.erase(str);
                        q.push(str);   
                    }
                }
            }
        }
        return 0;
    }
};