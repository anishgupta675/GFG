//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int src) {
        if(vis[src]) return false;
        vis[src] = 1;
        for(int i = 0; i < adj[src].size(); i++) if(!dfs(adj, vis, adj[src][i])) return false;
        return true;
    }
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<bool> vis(n);
        vector<vector<int>> edges(n);
        for(int i = 0; i < adj.size(); i++) {
            edges[adj[i][0]].push_back(adj[i][1]);
            edges[adj[i][1]].push_back(adj[i][0]);
        }
        if(!dfs(adj, vis, 0)) return false;
        for(int i = 0; i < n; i++) if(!vis[i]) return false;
        return true;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends