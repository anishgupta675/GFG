//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution 
{
private:
    class Orange{		// class to store index of rotten oranges
        public:
        int row, col;
        Orange(){}
        Orange(int x, int y){
            row=x,col=y;
        }
    };
    bool isValid(vector<vector<int>> &grid, int x, int y){		// it checks if x and y index is a valid fresh orange or not
        int n=grid.size(), m=grid[0].size();
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
            return true;
        }
        return false;
    }
    void rot(vector<vector<int>> &grid, queue<Orange> &q, int &fresh, int x, int y){		// to add to queue and mark it as rotten
        q.push(Orange(x, y));
        grid[x][y]=2;
        fresh--;
    }
public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        queue<Orange> q;
        int rotten=0, fresh=0;
        for(int i=0; i<n; i++){		// put all rotten oranges in queue
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push(Orange(i,j));
                    rotten++;
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        if(rotten==0){
            if(fresh) return -1;	// if no rotten oranges and some fresh oranges, they will never rot.
            else return 0;		// if no rotten and no fresh so no time required
        }
        int ans=-1;		
        while(!q.empty()){
            int count=q.size();	// number of oranges to be rotten in curr time
            while(count!=0){		// put all of their adj fresh oranges in queue
                Orange curr=q.front();
                q.pop();
                int x=curr.row-1, y=curr.col;
                if(isValid(grid, x, y)){
                    rot(grid, q, fresh, x, y);
                } 
                x+=2;
                if(isValid(grid, x, y)){
                    rot(grid, q, fresh, x, y);
                } 
                x--, y--;
                if(isValid(grid, x, y)){
                    rot(grid, q, fresh, x, y);
                } 
                y+=2;
                if(isValid(grid, x, y)){
                    rot(grid, q, fresh, x, y);
                } 
                count--;	
            }
            ans++;		// increment time when all oraneges of curr time processed
            count=q.size();
        }
        if(fresh!=0) return -1;	// if still fresh oranges means they could not be rot
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
