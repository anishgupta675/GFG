// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i]<< " ";
        }
        cout << endl;
    }
};


 // } Driver Code Ends
class Solution {
    unordered_set<int> primes;
    void simpleSieve(int limit, vector<int> &prime) {
        vector<bool> mark(limit + 1, true);
        for(int p = 2; p * p < 12; p++) {
            if(mark[p] == true) {
                for(int i = p * p; i < 12; i+= p)
                    mark[i] = false;
            }
        }
        for(int p = 2; p < 12; p++)
            if(mark[p] == true) prime.push_back(p);
    }
    void segmentedSieve(int n) {
        int limit = floor(sqrt(n)) + 1;
        vector<int> prime;
        prime.reserve(limit);
        simpleSieve(limit, prime);
        int low = limit;
        int high = 2 * limit;
        while(low < n) {
            if(high >= n) high = n;
            bool mark[limit + 1];
            memset(mark, true, sizeof(mark));
            for(int i = 0; i < prime.size(); i++) {
                int loLim = floor(low/prime[i]) * prime[i];
                if(loLim < low) loLim+= prime[i];
                for(int j = loLim; j < high; j+= prime[i])
                    mark[j - low] = false;
            }
            for(int i = low; i < high; i++) {
                if(mark[i - low] == true) {
                    primes.insert(i);
                    cout << i << endl;
                }
            }
            low = low + limit;
            high = high + limit;
        }
    }
  public:
    vector<int> findBots(vector<string> &usernames, int n) {
        // code here
        vector<int> res(n, 0);
        segmentedSieve(12);
        for(int i = 0; i < n; i++) {
            int count = 0;
            unordered_set<char> unique;
            for(int j = 0; j < usernames[i].length(); j++) {
                if(unique.find(usernames[i][j]) == unique.end()) {
                    unique.insert(usernames[i][j]);
                    count++;
                }
            }
            if(primes.find(count) == primes.end()) res[i] = 1;
            else res[i] = 0;
            unique.clear();
            count = 0;
        }
        return res;
    }
};


// { Driver Code Starts.

int main(){
    int t = 1;
    // scanf("%d ",&t);
    while(t--){
        
        int n = 4;
        // scanf("%d",&n);
        
        
        vector<string> usernames(n);
        usernames.push_back("abcdef");
        usernames.push_back("pqrs");
        usernames.push_back("xyzuvabb");
        usernames.push_back("aaaaaa");
        // Array::input(usernames,n);
        
        Solution obj;
        vector<int> res = obj.findBots(usernames, n);
        for(auto ele:res){
            // cout<<ele<<" ";
        }
        cout<<endl;
        
    }
}
  // } Driver Code Ends