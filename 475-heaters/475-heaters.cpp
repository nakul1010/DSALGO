class Solution {
public:
    
    int Get_Nearest_Radius(int find, vector<int>& heaters)
    {
        int start=0,end=heaters.size()-1,prev_mid=-1,mid=0;
        int just_greater=-1,just_smaller=-1;
        
        while(start<=end)
        {
            mid = (start+end)/2;
            // cout<<"mid : "<<mid<<"    start : "<<start<<"    end : "<<end<<"    arr[mid] : "<<heaters[mid]<<endl;
            if(heaters[mid]==find)
                return 0;
            
            if(find > heaters[mid])
            {
                just_smaller = heaters[mid];
                // end = mid-1;
                start = mid+1;
            }
            else
            {
                just_greater = heaters[mid];
                // start = mid+1;
                end = mid-1;
            }   
        }
        // cout<<"just_greater : "<<just_greater<<"    just_smaller : "<<just_smaller<<endl;
        if(just_greater!=-1 && just_smaller!=-1)
            return min(abs(just_greater-find), abs(just_smaller-find));
        if(just_greater!=-1)
            return abs(just_greater-find);
        return abs(just_smaller-find);
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        int radius = 0;
        
        sort(heaters.begin(),heaters.end());
        
        for(int i=0;i<houses.size();i++)
        {
            int get_nearest_radius = Get_Nearest_Radius(houses[i], heaters);
            // cout<<"house : "<<houses[i]<<"   radius : "<<get_nearest_radius<<"\n\n";
            radius = max(radius, get_nearest_radius);
        }
        
        return radius;
    }
};