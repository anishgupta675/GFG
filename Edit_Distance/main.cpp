//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& a, string& b) {
        // code here
        vector<int> f(b.size() + 1),s(b.size() + 1);
        for(int i = 0; i <= b.size(); i++) f[i] = i;
        for(int i = 1; i <= a.size(); i++) {
            s[0] = i;
            for(int j = 1; j <= b.size(); j++) {
                if(a[i - 1] == b[j - 1]) s[j] = f[j - 1];
                else s[j] = 1 + min(min(f[j - 1], f[j]), s[j - 1]);
            }
            f = s;
        }
        return f[b.size()];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
