#include<bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{
public:
    void swap(int *xp, int *yp) {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    int min(int a, int b) {
        return (a <= b) ? a : b;
    }
    int max(int a, int b) {
        return (a >= b) ? a : b;
    }
	// Function to find maximum product subarray
	int maxProduct(vector<int> arr) {
	    // code here
	    int ans = arr[0], min_prod = arr[0], max_prod = arr[0], n = arr.size();
	    for(int i = 1; i < n; i++) {
	        if(arr[i] < 0) swap(&min_prod, &max_prod);
	        min_prod = min(arr[i] * min_prod, arr[i]);
	        max_prod = max(arr[i] * max_prod, arr[i]);
	        ans = max(ans, max_prod);
	    }
	    return ans;
	}
};

int main() {}