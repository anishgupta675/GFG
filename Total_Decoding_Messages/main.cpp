//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int mod = 1e9 + 7;
    int countWays(string &digits, int n, vector<int>&dp){
        if(n < 2) return 1;
        if(dp[n] != -1) return dp[n]; 
        int cnt = 0;
        if(digits[n - 1] >= '1') cnt += countWays(digits, n - 1, dp) % mod;
        if(digits[n - 2] == '1' || digits[n - 2] == '2' && digits[n - 1] <= '6') cnt = (cnt + countWays(digits, n - 2, dp) % mod) % mod;
        return dp[n] = cnt % mod;
    }
  public:
    int countWays(string &digits) {
        // Code here
        if(digits[0] == '0') return 0;
        vector<int> dp(digits.size() + 1, -1);
        return countWays(digits, digits.size(), dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
