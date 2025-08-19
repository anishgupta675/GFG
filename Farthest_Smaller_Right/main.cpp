#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        // Precompute the minimum from each index to the end
        vector<int> preMin(n);
        preMin[n-1] = arr[n-1];
        
        // Fill preMin from right to left: preMin[i] = min(arr[i], preMin[i+1])
        for(int i = n-2; i>=0; --i){
            preMin[i] = min(arr[i], preMin[i+1]);
        }
        
        // Initialize answer array; last element always has no right smaller
        vector<int> ans(n); 
        ans[n-1] = -1;
        
        // For each element (except last), find farthest j such that arr[j] < arr[i]
        for(int i = 0; i<n-1; ++i){
            int low = i+1, high = n-1;
            int temp = -1; // stores the farthest index found
            while(low<=high){
                int mid = (low + high)/2;
                // If the minimum from mid to end is less than arr[i],
                // then there exists at least one value to the right of mid that is smaller.
                if(preMin[mid] < arr[i]){
                    temp = mid; // update candidate
                    low = mid+1; // try to find a farther index
                } else {
                    // No smaller value in the segment [mid, high], so search left
                    high = mid-1;
                }
            }
            ans[i] = temp;
        }
        
        return ans;
    }
};

int main() {}