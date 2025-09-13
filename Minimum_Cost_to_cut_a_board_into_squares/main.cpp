#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const int &a, const int &b) {
        return a > b; 
    }

    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.begin(), x.end(), cmp);
        sort(y.begin(), y.end(), cmp);

        int nx = x.size();
        int ny = y.size();

        int ans = 0;
        int xp = 1, yp = 1; 
        int i = 0, j = 0;

        while (i < nx && j < ny) {
            if (x[i] > y[j]) {
                ans += x[i] * yp;
                ++xp;
                ++i;
            } else {
                ans += y[j] * xp;
                ++yp;
                ++j;
            }
        }

        while (i < nx) {
            ans += x[i] * yp;
            ++i;
            ++xp;
        }

        while (j < ny) {
            ans += y[j] * xp;
            ++j;
            ++yp;
        }

        return ans;
    }
};

int main() {}