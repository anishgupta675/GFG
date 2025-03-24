//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        for(int i = 2; i < arr.size(); i++) {
            for(int j = 1; j < arr.size() - i + 1; j++) {
                int k = j + i - 1;
                dp[i][j] = INT_MAX;
                for(int l = j; l < k; l++) {
                    int cost = dp[j][l] + dp[l + 1][k] + arr[j - 1] * arr[k] * arr[l];
                    dp[j][k] = min(dp[j][k], cost);
                }
            }
        }
        return dp[1][arr.size() - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends
