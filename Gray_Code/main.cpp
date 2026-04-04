#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        if(n==1){
            vector<string>ans;
            ans.push_back("0");
            ans.push_back("1");
            return ans;
        }
        vector<string>tmp=graycode(n-1);
        int sz=tmp.size();
        vector<string>ans;
        for(int i=0; i<sz; i++){
            ans.push_back("0"+tmp[i]);
        }
        for(int i=sz-1; i>=0; i--){
            ans.push_back("1"+tmp[i]);
        }
        return ans;
    }
};

int main() {}