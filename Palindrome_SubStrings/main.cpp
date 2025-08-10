//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    public:
      int countPS(string &s) {
          // code here
          int n = s.length();
          int count = 0;
  
          // Odd-length palindromes
          for (int center = 0; center < n; center++) {
              int left = center, right = center;
              while (left >= 0 && right < n && s[left] == s[right]) {
                  if (right - left + 1 >= 2) count++;
                  left--;
                  right++;
              }
          }
  
          // Even-length palindromes
          for (int center = 0; center < n - 1; center++) {
              int left = center, right = center + 1;
              while (left >= 0 && right < n && s[left] == s[right]) {
                  if (right - left + 1 >= 2) count++;
                  left--;
                  right++;
              }
          }
  
          return count;
      }
  };  


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
