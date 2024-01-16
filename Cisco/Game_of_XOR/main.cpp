//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        optional<int> res = nullopt;
        for(int i = 0; i < (1 << N); i++) {
            int x = A[0];
            for(int j = 1; j < N; j++) if(i & (1 << j)) x^= A[j];
            if(!res) *res = x;
            else *res^= x;
        }
        return (res) ? *res : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends