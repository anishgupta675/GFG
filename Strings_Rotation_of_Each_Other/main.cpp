#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> computeLPSArray(string &pattern) {
        int i = 1, curr_ptr = 0;
        vector<int> lps(pattern.length(), 0);
        while(i < pattern.length()) {
             if(pattern[curr_ptr] == pattern[i % pattern.length()]) {
                 curr_ptr++;
                 lps[i] = curr_ptr;
                 i++;
             } else {
                if(curr_ptr != 0) { 
                curr_ptr = lps[curr_ptr - 1];  
            } else {
                lps[i] = 0;
                i++;
            }
             }
        }
        return lps;
    }
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if(s1.length() != s2.length()) return false;
        vector<int> lps = computeLPSArray(s2);
        int i = 0, curr_ptr = 0;
        while(i < (s1.length() * 2)) {
            if(s2[curr_ptr] == s1[i % s1.length()]) {
                curr_ptr++;
                i++;
                //  if(curr_ptr == s1.length()) return true;
                if(curr_ptr == s2.length()) return true;
            } else {
                if(curr_ptr) curr_ptr = lps[curr_ptr - 1];
                else i++;
            }
        }
        return false;
    }
};

int main() {}