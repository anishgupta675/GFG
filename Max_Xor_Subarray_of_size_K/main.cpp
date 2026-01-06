#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int maxi = 0;
        int sum = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            if(i>=k) sum = sum^arr[i-k];
            sum = sum^arr[i];
            if(i>=k-1){
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};

int main() {}