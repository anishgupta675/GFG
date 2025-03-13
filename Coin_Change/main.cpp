//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    long long int dp[1000][1000];
    long long int solve(vector<int> &coins, int n, int sum) {
        if(n == -1 && sum > 0) return 0;
        if(!sum) return 1;
        if(sum < 0) return 0;
        if(dp[n][sum] != -1) return dp[n][sum];
        return dp[n][sum] = solve(coins, n, sum - coins[n]) + solve(coins, n - 1, sum);
    }
public:
    int count(vector<int>& coins, int sum) {
        // code here.
        dp[sum][sum - 1];
        for(int i = 0; i < coins.size(); i++) {
            for(int j = 0; j <= sum; j++)
                dp[i][j] = -1;
        }
        return solve(coins, coins.size() - 1, sum);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
