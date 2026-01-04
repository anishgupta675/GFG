#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int count0 = 0, count1 = 0, count2 = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) count0++;
            else if(arr[i] == 1) count1++;
            else if(arr[i] == 2) count2++;
        }
        for(int i = 0; i < count0; i++)
            arr[i] = 0;
        for(int i = count0; i < count0 + count1; i++)
            arr[i] = 1;
        for(int i = count0 + count1; i < count0 + count1 + count2; i++)
            arr[i] = 2;
    }
};

int main() {}