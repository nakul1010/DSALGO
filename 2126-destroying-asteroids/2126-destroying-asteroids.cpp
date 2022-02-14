class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) 
    {
        sort(asteroids.begin(),asteroids.end());
        long long int curr_mass_of_planet = mass;
        
        for(int i=0;i<asteroids.size();i++)
        {
            if(curr_mass_of_planet < asteroids[i])
                return false;
            curr_mass_of_planet += asteroids[i];
        }
        return true;
    }
};