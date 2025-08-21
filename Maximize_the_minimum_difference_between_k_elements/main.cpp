#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& arr, int mid, int k) {
        int n = arr.size();
        int ctr = 1, i = 0;
        while(i < n) {
            auto it2 = lower_bound(arr.begin()+i+1, arr.end(), arr[i]+mid);
            if(it2 == arr.end()) break;
            i = it2 - arr.begin(); ctr++;
        }
        return ctr >= k;
    }

    int maxMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.back()-arr.front(), ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(arr, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};

int main() {}