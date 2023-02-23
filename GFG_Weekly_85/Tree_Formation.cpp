// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	long long minimumCost(int n,vector<int> &p)
	{
		//code here
		long long sum = 0;
		vector<int> deg(n, 0);
		for(int i = 1; i < n; i++) {
		    deg[i]++;
		    deg[p[i] - 1]++;
		    sum+= deg[i] * deg[p[i] - 1];
		}
		return sum;
	}
};


// { Driver Code Starts.


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> p(n);
		for(int i = 0; i<n; i++)cin >> p[i];
		Solution obj;
		long long ans = obj.minimumCost(n,p);
		cout << ans << endl;
		
	}
	return 0;
}
  // } Driver Code Ends