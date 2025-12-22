#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int maxRow = -1, ones = 0;
        
        for(int i=0;i<arr.size();i++){
            int o = 0;
            for(int j=arr[i].size()-1;j>=0;j--){
                if(arr[i][j]==0)break;
                o++;
            }
            if(o>ones){
                ones = o;
                maxRow = i;
            }
        }
        
        return maxRow;
        
    }
};

int main() {}