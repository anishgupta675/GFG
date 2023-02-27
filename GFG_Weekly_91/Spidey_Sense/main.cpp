// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
class Solution {
    bool safe(int x, int y, int n, int m) {
        if(x < 0 || y < 0 || x >= n || y >= m) return 0;
        return 1;
    }
  public:
    vector<vector<int>> shortestDistanceFromTheBomb(vector<vector<char>> &b, int n, int m) {
        // code here
        vector<vector<int>> d(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(b[i][j] == 'B') {
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = x + dx[k];
                int nc = y + dy[k];
                if(safe(nr, nc, n, m) && b[nr][nc] != 'W' && d[nr][nc] > d[x][y] + 1) {
                    d[nr][nc] = d[x][y] + 1;
                    q.push({nr, nc});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(d[i][j] == 1e9) d[i][j] = -1;
        }
        return d;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n,m;
        cin>>n>>m;
        vector<vector<char>> building(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>building[i][j];
            }
        }
        
        Solution obj;
        vector<vector<int>> res = obj.shortestDistanceFromTheBomb(building, n, m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j];
                if(j!=m-1) cout<<" ";
                else cout<<endl;
            }
        }
        
    }
}
  // } Driver Code Ends