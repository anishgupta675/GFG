//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<vector<int>> adj) 
	{
	    // code here
	    vector<int> in(V, 0);
	    vector<int> ans;
	    queue<int> q;
	    for(int i = 0; i < V; i++) {
	        for(auto x: adj[i])
	            in[x]++;
	    }
	    for(int i = 0; i < V; i++)
	        if(!in[i]) q.push(i);
	    while(!q.empty()) {
	        int td = q.front();
	        q.pop();
	        ans.push_back(td);
	        for(auto x: adj[td]) {
	            in[x]--;
	            if(!in[x]) q.push(x);
	        }
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
