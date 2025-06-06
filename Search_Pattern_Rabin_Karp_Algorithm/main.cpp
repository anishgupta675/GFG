#include<bits/stdc++.h>

using namespace std;

class Solution
{
    
    // THOMPSON's CONSISTENT HASHING ALGO
        vector<int> search(string pattern, string text, int q) {
            // return !pattern.compare(text.substr(low, size));
            int p = 0, t = 0, h = 1;
            vector<int> res;
            for(int i = 0; i < pattern.length() - 1; i++) h = (h * 256) % q;
            for(int i = 0; i < pattern.length(); i++) {
                p = (256 * p + pattern[i]) % q;
                t = (256 * t + text[i]) % q;
            }
            for(int i = 0; i <= text.length() - pattern.length(); i++) {
                if(p == t) {
                    int j;
                    for(j = 0; j < pattern.length(); j++) if(text[i + j] != pattern[j]) break;
                    if(j == pattern.length()) res.push_back(i + 1);
                }
                if(i < text.length() - pattern.length()) {
                    t = (256 * (t - text[i] * h) + text[i + pattern.length()]) % q;
                    if(t < 0) t+= q;
                }
            }
            return res;
        }
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> res;
            if(pattern.length() > text.length()) return res;
            // while(low + pattern.length() <= text.length()) {
            //     if(uset.find(text.substr(low, pattern.length())) == uset.end()) {
            //         low++;
            //         continue;
            //     }
            //     if(search(pattern, text, low, pattern.length())) res.push_back(low + 1);
            //     low++;
            // }
            return search(pattern, text, INT_MAX);
        }
     
};

// azbycx
// cx, hash = 27

int main() {}