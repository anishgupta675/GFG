//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<vector<int>> dp;
    bool isSubsetSum(int n, vector<int> &arr, int sum) {
        if(!sum) return 1;
        if(!n) {
            if(arr[0] == sum) return 1;
            else return 0;
        }
        if(dp[n][sum] != -1) return dp[n][sum] == 1;
        bool not_take = isSubsetSum(n - 1, arr, sum), take = 0;
        if(arr[n] <= sum) take = isSubsetSum(n - 1, arr, sum - arr[n]);
        dp[n][sum] = (not_take || take) ? 1 : 0;
        return take || not_take;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        for(int i = 0; i < arr.size(); i++) {
            vector<int> data;
            for(int j = 0; j <= sum; j++)
                data.push_back(-1);
            dp.push_back(data);
            data.clear();
        }
        return isSubsetSum(arr, sum);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
