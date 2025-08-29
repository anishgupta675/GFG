#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char,int>mpp;
        for(int i=0;i<p.size();i++){
            mpp[p[i]]++;
        }
        int count=mpp.size(); // count of distinct char
        int i=0,j=0,n=s.size();
        int start;
        int len=s.size();
        while(j<n){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0)
                count--;
            }
  
                while(count==0){
                    if(len>j-i+1){
                        len=j-i+1;
                        start=i;
                    }
                    if(mpp.find(s[i])!=mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]]==1){
                            count++;
                        }
                        
                    }
                    i++;
                }
            
            j++;
        }
        return len==s.size()? "-1":s.substr(start,len);
    }
};

int main() {}