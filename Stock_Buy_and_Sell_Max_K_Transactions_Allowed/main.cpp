//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        vector<int> next(2 * k), curr(2 * k);
        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = 2 * k - 1; j >= 0; j--) {
                int prof = 0;
                if(!(j % 2)) int prof = max(-prices[i] + next[j + 1], next[j]);
                else prof = max(prices[i] + next[j + 1], next[j]);
                curr[j] = prof;
            }
            next = curr;
        }
        return next[0];
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
