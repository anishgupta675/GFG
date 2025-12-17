#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        // Code here
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](auto &left, auto &right) {
            return left[0] < right[0];
        });
        int k = 0;
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= res[k][1]) {
                res[k][0] = min(res[k][0], intervals[i][0]);
                res[k][1] = max(res[k][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                k++;
            }
        }
        return res;
    }
};

int main() {}