#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        Node *ptr = root;
        ptr = ptr->next;
        while(ptr != nullptr) {
            Node *prev = nullptr, *curr1 = root, *curr2 = ptr;
            while(curr1 != nullptr && curr2 != nullptr) {
                if(curr1->data <= curr2->data) {
                    if(prev == nullptr) root = curr1;
                    else prev->bottom = curr1;
                    prev = curr1;
                    curr1 = curr1->bottom;
                } else {
                    if(prev == nullptr) root = curr2;
                    else prev->bottom = curr2;
                    prev = curr2;
                    curr2 = curr2->bottom;
                }
            }
            if(curr1 != nullptr) prev->bottom = curr1;
            if(curr2 != nullptr) prev->bottom = curr2;
            ptr = ptr->next;
        }
        return root;
    }
};

int main() {}