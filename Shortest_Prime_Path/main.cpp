//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
    vector<int> prime;
    int bfs(int src, int dst) {
        vector<int> ans(10001, -1);
        vector<int> vis(10001);
        queue<int> q;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(vis[f]) continue;
            vis[f] = 1;
            string s = to_string(f);
            for(int i = 0; i < 4; i++) {
                for(char ch = '0'; ch <= '9'; ch++) {
                    if(ch == s[i] || (ch == '0' && i == 0)) continue;
                    string nxt = s;
                    nxt[i] = ch;
                    int nxtN = stoi(nxt);
                    if(prime[nxtN] && ans[nxtN] == -1) {
                        ans[nxtN] = 1 + ans[f];
                        q.push(nxtN);
                    }
                }
            }
        }
        return ans[dst];
    }
public:
    Solution() {
        int mxp = 9999;
        prime = vector<int>(10001, 1);
        prime[1] = 0;
        for(int i = 2; i <= mxp; i++) {
            if(prime[i]) {
                for(int j = 2; j * i <= mxp; j++) prime[j * i] = 0;
            }
        }
    }
    int solve(int num1,int num2)
    {   
      //code here
      return bfs(num1, num2);
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends