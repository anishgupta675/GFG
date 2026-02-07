#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();

        // Step 1: total sum of elements
        int sum = 0;
        for (int num : arr) 
            sum += num;

        // Step 2: initial F0
        int F = 0;
        for (int i = 0; i < n; i++) {
            F += i * arr[i];
        }

        // Step 3: compute all rotations using recurrence
        int maxVal = F;
        for (int k = 1; k < n; k++) {
            F = F + sum - n * arr[n - k];
            maxVal = max(maxVal, F);
        }

        return maxVal;
    }
};

int main() {}