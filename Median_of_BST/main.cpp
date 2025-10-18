#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  void inorder(Node*root,vector<int>&in){
      if(root==NULL){
          return;
      }
      inorder(root->left,in);
      in.push_back(root->data);
      inorder(root->right,in);
  }
  public:
    int findMedian(Node* root) {
        // Code here
        vector<int>in;
        inorder(root,in);
        int n=in.size();
        if(n%2==0){
            int i=n/2;
            return in[i-1];
        }
        int i=(n+1)/2;
        return in[i-1];
    }
};

int main() {}