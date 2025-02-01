//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(vector<vector<char>> &mat, int i, int j, int n, int m, int index, string &word){
        if(mat[i][j] != word[index]) return false;
        if(index == word.length() - 1) return true;
        char ch = mat[i][j];
        mat[i][j] = '$';
        bool found = false;
        if(i > 0 and !found) found = solve(mat, i - 1, j, n, m, index + 1, word);
        if(i < n - 1 and !found) found = solve(mat,i + 1, j, n, m, index + 1, word);
        if(j > 0 and !found) found = solve(mat, i, j - 1, n, m, index + 1, word);
        if(j < m - 1 and !found) found=solve(mat, i, j + 1, n, m, index + 1, word);
        mat[i][j] = ch;
        return found;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == word[0]) {
                    if(solve(mat, i, j, mat.size(), mat[i].size(), 0, word)) return true;
                }
            }
        }   
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
