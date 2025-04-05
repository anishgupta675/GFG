//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    void traverse(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || 
           y < 0 || y >= grid[0].size() || 
           grid[x][y] == '0') return;
        
        grid[x][y] = '0';
        traverse(grid, x+1, y);
        traverse(grid, x, y+1);
        traverse(grid, x, y-1);
        traverse(grid, x-1, y);
        traverse(grid, x+1, y+1);
        traverse(grid, x-1, y+1);
        traverse(grid, x-1, y-1);
        traverse(grid, x+1, y-1);
    }
public:
    // Function to find the number of islands.
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size();
        int ret = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    traverse(grid, i, j);
                    ret++;
                }
            }
        }
        
        return ret;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
