//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Triple {
    long long x, y, z;
    Triple(long long a, long long b, long long c) : x(a), y(b), z(c) {}
};

class Solution {
    vector<vector<vector<long long>>> dp;
    void reset() {
        for(int i = 0; i < 65; i++) {
            for(int j = 0; j < 65; j++) {
                dp[0][i][j] = -1;
                dp[1][i][j] = -1;
            }
        }
    }
    long long dpf(string &s, int n, int tight, int k) {
        if(k < 0) return 0;
        if(!n) return 1;
        if(dp[tight][k][n] != -1) return dp[tight][k][n];
        int ub = (tight == 1 ? s[s.length() - n] - '0' : 1);
        long long ans = 0;
        for(int dig = 0; dig <= ub; dig++) {
            if(dig == ub) ans+= dpf(s, n - 1, tight, k - dig);
            else ans+= dpf(s, n - 1, 0, k - dig);
        }
        return dp[tight][k][n] = ans;
    }
    long long find(long long n, int k) {
        string s = bitset<64>(n).to_string();
        reset();
        return dpf(s, s.length(), 1, k);
    }
  public:
    long long findNthNumber(int n, int k) {
        // code here
        long long low = 0, high = 1e18;
        dp.resize(2, vector<vector<long long>>(65, vector<long long>(65)));
        while(low <= high) {
            long long mid = low + ((high - low) >> 1), count = find(mid, k);
            if(count >= n) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        long long res = obj.findNthNumber(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends