// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int maximumPrefix(int n,int m,string s,string t)
	{
		//code here
		int i = 0, j = 0;
		while(j < m) {
		    if(s[i] == t[j]) {
		        i++;
		        j++;
		    } else j++;
		}
		return (i < n) ? i + 1 : -1;
	}
};


// { Driver Code Starts.


int main()
{
    int c;
    cin >> c;
    while(c--)
    {
    	int n,m;
    	cin >> n >> m;
    	string s,t;
    	cin >> s >> t;
    	Solution obj;
		int ans = obj.maximumPrefix(n,m,s,t);
		cout << ans << "\n";
    }

	return 0;
}
  // } Driver Code Ends