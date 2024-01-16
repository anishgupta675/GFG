//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int max_val = 0;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) freq[A[i]]++;
        for(auto i : freq) {
            max_val = i.second;
            pq.push(make_pair(i.second, i.first));
        }
        if(max_val % 2 && (n - max_val) % 2) return 2;
        if(!(max_val % 2) && !((n - max_val) % 2)) return 1;
        if(!(max_val % 2) && (n - max_val) % 2) return 1;
        return 2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i = 0;i < n;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.findWinner(n, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends