//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(vector<vector<int>> adj, int idx, vector<bool> &st,vector<bool> &visited){
     
    
     
     
        visited[idx]=true;
         
        for(int i=0;i<adj[idx].size();i++){
   
            if(st[adj[idx][i]])
            return true;
            else{
                st[adj[idx][i]]=true;
                 
                if(dfs(adj,adj[idx][i],st,visited)) return true;
                else st[adj[idx][i]]=false;
            }
             
             
        }
        return false;
     
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        
        vector<bool>visited(V,false);
      
       
        for(int i=0;i<V;i++){
            vector<bool> st(V,false);
            if(!visited[i]){
                st[i]=true;
                if(dfs(adj,i,st,visited))
                return true;
            }
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
