//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    string solve(string &s,int i,int n,int k)
    {
        if(i>=n || k<=0) return s;
        string temp=s;
        for(int j=i;j<n;j++)
        {
            if(s[j]>s[i])
            {
                swap(s[j],s[i]);
                temp=max(temp,solve(s,i+1,n,k-1));
                swap(s[j],s[i]);
            }
        }
        temp=max(temp,solve(s,i+1,n,k)); //no swapping
        return temp;
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string& str, int k)
    {
       // code here.
       return solve(str,0,str.size(),k);
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
