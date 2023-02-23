// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

using ll = long long;
vector<int> c[100001];
ll dp[100001][2][20];
const ll inf = 1e17;
ll ans;

void dfs(int x, int k, vector<int> &a, vector<int> &b) {
    for(int y : c[x]) {
        for(int i = 0; i < k - 1; i++) {
            dp[y][0][i + 1] = max(dp[y][0][i + 1], a[y] + dp[x][0][i]);
            dp[y][1][i + 1] = max(dp[y][1][i + 1], b[y] + dp[x][1][i]);
        }
        for(int i = 0; i < k; i++) {
            dp[y][0][0] = max(dp[y][0][0], a[y] + dp[x][1][i]);
            dp[y][1][0] = max(dp[y][1][0], b[y] + dp[x][0][i]);
        }
    }
    for(int y : c[x])
        dfs(y, k, a, b);
    if(c[x].empty()) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < k; j++)
                ans = max(ans, dp[x][i][j]);
        }
    }
}

class Solution{
	public:
	long long maximumSum(int n,int k,vector<int> &p,vector<int> &a,vector<int> &b)
	{
		//code here
		for(int i = 0; i < n; i++)
		    c[i].clear();
	    for(int i = 1; i < n; i++)
	        if(p[i]) c[p[i] - 1].push_back(i);
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < 2; j++) {
	            for(int l = 0; l < k; l++)
	                dp[i][j][l] = -inf;
	        }
	    }
	    dp[0][0][0] = a[0];
	    dp[0][1][0] = b[0];
	    ans = -inf;
	    dfs(0, k, a, b);
	    return ans;
	}
};

// { Driver Code Starts.
	
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int> p(n),a(n),b(n);
		for(int i = 0; i<n; i++)cin >> p[i];
		for(int i = 0; i<n; i++)cin >> a[i];
		for(int i = 0; i<n; i++)cin >> b[i];
		Solution obj;
		long long ans = obj.maximumSum(n,k,p,a,b);
		cout << ans << endl;
		
	}
	return 0;
}  // } Driver Code Ends