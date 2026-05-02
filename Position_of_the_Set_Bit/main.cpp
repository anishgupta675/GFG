#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int N) {
        // code here
        int i = 1, position = -1;
        while(N) {
            if(N & 1) {
                if(position != -1) return -1;
                position = i;
            }
            i++;
            N>>= 1;
        }
        return position;
    }
};

int main() {}