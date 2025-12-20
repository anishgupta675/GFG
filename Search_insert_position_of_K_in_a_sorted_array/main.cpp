#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int low = 0, high = arr.size() - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(arr[mid] == k) return mid;
            if(arr[mid] < k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {}