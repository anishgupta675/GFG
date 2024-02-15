//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {
        // code here
        int a_count = 0, b_count = 0, hash_count = 0;
        queue<char> q;
        for(int i = 0; i < M; i++) {
            if(S[i] == 'A') {
                a_count++;
                q.push('A');
            } else if(S[i] == 'B') {
                b_count++;
                q.push('B');
            } else hash_count++;
        }
        for(int i = 0; i < N; i++) {
            if(S[i] == 'A') {
                a_count--;
                if(q.front() == 'A') q.pop();
            } else if(S[i] == 'B') {
                b_count--;
                if(q.front() == 'B') q.pop();
            } else hash_count--;
        }
        return (q.empty() && !a_count && !b_count && !hash_count);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends