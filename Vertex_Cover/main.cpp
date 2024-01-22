//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    bool vertexCover(vector<vector<bool>> &graph, vector<bool> &vis) {
        for(int i = 0; i < graph.size(); i++) for(int j = 0; j < graph[i].size(); i++) if(graph[i][j] && !(vis[i] || vis[j])) return false;
        return true;
    }
    int vertexCover(vector<vector<bool>> &graph, vector<bool> &vis, int start, int size, int minCoverSize) {
        if(start == graph.size()) if(vertexCover(graph, vis) && size < minCoverSize) minCoverSize = size;
        return minCoverSize;
    }
public:
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        // code here
        int minCoverSize = n;
        vector<bool> vis(n);
        vector<vector<bool>> graph(n, vector<bool>(n));
        for(pair<int, int> i : edges) {
            graph[i.first - 1][i.second - 1] = 1;
            graph[i.second - 1][i.first - 1] = 1;
        }
        minCoverSize = vertexCover(graph, vis, 0, 0, minCoverSize);
        return minCoverSize;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends