#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // code here
        return (V*V-V)/2-edges.size();
    }
};

int main() {}