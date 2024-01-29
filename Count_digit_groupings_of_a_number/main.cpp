//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int TotalCount(int i, string &str, int last, vector<vector<int>> &dp) {
        int count = 0, sum = 0;
        if(i >= str.size()) return 1;
        if(dp[i][last] != -1) return dp[i][last];
        for(int j = i; j < str.size(); i++) {
            sum+= (str[j] - '0');
            if(sum >= last) count+= TotalCount(j + 1, str, sum, dp);
        }
        return dp[i][last] = count;
    }
	public:
	int TotalCount(string str){
	    // Code here
	    vector<vector<int>> dp(str.size() + 1, vector<int>(901, -1));
	    return TotalCount(0, str, 0, dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends