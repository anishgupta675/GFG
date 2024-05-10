//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void getComb(int index, int B, vector<int> &A, vector<vector<int>> &res, vector<int> &ha){
        if(index == A.size()) {
            if(!B) {
                sort(ha.begin(), ha.end());
                res.push_back(ha);
            }
            return;
        }
        if(A[index] <= B) {
            ha.push_back(A[index]);
            getComb(index, B - A[index], A, res, ha);
            ha.pop_back();
        }
        getComb(index + 1, B, A, res, ha);
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>> res;
        vector<int> ha;
        getComb(0, B, A, res, ha);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends