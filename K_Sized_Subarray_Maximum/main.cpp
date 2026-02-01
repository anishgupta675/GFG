#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> q;
        vector<int> res;
        for(int i = 0;i<k;i++){
            while(!q.empty() and arr[q.back()]<arr[i])q.pop_back();
            q.push_back(i);
        }
        res.push_back(arr[q.front()]);
        for(int i = k;i<n;i++){
            while(!q.empty() and q.front()<=i-k)q.pop_front();
            while(!q.empty() and arr[q.back()]<arr[i])q.pop_back();
            q.push_back(i);
            
            res.push_back(arr[q.front()]);
        }
        
        return res;
    }
};

int main() {}