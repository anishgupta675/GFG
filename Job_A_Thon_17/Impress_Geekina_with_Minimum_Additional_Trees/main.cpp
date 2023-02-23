// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
    long long getSum(int low, int high) {
        if(low > high) return 0;
        long long sum = 0;
        for(int i = low; i <= high; i++)
            sum+= i;
        return sum;
    }
    long long find(int i, int k) {
        int temp = k - i + 1;
        long sum = temp;
        sum+= findSum(temp, k - 1);
        return sum;
    }
    long long findSum(int low, int high) { return getSum(1, high) - getSum(1, low - 1); }
  public:
    int impressGeekina(long long n, int k) {
        // code here
        if(n == 1) return 0;
        int low = 1, high = k;
        while(low <= high) {
            int mid = (low + high) / 2;
            long pos = find(mid, k);
            
            if(pos >= n) high = mid - 1;
            else low = mid + 1;
        }
        if(low > k) return -1;
        return low;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long n;
        scanf("%lld",&n);
        
        
        int k;
        scanf("%d",&k);
        
        Solution obj;
        int res = obj.impressGeekina(n, k);
        
        cout<<res<<endl;
        
    }
}
  // } Driver Code Ends