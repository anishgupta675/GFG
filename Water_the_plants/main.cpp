//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        int target = 0, i = 0, ans = 0;
        vector<vector<int>> sprinkles;
        for(int i = 0; i < n; i++) {
            if(gallery[i] != -1) {
                vector<int> data(2);
                data[0] = i - gallery[i];
                data[1] = i + gallery[i];
                sprinkles.push_back(data);
                data.clear();
            }
        }
        sort(sprinkles.begin(), sprinkles.end());
        while(target < n && i < sprinkles.size()) {
            if(sprinkles[i][0] > target) return -1;
            int max_idx = sprinkles[i][1];
            i++;
            while(i < sprinkles.size() && sprinkles[i][0] <= target) {
                max_idx = max(max_idx, sprinkles[i][1]);
                i++;
            }
            target = max_idx + 1;
            ans++;
        }
        if(target < n - 1) return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends