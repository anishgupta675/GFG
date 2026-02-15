#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(),a.end());
        int ans = INT_MAX, ff = 0, ll = m-1, n = a.size();;
        while(ll<n){
           ans = min(ans,a[ll++]-a[ff++]);
        }
        return ans;
    }
};

int main() {}