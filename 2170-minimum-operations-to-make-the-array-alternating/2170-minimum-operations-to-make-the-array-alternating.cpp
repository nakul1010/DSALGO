class Solution {
public:
    int minimumOperations(vector<int>& arr) 
    {
        int n = arr.size();
        unordered_map<int,int>mp_even,mp_odd;
        unordered_map<int,int>::iterator it;
        
        cout<<"n : "<<n<<endl;
        
        for(int i=0;i<n;i++)
        {
            if((i%2)==0)
                mp_even[arr[i]]++;
            else
                mp_odd[arr[i]]++;
        }
        
        
        int even_first=0, even_first_occ=0, even_second=0, max_occ = -1;
        for(it=mp_even.begin(); it!=mp_even.end(); it++)
        {
            if(it->second > max_occ)
                even_first = it->first , max_occ=it->second ;
        }
        even_first_occ = mp_even[even_first];
        mp_even.erase(even_first);
        max_occ = -1;
        for(it=mp_even.begin(); it!=mp_even.end(); it++)
        {
            if(it->second > max_occ)
                even_second = it->first , max_occ=it->second ;
        }
        
        
        
        int odd_first=0, odd_first_occ=0, odd_second=0;
        max_occ = -1;
        for(it=mp_odd.begin(); it!=mp_odd.end(); it++)
        {
            if(it->second > max_occ)
                odd_first = it->first , max_occ=it->second ;
        }
        odd_first_occ = mp_odd[odd_first];
        mp_odd.erase(odd_first);
        max_occ = -1;
        for(it=mp_odd.begin(); it!=mp_odd.end(); it++)
        {
            if(it->second > max_occ)
                odd_second = it->first , max_occ=it->second ;
        }
        
        cout<<"even_first : "<<even_first<<"    even_second : "<<even_second<<endl;
        cout<<"odd_first : "<<odd_first<<"    odd_second : "<<odd_second<<endl;
        
        cout<<"even_first_occ : "<<even_first_occ<<"    even_second_occ : "<<mp_even[even_second]<<endl;
        cout<<"odd_first_occ : "<<odd_first_occ<<"    odd_second_occ : "<<mp_odd[odd_second]<<endl;
        
        if(even_first!=odd_first)
            return n - even_first_occ - odd_first_occ;
        cout<<"Hello";
        return min( (n - even_first_occ - mp_odd[odd_second]) , (n - mp_even[even_second] - odd_first_occ) );
    }
};