// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    long long magicalSubarrays(int n,vector<int> arr)
    {
        //code here
        long long c = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 == 1) {
                arr[i] = 1;
                c++;
            } else {
                arr[i] = 0;
            }
        }
        if(c == 0) return 0;
        long long temp[2] = {1, 0};
        long long result = 0, sum = 0;
        long long cnt = 0;
        int i = 0, j = 0;
        while(j < n) {
            if(arr[j] == 1) {
                i = j + 1;
            } else {
                cnt+= (j - i + 1);
            }
            j++;
        }
        for(int i = 0; i < n; i++) {
            sum = (((sum + arr[i]) % 2) + 2) % 2;
            temp[sum]++;
        }
        result+= (temp[0] * (temp[0] - 1) / 2);
        result+= (temp[1] * (temp[1] - 1) / 2);
        return (result) - cnt;
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
		vector<int> arr(n);
		for(int i = 0; i<n; i++)cin >> arr[i];
    	Solution obj;
		cout << obj.magicalSubarrays(n,arr) << "\n";
    }

	return 0;
}
  // } Driver Code Ends