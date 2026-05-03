#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        int n = arr.size(), maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,__builtin_popcount(arr[i]));
        }
        vector<int>a[maxi+1];
        for(int i=0;i<n;i++){
            a[__builtin_popcount(arr[i])].push_back(arr[i]);
        }
        int k=0;
        for(int i=maxi;i>=0;i--){
            for(auto val:a[i]){
                arr[k]=val;
                k++;
            }
        }
        return arr;
    }
};

int main() {}