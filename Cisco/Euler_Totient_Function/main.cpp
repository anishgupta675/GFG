//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

const int MAX = 100001;

class Solution{
    vector<long long> p;
    void sieve() {
        long long *isPrime = (long long *)malloc((MAX + 1) * sizeof(long long));
        for(long long i = 2; i <= MAX; i++) {
            if(!(isPrime[i])) {
                p.push_back(i);
                for(long long j = 2; i * j <= MAX; j++) isPrime[i * j] = 1;
            }
        }
    }
public:
    // function to find totient of n
    long long ETF(long long N){
        // code here
        long long res = N;
        for(long long i = 0; p[i] * p[i] <= N; i++) {
            if(!(N % p[i])) {
                res-= res / p[i];
                while(!(N % p[i])) N/= p[i];
            }
        }
        if(N > 1) res-= res / N;
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends