//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int ans = 0;
    void numberSequenceUtil(int m, int n) {
        if(!n) {
            ans++;
            return;
        }
        if(m < n) return;
        numberSequenceUtil(m / 2, n - 1);
        numberSequenceUtil(m - 1, n);
    }
public:
    int numberSequence(int m, int n){
        // code here
        numberSequenceUtil(m, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends