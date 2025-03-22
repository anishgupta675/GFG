//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int maxValue(int idx, vector<int>& arr) {
        int prev2 = 0, prev1 = arr[idx];
        for(int i = idx + 1; i < arr.size(); ++i) {
            int curr = max(arr[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
  public:
    int maxValue(vector<int>& arr) {
        // your code here
        int includeLastHouse = maxValue(1, arr);
        arr.pop_back();
        int includeFirstHouse = maxValue(0, arr);
        return max(includeFirstHouse, includeLastHouse);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
