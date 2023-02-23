// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class Solution{
    private:
    struct TrieNode *getNode(void) {
        struct TrieNode *pNode = new TrieNode;
        pNode->isEndOfWord = false;
        for(int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
        return pNode;
    }
    void insert(struct TrieNode *root, string key) {
        struct TrieNode *pCrawl = root;
        for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if(!pCrawl->children[index]) pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }
    bool search(struct TrieNode *root, string key) {
        struct TrieNode *pCrawl = root;
        for(int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if(!pCrawl->children[index]) return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl->isEndOfWord);
    }
	public:
	int splitString(int n,string s)
	{
		//code here
		int count = 0;
		struct TrieNode *root = getNode();
		insert(root, s);
		for(int i = 0; i < n; i++)
		    if(s.substr(0, i) == s.substr(i, n)) count++;
		return count;
	}
};


// { Driver Code Starts.


int main()
{
    int c;
    cin >> c;
    while(c--)
    {
    	int n;
    	cin >> n;
    	string s;
    	cin >> s;
    	Solution obj;
		int ans = obj.splitString(n,s);
		cout << ans << "\n";
    }

	return 0;
}
  // } Driver Code Ends