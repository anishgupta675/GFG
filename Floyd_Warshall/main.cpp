//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size(); // Number of nodes in the graph
        
        // Iterate over all possible intermediate nodes ('via')
        for(int via = 0; via < n; ++via) {
            // For every source node 'i'
            for(int i = 0; i < n; ++i) {
                // For every destination node 'j'
                for(int j = 0; j < n; ++j) {
                    // Check if paths i→via and via→j exist (not infinity)
                    if(dist[i][via] < 1e8 && dist[via][j] < 1e8) {
                        // Update distance if i→via→j is shorter than i→j
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.floydWarshall(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
