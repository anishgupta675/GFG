#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int left = 0, right = n * m - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            int row = mid / m;
            int col = mid % m;
            
            int midVal = mat[row][col];
            
            if (midVal == x) {
                return true;
            }
            
            int leftRow = left / m, leftCol = left % m;
            int rightRow = right / m, rightCol = right % m;
            
            int leftVal = mat[leftRow][leftCol];
            int rightVal = mat[rightRow][rightCol];
            
            if (leftVal <= midVal) { 
                if (leftVal <= x && x < midVal) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { 
                if (midVal < x && x <= rightVal) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return false;
    }
};

int main() {}