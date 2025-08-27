#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        // code here
        if(arr.size() < 3) return 0;
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for(int i = arr.size() - 1; i >= 0; i--) {
            int l = 0, r = i - 1;
            while(l < r) {
                int s = arr[l] + arr[r];
                if(s > arr[i]) {
                    cnt+= r - l;
                    r--;
                } else l++;
            }
        }
        return cnt;
    }
};

int main() {}