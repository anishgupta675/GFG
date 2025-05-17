//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        vector<int> ans; // To store transformed values
        
        // Step 1: Apply quadratic transformation to each element
        for(int x : arr){
            long long int temp = (A * x * x) + (B * x) + C; // Compute A*(x^2) + B*x + C
            ans.push_back((int)(temp)); // Store the result (cast to int)
        }
        
        // Step 2: Sort the transformed array
        sort(ans.begin(), ans.end());
        
        return ans; // Return sorted transformed array
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends