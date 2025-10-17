#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    int cs = 0;
  public:
    void transformTree(Node *root) {
        // code here
        if(!root)return;
        int d = root->data;
        transformTree(root->right);
        root->data = cs;
        cs += d;
        transformTree(root->left);
    }
};

int main() {}