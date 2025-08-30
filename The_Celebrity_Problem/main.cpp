#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m) 
    {
        // code here 
        int n = m.size();
        stack<int>s;
        int i,j,k;
       
        for(i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>=2){
            i=s.top();
            s.pop();
            j=s.top();
            s.pop();
           
            if(m[i][j]==1)
            s.push(j);
            if(m[i][j]==0)
            s.push(i);
        }
       
        k=s.top();
        s.pop();
        for(i=0;i<n;i++){
            if(i!=k){
                if(m[k][i]!=0 or m[i][k]!=1)
                return -1;
            }
           
        }
        return k;
    }
};

int main() {}