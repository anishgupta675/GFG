#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        priority_queue<int> odd_numbers;
        priority_queue<int, vector<int>, greater<int>> even_numbers;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2) {
                odd_numbers.push(arr[i]);
            } else {
                even_numbers.push(arr[i]);
            }
        }
        int i = 0;
        while(!odd_numbers.empty()) {
            arr[i++] = odd_numbers.top();
            odd_numbers.pop();
        }
        while(!even_numbers.empty()) {
            arr[i++] = even_numbers.top();
            even_numbers.pop();
        }
    }
};

int main() {}