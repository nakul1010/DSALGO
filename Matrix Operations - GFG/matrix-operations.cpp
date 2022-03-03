// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool check(int i,int j,int r,int c)
    {
        if(i<0 || i>=r || j<0 || j>=c)
            return false;
        return true;
    }
    
    void move(int &i,int &j, string &direction)
    {
        if(direction == "right")
        {
            j++;
        }
        else if(direction == "up")
        {
            i--;
        }
        else if(direction == "down")
        {
            i++;
        }
        else if(direction == "left")
        {
            j--;
        }
    }
    
    void choose_direction(int &i,int &j, string &direction,vector<vector<int>>&matrix)
    {
        if(matrix[i][j]==0)
        {
            move(i,j,direction);
        }
        else
        {
            matrix[i][j] = 0;
            if(direction == "right")
            {
                direction = "down";
                move(i,j,direction);
            }
            else if(direction == "up")
            {
                direction = "right";
                move(i,j,direction);
            }
            else if(direction == "down")
            {
                direction = "left";
                move(i,j,direction);
            }
            else if(direction == "left")
            {
                direction = "up";
                move(i,j,direction);
            }
        }
    }
    
    pair<int,int> endPoints(vector<vector<int>> matrix)
    {
        int row = matrix.size(), col = matrix[0].size(), last_i=0,last_j=0,i=0,j=0;
        string direction = "right";
        
        while(true)
        {
            // cout<<"i : "<<i<<"  j : "<<j<<endl;
            if(check(i,j,row,col)==false)
            {
                break;
            }
            last_i=i, last_j=j;
            choose_direction(i,j,direction,matrix);
        }
        
        pair<int,int>p;
        p.first = last_i;
        p.second = last_j;
        return p;
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends