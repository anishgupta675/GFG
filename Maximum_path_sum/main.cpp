#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
    int solve(Node *root, int &maxSum) {
        if (root == nullptr) {
            return 0;
        }

        int left = max(0, solve(root->left, maxSum));
        int right = max(0, solve(root->right, maxSum));

        maxSum = max(maxSum, left + right + root->data);

        return root->data + max(left, right);
    }
  public:
    int findMaxSum(Node *root) {
        // code here
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};

int main() {}