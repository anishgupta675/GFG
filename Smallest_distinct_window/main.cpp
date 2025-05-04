//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int findSubString(string &str)
    {
        // Your code goes here   
        int n = str.length();
        int freq[127] = {0};
       
        int tdc = 0; // total distinct character
        for(int i = 0; i < n; i++){
            if(freq[str[i]] == 0) tdc++;
            freq[str[i]]++;
        }
       
        memset(freq,0,sizeof(freq));
       
        int cnt = 0;
        int st = 0;
        int size = n;
        int i = 0, j = 0;
        while(j < n){
            if(freq[str[j]] == 0) cnt++;
            freq[str[j]]++;
           
            while(cnt == tdc){
                if(j-i+1 < size){
                    st = i;
                    size = j-i+1;
                }
                freq[str[i]]--;
                if(freq[str[i++]] == 0){
                    cnt--;
                }
            }
            j++;
        }
       
        return size;
    }
};



//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
