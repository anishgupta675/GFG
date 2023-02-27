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
	bool checkSafe(char a, char b) {
		if(a == 'C' && b == 'T') return false;
		if(a == 'T' && b == 'C') return false;
		return true;
	}
  public:
    bool saveCivilians(int n, int m, vector<string> &grid) {
        // code here
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m - 1; j++)
            	if(i == n - 1) {
            		if(!checkSafe(grid[i][j], grid[i][j + 1])) return false;
            	}
            	else if(!checkSafe(grid[i][j], grid[i + 1][j]) || !checkSafe(grid[i][j], grid[i][j + 1])) return false;
        }
        return true;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int m;
        scanf("%d",&m);
        
        
        vector<string> grid(n);
        Array::input(grid,n);
        
        Solution obj;
        bool res = obj.saveCivilians(n, m, grid);
        if(res) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
}
  // } Driver Code Ends