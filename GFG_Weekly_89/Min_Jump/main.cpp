// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    bool isGood(int n) {
        if(!(n % 2)) return true;
        if(!(n % 3)) return true;
        return false;
    }
    public:
    int minJump(int n,vector<int> arr)
    {
        //code here
        int res = 0, low = 0, high = 0, farthest = 0;
        while(high < n - 1) {
            farthest = 0;
            for(int i = low; i <= high; i++)
                if(isGood(arr[i]) && isGood(arr[min(n - 1, i + arr[i])]) && farthest < i + arr[i]) farthest = i + arr[i];
            low = high + 1;
            high = max(high + 1, farthest);
            res++;
        }
        return res;
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
		cout << obj.minJump(n,arr) << "\n";
    }

	return 0;
}
  // } Driver Code Ends