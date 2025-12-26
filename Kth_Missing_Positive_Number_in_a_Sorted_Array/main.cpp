#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int len = arr.size();
        int max  = arr[len-1]+k,count=0;
        for(int i=1; i<=max; i++){
            if(!(binary_search(arr.begin(),arr.end(),i))){
                count++;
            }if(count==k){ 
                max = i;
                break;
            }
        }
        return max;
    }
};

int main() {}