//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        bool row = 0, column = 0, end = 0, major = 0;
        int i = 0, j = 0, count = 1;
        while(count <= n * m) {
            if(count == k) return a[i][j];
            if(i < 0 && end) {
                row = 0;
                major = 0;
            } else if(i == n && end) {
                row = 1;
                major = 0;
            } else if(j < 0 && end) {
                column = 0;
                major = 1;
            } else if(j == m && end) {
                column = 1;
                major = 1;
            }
            if(major) {
                if(row) {
                    i--;
                    if(i) end = 0;
                    else end = 1;
                } else {
                    i++;
                    if(i != n - 1) end = 0;
                    else end = 1;
                }
            } else {
                if(j) {
                    j--;
                    if(j) end = 0;
                    else end = 1;
                } else {
                    j++;
                    if(j != n - 1) end = 0;
                    else end = 1;
                }
            }
            count++;
        }
        return -1;
    }

};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends