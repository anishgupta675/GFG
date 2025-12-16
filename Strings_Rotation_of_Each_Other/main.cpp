#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if(s1.length() != s2.length()) return false;
        int i = 0, count = 0, curr_ptr = 0;
        while(i < (s1.length() * 2)) {
             if(s2[curr_ptr] != s1[i % s1.length()]) curr_ptr = 0;
             else if(s2[curr_ptr] == s1[i % s1.length()]) {
                 curr_ptr++;
                 if(curr_ptr == s1.length()) return true;
             }
             i++;
        }
        return false;
    }
};

int main() {}