//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(int i = 0; i < arr.size(); i++)
            sum += arr[i];
        if(sum % 2) return 0;
        int target = sum >> 1;
        int dp[arr.size() + 1][target + 1];
        for(int i = 0; i < arr.size() + 1; i++) {
            for(int j = 0; j < target + 1; j++) {
                if(!i && j > 0) dp[i][j] = 0;
                if(!j) dp[i][j] = 1;
            }
        }
        for(int i = 1; i < arr.size() + 1; i++) {
            for(int j = 1; j < target + 1; j++) {
                if(arr[i - 1] <= j) dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[arr.size()][target];
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
