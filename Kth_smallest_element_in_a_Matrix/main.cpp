#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int r=mat.size();
        int c=mat.size();
        vector<int> v;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                v.push_back(mat[i][j]);
            }
        }
    
        sort(v.begin(),v.end());
    
        return v[k-1];
    }
};

int main() {}