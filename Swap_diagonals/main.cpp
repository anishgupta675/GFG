#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        for(int i = 0, j = mat.size() - 1; i < mat.size(), j >= 0; i++, j--) {
            int temp = mat[i][i];
            mat[i][i] = mat[i][j];
            mat[i][j] = temp;
        }
    }
};

int main() {}