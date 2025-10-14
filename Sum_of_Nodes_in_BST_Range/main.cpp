#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        // Base case: if node is null, return 0 (no contribution to sum)
        if(!root) return 0;
        
        // Recursively get sum from left subtree
        int left = nodeSum(root->left, l, r);
        
        // Recursively get sum from right subtree  
        int right = nodeSum(root->right, l, r);
        
        // Check if current node's value is within the range [l, r]
        if(l <= root->data && root->data <= r) 
            // If yes, add current node's value + left subtree sum + right subtree sum
            return root->data + left + right;
        
        // If current node is not in range, return only the sum from subtrees
        return left + right;
    }
};

int main() {}